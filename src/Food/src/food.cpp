#include "food.h"
#include <vector>
#include <random>

Food::Food(std::shared_ptr<RenderManager> render_manager, std::shared_ptr<Snake> snake)
    : render_manager_(std::move(render_manager)), snake_(std::move(snake)) {}

SDL_Rect Food::GetFoodCoordinates() {
    return coordinates_of_food_;
}

void Food::SetFoodCoordinates(const SDL_Rect& new_food_coordinates) {
    coordinates_of_food_ = new_food_coordinates;
}

void Food::DrawFood() {
    coordinates_of_food_ = generateFoodCoordinate(snake_->GetSnakeCoordinates());
    render_manager_->SetRenderDrawColour(SurfaceColour::kBlue);
    render_manager_->DrawRect(coordinates_of_food_);
    render_manager_->FulfillRect(coordinates_of_food_);
}

SDL_Rect Food::generateFoodCoordinate(const std::array<SDL_Rect, 900>& snake_coords) {
    constexpr int grid_size = 30;
    constexpr int tile_size = 24;

    std::vector<SDL_Rect> free_tiles;

    for (int row = 0; row < grid_size; ++row) {
        for (int col = 0; col < grid_size; ++col) {
            SDL_Rect tile = { col * tile_size, row * tile_size, tile_size, tile_size };

            bool occupied = false;
            for (const SDL_Rect& segment : snake_coords) {
                if (segment.x == tile.x && segment.y == tile.y) {
                    occupied = true;
                    break;
                }
            }

            if (!occupied)
                free_tiles.push_back(tile);
        }
    }

    if (free_tiles.empty()) {
        throw std::runtime_error("No free tiles left to place food!");
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, static_cast<int>(free_tiles.size() - 1));

    return free_tiles[dist(gen)];
}
