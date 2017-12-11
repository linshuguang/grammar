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
#include "ast.hpp"
#include "main.hpp"

using namespace std;

//GlobalVariableAST
Symbol * GlobalVariableAST::FindSymbol() 
{
	Symbol * s = NULL;
	if(this->var_name!=NULL){
		s = GLOBAL_SYMBOL_TABLE->Lookup(this->var_name);
	}
	return s;
}
ADT * GlobalVariableAST::eval() 
{  
	Symbol * s = this->FindSymbol();
	if(s==NULL){
		cout<<"no this global var_name "<<this->var_name<<endl;
		return NULL;
	}
	
	return static_cast<ADT*>(s->GetVal());
}
void GlobalVariableAST::Assign(ADT* _val)
{

	Symbol * s = this->FindSymbol();
	if(s==NULL){
		cout<<"no this global variable "<<this->var_name<<endl;
		return;
	}else{
		s->ReVal(_val);
	}
}

ADT* GlobalVariableAST::IsSet() 
{
	Symbol * s = this->FindSymbol();
	if(s==NULL || s->GetVal()==NULL){
		return new BoolADT(false);
	}
	return new BoolADT(true);
}

//SimpleVariableAST
Symbol * SimpleVariableAST::FindSymbol() 
{
	Symbol * s = NULL;
	if(this->var_name!=NULL){
		s = CURRENT_SYMBOL_TABLE->Lookup(this->var_name);
	}
	return s;
}
ADT * SimpleVariableAST::eval() 
{
	Symbol * s = this->FindSymbol();
	if(s==NULL){
		cout<<"no this var_name "<<this->var_name<<endl;
		return NULL;
	}
	return static_cast<ADT*>(s->GetVal());
}
void SimpleVariableAST::Assign(ADT* _val)
{

	Symbol * s = this->FindSymbol();
	if(s==NULL){
		cout<<"no this variable "<<this->var_name<<endl;
		return;
	}else{
		s->ReVal(_val);
	}
}
ADT* SimpleVariableAST::IsSet() 
{
	Symbol * s = this->FindSymbol();
	if(s==NULL|| s->GetVal()==NULL){
		return new BoolADT(false);
	}
	return new BoolADT(true);
}
//TempVariableAST
ADT * TempVariableAST::eval() 
{
	ADT * result = NULL;
	if(this->l!=NULL){
		result = this->l->eval();
	}
	return result;
}
void TempVariableAST::Assign(ADT* _val)
{
	cout<<"temp variable cannot assign"<<endl;
}
ADT* TempVariableAST::IsSet() 
{
	return new BoolADT(false);
}
//FetchArrayDimVariableAST
ADT* FetchArrayDimVariableAST::eval()
{
	ArrayADT *array =NULL;
	ADT *dim = NULL;
	if(this->l!=NULL){
		array = dynamic_cast<ArrayADT*>(this->l->eval());
	}
	if(this->r!=NULL){
		dim = this->r->eval();
	}
	if(array==NULL || dim==NULL){
		return NULL;
	}
	return array->Get(dim);
}

void FetchArrayDimVariableAST::Assign(ADT*val)
{
	ArrayADT *array =NULL;
	ADT *dim = NULL;
	if(this->l!=NULL){
		array = dynamic_cast<ArrayADT*>(this->l->eval());
	}
	if(this->r!=NULL){
		dim = this->r->eval();
	}
	if(array!=NULL && dim!=NULL){
		array->Set(dim,val);
	}
}
ADT* FetchArrayDimVariableAST::IsSet() 
{
	ArrayADT *array =NULL;
	ADT *dim = NULL;
	if(this->l!=NULL){
		array = dynamic_cast<ArrayADT*>(this->l->eval());
	}
	if(this->r!=NULL){
		dim = this->r->eval();
	}
	if(array!=NULL && dim!=NULL){
		ADT * s = array->Get(dim);
		if(s!=NULL){
			return new BoolADT(true);
		}
	}
	return new BoolADT(false);
}
//ListAST
ADT * ListAST::eval() 
{
	
	ADT * ll = NULL;
	ADT * rr = NULL;
	if(this->l!=NULL){
		
		ll = this->l->eval();
		if(ll){
		}
	}	
	if(this->r!=NULL){
		rr = this->r->eval();
	}
	return rr;
}


//StmtListAST
ADT* StmtListAST::eval()
{
	AST * l = ListAST::l;	
	AST * r = ListAST::r;	
	
	ADT * result = NULL;
	if(l!=NULL){
		result = l->eval();
		FlowControlADT * flow = dynamic_cast<FlowControlADT*>(result);
		if(flow!=NULL){
			return result;
		}
	}
	if(r!=NULL){
		result = r->eval();
	}
	return result;
}

//TopStmtListAST
ADT* TopStmtListAST::eval() 
{
	return StmtListAST::eval();
}
//InnerStmtListAST
ADT * InnerStmtListAST::eval() 
{
	return StmtListAST::eval();
}



//DoubleAST
ADT * DoubleAST::eval()
{
	return  new DoubleADT(this->dval);
}



//BoolAST
ADT* BoolAST::eval()
{
	return  new BoolADT(this->bval);
}
//LongAST
ADT* LongAST::eval()
{
	return  new LongADT(this->lval);
}
//StrAST
ADT* StrAST::eval()
{
	return new StrADT(this->str);
}

//ArrayAST
ADT * ArrayAST::eval()
{
	ArrayADT *result = new ArrayADT();
	for(ListAST *list = dynamic_cast<ListAST*>(this->pair_list);list!=NULL;list=dynamic_cast<ListAST*>(list->r))
	{	
		
		DoubleArrowExpr * arrow_expr = dynamic_cast<DoubleArrowExpr*>(list->l);		
		if(arrow_expr==NULL){
			continue;
		}
		DoubleArrowADT * arrow_val = dynamic_cast<DoubleArrowADT *>(arrow_expr->eval()); 
		if(arrow_val==NULL){
			continue;
		}
		
		ADT *key = arrow_val->key;
		ADT *val = arrow_val->val;				
		result->Set(key,val);
	}

	return result;
}

///---------------------------------

ADT * Exit::eval()
{
	//this->l->eval();
	return NULL;
}

ADT * Print::eval()
{
	if(this->l==NULL){
		return NULL;
	}
	
	
	//CURRENT_SYMBOL_TABLE->Print();
	ADT * t = this->l->eval();
	//cout<<"print:"<<t<<endl;
	if(t!=NULL){
		t->Print();
	}else{
		//cout<<"print null"<<endl;
	}
	return NULL;
}

ADT * Eval::eval()
{
	//this->l->eval();
	return NULL;
}



ADT* ConcatExpr::eval()
{
	
	ADT * ll = this->l->eval();
	ADT * rr = this->r->eval();
	return ll->Concat(*rr);
}

ADT * ConstArray::eval()
{
	ArrayADT *result = new ArrayADT();
	cout<<"const_aray:\n\t";
	for(ListADT *pair_list = dynamic_cast<ListADT*>(this->l);pair_list!=NULL;pair_list=dynamic_cast<ListADT*>(pair_list->r))
	{	
		DoubleArrowADT * arrow = dynamic_cast<DoubleArrowADT*>(pair_list->l);		
		if(arrow==NULL){
			continue;
		}
		ADT *key = arrow->key;
		ADT *val = arrow->val;		
		
		if(key!=NULL)key->Print();cout<<"=>";val->Print();cout<<endl;
		result->Set(key,val);
	}

	return result;
}


ADT * DoubleArrowExpr::eval()
{
	ADT * _key = NULL;
	ADT * _val = NULL;
	if(this->key!=NULL){
		_key = this->key->eval();
	}
	if(this->val!=NULL){
		_val = this->val->eval();
	}
	return new DoubleArrowADT(_key,_val);
}
/*
void FetchArrayDimRef::Assign( ADT * val )
{
	if(this->var==NULL){
		return;
	}
	ArrayADT * _var = dynamic_cast<ArrayADT * >(this->var->eval());
	if(_var ==NULL){
		return;
	}
	ADT *_dim=NULL;
	if(this->dim!=NULL){
		_dim = this->dim->eval();
	}
	_var->Set(_dim,val);
}
ADT* FetchArrayDimRef::eval()
{
	//cout<<"eval"<<endl;
	ADT *_var = NULL;
	ADT *_dim=NULL;
	if(this->var!=NULL){
		_var = this->var->eval();
	}
	if(this->dim!=NULL){
		_dim = this->dim->eval();
	}
	
	FetchArrayDimVariableADT * fa =  new FetchArrayDimVariableADT(_var,_dim);
	return fa->Get();
}*/
//按值赋值的表达式
ADT* AssignExpr::eval()
{
	//AssignExpr
	VariableAST *var= dynamic_cast<VariableAST *>(this->l);
	if(var==NULL){
		cout<<"assign on non variable"<<endl;
		return NULL;
	
	}
	ADT * val = NULL;
	if(this->r!=NULL){
		val = this->r->eval();
	}	
	var->Assign(val);

	return val;
}

ADT* PreIncExpr::eval()
{
	if(this->var==NULL){
		return NULL;
	}
	ADT * _v = this->var->eval();
	return _v->PreInc();
}
ADT* PostIncExpr::eval()
{
	if(this->var==NULL){
		return NULL;
	}
	ADT * _v = this->var->eval();
	return _v->PostInc();
}
ADT* PreDecExpr::eval()
{
	if(this->var==NULL){
		return NULL;
	}
	ADT * _v = this->var->eval();
	return _v->PreDec();
}
ADT* PostDecExpr::eval()
{
	if(this->var==NULL){
		return NULL;
	}
	ADT * _v = this->var->eval();
	return _v->PostDec();
}


ADT* AddExpr::eval()
{
	ADT * ll = this->l->eval();
	ADT * rr = this->r->eval();
	return *ll + *rr;
}

ADT * SubExpr::eval()
{
	if(this->l==NULL || this->r==NULL){
		return NULL;
	}
	ADT * ll = this->l->eval();
	ADT * rr = this->r->eval();
	return *ll - *rr;
}

ADT * MulExpr::eval()
{
	if(this->l==NULL || this->r==NULL){
		return NULL;
	}
	ADT * ll = this->l->eval();
	ADT * rr = this->r->eval();
	return *ll * *rr;
}
ADT * DivExpr::eval()
{
	if(this->l==NULL || this->r==NULL){
		return NULL;
	}
	ADT * ll = this->l->eval();
	ADT * rr = this->r->eval();
	return *ll / *rr;
}

ADT * ModExpr::eval()
{
	if(this->l==NULL || this->r==NULL){
		return NULL;
	}
	ADT * ll = this->l->eval();
	ADT * rr = this->r->eval();
	return *ll % *rr;
}
ADT* NotExpr::eval()
{
	if(this->l==NULL){
		return NULL;
	}
	ADT * ll = this->l->eval();
	return ll->Not();
}






ADT* EqualExpr::eval()
{
	ADT * ll = NULL;
	ADT * rr = NULL;
	if(this->l!=NULL){
		ll = this->l->eval();
	}
	if(this->r!=NULL){
		rr = this->r->eval();
	}
	return *ll == *rr;
}
ADT* NotEqualExpr::eval()
{
	ADT * ll = NULL;
	ADT * rr = NULL;
	if(this->l!=NULL){
		ll = this->l->eval();
	}
	if(this->r!=NULL){
		rr = this->r->eval();
	}
	return *ll != *rr;
}
ADT* SmallThanExpr::eval()
{
	
	ADT * ll = NULL;
	ADT * rr = NULL;
	if(this->l!=NULL){
		ll = this->l->eval();
	}
	if(this->r!=NULL){
		rr = this->r->eval();
	}
	return *ll < *rr;	
}
ADT* SmallEqualExpr::eval()
{
	ADT * ll = NULL;
	ADT * rr = NULL;
	if(this->l!=NULL){
		ll = this->l->eval();
	}
	if(this->r!=NULL){
		rr = this->r->eval();
	}
	return *ll <= *rr;
}
ADT* GreatThanExpr::eval()
{
	ADT * ll = NULL;
	ADT * rr = NULL;
	if(this->l!=NULL){
		ll = this->l->eval();
	}
	if(this->r!=NULL){
		rr = this->r->eval();
	}
	return *ll > *rr;
}
ADT* GreatEqualExpr::eval()
{
	ADT * ll = NULL;
	ADT * rr = NULL;
	if(this->l!=NULL){
		ll = this->l->eval();
	}
	if(this->r!=NULL){
		rr = this->r->eval();
	}
	return *ll >= *rr;
}
ADT* CommaExpr::eval() 
{
	ListAST * list = dynamic_cast<ListAST *>(this->l);
	
	if(list==NULL){
		return NULL;
	}
	ADT *result= NULL;
	for(;list!=NULL;list=dynamic_cast<ListAST*>(list->r))
	{
		if(list->l!=NULL){
			result =list->l->eval();
		}
	}
	return result;
}

ADT * QmExpr::eval() 
{
	if(this->expr==NULL){
		return NULL;
	}
	ADT * result = NULL;
	
	result = this->expr->eval();
	if(result!=NULL){
		BoolADT *cont =dynamic_cast<BoolADT *>(result->ToBool());	
		result = NULL;
		if(cont!=NULL){
			bool c = (bool)*cont;
			if(c){
				if(this->first!=NULL){
					result = this->first->eval();
				}		
			}else {
				if(this->second!=NULL){
					result = this->second->eval();
				}		
			}
		}
	}
	return result;
}

ADT* IsSetExpr::eval() 
{
	
	for(ListAST * list = dynamic_cast<ListAST * >(this->var_list);list!=NULL;list = dynamic_cast<ListAST * >(list->r))
	{
		VariableAST * var = dynamic_cast<VariableAST * >(list->l);
		if(var==NULL){
			continue;
		}
		BoolADT * result = dynamic_cast<BoolADT*>(var->IsSet());
		if(result==NULL){
			continue;
		}
		bool c = (bool)(*result);
		if(!c){
			return new BoolADT(false);
		}
	}

	return new BoolADT(true);
}
ADT * EmptyExpr::eval() 
{
	ADT * result=NULL;
	if(this->var!=NULL){
		result = this->var->eval();
	}
	if(result==NULL){
		return new BoolADT(true);
	}
	
	return result->Empty();
//	return NULL;
}
/*-------------------------------------stmt------------------------------------------*/

//--------unticked_stmt------
//static int i=0;
ADT* UnTickedStmt::eval()
{
	//i++;
	//int j =i;
	//cout<<"unticked eval begin "<<&j<<":"<<i<<endl;
	ADT * result = NULL;
	for(ListAST* sl = dynamic_cast<ListAST*>(this->stmt_list);sl!=NULL;sl = dynamic_cast<ListAST *>(sl->r))
	{
		//cout<<"in stmt: "<<j<<endl;
		if(sl->l==NULL){
			continue;
		}
		result = sl->l->eval();
		if( NULL!=dynamic_cast<FlowControlADT *>(result)){
			break;
		}
	}
	//cout<<"unticked eval end"<<j<<endl;
	return result;
}
ADT* UnTickedStmt::Jmp(ADT * _label)
{
	AST * start = this->FindLabelDetail(_label);
	ListAST * sl = dynamic_cast<ListAST *>(start);
	if(sl==NULL){
		return NULL;
	}		
	Stmt* st = dynamic_cast<Stmt*>(sl->l);
	ADT * result = NULL;
	if(st!=NULL){	
		//cout<<"unticked jmp ok"<<endl;
		result = st->Jmp(_label);
		if( NULL!=dynamic_cast<FlowControlADT *>(result)){
			return result;
		}
	
	}
	//return NULL;
	for(sl=dynamic_cast<ListAST *>(sl->r);sl!=NULL;sl = dynamic_cast<ListAST *>(sl->r))
	{
		if(sl->l==NULL){
			continue;
		}
		result = sl->l->eval();
		if( NULL!=dynamic_cast<FlowControlADT *>(result)){
			break;
		}
	}
	return result;
}

bool UnTickedStmt::FindLabel(ADT * _label)
{
	//cout<<"stmt list findlabel"<<endl;
	for(ListAST * sl = dynamic_cast<ListAST *>(this->stmt_list);sl!=NULL;sl = dynamic_cast<ListAST *>(sl->r))
	{		
		Stmt * st = dynamic_cast<Stmt*>(sl->l);
		if(st==NULL){
			continue;
		}	
		//cout<<"s:"<<i++<<endl;
		if(st->FindLabel(_label)){
			return true;
		}
	}
	return false;
}

AST * UnTickedStmt::FindLabelDetail(ADT * _label)
{
	AST * result = NULL;
	//cout<<"stmt list findlabel"<<endl;
	for(ListAST * sl = dynamic_cast<ListAST *>(this->stmt_list);sl!=NULL;sl = dynamic_cast<ListAST *>(sl->r))
	{		
		Stmt * st = dynamic_cast<Stmt*>(sl->l);
		if(st==NULL){
			continue;
		}		
		if(st->FindLabel(_label)){
			result = sl;
			break;
		}
	}
	return result;
}

bool InnerStmt::FindLabel(ADT * _label)
{
	//std::cout<<"In InnerStmt ----------------------"<<std::endl;
	return UnTickedStmt::FindLabel(_label);
}
	
bool TopStmt::FindLabel(ADT * _label)
{
	//std::cout<<"In TopStmt ----------------------"<<std::endl;
	return UnTickedStmt::FindLabel(_label);
}
//label
ADT* LabelStmt::Jmp(ADT * _label)
{
	return this->eval();
}
bool LabelStmt::FindLabel(ADT * _label)
{
	//cout<<"label find label"<<endl;
	if(_label!=NULL && this->label!=NULL){
		ADT * this_label  = this->label->eval();
		ADT *ret = (*this_label == *_label);
		BoolADT * ba = dynamic_cast<BoolADT *>(ret);
		bool c = (bool)*ba;
		if(c){
			return true;
		}
	}
	return false;
}
ADT * LabelStmt::eval()
{
	return this->label->eval();
}



//--------------flow_stmt------------
bool FlowStmt::IsOK()
{
	if(this->expr==NULL){
		return false;
	}
	ADT * result = this->expr->eval();
	if(result==NULL){
		return false;
	}
	BoolADT * ba = dynamic_cast<BoolADT *>(result->ToBool());
	bool c= (bool)(*ba);
	return c;
}
bool FlowStmt::IsOK(ADT * cmp)
{
	if(this->expr==NULL){
		return false;
	}
	ADT * cmp1 = this->expr->eval();
	if(cmp1==NULL){
		return false;
	}
	BoolADT * ba = dynamic_cast<BoolADT *>(*cmp==*cmp1);
	bool c= (bool)(*ba);
	return c;
}
ADT * FlowStmt::Jmp(ADT * _label)
{
	Stmt *  st = dynamic_cast<Stmt*>(this->statement);
	return st->Jmp(_label);
}
bool FlowStmt::FindLabel(ADT * _label)
{
	Stmt *  st = dynamic_cast<Stmt*>(this->statement);
	return st->FindLabel(_label);
}
ADT * FlowStmt::eval()
{
	return this->statement->eval();
}
//-----------------if--------------
ADT * IfStmt::eval()
{
	
	ADT * result = NULL;	
	//int i=0;
	for(ListAST* next= dynamic_cast<ListAST*>(this->flow_list);next!=NULL;next= dynamic_cast<ListAST*>(next->r))
	{		
		FlowStmt * flow = dynamic_cast<FlowStmt *>(next->l);
		if(flow==NULL){
			continue;
		}
		//cout<<"flow eval "<<i++<<endl;
		if(flow->IsOK()){
			result = flow->eval();
			break;
		}
	}
	return result;
}
ADT* IfStmt::Jmp(ADT * _label)
{
	AST * start = this->FindLabelDetail(_label);
	ListAST * sl = dynamic_cast<ListAST *>(start);
	if(sl==NULL){
		return NULL;
	}
	Stmt* st = dynamic_cast<Stmt*>(sl->l);
	if(st==NULL){
		return NULL;
	}
	
	ADT * result = st->Jmp(_label);
	if(dynamic_cast<FlowControlADT *>(result)!=NULL){
		return result;
	}	
	result = NULL;
	for(ListAST* next= dynamic_cast<ListAST*>(sl->r);next!=NULL;next= dynamic_cast<ListAST*>(next->r))
	{
		
		IfFlow * if_flow = dynamic_cast<IfFlow *>(next->l);
		if(if_flow==NULL){
			continue;
		}
		if(if_flow->IsOK()){
			result = if_flow->eval();
			if(dynamic_cast<FlowControlADT *>(result)!=NULL){
				return result;
			}	
		}
	}
	return result;
}
bool IfStmt::FindLabel(ADT * _label)
{
	//cout<<"if find label"<<endl;
	for(ListAST* next= dynamic_cast<ListAST*>(this->flow_list);next!=NULL;next= dynamic_cast<ListAST*>(next->r))
	{
		Stmt * st = dynamic_cast<Stmt *>(next->l);
		if(st==NULL){
			continue;
		}
		if(st->FindLabel(_label)){	
			return true;
		}
	}
	return false;
}
AST * IfStmt::FindLabelDetail(ADT * _label)
{
	AST * result = NULL;	
	for(ListAST* next= dynamic_cast<ListAST*>(this->flow_list);next!=NULL;next= dynamic_cast<ListAST*>(next->r))
	{
		Stmt * st = dynamic_cast<Stmt *>(next->l);
		if(st==NULL){
			continue;
		}
		if(st->FindLabel(_label)){	
			result = next;
			break;
		}
	}
	return result;
}
//-----------------while--------------
ADT * WhileStmt::eval()
{
	if(this->expr==NULL){
		return NULL;
	}
	ADT * result = NULL;
	for(;;)
	{
		result = this->expr->eval();
		if(result==NULL){
			break;
		}
		BoolADT *cont =dynamic_cast<BoolADT*> (result->ToBool());
		if((bool)*cont == false){
			break;
		}
		if(this->statement==NULL){
			break;
		}
		result = this->statement->eval();
		FlowControlADT * flow = dynamic_cast<FlowControlADT*>(result);
		if(flow!=NULL){
			if(flow->IsContinue()){
				continue;
			}else{
				if(flow->IsBreak()){
					result = flow->Param();
				}
				break;
			}
		}
	}
	return result;
}

ADT * WhileStmt::Jmp(ADT * _label)
{
	Stmt* st = dynamic_cast<Stmt*>(this->statement);
	if(st==NULL){
		return NULL;
	}
	ADT* result = st->Jmp(_label);
	FlowControlADT * flow = dynamic_cast<FlowControlADT*>(result);
	if(flow!=NULL && !flow->IsContinue()){
		return result;
	}	
	return this->eval();
}
bool WhileStmt::FindLabel(ADT * _label)
{
	//cout<<"while find label"<<endl;
	Stmt* st = dynamic_cast<Stmt*>(this->statement);
	if(st==NULL){
		return false;
	}
	return st->FindLabel(_label);
}
//-----------------do-while--------------

ADT * DoWhileStmt::eval()
{
	ADT * result = NULL;
	for(;;)
	{
		if(this->statement!=NULL){
			result = this->statement->eval();
			FlowControlADT * flow = dynamic_cast<FlowControlADT*>(result);
			if(flow!=NULL){
				if(flow->IsContinue()){
					continue;
				}else{
					if(flow->IsBreak()){
						result = flow->Param();
					}
					break;
				}
			}
		}		
		BoolADT *cont =dynamic_cast<BoolADT*> (this->expr->eval()->ToBool());
		if((bool)*cont == false){
			break;
		}
	}
	return result;
}
ADT * DoWhileStmt::Jmp(ADT * _label)
{
	Stmt* st = dynamic_cast<Stmt*>(this->statement);
	ADT* result = st->Jmp(_label);
	FlowControlADT * flow = dynamic_cast<FlowControlADT*>(result);
	if(flow!=NULL && !flow->IsContinue()){
		return result;
	}	
	return this->eval();
}
bool DoWhileStmt::FindLabel(ADT * _label)
{
	//cout<<"do-while find label"<<endl;
	Stmt* st = dynamic_cast<Stmt*>(this->statement);
	if(st==NULL){
		return false;
	}
	return st->FindLabel(_label);
}
//-----------------for--------------

ADT * ForStmt::eval()
{
	if(this->init_expr!=NULL){
		this->init_expr->eval();
	}
	ADT * result = NULL;
	for(;;)
	{
		if(this->cond_expr!=NULL){
			result = this->cond_expr->eval();	
			if(result!=NULL){			
				BoolADT * cnt = dynamic_cast<BoolADT*>(result->ToBool());
				if(cnt!=NULL){
					bool c = (bool)(*cnt);					
					if(!c){
						break;
					}
				}			
			}
		}
		
		if(this->statement!=NULL){
			result = this->statement->eval();
			if(result!=NULL){
				FlowControlADT * flow = dynamic_cast<FlowControlADT*>(result);
				if(flow!=NULL){
					if(!flow->IsContinue()){
						if(flow->IsBreak()){
							result = flow->Param();
						}
						break;
					}
				}			
			}
		}		
		if(this->cont_expr!=NULL){
			this->cont_expr->eval();
		}
		
	}
	return result;
}
	
ADT * ForStmt::Jmp(ADT * _label)
{
	Stmt* st = dynamic_cast<Stmt*>(this->statement);
	ADT* result = st->Jmp(_label);
	FlowControlADT * flow = dynamic_cast<FlowControlADT*>(result);
	if(flow!=NULL && !flow->IsContinue()){
		return result;
	}	
	return this->eval();
}
bool ForStmt::FindLabel(ADT * _label)
{
	//cout<<"for find label"<<endl;
	Stmt* st = dynamic_cast<Stmt*>(this->statement);
	if(st==NULL){
		return false;
	}
	return st->FindLabel(_label);
}
//-----------------Switch--------------
ADT* SwitchStmt::eval()
{
	ADT * result =NULL;
	
	ADT * cont = this->expr->eval();
	for(ListAST* next= dynamic_cast<ListAST*>(this->case_list);next!=NULL;next= dynamic_cast<ListAST*>(next->r))
	{
		FlowStmt * fs = dynamic_cast<FlowStmt *>(next->l);
		if(fs==NULL){
			continue;
		}		
		if(fs->IsOK(cont)){	
			result =fs->eval();
			FlowControlADT * flow_control = dynamic_cast<FlowControlADT *>(result);
			if(flow_control!=NULL){
				if(flow_control->IsBreak()){					
					result = flow_control->Param();
				}
				break;
			}	
		}
	}	
	return result;
}
ADT * SwitchStmt::Jmp(ADT * _label)
{
	AST * start = this->FindLabelDetail(_label);
	ListAST * sl = dynamic_cast<ListAST *>(start);
	if(sl==NULL){
		return NULL;
	}
	Stmt* st = dynamic_cast<Stmt*>(sl->l);
	if(st==NULL){
		return NULL;
	}
	//cout<<"Switch jmp ok"<<endl;
	ADT * cont = NULL;
	ADT * result = st->Jmp(_label);
	FlowControlADT * flow_control = dynamic_cast<FlowControlADT *>(result);
	if(flow_control!=NULL){
		if(flow_control->IsBreak()){					
			result = flow_control->Param();
		}
		return result;
	}	
	result = NULL;
	for(ListAST* next= dynamic_cast<ListAST*>(sl->r);next!=NULL;next= dynamic_cast<ListAST*>(next->r))
	{		
		IfFlow * if_flow = dynamic_cast<IfFlow *>(next->l);
		if(if_flow==NULL){
			continue;
		}
		if(if_flow->IsOK(cont)){
			result = if_flow->eval();
			FlowControlADT * flow_control = dynamic_cast<FlowControlADT *>(result);
			if(flow_control!=NULL){
				if(flow_control->IsBreak()){					
					result = flow_control->Param();
				}
				break;
			}	
		}
	}
	return result;
}
bool SwitchStmt::FindLabel(ADT * _label)
{
	//cout<<"switch find label"<<endl;
	for(ListAST* next= dynamic_cast<ListAST*>(this->case_list);next!=NULL;next= dynamic_cast<ListAST*>(next->r))
	{
		Stmt * st = dynamic_cast<Stmt *>(next->l);
		if(st==NULL){
			continue;
		}
		if(st->FindLabel(_label)){	
			return true;
		}
	}
	return false;
}

AST * SwitchStmt::FindLabelDetail(ADT * _label)
{
	AST * result = NULL;	
	for(ListAST* next= dynamic_cast<ListAST*>(this->case_list);next!=NULL;next= dynamic_cast<ListAST*>(next->r))
	{
		Stmt * st = dynamic_cast<Stmt *>(next->l);
		if(st==NULL){
			continue;
		}
		if(st->FindLabel(_label)){	
			result = next;
			//cout<<"switch found label"<<endl;
			break;
		}
	}
	return result;
}
	
//foreach
ADT* ForeachStmt ::eval()
{
	if(this->variable==NULL){
		return NULL;
	}
	ADT * result = this->variable->eval();
	ArrayADT * array = dynamic_cast<ArrayADT*>(result);
	if(array==NULL){
		return NULL;
	}
	
	
	VariableAST * key_variable=dynamic_cast<VariableAST *>(this->foreach_variable);
	VariableAST * val_variable=dynamic_cast<VariableAST *>(this->foreach_optional_arg);
	for(ListADT * each= array->Each();each!=NULL;each=dynamic_cast<ListADT*>(each->r))
	{
		DoubleArrowADT* double_arrow = dynamic_cast<DoubleArrowADT*>(each->l);
		if(double_arrow==NULL){
			continue;
		}
		//double_arrow->Print();
		
		if(key_variable!=NULL){
			key_variable->Assign(double_arrow->key);
		}
		if(val_variable !=NULL){
			val_variable->Assign(double_arrow->val);
		}
			
		if(this->statement!=NULL){
			result = this->statement->eval();
			
			FlowControlADT * flow_control = dynamic_cast<FlowControlADT*>(result);
			if(flow_control!=NULL){
				if(flow_control->IsBreak() || flow_control->IsContinue()){
					result = flow_control->Param();
				}
				break;
			}
			
		}
		
	}
	cout<<endl;
	return result;
}


//break
ADT * BreakStmt::eval()
{
	ADT * ll = NULL;
	if(this->l!=NULL){
		ll = this->l->eval();
	}
	return new BreakADT(ll);
}
//continue
ADT * ContinueStmt::eval()
{
	ADT * ll = NULL;
	if(this->l!=NULL){
		ll = this->l->eval();
	}
	return new ContinueADT(ll);
}
//return
ADT * ReturnStmt::eval()
{
	ADT * ll = NULL;
	if(this->l!=NULL){
		ll = this->l->eval();
	}
	return new ReturnADT(ll);
}
//goto
ADT * GotoStmt::eval()
{
	ADT * l = NULL;
	if(this->label!=NULL){
		l = this->label->eval();
	}
	return new GotoADT(l);
}
//--------------------function---------------------


ADT * Function::eval()
{
	
	ADT * result = NULL;
	
	if(this->statement!=NULL){
		result = this->statement->eval();
	}
	
	for(;;)
	{
		FlowControlADT* flow_control = dynamic_cast<FlowControlADT*>(result);		
		if(flow_control!=NULL){			
			result= flow_control->Param();
			break;
			if(flow_control->IsGoto()){
				ADT * label = result;
				Stmt * st = dynamic_cast<Stmt*>(this->statement);
				if(st==NULL || !st->FindLabel(label)){
					break;
				}
				result = st->Jmp(label);
				continue;
			}
		}
		break;
		/*
		
		if(flow_control->IsGoto()){
			ADT * label = flow_control->Param();
			Stmt * st = dynamic_cast<Stmt*>(this->statement);
			if(st==NULL || !st->FindLabel(label)){
				break;
			}
			result = st->Jmp(label);
		}else{
			result = flow_control->Param();
			break;
		}
		}else{
			break;
		}*/
	}
	return result;
}
bool CallFunction::PrepareEnv(SymbolTable * symtbl,AST * formal_param_list)
{
	
	ListAST * actual_list = dynamic_cast<ListAST*>(this->actual_param_list);
	ListAST * formal_list = dynamic_cast<ListAST*>(formal_param_list);
	
	if(actual_list==NULL && formal_list==NULL){
		return true;
	}
	if(actual_list!=NULL && formal_list!=NULL){
		for(;;actual_list=dynamic_cast<ListAST *>(actual_list->r),formal_list=dynamic_cast<ListAST *>(formal_list->r))
		{
			if((actual_list!=NULL && formal_list!=NULL)){				
				if(formal_list->l==NULL){
					cout<<"bad formal param "<<endl;
					break;
				}
				StrADT * formal = dynamic_cast<StrADT*>(formal_list->l->eval());
				if(formal==NULL){
					cout<<"bad formal param 2"<<endl;
					break;
				}
				Symbol * t = symtbl->Lookup(formal->Str().c_str());
				if(t==NULL){
					cout<<"no symbol "<<endl;
					break;
				}
				ADT * actual = actual_list->l->eval();
				t->ReVal(actual);
			}else if((actual_list==NULL && formal_list==NULL)){
				break;
			}else{
				cout<<"actual param and formal param not matched"<<endl;
				return false;
			}
		}
	}else{
		cout<<"actual param and formal param not matched"<<endl;
		return false;
	}
	return true;
}

ADT * CallFunction::CallUser(Symbol *func_sym)
{	

	//int j= i;
	

	AST * func_ast = static_cast<AST*>(func_sym->GetVal());
	if(func_ast==NULL){
		cout<<"call no ast user function"<<endl;
		return NULL;
	}
	
	//cout<<"ok"<<endl;

	Function *func = dynamic_cast<Function*>(func_ast);
	if(func==NULL){
		cout<<"call not real function"<<endl;
		return NULL;
	}
	
	SymbolTable * new_symtbl = func->symtbl->Dump();
	if(new_symtbl==NULL){
		cout<<"call user function cannot alloc res"<<endl;
		return NULL;
	}
	
	ADT * result = NULL;
	
	if(this->PrepareEnv(new_symtbl,func->formal_param_list)){	
		
		SYMBOL_TABLE_STACK->Push(new_symtbl);	
		
		result = func->eval();
		
		SYMBOL_TABLE_STACK->Pop();
		
	}else{
		cout<<"PrepareEnv error"<<endl;
	}
	delete new_symtbl;
	
	return result;
}
ADT * CallFunction::CallMod(Symbol *func_sym)
{
	
	if(func_sym==NULL){
		return NULL;
	}
	typedef ADT* (*MOD_FUNC_WRAPPER)(ListADT *); 
	MOD_FUNC_WRAPPER func_ptr = (MOD_FUNC_WRAPPER)func_sym->GetVal();
	if(func_ptr==NULL){
		cout<<"call null mod function"<<endl;
	}
	ListADT * list = NULL;
	for(ListAST * actual_list = dynamic_cast<ListAST*>(this->actual_param_list);actual_list!=NULL;actual_list = dynamic_cast<ListAST*>(actual_list->r))
	{
		if(actual_list->l==NULL){
			continue;
		}
		if(list==NULL){
			list = new ListADT(actual_list->l->eval(),NULL);
		}else{
			list->push_back(new ListADT(actual_list->l->eval(),NULL));
		}
		
	}
	ADT *result = func_ptr(list);	
	delete list;
	return result;
}

ADT * CallFunction::eval()
{
	//static int i=0;
	//i++;
	ADT * result = NULL;
	if(this->func_name==NULL){
		cout<<"call what?"<<endl;
		return NULL;
	}
	StrADT * name = dynamic_cast<StrADT*>(this->func_name->eval());
	if(name==NULL){
		return NULL;
	}
	string s = name->Str();
	Symbol * func_sym = GLOBAL_FUNCTION_TABLE->Lookup(s.c_str());
	if(func_sym!=NULL){
		//int j= i;
		//cout<<"call user begin "<<j<<endl;
		result = this->CallUser(func_sym);		
		//cout<<"call user end" <<j<<endl;
	}else{
		func_sym = MOD_FUNCTION_TABLE->Lookup(s.c_str());
		if(func_sym==NULL){
			cout<<"call no symbol mod function"<<endl;
			return NULL;
		}
		result = this->CallMod(func_sym);
	}
	
	FlowControlADT * flow_control = dynamic_cast<FlowControlADT*>(result);
	if(flow_control!=NULL){
		result = flow_control->Param();
	}
	return result;
}


