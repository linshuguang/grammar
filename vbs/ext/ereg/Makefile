CC=g++ -Wall
CFLAGS=
LIBS=
TARGET=../so/ereg.so
stub: ereg.cpp 
	$(CC) -o $(TARGET) ereg.cpp ../../symbol.cpp ../../symboltable.cpp ../../symtabstack.cpp ../../adt.cpp ../../array.cpp $(LIBS) $(CFLAGS)  -fpic -shared

.PHONY: clean

clean:
	rm -f *.o $(TARGET)
