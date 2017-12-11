#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <exception>
#include "conf.hpp"
using namespace std;

Conf* Conf::_instance;
std::map<std::string,std::string> Conf::param_map;

string Conf::get_param(const char * _key)
{
	string key(_key);
	map<string,string>::iterator kmap_iter;
	kmap_iter = param_map.find(key);
	if(kmap_iter==param_map.end()){
		cout<<"no param \""<<_key<<"\""<<endl;
		return string("");
	}
	return kmap_iter->second;
}

string Conf::get_param(string &key)
{	
	map<string,string>::iterator kmap_iter;
	kmap_iter = param_map.find(key);
	if(kmap_iter==param_map.end()){
		return string("");
	}
	return kmap_iter->second;
} 
string& Conf::trim2(string &str)
{
	
	while(str.size()>0){
		char c =str[0];
		if(c==' ' || c=='\t'){
			str.erase(0,1);
		}else{
			break;
		}
	}
	size_t pos = str.size();
	while(pos>0){
		char c =str[pos-1];
		if(c==' ' || c=='\t'){
			str.erase(pos-1,1);
			pos = str.size();
		}else{
			break;
		}
	}
	return str;
}
string& Conf::trim(string &str)
{
	trim2(str);
	size_t first = str.find('"');
	size_t last  = str.rfind('"');
	
	if(first!=string::npos && last!=string::npos && last>first){
		str.erase(0,first+1);
		str.erase(last-1);
		return trim2(str);
	}
	for(size_t pos = 0;pos<str.size();pos=pos+1)
	{
		char c = str[pos];
		if(c==' '||c=='\t'){
			str.erase(pos);
			return str;
		}	
	}
	return str;
}
bool Conf::LoadConf(const char * param_file_name)
{	
	ifstream in(param_file_name);
	string s;
	while(getline(in,s)){
		size_t pos = s.find('=');
		if(pos==string::npos){
			cerr<<"no valide"<<endl;
			continue;
		}
		string key = s.substr(0,pos);
		trim(key);
		string val = s.substr(pos+1);
		trim(val);
		//cout<<key<<"=>"<<val<<endl;
		param_map[key]=val;
		s = "";
		if(param_map.size()>=100)
			break;
	}
	in.close();	
	return true;
}
Conf::Conf()
{	
	this->param_map.clear();
}
Conf::~Conf()
{
}
bool Conf::RegisterMod(Mod * mod)
{
	string mod_conf =this->get_param("mod_conf");
	string mod_path =this->get_param("mod_path");
	if(mod_path.size()==0){
		return false;
	}
	if(mod_path[mod_path.size()-1]!='/'){
		mod_path +="/";
	}
	ifstream in(mod_conf.c_str());
	string s;
	while(getline(in,s)){
		size_t pos = s.find('=');
		if(pos==string::npos){
			cerr<<"no valide"<<endl;
			continue;
		}
		string key = s.substr(0,pos);
		trim(key);
		string val = s.substr(pos+1);
		trim(val);
		mod->LoadMod(key,mod_path+val);
	}
	in.close();	
	return true;
}

