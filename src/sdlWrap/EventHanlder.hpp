//
// Created by dario on 09/09/17.
//

#ifndef TESTSDL_EVENTHANLDER_HPP
#define TESTSDL_EVENTHANLDER_HPP

#include "sdlWrap.hpp"
#include "Window.hpp"

namespace sdl
{
namespace window
{
class EventHandler
{
public:
	virtual void onClose(sdl::Window &source) {};
	virtual void onResize(sdl::Window &source, const SDL_Rect &newSize) {};
	virtual void onMove(sdl::Window &source, const SDL_Rect &newPos) {};
	virtual void onClick(sdl::Window &source, const SDL_MouseButtonEvent &where) {};
	virtual void onKey(sdl::Window &source, const SDL_KeyboardEvent &where) {};
	virtual void keys(sdl::Window &source, const Uint8 keys[]) {};
	virtual void onQuit(sdl::Window &source, const SDL_QuitEvent &quitEvent) {};

};

}
}

#endif //TESTSDL_EVENTHANLDER_HPP
