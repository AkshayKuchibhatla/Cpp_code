src/main: build/main.o build/Card.o build/GoFish.o build/GFPlayer.o
	g++ -o build/main -lncurses build/main.o build/Card.o build/GoFish.o build/GFPlayer.o
	./build/main

build/main.o build/Card.o build/GoFish.o build/GFPlayer.o: src/main.cpp src/Card.cpp src/GoFish.cpp src/GFPlayer.cpp
	mkdir -p build
	g++ -c src/main.cpp -o build/main.o
	g++ -c src/Card.cpp -o build/Card.o
	g++ -c src/GoFish.cpp -o build/GoFish.o
	g++ -c src/GFPlayer.cpp -o build/GFPlayer.o

src/main.cpp:
	echo "int main() { return 0; }" > src/main.cpp

src/Card.cpp:
	echo "int main() { return 0; }" > src/Card.cpp

src/GoFish.cpp:
	echo "int main() { return 0; }" > src/GoFish.cpp

src/GFPlayer.cpp:
	echo "int main() { return 0; }" > src/GFPlayer.cpp

test: src/Card.cpp src/GoFish.cpp src/GFPlayer.cpp src/tests.cpp
	g++ src/tests.cpp src/GFPlayer.cpp src/GoFish.cpp src/Card.cpp -lncurses -o build/tests
	./build/tests

clean:
	rm -rf build