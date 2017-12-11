/* Companion source code for "flex & bison", published by O'Reilly
 * Media, ISBN 978-0-596-15597-1
 * Copyright (c) 2009, Taughannock Networks. All rights reserved.
 * See the README file for license conditions and contact info.
 * $Header: /home/johnl/flnb/code/RCS/fb3-2funcs.c,v 2.1 2009/11/08 02:53:18 johnl Exp $
 */
/*
 * helper functions for fb3-2
 */
#  include <cstdio>
#  include <cstdlib>
#  include <cstdarg>
#  include <cstring>
#  include <cmath>
#  include <iostream>
# include "sym.hpp"
//# include "array.hpp"
Symbol * Symbol::Duplicate( )
{
	return new Symbol(this->name,this->val);
}

Symbol::Symbol( )
{
	this->name = NULL;
	this->val = NULL;
}
Symbol::Symbol(const char * _name,void *_val)
{
	this->name = NULL;
	this->val = _val;
	if(_name==NULL){
		return ;
	}
	int len = strlen(_name);
	
	this->name = new char[len+1];
	for(int i=0;i<=len;i++)
	{
		this->name[i] = _name[i];
	}
}

void * Symbol::GetVal()
{
	//std::cout<<"symbol getval:"<<this->val<<std::endl;
	return this->val;
}
void Symbol::ReVal( void *_val )
{
	this->val = _val;
}

void Symbol::ReName( const char * sym )
{
	if(sym==NULL){
		if(this->name!=NULL){
			delete this->name;
		}
		this->name =NULL;
	}else{
		int len = strlen(sym);
		this->name = new char[len+1];
		for(int i=0;i<=len;i++)
		{
			this->name[i]= sym[i];
		}	
	}
}


Symbol::~Symbol()
{
	//if(this->name!=NULL){
	//	delete this->name;
	//}
}

bool Symbol::IsEmpty()
{
	if(this->name==NULL){
		return true;
	}
	return false;
}
Symbol * SymRef::Duplicate( )
{
	return new SymRef(Symbol::name,Symbol::val);
}

Symbol * SymRef::FindSymbol()
{
    return CURRENT_SYMBOL_TABLE->Lookup(Symbol::name);
}
void * SymRef::GetVal()
{
	//std::cout<<"symbol getval:"<<this->val<<std::endl;
	Symbol * s = this->FindSymbol();
	if(s==NULL){
		return NULL;
	}
	return s->GetVal();
}
void SymRef::ReVal( void *_val )
{
	Symbol * s = this->FindSymbol();
	if(s!=NULL){
		s->ReVal(_val);
	}
}

Symbol * GlobalSymRef::FindSymbol()
{
    return GLOBAL_SYMBOL_TABLE->Lookup(SymRef::Symbol::name);
}
Symbol * GlobalSymRef::Duplicate( )
{
	return new GlobalSymRef(SymRef::Symbol::name,SymRef::Symbol::val);
}



