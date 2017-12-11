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
//SymbolTable GlobalSymbolTable;
//SymbolTable *symtab = &GlobalSymbolTable;
//SymTabStack symtab_stack;
SymbolTable SymTabStack::_mod_function;
SymbolTable SymTabStack::_user_function;

SymbolTable  SymTabStack::_global;
SymTabStack* SymTabStack::_instance = NULL;
vector<SymbolTable*> SymTabStack::_stack;


SymTabStack::SymTabStack()
{
		_stack.clear();
}
SymTabStack::~SymTabStack()
{
	
}
void SymTabStack::Push(SymbolTable* st)
{
	_stack.push_back(st);
}

SymbolTable* SymTabStack::Pop()
{
	SymbolTable* st = _stack.back();
	_stack.pop_back();
	return st;
}
SymbolTable* SymTabStack::Top()
{
	SymbolTable* st = _stack.back();
	return st;
}
SymbolTable* SymTabStack::Global()
{
	return &_global;
}

SymbolTable* SymTabStack::UserFunction()
{
	return &_user_function;
}
SymbolTable* SymTabStack::ModFunction()
{
	return &_mod_function;
}


