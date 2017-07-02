all:
	g++ -o tic-tac-toe main.cpp text.cpp window.cpp grid.cpp rect.cpp -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_gfx
