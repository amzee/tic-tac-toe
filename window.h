#pragma once

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>

class Window{

public:

	Window(const std::string &title, int width, int height);
	~Window();

	void pollEvents(SDL_Event &event);
	void clear() const;

	inline bool isClosed() const {return _closed;}

private:

	bool init();


// Declarations

private:

	std::string _title;
	int _width = 800, _height=600;
	bool _closed = false;
	SDL_Window *_window = nullptr;

public:
	static SDL_Renderer *renderer;
};
