#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "ereg.hpp"


using namespace std;


extern "C" {
	bool register_module(SymbolTable * symtbl);
}


static module_t modules[] = {
	{"eregi",eregi_wrapper},
};

bool register_module(SymbolTable * symtbl)
{
	for(size_t i=0;i<sizeof(modules)/sizeof(module_t);i++)
	{
		symtbl->Register(modules[i].func_name,(void *)modules[i].func_wrapper);
	}
	return true;
}

ADT* eregi(ADT *pattern ,ADT * str ,ADT *regs);


ADT* eregi_wrapper(ListADT *param_list)
{
	if(param_list==NULL){
		return NULL;
	} 
	ADT * pattern = param_list->l;
	ListADT * next = dynamic_cast<ListADT*>(param_list->r);
	if(next==NULL){
		return NULL;
	}
	ADT * str = next->l;
	ADT * regs = NULL;
	next = dynamic_cast<ListADT*>(next->r);
	if(next!=NULL){
		regs = next->l;
	}	
	return eregi(pattern ,str ,regs);
}

ADT* eregi(ADT *pattern ,ADT * str ,ADT *regs)
{
	return new BoolADT(true);
}