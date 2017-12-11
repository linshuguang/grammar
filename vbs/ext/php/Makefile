CC=g++ -Wall
CFLAGS=
LIBS=
TARGET=../so/php.so
stub: php.cpp 
	$(CC) -o $(TARGET) php.cpp ../../symbol.cpp ../../symboltable.cpp ../../symtabstack.cpp ../../adt.cpp ../../array.cpp $(LIBS) $(CFLAGS)  -fpic -shared

.PHONY: clean

clean:
	rm -f *.o $(TARGET)
