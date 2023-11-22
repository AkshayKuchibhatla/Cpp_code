mkdir -p ./build/
g++ -std=c++11 Deck.cpp Card.cpp Random.cpp CardIO.cpp Main.cpp -o ./build/CardBin
./build/CardBin