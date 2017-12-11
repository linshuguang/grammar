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
#include<sstream>
#include "adt.hpp"
#include "array.hpp"

using namespace std;


/*
 * ADT
 */


/***************************************BASIC_AVAL*****************************************************/

/*
 * DoubleADT
 */
unsigned char DoubleADT::Type() 
{
	return ADT_IS_DOUBLE;
}
ADT* DoubleADT::operator+(  ADT  &r)  
{	
	DoubleADT * rv =  dynamic_cast<DoubleADT *>( r.ToDouble());
	return new DoubleADT((double)*this + (double)*rv);
}
ADT* DoubleADT::operator-(  ADT  &r)  
{
	DoubleADT * rv =  dynamic_cast<DoubleADT *>( r.ToDouble());
	return new DoubleADT((double)*this - (double)*rv);	
}
ADT* DoubleADT::operator*(  ADT  &r)  
{
	DoubleADT * rv =  dynamic_cast<DoubleADT *>( r.ToDouble());
	return new DoubleADT((double)*this * (double)*rv);	
}
ADT* DoubleADT::operator/(  ADT  &r)  
{
	DoubleADT * rv =  dynamic_cast<DoubleADT *>( r.ToDouble());
	return new DoubleADT((double)*this / (double)*rv);	
}
ADT* DoubleADT::operator%(  ADT  &r)  
{
	LongADT * rv =  dynamic_cast<LongADT *>( r.ToLong());
	return new LongADT(((long)((double)*this)) % ((long)*rv));	
}

ADT* DoubleADT::Concat( ADT &r)
{
	unsigned char type = r.Type();
	if(type==ADT_IS_LONG){
		DoubleADT *rv = dynamic_cast<DoubleADT *>( &r);
		stringstream ss;
		ss<<(double)*this<<(double)*rv;
		return new StrADT(ss.str());
	}else if(type==ADT_IS_STRING){
		StrADT *rv = dynamic_cast<StrADT *>( &r);
		stringstream ss;
		ss<<(double)*this;
		return new StrADT(ss.str() + rv->Str());
	}
	return NULL;
}
ADT* DoubleADT::Print( )
{
	
	cout<<(double)*this;
	return NULL;
}

ADT* DoubleADT::ToString() 
{
	stringstream ss;
	ss<<this->dval;
	return new StrADT(ss.str());
}
ADT* DoubleADT::ToBool()
{
	if(this->dval==0.0){
		return new BoolADT(false);
	}else{
		return new BoolADT(true);
	}
}
ADT* DoubleADT::ToLong()
{
	return new LongADT((long)this->dval);
}
ADT* DoubleADT::ToDouble()
{
	return this;
}

ADT* DoubleADT::Not()
{
	if(this->dval!=0.0){
		return new BoolADT(false);
	}else{
		return new BoolADT(true);
	}
}


ADT* DoubleADT::operator==( ADT &r) 
{
	DoubleADT * rv =  dynamic_cast<DoubleADT *>(r.ToDouble());
	return new BoolADT((double)*this == (double)*rv);;
}
ADT* DoubleADT::operator!=( ADT &r) 
{
	DoubleADT * rv =  dynamic_cast<DoubleADT *>(r.ToDouble());
	return new BoolADT((double)*this != (double)*rv);;
}
ADT* DoubleADT::operator<( ADT &r) 
{
	DoubleADT * rv =  dynamic_cast<DoubleADT *>(r.ToDouble());
	return new BoolADT((double)*this < (double)*rv);;
}
ADT* DoubleADT::operator<=( ADT &r) 
{
	DoubleADT * rv =  dynamic_cast<DoubleADT *>(r.ToDouble());
	return new BoolADT((double)*this <= (double)*rv);;
}
ADT* DoubleADT::operator>( ADT &r) 
{
	DoubleADT * rv =  dynamic_cast<DoubleADT *>(r.ToDouble());
	return new BoolADT((double)*this > (double)*rv);;
}
ADT* DoubleADT::operator>=(ADT &r) 
{
	DoubleADT * rv =  dynamic_cast<DoubleADT *>(r.ToDouble());
	return new BoolADT((double)*this >= (double)*rv);;
}
ADT* DoubleADT::Empty()
{
	if(this->dval==0.0){
		return new BoolADT(true);
	}
	return  new BoolADT(false);
}
/*
 * LongADT
 */
unsigned char LongADT::Type() 
{
	return ADT_IS_LONG;
}
ADT* LongADT::operator+(  ADT  &r)  
{
	LongADT * rv =  dynamic_cast<LongADT *>( r.ToLong());
	return new LongADT((long)*this + (long)*rv);	
}
ADT* LongADT::operator-(  ADT  &r)  
{
	LongADT * rv =  dynamic_cast<LongADT *>( r.ToLong());
	return new LongADT((long)*this - (long)*rv);	
}
ADT* LongADT::operator*(  ADT  &r)  
{
	LongADT * rv =  dynamic_cast<LongADT *>( r.ToLong());
	return new LongADT((long)*this * (long)*rv);	
}
ADT* LongADT::operator/(  ADT  &r)  
{
	LongADT * rv =  dynamic_cast<LongADT *>( r.ToLong());
	return new LongADT((long)*this / (long)*rv);	
}
ADT* LongADT::operator%(  ADT  &r)  
{
	LongADT * rv =  dynamic_cast<LongADT *>( r.ToLong());
	return new LongADT((long)*this % (long)*rv);	
}
ADT* LongADT::Concat( ADT & r)
{
	unsigned char type = r.Type();
	if(type==ADT_IS_LONG){
		LongADT *rv = dynamic_cast<LongADT *>( &r);
		stringstream ss;
		ss<<(long)*this<<(long)*rv;
		return new StrADT(ss.str());
	}else if(type==ADT_IS_STRING){
		StrADT *rv = dynamic_cast<StrADT *>( &r);
		stringstream ss;
		ss<<(long)*this;
		return new StrADT(ss.str() + rv->Str());
	}
	return NULL;
}

ADT* LongADT::Print( )
{
	cout<<(long)*this;
	return NULL;
}

ADT* LongADT::ToString() 
{
	stringstream ss;
	ss<<this->lval;
	return new StrADT(ss.str());
}

ADT* LongADT::ToBool()
{
	if(this->lval==0){
		return new BoolADT(false);
	}else{
		return new BoolADT(true);
	}
}
ADT* LongADT::ToLong()
{
	return this;
	
}
ADT* LongADT::ToDouble()
{
	return new DoubleADT((double)this->lval);
}

ADT* LongADT::Not()
{
	if(this->lval!=0){
		return new BoolADT(false);
	}else{
		return new BoolADT(true);
	}
}


ADT* LongADT::operator==( ADT &r) 
{
	LongADT * rv =  dynamic_cast<LongADT *>(r.ToLong());
	return new BoolADT((long)*this == (long)*rv);;
}
ADT* LongADT::operator!=( ADT &r) 
{
	LongADT * rv =  dynamic_cast<LongADT *>(r.ToLong());
	return new BoolADT((long)*this != (long)*rv);;
}
ADT* LongADT::operator<( ADT &r) 
{
	LongADT * rv =  dynamic_cast<LongADT *>(r.ToLong());
	//	cout<<"long "<<(long)*this<<"<"<<(long)*rv<<endl;
	
	return new BoolADT((long)*this < (long)*rv);;
}
ADT* LongADT::operator<=( ADT &r) 
{
	LongADT * rv =  dynamic_cast<LongADT *>(r.ToLong());
	return new BoolADT((long)*this <= (long)*rv);;
}
ADT* LongADT::operator>( ADT &r) 
{
	
	LongADT * rv =  dynamic_cast<LongADT *>(r.ToLong());
	//cout<<"long "<<(long)*this<<">"<<(long)*rv<<endl;
	return new BoolADT((long)*this > (long)*rv);;
}
ADT* LongADT::operator>=(ADT &r) 
{
	LongADT * rv =  dynamic_cast<LongADT *>(r.ToLong());
	return new BoolADT((long)*this >= (long)*rv);;
}

ADT* LongADT::Empty()
{
	if(this->lval==0){
		return new BoolADT(true);
	}
	return  new BoolADT(false);
}
/*
 * BoolADT
 */

unsigned char BoolADT::Type() 
{
	return ADT_IS_BOOL;
}
ADT* BoolADT::operator+(  ADT  &r)  
{
	
	BoolADT * rv =  dynamic_cast<BoolADT *>(r.ToBool());
	return new BoolADT((bool)*rv + (bool)*this);

}


ADT* BoolADT::Concat( ADT &r)
{
	unsigned char type = r.Type();
	if(type==ADT_IS_BOOL){
		BoolADT *rv = dynamic_cast<BoolADT *>( &r);
		stringstream ss;
		ss<<(bool)*this<<(bool)*rv;
		return new StrADT(ss.str());
	}else if(type==ADT_IS_STRING){
		StrADT *rv = dynamic_cast<StrADT *>( &r);
		stringstream ss;
		ss<<(bool)*this;
		return new StrADT(ss.str() + rv->Str());
	}
	return NULL;
}

ADT* BoolADT::Print( )
{
	cout<<(bool)*this;
	return NULL;
}

ADT* BoolADT::ToString() 
{
	stringstream ss;
	ss<<this->bval;
	return new StrADT(ss.str());
}
ADT* BoolADT::ToBool()
{
	return new BoolADT(this->bval);
}
ADT* BoolADT::ToLong()
{
	return new LongADT((long)this->bval);
	
}
ADT* BoolADT::ToDouble()
{
	return new DoubleADT((double)this->bval);
}

ADT* BoolADT::Not()
{
	return new BoolADT(!this->bval);
}

ADT* BoolADT::Empty()
{
	return new BoolADT(this->bval);
}
/*
 * StrADT
 */
unsigned char StrADT::Type() 
{
	return ADT_IS_STRING;
}

ADT* StrADT::operator+(  ADT  &r)  
{
	if(r.Type()==ADT_IS_STRING){
		StrADT * rv =  dynamic_cast<StrADT *>( &r);
		std::string s = this->Str() + rv->Str();
		return new StrADT(s.c_str());
	}
	return NULL;
}
ADT* StrADT::Concat( ADT &r)
{
	unsigned char type = r.Type();
	if(type==ADT_IS_STRING){
		StrADT *rv = dynamic_cast<StrADT *>( &r);
		return new StrADT(this->Str() + rv->Str());
	}else if(type==ADT_IS_LONG){
		LongADT *rv = dynamic_cast<LongADT *>( &r);
		stringstream ss;
		ss<<(long)*rv;
		return new StrADT(this->Str() + ss.str());
	}else if(type==ADT_IS_BOOL){
		BoolADT *rv = dynamic_cast<BoolADT *>( &r);
		stringstream ss;
		ss<<(bool)*rv;
		return new StrADT(this->Str() + ss.str());
	}else if(type==ADT_IS_DOUBLE){
		DoubleADT *rv = dynamic_cast<DoubleADT *>( &r);
		stringstream ss;
		ss<<(double)*rv;
		return new StrADT(this->Str() + ss.str());
	}
	return NULL;
}
ADT* StrADT::Print( )
{
	
	//cout<<'"'<<this->Str()<<'"';
	cout<<this->s;
	return NULL;
}

ADT* StrADT::ToString() 
{
	string str(this->s);
	return new StrADT(str);
}

ADT* StrADT::ToBool()
{
	
	return new BoolADT(true);
}
ADT* StrADT::ToLong() 
{
	return new LongADT(atol(this->s));
}
ADT* StrADT::ToDouble() 
{
	return new DoubleADT(atof(this->s));
}

ADT* StrADT::Not()
{
	return new BoolADT(false);
}

ADT* StrADT::operator==( ADT &r) 
{
	StrADT * rv =  dynamic_cast<StrADT *>( r.ToString());
	if(!strcmp(this->s,rv->s)){
		return new BoolADT(true);
	}else{
		return new BoolADT(false);
	}
}
ADT* StrADT::operator!=( ADT &r) 
{
	StrADT * rv =  dynamic_cast<StrADT *>( r.ToString());
	if(!strcmp(this->s,rv->s)){
		return new BoolADT(false);
	}else{
		return new BoolADT(true);
	}

}
ADT* StrADT::Empty()
{
	if(this->s==NULL ||strlen(this->s)==0){
		return new BoolADT(true);
	}
	return  new BoolADT(false);
}

/****************************************VariableADT****************************************************/


/*
 * FetchArrayDimADT
 */
 
 /*
ADT * FetchArrayDimVariableADT::operator+( ADT & va)
{
	
	if(this->array==NULL || this->dim==NULL){
		return NULL;
	}
	ArrayADT * a = dynamic_cast<ArrayADT*>(this->array);
	ADT * tt = a->Get(this->dim);
	if(tt==NULL){
		//this->array->Set(this->dim->ToString(),va);
	}else{
		*tt + va;
	}
	return NULL;
}
ADT* FetchArrayDimVariableADT::Concat( ADT &va)
{
	if(this->array==NULL || this->dim==NULL){
		return NULL;
	}
	ArrayADT * a = dynamic_cast<ArrayADT*>(this->array);
	ADT * tt = a->Get(this->dim);
	if(tt==NULL){
		//this->array->Set(this->dim->ToString(),va);
	}else{
		tt->Concat(va);
	}
	return NULL;
}
ADT* FetchArrayDimVariableADT::Print( )
{
	if(this->array==NULL || this->dim==NULL){
		return NULL;
	}
	ArrayADT * a = dynamic_cast<ArrayADT*>(this->array);

	ADT * tt = a->Get(this->dim);

	
	if(tt==NULL){
		//this->array->Set(this->dim->ToString(),va);
	}else{
		tt->Print();
	}
	return NULL;
}
ADT* FetchArrayDimVariableADT::ToString()
{
	if(this->array==NULL || this->dim==NULL){
		return NULL;
	}
	ArrayADT * a = dynamic_cast<ArrayADT*>(this->array);
	ADT * tt = a->Get(this->dim);
	if(tt==NULL){
		//this->array->Set(this->dim->ToString(),va);
	}else{
		return tt->ToString();
	}
	return NULL;
}

ADT* FetchArrayDimVariableADT::Get()
{
	ADT * tt = NULL;
	if(this->array!=NULL && this->dim!=NULL){
		ArrayADT * a = dynamic_cast<ArrayADT*>(this->array);
		tt = a->Get(this->dim);
	}
	return tt;
}
void FetchArrayDimVariableADT::Assign( ADT *t) 
{
	if(this->array!=NULL){
		ArrayADT * a = dynamic_cast<ArrayADT*>(this->array);
		a->Set(this->dim,t);
	}
	
}
void FetchArrayDimVariableADT::UnSet()
{
	if(this->array!=NULL && this->dim!=NULL){
		ArrayADT * a = dynamic_cast<ArrayADT*>(this->array);
		a->UnSet(this->dim);
	}
}
ADT * FetchArrayDimVariableADT::ToBool()
{
	if(this->array!=NULL && this->dim!=NULL){
		ArrayADT * a = dynamic_cast<ArrayADT*>(this->array);
		return new BoolADT(a->Exist(this->dim));
	}
	return false;
}
*/

