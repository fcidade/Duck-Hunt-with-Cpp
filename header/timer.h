#include <SDL2/SDL.h>

#ifndef TIMER_H
#define TIMER_H
class Timer{
public:
	Timer();
	void start();
	void stop();
	void pause();
	void unpause();
	Uint32 getTicks();
	bool isStarted();
	bool isPaused();
private:
	Uint32 _startTicks;
	Uint32 _pausedTicks;
	bool _paused;
	bool _started;
};
#endif