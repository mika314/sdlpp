#include "../../sdlpp.hpp"
#include <vector>

struct Star
{
  float x;
  float y;
  float z;
};

int main(int argc, char **argv)
{
  sdl::Init init(SDL_INIT_EVERYTHING);
  sdl::Window w("Starfiled", 65, 126, 1280, 720, SDL_WINDOW_BORDERLESS);
  SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
  sdl::Renderer r(w.get(), -1, 0);
  auto done = false;
  sdl::EventHandler e;
  e.quit = [&done](const SDL_QuitEvent &)
    {
      done = true;
    };
  std::vector<Star> stars;
  for (int i = 0; i < 1000; ++i)
    stars.push_back(Star{ 1.0f * (rand() % 1280), 1.0f * (rand() % 720), 0 });
  while (!done)
  {
    while (e.poll()) {}
    r.setDrawColor(0x00, 0x00, 0x00, 0xff);
    r.clear();
    for (auto &star: stars)
    {
      if (star.z < 0xff)
        star.z += 1;
      star.x = (star.x - 1280 / 2) * (1 + 0.0001 * star.z) + 1280 / 2;
      star.y = (star.y - 720 / 2) * (1 + 0.0001 * star.z) + 720 / 2;
      if (star.x < 0 || star.x > 1280 || star.y < 0 || star.y > 720)
        star = Star{ 1.0f * (rand() % 1280), 1.0f * (rand() % 720), 0 };
      r.setDrawColor(star.z, star.z, star.z, 0xff);
      r.drawPoint(star.x, star.y);
    }
    r.present();
  }
}
