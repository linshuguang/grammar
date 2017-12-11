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


/***************************************CONST_AVAL*****************************************************/

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
	//return new StrADT(ss.str());
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
	StrADT * rv = dynamic_cast<StrADT *>(r.ToString());
	if(rv!=NULL){
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


ADT * CompoundVariableADT::Assign(ADT * val) 
{
	IdADT *_id = dynamic_cast<IdADT*>(this->id);
	if(_id==NULL){
		return NULL;
	}
	Symbol * s = CURRENT_SYMBOL_TABLE->Lookup(_id->name);
	if(s==NULL){
		cout<<"assign on not registered variable "<<_id->name<<endl;
		exit(-1);
	}
	ListADT * _id_tail_list = dynamic_cast<ListADT *>(this->id_tail_list);
	ADT * adt = static_cast<ADT*>(s->GetVal());
	ByRefADT * ref = dynamic_cast<ByRefADT*>(adt);
	if(ref==NULL){//如果是按值传递
		if(_id_tail_list==NULL){//如果是简单变量
			s->ReVal(val);
		}else{//左值必须是array
			ArrayADT * array = dynamic_cast<ArrayADT*>(adt);
			if(array!=NULL){
			}else{
				FunctionADT * function = dynamic_cast<FunctionADT*>(adt);
				if(array!=NULL){
				}
			}
			
		}
	}else{//如果是引用
	}
	return val;
}


