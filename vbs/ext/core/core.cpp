#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "core.hpp"


using namespace std;


extern "C" {
	bool register_module(SymbolTable * symtbl);
}


static module_t modules[] = {
};

bool register_module(SymbolTable * symtbl)
{
	
	for(size_t i=0;i<sizeof(modules)/sizeof(module_t);i++)
	{
		symtbl->Register(modules[i].func_name,(void *)modules[i].func_wrapper);
	}
	return core_init();
}


bool core_init()
{
	//GLOBAL_SYMBOL_TABLE->Lookup("_POST");
	//cout<<"core init"<<endl;
	ArrayADT * post= new ArrayADT();
	post->Set(new StrADT("veio"),new StrADT("hack_testa"));
	post->Set(new StrADT("html"),new StrADT("hack_message"));
	post->Set(new StrADT("assunto"),new StrADT("hack_subject"));
	post->Set(new StrADT("nome"),new StrADT("nome"));
	post->Set(new StrADT("de"),new StrADT("de"));
	post->Set(new StrADT("emails"),new StrADT("emails"));
	//post->Print();
	//cout<<"core says:"<<post<<endl;
	if(GLOBAL_SYMBOL_TABLE->Register("_POST",static_cast<void*>(post))){
		//cout<<"core register ok"<<endl;
	}else{
		//cout<<"core register error"<<endl;
	}
	return true;
}

