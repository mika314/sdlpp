# sdlpp
Header only C++ wrapper for SDL2.

## sdl::Init Class
Defined in header `<sdlpp.hpp>`
### Public Functions
#### (constructor)
```c++
sdl::Init::Init(Uint32 flags)
```
##### Function Parameters
* flags - subsystem initialization flags, see https://wiki.libsdl.org/SDL_Init

##### Exceptions
sdl::Error

## sdl::Window Class
Defined in header `<sdlpp.hpp>`

### Public Functions

#### (constructor)
```c++
sdl::Window::Window(const char *title, int x, int y, int w, int h, Uint32 flags)
```

##### Function Parameters
* title - the title of the window, in UTF-8 encoding
* x - the x position of the window, SDL_WINDOWPOS_CENTERED, or SDL_WINDOWPOS_UNDEFINED
* y - the y position of the window, SDL_WINDOWPOS_CENTERED, or SDL_WINDOWPOS_UNDEFINED
* w - the width of the window, in screen coordinates
* h - the height of the window, in screen coordinates
* flags - 0, or one or more SDL_WindowFlags OR'd togethe

See: https://wiki.libsdl.org/SDL_CreateWindow

##### Exceptions
sdl::Error

#### glCreateContext
```c++
SDL_GLContext glCreateContext()
```

##### Exceptions
sdl::Error

#### glGetDrawableSize
```c++
void glGetDrawableSize(int *w, int *h)
```

##### Function Parameters
* w - a pointer to variable for storing the width in pixels, may be nullptr
* h - a pointer to variable for storing the height in pixels, may be nullptr

##### Exceptions
sdl::Error

#### glMakeCurrent

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### glSwap

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getBrightness

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getData

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getDisplayIndex

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getDisplayMode

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getFlags

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getFromID

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getGammaRamp

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getGrab

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getID

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getMaximumSize

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getMinimumSize

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getPixelFormat

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getPosition

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getSize

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getSurface

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getTitle

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### hide

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### maximize

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### minimize

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### raise

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### restore

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setBordered

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setBrightness

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setData

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setDisplayMode

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setFullscreen

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setGammaRamp

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setGrab

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setHitTest
##### Function Parameters
* 
##### Exceptions
sdl::Error

#### setIcon

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setMaximumSize

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setMinimumSize

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setPosition

##### Function Parameters
* 
##### Exceptions
sdl::Error

#### setSize

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setTitle

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### show

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### updateSurface

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### updateSurfaceRects

##### Function Parameters
* 

##### Exceptions
sdl::Error

## sdl::Renderer Class
Defined in header `<sdlpp.hpp>`

### Public Functions

## sdl::Texture Class
Defined in header `<sdlpp.hpp>`

### Public Functions

## sdl::Audio Class
Defined in header `<sdlpp.hpp>`

### Public Functions

## sdl::Error Class
Defined in header `<sdlpp.hpp>`

### Public Functions

## sdl::EventHandler Class
Defined in header `<sdlpp.hpp>`

### Public Functions

