class _TTF_Font;

#ifndef ENGINE_H
#define ENGINE_H
class Engine{
public:
	void LoadGame();
	void Logic();
	void DrawScreen();
	void Quit();
	_TTF_Font *font;
};
#endif