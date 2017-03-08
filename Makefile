all:
	g++ main.cpp source/*.cpp -Iheader -std=c++11 -lSDL2 -lSDL2_image -lSDL2_ttf -w -o o
