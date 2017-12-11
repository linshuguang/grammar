#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "function.hpp"


using namespace std;


extern "C" {
	bool register_module(SymbolTable * symtbl);
}


static module_t modules[] = {		
	{"function_exists",function_exists_wrapper},
	{"is_callable",is_callable_wrapper},

};

bool register_module(SymbolTable * symtbl)
{
	for(size_t i=0;i<sizeof(modules)/sizeof(module_t);i++)
	{
		symtbl->Register(modules[i].func_name,(void *)modules[i].func_wrapper);
	}
	return true;
}

ADT* function_exists(ADT *function_name);
ADT * is_callable(ADT *function_name,ADT * syntax_only,ADT * callable_name);

ADT* function_exists_wrapper(ListADT *param_list)
{
	if(param_list==NULL){
		return NULL;
	} 
	ADT * function_name = param_list->l;
	return function_exists(function_name);
}
ADT* is_callable_wrapper(ListADT *param_list)
{
	if(param_list==NULL){
		return NULL;
	} 
	ADT * function_name = param_list->l;
	ListADT * next = dynamic_cast<ListADT*>(param_list->r);
	if(next==NULL){
		return NULL;
	}
	ADT * syntax_only = next->l;
	ADT * callable_name = NULL;
	next = dynamic_cast<ListADT*>(next->r);
	if(next!=NULL){
		callable_name = next->l;
	}	
	return is_callable(function_name,syntax_only,callable_name);
}

ADT* function_exists(ADT *_function_name)
{
	StrADT * function_name = dynamic_cast<StrADT*>(_function_name);
	if(function_name==NULL){
		return NULL;
	}
	string s = function_name->Str();
	if(GLOBAL_FUNCTION_TABLE->Lookup(s.c_str())!=NULL){
		return new BoolADT(true);
	}
	if(MOD_FUNCTION_TABLE ->Lookup(s.c_str())!=NULL){
		return new BoolADT(true);
	}
	return new BoolADT(false);
}
ADT* is_callable(ADT * _function_name,ADT * _syntax_only,ADT * _callable_name)
{
	
	return function_exists(_function_name);
}
