.SUFFIXES: .cpp .o

OBJECTS = Integer.o Float.o  Complex.o test.o  

CXX = g++

TARGET = test
$(TARGET) : $(OBJECTS)
	$(CXX) -o test $(OBJECTS)

clean :
	rm -rf $(OBJECTS)
