mkdir -p ./build/
g++ -I/opt/homebrew/opt/sdl2/include test_sdl.cpp -L/opt/homebrew/opt/sdl2/lib -lSDL2 -o ./build/sdlBin
./build/sdlBin