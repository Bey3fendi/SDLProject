#include "render_manager.h"
#include <SDL2/SDL_render.h>

RenderManager::RenderManager() = default;

bool RenderManager::CreateWindow(const char* title, int x, int y, int w, int h, Uint32 flag) { //TODO: will be moved into the WindowManager
    bool result = false;
    window_ = SDL_CreateWindow(title, x, y, w, h, flag);

    if (!window_) {
        LOG(ERROR) << "Window cannot created the error is: " << SDL_GetError();
    } else {
        LOG(INFO) << "Window created successfully!";
        result = true;
    }
    return result;
}

SDL_Window* RenderManager::GetWindow() {//TODO: will be moved into the WindowManager
    if (window_) {
        return window_;
    } else {
        LOG(WARNING) << "window object is not created yet";
        return nullptr;
    }
}

bool RenderManager::CreateRenderer(int index, uint32_t flag) {
    bool result = false;
    renderer_ = SDL_CreateRenderer(window_, index, flag);

    if (!renderer_) {
        LOG(ERROR) << "Renderer cannot created the error is: " << SDL_GetError();
    } else {
        LOG(INFO) << "Renderer created successfully!";
        result = true;
    }
    return result;
}

SDL_Renderer* RenderManager::GetRenderer() {
    if (renderer_) {
        return renderer_;
    } else {
        LOG(WARNING) << "Renderer object is not created yet";
        return nullptr;
    }
}

void RenderManager::SetRenderDrawColour(SurfaceColour colour_selection) {
    switch (colour_selection) {
        case kBlack:  SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);         break;
        case kWhite:  SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);   break;
        case kRed:    SDL_SetRenderDrawColor(renderer_, 255, 0, 0, 255);       break;
        case kGreen:  SDL_SetRenderDrawColor(renderer_, 0, 255, 0, 255);       break;
        case kBlue:   SDL_SetRenderDrawColor(renderer_, 0, 0, 255, 255);       break;
        case kYellow: SDL_SetRenderDrawColor(renderer_, 255, 255, 0, 255);     break;
        case kPink:   SDL_SetRenderDrawColor(renderer_, 255, 192, 203, 255);   break;
        case kBrown:  SDL_SetRenderDrawColor(renderer_, 139, 69, 19, 255);     break;
        case kOrange: SDL_SetRenderDrawColor(renderer_, 255, 165, 0, 255);     break;
        default:      SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);         break;
    }
}

void RenderManager::DrawRect(SDL_Rect outline) {
    SDL_RenderDrawRect(renderer_, &outline);
}

void RenderManager::FulfillRect(SDL_Rect outline) {
    SDL_RenderFillRect(renderer_, &outline);
}

void RenderManager::RenderPresent() {
    SDL_RenderPresent(renderer_);
}

void RenderManager::Clear() {
    SDL_RenderClear(renderer_);
}

RenderManager::~RenderManager() {
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
}
