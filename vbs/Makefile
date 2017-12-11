LEX=flex
YACC=bison
CC=g++  -Wall  
a.exe : lex.yy.o frame.tab.o  ast.o adt.o symbol.o symtabstack.o symboltable.o main.o array.o conf.o mod.o dl.o
	$(CC) lex.yy.o frame.tab.o ast.o adt.o symbol.o symtabstack.o symboltable.o  main.o   array.o conf.o mod.o dl.o -o a.exe  

lex.yy.o : lex.yy.c frame.tab.h 
	$(CC) -c lex.yy.c
	
frame.tab.o : frame.tab.c 
	$(CC) -c frame.tab.c 

ast.o : ast.hpp ast.cpp sym.hpp symbol.cpp
	$(CC) -c ast.cpp symbol.cpp

adt.o : adt.hpp adt.cpp
	$(CC) -c adt.cpp	
	
symbol.o : sym.hpp symbol.cpp
	$(CC) -c symbol.cpp 

symtabstack.o : sym.hpp symtabstack.cpp
	$(CC) -c symtabstack.cpp

symboltable.o : sym.hpp symboltable.cpp 
	$(CC) -c symboltable.cpp 
	

main.o	: main.hpp main.cpp 
	$(CC) -c main.cpp 

array.o	: array.hpp array.cpp 
	$(CC) -c array.cpp 
	
conf.o	: conf.hpp conf.cpp 
	$(CC) -c conf.cpp 
	
mod.o	: mod.hpp mod.cpp dl/dlfcn.hpp
	$(CC) -c mod.cpp
	
dl.o: dl/dlfcn.hpp dl/dlfcn.cpp
	$(CC) -c dl/dlfcn.cpp -o dl.o
	
frame.tab.c frame.tab.h: frame.y
	$(YACC) -d frame.y
	
lex.yy.c:frame.l
	$(LEX) frame.l

clean:
	rm -rf *.o *.c *.h *.exe