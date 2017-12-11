CC=g++ -Wall
CFLAGS=
LIBS=
TARGET=../so/function.so
stub: function.cpp 
	$(CC) -o $(TARGET)    function.cpp ../../symbol.cpp ../../symboltable.cpp ../../symtabstack.cpp ../../adt.cpp ../../array.cpp $(LIBS) $(CFLAGS)  -fpic -shared

.PHONY: clean

clean:
	rm -f *.o $(TARGET)
