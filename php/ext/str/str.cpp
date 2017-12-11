#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "str.hpp"


using namespace std;


extern "C" {
	bool register_module(SymbolTable * symtbl);
}


static module_t modules[] = {

	{"strtolower",strtolower_wrapper},
	{"strpos",strpos_wrapper},
	{"substr",substr_wrapper},
	{"stripslashes",stripslashes_wrapper},
	{"explode",explode_wrapper},
};

bool register_module(SymbolTable * symtbl)
{
	for(size_t i=0;i<sizeof(modules)/sizeof(module_t);i++)
	{
		symtbl->Register(modules[i].func_name,(void *)modules[i].func_wrapper);
	}
	return true;
}

std::string strtolower( char const* bytes_to_encode, unsigned int in_len);
ADT* substr( ADT* str,ADT * start, ADT* length);
ADT* strpos( ADT *haystack , ADT * needle ,ADT *offset);
ADT* stripslashes( ADT* str);
ADT* explode( ADT * delimiter ,ADT *str,ADT * limit );




//substr
ADT* substr_wrapper(ListADT *param_list)
{
	if(param_list==NULL){
		return NULL;
	} 
	ADT * str = param_list->l;
	ListADT * next = dynamic_cast<ListADT*>(param_list->r);
	if(next==NULL){
		return NULL;
	}
	ADT * start = next->l;
	ADT * length = NULL;
	next = dynamic_cast<ListADT*>(next->r);
	if(next!=NULL){
		length = next->l;
	}	
	return substr(str,start,length);
}
ADT* substr( ADT* _str,ADT * _start, ADT* _length)
{
	StrADT * str = dynamic_cast<StrADT*>(_str);
	if(str==NULL){
		return NULL;
	}
	LongADT * start = dynamic_cast<LongADT*>(_start);
	if(start==NULL){
		return NULL;
	}
	LongADT * length = dynamic_cast<LongADT*>(_length);
	string s = str->Str();
	long t = (long)(*start);
	if(length==NULL){		
		return new StrADT(s.substr(t));
	}else{
		long l= (long)(*length);
		return new StrADT(s.substr(t,l));
	}
}

//strpos
ADT* strpos_wrapper(ListADT *param_list)
{
	if(param_list==NULL){
		return NULL;
	} 
	ADT * haystack = param_list->l;
	ListADT * next = dynamic_cast<ListADT*>(param_list->r);
	if(next==NULL){
		return NULL;
	}
	ADT * needle = next->l;
	ADT * offset = NULL;
	next = dynamic_cast<ListADT*>(next->r);
	if(next!=NULL){
		offset = next->l;
	}
	return strpos( haystack ,needle ,offset);	
}
ADT* strpos( ADT *_haystack , ADT * _needle ,ADT *_offset)
{
	StrADT * haystack = dynamic_cast<StrADT*>(_haystack);
	if(haystack==NULL){
		return NULL;
	}
	StrADT * needle = dynamic_cast<StrADT*>(_needle);
	if(needle==NULL){
		return NULL;
	}
	LongADT * offset = dynamic_cast<LongADT*>(_offset);
	string s = haystack->Str();
	string t = needle->Str();
	if(offset==NULL){		
		return new LongADT(s.find(t));
	}else{
		long off= (long)(*offset);
		return new LongADT(s.find(t,off));
	}
}

//strtolower
static char tolower(char c) 
{    
	if(c>='A' && c<='Z'){
		return 'a'+(c-'A');
	}else{
		return c;
	}
	
}    
ADT* strtolower_wrapper(ListADT *param_list)
{
	if(param_list==NULL || param_list->l==NULL){
		return NULL;
	}
	StrADT * str = dynamic_cast<StrADT*>(param_list->l);
	if(str==NULL){
		return NULL;
	}
	string s = str->Str();
	string t = strtolower((char const*)s.c_str(),s.size());
	return new StrADT(t);
}

std::string strtolower(char const* bytes_to_encode, unsigned int in_len) 
{    
	std::string t;
	for(unsigned int i=0;i<in_len;i++)
	{
		char c = tolower(bytes_to_encode[i]);
		t+=c;
	}
	return t;    
} 

//stripslashes
ADT* stripslashes_wrapper(ListADT *param_list)
{
	if(param_list==NULL){
		return NULL;
	}
	ADT * str = param_list->l;
	return stripslashes( str);   
}
ADT* stripslashes( ADT* _str)
{
	StrADT * str = dynamic_cast<StrADT*>(_str);
	if(str==NULL){
		return NULL;
	}
	string s =str->Str();
	string t;
	for(size_t i=0;i<s.size();i++)
	{
		if(s[i]!='\\'){
			t+=s[i];
		}
	}
	return new StrADT(t);
}
//explode
ADT* explode_wrapper(ListADT *param_list)
{
	if(param_list==NULL ){
		return NULL;
	}
	ADT *delimiter = param_list->l;
	ListADT * next = dynamic_cast<ListADT*>(param_list->r);
	if(next==NULL){
		return NULL;
	}
	ADT * str = next->l;
	ADT * limit = NULL;
	next = dynamic_cast<ListADT*>(next->r);
	if(next!=NULL){
		limit = next->l;
	}
	return explode(delimiter,str,limit);
}

ADT* explode( ADT * _delimiter ,ADT *_str,ADT * _limit )
{
	ArrayADT * result = new ArrayADT(); 
	StrADT * delimiter =dynamic_casat<StrADT*>(_delimiter);
	if(delimiter==NULL){
		return result;
	}
	string sub_s = delimiter->Str();
	StrADT * str =dynamic_casat<StrADT*>(_str);
	if(str==NULL){
		return result;
	}
	
	string s = str->Str();
	for(;;)
	{
		s.find(sub.s);
	}
	return NULL;
}
