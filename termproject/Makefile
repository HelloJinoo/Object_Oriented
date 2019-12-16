.SUFFIXES: .cpp .o

OBJECTS = array_2d.o big_block.o cross_block.o fold_block.o tree_block.o

MAIN = main.o $(OBJECTS)

CXX = g++

DATA = data

TARGET = test

$(TARGET) : $(MAIN)
	$(CXX) -o $(TARGET) $(MAIN) 

clean :
	rm -rf $(MAIN) $(TARGET)
