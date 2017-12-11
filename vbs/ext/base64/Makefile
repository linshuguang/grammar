CC=g++ -Wall
CFLAGS=
LIBS=
TARGET=../so/base64.so
stub: base64.cpp 
	$(CC) -o $(TARGET)  base64.cpp  ../../symbol.cpp ../../symboltable.cpp ../../symtabstack.cpp ../../adt.cpp ../../array.cpp $(LIBS) $(CFLAGS)  -fpic -shared

.PHONY: clean

clean:
	rm -f *.o $(TARGET)
