CC=g++
CV_PATH=/usr/local/lib
JAVA_INCLUDE=/usr/lib/jvm/java-1.6.0-openjdk-amd64/include
SEARCH_LIB=$(CV_PATH)/libopencv_core.so $(CV_PATH)/libopencv_highgui.so $(CV_PATH)/libopencv_imgproc.so $(CV_PATH)/libopencv_objdetect.so 
INCLUDE=-I/usr/local/include -I$(JAVA_INCLUDE) -I$(JAVA_INCLUDE)/linux
LIBRARY=-L/usr/local/lib
OUT=libcpu_face_detect.so
SRC=call_cpu.cpp


FLAGS= -m64 -shared -fPIC
all:
	$(CC) $(FLAGS) $(SRC) $(SEARCH_LIB) -o $(OUT) $(INCLUDE) 
clean:
	rm *.so
