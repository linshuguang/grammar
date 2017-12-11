#pragma once
#include<map>
#include<string>
#include<vector>
#include "sym.hpp"
#include "adt.hpp"
typedef bool (*MOD_REGISTER_WRAPPER)(SymbolTable *); 
typedef ADT* (*MOD_FUNC_WRAPPER)(ListADT *); 
struct module_t {
    const char * func_name;
	MOD_FUNC_WRAPPER func_wrapper;
};

class Mod{
	static Mod* _instance;
	static std::map<std::string,std::string> mod_array;
public:
	static Mod * Instance()
    {
		if( 0== _instance){			
			_instance = new Mod;
		}
		return _instance;
    }
	bool LoadMod(const std::string &name,const std::string &path);
	bool Register( SymbolTable * symtbl);
	Mod();
	~Mod();
};



