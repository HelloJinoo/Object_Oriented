
.SUFFIXES : .cpp .o     # .cpp와 .o파일을 다룰 것임을 표기

OBJECTS=human.o student.o shared_ref.o smart_obj.o weak_pointer.o test.o # compile할 object파일들 설정

# compile할 테스트코드의 object파일을 포함한 object 파일들 설정

CXX = g++ # CXX 설정

TARGET = test #실행파일 이름 설정

$(TARGET) : $(OBJECTS)
	$(CXX) -o test $(OBJECTS) 	


clean : 
	rm -rf $(TARGET) $(OBJECTS)

 # 컴파일하기 위해 필요한 파일들 설정
