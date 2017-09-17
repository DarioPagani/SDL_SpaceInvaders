# Space Invaders in SDL 2
An implementation of Space Invaders in SDL, written in C/C++

## How to build

### Ubuntu and others GNU+Linux
#### Requirements
| Package           | Version    | APT Url                                                                  |
|:------------------|:----------:|-------------------------------------------------------------------------:|
| GIT (for cloning) |            | [INSTALL](http://dariopagani.github.io/aptUrl.html?pkg=git)              |
| build-essential   | gcc >= 5.4 | [INSTALL](http://dariopagani.github.io/aptUrl.html?pkg=build-essential)  |
| CMake             | >= 3.5     | [INSTALL](http://dariopagani.github.io/aptUrl.html?pkg=cmake)            |
| SDL2              | >= 2.0     | [INSTALL](http://dariopagani.github.io/aptUrl.html?pkg=libsdl2-dev)      |
| SDL2 TTF          | >= 2.0     | [INSTALL](http://dariopagani.github.io/aptUrl.html?pkg=libsdl2-ttf-dev)  |
| SDL2 IMAGE        | >= 2.0     | [INSTALL](http://dariopagani.github.io/aptUrl.html?pkg=libsdl2-image-dev)|

#### Cloning
Open a Terminal window, if you want move into a folder and run
```
git clone https://github.com/DarioPagani/SDL_SpaceInvaders.git
```
Now you should have a folder called `SDL_SpaceInvaders`, move into with `cd SDL_SpaceInvaders`, now you have all the source code and we can start compile.

#### Compiling 
Run
```
cmake . && make
```

### Windows NT
Coming soon...
### Mac OS X
I do not have any Apple Computers but I think it's almost like Ubuntu

## Future
I am making this simple and basic game only for fun and learn about SDL 2. The program could contains memory leaks, horrible code styling and not so fast procedures.

In the future, if I have time, I would like to add more features to this basic games.

- [x] Implement a basic C++ wrapper around the original C SDL 2 data structs and functions
- [x] Implement SDL_TTF and SDL_IMG extension
- [x] Implement a basic physic engine with collisions, movements and speed
- [x] Start writing a functional game
- [ ] Make enemies fire against the player
- [x] Add dynamic full-screen support based on actual monitor resolution (press F11)
- [ ] Add menus, pause and, in general, a basic GUI
- [ ] Add sound support
- [ ] Make the compiler transform all the resources in objects, link these object to the main executable and then have a single executable file with all the resources inside!

## Assets sources
I have taken all the resources used in this games from a previous game called [HardCade](https://play.google.com/store/apps/details?id=com.capslock.hardcade), developed by me and my classmates for a school project. In facts I am pointing to recreate the minigame "Space Invaders" written by me in JavaScript in C/C++.

A special thanks to [Mirko Sbrana]() for the graphical assets and Matteo Bernardini for the sounds effects

You can learn more about HardCade from [here](http://cheli.site/#/post/hardcade) and [here](http://capslockja.com/).

## License
See the [LICENSE](LICENSE) file
