//
// Created by dario on 07/09/17.
//


#ifndef TESTSDL_WINDOW_HPP
#define TESTSDL_WINDOW_HPP

#include <SDL2/SDL.h>
#include <list>
#include <ostream>

#include "sdlWrap.hpp"
#include "EventHanlder.hpp"

namespace sdl
{

class Texture;
class Window;


class Window
{
public:
	Window(const char * const title, const int width, const int height, const int internalResWidth, const int internalResHeight);
	Window(const char * const title, const int width, const int height);
	Window() = delete;
	~Window();
	Window(const Window& sorgente) = delete;

	friend Window &operator<<	(Window &os, Texture &render);
	friend Window &operator<<	(Window &os, const std::list<Texture*> &tiles);

	void						paintFrame();
	void						clearFrame();
	void 						dispose();

	SDL_Renderer				*getRenderer() const;
	SDL_Rect					getWindowDimensions() const;
	SDL_Rect					getRenderDimension() const;
	unsigned long long			getID() const;
	bool						isQuitted() const;
	bool 						isFullscreen() const;

	void						setVisible(const bool &visible);
	void 						setHandler(window::EventHandler * const handler);
	void						setTile(const std::string &title);
	void 						setIcon(SDL_Surface * const icon);
	void						setWindowDimension(const int x, const int y);
	void						setWindowPosition(const int w, const int h);
	void 						setWindowDimensions(const SDL_Rect &pos);
	void 						setWindowFullscreen(const bool fullscreen);

protected:
	bool 	askForEvent();
	bool	belongTo(const Window &other);
	window::EventHandler		*handler;

private:
	SDL_Window					*finestra	= 0;
	SDL_Renderer				*contenuto	= 0;
	std::list<sdl::Texture*>	renderQue	= std::list<sdl::Texture*>();
	bool						quitted		= false;
	const unsigned long long	id;
};

}


#endif //TESTSDL_WINDOW_HPP
