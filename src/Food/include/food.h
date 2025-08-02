#pragma once

#include <SDL2/SDL_rect.h>
#include <memory>
#include "render_manager.h"
#include "Snake.h" // TODO: fix it after done CMake of food module

constexpr int FOOD_SQUARE_WIDTH = 24;
constexpr int FOOD_SQUARE_HEIGHT = 24;

class Food {
public:
    explicit Food(std::shared_ptr<RenderManager> render_manager, std::shared_ptr<Snake> snake);

    virtual SDL_Rect GetFoodCoordinates();
    virtual void SetFoodCoordinates(const SDL_Rect& new_food_coordinates);
    virtual void DrawFood();

    virtual ~Food() = default;

private:
    SDL_Rect generateFoodCoordinate(const std::array<SDL_Rect, 900>& snake_coords);

    SDL_Rect coordinates_of_food_{};
    std::shared_ptr<RenderManager> render_manager_;
    std::shared_ptr<Snake> snake_;
};
