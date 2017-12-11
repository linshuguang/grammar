#pragma once
#include<vector>
#include<string>
//#include "adt.hpp"
using namespace std;

/* symbol table */

class Symbol{		/* a variable name */
protected:
	char *name;
	void * val;
public:
	Symbol(const char * _name,void *_val); 
	Symbol();
	virtual ~Symbol();
	virtual char * c_name(){return this->name;}
	virtual bool IsEmpty();
	virtual void ReName( const char * sym );
	virtual void ReVal( void*_val );
	virtual void * GetVal( );
	virtual Symbol * Duplicate();
	friend class SymbolTable;
};

class SymRef:public Symbol{		/* a variable name */
	virtual Symbol * FindSymbol();
public:
	SymRef(const char * _name,void *_val):Symbol(_name,_val)
	{
		
	}
	SymRef(const char * _name):Symbol(_name,NULL)
	{
		
	}
	SymRef():Symbol()
	{
	
	}
	virtual ~SymRef()
	{
	
	}
	virtual Symbol * Duplicate();
	virtual void ReVal( void*_val );
	virtual void * GetVal( );
};
class GlobalSymRef:public SymRef{		/* a variable name */
	virtual Symbol * FindSymbol();
public:
	GlobalSymRef(const char * _name,void *_val):SymRef(_name,_val){}
	GlobalSymRef(const char * _name):SymRef(_name,NULL){}
	GlobalSymRef():SymRef(){}
	virtual Symbol * Duplicate();
	~GlobalSymRef(){}
};
class SymbolTable{
private :
	int TabSize;
	Symbol **symtab;
	bool Init();
	/* simple symtab of fixed size */
	unsigned SymHash(const char *sym);
	Symbol **LookupEmptyInternal(const char* sym);
	Symbol **LookupInternal(const char*_sym);

public:
	SymbolTable(int _TabSize);
	SymbolTable();
	virtual ~SymbolTable();
	Symbol *Lookup(const char*_sym);
	//Symbol *Lookfor(const char*_sym);
	virtual SymbolTable * Dump();
	virtual void Print();
	virtual bool Register(const char*_sym);
	virtual bool Register(const char*_sym,void *_val);
	virtual bool RegisterRef(const char*_sym);
	virtual bool RegisterGlobalRef(const char*_sym);
	virtual bool UnRegister(const char*_sym);
};
#define NEW_SYMBOL_TABLE() ( new SymbolTable())
#define SYMBOL_TABLE_STACK ( SymTabStack::Instance())
#define CURRENT_SYMBOL_TABLE (SYMBOL_TABLE_STACK->Top())
#define GLOBAL_SYMBOL_TABLE (SYMBOL_TABLE_STACK->Global())
#define GLOBAL_FUNCTION_TABLE (SYMBOL_TABLE_STACK->UserFunction())
#define MOD_FUNCTION_TABLE (SYMBOL_TABLE_STACK->ModFunction())



class SymbolTable;


class SymTabStack{	
	SymTabStack();
	virtual ~SymTabStack();
	static SymbolTable _mod_function;
	static SymbolTable _user_function;
	static SymbolTable _global;
	static SymTabStack* _instance;
	static vector<SymbolTable*> _stack;
public:
	static SymTabStack * Instance()
    {
		if( 0== _instance){			
			_instance = new SymTabStack;
			_stack.push_back(&_global);
		}
		return _instance;
    }
	virtual SymbolTable* UserFunction();
	virtual SymbolTable* ModFunction();
	virtual SymbolTable* Global();
	virtual void Push(SymbolTable*);
	virtual SymbolTable* Pop();
	virtual SymbolTable* Top();
};


