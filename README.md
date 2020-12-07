[![Build Status](https://travis-ci.org/mika314/sdlpp.svg?branch=master)](https://travis-ci.org/mika314/sdlpp)

# sdlpp
Header only C++ wrapper for SDL2.

[![C++ Wrapper for SDL2](https://img.youtube.com/vi/fD-bCQ20NRo/0.jpg)](https://www.youtube.com/watch?v=fD-bCQ20NRo)

The library leverages RAII and error handling with exceptions.

Optional support for SDL2_gfx's graphic primitives is available. To turn it on, uncomment the
`#define USE_SDLGFX` directive in `sdlpp.hpp`.

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
|ctor|SDL_CreateWindow|
|dtor|SDL_DestroyWindow|
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

## Renderer
|Method|SDL2 function|
|------|-------------|
|ctor|SDL_CreateRenderer|
|dtor|SDL_DestroyRenderer|
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

## Renderer if SDL2_gfx-support is enabled
|Method|SDL2_gfx function|
|------|-----------------|
|pixelColor|pixelColor|
|pixelRGBA|pixelRGBA|
|hlineColor|hlineColor|
|hlineRGBA|hlineRGBA|
|vlineColor|vlineColor|
|vlineRGBA|vlineRGBA|
|rectangleColor|rectangleColor|
|rectangleRGBA|rectangleRGBA|
|roundedRectangleColor|roundedRectangleColor|
|roundedRectangleRGBA|roundedRectangleRGBA|
|boxColor|boxColor|
|boxRGBA|boxRGBA|
|roundedBoxColor|roundedBoxColor|
|roundedBoxRGBA|roundedBoxRGBA|
|lineColor|lineColor|
|lineRGBA|lineRGBA|
|aalineColor|aalineColor|
|aalineRGBA|aalineRGBA|
|thickLineColor|thickLineColor|
|thickLineRGBA|thickLineRGBA|
|circleColor|circleColor|
|circleRGBA|circleRGBA|
|arcColor|arcColor|
|arcRGBA|arcRGBA|
|aacircleColor|aacircleColor|
|aacircleRGBA|aacircleRGBA|
|filledCircleColor|filledCircleColor|
|filledCircleRGBA|filledCircleRGBA|
|ellipseColor|ellipseColor|
|ellipseRGBA|ellipseRGBA|
|aaellipseColor|aaellipseColor|
|aaellipseRGBA|aaellipseRGBA|
|filledEllipseColor|filledEllipseColor|
|filledEllipseRGBA|filledEllipseRGBA|
|pieColor|pieColor|
|pieRGBA|pieRGBA|
|filledPieColor|filledPieColor|
|filledPieRGBA|filledPieRGBA|
|trigonColor|trigonColor|
|trigonRGBA|trigonRGBA|
|aatrigonColor|aatrigonColor|
|aatrigonRGBA|aatrigonRGBA|
|filledTrigonColor|filledTrigonColor|
|filledTrigonRGBA|filledTrigonRGBA|
|polygonColor|polygonColor|
|polygonRGBA|polygonRGBA|
|aapolygonColor|aapolygonColor|
|aapolygonRGBA|aapolygonRGBA|
|filledPolygonColor|filledPolygonColor|
|filledPolygonRGBA|filledPolygonRGBA|
|texturedPolygon|texturedPolygon|
|bezierColor|bezierColor|
|bezierRGBA|bezierRGBA|
|characterColor|characterColor|
|characterRGBA|characterRGBA|
|stringColor|stringColor|
|stringRGBA|stringRGBA|

## Texture
|Method|SDL2 function|
|------|-------------|
|ctor|SDL_CreateTexture|
|ctor|SDL_CreateTextureFromSurface|
|dtor|SDL_DestroyRenderer|
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

## Surface
|Method|SDL2 function|
|------|-------------|
|ctor|SDL_CreateRGBSurface|
|ctor|SDL_LoadBMP_RW|
|ctor|SDL_LoadBMP|
|ctor|SDL_ConvertSurface|
|dtor|SDL_FreeSurface|
|setPalette|SDL_SetSurfacePalette|
|lock \*|SDL_LockSurface|
|unlock \*|SDL_UnlockSurface|
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

\* Consider `sdl::Surface::Lock` RAII object instead.

## Audio
|Method|SDL2 function|
|------|-------------|
|ctor|SDL_OpenAudioDevice*|
|dtor|SDL_CloseAudioDevice|
|clearQueued|SDL_ClearQueuedAudio|
|getStatus|SDL_GetAudioDeviceStatus|
|getQueuedSize|SDL_GetQueuedAudioSize|
|lock|SDL_LockAudioDevice|
|pause|SDL_PauseAudioDevice|
|queue|SDL_QueueAudio|
|unlock|SDL_UnlockAudioDevice|

*)
```c++
Audio(const char *device,
          bool iscapture,
          const SDL_AudioSpec *desired,
          SDL_AudioSpec *obtained,
          int allowed_changes,
          std::function<void(Uint8 *stream, int len)> callback = nullptr);
```

## Event Handling
Example code:
```c++
  auto done = false;
  sdl::EventHandler e;
  e.quit = [&done](const SDL_QuitEvent &)
    {
      done = true;
    };
  while (!done)
  {
    while (e.poll()) {}
    // rendering
  }

```
|SDL_Event::type|sdl::EventHandler member variable|
|---------------|----------------------|
|SDL_AUDIODEVICEADDED|audioDeviceAdded|
|SDL_AUDIODEVICEREMOVED|audioDeviceRemoved|
|SDL_CONTROLLERAXISMOTION|controllerAxisMotion|
|SDL_CONTROLLERBUTTONDOWN|controllerButtonDown|
|SDL_CONTROLLERBUTTONUP|controllerButtonUp|
|SDL_CONTROLLERDEVICEADDED|controllerDeviceAdded|
|SDL_CONTROLLERDEVICEREMOVED|controllerDeviceRemoved|
|SDL_CONTROLLERDEVICEREMAPPED|controllerDeviceRemapped|
|SDL_DOLLARGESTURE|dollarGesture|
|SDL_DOLLARRECORD|dollarRecord|
|SDL_DROPFILE|dropFile|
|SDL_FINGERMOTION|fingerMotion|
|SDL_FINGERDOWN|fingerDown|
|SDL_FINGERUP|fingerUp|
|SDL_KEYDOWN|keyDown|
|SDL_KEYUP|keyUp|
|SDL_JOYAXISMOTION|joyAxisMotion|
|SDL_JOYBALLMOTION|joyBallMotion|
|SDL_JOYHATMOTION|joyHatMotion|
|SDL_JOYBUTTONDOWN|joyButtonDown|
|SDL_JOYBUTTONUP|joyButtonUp|
|SDL_JOYDEVICEADDED|joyDeviceAdded|
|SDL_JOYDEVICEREMOVED|joyDeviceRemoved|
|SDL_MOUSEMOTION|mouseMotion|
|SDL_MOUSEBUTTONDOWN|mouseButtonDown|
|SDL_MOUSEBUTTONUP|mouseButtonUp|
|SDL_MOUSEWHEEL|mouseWheel|
|SDL_MULTIGESTURE|multiGesture|
|SDL_QUIT|quit|
|SDL_SYSWMEVENT|sysWmEvent|
|SDL_TEXTEDITING|textEditing|
|SDL_TEXTINPUT|textInput|
|SDL_USEREVENT|userEvent|
|SDL_WINDOWEVENT|windowEvent|

Function poll() internally calls SDL_PollEvent and function wait() calls SDL_WaintEvent() or SDL_WaitEventTimeout().

## Examples

Go in the example directory examples/pong or examples/starfield and run make to build.
