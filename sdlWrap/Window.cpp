//
// Created by dario on 07/09/17.
//

#include <iostream>
#include "sdlWrap.hpp"

namespace sdl
{
// Global thinks
sdl::window::EventHandler dummy;
unsigned long long idGen = 0;

Window::Window(const char *const title, const int width, const int height, const int internalResWidth, const int internalResHeight):
handler(&dummy),
id(idGen++)
{
	SDL_SetError("Unkonow error!Gao");

	this->finestra = SDL_CreateWindow(title, -1,0, width, height, SDL_WINDOW_HIDDEN);

	if(!finestra)
		throw sdl::Exception(SDL_GetError(), __LINE__ - 2, __FILE__);

	this->contenuto = SDL_CreateRenderer(this->finestra, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(!contenuto)
		throw sdl::Exception(SDL_GetError(), __LINE__ - 2, __FILE__);

	SDL_RenderSetLogicalSize(this->contenuto, internalResWidth, internalResHeight);
	//SDL_SetRenderDrawColor(this->contenuto, 0, 0, 0, 255);

	clearFrame();
}

Window::Window(const char *const title, const int width, const int height):
Window(title, width, height, width, height)
{
	;
}

Window::~Window()
{
	SDL_DestroyRenderer(this->contenuto);
	SDL_DestroyWindow(this->finestra);
}

std::string message = "Texture does not belong to Window ";
Window &operator<<(Window &os, Texture &render)
{
	if(!(os.belongTo(render.getParent())))
		throw Exception(message);

	os.renderQue.remove(&render);
	os.renderQue.push_back(&render);

	return os;
}

Window &operator<<(Window &os, const std::list<Texture *> &tiles)
{
	for(auto i = tiles.begin(); i != tiles.end(); i++)
		os << **i;

	return os;
}

const u_int8_t maxValue = (-1);
void Window::paintFrame()
{
	for(auto i = renderQue.begin(); i != renderQue.end(); i++)
	{
		SDL_Rect tmpForC = ((*i)->getFrameBounds());
		SDL_Rect positionAn = (*i)->getPosition();

		SDL_RenderCopy(contenuto, (*i)->getTexture(), &tmpForC, &positionAn);
	}

	SDL_RenderPresent(contenuto);

	while(askForEvent())
		continue;

	renderQue.clear();
}

void Window::clearFrame()
{
	SDL_RenderClear(contenuto);
}

SDL_Renderer *Window::getRenderer() const
{
	return contenuto;
}

void Window::setVisible(const bool &visible)
{
	(visible ? SDL_ShowWindow : SDL_HideWindow)(finestra);

}

bool Window::isQuitted() const
{
	return quitted;
}

bool Window::askForEvent()
{
	SDL_Event e;

	handler->keys(*this, SDL_GetKeyboardState(nullptr));

	if(!SDL_PollEvent(&e))
		return false;

	switch (e.type)
	{
		case SDL_QUIT:
			handler->onQuit(*this, e.quit);
			break;
		case SDL_MOUSEBUTTONDOWN:
			handler->onClick(*this, e.button);
			break;
		case SDL_KEYDOWN :
			handler->onKey(*this, e.key);
			break;
		default:
			break;
	}

	return true;
}

SDL_Rect Window::getWindowDimensions() const
{
	SDL_Rect dimension = {0};

	SDL_GetWindowPosition(finestra, &dimension.x, &dimension.y);
	SDL_GetWindowSize(finestra, &dimension.w, &dimension.h);

	return dimension;
}

SDL_Rect Window::getRenderDimension() const
{
	SDL_Rect dimension = {0};
	SDL_RenderGetLogicalSize(contenuto, &dimension.w, &dimension.h);

	return dimension;
}

void Window::setHandler(window::EventHandler * const handler)
{
	Window::handler = handler;
}

unsigned long long Window::getID() const
{
	return id;
}

bool Window::belongTo(const Window &other)
{
	return this == &other;
}

void Window::dispose()
{
	quitted = true;
	setVisible(false);
}

void Window::setTile(const std::string &title)
{
	SDL_SetWindowTitle(finestra, title.c_str());
}

void Window::setIcon(SDL_Surface * const icon)
{
	if(icon)
		SDL_SetWindowIcon(finestra, icon);
}

void Window::setWindowFullscreen(const bool fullscreen)
{
	SDL_SetWindowFullscreen(finestra, fullscreen);
}

void Window::setWindowDimension(const int x, const int y)
{
	SDL_SetWindowSize(finestra, x,y);
}

void Window::setWindowPosition(const int w, const int h)
{
	SDL_SetWindowPosition(finestra,w,h);
}

void Window::setWindowDimensions(const SDL_Rect &pos)
{
	setWindowDimension(pos.w, pos.h);
	setWindowPosition(pos.x, pos.y);
}

bool Window::isFullscreen() const
{
	return SDL_GetWindowFlags(finestra) & SDL_WINDOW_FULLSCREEN;
}

}