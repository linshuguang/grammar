CC=g++ -Wall
CFLAGS=
LIBS=
TARGET=../so/core.so
stub: core.cpp 
	$(CC) -o $(TARGET) core.cpp ../../symbol.cpp ../../symboltable.cpp ../../symtabstack.cpp ../../adt.cpp ../../array.cpp $(LIBS) $(CFLAGS)  -fpic -shared

.PHONY: clean

clean:
	rm -f *.o $(TARGET)
