#pragma once
#include<string>
#include<string>
#include<cstring>
#include<iostream>


enum ADT_TYPE{
	ADT_IS_NULL,
	ADT_IS_LONG,
	ADT_IS_DOUBLE,
	ADT_IS_BOOL,
	ADT_IS_ARRAY,
	ADT_IS_OBJECT,
	ADT_IS_STRING,
	ADT_IS_RESOURCE,
	ADT_IS_CONSTANT,
	ADT_IS_CONSTANT_ARRAY,	
	ADT_IS_DUMMY,
};

/*
 * ADTӦ����һ������࣬�����ṩʵ��
 * Ӧ������������һ���ṩ����ʵ�ֵļ̳���
 * ����������ͼ̳��Ըû���
 * 
 * BasicADT:
			�̳��Ը���AVAl(���������������)
			ADT_IS_NULL,
			ADT_IS_LONG,
			ADT_IS_DOUBLE,
			ADT_IS_BOOL,
			ADT_IS_ARRAY,
			ADT_IS_OBJECT,
			ADT_IS_STRING,
			ADT_IS_RESOURCE,
			ADT_IS_CONSTANT,
			ADT_IS_CONSTANT_ARRAY,
 * ComplicateADT:
			�̳��Ը���ADT����Ҫ���ڱ����ı�ʾ�����ƺ������ã���������ƫ�Ʊ��ʽ��
			ADT_IS_DUMMY
 * ContainerADT:
			��һ��ADT���ص��Ƕ��Ⱪ¶�Լ���ȫ���ṹ���������ⲿֱ�Ӳ���
			Ҳ���Լ������������Ⱪ¶�Լ��ṹ��ClassADT�Ƚṹ
			�̳��Ը���ADT����Ҫ���������һЩ�洢�ṹ�������ṩ����������
			ADT_IS_DUMMY
 */
class ADT{  
public:
	virtual ~ADT(){}	
	virtual unsigned char Type()=0; //�����ӦΪͨ�õ�������ƣ���Ҫ����debug
	
	
	virtual ADT* Print( ) =0;//�����ӦΪͨ�õ��������
	
	virtual ADT* ToString( ) =0;//�����ӦΪͨ�õ��������
	virtual ADT* ToLong( ) =0;//�����ӦΪͨ�õ��������
	virtual ADT* ToDouble( ) =0;//�����ӦΪͨ�õ��������
	virtual ADT* ToBool() =0; 
	//virtual ADT* ToInt( ) =0;//�����ӦΪͨ�õ��������		
	
	virtual ADT* Concat( ADT &) =0;//�����ӦΪͨ�õ��������
	
	virtual ADT* operator+( ADT &) =0;//�����ӦΪͨ�õ�������ƣ�	
	virtual ADT* operator[](ADT *)=0; //�����ӦΪͨ�õ�������ƣ���ʵ������Ϊarray���ͱ�����		
	virtual ADT* operator-( ADT &) =0;
	virtual ADT* operator*( ADT &) =0;
	virtual ADT* operator/( ADT &) =0;	
	virtual ADT* operator%( ADT &) =0;	
	virtual ADT* Duplicate() =0;	
	
	virtual ADT* PreInc() =0; 
	virtual ADT* PostInc() =0; 
	virtual ADT* PreDec() =0; 
	virtual ADT* PostDec() =0; 
	
	virtual ADT* Not() =0; 
	
	virtual ADT* operator==( ADT &) =0; 
	virtual ADT* operator!=( ADT &) =0; 
	virtual ADT* operator<( ADT &) =0;
	virtual ADT* operator<=( ADT &) =0;
	virtual ADT* operator>( ADT &) =0;
	virtual ADT* operator>=( ADT &) =0;	
	virtual ADT *Empty()=0;
};  




/***************************************BASIC_AVAL*****************************************************/

class BasicADT:public ADT{  
public:
	
	virtual ~BasicADT(){}	
	virtual unsigned char Type()
	{
		return ADT_IS_DUMMY;
	}
	virtual ADT* operator+( ADT &) 
	{
		return NULL;
	}
	virtual ADT* Concat( ADT &)
	{
		
		return NULL;
	}
	virtual ADT* Print( )
	{
		return NULL;
	}
	virtual ADT* ToString( ) 
	{
		return NULL;
	}
	virtual ADT* ToLong( ) 
	{
		return NULL;
	}
	virtual ADT* ToDouble( ) 
	{
		return NULL;
	}
	
	
	virtual ADT* operator[](ADT *)
	{
		return NULL;
	}
	virtual ADT* operator-( ADT &)
	{
		return NULL;
	}
	virtual ADT* operator*( ADT &) 
	{
		return NULL;
	}
	virtual ADT* operator/( ADT &) 
	{
		return NULL;
	}
	virtual ADT* operator%( ADT &) 
	{
		return NULL;
	}
	virtual ADT* Duplicate() 
	{
		return NULL;
	}
	virtual ADT* ToBool() 
	{
		return NULL;
	}
	virtual ADT* PreInc()
	{
		return NULL;
	}	
	virtual ADT* PostInc()
	{
		return NULL;
	}
	virtual ADT* PreDec()
	{
		return NULL;
	}	
	virtual ADT* PostDec()
	{
		return NULL;
	}
	
	virtual ADT* Not() 
	{
		return NULL;
	}
	
	virtual ADT* operator==( ADT &) 
	{
		return NULL;
	}
	virtual ADT* operator!=( ADT &) 
	{
		return NULL;
	}
	virtual ADT* operator<( ADT &) 
	{
		return NULL;
	}
	virtual ADT* operator<=( ADT &) 
	{
		return NULL;
	}
	virtual ADT* operator>( ADT &) 
	{
		return NULL;
	}
	virtual ADT* operator>=( ADT &) 
	{
		return NULL;
	}	
	virtual ADT *Empty()
	{
		return NULL;
	}
};

class DoubleADT:public BasicADT{
	double  dval;
public:
	DoubleADT()
	{
	}
	DoubleADT( double _dval)
	{
		this->dval = _dval; 
	}
	operator double()
	{
		return this->dval;
	}		
	unsigned char Type() ;
	ADT* operator+( ADT & );	
	ADT* operator-( ADT & );	
	ADT* operator*( ADT & );	
	ADT* operator/( ADT & );	
	ADT* operator%( ADT & );	
	
	ADT* Concat( ADT &);
	ADT* Print( );
	
	virtual ADT* Duplicate() 
	{
		return new DoubleADT(this->dval);
	}
	ADT* ToString( );
	ADT* ToBool() ; 
	ADT* ToLong() ; 
	ADT* ToDouble() ; 
	
	ADT* Not();
	
	ADT* operator==( ADT &) ;
	ADT* operator!=( ADT &) ;
	ADT* operator<( ADT &) ;
	ADT* operator<=( ADT &) ;
	ADT* operator>( ADT &) ;
	ADT* operator>=( ADT &) ;	
	ADT* Empty();
	
};


class LongADT:public BasicADT{
	long lval;
public:
	LongADT(){}
	LongADT(long _lval)
	{
		this->lval = _lval;
	}
	operator long()
	{
		return this->lval;
	}
	unsigned char Type() ;
	ADT* operator+( ADT & )  ;
	ADT* operator-( ADT & );	
	ADT* operator*( ADT & );	
	ADT* operator/( ADT & );	
	ADT* operator%( ADT & );	
	
	ADT* Concat( ADT &);
	ADT* Print( );
	
	virtual ADT* Duplicate() 
	{
		return new LongADT(this->lval);
	}
	
	virtual ADT* PreInc()
	{
		this->lval++;
		return this;
	}	
	virtual ADT* PostInc()
	{	
		long l = this->lval;
		this->lval++;
		return new LongADT(l);
	}
	virtual ADT* PreDec()
	{
		this->lval--;
		return this;
	}	
	virtual ADT* PostDec()
	{	
		long l = this->lval;
		this->lval--;
		return new LongADT(l);
	}
	ADT* ToString( );
	ADT* ToBool() ; 
	ADT* ToLong() ; 
	ADT* ToDouble() ; 
	
	ADT* Not();
	
	ADT* operator==( ADT &) ;
	ADT* operator!=( ADT &) ;
	ADT* operator<( ADT &) ;
	ADT* operator<=( ADT &) ;
	ADT* operator>( ADT &) ;
	ADT* operator>=( ADT &) ;	
	ADT* Empty();
};
class BoolADT:public BasicADT{
	bool bval;
public:
	BoolADT(){}
	BoolADT(bool _bval)
	{
		this->bval = _bval; 
	}
	operator bool()
	{
		return this->bval;
	}
	unsigned char Type() ;	
	
	ADT* operator+( ADT & ) ;	
	
	ADT* Concat( ADT &);
	ADT* Print( );
	
	virtual ADT* Duplicate() 
	{
		return new BoolADT(this->bval);
	}
	ADT* ToString( );
	ADT* ToBool() ; 
	ADT* ToLong() ; 
	ADT* ToDouble() ; 
	ADT* Not();
	ADT* Empty();
};
class StrADT:public BasicADT{
	char *s;  
	int len;  
public:
	StrADT()
	{
		this->s = NULL;
	}
	virtual ~StrADT()
	{
		if(this->s != NULL) {
			delete this->s;
		}
		this->s = NULL;
	}
	StrADT( const char * _s)
	{ 
		this->len = strlen(_s);
		this->s = new char[this->len +1];  
		for(int i=0;i<this->len;i++)
		{
			this->s[i]= _s[i];
		}
		this->s[this->len]=0;
	}
	StrADT( const std::string str)
	{ 
		this->len = str.length();
		this->s = new char[this->len +1];  
		for (size_t i=0; i < str.length(); i++)
		{
			this->s[i] = str[i];
		}
		this->s[this->len]=0;
	}
	std::string Str()
	{ 
		return std::string(this->s);
	}
	unsigned char Type() ;	
	ADT* operator+( ADT & ) ;		
	ADT* Concat( ADT &);
	ADT* Print( );
	
	virtual ADT* Duplicate() 
	{
		return new StrADT(this->s);
	}
	ADT* ToBool() ; 
	ADT* ToString( );
	ADT* ToLong() ; 
	ADT* ToDouble() ;
	ADT* Not();
	
	ADT* operator==( ADT &) ;
	ADT* operator!=( ADT &) ;
	ADT* Empty();
};
/***************************************************************************************/


/****************************************Container::ADT***********************************************/


class ContainerADT:public BasicADT{  
public:
	virtual ~ContainerADT(){}		
};

class ListADT:public ContainerADT{  //LListADT:ContainerADT
public:
	ADT * l;
	ADT * r;
	virtual ~ListADT()
	{
		if(this->r!=NULL){
			delete r;
			this->r = NULL;
		}
		if(this->l!=NULL){
			delete this->l;
			this->l = NULL;
		}
	}	
	ListADT()
	{ 
		this->l= NULL;
		this->r=NULL;
	}	
	ListADT(ADT*_l,ADT*_r)
	{
		this->l=_l;
		this->r=_r;
	}	
	void push_back(ADT* n)
	{
		ListADT *ll = this;
		for(;ll!=NULL;ll=dynamic_cast<ListADT*>(ll->r))
		{
			if(ll->r==NULL){
				break;
			}
		}
		ll->r = n;
	}
};  


/****************************************Container::ADT***********************************************/


class FlowControlADT:public BasicADT{  
	ADT * l;
public:
	FlowControlADT()
	{
		this->l = NULL;
	}		
	FlowControlADT(ADT * _l)
	{
		this->l = _l;
	}		
	virtual ~FlowControlADT()
	{		
	}		
	virtual ADT* Param()
	{
		return this->l;
	}	
	virtual bool IsBreak()
	{
		return false;
	}
	virtual bool IsContinue()
	{
		return false;
	}
	virtual bool IsReturn()
	{
		return false;
	}
	virtual bool IsGoto()
	{
		return false;
	}

};
class BreakADT:public FlowControlADT{  
public:
	BreakADT():FlowControlADT()
	{
	}
	
	BreakADT(ADT * _l):FlowControlADT(_l)
	{
	}		
	virtual ~BreakADT()
	{
	}		
	virtual bool IsBreak()
	{
		return true;
	}
};
class ContinueADT:public FlowControlADT{  
public:
	ContinueADT():FlowControlADT()
	{
	}
	
	ContinueADT(ADT * _l):FlowControlADT(_l)
	{
	}		
	virtual ~ContinueADT()
	{
	}		
	virtual bool IsContinue()
	{
		return true;
	}
};
class ReturnADT:public FlowControlADT{  
public:
	ReturnADT():FlowControlADT()
	{
	}
	
	ReturnADT(ADT * _l):FlowControlADT(_l)
	{
	}		
	virtual ~ReturnADT()
	{
	}		
	virtual bool IsReturn()
	{
		return true;
	}
};
class GotoADT:public FlowControlADT{  
public:
	GotoADT():FlowControlADT()
	{
	}
	
	GotoADT(ADT * _l):FlowControlADT(_l)
	{
	}		
	virtual ~GotoADT()
	{
	}		
	virtual bool IsGoto()
	{
		return true;
	}
};

/****************************************VariableADT****************************************************/
//��ֵ�����밴�������õ�������Ҫ����д��ʱ��
//��������ʱ������û��̫������
//ֻҪ����assign������ʱ�򣬾����ֳ������
//����ֻҪ����assign��ʵ�ּ���

/*
class VariableADT:public BasicADT{  
public:
	virtual ~VariableADT(){}	
	virtual void Assign( ADT *t) =0;	
	virtual void UnSet() {}	
	virtual ADT* ToBool()
	{
		return new BoolADT(true);
	}
};  



class SimpleVariableADT:public VariableADT{
	ADT * l;//ĳ��symbol��adt
public:
	SimpleVariableADT() 
	{
		this->l = NULL;
	}
	
	SimpleVariableADT(ADT * _l ) 
	{
		this->l = _l;
	}
	
	virtual~SimpleVariableADT() 
	{		
	}
	virtual void UnSet() 
	{
		this->l = NULL;
	}		
	
	//VariableByVal�ĸ�ֱֵ�Ӹ��ǾͿ�����
	virtual void Assign( ADT *_l) //var���е�ʵ��
	{
		std::cout<<"simple assign"<<std::endl;
		this->l = _l;
	}
	
	virtual ADT* operator+( ADT & _l) 
	{
		if(this->l==NULL){
			return NULL;
		}		
		return *this->l+ _l;
	}
	
	virtual ADT* Concat( ADT &_l) 
	{
		if(this->l==NULL){
			return NULL;
		}		
		return this->l->Concat(_l);
	}
	
	virtual ADT* Print( ) 
	{
		std::cout<<"print"<<std::endl;
		if(this->l==NULL){
			return NULL;
		}		
		this->l->Print();
		return NULL;
	}
	
	virtual ADT* ToString( ) 
	{
		if(this->l==NULL){
			return NULL;
		}		
		return this->l->ToString();
	}
	virtual ADT* Duplicate( ) 
	{
		if(this->l==NULL){
			return NULL;
		}		
		return this->l->Duplicate();
	}
};


class FetchArrayDimVariableADT:public VariableADT{
	ADT * array;
	ADT * dim;
public:
	FetchArrayDimVariableADT()
	{
		this->array=NULL;
		this->dim = NULL;
	}
	FetchArrayDimVariableADT( ADT * _array,ADT * _dim){this->array = _array; this->dim = _dim;}
	unsigned char Type() {return ADT_IS_DUMMY;}
	ADT* operator+( ADT & );//  {return NULL;}
	ADT* Concat( ADT &);
	ADT* Print( );//{return NULL;}
	ADT* ToString();//{return NULL;}
	ADT* Get();
	void Assign( ADT *t) ;
	virtual void UnSet() ;
	ADT*  ToBool();
};
*/
/****************************************CompoundADT****************************************************/
class CompoundADT:public BasicADT{ 
public:
	virtual ~CompoundADT()
	{
	}		
};  

class DoubleArrowADT:public CompoundADT{
public:
	ADT * key;
	ADT * val;

	DoubleArrowADT()
	{
		this->key=NULL;
		this->val = NULL;
	}
	DoubleArrowADT( ADT * _key,ADT * _val)
	{
		this->key = _key; 
		this->val = _val;
	}
	ADT* Print( )
	{
		std::cout<<'"';
		if(this->key!=NULL){
			this->key->Print();
		}else{
			std::cout<<"NULL";
		}
		std::cout<<"\"=>\"";
		if(this->val!=NULL){
			this->val->Print();
		}else{
			std::cout<<"NULL";
		}
		std::cout<<"\""<<std::endl;
		return NULL;
	}
};












