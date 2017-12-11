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

class VariableAST:public AST{
public:
	VariableAST() {}
	virtual~VariableAST() {}
	virtual ADT * eval() =0;
	virtual void Assign(ADT*) =0; 
	virtual ADT* IsSet() =0; 
};
class GlobalVariableAST:public VariableAST{
	char * var_name;//symbol name
	Symbol* FindSymbol();
public:
	GlobalVariableAST() 
	{
		this->var_name = NULL;
	}
	GlobalVariableAST(char * _var_name ) 
	{
		this->var_name = NULL;
		if(_var_name!=0){
			int len = strlen(_var_name);
			this->var_name = new char[len+1];
			for(int i=0;i<=len;i++)
			{
				this->var_name[i]=_var_name[i];
			}
		}
	}
	virtual ADT * eval(); 
	virtual~GlobalVariableAST() 
	{
	}
	void Assign(ADT*);
	ADT* IsSet() ;
};

class SimpleVariableAST:public VariableAST{
	char * var_name;//symbol name
	Symbol* FindSymbol();
public:
	SimpleVariableAST() 
	{
		this->var_name = NULL;
	}
	SimpleVariableAST(char * _var_name ) 
	{
		this->var_name = NULL;
		if(_var_name!=0){
			int len = strlen(_var_name);
			this->var_name = new char[len+1];
			for(int i=0;i<=len;i++)
			{
				this->var_name[i]=_var_name[i];
			}
		}
	}
	virtual ADT * eval(); 
	virtual~SimpleVariableAST() 
	{
	}
	void Assign(ADT*);
	ADT* IsSet() ;
};
class TempVariableAST:public VariableAST{
	AST * l;
public:
	TempVariableAST() 
	{
		this->l = NULL;
	}
	TempVariableAST(AST * _l) 
	{
		this->l = _l;
	}
	virtual ADT * eval(); 
	virtual~TempVariableAST() 
	{
	}
	void Assign(ADT*);
	ADT* IsSet() ;
};

class ComplicateVariableAST:public VariableAST{
public:
	ComplicateVariableAST() {}
	virtual~ComplicateVariableAST() {}
	virtual ADT * eval()=0 ;
	virtual void Assign(ADT*)=0;
	virtual ADT* IsSet() =0;	
};

class FetchArrayDimVariableAST:public ComplicateVariableAST{
	AST * l;//array
	AST * r;//dim	
public:
	FetchArrayDimVariableAST() {this->l=NULL;this->r=NULL;}
	FetchArrayDimVariableAST(AST *_l,AST *_r) {this->l=_l;this->r=_r;}
	virtual ADT * eval();
	virtual~FetchArrayDimVariableAST() {}
	void Assign(ADT*);
	ADT*IsSet();
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
	StrAST(const char* _str){  int len = strlen(_str);this->str= new  char[len+1];for(int i=0;i<=len;i++)this->str[i]=_str[i];}
	~StrAST(){ if(this->str != NULL)delete this->str;}
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

class Eval:public AST{			/* built-in function */
	AST*l;
public:
	Eval():AST(){this->l= NULL;}
	Eval(AST * _l):AST(){this->l= _l;}
	ADT * eval();
};



class UserFunCall:public AST {		/* user function */
	AST *l;		/* list of arguments */
	Symbol *s;
public:  
	UserFunCall():AST(){this->l= NULL;this->s = NULL;}
	UserFunCall(Symbol *_s,AST * _l):AST(){this->l= _l;this->s = _s;}
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


class DoubleArrowExpr:public AST{
	AST * key;
	AST * val;
public:  
	DoubleArrowExpr(){this->key= NULL;this->val = NULL;}
	DoubleArrowExpr(AST *_key,AST * _val){this->key= _key;this->val = _val;}
	ADT * eval();
};
/*
class FetchArrayDimRef:public SymRef {
	AST * var;
	AST * dim;
public:
	FetchArrayDimRef(){this->var= NULL;this->dim = NULL;}
	FetchArrayDimRef(AST *_var,AST * _dim){this->var= _var;this->dim = _dim;}
	virtual void Assign( ADT * val );
	ADT * eval();
};
*/


class PreIncExpr:public AST{
	AST * var;
public:  
	PreIncExpr()
	{
		this->var = NULL;
	}
	PreIncExpr(AST * _var)
	{
		this->var = _var;
	}
	ADT * eval();
};

class PostIncExpr:public AST{
	AST * var;
public:  
	PostIncExpr()
	{
		this->var = NULL;
	}
	PostIncExpr(AST * _var)
	{
		this->var = _var;
	}
	ADT * eval();
};

class PreDecExpr:public AST{
	AST * var;
public:  
	PreDecExpr()
	{
		this->var = NULL;
	}
	PreDecExpr(AST * _var)
	{
		this->var = _var;
	}
	ADT * eval();
};

class PostDecExpr:public AST{
	AST * var;
public:  
	PostDecExpr()
	{
		this->var = NULL;
	}
	PostDecExpr(AST * _var)
	{
		this->var = _var;
	}
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

class QmExpr:public AST{
	AST * expr;
	AST * first;
	AST * second;
public:
	QmExpr() 
	{
		this->expr =NULL;
		this->first =NULL;
		this->second =NULL;
	}
	QmExpr(AST *_expr,AST* _first,AST *_second) 
	{
		this->expr =_expr;
		this->first =_first;
		this->second =_second;
	}
	virtual ADT * eval() ;
	virtual~ QmExpr() {}
};
class IsSetExpr:public AST{
	AST * var_list;
public:
	IsSetExpr() 
	{
		this->var_list =NULL;
	}
	IsSetExpr(AST *_var_list) 
	{
		this->var_list =_var_list;
	}
	virtual ADT * eval() ;
	virtual~ IsSetExpr() {}
};
class EmptyExpr:public AST{
	AST * var;
public:
	EmptyExpr() 
	{
		this->var =NULL;
	}
	EmptyExpr(AST *_var) 
	{
		this->var =_var;
	}
	virtual ADT * eval() ;
	virtual~ EmptyExpr() {}
};


/*-------------------------------------stmt------------------------------------------*/
/*
class LabelAST:public StmtAST AST{
	AST * label;
public:
	LabelAST()
	{
		this->label = NULL;
	}
	LabelAST(AST * _stmt_list)
	{
		this->label = _label;
	}
	ADT * eval();
	~LabelAST(){}	
};

class StmtListAST:public AST{
	AST * ;
	AST * next;
public:
	StmtAST()
	{
	}
	StmtAST(AST * _stmt_list)
	{		
	}
	bool IsLabel(ADT*lb);
	ADT * eval();
	~StmtAST(){}	
};class StmtAST:public AST{
public:
	StmtAST()
	{
	}
	bool Goto(ADT*label);
	virtual ADT * eval();
	~StmtAST(){}	
};
*/














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
class FunctionDeclarationStmt: public Stmt{
	AST * func;
public:
	FunctionDeclarationStmt()
	{
		this->func = NULL;
	}
	FunctionDeclarationStmt(AST *_func)
	{
		this->func = _func;
	}
	~FunctionDeclarationStmt()
	{
	}
	ADT * eval()
	{
		return NULL;
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
class UnTickedStmt:public Stmt{
	AST * stmt_list;
	AST * FindLabelDetail(ADT * _label);
public:
	UnTickedStmt()
	{
		this->stmt_list=NULL;
	}
	UnTickedStmt(AST *_stmt_list)
	{
		this->stmt_list= _stmt_list;
	}
	virtual ADT * Jmp(ADT * _label);
	virtual bool FindLabel(ADT * _label);
	virtual ADT * eval();
	~UnTickedStmt(){}	
};
//inner stmt
class InnerStmt:public UnTickedStmt{	
public:
	InnerStmt():UnTickedStmt(){}
	InnerStmt(AST *_stmt_list):UnTickedStmt(_stmt_list){}
	~InnerStmt(){}	
	virtual bool FindLabel(ADT * _label);
};
//top stmt
class TopStmt:public UnTickedStmt{	
public:
	TopStmt():UnTickedStmt(){}
	TopStmt(AST *_stmt_list):UnTickedStmt(_stmt_list){}
	~TopStmt(){}	
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
//foreach
class ForeachStmt :public Stmt{
	AST * variable ;
	AST * foreach_variable ;
	AST * foreach_optional_arg ;
	AST * statement ;
public:
	ForeachStmt()
	{
		this->variable =NULL ;
		this->foreach_variable =NULL;
		this->foreach_optional_arg =NULL; 
		this->statement =NULL;
	}
	ForeachStmt(AST * _variable ,AST * _foreach_variable ,AST * _foreach_optional_arg,AST * _statement )
	{
		this->variable = _variable ;
		this->foreach_variable = _foreach_variable;
		this->foreach_optional_arg = _foreach_optional_arg; 
		this->statement = _statement;
	}
	~ForeachStmt(){}
	ADT * eval();
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
//global
class GlobalStmt:public Stmt{
	AST *global_var_list;
public:
	GlobalStmt()
	{
		this->global_var_list = NULL;
	}
	GlobalStmt(AST * _global_var_list)
	{
		this->global_var_list = _global_var_list;
	}
	ADT * eval()
	{
		return NULL;
	}
};

//--------------------FUNC---------------------------
class Function:public AST{
protected:
	SymbolTable * symtbl;
	AST * formal_param_list;
	AST * statement;
public:
	Function()
	{
		this->symtbl = new SymbolTable;
		this->formal_param_list = NULL;
		this->statement = NULL;
	}
	Function(SymbolTable * _symtbl,AST * _formal_param_list,AST * _statement)
	{
		if(_symtbl!=NULL){
			this->symtbl = _symtbl;
		}else{
			this->symtbl = new SymbolTable;
		}
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












