#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "base64.hpp"


using namespace std;


extern "C" {
	bool register_module(SymbolTable * symtbl);
}


static module_t modules[] = {
	{"base64_encode",base64_encode_wrapper},
	{"base64_decode",base64_decode_wrapper},
	
};

bool register_module(SymbolTable * symtbl)
{
	for(size_t i=0;i<sizeof(modules)/sizeof(module_t);i++)
	{
		symtbl->Register(modules[i].func_name,(void *)modules[i].func_wrapper);
	}
	return true;
}

static std::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len);
static std::string base64_decode(std::string const& encoded_string) ;


ADT* base64_encode_wrapper(ListADT *param_list)
{
	if(param_list==NULL || param_list->l==NULL){
		return false;
	}
	StrADT * str = dynamic_cast<StrADT*>(param_list->l);
	if(str==NULL){
		return false;
	}
	string s = str->Str();
	string t = base64_encode((unsigned char const*)s.c_str(),s.size());
	return new StrADT(t);
}

ADT* base64_decode_wrapper(ListADT *param_list)
{
	if(param_list==NULL || param_list->l==NULL){
		return false;
	}
	StrADT * str = dynamic_cast<StrADT*>(param_list->l);
	if(str==NULL){
		return false;
	}
	string s = str->Str();
	string t = base64_decode(s);
	return new StrADT(t);
}
static const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";      
static inline bool is_base64(unsigned char c) 
{    
	return (isalnum(c) || (c == '+') || (c == '/'));  
}    

std::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len) 
{    
	std::string ret;    
	int i = 0;    
	int j = 0;    
	unsigned char char_array_3[3];    
	unsigned char char_array_4[4];      
	while (in_len--) {      
		char_array_3[i++] = *(bytes_to_encode++);      
		if (i == 3) {        
			char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;        
			char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);        
			char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);        
			char_array_4[3] = char_array_3[2] & 0x3f;          
			for(i = 0; (i <4) ; i++)
				ret += base64_chars[char_array_4[i]];        
			i = 0;      
		}    
	}      
	if (i)    {      
		for(j = i; j < 3; j++)        
			char_array_3[j] = '\0';        
		char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;      
		char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);      
		char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);      
		char_array_4[3] = char_array_3[2] & 0x3f;        
		
		for (j = 0; (j < i + 1); j++)        
			ret += base64_chars[char_array_4[j]];       
		while((i++ < 3))        
			ret += '=';      
	}      
	return ret;    
}    

std::string base64_decode(std::string const& encoded_string) 
{    
	int in_len = encoded_string.size();    
	int i = 0;    int j = 0;    int in_ = 0;    
	unsigned char char_array_4[4], char_array_3[3];    
	std::string ret;      
	while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {      
		char_array_4[i++] = encoded_string[in_]; 
		in_++;      
		if (i ==4) {        
			for (i = 0; i <4; i++)          
				char_array_4[i] = base64_chars.find(char_array_4[i]);          
			char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);        
			char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);        
			char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];          
			for (i = 0; (i < 3); i++)          
				ret += char_array_3[i];        
			i = 0;      
		}    
	}      
	if (i) {      
		for (j = i; j <4; j++)        
			char_array_4[j] = 0;        
		for (j = 0; j <4; j++)        
			char_array_4[j] = base64_chars.find(char_array_4[j]);        
		char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);      
		char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);      
		char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];        
		for (j = 0; (j < i - 1); j++) 
			ret += char_array_3[j];    
	}      
	return ret;  
}  
