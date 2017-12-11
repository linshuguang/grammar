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
#include "sym.hpp"
#include "main.hpp"

bool SymbolTable::Init()
{
	this->symtab = new Symbol *[this->TabSize];
	
	for(int i=0; i < this->TabSize; i++ )
	{
		this->symtab[i] = NULL;
	}
	
	return true;
}
SymbolTable::SymbolTable(int _TabSize)
{
	this->TabSize = _TabSize;
	this->Init();
}

SymbolTable::SymbolTable()
{
	#define NHASH 20
	this->TabSize = NHASH;
	this->Init();
}

unsigned
SymbolTable::SymHash(const char *sym)
{
	unsigned int hash = 0;
	unsigned c;
	while((c = *sym++)) hash = hash*9 ^ c;
	return hash;
}
bool SymbolTable::Register(const char* sym,void * _val)
{	
	Symbol *sp = this->Lookup(sym);
	if(sp!=NULL){
		//cout<<"symbol "<<sym<<" already exist"<<endl;
		return true;
	}
	Symbol **spp = this->LookupEmptyInternal(sym);
	if(spp==NULL){
		cout<<"symbol table already full"<<endl;
		return false;
	}
	if(*spp!=NULL){
		delete *spp;
	}
	*spp = new Symbol(sym,_val);
	return true;
}
bool SymbolTable::Register(const char* sym)
{	
	/*
	Symbol *sp = this->Lookup(sym);
	if(sp!=NULL){
		//cout<<"symbol "<<sym<<" already exist"<<endl;
		return true;
	}
	Symbol **spp = this->LookupEmptyInternal(sym);
	if(spp==NULL){
		cout<<"symbol table already full"<<endl;
		return false;
	}
	if(*spp!=NULL){
		delete *spp;
	}
	*spp = new Symbol(sym,NULL);
	return true;
	*/
	return this->Register(sym,NULL);
}
bool SymbolTable::RegisterRef(const char* sym)
{	
	Symbol *sp = this->Lookup(sym);
	if(sp!=NULL){
		//cout<<"symbol "<<sym<<" already exist"<<endl;
		return true;
	}
	Symbol **spp = this->LookupEmptyInternal(sym);
	if(spp==NULL){
		cout<<"symbol table already full"<<endl;
		return false;
	}
	if(*spp!=NULL){
		delete *spp;
	}
	*spp = new SymRef(sym);
	return true;
}
bool SymbolTable::RegisterGlobalRef(const char* sym)
{	
	Symbol *sp = this->Lookup(sym);
	if(sp!=NULL){
		//cout<<"symbol "<<sym<<" already exist"<<endl;
		return true;
	}
	Symbol **spp = this->LookupEmptyInternal(sym);
	if(spp==NULL){
		cout<<"symbol table already full"<<endl;
		return false;
	}
	if(*spp!=NULL){
		delete *spp;
	}
	*spp = new GlobalSymRef(sym);
	return true;
}

bool SymbolTable::UnRegister(const char* sym)
{	
	Symbol **spp = this->LookupInternal(sym);
	if(spp==NULL||*spp==NULL){
		//cout<<"symbol "<<sym<<" not exist"<<endl;
		return true;
	}
	Symbol * sp = *spp;
	*spp = NULL;
	delete sp;	
	return true;
}
Symbol **
SymbolTable::LookupEmptyInternal(const char* sym)
{	
	Symbol **spp = &this->symtab[this->SymHash(sym)%this->TabSize];
	int scount = this->TabSize;		
	while(--scount >= 0) {
		Symbol * sp = *spp;
		if(sp==NULL){
			return spp;
		}else if(sp->IsEmpty()) {						
			return spp;
		}
		if(++spp >= this->symtab+this->TabSize) {
			spp = this->symtab; 
		}
	}	
	return NULL;	
}
Symbol *
SymbolTable::Lookup(const char* sym)
{	
	
	Symbol **spp = this->LookupInternal(sym);
	if(spp==NULL || *spp==NULL){
		return NULL;
	}
	return *spp;
}

Symbol **
SymbolTable::LookupInternal(const char* sym)
{	
	Symbol **spp = &this->symtab[this->SymHash(sym)%this->TabSize];
	int scount = this->TabSize;		

	while(--scount >= 0) {
		Symbol * sp = *spp;
		if(sp==NULL ||sp->IsEmpty()) {			
			continue;
		}
		if(!strcmp(sp->c_name(),sym)) { 
			return spp; 
		}	
		if(++spp >= this->symtab+this->TabSize) {
			spp = this->symtab; 
		}
	}
	return NULL;
}
SymbolTable::~SymbolTable()
{
	delete []this->symtab;
}
void SymbolTable::Print()
{
	
	for(int i=0;i<this->TabSize;i++)
	{
		Symbol * sp = this->symtab[i];
		if(sp==NULL||sp->c_name()==NULL) { 
			continue;
		}	
		std::cout<<"symbol:"<<sp->c_name()<<",val:"<<sp->GetVal()<<std::endl;
	}
	
}

SymbolTable * SymbolTable::Dump()
{	
	SymbolTable * st = new SymbolTable(this->TabSize);
	if(st==NULL){		
		return NULL;
	}
	for(int i =0;i<this->TabSize;i++)
	{
		Symbol *sp = this->symtab[i] ; 		
		if(sp==NULL||sp->name==NULL){
			continue;
		}
		st->symtab[i] = sp->Duplicate();
	}

	return st;
}


