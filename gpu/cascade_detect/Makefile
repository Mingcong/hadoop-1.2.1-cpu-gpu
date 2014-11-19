CC=g++
JAVA_INCLUDE=/home/ideal/tools/jdk1.7.0_71/include
INCLUDE=-I/usr/local/include -I$(JAVA_INCLUDE) -I$(JAVA_INCLUDE)/linux
LIBRARY=-L/home/ideal/tools/cuda-5.5/lib64
OUT=libgpu_app.so
SRC=call_gpu.cpp


FLAGS= -m64 -shared -fPIC
all:
	$(CC) $(FLAGS) $(SRC) `pkg-config --cflags --libs opencv` -o $(OUT) $(INCLUDE) $(LIBRARY) 
clean:
	rm *.so
