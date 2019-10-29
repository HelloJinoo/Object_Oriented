.SUFFIXES: .cpp .h .o

OBJECTS= object.o smart_obj.o shared_mut.o main.o unique_immut.o
CPP = object.cpp smart_obj.cpp shared_mut.cpp main.cpp unique_immut.cpp

CXX = g++
CPPFALGES = -c

TARGET = test

$(TARGET) : $(CPP) 
	$(CXX) -c $(CPP)

clean :
	rm -rf $(OBJECTS)

object.o : object.cpp

smart_obj.o : smart_obj.cpp

shared_mut.o : shared_mut.cpp

main.o : main.cpp

unique_immut.o : unique_immut.cpp
