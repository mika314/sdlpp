# sdlpp
Header only C++ wrapper for SDL2.

[![C++ Wrapper for SDL2](https://img.youtube.com/vi/fD-bCQ20NRo/0.jpg)](https://www.youtube.com/watch?v=fD-bCQ20NRo)

The library leverage RAII and error handling with exceptions.

SDL2 code
```c++
  int res = SDL_Init(SDL_INIT_EVERYTHING);
  if (res < 0)
  {
    // error handling
  }
  // your code
  SDL_Quit();
```

sdlpp code
```c++
  try
  {
    sdl::Init init(SDL_INIT_EVERYTHING);
    // your code
  }
  catch (sdl::Error &e)
  {
    // error handling
  }
```

Also I mapped functions to methods.

## Window
|Method|SDL2 function|
|------|-------------|
|glCreateContext|SDL_GL_CreateContext|
|glGetDrawableSize|SDL_GL_GetDrawableSize|
|glMakeCurrent|SDL_GL_MakeCurrent|
|glSwap|SDL_GL_SwapWindow|
|getBrightness|SDL_GetWindowBrightness|
|getData|SDL_GetWindowData|
|getDisplayIndex|SDL_GetWindowDisplayIndex|
|getDisplayMode|SDL_GetWindowDisplayMode|
|getFlags|SDL_GetWindowFlags|
|getGammaRamp|SDL_GetWindowGammaRamp|
|getGrab|SDL_GetWindowGrab|
|getID|SDL_GetWindowID|
|getMaximumSize|SDL_GetWindowMaximumSize|
|getMinimumSize|SDL_GetWindowMinimumSize|
|getPixelFormat|SDL_GetWindowPixelFormat|
|getPosition|SDL_GetWindowPosition|
|getSize|SDL_GetWindowSize|
|getSurface|SDL_GetWindowSurface|
|getTitle|SDL_GetWindowTitle|
|hide|SDL_HideWindow|
|maximize|SDL_MaximizeWindow|
|minimize|SDL_MinimizeWindow|
|raise|SDL_RaiseWindow|
|restore|SDL_RestoreWindow|
|setBordered|SDL_SetWindowBordered|
|setBrightness|SDL_SetWindowBrightness|
|setData|SDL_SetWindowData|
|setDisplayMode|SDL_SetWindowDisplayMode|
|setFullscreen|SDL_SetWindowFullscreen|
|setGammaRamp|SDL_SetWindowGammaRamp|
|setGrab|SDL_SetWindowGrab|
|setHitTest|SDL_SetWindowHitTest|
|setIcon|SDL_SetWindowIcon|
|setMaximumSize|SDL_SetWindowMaximumSize|
|setMinimumSize|SDL_SetWindowMinimumSize|
|setPosition|SDL_SetWindowPosition|
|setSize|SDL_SetWindowSize|
|setTitle|SDL_SetWindowTitle|
|show|SDL_ShowWindow|
|updateSurface|SDL_UpdateWindowSurface|
|updateSurfaceRects|SDL_UpdateWindowSurfaceRects|

##Renderer
|Method|SDL2 function|
|------|-------------|
|getDrawBlendMode|SDL_GetRenderDrawBlendMode|
|getDrawColor|SDL_GetRenderDrawColor|
|getDriverInfo|SDL_GetRenderDriverInfo|
|getTarget|SDL_GetRenderTarget|
|getInfo|SDL_GetRendererInfo|
|getOutputSize|SDL_GetRendererOutputSize|
|clear|SDL_RenderClear|
|copy|SDL_RenderCopy|
|copyEx|SDL_RenderCopyEx|
|drawLine|SDL_RenderDrawLine|
|drawLines|SDL_RenderDrawLines|
|drawPoint|SDL_RenderDrawPoint|
|drawPoints|SDL_RenderDrawPoints|
|drawRect|SDL_RenderDrawRect|
|drawRects|SDL_RenderDrawRects|
|fillRect|SDL_RenderFillRect|
|fillRects|SDL_RenderFillRects|
|getClipRect|SDL_RenderGetClipRect|
|getLogicalSize|SDL_RenderGetLogicalSize|
|getScale|SDL_RenderGetScale|
|getViewport|SDL_RenderGetViewport|
|isClipEnabled|SDL_RenderIsClipEnabled|
|present|SDL_RenderPresent|
|readPixels|SDL_RenderReadPixels|
|setClipRect|SDL_RenderSetClipRect|
|setLogicalSize|SDL_RenderSetLogicalSize|
|setScale|SDL_RenderSetScale|
|setViewport|SDL_RenderSetViewport|
|targetSupported|SDL_RenderTargetSupported|
|setDrawBlendMode|SDL_SetRenderDrawBlendMode|
|setDrawColor|SDL_SetRenderDrawColor|
|setTarget|SDL_SetRenderTarget|

##Texture
|glBind|SDL_GL_BindTexture|
|glUnbind|SDL_GL_UnbindTexture|
|getAlphaMod|SDL_GetTextureAlphaMod|
|getBlendMode|SDL_GetTextureBlendMode|
|getColorMod|SDL_GetTextureColorMod|
|lock|SDL_LockTexture|
|query|SDL_QueryTexture|
|setAlphaMod|SDL_SetTextureAlphaMod|
|setBlendMode|SDL_SetTextureBlendMode|
|setColorMod|SDL_SetTextureColorMod|
|unlock|SDL_UnlockTexture|
|update|SDL_UpdateTexture|
|updateYuv|SDL_UpdateYUVTexture|

Also Texture has overloaded constructor:
```c++
Texture(SDL_Renderer *renderer, SDL_Surface *surface);
```

##Surface
|setPalette|SDL_SetSurfacePalette|
|lock|SDL_LockSurface|
|unlock|SDL_UnlockSurface|
|setColorKey|SDL_SetColorKey|
|getColorKey|SDL_GetColorKey|
|setColorMode|SDL_SetSurfaceColorMod|
|getColorMode|SDL_GetSurfaceColorMod|
|setClipRect|SDL_SetClipRect|
|getClipRect|SDL_GetClipRect|
|fillRect|SDL_FillRect|
|fillRects|SDL_FillRects|
|blit|SDL_BlitSurface|
|softStretch|SDL_SoftStretch|
|blitScaled|SDL_BlitScaled|

Surface also has multiple overloaded constructors:
```c++
Surface(Uint32 flags, int width, int height, int depth,
            Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask);
Surface(SDL_RWops *src, int freesrc);
Surface(const std::string &file);
Surface(SDL_Surface *src, const SDL_PixelFormat *fmt, Uint32 flags);
Surface(SDL_Surface *src, Uint32 pixel_format, Uint32 flags);
```
##Audio
|clearQueued|SDL_ClearQueuedAudio|
|getStatus|SDL_GetAudioDeviceStatus|
|getQueuedSize|SDL_GetQueuedAudioSize|
|lock|SDL_LockAudioDevice|
|pause|SDL_PauseAudioDevice|
|queue|SDL_QueueAudio|
|unlock|SDL_UnlockAudioDevice|

Constructor:
```c++
Audio(const char *device,
          bool iscapture,
          const SDL_AudioSpec *desired,
          SDL_AudioSpec *obtained,
          int allowed_changes,
          std::function<void(Uint8 *stream, int len)> callback = nullptr);
```

##Event Handling