#pragma once

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_stdinc.h>

#include <cstdint>
#include "SDL2/SDL.h"
#include "Logger.h"

/*TODO: Add name spaces in the future*/

constexpr int WIDTH = 1280;
constexpr int HEIGHT = 720;
const char WINDOW_TITLE[6] = "Snake";

enum SurfaceColour { //TODO: can be movable to a constants or utilities class
    kBlack,
    kWhite,
    kRed,
    kGreen,
    kBlue,
    kYellow,
    kPink,
    kBrown,
    kOrange,
};

class RenderManager {
public:
    RenderManager();

    virtual bool CreateWindow(const char* title, int x, int y, int w, int h, Uint32 flag);
    virtual SDL_Window* GetWindow();

    virtual bool CreateRenderer(int index, uint32_t flag);
    virtual SDL_Renderer* GetRenderer();

    virtual void SetRenderDrawColour(SurfaceColour colour_selection);
    virtual void Clear();
    virtual void DrawRect(SDL_Rect outline);
    virtual void FulfillRect(SDL_Rect outline);
    virtual void RenderPresent();

    virtual ~RenderManager();

private:
    SDL_Window* window_ = nullptr;
    SDL_Renderer* renderer_ = nullptr;
};
