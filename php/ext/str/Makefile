CC=g++ -Wall
CFLAGS=
LIBS=
TARGET=../so/str.so
stub: str.cpp 
	$(CC) -o $(TARGET) str.cpp  ../../symbol.cpp ../../symboltable.cpp ../../symtabstack.cpp ../../adt.cpp ../../array.cpp $(LIBS) $(CFLAGS)  -fpic -shared

.PHONY: clean

clean:
	rm -f *.o $(TARGET)
