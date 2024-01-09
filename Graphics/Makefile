all: test2.cpp
	mkdir -p ./build/
	g++ -I/opt/homebrew/opt/sdl2/include game.cpp rectangle.cpp main.cpp -L/opt/homebrew/opt/sdl2/lib -lSDL2 -o ./build/sdlBin
	./build/sdlBin

clean: 
	$(RM) ./build/sdlBin