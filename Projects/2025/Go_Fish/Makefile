src/main: build/main.o build/Card.o build/GoFish.o
	g++ -o build/main -lncurses build/main.o build/Card.o build/GoFish.o
	./build/main

build/main.o build/Card.o build/GoFish.o: src/main.cpp src/Card.cpp src/GoFish.cpp
	mkdir -p build
	g++ -c src/main.cpp -o build/main.o
	g++ -c src/Card.cpp -o build/Card.o
	g++ -c src/GoFish.cpp -o build/GoFish.o

src/main.cpp:
	echo "int main() { return 0; }" > src/main.cpp

src/Card.cpp:
	echo "int main() { return 0; }" > src/Card.cpp

src/GoFish.cpp:
	echo "int main() { return 0; }" > src/GoFish.cpp

clean:
	rm -rf build