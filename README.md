# sdlpp
Header only C++ wrapper for SDL2.

[![C++ Wrapper for SDL2](https://img.youtube.com/vi/fD-bCQ20NRo/0.jpg)](https://www.youtube.com/watch?v=fD-bCQ20NRo)

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
SDL_GLContext sdl::Window::glCreateContext()
```

##### Exceptions
sdl::Error

#### glGetDrawableSize
```c++
void sdl::Window::glGetDrawableSize(int *w, int *h)
```

##### Function Parameters
* w - a pointer to variable for storing the width in pixels, may be nullptr
* h - a pointer to variable for storing the height in pixels, may be nullptr

##### Exceptions
sdl::Error

#### glMakeCurrent
```c++
int sdl::Window::glMakeCurrent(SDL_GLContext context)
```

##### Function Parameters
* context - 

##### Exceptions
sdl::Error

#### glSwap
```c++
void sdl::Window::glSwap()
```

#### getBrightness
```c++
float sdl::Window::getBrightness()
```

#### getData
```c++
void *sdl::Window::getData(const char *name, void *userdata)
```

##### Function Parameters
* name -
* userdata -

##### Exceptions
sdl::Error

#### getDisplayIndex
```c++
int sdl::Window::getDisplayIndex()
```

##### Exceptions
sdl::Error

#### getDisplayMode
```c++
int sdl::Window::getDisplayMode(SDL_DisplayMode *mode)
```

##### Function Parameters
* mode -

##### Exceptions
sdl::Error

#### getFlags
```c++
Uint32 sdl::Window::getFlags()
```

##### Exceptions
sdl::Error

#### getGammaRamp
```c++
int sdl::Window::getGammaRamp(Uint16 *red, Uint16 *green, Uint16 *blue)
```

##### Function Parameters
* red - A pointer to a 256 element array of 16-bit quantities to hold the translation table for the red channel, or nullptr.
* green - A pointer to a 256 element array of 16-bit quantities to hold the translation table for the green channel, or nullptr.
* blue - A pointer to a 256 element array of 16-bit quantities to hold the translation table for the blue channel, or nullptr.

##### Exceptions
sdl::Error

#### getGrab
```c++
sdl::Window::getGrab()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getID
```c++
sdl::Window::getID()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getMaximumSize
```c++
sdl::Window::getMaximumSize()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getMinimumSize
```c++
sdl::Window::getMinimumSize()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getPixelFormat
```c++
sdl::Window::getPixelFormat()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getPosition
```c++
sdl::Window::getPosition()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getSize
```c++
sdl::Window::getSize()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getSurface
```c++
sdl::Window::getSurface()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### getTitle
```c++
sdl::Window::getTitle()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### hide
```c++
sdl::Window::hide()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### maximize
```c++
sdl::Window::maximize()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### minimize
```c++
sdl::Window::minimize()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### raise
```c++
sdl::Window::raise()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### restore
```c++
sdl::Window::restore()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setBordered
```c++
sdl::Window::setBordered()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setBrightness
```c++
sdl::Window::setBrightness()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setData
```c++
sdl::Window::setData()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setDisplayMode
```c++
sdl::Window::setDisplayMode()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setFullscreen
```c++
sdl::Window::setFullscreen()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setGammaRamp
```c++
sdl::Window::setGammaRamp()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setGrab
```c++
sdl::Window::setGrab()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setHitTest
```c++
sdl::Window::setHitTest()
```
##### Function Parameters
* 
##### Exceptions
sdl::Error

#### setIcon
```c++
sdl::Window::setIcon()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setMaximumSize
```c++
sdl::Window::setMaximumSize()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setMinimumSize
```c++
sdl::Window::setMinimumSize()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setPosition
```c++
sdl::Window::setPosition()
```

##### Function Parameters
* 
##### Exceptions
sdl::Error

#### setSize
```c++
sdl::Window::setSize()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### setTitle
```c++
sdl::Window::setTitle()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### show
```c++
sdl::Window::show()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### updateSurface
```c++
sdl::Window::updateSurface()
```

##### Function Parameters
* 

##### Exceptions
sdl::Error

#### updateSurfaceRects
```c++
sdl::Window::updateSurfaceRects()
```

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

