#pragma once
#include"mod.hpp"

class Conf{
	static Conf* _instance;
 	static std::map<std::string,std::string> param_map;
	std::string&  trim(std::string &str);
	std::string&  trim2(std::string &str);		
public:
	static Conf * Instance()
    {
		if( 0== _instance){			
			_instance = new Conf;
		}
		return _instance;
    }
	std::string get_param(const char * _key);
	std::string get_param(std::string &key);
	Conf();
	bool LoadConf(const char * param_file_name);
	bool RegisterMod(Mod*);
	~Conf();
};


