#include "Snake.h"

Snake::Snake(std::shared_ptr<RenderManager> render_manager)
    : render_manager_(render_manager) {
    snake_coordinates_[0] = {0, 0, SNAKE_SQUARE_WIDTH, SNAKE_SQUARE_HEIGHT};
    snake_coordinates_[1] = {24, 0, SNAKE_SQUARE_WIDTH, SNAKE_SQUARE_HEIGHT};
    snake_coordinates_[2] = {48, 0, SNAKE_SQUARE_WIDTH, SNAKE_SQUARE_HEIGHT};
}

std::array<SDL_Rect, MAX_SNAKE_SIZE> Snake::GetSnakeCoordinates() {
    return snake_coordinates_;
}

void Snake::SetSnakeCoordinates(const std::array<SDL_Rect, MAX_SNAKE_SIZE>& snake_coordinate_array) {
    snake_coordinates_ = snake_coordinate_array;
}

void Snake::AddNewTileToSnake(const SDL_Rect& outline) {
    ++snake_size_;
    snake_coordinates_[snake_size_] = outline;
}

void Snake::DrawSnake() {
    for (int i = 0; i <= snake_size_; ++i) {
        render_manager_->SetRenderDrawColour(SurfaceColour::kRed);
        render_manager_->DrawRect(snake_coordinates_[i]);
        render_manager_->FulfillRect(snake_coordinates_[i]);
    }
}

int Snake::GetSnakeSize() {
    return snake_size_;
}
