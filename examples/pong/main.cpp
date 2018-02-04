#include "../../sdlpp.hpp"

int main(int argc, char *argv[])
{
  using namespace sdl;
  Init init(SDL_INIT_EVERYTHING);
  const auto Width = 1280;
  const auto Height = 720;
  Window w("Graphs", 63, 126, Width, Height, SDL_WINDOW_BORDERLESS);
  SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
  Renderer r(w.get(), -1, 0);
  auto currentTick = SDL_GetTicks() / 17;
  auto playerY = 0;
  auto aiY = 0;
  auto pongX = 1280 / 2;
  auto pongY = 720 / 2;
  auto pongVX = 5;
  auto pongVY = 5;
  auto aiScore = 0;
  auto playerScore = 0;
  EventHandler e;
  e.mouseMotion = [&playerY](const SDL_MouseMotionEvent &e)
    {
      playerY = e.y - 50;
    };
  auto done = false;
  e.quit = [&done](const SDL_QuitEvent &)
    {
      done = true;
    };
  while(!done)
  {
    while (e.poll()) {}
    auto oldTick = currentTick;
    currentTick = SDL_GetTicks() / 17;
    for (;oldTick < currentTick; ++oldTick)
    {
      pongX += pongVX;
      pongY += pongVY;
      if (pongY < 0 && pongVY < 0)
        pongVY *= -1;
      if (pongY > Height && pongVY > 0)
        pongVY *= -1;
      if (pongX < 0 && pongVX < 0)
      {
        pongVX *= -1;
        if (pongY < playerY || pongY > playerY + 100)
        {
          aiScore++;
          pongX = 1280 / 2;
          pongY = 720 / 2;
        }
      }
      if (pongX > Width && pongVX > 0)
      {
        pongVX *= -1;
        if (pongY < aiY || pongY > aiY + 100)
        {
          playerScore++;
          pongX = 1280 / 2;
          pongY = 720 / 2;
        }
      }
      if (aiY + 50 < pongY)
        aiY += 4;
      else
        aiY -= 4;
    }
    r.setDrawColor(0x00, 0x00, 0x00, 0xff);
    r.clear();
    r.setDrawColor(0xff, 0xff, 0xff, 0xff);
    SDL_Rect rect;
    rect = { 0, playerY, 10, 100 };
    r.fillRect(&rect);
    rect = { 1280 - 10, aiY, 10, 100 };
    r.fillRect(&rect);
    rect = { pongX - 5, pongY - 5, 10, 10 };
    r.fillRect(&rect);
    for (auto i = 0; i < playerScore; ++i)
    {
      rect = { 100 + i * 20, 50, 10, 10 };
      r.fillRect(&rect);
    }
    for (auto i = 0; i < aiScore; ++i)
    {
      rect = { 1280 - 100 - i * 20, 50, 10, 10 };
      r.fillRect(&rect);
    }
    r.present();
  }
}
