.SUFFIXES: .cpp .h .o

OBJECTS= vehicle.o car.o bike.o main.o
CPP = vehicle.cpp car.cpp bike.cpp main.cpp
CXX = g++
	
TARGET = test

$(TARGET) : $(OBJECTS) 
	$(CXX) -o $(TARGET) $(OBJECTS)
	
clean :
	rm -rf $(OBJECTS) $(TARGET)

main.o : main.cpp
vehicle.o : vehicle.cpp
car.o : car.cpp
bike.o : bike.cpp

