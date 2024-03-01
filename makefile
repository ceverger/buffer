all:
	g++ -shared add.cpp buffer.cpp setsize.cpp setbuffer.cpp -o libbuffer.so -I .
