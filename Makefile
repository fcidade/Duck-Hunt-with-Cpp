CC = g++
CPP = -std=c++11
SOURCE = main.cpp source/*.cpp
INCLUDE = -Iheader -lSDL2 -lSDL2_image -lSDL2_ttf
WARNING = -w
OUTPUT = -o o

all:
	$(CC) $(SOURCE) $(INCLUDE) $(CPP) $(WARNING) $(OUTPUT)
