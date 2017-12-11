%option noyywrap
%option nounput 
%option case-insensitive

UCN	(\\u[0-9a-fA-F]{4}|\\U[0-9a-fA-F]{8})

%{
#include "main.hpp"
#include "frame.tab.h"
#include <iostream>
#include <errno.h>
#include <strings.h>

using namespace std;
extern "C"{
	int yylex(void);
}

char *strndup( const char *s, size_t n);
bool extract_string(zval * zv,bool flag);
%}

%x ST_IN_SCRIPTING
%x ST_IN_FULL_COMMENT

%%

<INITIAL>"<%" { 
	//cout<<"begin vbs"<<endl;
	BEGIN ST_IN_SCRIPTING;
}
<ST_IN_SCRIPTING>"%>" { 
	BEGIN INITIAL;
	//cout<<endl<<"end vbs"<<endl;
}

<ST_IN_SCRIPTING>^[ \t]*"Rem".* { 	
	//cout<<"rem注释"<<yytext<<endl;
}

<ST_IN_SCRIPTING>"//".* { 
	//cout<<"单行注释//"<<endl;
}

<ST_IN_SCRIPTING>"/\*"([^*]|\*+[^/*])*\*+"/" { 
	//cout<<"多行注释注释"<<endl;
}



<ST_IN_SCRIPTING>"\r\n"|"\r"|"\n"|":" {
	//cout<<"new line :"<<yyleng<<endl;
	return T_NEW_LINE;
}

<ST_IN_SCRIPTING>"#"[\x20-\x22\x24-\x7e]+"#" { //不包含'#'的可打印字符
	//cout<<"date"<<endl;
	return T_DATE;
}

<ST_IN_SCRIPTING>[:alnum:]+"."[:alnum:]+("E"[+-]?[:alnum:]+)? {
	//cout<<"float"<<endl;
	yylval.zv = new zval;
	yylval.zv->value.dval = strtod(yytext,NULL);
	return T_FLOAT;
}

<ST_IN_SCRIPTING>[:alnum:]+"E"[+-]?[:alnum:]+ {
	//cout<<"float2"<<endl;
	yylval.zv = new zval;
	yylval.zv->value.dval = strtod(yytext,NULL);
	return T_FLOAT;
}
			   

<ST_IN_SCRIPTING>"&H"[[:alnum:][:alpha:]]+"&"? {
	//cout<<"hex"<<endl;
	yylval.zv = new zval;
	yylval.zv->value.lval = strtol(yytext+2,NULL,8);
	return T_INTEGER;
}

<ST_IN_SCRIPTING>"&"[0-7]+"&"? {
	//cout<<"oct"<<endl;
	yylval.zv = new zval;
	yylval.zv->value.lval = strtol(yytext+1,NULL,8);	
	return T_INTEGER;
}

<ST_IN_SCRIPTING>[0-9]+ {
	//cout<<"decimal:"<<yytext<<endl;
	yylval.zv = new zval;
	yylval.zv->value.lval = strtol(yytext,NULL,0);
	return T_INTEGER;
}

<ST_IN_SCRIPTING>L?\"([^\"\\]|\\['"?\\abfnrtv]|\\[0-7]{1,3}|\\[Xx][0-9a-fA-F]+|{UCN})+\" {
	//cout<<" \" flex found string:"<<yytext<<endl;
	yylval.zv = new zval;
	yylval.zv->value.str.val = strndup(yytext+1,yyleng-2);
	//cout<<"flex extract string:"<<yylval.zv->value.str.val<<endl<<endl;
	return T_STRING;
}

<ST_IN_SCRIPTING>L?\'([^'\\]|\\['"?\\abfnrtv]|\\[0-7]{1,3}|\\[Xx][0-9a-fA-F]+|{UCN})+\' {
	//cout<<" \' flex found string:"<<yytext<<endl;
	yylval.zv = new zval;
	yylval.zv->value.str.val = strndup(yytext+1,yyleng-2);
	//cout<<"flex extract string:"<<yylval.zv->value.str.val<<endl<<endl;
	return T_STRING;
}
 

<ST_IN_SCRIPTING>"Option" {
	return T_OPTION;
}

<ST_IN_SCRIPTING>"Explicit" {
	return T_EXPLICIT;
}

<ST_IN_SCRIPTING>"Dim" {
	return T_DIM;
}
<ST_IN_SCRIPTING>"Default" {
	return T_DEFAULT;
}

<ST_IN_SCRIPTING>"Erase" {
	return T_ERASE;
}

<ST_IN_SCRIPTING>"Error" {
	return T_ERROR;
}


<ST_IN_SCRIPTING>"Step" {
	return T_STEP;
}

<ST_IN_SCRIPTING>"Set" {
	return T_SET;
}

<ST_IN_SCRIPTING>"New" {
	return T_NEW;
}

<ST_IN_SCRIPTING>"Imp" {
	return T_IMP;
}

<ST_IN_SCRIPTING>"Property" {
	return T_PROPERTY;
}

<ST_IN_SCRIPTING>"Eqv" {
	return T_EQV;
}

<ST_IN_SCRIPTING>"Xor" {
	return T_XOR;
}

<ST_IN_SCRIPTING>"Add" {
	return T_ADD;
}

<ST_IN_SCRIPTING>"Not" {
	return T_NOT;
}

<ST_IN_SCRIPTING>"Mod" {
	return T_MOD;
}

<ST_IN_SCRIPTING>"True" {
	yylval.zv = new zval;
	yylval.zv->value.bval= true;
	return T_BOOL;
}

<ST_IN_SCRIPTING>"False" {
	yylval.zv = new zval;
	yylval.zv->value.bval= false;
	return T_BOOL;
}

<ST_IN_SCRIPTING>"Nothing" {
	return T_NOTHING;
}

<ST_IN_SCRIPTING>"Null" {
	return T_NULL;
}

<ST_IN_SCRIPTING>"Empty" {
	return T_EMPTY;
}

<ST_IN_SCRIPTING>"Call" {
	return T_CALL;
}

<ST_IN_SCRIPTING>"Resume" {
	return T_RESUME;
}

<ST_IN_SCRIPTING>"Goto" {
	return T_GOTO;
}

<ST_IN_SCRIPTING>"Sub" {
	return T_SUB;
}

<ST_IN_SCRIPTING>"Function" {
	return T_FUNCTION;
}

<ST_IN_SCRIPTING>"For" {
	return T_FOR;
}

<ST_IN_SCRIPTING>"Do" {
	return T_DO;
}
<ST_IN_SCRIPTING>"End" {
	return T_END;
}

<ST_IN_SCRIPTING>"Exit" {
	return T_EXIT;
}

<ST_IN_SCRIPTING>"Public" {
	return T_PUBLIC;
}


<ST_IN_SCRIPTING>"Private" {
	return T_PRIVATE;
}

<ST_IN_SCRIPTING>"ByVal" {
	return T_BYVAL;
}

<ST_IN_SCRIPTING>"ByRef" {
	return T_BYREF;
}

<ST_IN_SCRIPTING>"Const" {
	return T_CONST;
}

<ST_IN_SCRIPTING>"If" {
	return T_IF;
}

<ST_IN_SCRIPTING>"Then" {
	return T_THEN;
}

<ST_IN_SCRIPTING>"Else" {
	return T_ELSE;
}

<ST_IN_SCRIPTING>"ElseIf" {
	return T_ELSEIF;
}

<ST_IN_SCRIPTING>"ReDim" {
	return T_REDIM;
}

<ST_IN_SCRIPTING>"Preserve" {
	return T_PRESERVE;
}

<ST_IN_SCRIPTING>"With" {
	return T_WITH;
}

<ST_IN_SCRIPTING>"Loop" {
	return T_LOOP;
}

<ST_IN_SCRIPTING>"While" {
	return T_WHILE;
}

<ST_IN_SCRIPTING>"Wend" {
	return T_WEND;
}

<ST_IN_SCRIPTING>"Until" {
	return T_UNTIL;
}

<ST_IN_SCRIPTING>"To" {
	
	return T_TO;
}

<ST_IN_SCRIPTING>"Next" {
	
	return T_NEXT;
}

<ST_IN_SCRIPTING>"In" {
	return T_IN;
}

<ST_IN_SCRIPTING>"Each" {
	return T_EACH;
}

<ST_IN_SCRIPTING>"Select" {
	return T_SELECT;
}

<ST_IN_SCRIPTING>"Case" {
	return T_CASE;
}

<ST_IN_SCRIPTING>"Print" {
	//cout<<yytext<<endl;
	return T_PRINT;
}


<ST_IN_SCRIPTING>"Eval" {
	return T_EVAL;
}

<ST_IN_SCRIPTING>"Execute" {
	return T_EXECUTE;
}

<ST_IN_SCRIPTING>">="|"=>" {
	return T_BIG_EQV;
}

<ST_IN_SCRIPTING>"<="|"=<" {
	return T_SMALL_EQV;
}

<ST_IN_SCRIPTING>"<>" {
	return T_NOT_EQV;
}



<ST_IN_SCRIPTING>[\/\\,=<>&+\-*^.()] {
	//if(yytext[0]==')' || yytext[0]=='('){
	//	cout<<"flex:"<<yytext<<endl;
	//}
	//cout<<yytext[0]<<endl;
	return yytext[0];
}

<ST_IN_SCRIPTING>[\t \r\n] {
	
}

<ST_IN_SCRIPTING>[a-z][a-z[:alnum:]_]* {
	//cout<<"ID:"<<yytext<<endl;
	yylval.zv = new zval;
	yylval.zv->value.str.val = (char *)strndup(yytext, yyleng);
	return T_ID;
}


<ST_IN_SCRIPTING>. { 
	cout<<"other:"<<yytext<<" leng:"<<yyleng <<endl;
}



%%
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
	
	size_t i,j;
	for(i=0,j=0;i<nn;i++)
	{
		char c ;
		c = s[i];
		if(c=='\\'){
			i++;
			if(i>=nn){
				break;
			}
			char d = s[i];
			if(d=='r'){
				c='\r';
			}else if(d=='n'){
				c='\n';
			}else if(d=='t'){
				c='\t';
			}else{
				c=d;
			}
		}
		t[j++]=c;
	}
	t[j]='\0';
	
	return t;
}
bool extract_string(zval * zv,bool flag)
{
	string s ="";
	while (1) {
		char c = yyinput();
		if(c==EOF){
			cout<<"encounter eof"<<endl;
			exit(-1);
		}
		if(c=='\\'){
			char d = yyinput();
			if(d==EOF){
				cout<<"encounter eof 2"<<endl;
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
		if(c==flag && zv!=NULL){
				zv->value.str.val = (char *) strndup(s.c_str(), s.size()); 
				zv->value.str.len = s.size();
				return true;
		}
		s+=c;
	}
	return false;
}

