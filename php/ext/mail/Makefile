CC=g++ -Wall
CFLAGS=
LIBS=
TARGET=../so/mail.so
stub: mail.cpp 
	$(CC) -o $(TARGET) mail.cpp ../../symbol.cpp ../../symboltable.cpp ../../symtabstack.cpp ../../adt.cpp ../../array.cpp $(LIBS) $(CFLAGS)  -fpic -shared

.PHONY: clean

clean:
	rm -f *.o $(TARGET)
