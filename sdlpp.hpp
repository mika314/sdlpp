/*
This source file is part of sdlpp (C++ wrapper for SDL2)

Copyright (c) 2017 Anton Te

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

// enable this if you want to use the higher-level SDL2_gfx features
//#define USE_SDLGFX

#include <SDL.h>
#ifdef USE_SDLGFX
#include <SDL2_gfxPrimitives.h>
#endif
#include <functional>
#include <sstream>

namespace sdl
{
  class Error : public std::runtime_error
  {
  public:
    using std::runtime_error::runtime_error;
  };
  class Init
  {
  public:
    template <typename... Args>
    Init(Args... args)
    {
      auto res = SDL_Init(args...);
      if (res < 0)
      {
        std::ostringstream strm;
        strm << "Init::Init(): " << SDL_GetError();
        throw Error(strm.str());
      }
    }
    Init(const Init &) = delete;
    Init &operator=(const Init &) = delete;
    ~Init() { SDL_Quit(); }
  };
#define SDL_CLASS(X)                                 \
  class X                                            \
  {                                                  \
  public:                                            \
    template <typename... Args>                      \
    X(Args... args)                                  \
    {                                                \
      handle = SDL_Create##X(args...);               \
      if (!handle)                                   \
      {                                              \
        std::ostringstream strm;                     \
        strm << #X "::" #X "(): " << SDL_GetError(); \
        throw Error(strm.str());                     \
      }                                              \
    }                                                \
    X(SDL_##X *handle_) : handle(handle_) {}         \
    X(const X &) = delete;                           \
    X &operator=(const X &) = delete;                \
    X &operator=(X &&x)                              \
    {                                                \
      handle = x.handle;                             \
      x.handle = nullptr;                            \
      return *this;                                  \
    }                                                \
    X(X &&x) : handle(x.handle) { x.handle = nullptr; }    \
    ~X()                                             \
    {                                                \
      if (handle)                                    \
        SDL_Destroy##X(handle);                      \
    }                                                \
    SDL_##X *get() { return handle; }                \
    const SDL_##X *get() const { return handle; }    \
  private:                                           \
    SDL_##X *handle;                                 \
                                                     \
  public:                                            \
    SDL_CLASS_METHOD_LIST                            \
  }

  template <typename R, typename... Args2, typename... Args>
  auto callSdl(R(f)(Args2...), Args... args) -> decltype(f(args...))
  {
    return f(args...);
  }

  template <typename R, typename... Args2, typename... Args>
  auto callSdl(R *(f)(Args2...), Args... args) -> decltype(f(args...))
  {
    auto r = f(args...);
    if (r == nullptr)
    {
      throw Error(std::string("Error string: ") + SDL_GetError());
    }
    return r;
  }

  template <typename... Args2, typename... Args>
  auto callSdl(int(f)(Args2...), Args... args) -> decltype(f(args...))
  {
    auto r = f(args...);
    if (r == -1)
    {
      throw Error("Error code: " + std::to_string(r) + " Error string: " + SDL_GetError());
    }
    return r;
  }

  template <typename... Args2, typename... Args>
  auto callSdl(void(f)(Args2...), Args... args) -> decltype(f(args...))
  {
    f(args...);
  }

#define METHOD2(X, Y)                                      \
  template <typename... Args>                              \
  auto X(Args... args)->decltype(Y(handle, args...))       \
  {                                                        \
    return callSdl(Y, handle, args...);                    \
  }
#define METHOD(X, Y) METHOD2(X, SDL_##Y)

#define SDL_CLASS_METHOD_LIST_TMP                \
  METHOD(glCreateContext, GL_CreateContext)      \
  METHOD(glGetDrawableSize, GL_GetDrawableSize)  \
  METHOD(glMakeCurrent, GL_MakeCurrent)          \
  METHOD(glSwap, GL_SwapWindow)                  \
  METHOD(getBrightness, GetWindowBrightness)     \
  METHOD(getData, GetWindowData)                 \
  METHOD(getDisplayIndex, GetWindowDisplayIndex) \
  METHOD(getDisplayMode, GetWindowDisplayMode)   \
  METHOD(getFlags, GetWindowFlags)               \
  METHOD(getGammaRamp, GetWindowGammaRamp)       \
  METHOD(getGrab, GetWindowGrab)                 \
  METHOD(getID, GetWindowID)                     \
  METHOD(getMaximumSize, GetWindowMaximumSize)   \
  METHOD(getMinimumSize, GetWindowMinimumSize)   \
  METHOD(getPixelFormat, GetWindowPixelFormat)   \
  METHOD(getPosition, GetWindowPosition)         \
  METHOD(getSize, GetWindowSize)                 \
  METHOD(getSurface, GetWindowSurface)           \
  METHOD(getTitle, GetWindowTitle)               \
  METHOD(hide, HideWindow)                       \
  METHOD(maximize, MaximizeWindow)               \
  METHOD(minimize, MinimizeWindow)               \
  METHOD(raise, RaiseWindow)                     \
  METHOD(restore, RestoreWindow)                 \
  METHOD(setBordered, SetWindowBordered)         \
  METHOD(setBrightness, SetWindowBrightness)     \
  METHOD(setData, SetWindowData)                 \
  METHOD(setDisplayMode, SetWindowDisplayMode)   \
  METHOD(setFullscreen, SetWindowFullscreen)     \
  METHOD(setGammaRamp, SetWindowGammaRamp)       \
  METHOD(setGrab, SetWindowGrab)                 \
  METHOD(setIcon, SetWindowIcon)                 \
  METHOD(setMaximumSize, SetWindowMaximumSize)   \
  METHOD(setMinimumSize, SetWindowMinimumSize)   \
  METHOD(setPosition, SetWindowPosition)         \
  METHOD(setSize, SetWindowSize)                 \
  METHOD(setTitle, SetWindowTitle)               \
  METHOD(show, ShowWindow)                       \
  METHOD(updateSurface, UpdateWindowSurface)     \
  METHOD(updateSurfaceRects, UpdateWindowSurfaceRects)
#if SDL_COMPILEDVERSION < 2004
#define SDL_CLASS_METHOD_LIST                    \
  SDL_CLASS_METHOD_LIST_TMP
#else
#define SDL_CLASS_METHOD_LIST                    \
  SDL_CLASS_METHOD_LIST_TMP                      \
  METHOD(setHitTest, SetWindowHitTest)
#endif

  SDL_CLASS(Window);
#undef SDL_CLASS_METHOD_LIST
#undef SDL_CLASS_METHOD_LIST_TMP

#define SDL_CLASS_METHOD_LIST_TMP                  \
  METHOD(getDrawBlendMode, GetRenderDrawBlendMode) \
  METHOD(getDrawColor, GetRenderDrawColor)         \
  METHOD(getDriverInfo, GetRenderDriverInfo)       \
  METHOD(getTarget, GetRenderTarget)               \
  METHOD(getInfo, GetRendererInfo)                 \
  METHOD(getOutputSize, GetRendererOutputSize)     \
  METHOD(clear, RenderClear)                       \
  METHOD(copy, RenderCopy)                         \
  METHOD(copyEx, RenderCopyEx)                     \
  METHOD(drawLine, RenderDrawLine)                 \
  METHOD(drawLines, RenderDrawLines)               \
  METHOD(drawPoint, RenderDrawPoint)               \
  METHOD(drawPoints, RenderDrawPoints)             \
  METHOD(drawRect, RenderDrawRect)                 \
  METHOD(drawRects, RenderDrawRects)               \
  METHOD(fillRect, RenderFillRect)                 \
  METHOD(fillRects, RenderFillRects)               \
  METHOD(getClipRect, RenderGetClipRect)           \
  METHOD(getLogicalSize, RenderGetLogicalSize)     \
  METHOD(getScale, RenderGetScale)                 \
  METHOD(getViewport, RenderGetViewport)           \
  METHOD(present, RenderPresent)                   \
  METHOD(readPixels, RenderReadPixels)             \
  METHOD(setClipRect, RenderSetClipRect)           \
  METHOD(setLogicalSize, RenderSetLogicalSize)     \
  METHOD(setScale, RenderSetScale)                 \
  METHOD(setViewport, RenderSetViewport)           \
  METHOD(targetSupported, RenderTargetSupported)   \
  METHOD(setDrawBlendMode, SetRenderDrawBlendMode) \
  METHOD(setDrawColor, SetRenderDrawColor)         \
  METHOD(setTarget, SetRenderTarget)

#ifdef USE_SDLGFX
  #define SDLGFX_METHOD_LIST                       \
    METHOD2(pixelColor, ::pixelColor) \
    METHOD2(pixelRGBA, ::pixelRGBA) \
    METHOD2(hlineColor, ::hlineColor) \
    METHOD2(hlineRGBA, ::hlineRGBA) \
    METHOD2(vlineColor, ::vlineColor) \
    METHOD2(vlineRGBA, ::vlineRGBA) \
    METHOD2(rectangleColor, ::rectangleColor) \
    METHOD2(rectangleRGBA, ::rectangleRGBA) \
    METHOD2(roundedRectangleColor, ::roundedRectangleColor) \
    METHOD2(roundedRectangleRGBA, ::roundedRectangleRGBA) \
    METHOD2(boxColor, ::boxColor) \
    METHOD2(boxRGBA, ::boxRGBA) \
    METHOD2(roundedBoxColor, ::roundedBoxColor) \
    METHOD2(roundedBoxRGBA, ::roundedBoxRGBA) \
    METHOD2(lineColor, ::lineColor) \
    METHOD2(lineRGBA, ::lineRGBA) \
    METHOD2(aalineColor, ::aalineColor) \
    METHOD2(aalineRGBA, ::aalineRGBA) \
    METHOD2(thickLineColor, ::thickLineColor) \
    METHOD2(thickLineRGBA, ::thickLineRGBA) \
    METHOD2(circleColor, ::circleColor) \
    METHOD2(circleRGBA, ::circleRGBA) \
    METHOD2(arcColor, ::arcColor) \
    METHOD2(arcRGBA, ::arcRGBA) \
    METHOD2(aacircleColor, ::aacircleColor) \
    METHOD2(aacircleRGBA, ::aacircleRGBA) \
    METHOD2(filledCircleColor, ::filledCircleColor) \
    METHOD2(filledCircleRGBA, ::filledCircleRGBA) \
    METHOD2(ellipseColor, ::ellipseColor) \
    METHOD2(ellipseRGBA, ::ellipseRGBA) \
    METHOD2(aaellipseColor, ::aaellipseColor) \
    METHOD2(aaellipseRGBA, ::aaellipseRGBA) \
    METHOD2(filledEllipseColor, ::filledEllipseColor) \
    METHOD2(filledEllipseRGBA, ::filledEllipseRGBA) \
    METHOD2(pieColor, ::pieColor) \
    METHOD2(pieRGBA, ::pieRGBA) \
    METHOD2(filledPieColor, ::filledPieColor) \
    METHOD2(filledPieRGBA, ::filledPieRGBA) \
    METHOD2(trigonColor, ::trigonColor) \
    METHOD2(trigonRGBA, ::trigonRGBA) \
    METHOD2(aatrigonColor, ::aatrigonColor) \
    METHOD2(aatrigonRGBA, ::aatrigonRGBA) \
    METHOD2(filledTrigonColor, ::filledTrigonColor) \
    METHOD2(filledTrigonRGBA, ::filledTrigonRGBA) \
    METHOD2(polygonColor, ::polygonColor) \
    METHOD2(polygonRGBA, ::polygonRGBA) \
    METHOD2(aapolygonColor, ::aapolygonColor) \
    METHOD2(aapolygonRGBA, ::aapolygonRGBA) \
    METHOD2(filledPolygonColor, ::filledPolygonColor) \
    METHOD2(filledPolygonRGBA, ::filledPolygonRGBA) \
    METHOD2(texturedPolygon, ::texturedPolygon) \
    METHOD2(bezierColor, ::bezierColor) \
    METHOD2(bezierRGBA, ::bezierRGBA) \
    METHOD2(characterColor, ::characterColor) \
    METHOD2(characterRGBA, ::characterRGBA) \
    METHOD2(stringColor, ::stringColor) \
    METHOD2(stringRGBA, ::stringRGBA) \
    int stringColor(Sint16 x, Sint16 y, const std::string& str, Uint32 color) \
      { return stringColor(x,y, str.c_str(), color); } \
    int stringRGBA(Sint16 x, Sint16 y, const std::string& str, Uint8 r, Uint8 g, Uint8 b, Uint8 a) \
      { return stringRGBA(x,y, str.c_str(), r,g,b,a); }

#else
  #define SDLGFX_METHOD_LIST
#endif

#if SDL_COMPILEDVERSION < 2004
#define SDL_CLASS_METHOD_LIST                      \
  SDL_CLASS_METHOD_LIST_TMP                        \
  SDLGFX_METHOD_LIST
  SDL_CLASS(Renderer);
#else
#define SDL_CLASS_METHOD_LIST                      \
  SDL_CLASS_METHOD_LIST_TMP                        \
  SDLGFX_METHOD_LIST                               \
  METHOD(isClipEnabled, RenderIsClipEnabled)
  SDL_CLASS(Renderer);
#endif

#undef SDL_CLASS_METHOD_LIST
#define SDL_CLASS_METHOD_LIST                                 \
  Texture(SDL_Renderer *renderer, SDL_Surface *surface)       \
    : handle(SDL_CreateTextureFromSurface(renderer, surface)) \
  {                                                           \
    if (!handle)                                              \
    {                                                         \
      std::ostringstream strm;                                \
      strm << "Texture::Texture(): " << SDL_GetError();       \
      throw Error(strm.str());                                \
    }                                                         \
  }                                                           \
  METHOD(glBind, GL_BindTexture)                              \
  METHOD(glUnbind, GL_UnbindTexture)                          \
  METHOD(getAlphaMod, GetTextureAlphaMod)                     \
  METHOD(getBlendMode, GetTextureBlendMode)                   \
  METHOD(getColorMod, GetTextureColorMod)                     \
  METHOD(lock, LockTexture)                                   \
  METHOD(query, QueryTexture)                                 \
  METHOD(setAlphaMod, SetTextureAlphaMod)                     \
  METHOD(setBlendMode, SetTextureBlendMode)                   \
  METHOD(setColorMod, SetTextureColorMod)                     \
  METHOD(unlock, UnlockTexture)                               \
  METHOD(update, UpdateTexture)                               \
  METHOD(updateYuv, UpdateYUVTexture)
  SDL_CLASS(Texture);

  class Surface
  {
    void checkErrors()
    {
      if (!handle)
      {
        std::ostringstream strm;
        strm << "Surface::Surface(): " << SDL_GetError();
        throw Error(strm.str());
      }
    }

  public:
    Surface(Uint32 flags,
            int width,
            int height,
            int depth,
            Uint32 Rmask,
            Uint32 Gmask,
            Uint32 Bmask,
            Uint32 Amask)
      : handle(SDL_CreateRGBSurface(flags, width, height, depth, Rmask, Gmask, Bmask, Amask))
    {
      checkErrors();
    }
    Surface(SDL_RWops *src, int freesrc) : handle(SDL_LoadBMP_RW(src, freesrc)) { checkErrors(); }
    Surface(const std::string &file) : handle(SDL_LoadBMP(file.c_str())) { checkErrors(); }
    Surface(SDL_Surface *src, const SDL_PixelFormat *fmt, Uint32 flags)
      : handle(SDL_ConvertSurface(src, fmt, flags))
    {
      checkErrors();
    }
    Surface(SDL_Surface *src, Uint32 pixel_format, Uint32 flags)
      : handle(SDL_ConvertSurfaceFormat(src, pixel_format, flags))
    {
      checkErrors();
    }
    Surface(SDL_Surface *handle_) : handle(handle_)
    {
      checkErrors();
    }
    Surface(const Surface &) = delete;
    Surface &operator=(const Surface &) = delete;
    ~Surface() { SDL_FreeSurface(handle); }
    SDL_Surface *get() { return handle; }
    const SDL_Surface *get() const { return handle; }

  private:
    SDL_Surface *handle;

  public:
    METHOD(setPalette, SetSurfacePalette)
    METHOD(lock, LockSurface)
    METHOD(unlock, UnlockSurface)
    METHOD(setColorKey, SetColorKey)
    METHOD(getColorKey, GetColorKey)
    METHOD(setColorMode, SetSurfaceColorMod)
    METHOD(getColorMode, GetSurfaceColorMod)
    METHOD(setClipRect, SetClipRect)
    METHOD(getClipRect, GetClipRect)
    METHOD(fillRect, FillRect)
    METHOD(fillRects, FillRects)
    METHOD(blit, BlitSurface)
    METHOD(softStretch, SoftStretch)
    METHOD(blitScaled, BlitScaled)
  };

  class Audio
  {
  public:
    Audio(const char *device,
          bool iscapture,
          const SDL_AudioSpec *desired,
          SDL_AudioSpec *obtained,
          int allowed_changes,
          std::function<void(Uint8 *stream, int len)> callback_ = nullptr)
      : callback(callback_)
    {
      if (desired)
      {
        SDL_AudioSpec tmp;
        tmp = *desired;
        if (callback)
        {
          tmp.callback = Audio::internalCallback;
          tmp.userdata = this;
        }
        else
        {
          tmp.callback = nullptr;
        }
        handle = SDL_OpenAudioDevice(device, iscapture, &tmp, obtained, allowed_changes);
      }
      else
      {
        handle = SDL_OpenAudioDevice(device, iscapture, desired, obtained, allowed_changes);
      }
      if (handle <= 0)
      {
        std::ostringstream strm;
        strm << "Audio::Audio(): " << SDL_GetError();
        throw Error(strm.str());
      }
    }
    Audio(SDL_AudioDeviceID handle_) : handle(handle_) {}
    Audio(const Audio &) = delete;
    Audio &operator=(const Audio &) = delete;
    ~Audio() { SDL_CloseAudioDevice(handle); }
    SDL_AudioDeviceID get() { return handle; }

  private:
    SDL_AudioDeviceID handle;
    std::function<void(Uint8 *stream, int len)> callback;
    static void internalCallback(void *userdata, Uint8 *stream, int len)
    {
      static_cast<Audio *>(userdata)->callback(stream, len);
    }

  public:
#if SDL_COMPILEDVERSION >= 2004
    METHOD(clearQueued, ClearQueuedAudio)
    METHOD(getQueuedSize, GetQueuedAudioSize)
    METHOD(queue, QueueAudio)
#endif
    METHOD(getStatus, GetAudioDeviceStatus)
    METHOD(lock, LockAudioDevice)
    METHOD(pause, PauseAudioDevice)
    METHOD(unlock, UnlockAudioDevice)
  };
  class EventHandler
  {
  public:
    bool poll()
    {
      SDL_Event e;
      if (SDL_PollEvent(&e))
      {
        handleEvent(e);
        return true;
      }
      else
        return false;
    }
    void wait(int timeout = -1)
    {
      SDL_Event e;
      int res;
      if (timeout >= 0)
        res = SDL_WaitEvent(&e);
      else
        res = SDL_WaitEventTimeout(&e, timeout);
      if (res)
        handleEvent(e);
      else
      {
        std::ostringstream strm;
        strm << "EventHandler::wait(): " << SDL_GetError();
        throw Error(strm.str());
      }
    }
#define SDL_EVENTS_TMP                                                    \
  EVENT(SDL_CONTROLLERAXISMOTION, controllerAxisMotion, caxis);           \
  EVENT(SDL_CONTROLLERBUTTONDOWN, controllerButtonDown, cbutton);         \
  EVENT(SDL_CONTROLLERBUTTONUP, controllerButtonUp, cbutton);             \
  EVENT(SDL_CONTROLLERDEVICEADDED, controllerDeviceAdded, cdevice);       \
  EVENT(SDL_CONTROLLERDEVICEREMOVED, controllerDeviceRemoved, cdevice);   \
  EVENT(SDL_CONTROLLERDEVICEREMAPPED, controllerDeviceRemapped, cdevice); \
  EVENT(SDL_DOLLARGESTURE, dollarGesture, dgesture);                      \
  EVENT(SDL_DOLLARRECORD, dollarRecord, dgesture);                        \
  EVENT(SDL_DROPFILE, dropFile, drop);                                    \
  EVENT(SDL_FINGERMOTION, fingerMotion, tfinger);                         \
  EVENT(SDL_FINGERDOWN, fingerDown, tfinger);                             \
  EVENT(SDL_FINGERUP, fingerUp, tfinger);                                 \
  EVENT(SDL_KEYDOWN, keyDown, key);                                       \
  EVENT(SDL_KEYUP, keyUp, key);                                           \
  EVENT(SDL_JOYAXISMOTION, joyAxisMotion, jaxis);                         \
  EVENT(SDL_JOYBALLMOTION, joyBallMotion, jball);                         \
  EVENT(SDL_JOYHATMOTION, joyHatMotion, jhat);                            \
  EVENT(SDL_JOYBUTTONDOWN, joyButtonDown, jbutton);                       \
  EVENT(SDL_JOYBUTTONUP, joyButtonUp, jbutton);                           \
  EVENT(SDL_JOYDEVICEADDED, joyDeviceAdded, jdevice);                     \
  EVENT(SDL_JOYDEVICEREMOVED, joyDeviceRemoved, jdevice);                 \
  EVENT(SDL_MOUSEMOTION, mouseMotion, motion);                            \
  EVENT(SDL_MOUSEBUTTONDOWN, mouseButtonDown, button);                    \
  EVENT(SDL_MOUSEBUTTONUP, mouseButtonUp, button);                        \
  EVENT(SDL_MOUSEWHEEL, mouseWheel, wheel);                               \
  EVENT(SDL_MULTIGESTURE, multiGesture, mgesture);                        \
  EVENT(SDL_QUIT, quit, quit);                                            \
  EVENT(SDL_SYSWMEVENT, sysWmEvent, syswm);                               \
  EVENT(SDL_TEXTEDITING, textEditing, edit);                              \
  EVENT(SDL_TEXTINPUT, textInput, text);                                  \
  EVENT(SDL_USEREVENT, userEvent, user);                                  \
  EVENT(SDL_WINDOWEVENT, windowEvent, window);
#if SDL_COMPILEDVERSION < 2004
#define SDL_EVENTS SDL_EVENTS_TMP
#else
#define SDL_EVENTS                                                        \
  SDL_EVENTS_TMP                                                          \
  EVENT(SDL_AUDIODEVICEADDED, audioDeviceAdded, adevice);                 \
  EVENT(SDL_AUDIODEVICEREMOVED, audioDeviceRemoved, adevice);
#endif

#define EVENT(x, y, z) std::function<void(const decltype(SDL_Event::z) &)> y
    SDL_EVENTS
#undef EVENT
  private:
    void handleEvent(const SDL_Event &e)
    {
      switch (e.type)
      {
#define EVENT(x, y, z) \
  case x:              \
    if (y)             \
      y(e.z);          \
    break;
        SDL_EVENTS
#undef EVENT
      default: break;
      }
    }
  };
} // namespace sdl
