#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <exception>
#include "mod.hpp"
#include "dl/dlfcn.hpp"

using namespace std;

Mod* Mod::_instance;
std::map<std::string,std::string> Mod::mod_array;

Mod::Mod()
{	
}
Mod::~Mod()
{
}
bool Mod::LoadMod(const std::string &name,const std::string &path)
{	
	map<string,string>::iterator iter = mod_array.find(name);
	if(iter!=mod_array.end()){
		cout<<"mod already loaded"<<endl;
		return false;
	}
	mod_array[name]=path;
	return true;
}
bool Mod::Register( SymbolTable * symtbl)
{
	map<string,string>::iterator it;
	for ( it=mod_array.begin() ; it != mod_array.end(); it++ )
	{
		//cout << (*it).first << " => " << (*it).second << endl;
		string path = (*it).second;
		
		void *dp = dlopen(path.c_str(),RTLD_LAZY);	
		if(dp==NULL){
			return false;
		}
		MOD_REGISTER_WRAPPER wrapper = (MOD_REGISTER_WRAPPER)dlsym(dp,"register_module");
		if(wrapper==NULL){
			dlclose(dp);
			continue;
		}
		wrapper(symtbl);
	}
	return 0;
}
/*
	void *dp = dlopen(path.c_str(),RTLD_LAZY);	
	if(dp==NULL){
		return false;
	}
	MOD_FUNC_WRAPPER
	dump_cache = (PFN_CACHE)dlsym(dp,"register_module");
	//dump_end = (PFN_END)dlsym(dp,WORKER_END);
	//dump_start = (PFN_START)dlsym(dp,WORKER_START);
	//dump_err = (PFN_ERR)dlsym(dp,WORKER_ERR);
	*/	

