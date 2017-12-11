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

#define FLAG_BY_NON 0
#define FLAG_BY_VAL 1
#define FLAG_BY_REF 2

//extern class AST * top=NULL;
%}

%union {
  class AST *a;
  class ListAST *l;
  zval * zv;
  unsigned char f;
}


%token T_AND 
%token T_CALL
%token T_CASE
%token T_CONST
%token T_DIM
%token T_DO
%token T_EACH
%token T_ELSE
%token T_ELSEIF
%token T_EMPTY
%token T_END
%token T_EQU
%token T_ERASE
%token T_ERROR
%token T_EXIT
%token T_EXPLICIT
%token T_FALSE
%token T_FOR
%token T_FUNCTION
%token T_IF
%token T_IS
%token T_IMP
%token T_IN
%token T_LOOP
%token T_MOD
%token T_NEXT
%token T_NOT
%token T_NOTHING
%token T_NULL
%token T_ON
%token T_OPTION
%token T_REDIM
%token T_REM
%token T_RESUME
%token T_SELECT
%token T_SET
%token T_STEP
%token T_SUB
%token T_THEN
%token T_TO
%token T_TRUE
%token T_WEND
%token T_WITH
%token T_XOR
%token T_UNTIL
%token T_CLASS
%token T_PUBLIC
%token T_PRIVATE
%token T_DEFAULT
%token T_PROPERTY
%token T_LET
%token T_GET
%token T_BYREF
%token T_BYVAL
%token T_NEW
%token T_WHILE
%token T_RANDOMIZE
%token T_PRESERVE
%token T_IS_GREATER_OR_EQUAL
%token T_DOUBLE_ARROW
%token T_IS_SMALLER_OR_EQUAL
%token T_IS_NOT_EQUAL
%token T_GOTO
%token T_OR
%token T_EQV
%token T_ADD

%token T_BIG_EQV
%token T_SMALL_EQV
%token T_NOT_EQV
%token T_DATE
%token T_NEW_LINE


%token T_PRINT
%token T_EVAL
%token T_EXECUTE	


%left '+' '-' '.'
%left '*' '/' '%'
%right '!' 

%token _EOF


%token <zv> T_INTEGER   
%token <zv> T_FLOAT  
%token <zv> T_STRING    
%token <zv> T_ID
%token <zv> T_BOOL
%left ','
%nonassoc '|' UMINUS


%type <a> Program
%type <a> VarDecl
%type <a> ExtendedID Stmt ExprStmt
%type <a> GlobalStmt
%type <l> GlobalStmtList

%type <a> Variable   CompoundVariable
%type <a> ConstExpr 

%type <a> ID
%type <l> CommaExprList
%type <a> Expr ExprWithoutVariable
%type <a> ErrorExpr ExitExpr
%type <l> VariableTailList
%type <a> VariableTailOpt
%type <l> InnerStmtList
%type <a> InnerStmt

%type <a> DimStmt 
%type <l> VarDeclList ArrayRankList 

%type <a> CmpExpr ConditionExpr  ElseOpt EndIfOpt
%type <l> ElseStmtList ElseStmtListOpt
%type <a> GlobalBlockStmt InnerBlockStmt
%type <a> IfStmt

%type <a> ForStmt
%type <a> StepOpt

%type <a> LoopStmt
%type <a> Eval
%type <a> SelectStmt CaseStmt
%type <l> CaseStmtList
%type <l> ExprList

%type <a> FunctionDecl
%type <l>  MethodArgList ArgList
%type <a> Arg 
%type <f> ArgModifierOpt
%type <a> SubDecl

%start Program

		
%%

NL:
     T_NEW_LINE {}
	| NL T_NEW_LINE {}
;

NLOpt:
	NL {}
	|  {}
;
	


Program:
	GlobalBlockStmt { CURRENT_TOP_AST =  new TopBlockStmt($1);}
;

GlobalBlockStmt:
	GlobalStmtList {}
;

GlobalStmtList:
		  GlobalStmt  GlobalStmtList{ $$ = new ListAST($1,$2);}
		| ConstDecl{}
		| GlobalStmt{$$= new ListAST($1,NULL);}		
;
GlobalStmt:
	 SubDecl {}
	| ClassDecl {}
    | FieldDecl {}
    | FunctionDecl {$$ = $1;}
	| Stmt {$$ =$1;}	
;

ClassDecl:
	T_CLASS ExtendedID NL MemberDeclList T_END T_CLASS NL {}
;

MemberDeclList:
	MemberDecl MemberDeclList{}
    | {}
;

MemberDecl:
	FieldDecl {}
    | VarDecl {}
    | ConstDecl {}
    | SubDecl {}
    | FunctionDecl {}
    | PropertyDecl {}
;

PropertyDecl:
	MethodAccessOpt T_PROPERTY PropertyAccessType ExtendedID MethodArgList NL MethodStmtList T_END T_PROPERTY NL {}
;	
MethodAccessOpt:
	T_PUBLIC T_DEFAULT
    | AccessModifierOpt
;

MethodStmtList:
	MethodStmt MethodStmtList {}
    | {}
;

MethodStmt:
	ConstDecl {}
    | Stmt {}
;



AccessModifierOpt:
	T_PUBLIC {}
    | T_PRIVATE {}
    | {}
;

PropertyAccessType:
	T_GET
    | T_LET
    | T_SET
;

FieldDecl:
	T_PRIVATE FieldNameList  NL {}
    | T_PUBLIC FieldNameList  NL {}
;

FieldNameList:
	| FieldName ',' FieldNameList {}
	|FieldName {}
;

FieldName:
		FieldID '(' ArrayRankList ')'
        | FieldID
;

FieldID:
		ID
        | T_DEFAULT
        | T_ERASE
        | T_ERROR
        | T_EXPLICIT
        | T_STEP
;




ConstDecl:
	T_CONST ConstList NL {}
;
ConstList:
    ExtendedID '=' ConstExprDef ',' ConstList {}
    | ExtendedID '=' ConstExprDef {}
;
ConstExprDef:
	'(' ConstExprDef ')' {}
    | '-' ConstExprDef {}
    | '+' ConstExprDef {}
    | ConstExpr {}
;
ConstExpr:
	T_BOOL {$$= new BoolAST($1->value.bval);}
    | T_INTEGER { $$ = new LongAST($1->value.lval);/*cout<<"interger:"<<$1->value.lval<<endl;*/}
    | T_FLOAT {}
    | T_STRING {$$ = new StrAST($1->value.str.val);}
    | T_DATE {}
	| T_NOTHING {}
    | T_NULL {}
    | T_EMPTY {}
;


SubDecl:
	  T_SUB  ID MethodArgList NL  InnerBlockStmt T_END T_SUB NLOpt
	  {
	/*
		IdAST * id = dynamic_cast<IdAST*>($2);
		if(id==NULL){
			cout<<"function decl null"<<endl;
			exit(-1);
		}
		if(!CURRENT_SYMBOL_TABLE->Register(id->name)){
			cout<<"function redefine"<<endl;
			exit(-1);
		}
		Symbol * symbol = GLOBAL_SYMBOL_TABLE->Lookup(id->name);
		symbol->ReVal(new Function($3,$5));		
	*/		
		$$ = new FunctionDeclStmt($2,$3,$5);
	  }  
	  | T_SUB  ID MethodArgList Expr T_END T_SUB  NLOpt
	  {
		cout<<"sub decl"<<endl;
		$$ = NULL;
	  }
;

FunctionDecl:
    T_FUNCTION ID MethodArgList NL InnerBlockStmt T_END T_FUNCTION  NLOpt
	{
			$$ = NULL;
	}
    | T_FUNCTION ID MethodArgList Expr  T_END T_FUNCTION NLOpt 
	{
			$$ = NULL;
	}
;

MethodArgList:
	'(' ArgList ')' {$$=$2;}
    | '(' ')' {$$=new ListAST(NULL,NULL);}
    | { $$ = NULL;}
;
ArgList:
	Arg ',' ArgList { $$ = new ListAST($1,$3);}  
    | Arg {$$ = new ListAST($1,NULL);}
;
Arg:
	ArgModifierOpt ID '(' ')' { $$ = $2; }
    | ArgModifierOpt ID { $$ = $2;}
;
ArgModifierOpt:
	T_BYVAL { $$ = FLAG_BY_VAL;}
    | T_BYREF {$$ = FLAG_BY_REF;}
    | {$$ = FLAG_BY_NON;}
;
InnerBlockStmt:
	InnerStmtList {$$= new InnerBlockStmt($1);}
;

InnerStmtList:
	 InnerStmt InnerStmtList{$$ = new ListAST($1,$2);}
    | InnerStmt{$$= new ListAST($1,NULL);}
	| {$$=NULL;}
;

InnerStmt:
	ConstDecl {}
	| Stmt {$$=$1;}
;


Stmt:
	DimStmt {$$=$1; }
    | RedimStmt {}
    | IfStmt {$$ =$1;}
    | WithStmt  {}
    | SelectStmt { $$ = $1;}
    | LoopStmt {$$ = $1;}
    | ForStmt {$$=$1;}
    | ExprStmt  { $$ = $1;}	
	| NL {$$ = NULL;}
;

Eval:
	T_EVAL '(' Expr ')'
	{
		$$ = new Eval($3);	
	}
;

RedimStmt:
	T_REDIM RedimDeclList NL {}
    | T_REDIM  T_PRESERVE  RedimDeclList NL {}
;

RedimDeclList:
	RedimDecl ',' RedimDeclList {}
    | RedimDecl {}
;

RedimDecl:
	ExtendedID '(' ExprList ')' {}
;


DimStmt:
        T_DIM VarDeclList NL {$$ = new DimStmt($2);}
;
VarDeclList:
		VarDecl ',' VarDeclList {$$ = new ListAST($1,$3);}
		| VarDecl {$$ = new ListAST($1,NULL);}
;		
VarDecl:
        T_ID '(' ArrayRankList ')' {$$ = new ArrayVarDeclAST($1->value.str.val,$3);}
       | T_ID {$$ = new SimpleVarDeclAST($1->value.str.val);}
;
ArrayRankList:
	T_INTEGER ',' ArrayRankList 
	{
		$$ = new ListAST(new LongAST($1->value.lval),$3);
	}
    | T_INTEGER 
	{
		$$ = new ListAST(new LongAST($1->value.lval),NULL);
	}
;		
ExtendedID:
         ID { $$ = $1;}
;
						 
		 
IfStmt:
	T_IF  ConditionExpr T_THEN NL InnerBlockStmt NLOpt ElseStmtListOpt T_END  T_IF NL 
	{
		ListAST * l = new ListAST(new IfFlow($2,$5),NULL);
		l->push_back($7);
		$$ = new IfStmt(l);
	}
    | T_IF ConditionExpr T_THEN Expr ElseOpt EndIfOpt  NL
	{ 
		ListAST * l = new ListAST(new IfFlow($2,new ExprStmt($4)),NULL);		
		l->push_back(new ListAST($5,NULL));
		$$ = new IfStmt(l);
		//$$ = NULL;
	}
;
ConditionExpr:
	CmpExpr { $$= $1; }
	| Variable '='  ConstExpr { $$ = new EqualExpr($1,$3); } 
	| ConstExpr '='  ConstExpr { $$ = new EqualExpr($1,$3);}
	| Variable '='  Variable { $$ = new EqualExpr($1,$3); } 
;

ElseStmtListOpt:
	ElseStmtList {$$=$1;}
	| {$$ = NULL;}
;

ElseStmtList:
	  T_ELSEIF Expr T_THEN NL InnerBlockStmt ElseStmtList { $$ = new ListAST(new IfFlow($2,$5),$6);}
    | T_ELSEIF Expr T_THEN Expr NL ElseStmtList {$$ = new ListAST(new IfFlow($2,new ExprStmt($4)),$6);}
	| T_ELSE Expr NL {$$ = new ListAST(new IfFlow(new BoolAST(true),new ExprStmt($2)),NULL);}
	| T_ELSE NL InnerBlockStmt {$$ = new ListAST(new IfFlow(new BoolAST(true),$3),NULL);} 
	| {$$ = NULL;}
;
ElseOpt:
	T_ELSE Expr {$$ = new IfFlow(new BoolAST(true),new ExprStmt($2)); }
    | {$$= NULL;}
;
EndIfOpt:
	  T_END T_IF 
	  {
		/*纯为语意完整目的，没有什么解析必要*/
	  }
	| {/*纯为语意完整目的，没有什么解析必要*/}
;

	

WithStmt:
	T_WITH Expr NL InnerStmtList T_END T_WITH NL {}
;



LoopStmt:
	  T_DO T_UNTIL  ConditionExpr NL InnerBlockStmt  T_LOOP   NL 
	  {			
		$$ = new WhileStmt(new NotExpr($3),$5);
	  }
	| T_DO T_WHILE ConditionExpr NL InnerBlockStmt T_LOOP NL 
	  {		
		$$ = new WhileStmt($3,$5);
	  }    
	| T_DO NL InnerBlockStmt T_LOOP T_UNTIL ConditionExpr NL 
	  {
		$$ = new DoWhileStmt($3,new NotExpr($6));
	  }
	| T_DO NL InnerBlockStmt T_LOOP T_WHILE ConditionExpr NL 
	  {
		$$ = new DoWhileStmt($3,$6);
	  }
    | T_DO NL InnerBlockStmt T_LOOP NL 
	  {
		$$ = new DoWhileStmt($3,new BoolAST(true));
	  }
    | T_WHILE ConditionExpr NL InnerBlockStmt T_WEND NL 
	  {
		$$ = new WhileStmt($2,$4);
	  }
;




ForStmt:
	  T_FOR ID '=' Expr T_TO Expr StepOpt NL InnerBlockStmt T_NEXT NL 
	  {
		//cout<<"for ok"<<endl;
	    $$ = new ForStmt(new AssignExpr($2,$4),new SmallEqualExpr($2,$6),new AssignExpr($2,new AddExpr($2,$7)),$9);
	  }
	| T_FOR T_EACH ID T_IN Expr NL InnerBlockStmt T_NEXT NL 
	 {
		$$ = NULL;
	 }
;
StepOpt:
	  T_STEP Expr { $$ = $2;}
	| { $$ = new LongAST(1);}
;


SelectStmt:
	T_SELECT  T_CASE Expr NL CaseStmtList  T_END T_SELECT NL 
	{ 
		$$ = new SwitchStmt($3,$5);
	}
;
CaseStmtList:
	CaseStmtList CaseStmt
	  {
		//$$ =  new ListAST($1,$2);
		$$ = $1; 
		$$->push_back(new ListAST($2,NULL));
	  }
    | CaseStmt 
	{
		$$ = new ListAST($1,NULL);
	}
;

CaseStmt:
	 T_CASE ExprList NLOpt Stmt 
	  {
		$$ = new CaseFlow($2,$4); 
	  }
	| T_CASE  T_ELSE NLOpt Stmt 
	  { 	   
		$$ = new DefaultFlow($4);
	  }
;


ExprList:
	Expr ','  ExprList
	{
		$$ = new ListAST($1,$3);
	}
	| Expr	
	{
		$$ = new ListAST($1,NULL);
	}
;

ExprStmt:
	Expr NL { $$ = new ExprStmt($1);}
;

Expr:
	 Variable {$$=$1;}
	|ExprWithoutVariable {$$=$1;}
;

ExprWithoutVariable:
	  Variable '=' Expr {$$ = new AssignExpr($1,$3);}
	| Variable '=' T_BYREF Variable {$$ = new AssignExpr($1,new ByRefAST($4));}
	| T_CALL Variable { $$ = NULL;/*new CallExpr($2); cout<<"call abc"<<endl;*/}	
	| ErrorExpr {$$=$1;}
	| ExitExpr {$$=$1;}	
	| T_ERASE ID  {}
	| T_SET Variable '=' Expr {$$ = new AssignExpr($2,$4);}
	| T_SET Variable '=' T_NEW Variable {$$ = new AssignExpr($2,$5);}
	| Expr T_IMP Expr {}
	| Expr T_XOR Expr {}
	| Expr T_OR Expr {}
	| Expr T_AND Expr {}
	| T_NOT Expr {}
	| Expr T_IS Expr {}
	| CmpExpr {$$ =$1;}
    | Expr '&' Expr {$$ = new ConcatExpr($1,$3);}
	| Expr '+' Expr {$$ = new AddExpr($1,$3);}
	| Expr '-' Expr {}
	| Expr T_MOD Expr {}
	| Expr '\\' Expr {}
	| Expr '*' Expr {}
    | Expr '/' Expr {}
	| '-' Expr {  }
    | '+' Expr { $$ = $2;}
	| Expr '^' Expr {}
	| '(' Expr ')' { $$ = $2;}
	| ConstExpr {$$ = $1;}
	| T_PRINT '('Expr ')' {$$ = new Print($3); }
	| Eval { $$ = $1;}
;
CmpExpr:
      Expr T_BIG_EQV Expr {$$ = new GreatEqualExpr($1,$3);}
	| Expr T_EQV Expr {$$ = new EqualExpr($1,$3);}
    | Expr T_SMALL_EQV Expr { $$ = new SmallEqualExpr($1,$3);}
	| Expr T_NOT_EQV  Expr { $$ = new NotEqualExpr($1,$3);}
	| Expr '>'  Expr {$$ = new GreatThanExpr($1,$3);}
	| Expr '<'  Expr {$$ = new SmallThanExpr($1,$3);}
;

Variable:
	CompoundVariable VariableTailOpt {$$ = new VariableAST($1,$2);}
;

VariableTailOpt:
	 {$$= NULL;}
	| '.' VariableTailList {$$=$2;}
;

VariableTailList:
	CompoundVariable '.' VariableTailList{$$ = new ListAST($1,$3);}
	| CompoundVariable {$$ = new ListAST($1,NULL);}
;

CompoundVariable:
	  ID '(' CommaExprList ')' {  $$= new CompoundVariableAST($1,$3);}
    | ID '(' Expr ')' {$$= new CompoundVariableAST($1,new ListAST($3,NULL)); }
    | ID '(' ')' { $$= new CompoundVariableAST($1,new ListAST(NULL,NULL)); }
	| ID {$$= new CompoundVariableAST($1,NULL);}
;
	
ErrorExpr:
	T_ON T_ERROR T_RESUME T_NEXT {}
    | T_ON T_ERROR T_GOTO  T_INTEGER {}
;

ExitExpr:
	T_EXIT  T_DO { $$ = new BreakStmt(); }
    | T_EXIT T_FOR { $$ = new BreakStmt();}
    | T_EXIT T_FUNCTION { $$ = new ReturnStmt();}
    | T_EXIT T_PROPERTY {$$ = new ReturnStmt();}
    | T_EXIT T_SUB {$$ = new ReturnStmt();}
;




CommaExprList:
	Expr ',' CommaExprList {$$ = new ListAST($1,$3);}
    | Expr {$$ = new ListAST($1,NULL);}
	| {$$ =NULL;}
;




ID:
	T_ID 
	{ 
		//$$ = new SimpleVariableAST($1->value.str.val);
		//cout<<"id"<<endl;
		$$ = new IdAST($1->value.str.val);
		//cout<<"var:"<<$1->value.str.val<<endl;
	}
;


%%

void yyerror(const char *s)
{
	
}

int main(int argc, char *argv[])
{
	
	
	/*
	if(!core_init(argc,argv)){
		return -1;
	}
	*/
	CURRENT_TOP_AST=NULL;
	//cout<<"before yyparse"<<endl;
	yyparse();
	//cout<<"after yyparse"<<endl;
	begin_to_parse(CURRENT_TOP_AST);

	return 0;
}
