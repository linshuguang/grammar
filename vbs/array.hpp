#pragma once
#include<string>
#include "sym.hpp"
#include "adt.hpp"
#include "ast.hpp"

using namespace std;

typedef unsigned long ulong;
typedef unsigned int uint;

class HashKey {
	ADT* key;
	char *arKey;
	uint nKeyLength;
	ulong h;
	ulong hash_func()
	{
		char* _arKey = this->arKey;
		uint _nKeyLength = this->nKeyLength;
		register ulong hash = 5381;
		/* variant with the hash unrolled eight times */
		for ( ; _nKeyLength >= 8; _nKeyLength -= 8) 
		{
			hash = ((hash << 5) + hash) + *_arKey++;
			hash = ((hash << 5) + hash) + *_arKey++;
			hash = ((hash << 5) + hash) + *_arKey++;
			hash = ((hash << 5) + hash) + *_arKey++;
			hash = ((hash << 5) + hash) + *_arKey++;
			hash = ((hash << 5) + hash) + *_arKey++;
			hash = ((hash << 5) + hash) + *_arKey++;
			hash = ((hash << 5) + hash) + *_arKey++;
		}
		switch (_nKeyLength) 
		{
			case 7: 
				hash = ((hash << 5) + hash) + *_arKey++; /* fallthrough... */
			case 6: 
				hash = ((hash << 5) + hash) + *_arKey++; /* fallthrough... */
			case 5: 
				hash = ((hash << 5) + hash) + *_arKey++; /* fallthrough... */
			case 4: 
				hash = ((hash << 5) + hash) + *_arKey++; /* fallthrough... */
			case 3: 
				hash = ((hash << 5) + hash) + *_arKey++; /* fallthrough... */
			case 2: 
				hash = ((hash << 5) + hash) + *_arKey++; /* fallthrough... */
			case 1: 
				hash = ((hash << 5) + hash) + *_arKey++; break;
			case 0: 
				break;
			default:
				break;
		}
		return hash;
	}

public:
	HashKey (ADT * _key);
	const char * AKey (){return this->arKey;}
	void Print();
	long Atol();
	~HashKey ();
	ulong Key();
	bool Equal(const HashKey &);
	bool operator==(const HashKey &_hk);
	bool operator!=(const HashKey &_hk);
	HashKey* Duplicate();
	friend class Bucket;
	friend class HashTable;
} ;

class Bucket {
	ulong h;						/* Used for numeric indexing */
	ADT *pData;
	HashKey *arKey;
	class Bucket * pNext;
public:
	bool Hit(const HashKey&_arKey);
	ulong Key();
	void Print();
	void SetData(ADT *_pData);
	void SetKey(HashKey*_arKey);
	Bucket(HashKey *_arKey,ADT *_pData);
	Bucket(HashKey &_arKey,ADT *_pData);
	Bucket();	
	~Bucket();
	friend class HashTable;
} ;



class HashTable {
	uint nTableSize;
	uint nTableMask;
	uint nNumOfElements;
	ulong nNextFreeElement;
	class Bucket *pInternalPointer;	/* Used for element traversal */
	class Bucket *pListHead;
	class Bucket *pListTail;
	class Bucket **arBuckets;
	void ReSize();	
public:
	HashTable();
	~HashTable();	
	
	void Print();
	void Set(HashKey*arKey, ADT *pData);	
	void UnSet(HashKey*arKey);	
	ADT * Get(HashKey*arKey);
	ADT * Get(HashKey&arKey);
	HashTable* Duplicate();
	bool Exist(HashKey*arKey);
	ListADT* Each();
	ADT* Empty()
	{
		if(this->nNumOfElements==0){
			return new BoolADT(true);
		}
		return  new BoolADT(false);
	}
} ;



class ArrayADT:public ConstValueADT{
	HashTable *ht;
	ADT * RealGet(HashKey &);
	void RealSet(HashKey *,ADT*);
	ADT * dimention;
public:
	
	ArrayADT();
	ArrayADT(ADT * _dimetion_list);
	~ArrayADT();
	unsigned char Type() ;
	ADT* operator+( ADT & ) ;	
	ADT* Concat( ADT &);
	ADT* Print( );
	ADT* ToString( ){return NULL;}
	ADT* operator[](ADT *);
	virtual ADT* Duplicate();
	ADT * ToBool()
	{
		return new BoolADT(true);
	}
	
	bool Exist(ADT*);
	ADT* Get(ADT*);	
	void Set(ADT*,ADT*);			
	void Append(ADT *);
	void UnSet(ADT*);		
	ListADT* Each();
	ADT* Retrieve(ADT*);	
	ADT* Assign(ADT*,ADT*);
	//virtual ADT * Parentheses(ADT*);

};









