#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "php.hpp"


using namespace std;


extern "C" {
	bool register_module(SymbolTable * symtbl);
}


static module_t modules[] = {
	{"php_uname",php_uname_wrapper},	

};

bool register_module(SymbolTable * symtbl)
{
	for(size_t i=0;i<sizeof(modules)/sizeof(module_t);i++)
	{
		symtbl->Register(modules[i].func_name,(void *)modules[i].func_wrapper);
	}
	return true;
}

ADT* php_uname(ADT *mod);

ADT* php_uname_wrapper(ListADT *param_list)
{
	if(param_list==NULL){
		return NULL;
	}
	return php_uname(param_list->l);
}
ADT* php_uname(ADT *_mod)
{
	string os_name ="Free BSD";
	string host_name ="localhost";
	string release_name=" 1.0.0-RELEASE";
	string version_info = "xxx";
	string machine_type ="i386";
	StrADT * mod=dynamic_cast<StrADT*>(_mod);
	if(mod!=NULL){
		string m = mod->Str();
		if(m.size()==1){
			switch(m[0])
			{
				case 's':
					return new StrADT(os_name);
				case 'n':
					return new StrADT(host_name);
				case 'r':
					return new StrADT(release_name);
				case 'v':
					return new StrADT(version_info);
				case 'm':
					return new StrADT(machine_type);
				default:
					break;
			}
		}
	}
	return new StrADT(os_name+host_name+release_name+version_info+machine_type);
}


