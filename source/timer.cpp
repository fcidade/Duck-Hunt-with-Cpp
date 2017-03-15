#include "timer.h"

Timer::Timer() : _startTicks(0), _pausedTicks(0), _paused(false), _started(false){}

void Timer::start(){
	this->_started = true;
	this->_paused = false;
	this->_startTicks = SDL_GetTicks();
	this->_pausedTicks = 0;
}

void Timer::stop(){
	this->_started = false;
	this->_paused = false;
	this->_startTicks = 0;
	this->_pausedTicks = 0;
}

void Timer::pause(){
	if(_started && !_paused){
		_paused = true;
		_pausedTicks = SDL_GetTicks() - _startTicks;
		_startTicks = 0;
	}
}

void Timer::unpause(){
	if(_started && _paused){
		_paused = false;
		_startTicks = SDL_GetTicks() - _pausedTicks;
		_pausedTicks = 0;
	}
}

Uint32 Timer::getTicks(){
	Uint32 time = 0;
	if(_started){
		if(_paused){
			time = _pausedTicks;
		}else{
			time = SDL_GetTicks() - _startTicks;
		}
	}
	return time;
}

bool Timer::isStarted(){
	return _started;
}

bool Timer::isPaused(){
	return _started && _paused;
}