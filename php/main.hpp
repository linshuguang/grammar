#pragma once
#include<string>



typedef struct _zval_struct zval;  

typedef union _zvalue_value {  
    long lval;  /* long value */  
    double dval;    /* double value */  
    struct {  
        char *val;  
        int len;  
    } str;  
    //HashTable *ht;  /* hash table value */  
    //zend_object_value obj;  
} zvalue_value;  

struct _zval_struct {  
    /* Variable information */  
    zvalue_value value;     /* value */  
    unsigned int refcount__gc;  
    unsigned char type;    /* active type */  
    unsigned char is_ref__gc;  
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

