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

/*
1 = vbOK - OK was clicked
2 = vbCancel - Cancel was clicked 
3 = vbAbort - Abort was clicked
4 = vbRetry - Retry was clicked
5 = vbIgnore - Ignore was clicked
6 = vbYes - Yes was clicked
7 = vbNo - No was clicked
*/

static module_t modules[] = {		
	{"MsgBox",MsgBox_wrapper},
};

bool register_module(SymbolTable * symtbl)
{
	for(size_t i=0;i<sizeof(modules)/sizeof(module_t);i++)
	{
		symtbl->Register(modules[i].func_name,(void *)modules[i].func_wrapper);
	}
	symtbl->Register("vbOK",new IntegerADT(1));
	symtbl->Register("vbCancel",new IntegerADT(2));
	symtbl->Register("vbAbort",new IntegerADT(3));
	symtbl->Register("vbRetry",new IntegerADT(4));
	symtbl->Register("vbIgnore",new IntegerADT(5));
	symtbl->Register("vbYes",new IntegerADT(6));
	symtbl->Register("vbNo",new IntegerADT(7));
	return true;
}

ADT* MsgBox(ADT * prompt,ADT * buttons,ADT * title,ADT * helpfile,ADT * context);

ADT* MsgBox_wrapper(ListADT *param_list)
{
	if(param_list==NULL){
		return NULL;
	} 
	ADT * prompt = param_list->l;;	
	ADT * buttons = NULL;
	ListADT * next = dynamic_cast<ListADT*>(param_list->r);
	if(next!=NULL){
		buttons = next->l;
	}
	ADT * title=NULL;
	next = dynamic_cast<ListADT*>(next->r);
	if(next!=NULL){
		title = next->l;
	}
	next = dynamic_cast<ListADT*>(next->r);
	ADT * helpfile=NULL;
	if(next!=NULL){
		helpfile = next->l;
	}
	next = dynamic_cast<ListADT*>(next->r);
	ADT * context=NULL;
	if(next!=NULL){
		context = next->l;
	}
	return MsgBox(prompt,buttons,title,helpfile,context);
}
ADT* MsgBox(ADT * prompt,ADT * buttons,ADT * title,ADT * helpfile,ADT * context)
{
	return NULL;
}

