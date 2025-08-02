#pragma once

#include <SDL2/SDL_rect.h>
#include <array>
#include <memory>
#include "render_manager.h"

// Constants for snake structure
constexpr int SNAKE_SQUARE_WIDTH = 24;
constexpr int SNAKE_SQUARE_HEIGHT = 24;
constexpr int MAX_SNAKE_SIZE = 900;

class Snake {
public:
    explicit Snake(std::shared_ptr<RenderManager> render_manager);

    virtual std::array<SDL_Rect, MAX_SNAKE_SIZE> GetSnakeCoordinates();
    virtual void SetSnakeCoordinates(const std::array<SDL_Rect, MAX_SNAKE_SIZE>& snake_coordinate_array);
    virtual void AddNewTileToSnake(const SDL_Rect& outline);
    virtual void DrawSnake();
    virtual int GetSnakeSize();

    ~Snake() = default;

private:
    std::array<SDL_Rect, MAX_SNAKE_SIZE> snake_coordinates_;
    int snake_size_ = 2;
    std::shared_ptr<RenderManager> render_manager_;
};
