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

ADT * IdAST::eval()
{
	ADT * result = NULL;
	/*
	Symbol * s = CURRENT_SYMBOL_TABLE->Lookup(_id->name);
	if(s==NULL){
		cout<<"no this symbol "<<_id->name<<endl;
		exit(-1);
	}
	result = static_cast<ADT *>(s->GetVal());
	//}		
	return result;
	*/
	return new IdADT(this->name);	
}


ADT * ByValAST::eval()
{
	ADT * result = NULL;
	if(this->ast!=NULL){
		result = this->ast->eval();
	}
	return result;
	//return new ValueADT(result);
}
ADT *ByRefAST::eval()
{
	ADT * result = NULL;
	if(this->ast!=NULL){
		result = this->ast->eval();
	}
	//return new ByRefADT(result);
	return NULL;
	//return new ValueADT(result);
}

ADT * VariableAST::eval()
{
	ADT * result = NULL;
	if(this->var!=NULL){
		result = this->var->eval();
	}
	if(this->var_tail_list!=NULL){
	}
	return result;
}

ADT * VariableAST::Assign(AST * _val)
{
	ADT * val = NULL;
	//if(_val!=NULL){
		//val = _val->eval();
	//}
	CompoundVariableAST * _var = dynamic_cast<CompoundVariableAST * >(this->var);
	if(_var==NULL){
		return val;
	}
	if(var_tail_list==NULL){
		val = _var->Assign(_val);
	}else{
	}
	/*
	AST * var ;
	AST * var_tail_list;
	ADT * result = NULL;
	if(this->var!=NULL){
		result = this->var->eval();
	}
	if(this->var_tail_list!=NULL){
	}*/
	
	return val;
}

			
ADT * CompoundVariableAST::eval()
{		
	ADT * result = NULL;
	ADT * _id = NULL;
	ADT * _id_comma_list = NULL;
	if(this->id!=NULL){
		_id = this->id->eval();
	}
	
	if(this->id_comma_list!=NULL){
		_id_comma_list = this->id_comma_list->eval();
	}
	return new CompoundVariableADT(_id,_id_comma_list);
}
ADT * CompoundVariableAST::Assign( AST * val)
{		
	ADT * result = NULL;
	if(val!=NULL){
		result = val->eval();
	}
	
	for(IdAST * _id = dynamic_cast<IdAST *>(this->id);_id!=NULL;)
	{
		Symbol * s = CURRENT_SYMBOL_TABLE->Lookup(_id->name);
		if(s==NULL){
			cout<<"no this symbol "<<_id->name<<endl;
			exit(-1);
		}
		if(id_comma_list==NULL){//如果就是一个id			
			s->ReVal(result);
		}else{//如果是函数或者是数组			
			ADT * adt = static_cast<ADT *>(s->GetVal());
			
			ArrayADT* array = dynamic_cast<ArrayADT*>(adt);			
			if(array!=NULL){//如果是数组
				
				break;
			}
			
			FunctionADT* function = dynamic_cast<FunctionADT*>(adt);			
			if(function!=NULL){//如果是函数
				break;
			}
		}	
		break;
	}	
	return result;
}

ADT * VarDeclAST::eval()
{
	if(this->id==NULL){
		return NULL;
	}
	if(this->comma_list==NULL){
		CURRENT_SYMBOL_TABLE->Register(this->id);
		return NULL;
	}
	ListADT * list = dynamic_cast<ListADT*>(this->comma_list->eval());
	ArrayADT * array = new ArrayADT(list);
	CURRENT_SYMBOL_TABLE->Register(this->id,array);
	return NULL;
}


ADT * SimpleVarDeclAST::eval()
{
	//cout<<"simple var decl :"<<this->id<<endl;
	
	return NULL;
}

ADT * ArrayVarDeclAST::eval()
{
	//cout<<"array var decl :"<<this->id<<endl;
	
	ListADT * list_adt =NULL;
	for(ListAST * list = dynamic_cast<ListAST*>(this->comma_list);list!=NULL;list =dynamic_cast<ListAST*>(list->r) )
	{
		ADT * dimention =  NULL;
		if(list->l==NULL){
			cerr<<"dimentionlist"<<endl;
		}
		dimention = list->l->eval()	;
		if(list_adt==NULL){
			list_adt = new ListADT(dimention,NULL);
		}else{
			list_adt->push_back( new ListADT(dimention,NULL));
		}		
	}
	ArrayADT * array = new ArrayADT(list_adt);
	CURRENT_SYMBOL_TABLE->Register(this->id,array);
	return NULL;
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
	return new ListADT(ll,rr);
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
	return new DoubleADT(this->dval);
}



//BoolAST
ADT* BoolAST::eval()
{
	//return  new ValueADT(new BoolADT(this->bval));
	return  new BoolADT(this->bval);
}
//LongAST
ADT* LongAST::eval()
{
	//return  new ValueADT(new LongADT(this->lval));
	return new LongADT(this->lval);
}
//StrAST
ADT* StrAST::eval()
{
	//return new ValueADT(new StrADT(this->str));
	return new StrADT(this->str);
}

//ArrayAST
ADT * ArrayAST::eval()
{
	ArrayADT *result = new ArrayADT();
	for(ListAST *list = dynamic_cast<ListAST*>(this->pair_list);list!=NULL;list=dynamic_cast<ListAST*>(list->r))
	{	
		/*
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
		 */
	}

	//return new ValueADT(result);
	return result;
}

///---------------------------------

ADT * Exit::eval()
{
	ADT * result=NULL;
	if(this->l!=NULL){
		result = this->l->eval();
	}
	exit(0);
	return result;
}

ADT * Print::eval()
{
	if(this->l==NULL){
		return NULL;
	}	
	//CURRENT_SYMBOL_TABLE->Print();
	ADT * t = this->l->eval();
	//cout<<"print ok"<<t<<endl;
	//cout<<"print1 "<<t<<endl;
	//cout<<"print1 "<<endl;
	if(t!=NULL){
		t->Print();
	}else{
		//cout<<"print null"<<endl;
	}
	//cout<<"print ok"<<endl;
	//cout<<"print2 "<<endl;
	return NULL;
}

//Eval


ADT * Eval::eval()
{
	
	ADT * result = NULL;
	ADT * actual_str = NULL;
	if(this->str!=NULL){
		result = this->str->eval();
		if(result!=NULL){
			actual_str = result->ToString();
		}
	}
	
	if(actual_str!=NULL){
		AST * tmp_top_ast = NULL;
		char eval_tmpnam [L_tmpnam];
		tmpnam(eval_tmpnam);
		freopen( eval_tmpnam, "w", stdout );
		cout<<"<%"<<endl;
		actual_str->Print();
		cout<<endl<<"%>";
		freopen( "CON", "w", stdout );
		
		cout<<yylineno<<":";
		FILE * fp = fopen(eval_tmpnam,"r");
		FILE * old_yyin = yyin;
		//stdout = fp;
		yyin = fp;
		//fclose(fp);
		
		PUSH_TOP_AST();
		
		int tok;
		while((tok=yylex())){
			//yylex();
			yyparse();
		}
		tmp_top_ast = CURRENT_TOP_AST;
		
		POP_TOP_AST();
		
		yyin= old_yyin;
		//stdin
		if(tmp_top_ast!=NULL){
			//cout<<"tmp_top_ast not null"<<endl;
			result = tmp_top_ast->eval();
		}
		fclose(fp);
		remove (eval_tmpnam); 
	}
	
	return result;
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


//按值赋值的表达式
ADT* AssignExpr::eval()
{
	VariableAST * var = dynamic_cast<VariableAST*>(this->l);
	if(var==NULL){
		cout<<"assgin null error"<<endl;
		return NULL;
	}
	//ADT * val = NULL;
	/*
	ADT * ll = NULL;
	if(this->l==NULL){
		return result;
	}else{
		ll = this->l->eval();
	}
	
	ADT * rr = NULL;
	if(this->r==NULL){
		return val;
	}else{
		val = this->r->eval();
	}*/
	return var->Assign(this->r);
	//return result;
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



/*-------------------------------------stmt------------------------------------------*/

//--------unticked_stmt------
//static int i=0;
ADT* BlockStmt::eval()
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
ADT* BlockStmt::Jmp(ADT * _label)
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

bool BlockStmt::FindLabel(ADT * _label)
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

AST * BlockStmt::FindLabelDetail(ADT * _label)
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

bool InnerBlockStmt::FindLabel(ADT * _label)
{
	//std::cout<<"In InnerStmt ----------------------"<<std::endl;
	return BlockStmt::FindLabel(_label);
}
	
bool TopBlockStmt::FindLabel(ADT * _label)
{
	//std::cout<<"In TopStmt ----------------------"<<std::endl;
	return BlockStmt::FindLabel(_label);
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
			break;
			/*
			FlowControlADT * flow_control = dynamic_cast<FlowControlADT *>(result);
			if(flow_control!=NULL){
				if(flow_control->IsBreak()){					
					result = flow_control->Param();
				}
				break;
			}
*/			
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
	
//Case 
bool CaseFlow::IsOK(ADT * cmp)
{
	if(cmp==NULL){
		return false;
	}
	for(ListAST * l = dynamic_cast<ListAST *>(FlowStmt::expr);l!=NULL;l=dynamic_cast<ListAST *>(l->r))
	{
		//CaseFlow(AST * _expr,AST * _statement):FlowStmt(_expr, _statement)
		AST * expr = l->l;
		if(expr==NULL){
			continue;
		}
		ADT * cmp1 = expr->eval();
		if(cmp1==NULL){
			continue;
		}
		BoolADT * ba = dynamic_cast<BoolADT *>(*cmp==*cmp1);
		bool c= (bool)(*ba);
		if(c){
			return true;
		}
	}
	return false;
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



ADT * DimStmt:: eval()
{
	
	for(ListAST * list = dynamic_cast<ListAST*>(this->var_list);list!=NULL;list =dynamic_cast<ListAST*>(list->r))
	{
		VarDeclAST * var_decl = dynamic_cast<VarDeclAST *>(list->l);
		if(var_decl==NULL){
			continue;
		}
		var_decl->eval();
		//$1->value.str.val
		//StrList * id = <Str>
	}
	return NULL;
}
//--------------------function---------------------

/*

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
		
		///////////
		//if(flow_control->IsGoto()){
		//	ADT * label = flow_control->Param();
		//	Stmt * st = dynamic_cast<Stmt*>(this->statement);
		//	if(st==NULL || !st->FindLabel(label)){
		//		break;
		//	}
		//	result = st->Jmp(label);
		//}else{
		//	result = flow_control->Param();
		//	break;
		//}
		//}else{
		//	break;
		//}
		//////////
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
	
	SymbolTable * new_symtbl = NEW_SYMBOL_TABLE();
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
	//delete list;
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
	Symbol * func_sym = CURRENT_SYMBOL_TABLE->Lookup(s.c_str());
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


*/
ADT* CallExpr::DestroyEnv()
{	
	ADT * result = NULL;
	SymbolTable * symtbl = SYMBOL_TABLE_STACK->Pop();
	/*
	IdAST * id = dynamic_cast<IdAST*>(this->function_name);
	if(id==NULL){
		cout<<"call what?"<<endl;
		return NULL;
	}
	Symbol * s = symtbl->Lookup(id->name);
	if(s==NULL){
		cout<<"call not defined function "<<id->name<<endl;
		exit(-1);
	}*/	
	
	delete symtbl;
	return result;
}

bool CallExpr::BuildEnv(AST * formal_param_list)
{	
	SymbolTable * symtbl = GLOBAL_SYMBOL_TABLE->Dump();
	if(symtbl==NULL){
		cout<<"call user function cannot alloc res"<<endl;
		return false;
	}
	
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
				}else if(actual_list->l==NULL){
					cout<<"bad actual param "<<endl;
					break;
				}
				IdAST * id = dynamic_cast<IdAST*>(formal_list->l);
				if(id==NULL){
					cout<<"bad formal param 2"<<endl;
					break;
				}
				
				ADT * actual = actual_list->l->eval();
				
				Symbol * t = symtbl->Lookup(id->name);
				if(t==NULL){
					symtbl->Register(id->name,actual);
				}else{				
					t->ReVal(actual);
				}
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
	SYMBOL_TABLE_STACK->Push(symtbl);	
	return true;
}

ADT * CallExpr::eval()
{
	cout<<"call eval"<<endl;
	ADT * result = NULL;
	IdAST * id = dynamic_cast<IdAST*>(this->function_name);
	if(id==NULL){
		cout<<"call what?"<<endl;
		return NULL;
	}
	Symbol * s = CURRENT_SYMBOL_TABLE->Lookup(id->name);
	if(s==NULL){
		cout<<"call not defined function "<<id->name<<endl;
		exit(-1);
	}	
	
	FunctionADT * func = static_cast<FunctionADT*>(s->GetVal());
	if(func==NULL){
		cout<<"call not defined function "<<id->name<<endl;
		exit(-1);
	}
	AST * formal_param_list = static_cast<AST*>(func->formal_param_list);
	AST * statement = static_cast<AST*>(func->statement);	
	this->BuildEnv(formal_param_list);
	if(statement!=NULL){
		result = statement->eval();
	}
	
	this->DestroyEnv();
	
	
	FlowControlADT * flow_control = dynamic_cast<FlowControlADT*>(result);
	if(flow_control!=NULL){
		result = flow_control->Param();
	}
	return result;
}

