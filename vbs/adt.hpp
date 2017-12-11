#pragma once
#include<string>
#include<string>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include "sym.hpp"

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
	ADT_IS_BYREF,	
	ADT_IS_BYVAL,	
	ADT_IS_FUNCTION,
	ADT_IS_CLASS,
	ADT_IS_DUMMY,
	ADT_IS_VARIABLE,
};

/*
 * ADT应该是一个虚基类，本身不提供实现
 * 应该在其下生成一个提供基本实现的继承类
 * 其后所有类型继承自该基类
 * 
 * BasicADT:
			继承自父类AVAl(最基本的数据类型)
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
			继承自父类ADT（主要用于变量的表示，类似函数调用，或者数组偏移表达式）
			ADT_IS_DUMMY
 * ContainerADT:
			这一类ADT的特点是对外暴露自己的全部结构，可以由外部直接操纵
			也可以继续派生不对外暴露自己结构的ClassADT等结构
			继承自父类ADT（主要用于链表等一些存储结构，本身不提供计算能力）
			ADT_IS_DUMMY
 */

class ADT{  
public:
	virtual ~ADT(){}	
	virtual unsigned char Type()=0; //这个适应为通用的类型设计，主要用于debug
	
	
	virtual ADT* Print( ) =0;//这个适应为通用的类型设计
	
	virtual ADT* ToString( ) =0;//这个适应为通用的类型设计
	virtual ADT* ToLong( ) =0;//这个适应为通用的类型设计
	virtual ADT* ToDouble( ) =0;//这个适应为通用的类型设计
	virtual ADT* ToBool() =0; 
	//virtual ADT* ToInt( ) =0;//这个适应为通用的类型设计		
	
	virtual ADT* Concat( ADT &) =0;//这个适应为通用的类型设计
	
	virtual ADT* operator+( ADT &) =0;//这个适应为通用的类型设计，	
	virtual ADT* operator[](ADT *)=0; //这个适应为通用的类型设计，其实是特意为array类型保留的		
	virtual ADT* operator-( ADT &) =0;
	virtual ADT* operator*( ADT &) =0;
	virtual ADT* operator/( ADT &) =0;	
	virtual ADT* operator%( ADT &) =0;	
	virtual ADT* Duplicate() =0;	
	
	virtual ADT* Not() =0; 
	
	virtual ADT* operator==( ADT &) =0; 
	virtual ADT* operator!=( ADT &) =0; 
	virtual ADT* operator<( ADT &) =0;
	virtual ADT* operator<=( ADT &) =0;
	virtual ADT* operator>( ADT &) =0;
	virtual ADT* operator>=( ADT &) =0;	
	
	virtual ADT * ByVal() = 0;//按值传递
	virtual ADT * ByRef() = 0;//按引用传递
	
	virtual ADT * Parentheses(ADT*) = 0;//其实是为array或class或function用的，括号
};
 



///////////////////////////////////////////

class VariableADT:public ADT{  	
	ADT * var ;
	ADT * var_tail_list;
public:
	virtual ~VariableADT(){}	
	virtual unsigned char Type()
	{
		return ADT_IS_VARIABLE;
	}		
	virtual ADT* Print( )
	{
		ADT * adt = this->ByVal();
		if(adt!=NULL){
			return adt->Print();
		}
		return NULL;
	}
	
	virtual ADT* ToString( )
	{
		ADT * adt = this->ByVal();
		if(adt!=NULL){
			return adt->ToString();
		}
		return NULL;
	}
	virtual ADT* ToLong( )
	{
		ADT * adt = this->ByVal();
		if(adt!=NULL){
			return adt->ToLong();
		}
		return NULL;
	}
	virtual ADT* ToDouble( )
	{
		ADT * adt = this->ByVal();
		if(adt!=NULL){
			return adt->ToDouble();
		}
		return NULL;
	}
	virtual ADT* ToBool()
	{
		ADT * adt = this->ByVal();
		if(adt!=NULL){
			return adt->ToBool();
		}
		return NULL;
	}
	
	virtual ADT* Concat( ADT & _adt)
	{
		ADT * adt = this->ByVal();
		if(adt!=NULL){
			return adt->Concat(_adt);
		}
		return NULL;
	}
	
	virtual ADT* operator+( ADT & _adt)	
	{
		ADT * adt = this->ByVal();
		if(adt!=NULL){
			return *adt + _adt;
		}
		return NULL;
	}
	virtual ADT* operator[](ADT *_adt)
	{
		ADT * adt = this->ByVal();
		if(adt!=NULL){
			return (*adt)[_adt];
		}
		return NULL;
	}
	virtual ADT* operator-( ADT & _adt)
	{
		ADT * adt = this->ByVal();
		if(adt!=NULL){
			return *adt- _adt;
		}
		return NULL;
	}
	virtual ADT* operator*( ADT &_adt)
	{
		ADT * adt = this->ByVal();
		if(adt!=NULL){
			return *adt * _adt;
		}
		return NULL;
	}
	virtual ADT* operator/( ADT &_adt)
	{
		ADT * adt = this->ByVal();
		if(adt!=NULL){
			return *adt / _adt;
		}
		return NULL;
	}
	virtual ADT* operator%( ADT &_adt)
	{
		ADT * adt = this->ByVal();
		if(adt!=NULL){
			return *adt % _adt;
		}
		return NULL;
	}		
	virtual ADT* Not()
	{
		ADT * adt = this->ByVal();
		if(adt!=NULL){
			return adt->Not();
		}
		return NULL;
	}
	
	virtual ADT* operator==( ADT &_adt)
	{
		ADT * adt = this->ByVal();
		if(adt!=NULL){
			return *adt == _adt;
		}
		return NULL;
	}
	virtual ADT* operator!=( ADT &_adt)
	{
		ADT * adt = this->ByVal();
		if(adt!=NULL){
			return *adt != _adt;
		}
		return NULL;
	}	
	virtual ADT* operator<( ADT &_adt)
	{
		ADT * adt = this->ByVal();
		if(adt!=NULL){
			return *adt < _adt;
		}
		return NULL;
	}
	virtual ADT* operator<=( ADT &_adt)
	{
		ADT * adt = this->ByVal();
		if(adt!=NULL){
			return *adt <= _adt;
		}
		return NULL;
	}
	virtual ADT* operator>( ADT &_adt)
	{
		ADT * adt = this->ByVal();
		if(adt!=NULL){
			return *adt > _adt;
		}
		return NULL;
	}
	virtual ADT* operator>=( ADT &_adt)
	{
		ADT * adt = this->ByVal();
		if(adt!=NULL){
			return *adt >= _adt;
		}
		return NULL;
	}
	virtual ADT* Duplicate()
	{
		ADT * adt = this->ByVal();
		if(adt!=NULL){
			return adt->Duplicate();
		}
		return NULL;
	}
	virtual ADT* ByVal() 
	{
		ADT * result = NULL;
		if(this->var!=NULL){
			result = this->var->ByVal();
		}
		if(this->var_tail_list!=NULL){
		}
		return result;
	}
	
	virtual ADT* ByRef() 
	{
		return this;
	}
	
	virtual ADT* Assign(ADT *_adt) 
	{
		/*
			ADT * adt = this->ByVal();
			if(adt!=NULL){
				return adt->Assign(_adt);
			}
		*/
		
		return NULL;
	}	
	virtual ADT * Parentheses(ADT*)
	{
		return NULL;
	}

};


class CompoundVariableADT:public VariableADT{
	ADT * id;
	ADT * id_tail_list;
public:

	CompoundVariableADT() 
	{
		this->id = NULL;
		this->id_tail_list = NULL;
	}
	CompoundVariableADT(ADT * _id) 
	{
		this->id = _id;
		this->id_tail_list = NULL;
	}	
	CompoundVariableADT(ADT * _id,ADT* _id_comma_list) 
	{
		this->id = _id;
		this->id_tail_list = _id_comma_list;
	}
	ADT * Assign(ADT * val);
	virtual ~CompoundVariableADT() 
	{
	}
};



/***************************************ComplicateADT*****************************************************/
/*
class ComplicateADT:public InnerADT{  
public:
	~ComplicateADT(){}
};

class FetchArrayADT:public VariableADT{
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
};*/
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
	virtual ADT * Retrieve(ADT*)
	{
		return NULL;
	}
	virtual ADT * ByVal()
	{
		return this;
	}
	virtual ADT * ByRef()
	{
		return NULL;
	}
	virtual ADT * Parentheses(ADT*)
	{
		return NULL;
	}
};


class ConstValueADT:public BasicADT{  
public :
	~ConstValueADT(){}
};
class DoubleADT:public ConstValueADT{
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


class LongADT:public ConstValueADT{
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
class BoolADT:public ConstValueADT{
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
class StrADT:public ConstValueADT{
	char *s;  
	int len;  
public:
	StrADT()
	{
		this->s = NULL;
	}
	virtual ~StrADT()
	{
	}
	StrADT( const char * _s)
	{ 
		if(_s==NULL){
			return;
		}
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


class ExitSubADT:public FlowControlADT{  
public:
	ExitSubADT():FlowControlADT()
	{
	}
	
	ExitSubADT(ADT * _l):FlowControlADT(_l)
	{
	}		
	virtual ~ExitSubADT()
	{
	}		
};	
class ExitPropertyADT:public FlowControlADT{  
public:
	ExitPropertyADT():FlowControlADT()
	{
	}
	
	ExitPropertyADT(ADT * _l):FlowControlADT(_l)
	{
	}		
	virtual ~ExitPropertyADT()
	{
	}		
};	
class ExitDoADT:public FlowControlADT{  
public:
	ExitDoADT():FlowControlADT()
	{
	}	
	ExitDoADT(ADT * _l):FlowControlADT(_l)
	{
	}		
	virtual ~ExitDoADT()
	{
	}		
};
class ExitForADT:public FlowControlADT{  
public:
	ExitForADT():FlowControlADT()
	{
	}
	
	ExitForADT(ADT * _l):FlowControlADT(_l)
	{
	}		
	virtual ~ExitForADT()
	{
	}		
};
class ExitFunctionADT:public FlowControlADT{  
public:
	ExitFunctionADT():FlowControlADT()
	{
	}
	
	ExitFunctionADT(ADT * _l):FlowControlADT(_l)
	{
	}		
	virtual ~ExitFunctionADT()
	{
	}		
};

/****************************************VariableADT****************************************************/
//安值引用与按引用引用的区别主要是在写的时候，
//读变量的时候两者没有太大区别
//只要是在assign动作的时候，就体现出差别了
//所以只要管制assign的实现即可

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
	ADT * l;//某个symbol的adt
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
	
	//VariableByVal的赋值直接覆盖就可以了
	virtual void Assign( ADT *_l) //var特有的实现
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



class ByRefADT:public BasicADT{  
public:
	ADT * adt;
	ByRefADT()
	{
		this->adt = NULL;
	}		
	ByRefADT(ADT * _adt)
	{
		this->adt = _adt;
	}	
	virtual ~ByRefADT()
	{		
	}
};

class ByValADT:public BasicADT{  
public:
	ADT * adt;
	ByValADT()
	{
		this->adt = NULL;
	}		
	ByValADT(ADT * _adt)
	{
		this->adt = _adt;
	}	
	virtual ~ByValADT()
	{		
	}
};

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
		/*
		if(this->r!=NULL){
			delete r;
			this->r = NULL;
		}
		if(this->l!=NULL){
			delete this->l;
			this->l = NULL;
		}*/
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

class IdADT:public ContainerADT{  
public:
	char * name;
	IdADT()
	{
		this->name=NULL;
	}
	IdADT(const char* _name)
	{  
		
		this->name =NULL;
		if(_name==NULL){
			return;
		}
		int len = strlen(_name);
		this->name= new  char[len+1];
		if(len==0){
			this->name[0]=0;
			return;
		}		
		for(int i=0;i<=len;i++){
			this->name[i]=_name[i];
		}
	}
	virtual ~IdADT(){}	
}; 

/****************************************Class\Function::ADT***********************************************/
class FunctionADT:public BasicADT{
public:
	virtual ~FunctionADT(){}
	void * formal_param_list;
	void * statement;
	FunctionADT()
	{
		this->formal_param_list = NULL;
		this->statement=NULL;
	}
	FunctionADT(void * _formal_param_list,void * _statement)
	{
		this->formal_param_list = _formal_param_list;
		this->statement= _statement;
	}
};








