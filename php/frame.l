%{
#include "main.hpp"
#include "frame.tab.h"
#include <iostream>
#include <errno.h>
#include <strings.h>

using namespace std;
extern "C"{
	int yywrap(void);
	int yylex(void);
}



char *strndup( const char *s, size_t n)
{
	
	if(n==0){
		return NULL;
	}
	size_t nn = strlen(s);
	if(n<nn){
		nn = n;
	}
	char * t = new char[nn+1];
	for(size_t i=0;i<nn;i++)
	{
		t[i]=s[i];
	}
	t[nn]='\0';
	
	return t;
}
double zend_oct_strtod(const char *str, char **endptr);

string temp_string;
int i;
%}




LNUM	[0]|[1-9][0-9]*
DNUM	([0-9]*"."[0-9]+)|([0-9]+"."[0-9]*)
EXPONENT_DNUM	(({LNUM}|{DNUM})[eE][+-]?{LNUM})
HNUM	"0x"[0-9a-fA-F]+
BNUM	"0b"[01]+
LABEL	[a-zA-Z_\x7f-\xff][a-zA-Z0-9_\x7f-\xff]*
WHITESPACE [ \n\r\t]+
TABS_AND_SPACES [ \t]*
TOKENS [;:,.\[\]()|^&+-/*=%!~$<>?@]
ANY_CHAR [^]
NEWLINE ("\r"|"\n"|"\r\n")

%x ST_IN_SCRIPTING
%x ST_IN_FULL_COMMENT
%x ST_LOOKING_FOR_PROPERTY
%x ST_VAR_OFFSET
%x ST_DOUBLE_QUOTES

%%

<ST_IN_SCRIPTING>"exit" {
	return T_EXIT;
}

<ST_IN_SCRIPTING>"die" {
	return T_EXIT;
}

<ST_IN_SCRIPTING>"print" {
	return T_PRINT;
}

<ST_IN_SCRIPTING>"function" {    
	return T_FUNCTION;
}

<ST_IN_SCRIPTING>"const" {
	return T_CONST;
}

<ST_IN_SCRIPTING>"return" {
	return T_RETURN;
}

<ST_IN_SCRIPTING>"try" {
	return T_TRY;
}

<ST_IN_SCRIPTING>"catch" {
	return T_CATCH;
}

<ST_IN_SCRIPTING>"throw" {
	return T_THROW;
}

<ST_IN_SCRIPTING>"if" {
	return T_IF;
}

<ST_IN_SCRIPTING>"elseif" {
	return T_ELSEIF;
}

<ST_IN_SCRIPTING>"endif" {
	return T_ENDIF;
}

<ST_IN_SCRIPTING>"else" {
	return T_ELSE;
}

<ST_IN_SCRIPTING>"while" {
	return T_WHILE;
}

<ST_IN_SCRIPTING>"endwhile" {
	return T_ENDWHILE;
}

<ST_IN_SCRIPTING>"do" {
	return T_DO;
}

<ST_IN_SCRIPTING>"for" {
	return T_FOR;
}

<ST_IN_SCRIPTING>"endfor" {
	return T_ENDFOR;
}

<ST_IN_SCRIPTING>"foreach" {
	return T_FOREACH;
}

<ST_IN_SCRIPTING>"endforeach" {
	return T_ENDFOREACH;
}

<ST_IN_SCRIPTING>"as" {
	return T_AS;
}

<ST_IN_SCRIPTING>"switch" {
	return T_SWITCH;
}

<ST_IN_SCRIPTING>"endswitch" {
	return T_ENDSWITCH;
}

<ST_IN_SCRIPTING>"case" {
	return T_CASE;
}

<ST_IN_SCRIPTING>"default" {
	return T_DEFAULT;
}

<ST_IN_SCRIPTING>"break" {
	return T_BREAK;
}

<ST_IN_SCRIPTING>"continue" {
	return T_CONTINUE;
}

<ST_IN_SCRIPTING>"goto" {
	return T_GOTO;
}

<ST_IN_SCRIPTING>"global" {
	return T_GLOBAL;
}

<ST_IN_SCRIPTING>"isset" {
	return T_ISSET;
}


<ST_IN_SCRIPTING>"unset" {
	return T_UNSET;
}

<ST_IN_SCRIPTING>"=>" {
	
	return T_DOUBLE_ARROW;
}

<ST_IN_SCRIPTING>"array" {
	
	return T_ARRAY;
}

<ST_IN_SCRIPTING>"++" {
	return T_INC;
}

<ST_IN_SCRIPTING>"--" {
	return T_DEC;
}

<ST_IN_SCRIPTING>"===" {
	return T_IS_IDENTICAL;
}

<ST_IN_SCRIPTING>"!==" {
	return T_IS_NOT_IDENTICAL;
}

<ST_IN_SCRIPTING>"==" {
	return T_IS_EQUAL;
}

<ST_IN_SCRIPTING>"!="|"<>" {
	return T_IS_NOT_EQUAL;
}

<ST_IN_SCRIPTING>"<=" {
	return T_IS_SMALLER_OR_EQUAL;
}

<ST_IN_SCRIPTING>">=" {
	return T_IS_GREATER_OR_EQUAL;
}

<ST_IN_SCRIPTING>"+=" {
	return T_PLUS_EQUAL;
}

<ST_IN_SCRIPTING>"-=" {
	return T_MINUS_EQUAL;
}

<ST_IN_SCRIPTING>"*=" {
	return T_MUL_EQUAL;
}

<ST_IN_SCRIPTING>"/=" {
	return T_DIV_EQUAL;
}

<ST_IN_SCRIPTING>".=" {
	return T_CONCAT_EQUAL;
}

<ST_IN_SCRIPTING>"%=" {
	return T_MOD_EQUAL;
}

<ST_IN_SCRIPTING>"<<=" {
	return T_SL_EQUAL;
}

<ST_IN_SCRIPTING>">>=" {
	return T_SR_EQUAL;
}

<ST_IN_SCRIPTING>"&=" {
	return T_AND_EQUAL;
}

<ST_IN_SCRIPTING>"|=" {
	return T_OR_EQUAL;
}

<ST_IN_SCRIPTING>"^=" {
	return T_XOR_EQUAL;
}

<ST_IN_SCRIPTING>"||" {
	return T_BOOLEAN_OR;
}

<ST_IN_SCRIPTING>"&&" {
	return T_BOOLEAN_AND;
}

<ST_IN_SCRIPTING>"OR" {
	return T_LOGICAL_OR;
}

<ST_IN_SCRIPTING>"AND" {
	return T_LOGICAL_AND;
}

<ST_IN_SCRIPTING>"XOR" {
	return T_LOGICAL_XOR;
}

<ST_IN_SCRIPTING>"<<" {
	return T_SL;
}

<ST_IN_SCRIPTING>">>" {
	return T_SR;
}


<ST_IN_SCRIPTING>{TOKENS} {
	return yytext[0];
}

<ST_IN_SCRIPTING>"{" {
	return '{';
}



<ST_IN_SCRIPTING>"}" {
	return '}';
}

<ST_IN_SCRIPTING>"\\" {
	return T_NS_SEPARATOR;
}


<ST_IN_SCRIPTING>{LNUM} {
	/*
		#if SIZEOF_LONG == 4
		#define MAX_LENGTH_OF_LONG 11
		static const char long_min_digits[] = "2147483648";
		#elif SIZEOF_LONG == 8
		#define MAX_LENGTH_OF_LONG 20
		static const char long_min_digits[] = "9223372036854775808";
		#else
		#error "Unknown SIZEOF_LONG"
		#endif
	*/
	yylval.zv = new zval;
	if (yyleng < 11 - 1) { /* Won't overflow */
		yylval.zv->value.lval = strtol(yytext, NULL, 0);
	} else {
		errno = 0;
		yylval.zv->value.lval = strtol(yytext, NULL, 0);
		if (errno == ERANGE) { /* Overflow */
			if (yytext[0] == '0') { /* octal overflow */
				yylval.zv->value.dval = zend_oct_strtod(yytext, NULL);
			} else {
				yylval.zv->value.dval =  strtod(yytext, NULL);
			}
			yylval.zv->type = IS_DOUBLE;
			return T_DNUMBER;
		}
	}

	yylval.zv->type = IS_LONG;
	return T_LNUMBER;
	/*
	
	yylval.zv->value.lval = strtol(yytext,NULL,10);
	
	yylval.zv->type = IS_LONG; 
	return T_LNUMBER;
	*/
}


<ST_IN_SCRIPTING>{HNUM} {
	yylval.zv = new zval;
	char *hex = yytext + 2; /* Skip "0x" */
	int len = yyleng - 2;

	/* Skip any leading 0s */
	while (*hex == '0') {
		hex++;
		len--;
	}

	if (len == 0) {
		yylval.zv->value.lval = 0;
	} else {
		 yylval.zv->value.lval = strtol(hex,NULL,16);
	}
	yylval.zv->type = IS_LONG; 
	return T_DNUMBER;
}

<ST_IN_SCRIPTING>{DNUM}|{EXPONENT_DNUM} {
	yylval.zv = new zval;
	yylval.zv->value.dval = strtod(yytext, NULL);
	yylval.zv->type = IS_DOUBLE; 
	
	return T_DNUMBER;
}

<ST_VAR_OFFSET>[0]|([1-9][0-9]*) { /* Offset could be treated as a long */

		/*
		#if SIZEOF_LONG == 4
		#define MAX_LENGTH_OF_LONG 11
		static const char long_min_digits[] = "2147483648";
		#elif SIZEOF_LONG == 8
		#define MAX_LENGTH_OF_LONG 20
		static const char long_min_digits[] = "9223372036854775808";
		#else
		#error "Unknown SIZEOF_LONG"
		#endif
	*/
	
	if (yyleng < 11 - 1 || (yyleng == 11 - 1 && strcmp(yytext, "2147483648") < 0)) {
		yylval.zv->value.lval = strtol(yytext, NULL, 10);
		yylval.zv->type = IS_LONG;
	} else {
		yylval.zv->value.str.val = (char *)strndup(yytext, yyleng);
		yylval.zv->value.str.len = yyleng;
		yylval.zv->type = IS_STRING;
	}
	return T_NUM_STRING;
}

<ST_VAR_OFFSET>{LNUM}|{HNUM}|{BNUM} { /* Offset must be treated as a string */
	yylval.zv->value.str.val = (char *)strndup(yytext, yyleng);
	yylval.zv->value.str.len = yyleng;
	yylval.zv->type = IS_STRING;
	return T_NUM_STRING;
}

<ST_IN_SCRIPTING,ST_DOUBLE_QUOTES>"$"{LABEL} {
	
	yylval.zv = new zval;
	yylval.zv->value.str.val = (char *) strndup(yytext+1, yyleng-1); 
	yylval.zv->value.str.len = yyleng-1;
	
	
	return T_VARIABLE;
}

<ST_IN_SCRIPTING,ST_DOUBLE_QUOTES,ST_VAR_OFFSET>"$"{LABEL} {
	
	yylval.zv = new zval;
	yylval.zv->value.str.val = (char *) strndup(yytext, yyleng); 
	yylval.zv->value.str.len = yyleng;	
	return T_STRING;
}

<ST_IN_SCRIPTING>b?['] {
	string s ="";
	while (1) {
		char c = yyinput();
		if(c==EOF){
			cout<<"error on DOUBLE QUOTE"<<endl;
			exit(-1);
		}
		if(c=='\\'){
			char d = yyinput();
			if(d==EOF){
				cout<<"error on DOUBLE QUOTE2"<<endl;
				exit(-1);
			}else if(d=='r'){
				c ='\r';
			}else if(d=='n'){
				c ='\n';
			}else if(d=='t'){
				c ='\t';
			}else{
				c=d;
			}
		}
		if(c=='\''){
				yylval.zv = new zval;
				yylval.zv->value.str.val = (char *) strndup(s.c_str(), s.size()); 
				yylval.zv->value.str.len = s.size();
				return T_CONSTANT_ENCAPSED_STRING;
		}
		s+=c;
	}
}
<ST_IN_SCRIPTING>b?["] {
	string s ="";
	while (1) {
		char c = yyinput();
		if(c==EOF){
			cout<<"error on DOUBLE QUOTE"<<endl;
			exit(-1);
		}
		if(c=='\\'){
			char d = yyinput();
			if(d==EOF){
				cout<<"error on DOUBLE QUOTE2"<<endl;
				exit(-1);
			}else if(d=='r'){
				c ='\r';
			}else if(d=='n'){
				c ='\n';
			}else if(d=='t'){
				c ='\t';
			}else{
				c=d;
			}
		}
		if(c=='"'){
				yylval.zv = new zval;
				yylval.zv->value.str.val = (char *) strndup(s.c_str(), s.size()); 
				yylval.zv->value.str.len = s.size();
				return T_CONSTANT_ENCAPSED_STRING;
		}
		s+=c;
	}
}

<ST_DOUBLE_QUOTES>["] { 
	return '"';
}

<INITIAL>"<?php"([ \t]|{NEWLINE}) {
	BEGIN ST_IN_SCRIPTING ;
}


<ST_IN_SCRIPTING>"#"|"//" {	
	for(;;)
	{
		char c = yyinput();
		if(c == EOF){
			cout<<"error on comment 1"<<endl;
			exit(-1);
		} 
		
		if(c=='\r' || c=='\n')
			break;			
	}
}

<ST_IN_SCRIPTING,ST_VAR_OFFSET>{LABEL} {
	yylval.zv = new zval;
	yylval.zv->value.str.val = (char *)strndup(yytext, yyleng);
	yylval.zv->value.str.len = yyleng;
	yylval.zv->type = IS_STRING;
	return T_STRING;
}

<ST_IN_SCRIPTING>"/*"|"/**"{WHITESPACE} {
	char d = yyinput();
	if(d == EOF){
			cout<<"error on comment 2"<<endl;
			exit(-1);
	} 
		
	for(;;)
	{
		char c = yyinput();
		if(c == EOF){
			cout<<"error on comment 3"<<endl;
			exit(-1);
		} 		
		if(d=='*' || c=='/'){
			break;			
		}else{
			d = c;
		}
	}	
}
<ST_IN_SCRIPTING>("?>"){NEWLINE}? {
	BEGIN INITIAL ;
}

<ST_IN_SCRIPTING>.|[\n] { }

<INITIAL>.* { }

<<EOF>> { return _EOF;}

%%
double zend_oct_strtod(const char *str, char **endptr)
{
	const char *s = str;
	char c;
	double value = 0;
	int any = 0;

	/* skip leading zero */
	s++;

	while ((c = *s++)) {
		if (c < '0' || c > '7') {
			/* break and return the current value if the number is not well-formed
			 * that's what Linux strtol() does 
			 */
			break;
		}
		value = value * 8 + c - '0';
		any = 1;
	}

	if (endptr != NULL) {
		*endptr = (char *)(any ? s - 1 : str);
	}

	return value;
}
int yywrap(void)
{
	return 1;
}
