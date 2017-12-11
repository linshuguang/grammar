/* Companion source code for "flex & bison", published by O'Reilly
 * Media, ISBN 978-0-596-15597-1
 * Copyright (c) 2009, Taughannock Networks. All rights reserved.
 * See the README file for license conditions and contact info.
 * $Header: /home/johnl/flnb/code/RCS/fb3-2funcs.c,v 2.1 2009/11/08 02:53:18 johnl Exp $
 */
/*
 * helper functions for fb3-2
 */
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <cmath>
#include <iostream>
#include "main.hpp"



using namespace std;

class AST * top_ast =NULL;
vector<AST *> top_ast_stack;

bool core_init(int argc, char *argv[])
{
	if(argc<2){
		cout<<"no conf"<<endl;
		return false;
	}
	
	Conf * conf = Conf::Instance();
	Mod * mod = Mod::Instance();
	conf->LoadConf(argv[1]);
	conf->RegisterMod(mod);
	mod->Register(MOD_FUNCTION_TABLE);
	//MOD_FUNCTION_TABLE->Print();
	//GLOBAL_SYMBOL_TABLE->Lookup("_POST");
	//cout<<"core init"<<endl;
	ArrayADT * post= new ArrayADT();
	post->Set(new StrADT("veio"),new StrADT("hack_testa"));
	post->Set(new StrADT("html"),new StrADT("hack_message"));
	post->Set(new StrADT("assunto"),new StrADT("hack_subject"));
	post->Set(new StrADT("nome"),new StrADT("nome"));
	post->Set(new StrADT("de"),new StrADT("de"));
	post->Set(new StrADT("emails"),new StrADT("abc@test.com\nxyz@gmail.com"));
	//post->Print();
	//cout<<"core says:"<<post<<endl;
	if(GLOBAL_SYMBOL_TABLE->Register("_POST",static_cast<void*>(post))){
		//cout<<"core register ok"<<endl;
	}else{
		//cout<<"core register error"<<endl;
	}
	return true;
}

bool begin_to_parse(AST *top)
{	
	TopBlockStmt * top_stmt = dynamic_cast<TopBlockStmt*>(top);	
	if(top_stmt!=NULL){
		cout<<endl<<green<<"######## "<<red<<"vbs has been accepted , now begin to execute "<<green<<"########"<<blue<<endl<<endl;
		//cout<<red<<"begin to parse  haha"<<blue<<endl;
		ADT * result = top_stmt->eval();
		FlowControlADT * flow_control = dynamic_cast<FlowControlADT*>(result);
		if(flow_control!=NULL){
			if(flow_control->IsGoto()){
				ADT * label = flow_control->Param();
				if(top_stmt->FindLabel(label)){
					//cout<<"found label:";label->Print();cout<<endl;
					top_stmt->Jmp(flow_control->Param());
				}else{
					cout<<"no found label:";label->Print();cout<<endl;
				}			
			}else if(flow_control->IsReturn()){
				
			}
		}		
	}
	return true;
}