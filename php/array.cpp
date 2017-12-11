/* Companion source code for "flex & bison", published by O'Reilly
 * Media, ISBN 978-0-596-15597-1
 * Copyright (c) 2009, Taughannock Networks. All rights reserved.
 * See the README file for license conditions and contact info.
 * $Header: /home/johnl/flnb/code/RCS/fb3-2funcs.c,v 2.1 2009/11/08 02:53:18 johnl Exp $
 */
/*
 * helper functions for fb3-2
 */
#include<cstdio>
#include<cstdlib>
#include<cstdarg>
#include<cstring>
#include<cmath>
#include<iostream>
#include<sstream>
#include "array.hpp"
#include "adt.hpp"

using namespace std;

HashKey::HashKey (ADT * _key)
{	
	StrADT* k = dynamic_cast<StrADT *>(_key->ToString());
	string sk = k->Str();
	this->nKeyLength = sk.size();
	this->arKey  = new char[this->nKeyLength+1] ;
	uint i;
	for(i=0;i<this->nKeyLength;i++)
	{
		this->arKey[i] = sk[i];
	}	
	this->arKey[i] = 0;
	this->h = this->hash_func();
	this->key = _key->Duplicate();
}

HashKey::~HashKey ()
{
}
long HashKey::Atol()
{
	if(this->arKey[0]==0){
		return -1;
	}
	long j = 0;
	for(size_t i=0;;i++)
	{
		char c = this->arKey[i];
		if(c==0){
			break;
		}
		if(c<'0'||c>'9'){
			return -1;
		}
		j = 10*j +(long)(c-'0');
	}
	return j;
}
void HashKey::Print()
{
	this->key->Print();
}

bool HashKey::operator==(const HashKey &_hk)
{
	
	if(!strcmp(this->arKey,_hk.arKey)){
		return true;
	}
	return false;
}

bool HashKey::operator!=(const HashKey &_hk)
{
	
	if(!strcmp(this->arKey,_hk.arKey)){
		return false;
	}
	return true;
}
ulong HashKey::Key()
{
	return this->h;
}

bool HashKey::Equal(const HashKey &ht)
{
	if(!strcmp(this->arKey,ht.arKey)){
		return true;
	}
	return false;
}


HashKey* HashKey::Duplicate()
{
	
	HashKey* hk = new HashKey(this->key);
	
	return hk;
}
/*
 * Bucket
 */	
Bucket::Bucket(HashKey *_arKey,ADT *_pData)
{	
	this->arKey = _arKey;
	this->pData = _pData;	
	if(_arKey!=NULL){
		this->h = _arKey->Key();
	}
	this->pNext = NULL;	
}
Bucket::Bucket()
{
	this->arKey = NULL;
	this->pData = NULL;
	this->pNext = NULL;
}
ulong Bucket::Key()
{
	return this->h;
}
Bucket::~Bucket()
{
	if(this->pNext!=NULL){
		delete this->pNext;
	}
} 

bool Bucket::Hit(const HashKey&_arKey)
{	
	if(this->arKey==NULL){
		return false;
	}
	if(!this->arKey->Equal(_arKey)){
		return false;
	}
	return true;
}

void Bucket::SetData(ADT *_pData)
{
	if(this->pData!=NULL){
		delete this->pData;
	}
	this->pData = _pData;
}

void Bucket::SetKey(HashKey*_arKey)
{
	if(this->arKey!=NULL){
		delete this->arKey;
	}
	this->arKey = _arKey;	
	if(_arKey!=NULL){
		this->h = _arKey->Key();	
	}
}

void Bucket::Print()
{
	if(this->arKey!=NULL){
		this->arKey->Print();
	}
	cout<<"=>";
	if(this->pData!=NULL){
		this->pData->Print();	
	}
	cout<<"\n"<<endl;
}

/*
 * HashTable
 */	

HashTable::HashTable()
{

	uint nSize =50;
	uint i = 3;
	
	if (nSize >= 0x80000000) {
		this->nTableSize = 0x80000000;
	} else {
		while ((1U << i) < nSize) {
			i++;
		}
		this->nTableSize = 1 << i;
	}
	
	this->nTableMask = this->nTableSize - 1;
	this->arBuckets = NULL;
	this->pListHead = NULL;
	this->pListTail = NULL;
	this->nNumOfElements = 0;
	this->nNextFreeElement = 0;
	this->pInternalPointer = NULL;
	
	this->arBuckets = new Bucket* [this->nTableSize];
	for(i=0;i<this->nTableSize;i++)
	{
		this->arBuckets[i]= NULL;
	}
	
}


void HashTable::Set( HashKey*_arKey, ADT *_pData)
{

	ulong h;
	uint nIndex;
	Bucket *p;
	HashKey*arKey = _arKey;
	ADT *pData = _pData;
	
	if(arKey==NULL){
		arKey= new HashKey(new LongADT(this->nNextFreeElement));
	}
	
	h = arKey->Key();
	
	long hh = arKey->Atol();
	if(hh>=0){
		if ((long)hh >= (long)this->nNextFreeElement){
			this->nNextFreeElement = (ulong)hh + 1;
		}
	}
	
	nIndex = h & this->nTableMask;
	p = this->arBuckets[nIndex];
	if(p==NULL){
		this->arBuckets[nIndex] = new Bucket(arKey, pData);
		this->nNumOfElements++; 
		return;
	}
	for(;p!=NULL ;p=p->pNext)
	{
		if(p->Hit(*arKey)){
			p->SetData(pData);
			return ;
		}
		if(p->pNext==NULL){
			break;
		}
	}

	
	Bucket *tmp = new Bucket(arKey, pData);
	p->pNext = tmp;				
	this->nNumOfElements++; 
}

void HashTable::UnSet( HashKey*_arKey)
{
	Bucket *p,*pp;
	ulong h;
	uint nIndex;
	if(_arKey==NULL){
		return ;
	}
	h = _arKey->Key();
	
	nIndex = h & this->nTableMask;
	p=pp = this->arBuckets[nIndex];
	
	
	if(p->Hit(*_arKey)){
				this->arBuckets[nIndex] = p->pNext;
				delete p;
				return;
	}
	for(;p!=NULL ;p=p->pNext,pp=p)
	{
			if(p->Hit(*_arKey)){
				pp->pNext = p->pNext;
				delete p;
				return;
			}
	}	
}

ADT * HashTable::Get( HashKey*_arKey)
{
	ulong h;
	uint nIndex;
	Bucket *p;
	if(_arKey==NULL){
		return NULL;
	}
	
	h = _arKey->Key();
	
	//cout<<"lookup:"<<_arKey->AKey()<<endl;
	
	nIndex = h & this->nTableMask;

	for(p = this->arBuckets[nIndex];p!=NULL ;p=p->pNext)
	{
			//cout<<"cmp with:"<<p->AKey()<<endl;
			if(p->Hit(*_arKey)){
				return p->pData;
			}
	}	
	//cout<<endl<<endl;
	return NULL;
}
ADT * HashTable::Get( HashKey &_arKey)
{
	ulong h;
	uint nIndex;
	Bucket *p;
	h = _arKey.Key();
	
	nIndex = h & this->nTableMask;

	for(p = this->arBuckets[nIndex];p!=NULL ;p=p->pNext)
	{

			if(p->Hit(_arKey)){
				return p->pData;
			}
	}	
	return NULL;
}


HashTable::~HashTable()
{
	delete []this->arBuckets;
}

void HashTable::ReSize()
{
	if(this->nNumOfElements <= this->nTableSize){
		return;
	}
}

void HashTable::Print()
{
	Bucket *p;
	
	for(uint nIndex =0;nIndex<this->nTableSize;nIndex++)
	{
		//cout<<"bucket["<<nIndex<<"]"<<endl;
		for(p=this->arBuckets[nIndex];p!=NULL ;p=p->pNext)
		{
			p->Print();
		}	
	}
}
HashTable* HashTable::Duplicate()
{
	HashTable* ht = new HashTable();	
	Bucket *p;	
	//cout<<"duplicate hashtable"<<endl;
	for(uint nIndex =0;nIndex<this->nTableSize;nIndex++)
	{
		for(p=this->arBuckets[nIndex];p!=NULL ;p=p->pNext)
		{
			HashKey * newKey = NULL;
			ADT * newData = NULL;
			if(p->arKey==NULL){
				continue;
			}
			
			newKey = p->arKey->Duplicate();
			
			if(p->pData!=NULL){
				newData = p->pData->Duplicate();
			}
			ht->Set(newKey,newData);
		}	
	}
	//Set(HashKey*arKey, ADT *pData);
	//HashKey *arKey;
	return ht;
}



bool HashTable::Exist(HashKey*arKey)
{
	if(arKey==NULL){
		return false;
	}
	ulong h;
	uint nIndex;
	Bucket *p;
	h = arKey->Key();
	
	nIndex = h & this->nTableMask;

	for(p = this->arBuckets[nIndex];p!=NULL ;p=p->pNext)
	{

			if(p->Hit(*arKey)){
				return true;
			}
	}	
	return false;
}
ListADT* HashTable::Each()
{	
	ListADT * list = new ListADT(NULL,NULL);
	
	for(uint nIndex =0;nIndex<this->nTableSize;nIndex++)
	{
		for(Bucket *p=this->arBuckets[nIndex];p!=NULL ;p=p->pNext)
		{
			HashKey * newKey = NULL;
			ADT * newData = NULL;
			if(p->arKey==NULL){
				continue;
			}		
			
			newKey = p->arKey ;//->key->Duplicate();
			//newKey->key->Print();
			
			if(p->pData!=NULL){
				newData = p->pData->Duplicate();
			}
			list->push_back(new ListADT(new DoubleArrowADT(newKey->key->Duplicate(),newData),NULL));
		}	
	}
	return list;
}
/*
 * ArrayADT
 */	
 
ArrayADT::ArrayADT()
{
	this->ht = new HashTable();
}
ArrayADT::~ArrayADT()
{
	delete this->ht;
}
	
unsigned char ArrayADT::Type() 
{
	return ADT_IS_ARRAY;
}

ADT* ArrayADT::operator+(  ADT  &r)  
{
	return this;
}

ADT* ArrayADT::Concat( ADT & r)
{
	
	return new ArrayADT();
}
ADT* ArrayADT::Print( )
{
	cout<<"Array("<<endl;
	if(this->ht!=NULL){
		this->ht->Print();
	}
	cout<<")"<<endl;
	return NULL;
}


ADT* ArrayADT::operator[](ADT *dim)
{
	if(dim==NULL){
		return NULL;
	}
	HashKey * hk = new HashKey(dim);
	ADT * t = this->ht->Get(*hk);
	delete hk;
	return t;
}



ADT * ArrayADT::RealGet(HashKey & hk)
{
	return this->ht->Get(hk);
}	
void ArrayADT::RealSet(HashKey *k,ADT*v)
{
	this->ht->Set(k,v);
}

void ArrayADT::Append(ADT * val)
{	
	this->RealSet(NULL,val);
}

void ArrayADT::UnSet(ADT* dim)
{
	HashKey *hk = new HashKey(dim);
	this->ht->UnSet(hk);
}
ADT* ArrayADT::Get(ADT* key)
{
	HashKey *hk = new HashKey(key);
	return this->RealGet(*hk);
}
void ArrayADT::Set(ADT*key,ADT*val)
{
	HashKey *hk = NULL;
	if(key!=NULL){
		hk = new HashKey(key);
	}	
	this->RealSet(hk,val);
	
}
ADT* ArrayADT::Duplicate() 
{
	ArrayADT *array = new ArrayADT();
	array->ht = this->ht->Duplicate();
	return array;
}
bool ArrayADT::Exist(ADT* dim)
{
	if(dim==NULL){
		return false;
	}
	HashKey *hk = new HashKey(dim);
	return ht->Exist(hk);
}
ListADT* ArrayADT::Each()
{	
	return this->ht->Each();
}
