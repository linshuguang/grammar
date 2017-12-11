%{
#include "ast.hpp"
#include "sym.hpp"
#include "adt.hpp"
#include "main.hpp"
#include "array.hpp"

#include <iostream>
#include <string>
#include<cstring>

using namespace std;
extern "C"
{
	void yyerror(const char *s);
	int yylex(void);
};
class AST * top=NULL;
%}

%union {
  class AST *a;
  class ListAST *l;
  zval * zv;
}


%right T_PRINT

%left T_INCLUDE T_INCLUDE_ONCE T_EVAL T_REQUIRE T_REQUIRE_ONCE
%token T_INCLUDE      "include (T_INCLUDE)"
%token T_INCLUDE_ONCE "include_once (T_INCLUDE_ONCE)"
%token T_EVAL         "eval (T_EVAL)"
%token T_REQUIRE      "require (T_REQUIRE)"
%token T_REQUIRE_ONCE "require_once (T_REQUIRE_ONCE)"
%left T_LOGICAL_OR
%token T_LOGICAL_OR   "or (T_LOGICAL_OR)"
%left T_LOGICAL_XOR
%token T_LOGICAL_XOR  "xor (T_LOGICAL_XOR)"
%left T_LOGICAL_AND
%token T_LOGICAL_AND  "and (T_LOGICAL_AND)"
%token T_PRINT        "print (T_PRINT)"
%left T_PLUS_EQUAL T_MINUS_EQUAL T_MUL_EQUAL T_DIV_EQUAL T_CONCAT_EQUAL T_MOD_EQUAL T_AND_EQUAL T_OR_EQUAL T_XOR_EQUAL T_SL_EQUAL T_SR_EQUAL
%token T_PLUS_EQUAL   "+= (T_PLUS_EQUAL)"
%token T_MINUS_EQUAL  "-= (T_MINUS_EQUAL)"
%token T_MUL_EQUAL    "*= (T_MUL_EQUAL)"
%token T_DIV_EQUAL    "/= (T_DIV_EQUAL)"
%token T_CONCAT_EQUAL ".= (T_CONCAT_EQUAL)"
%token T_MOD_EQUAL    "%= (T_MOD_EQUAL)"
%token T_AND_EQUAL    "&= (T_AND_EQUAL)"
%token T_OR_EQUAL     "|= (T_OR_EQUAL)"
%token T_XOR_EQUAL    "^= (T_XOR_EQUAL)"
%token T_SL_EQUAL     "<<= (T_SL_EQUAL)"
%token T_SR_EQUAL     ">>= (T_SR_EQUAL)"
%left '?' ':'
%left T_BOOLEAN_OR
%token T_BOOLEAN_OR   "|| (T_BOOLEAN_OR)"
%left T_BOOLEAN_AND 
%token T_BOOLEAN_AND  "&& (T_BOOLEAN_AND)"

%left '^'
%left '&'
%nonassoc T_IS_EQUAL T_IS_NOT_EQUAL T_IS_IDENTICAL T_IS_NOT_IDENTICAL
%token T_IS_EQUAL     "== (T_IS_EQUAL)"
%token T_IS_NOT_EQUAL "!= (T_IS_NOT_EQUAL)"
%token T_IS_IDENTICAL "=== (T_IS_IDENTICAL)"
%token T_IS_NOT_IDENTICAL "!== (T_IS_NOT_IDENTICAL)"
%nonassoc '<' T_IS_SMALLER_OR_EQUAL '>' T_IS_GREATER_OR_EQUAL
%token T_IS_SMALLER_OR_EQUAL "<= (T_IS_SMALLER_OR_EQUAL)"
%token T_IS_GREATER_OR_EQUAL ">= (T_IS_GREATER_OR_EQUAL)"
%left T_SL T_SR
%token T_SL "<< (T_SL)"
%token T_SR ">> (T_SR)"
%left '+' '-' '.'
%left '*' '/' '%'
%right '!'
%nonassoc T_INSTANCEOF
%token T_INSTANCEOF  "instanceof (T_INSTANCEOF)"
%right '~' T_INC T_DEC T_INT_CAST T_DOUBLE_CAST T_STRING_CAST T_ARRAY_CAST T_OBJECT_CAST T_BOOL_CAST T_UNSET_CAST '@'
%token T_INC "++ (T_INC)"
%token T_DEC "-- (T_DEC)"
%token T_INT_CAST    "(int) (T_INT_CAST)"
%token T_DOUBLE_CAST "(double) (T_DOUBLE_CAST)"
%token T_STRING_CAST "(string) (T_STRING_CAST)"
%token T_ARRAY_CAST  "(array) (T_ARRAY_CAST)"
%token T_OBJECT_CAST "(object) (T_OBJECT_CAST)"
%token T_BOOL_CAST   "(bool) (T_BOOL_CAST)"
%token T_UNSET_CAST  "(unset) (T_UNSET_CAST)"
%right '['
%nonassoc T_NEW T_CLONE
%token T_NEW       "new (T_NEW)"
%token T_CLONE     "clone (T_CLONE)"
%token T_EXIT      "exit (T_EXIT)"
%token T_IF        "if (T_IF)"
%left T_ELSEIF
%token T_ELSEIF    "elseif (T_ELSEIF)"
%left T_ELSE 
%token T_ELSE      "else (T_ELSE)"
%left T_ENDIF 
%token T_ENDIF     "endif (T_ENDIF)"




%token T_INLINE_HTML
%token T_CHARACTER
%token T_BAD_CHARACTER
%token T_ENCAPSED_AND_WHITESPACE  "quoted-string and whitespace (T_ENCAPSED_AND_WHITESPACE)"
%token T_ECHO       "echo (T_ECHO)"
%token T_DO         "do (T_DO)"
%token T_WHILE      "while (T_WHILE)"
%token T_ENDWHILE   "endwhile (T_ENDWHILE)"
%token T_FOR        "for (T_FOR)"
%token T_ENDFOR     "endfor (T_ENDFOR)"
%token T_FOREACH    "foreach (T_FOREACH)"
%token T_ENDFOREACH "endforeach (T_ENDFOREACH)"
%token T_DECLARE    "declare (T_DECLARE)"
%token T_ENDDECLARE "enddeclare (T_ENDDECLARE)"
%token T_AS         "as (T_AS)"
%token T_SWITCH     "switch (T_SWITCH)"
%token T_ENDSWITCH  "endswitch (T_ENDSWITCH)"
%token T_CASE       "case (T_CASE)"
%token T_DEFAULT    "default (T_DEFAULT)"
%token T_BREAK      "break (T_BREAK)"
%token T_CONTINUE   "continue (T_CONTINUE)"
%token T_GOTO       "goto (T_GOTO)"
%token T_FUNCTION   "function (T_FUNCTION)"
%token T_CONST      "const (T_CONST)"
%token T_RETURN     "return (T_RETURN)"
%token T_TRY        "try (T_TRY)"
%token T_CATCH      "catch (T_CATCH)"
%token T_THROW      "throw (T_THROW)"
%token T_USE        "use (T_USE)"
%token T_INSTEADOF  "insteadof (T_INSTEADOF)"
%token T_GLOBAL     "global (T_GLOBAL)"
%right T_STATIC T_ABSTRACT T_FINAL T_PRIVATE T_PROTECTED T_PUBLIC
%token T_STATIC     "static (T_STATIC)"
%token T_ABSTRACT   "abstract (T_ABSTRACT)"
%token T_FINAL      "final (T_FINAL)"
%token T_PRIVATE    "private (T_PRIVATE)"
%token T_PROTECTED  "protected (T_PROTECTED)"
%token T_PUBLIC     "public (T_PUBLIC)"
%token T_VAR        "var (T_VAR)"
%token T_UNSET      "unset (T_UNSET)"
%token T_ISSET      "isset (T_ISSET)"
%token T_EMPTY      "empty (T_EMPTY)"
%token T_HALT_COMPILER "__halt_compiler (T_HALT_COMPILER)"
%token T_CLASS      "class (T_CLASS)"
%token T_TRAIT      "trait (T_TRAIT)"
%token T_INTERFACE  "interface (T_INTERFACE)"
%token T_EXTENDS    "extends (T_EXTENDS)"
%token T_IMPLEMENTS "implements (T_IMPLEMENTS)"
%token T_OBJECT_OPERATOR "-> (T_OBJECT_OPERATOR)"
%token T_DOUBLE_ARROW    "=> (T_DOUBLE_ARROW)"
%token T_LIST            "list (T_LIST)"
%token T_ARRAY           "array (T_ARRAY)"
%token T_CALLABLE        "callable (T_CALLABLE)"
%token T_CLASS_C         "__CLASS__ (T_CLASS_C)"
%token T_TRAIT_C         "__TRAIT__ (T_TRAIT_C)"
%token T_METHOD_C        "__METHOD__ (T_METHOD_C)"
%token T_FUNC_C          "__FUNCTION__ (T_FUNC_C)"
%token T_LINE            "__LINE__ (T_LINE)"
%token T_FILE            "__FILE__ (T_FILE)"
%token T_COMMENT         "comment (T_COMMENT)"
%token T_DOC_COMMENT     "doc comment (T_DOC_COMMENT)"
%token T_OPEN_TAG        "open tag (T_OPEN_TAG)"
%token T_OPEN_TAG_WITH_ECHO "open tag with echo (T_OPEN_TAG_WITH_ECHO)"
%token T_CLOSE_TAG       "close tag (T_CLOSE_TAG)"
%token T_WHITESPACE      "whitespace (T_WHITESPACE)"
%token T_START_HEREDOC   "heredoc start (T_START_HEREDOC)"
%token T_END_HEREDOC     "heredoc end (T_END_HEREDOC)"
%token T_DOLLAR_OPEN_CURLY_BRACES "${ (T_DOLLAR_OPEN_CURLY_BRACES)"
%token T_CURLY_OPEN      "{$ (T_CURLY_OPEN)"
%token T_PAAMAYIM_NEKUDOTAYIM ":: (T_PAAMAYIM_NEKUDOTAYIM)"
%token T_NAMESPACE       "namespace (T_NAMESPACE)"
%token T_NS_C            "__NAMESPACE__ (T_NS_C)"
%token T_DIR             "__DIR__ (T_DIR)"
%token T_NS_SEPARATOR    "\\ (T_NS_SEPARATOR)"

%token _EOF
%token <zv> T_CONSTANT_ENCAPSED_STRING
%token <zv> T_LNUMBER   
%token <zv> T_DNUMBER  
%token <zv> T_STRING    
%token <zv> T_STRING_VARNAME 
%token <zv> T_VARIABLE  
%token <zv> T_NUM_STRING 








%left ','

%nonassoc '|' UMINUS


%type <l> top_statement_list 
%type <a> top_statement function_declaration_statement unticked_function_declaration_statement 

%type <a>  inner_statement statement unticked_statement

%type <a> expr scalar expr_without_variable common_scalar			 encaps_list encaps_var

%type <a> variable base_variable_with_function_calls base_variable		reference_variable compound_variable r_variable variable_without_objects

%type <a> function_call 
%type <l> function_call_parameter_list non_empty_function_call_parameter_list

%type <a> namespace_name



%type <a>    array_pair_list dim_offset
%type <l>  non_empty_array_pair_list
%type <a> rw_variable


%type <l> inner_statement_list elseif_list 
%type <a> else_single
%type <a> while_statement

%type <a> for_statement

%type <a> for_expr
%type <l> non_empty_for_expr
%type <l> case_list switch_case_list


%type <l> parameter_list non_empty_parameter_list

%type <a> foreach_statement foreach_optional_arg foreach_variable

%type <l> global_var_list 
%type <a> global_var	

%type <a> internal_functions_in_yacc
%type <l> isset_variables
%type <l> echo_expr_list
%type <a> exit_expr

%start start 
		
%%

start:
	top_statement_list	{top =  new TopStmt($1); }
;

top_statement_list:
		top_statement_list   top_statement {$$ = $1; $1->push_back(new TopStmtListAST($2,NULL));}
	|	{$$=new TopStmtListAST(NULL,NULL);}/* empty */
;

namespace_name:
		T_STRING { $$ = new StrAST($1->value.str.val) ; }
;

top_statement:
		statement						{  $$=$1;}
	|	function_declaration_statement	{  $$=$1;}
;




function_declaration_statement:
		unticked_function_declaration_statement	{ $$=$1;}
;

unticked_function_declaration_statement:
		function {SYMBOL_TABLE_STACK->Push(NEW_SYMBOL_TABLE());} is_reference T_STRING  '(' parameter_list ')' 	'{' inner_statement_list '}' 
		{
			//cout<<"function def ok"<<endl;
			
			SymbolTable * symtbl = SYMBOL_TABLE_STACK->Pop();
			if(!GLOBAL_FUNCTION_TABLE->Register($4->value.str.val)){
				cout<<"function register error"<<endl;
			}
			Symbol * symbol = GLOBAL_FUNCTION_TABLE->Lookup($4->value.str.val);
			symbol->ReVal(new Function(symtbl,$6,new InnerStmt($9)));
			
			$$ = new FunctionDeclarationStmt(NULL);
		}
;

inner_statement_list:
		inner_statement_list   inner_statement 
		{ 
			$1->push_back( new InnerStmtListAST($2,NULL));
			$$= $1;
		}
	|	{$$=new InnerStmtListAST(NULL,NULL);}/* empty */
;

inner_statement:
		statement {$$=$1; }
	|	function_declaration_statement {$$=$1;}
;

parameter_list:
		non_empty_parameter_list {$$=$1;}
	|	{$$ = NULL;}/* empty */
;


non_empty_parameter_list:
		optional_class_type T_VARIABLE				
		{
			(CURRENT_SYMBOL_TABLE)->Register($2->value.str.val); 
			$$ = new ListAST(new StrAST($2->value.str.val),NULL);
		}
	|	non_empty_parameter_list ',' optional_class_type T_VARIABLE 	
		{ 
			(CURRENT_SYMBOL_TABLE)->Register($4->value.str.val); 
			$1->push_back(new ListAST(new StrAST($4->value.str.val),NULL));			
		}
;

optional_class_type:
	{ }/* empty */
	|	T_ARRAY						{}
;

is_reference:
			{ }/* empty */
	|	'&'			{ }
;



statement:
		unticked_statement {$$=$1;}
		|	T_STRING ':' 
			{ 
				//zend_do_label(&$1 TSRMLS_CC); 
				$$ = new LabelStmt(new StrAST($1->value.str.val));
			}
;

unticked_statement:
		'{' inner_statement_list '}' 
		{
			//cout<<"unticked begin"<<endl;
			$$=new InnerStmt($2);
		}
	|	T_IF  '(' expr ')'  statement  elseif_list  else_single 
		{ 
			ListAST * l = new ListAST(new IfFlow($3,$5),$6);
			l->push_back(new ListAST($7,NULL));
			$$ = new IfStmt(l);
		}
	|	T_WHILE '(' expr  ')' while_statement 
		{ 
			$$ = new WhileStmt($3,$5);
		}
	|	T_DO statement T_WHILE '(' expr ')' ';' 
		{ 
			$$ = new DoWhileStmt($2,$5);			
		}
	|	T_FOR '(' for_expr ';' for_expr ';' for_expr')' for_statement 
		{ 
			$$ = new ForStmt($3,$5,$7,$9);
		}
	|	T_SWITCH '(' expr ')' switch_case_list 
		{ 
			//cout<<"switch begin"<<endl;
			$$ = new SwitchStmt($3,$5);
			//cout<<"switch end"<<endl;
		}
	|	T_BREAK ';'				
		{ 
			$$ = new BreakStmt(NULL);
		}
	|	T_BREAK expr ';'		
		{ 
			$$ = new BreakStmt($2);
		}
	|	T_CONTINUE ';'			
		{ 
			$$ = new ContinueStmt(NULL);
		}
	|	T_CONTINUE expr ';'		
		{ 
			$$ = new ContinueStmt($2);
		}
	|	T_RETURN ';'						
		{ 
			
			$$ = new ReturnStmt(NULL);
		}
	|	T_RETURN expr_without_variable ';'	
		{ 
			$$ = new ReturnStmt($2);
		}
	|	T_RETURN variable ';'				
		{  
			$$ = new ReturnStmt($2);
		}
	|	T_GLOBAL global_var_list ';'
		{
			$$ = new GlobalStmt($2);
		}
	|	T_ECHO echo_expr_list ';'
		{
			$$ = new EchoStmt($2);
		}
	|	expr ';'				
		{ 
			$$=new ExprStmt($1);
		}
	|	T_FOREACH '(' variable T_AS foreach_variable foreach_optional_arg ')' foreach_statement 
		{ 
			//new DoubleArrowExpr($5,$6);
			//zend_do_foreach_end(&$1, &$4 TSRMLS_CC); 
			$$ = new ForeachStmt($3,$5,$6,$8);
		}
	|	T_FOREACH '(' expr_without_variable T_AS variable foreach_optional_arg ')' 	foreach_statement 
		{ 
			$$ = new ForeachStmt($3,$5,$6,$8);
		}		
	|	';'	{$$=NULL;}	
	|	T_GOTO T_STRING ';' 
		{ 			
			$$ = new GotoStmt(new StrAST($2->value.str.val));
		}
;

foreach_optional_arg:
		/* empty */						{ $$= NULL; }
	|	T_DOUBLE_ARROW foreach_variable	{ $$ = $2; }
;


foreach_variable:
		variable			{ $$ = $1; }
	|	'&' variable		{ }
;


for_statement:
		statement {$$=$1;}
	|	':' inner_statement_list T_ENDFOR ';' 
		{
			$$= new InnerStmt($2);
		}
;
foreach_statement:
		statement {$$=$1;}
	|	':' inner_statement_list T_ENDFOREACH ';'
		{
			$$= new InnerStmt($2);
		}
;

switch_case_list:
		'{' case_list '}'					
		{ 
			$$ = $2; 
		}
	|	'{' ';' case_list '}'				
		{ 
			$$ = $3; 
		}
	|	':' case_list T_ENDSWITCH ';'		
		{ 
			$$ = $2; 
		}
	|	':' ';' case_list T_ENDSWITCH ';'	
		{ 
			$$ = $3; 
		}
;


case_list:
		/* empty */	
		{
			$$ = new ListAST(NULL,NULL);
		}
	|	case_list T_CASE expr case_separator inner_statement_list 
		{ 
			$1->push_back(new ListAST(new CaseFlow($3,new InnerStmt($5)),NULL));
			$$ = $1;
			//,NULL)));
		}
	|	case_list T_DEFAULT case_separator inner_statement_list 
		{ 			
			$1->push_back(new ListAST(new DefaultFlow(new InnerStmt($4)),NULL));
			$$ = $1;
		}
;


case_separator:
		':'
	|	';'
;

while_statement:
		statement {$$ =$1;}
	
;

elseif_list:
		{ $$=new ListAST(NULL,NULL); }	/* empty */
	|	elseif_list T_ELSEIF '(' expr ')'  statement 
		{ 			
			$1->push_back( new ListAST(new IfFlow($4,$6),NULL));
			$$= $1;
		}
;


else_single:
	 { $$=NULL; }	/* empty */
	|	T_ELSE statement {$$=new ElseFlow($2);}
;

echo_expr_list:
		echo_expr_list ',' expr 
		{ 
			$$ = $1;
			$1->push_back(new ListAST($3,NULL));
		}
	|	expr					
		{ 
			$$ = new ListAST($1,NULL);
		}
;

for_expr:
		/* empty */			{ $$=NULL; }
	|	non_empty_for_expr	{ $$ = new CommaExpr($1);}
;

non_empty_for_expr:
		non_empty_for_expr ',' expr { $$ = $1; $1->push_back(new ListAST($3,NULL)); }
	|	expr					{ $$ = new ListAST($1,NULL); }
;

expr:
		r_variable					{$$=$1;}
	|	expr_without_variable		{ $$=$1 ;}
;




expr_without_variable :
		variable '=' expr		{  $$=new AssignExpr($1,$3); }
	|	variable T_CONCAT_EQUAL expr	
		{ 
			$$ = new AssignExpr($1,new ConcatExpr($1,$3));
		}
	|	rw_variable T_INC { $$= new PostIncExpr($1); }
	|	T_INC rw_variable { $$= new PreIncExpr($2);}
	|	rw_variable T_DEC {$$= new PostDecExpr($1); }
	|	T_DEC rw_variable {$$= new PreDecExpr($2); }
	|	expr '.' expr 	{ $$= new ConcatExpr($1,$3);  }
	|	expr '+' expr 	{ $$= new AddExpr($1,$3);}
	|	expr '-' expr 	{  $$ = new SubExpr($1,$3);/*$$ = newast('-', $1,$3); */}
	|	expr '*' expr	{ $$ = new MulExpr($1,$3);/* $$ = newast('*', $1,$3); */}
	|	expr '/' expr	{ $$ = new DivExpr($1,$3); /*$$ = newast('/', $1,$3); */}
	|	expr '%' expr 	{ $$ = new ModExpr($1,$3); /* $$ = newast('%', $1,$3);*/ }
	|	'!' expr { $$ = new NotExpr($2); }
	|	'~' expr { $$ = new NotExpr($2); }
	|	expr T_IS_EQUAL expr			{ $$ = new EqualExpr($1,$3);}
	|	expr T_IS_NOT_EQUAL expr 		{ $$ = new NotEqualExpr($1,$3);}
	|	expr '<' expr 					{ $$ = new SmallThanExpr($1,$3);}
	|	expr T_IS_SMALLER_OR_EQUAL expr { $$ = new SmallEqualExpr($1,$3);}
	|	expr '>' expr 					{ $$ = new GreatThanExpr($1,$3);}
	|	expr T_IS_GREATER_OR_EQUAL expr { $$ = new GreatEqualExpr($1,$3);}
	|	'(' expr ')' 	{ $$=$2; }
	|	expr '?' expr ':' expr	 {$$ = new QmExpr($1,$3,$5);}
	|	internal_functions_in_yacc { $$ = $1; }
	|	T_EXIT exit_expr	{$$ = new Exit($2); }
	|	scalarscalar				{$$=$1;}
	|	T_ARRAY '(' array_pair_list ')' {$$=new ArrayAST($3);}
	|	'[' array_pair_list ']' { /*$$ = $2; */}
	|	T_PRINT expr  {$$= new Print($2);}
	|	function is_reference '(' {}
			parameter_list ')' lexical_vars '{' inner_statement_list '}' { /*cout<<"ref"<<endl;*/}
;

function:	
	T_FUNCTION 
	{ 
	}
;



scalar:
		common_scalar			{ $$ = $1;}
	|	'"' encaps_list '"' 	{  /*$$ = $2; */}
;

possible_comma:
		/* empty */
	|	','
;

array_pair_list:
		/* empty */ {$$=NULL; }
	|	non_empty_array_pair_list possible_comma	{ $$ = $1; }
;

non_empty_array_pair_list:
		non_empty_array_pair_list ',' expr T_DOUBLE_ARROW expr	{$1->push_back( new ListAST(new DoubleArrowExpr($3,$5),NULL));$$= $1; }
	|	non_empty_array_pair_list ',' expr			{$1->push_back(new ListAST(new DoubleArrowExpr(NULL,$3),NULL));$$= $1; }
	|	expr T_DOUBLE_ARROW expr	{ $$ = new ListAST(new DoubleArrowExpr($1,$3),NULL); }
	|	expr 				{ $$ =new ListAST(new DoubleArrowExpr(NULL,$1),NULL); }
;

global_var_list:
		global_var_list ',' global_var	
		{ 
			$$ = $1;
			$1->push_back(new ListAST($3,NULL));
		}
	|	global_var						
		{ 
			$$ = new ListAST($1,NULL);
		}
;


global_var:
		T_VARIABLE			
		{ 
			CURRENT_SYMBOL_TABLE->RegisterGlobalRef($1->value.str.val);
			$$ = new GlobalVariableAST($1->value.str.val); 
		}
;
encaps_list:
		encaps_list encaps_var {  }
	|	encaps_list T_ENCAPSED_AND_WHITESPACE	{ }
	|	encaps_var { }
	|	T_ENCAPSED_AND_WHITESPACE encaps_var	{ }
;

encaps_var:
		T_VARIABLE { /*$$ = newref(lookup($1->value.str.val));*/ cout<<"variable"<<endl;}
		|	T_VARIABLE '[' encaps_var_offset ']'	{ }
;


internal_functions_in_yacc :
		T_ISSET '(' isset_variables ')' 
		{ 
			$$ = new IsSetExpr($3); 
		}
	|	T_EMPTY '(' variable ')'	
		{ 
			$$ = new EmptyExpr($3);
		}
;

isset_variables:
		variable 				
		{ 
			$$ = new ListAST($1,NULL);
		}
	|	isset_variables ',' variable 
		{ 
			//$$ = $1->push_back(new ListAST($3,NULL));
		}
;	


encaps_var_offset:
		T_STRING		{  }
	|	T_NUM_STRING	{  }
	|	T_VARIABLE		{ }
;

common_scalar:
		T_LNUMBER 					{ $$ = new LongAST($1->value.lval); }
	|	T_DNUMBER 					{ $$ = new DoubleAST($1->value.dval);}
	|	T_CONSTANT_ENCAPSED_STRING	
		{ 
			$$ = new StrAST($1->value.str.val);
			
		}
;




lexical_vars:
		/* empty */
;


exit_expr:
		/* empty */	{ $$=NULL;}
	|	'(' ')'		{ $$=NULL;}
	|	'(' expr ')'	{$$=$2;}
;

rw_variable:
	variable	{ $$=$1;}
;
variable:
		base_variable_with_function_calls { $$=$1; }
;


base_variable_with_function_calls:
		base_variable				{  $$=$1;}
	|	function_call {$$=new TempVariableAST($1);}
;


base_variable:
		reference_variable { $$=$1;}
;

reference_variable:
		reference_variable '[' dim_offset ']'	{ $$ = new FetchArrayDimVariableAST($1,$3); }
	|	compound_variable			{ $$=$1;}
;


compound_variable:
		T_VARIABLE			
		{
			//Symbol * s = 
			(CURRENT_SYMBOL_TABLE)->Register($1->value.str.val); 
			$$ = new SimpleVariableAST($1->value.str.val);
		}
	|	'$' '{' expr '}'	{   }
;

dim_offset:
	{$$=NULL;   }	/* empty */		
	|	expr			{ $$=$1; }
;

function_call:
	namespace_name '('	function_call_parameter_list')' 
	{  
		//cout<<"function call "<<endl;
		//$$ = NULL;
		$$ = new CallFunction($1, $3);
	}
	|	variable_without_objects  '(' function_call_parameter_list ')'	
	{  
		$$ = new CallFunction($1, $3);
	}
;

function_call_parameter_list:
		non_empty_function_call_parameter_list	{ $$=$1; }
	|	/* empty */				{$$=NULL;}
;

non_empty_function_call_parameter_list:
		expr_without_variable	 
		{
			$$ = new ListAST($1,NULL);
		}
	|	variable	
		{
			$$ = new ListAST($1,NULL);
		}			
	|	non_empty_function_call_parameter_list ',' expr_without_variable	
		{ 
			$$ = $1;
			$1->push_back(new ListAST($3,NULL));
		}
	|	non_empty_function_call_parameter_list ',' variable					
		{ 
			$$ = $1;
			$1->push_back(new ListAST($3,NULL));
		}
;


variable_without_objects:
		reference_variable {/* $$=$1; */}
;

r_variable:
	  variable { $$=$1;}
;
%%

void yyerror(const char *s)
{
	
}

int main(int argc, char *argv[])
{
	
	
	
	if(!core_init(argc,argv)){
		return -1;
	}
	top=NULL;	
	yyparse();
	begin_to_parse(top);

	return 0;
}
