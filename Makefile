all:
	g++ -std=c++11 -o tic-tac-toe main.cpp text.cpp window.cpp grid.cpp rect.cpp ai.cpp -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_gfx
