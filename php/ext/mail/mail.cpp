#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "mail.hpp"


using namespace std;


extern "C" {
	bool register_module(SymbolTable * symtbl);
}


static module_t modules[] = {
	{"mail",mail_wrapper},	

};

bool register_module(SymbolTable * symtbl)
{
	for(size_t i=0;i<sizeof(modules)/sizeof(module_t);i++)
	{
		symtbl->Register(modules[i].func_name,(void *)modules[i].func_wrapper);
	}
	return true;
}

ADT* mail(ADT * _to,ADT * _subject,ADT * _message,ADT * _additional_headers,ADT * _additional_parameters);

ADT* mail_wrapper(ListADT *param_list)
{
	if(param_list==NULL){
		return NULL;
	}
	ADT * to = param_list->l;
	ListADT * next= dynamic_cast<ListADT*>(param_list->r);
	if(next==NULL){
		return NULL;
	}
	ADT * subject =next->l;
	next= dynamic_cast<ListADT*>(next->r);
	if(next==NULL){
		return NULL;
	}
	ADT * message =next->l;
	ADT * additional_headers =NULL;
	next= dynamic_cast<ListADT*>(next->r);
	if(next!=NULL){
		additional_headers =next->l;
	}	
	ADT *additional_parameters=NULL ;
	next= dynamic_cast<ListADT*>(next->r);
	if(next!=NULL){
		additional_parameters =next->l;
	}		
	return mail(to,subject,message,additional_headers,additional_parameters);
}
ADT* mail(ADT * _to,ADT * _subject,ADT * _message,ADT * _additional_headers,ADT * _additional_parameters)
{
	if(_to!=NULL){
		cout<<"to:";
		_to->Print();
		cout<<endl;
	}
	if(_subject!=NULL){
		cout<<"subject:";
		_subject->Print();
		cout<<endl;
	}
	if(_message!=NULL){
		cout<<"message:";
		_message->Print();
		cout<<endl;
	}
	if(_additional_headers!=NULL){
		cout<<"additional_headers:";
		_additional_headers->Print();
		cout<<endl;
	}
	if(_additional_parameters!=NULL){
		cout<<"additional_parameters:";
		_additional_parameters->Print();
		cout<<endl;
	}
	return new BoolADT(true);
}


