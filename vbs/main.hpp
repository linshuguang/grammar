#pragma once
#include<string>
#include<vector>
#include "sym.hpp"
#include "adt.hpp"
#include "ast.hpp"
#include "mod.hpp"
#include "conf.hpp"
#include "color.hpp"

typedef struct _zval_struct zval;  

typedef union _zvalue_value {  
    long lval;  /* long value */  
    double dval;    /* double value */  
    struct {  
        char *val;  
        int len;  
    } str;  
	bool bval;
    //HashTable *ht;  /* hash table value */  
    //zend_object_value obj;  
} zvalue_value;  

struct _zval_struct {  
    /* Variable information */  
    zvalue_value value;     /* value */  
};  

enum znode_type{
	IS_NULL,
	IS_LONG,
	IS_DOUBLE,
	IS_BOOL,
	IS_ARRAY,
	IS_OBJECT,
	IS_STRING,
	IS_RESOURCE,
	IS_CONSTANT,
	IS_CONSTANT_ARRAY,	
};

//extern class SymbolTable *symtab;
//extern class SymbolTable GlobalSymbolTable;
//extern class SymTabStack symtab_stack;




class Extension{
	
};
bool core_init(int argc, char *argv[]);
bool begin_to_parse(AST *);

extern class AST * top_ast;
extern vector<AST *> top_ast_stack;


#define CURRENT_TOP_AST (top_ast)
#define CURRENT_TOP_AST_STACK (top_ast_stack)
#define PUSH_TOP_AST() do{CURRENT_TOP_AST_STACK.push_back(CURRENT_TOP_AST);CURRENT_TOP_AST=NULL;}while(0);
#define POP_TOP_AST() do{CURRENT_TOP_AST=CURRENT_TOP_AST_STACK[CURRENT_TOP_AST_STACK.size()];CURRENT_TOP_AST_STACK.pop_back();}while(0);

extern int yyparse ();
extern int yylineno;
extern "C" {
	int yylex ();
	
	//void yyrestart(FILE*);
}

//extern int yyrestart(FILE*);
extern FILE  *yyin,* yyout;

