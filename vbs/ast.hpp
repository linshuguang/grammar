#pragma once
#pragma once
#include<string>
#include "sym.hpp"
#include "adt.hpp"
#include "array.hpp"




class AST{
public:
	AST() {}
	virtual ADT * eval() = 0;
	virtual~AST() {}
};
class ByValAST:public AST{
	AST * ast;
public:
	ByValAST() 
	{
		this->ast =NULL;
	}
	ByValAST(AST * _ast) 
	{
		this->ast = _ast;
	}
	virtual ADT * eval();
	virtual~ByValAST() {}
};
class ByRefAST:public AST{
	AST * ast;
public:
	ByRefAST() 
	{
		this->ast =NULL;
	}
	ByRefAST(AST * _ast) 
	{
		this->ast = _ast;
	}
	virtual ADT * eval() ;
	virtual~ByRefAST() {}
};

class IdAST:public AST{	
public:
	char * name;
	IdAST()
	{
		this->name=NULL;
	}
	IdAST(const char* _name)
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
	~IdAST() {}
	virtual ADT * eval() ;
};

class VariableAST:public AST{
	AST * var ;
	AST * var_tail_list;
public:
	VariableAST() 
	{
		this->var = NULL;
		this->var_tail_list =NULL;
	}
	VariableAST(AST * _var)
	{
		this->var = _var;
		this->var_tail_list = NULL;
	}
	VariableAST(AST * _var,AST * _var_tail_list)
	{
		this->var = _var;
		this->var_tail_list = _var_tail_list;
	}
	virtual~VariableAST() {}
	virtual ADT * eval() ;
	ADT * Assign(AST * );
};
class CompoundVariableAST:public AST{
	AST * id;
	AST * id_comma_list;
public:
	CompoundVariableAST() 
	{
		this->id = NULL;
		this->id_comma_list = NULL;
	}
	CompoundVariableAST(AST * _id) 
	{
		this->id = _id;
		this->id_comma_list = NULL;
	}	
	CompoundVariableAST(AST * _id,AST* _id_comma_list) 
	{
		this->id = _id;
		this->id_comma_list = _id_comma_list;
	}
	virtual ~CompoundVariableAST() 
	{
	}
	virtual ADT * eval();
	ADT * Assign(AST * );
};

class VarDeclAST:public AST{
	
public:
	char * id;
	AST * comma_list ;
	VarDeclAST() 
	{
		this->id = NULL;
		this->comma_list = NULL;
	}
	VarDeclAST(char * _id,AST* _comma_list=NULL) 
	{
		this->id =NULL;
		if(_id!=NULL){		
			int len = strlen(_id);
			this->id= new  char[len+1];
			this->id[0]=0;
			if(len!=0){
				for(int i=0;i<=len;i++)
				{
					this->id[i]=_id[i];
				}
			}
		}
		this->comma_list = _comma_list;
	}
	virtual~VarDeclAST() {}
	virtual ADT * eval() =0;
};


class SimpleVarDeclAST:public VarDeclAST{
public:
	char * id;
	SimpleVarDeclAST() 
	{
		this->id = NULL;
	}
	virtual ~SimpleVarDeclAST() 
	{
	}
	SimpleVarDeclAST(char * _id) 
	{
		this->id =NULL;
		if(_id!=NULL){		
			int len = strlen(_id);
			this->id= new  char[len+1];
			this->id[0]=0;
			if(len!=0){
				for(int i=0;i<=len;i++)
				{
					this->id[i]=_id[i];
				}
			}
		}
	}
	virtual ADT * eval();
};

class ArrayVarDeclAST:public VarDeclAST{
public:
	char * id;
	AST * comma_list ;
	ArrayVarDeclAST() 
	{
		this->id = NULL;
		this->comma_list = NULL;
	}
	virtual ~ArrayVarDeclAST() 
	{
	}
	ArrayVarDeclAST(char * _id,AST* _comma_list) 
	{
		this->id =NULL;
		if(_id!=NULL){		
			int len = strlen(_id);
			this->id= new  char[len+1];
			this->id[0]=0;
			if(len!=0){
				for(int i=0;i<=len;i++)
				{
					this->id[i]=_id[i];
				}
			}
		}
		this->comma_list = _comma_list;
	}
	virtual ADT * eval();
};


class ListAST:public AST{
public:
	AST * l;
	AST * r;
	ListAST() {this->l=NULL;this->r=NULL;}
	ListAST(AST *_l,AST*_r) {this->l=_l;this->r=_r;}
	void push_back(AST *_r) 
	{
		ListAST * _l = dynamic_cast<ListAST*>(this); 
		while(_l->r!=NULL){
			_l=dynamic_cast<ListAST*>(_l->r); 
		}
		_l->r=_r;
	}
	virtual ADT * eval() ;
	virtual~ListAST() {}
};

class StmtListAST:public ListAST {		
public:  
	StmtListAST():ListAST()
	{
	}
	StmtListAST(AST *_l,AST * _r):ListAST(_l, _r)
	{
	}
	ADT * eval();
};


class TopStmtListAST:public StmtListAST{
public:
	TopStmtListAST():StmtListAST() 
	{
	}
	TopStmtListAST(AST *_l,AST*_r):StmtListAST(_l,_r) 
	{
	}
	virtual ADT * eval() ;
	virtual~TopStmtListAST() {}
};
class InnerStmtListAST:public StmtListAST{
public:
	InnerStmtListAST():StmtListAST() 
	{
	}
	InnerStmtListAST(AST *_l,AST*_r):StmtListAST(_l,_r) 
	{
	}
	virtual ADT * eval() ;
	virtual~InnerStmtListAST() {}
};


class NullAST:public AST{
public:
	NullAST(){ }
	//NullAST(){this->}
	//IS_NULL,
};

class DoubleAST:public AST{
	double dval;
public:
	DoubleAST(){}
	DoubleAST( double _dval){this->dval = _dval; }
	operator double(){return this->dval;}
	operator float(){return (float)this->dval;}
	ADT * eval();	
};

class BoolAST:public AST{
	bool bval;
public:
	BoolAST(){}
	BoolAST(bool _bval){this->bval = _bval; }
	operator bool(){return this->bval;}
	ADT* eval();
};

class LongAST:public AST{
	long lval;
public:
	LongAST(){}
	LongAST(long _lval){this->lval = _lval;}
	operator long(){return this->lval;}
	operator int(){return (int)this->lval;}
	ADT* eval();
};

class ArrayAST:public AST{
	AST * pair_list;
public:
	ArrayAST()
	{
		this->pair_list = NULL;
	}
	ArrayAST(AST *_pair_list)
	{
		this->pair_list = _pair_list;
	}
	ADT * eval();
};

class ObjectAST:public AST{
	ObjectAST(){}
};

class StrAST:public AST{
	char*str;
public:
	StrAST(){ this->str = NULL;}
	StrAST(const char* _str)
	{  
		this->str =NULL;
		if(_str==NULL){
			return;
		}
		int len = strlen(_str);
		this->str= new  char[len+1];
		if(len==0){
			this->str[0]=0;
			return;
		}
		
		for(int i=0;i<=len;i++){
			this->str[i]=_str[i];
		}
	}
	~StrAST(){}
	ADT* eval();
};

class ResAST:public AST{
	ResAST(){}
};

class ConstAST:public AST{
	ConstAST(){}
};

class ConstArrayAST:public AST{
	ConstArrayAST(){}
};



//按值赋值的表达式
class AssignExpr:public AST {
	AST * r;
	AST *l;		/* value */
public:
	AssignExpr()
	{
		this->l = NULL; 
		this->r = NULL;
	}
	AssignExpr(AST *_l,AST *_r)
	{
		this->l = _l; 
		this->r = _r;
	}
	ADT* eval();
};
class Exit:public AST{			/* built-in function */
	AST*l;
public:
	Exit(){this->l= NULL;}
	Exit(AST * _l){this->l= _l;}
	ADT * eval();
};

class Print:public AST{			/* built-in function */
	AST*l;
public:
	Print(){this->l= NULL;}
	Print(AST * _l){this->l= _l;}
	ADT * eval();
};



//eval
class Eval:public AST{
	AST * str;
public:
	Eval()
	{
		this->str = NULL;
	}
	Eval(AST * _str)
	{
		this->str = _str;
	}
	~Eval(){}
	virtual ADT * eval();	
};






class ConcatExpr:public AST{		/* user function */
	AST * l;
	AST * r;
public:  
	ConcatExpr(){this->l= NULL;this->r = NULL;}
	ConcatExpr(AST *_l,AST * _r){this->l= _l;this->r = _r;}
	ADT * eval();
};

class ConstArray:public AST{
	AST* l;
public:  
	ConstArray(){this->l= NULL;}
	ConstArray(AST *_l){this->l= _l;}
	ADT * eval();	
};





class AddExpr:public AST {		/* user function */
	AST * l;
	AST * r;
public:  
	AddExpr()
	{
		this->l= NULL;
		this->r = NULL;
	}
	AddExpr(AST *_l,AST * _r)
	{
		this->l= _l;
		this->r = _r;
	}
	ADT * eval();
};

class SubExpr:public AST{
	AST *l;
	AST *r;
public:
	SubExpr()
	{
		this->l = NULL;
		this->r = NULL;
	}
	SubExpr(AST * _l,AST * _r)
	{
		this->l = _l;
		this->r = _r;
	}
	ADT * eval();
};

class MulExpr:public AST{
	AST *l;
	AST *r;
public:
	MulExpr()
	{
		this->l = NULL;
		this->r = NULL;
	}
	MulExpr(AST * _l,AST * _r)
	{
		this->l = _l;
		this->r = _r;
	}
	ADT * eval();
};
class DivExpr:public AST{
	AST *l;
	AST *r;
public:
	DivExpr()
	{
		this->l = NULL;
		this->r = NULL;
	}
	DivExpr(AST * _l,AST * _r)
	{
		this->l = _l;
		this->r = _r;
	}
	ADT * eval();
};
class ModExpr:public AST{
	AST *l;
	AST *r;
public:
	ModExpr()
	{
		this->l = NULL;
		this->r = NULL;
	}
	ModExpr(AST * _l,AST * _r)
	{
		this->l = _l;
		this->r = _r;
	}
	ADT * eval();
};
class NotExpr:public AST{
	AST *l;
public:
	NotExpr()
	{
		this->l = NULL;
	}
	NotExpr(AST * _l)
	{
		this->l = _l;
	}
	ADT * eval();
};







class EqualExpr:public AST{
	AST * l;
	AST * r;
public:
	EqualExpr(AST * _l,AST * _r)
	{
		this->l = _l;
		this->r = _r;
	}
	~EqualExpr()
	{
	}
	ADT * eval();
};
class NotEqualExpr:public AST{
	AST * l;
	AST * r;
public:
	NotEqualExpr(AST * _l,AST * _r)
	{
		this->l = _l;
		this->r = _r;
	}
	~NotEqualExpr()
	{
	}
	ADT * eval();
};

class SmallThanExpr:public AST{
	AST * l;
	AST * r;
public:
	SmallThanExpr(AST * _l,AST * _r)
	{
		this->l = _l;
		this->r = _r;
	}
	~SmallThanExpr()
	{
	}
	ADT * eval();
};
class SmallEqualExpr:public AST{
	AST * l;
	AST * r;
public:
	SmallEqualExpr(AST * _l,AST * _r)
	{
		this->l = _l;
		this->r = _r;
	}
	~SmallEqualExpr()
	{
	}
	ADT * eval();
};
class GreatThanExpr:public AST{
	AST * l;
	AST * r;
public:
	GreatThanExpr(AST * _l,AST * _r)
	{
		this->l = _l;
		this->r = _r;
	}
	~GreatThanExpr()
	{
	}
	ADT * eval();
};
class GreatEqualExpr:public AST{
	AST * l;
	AST * r;
public:
	GreatEqualExpr(AST * _l,AST * _r)
	{
		this->l = _l;
		this->r = _r;
	}
	~GreatEqualExpr()
	{
	}
	ADT * eval();
};
class CommaExpr:public AST{
	AST * l;
public:
	CommaExpr() 
	{
		this->l=NULL;
	}
	CommaExpr(AST *_l) 
	{
		this->l=_l;
	}
	virtual ADT * eval() ;
	virtual~ CommaExpr() {}
};















//-----------------expr-------------------------------
class Expr:public AST{	
public:
	Expr(){}
	virtual ADT * eval()=0;
	~Expr(){}	
};

//----------------------------------------
class Stmt:public AST{	
public:
	Stmt(){}
	virtual bool FindLabel(ADT * _label)
	{
		return false;
	}
	virtual ADT * Jmp(ADT * _label)
	{
		return NULL;
	}	
	virtual ADT * eval()=0;
	~Stmt(){}	
};

/*
//vb imported
class VarDeclStmt:public AST{	
	AST * var_list;
public:
	VarDeclStmt()
	{
		this->var_list = NULL;
	}
	VarDeclStmt(AST *_var_list)
	{
		this->var_list = _var_list;
	}
	~VarDeclStmt()
	{
	}
	ADT * eval()
	{
		return NULL;
	}
};*/

/*
 * 如果不限定函数必须先声明的话，这个ast其实是没太大意义的
 * 保留的主要目的是为了后来方便监控函数声明 
 */

class FunctionDeclStmt: public Stmt{
	AST * func_name;
	AST * formal_param_list;
	AST * statement;
public:
	FunctionDeclStmt(AST * _func_name,AST * _formal_param_list,AST * _statement)
	{
		this->func_name = func_name;
		this->formal_param_list = formal_param_list;
		this->statement = statement;
	}
	FunctionDeclStmt()
	{
		this->func_name = NULL;
		this->formal_param_list = NULL;
		this->statement = NULL;
	}
	~FunctionDeclStmt()
	{
	}
	ADT * eval()
	{
		
		ADT * result = NULL;
		IdAST * id = dynamic_cast<IdAST *>(this->func_name);
		if(id==NULL){
			cout<<"function decl error"<<endl;
			exit(-1);
		}		
		result = new FunctionADT(this->formal_param_list,this->statement);
		Symbol * s = CURRENT_SYMBOL_TABLE->Lookup(id->name);
		if(s==NULL){
			CURRENT_SYMBOL_TABLE->Register(id->name,result);
		}else{
			s->ReVal(result);	
		}		
		return result;
	}
};





class ExprStmt:public Stmt{	
	AST * expr;
public:
	ExprStmt()
	{
		this->expr = NULL;
	}
	ExprStmt(AST *_expr)
	{
		this->expr = _expr;
	}
	virtual ADT * eval()
	{
		ADT * result = NULL;
		if(this->expr!=NULL){
			result = this->expr->eval();
		}
		return result;
	}
	~ExprStmt(){}	
};

//对stmt_list的包装
class BlockStmt:public Stmt{
	AST * stmt_list;
	AST * FindLabelDetail(ADT * _label);
public:
	BlockStmt()
	{
		this->stmt_list=NULL;
	}
	BlockStmt(AST *_stmt_list)
	{
		this->stmt_list= _stmt_list;
	}
	virtual ADT * Jmp(ADT * _label);
	virtual bool FindLabel(ADT * _label);
	virtual ADT * eval();
	~BlockStmt(){}	
};
//inner stmt
class InnerBlockStmt:public BlockStmt{	
public:
	InnerBlockStmt():BlockStmt(){}
	InnerBlockStmt(AST *_stmt_list):BlockStmt(_stmt_list){}
	~InnerBlockStmt(){}	
	virtual bool FindLabel(ADT * _label);
};
//top stmt
class TopBlockStmt:public BlockStmt{	
public:
	TopBlockStmt():BlockStmt(){}
	TopBlockStmt(AST *_stmt_list):BlockStmt(_stmt_list){}
	~TopBlockStmt(){}	
	virtual bool FindLabel(ADT * _label);
};

//label stmt
class LabelStmt:public Stmt{
	AST * label;	
public:
	LabelStmt()
	{
		this->label=NULL;
	}
	LabelStmt(AST *_label)
	{
		this->label= _label;
	}
	virtual ADT * Jmp(ADT * _label);
	virtual bool FindLabel(ADT * _label);
	virtual ADT * eval();
	~LabelStmt(){}	
};
//flow stmt
class FlowStmt:public Stmt{
protected:
	AST * expr;
	AST * statement;
public:
	FlowStmt()
	{
		this->expr = NULL;
		this->statement = NULL;
	}
	FlowStmt(AST * _expr,AST * _statement)
	{
		this->expr = _expr;
		this->statement = _statement;
	}
	~FlowStmt()		
	{
	}
	virtual bool IsOK();
	virtual bool IsOK(ADT * cmp);
	virtual ADT * Jmp(ADT * _label);
	virtual bool FindLabel(ADT * _label);
	virtual ADT * eval();
};
//if flow
class IfFlow:public FlowStmt{
public:
	IfFlow():FlowStmt()
	{
	}
	IfFlow(AST * _expr,AST * _statement):FlowStmt(_expr,_statement)
	{
	}
	~IfFlow()		
	{
	}
};
//else flow
class ElseFlow:public FlowStmt{
public:
	ElseFlow():FlowStmt()
	{
	}
	ElseFlow(AST * _statement):FlowStmt(new BoolAST(true), _statement)
	{
	}
	~ElseFlow()		
	{
	}
};
//if 
class IfStmt:public Stmt{
	AST * flow_list;
	AST * FindLabelDetail(ADT * _label);
public:  
	IfStmt()
	{
		this->flow_list = NULL;
	}
	IfStmt(AST * _if_flow_list)
	{
		this->flow_list = _if_flow_list;
	}
	ADT * eval();
	ADT * Jmp(ADT * _label);
	virtual bool FindLabel(ADT * _label);
};

//while
class WhileStmt:public Stmt{
	AST *expr;
	AST *statement;
public:
	WhileStmt()
	{
		this->expr = NULL;
		this->statement = NULL;
	}
	WhileStmt(AST * _expr, AST * _statement)
	{
		this->expr = _expr;
		this->statement = _statement;
	}
	ADT * eval();
	ADT * Jmp(ADT * _label);
	virtual bool FindLabel(ADT * _label);
};

//do-while
class DoWhileStmt:public Stmt{
	AST *statement;
	AST *expr;
public:
	DoWhileStmt()
	{
		this->expr = NULL;
		this->statement = NULL;
	}
	DoWhileStmt(AST * _statement, AST * _expr)
	{
		this->expr = _expr;
		this->statement = _statement;
	}
	ADT * eval();
	ADT * Jmp(ADT * _label);
	virtual bool FindLabel(ADT * _label);
};


//for
class ForStmt:public Stmt{
	AST *init_expr;
	AST *cond_expr;
	AST *cont_expr;
	AST *statement;
public:
	ForStmt()
	{
		this->init_expr = NULL;
		this->cond_expr = NULL;
		this->cont_expr = NULL;
		this->statement = NULL;
	}
	ForStmt(AST * _init_expr,AST*_cond_expr,AST*_cont_expr,AST * _statement)
	{
		this->init_expr = _init_expr;
		this->cond_expr = _cond_expr;
		this->cont_expr = _cont_expr;
		this->statement = _statement;
	}
	ADT * eval();
	ADT * Jmp(ADT * _label);
	virtual bool FindLabel(ADT * _label);
};
//switch
class SwitchStmt:public Stmt{
	AST *expr;
	AST *case_list;
	AST * FindLabelDetail(ADT * _label);
public:
	SwitchStmt()
	{
		this->expr = NULL;
		this->case_list = NULL;
	}
	SwitchStmt(AST * _expr,AST*_cast_list)
	{
		this->expr = _expr;
		this->case_list = _cast_list;
	}
	ADT * eval();
	ADT * Jmp(ADT * _label);
	virtual bool FindLabel(ADT * _label);
};

class CaseFlow:public FlowStmt{
public:
	CaseFlow():FlowStmt()
	{
	}
	CaseFlow(AST * _expr,AST * _statement):FlowStmt(_expr, _statement)
	{
	}
	bool IsOK(ADT * cmp);
	~CaseFlow()		
	{
	}
};
class DefaultFlow:public FlowStmt{
public:
	DefaultFlow():FlowStmt()
	{
	}
	DefaultFlow(AST * _statement):FlowStmt(new BoolAST(true), _statement)
	{
	}
	bool IsOK(ADT *)
	{
		return true;
	}
	~DefaultFlow()		
	{
	}
};





//flowcontrol stmt
class FlowControlStmt:public Stmt{
public:
	FlowControlStmt(){}
	~FlowControlStmt(){}
};

class BreakStmt:public FlowControlStmt{
	AST * l;
public:
	BreakStmt()
	{
		this->l = NULL;
	}
	BreakStmt(AST * _l)
	{
		this->l = _l;
	}
	ADT * eval();
};

class ContinueStmt:public FlowControlStmt{
	AST * l;
public:
	ContinueStmt()
	{
		this->l = NULL;
	}
	ContinueStmt(AST * _l)
	{
		this->l = _l;
	}
	ADT * eval();
};

class ReturnStmt:public FlowControlStmt{
	AST * l;
public:
	ReturnStmt()
	{
		this->l = NULL;
	}
	ReturnStmt(AST * _l)
	{
		this->l = _l;
	}
	ADT * eval();
};

class GotoStmt:public FlowControlStmt{
	AST * label;
public:
	GotoStmt(AST * _label)
	{
		this->label = _label;
	}
	~GotoStmt()
	{
	}
	ADT * eval();
};


class DimStmt:public Stmt{		
	AST * var_list;
public:
	DimStmt() {}
	DimStmt(AST * _var_list){this->var_list = _var_list;}
	virtual~DimStmt() {}
	virtual ADT * eval();
};
//--------------------FUNC---------------------------

/*
class Function:public AST{
protected:
	AST * formal_param_list;
	AST * statement;
public:
	Function()
	{
		this->formal_param_list = NULL;
		this->statement = NULL;
	}
	Function(AST * _formal_param_list,AST * _statement)
	{
		this->formal_param_list = _formal_param_list;
		this->statement = _statement;
	}
	~Function(){}
	virtual ADT * eval();
	friend class CallFunction;
};

class CallFunction:public AST{
	AST * func_name;
	AST * actual_param_list;	
	bool PrepareEnv(SymbolTable * symtbl,AST * formal_param_list);
	ADT* CallMod(Symbol *s);
	ADT* CallUser(Symbol *s);
public:
	CallFunction()
	{
		this->func_name = NULL;
		this->actual_param_list = NULL;		
	}
	CallFunction(AST * _func_name,AST * _actual_param_list)
	{
		this->func_name = _func_name;
		this->actual_param_list = _actual_param_list;		
	}
	~CallFunction(){}
	virtual ADT * eval();	
};
*/

class CallExpr:public Expr{
	AST * function_name;
	AST * actual_param_list;	
	bool BuildEnv(AST * formal_param_list);
	ADT * DestroyEnv();
public:
	CallExpr()
	{
		this->function_name = NULL;
		this->actual_param_list = NULL;		
	}
	CallExpr(AST * _function_name,AST * _actual_param_list=NULL)
	{
		//cout<<"cunstructor1"<<endl;
		this->function_name = _function_name;
		this->actual_param_list = _actual_param_list;		
	}
	/*
	CallExpr(AST * _function_name)
	{
		cout<<"cunstructor2"<<endl;
		this->function_name = _function_name;
		this->actual_param_list = NULL;		
	}
	*/
	~CallExpr(){}
	virtual ADT * eval();	
};















