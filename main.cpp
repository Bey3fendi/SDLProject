#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_ttf.h>
#include <cstdlib>
#include <memory>
#include "SDL2/SDL.h"
#include "Logger.h"
#include "render_manager.h"
#include "Snake.h"
#include "food.h"

int main() {

/*TestRenderManager && snake && food*/
std::shared_ptr<RenderManager> render_manager = std::make_shared<RenderManager>();
std::shared_ptr<Snake> snake = std::make_shared<Snake>(render_manager);
std::shared_ptr<Food> food = std::make_unique<Food>(render_manager, snake);

render_manager->CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);

bool res = render_manager->CreateRenderer(-1, SDL_RENDERER_ACCELERATED);

SDL_Rect outline = {72, 0, SNAKE_SQUARE_WIDTH, SNAKE_SQUARE_HEIGHT};
SDL_Rect outline2 = {96, 0, SNAKE_SQUARE_WIDTH, SNAKE_SQUARE_HEIGHT};
SDL_Rect outline3 = {120, 0, SNAKE_SQUARE_WIDTH, SNAKE_SQUARE_HEIGHT};
snake->AddNewTileToSnake(outline);
snake->AddNewTileToSnake(outline2);
snake->AddNewTileToSnake(outline3);
SDL_Rect food_coordinates {};

int current_time = SDL_GetTicks();
bool is_stopped = true;
bool showRect = true;
while(is_stopped) {
    render_manager->SetRenderDrawColour(SurfaceColour::kPink);
    render_manager->Clear();

    if(showRect) {
        // render_manager->SetRenderDrawColour(SurfaceColour::kBlack);
        // render_manager->DrawRect(outline);
        // render_manager->FulfillRect(outline);
        food_coordinates = food->generateFoodCoordinate(snake->GetSnakeCoordinates());
        food->SetFoodCoordinates(food_coordinates);
        snake->DrawSnake();
        food->DrawFood(food_coordinates);
    }

    render_manager->RenderPresent();
    int last_time = SDL_GetTicks();
    if(last_time - current_time >= 10000) {
        is_stopped = false;
    }
    SDL_Delay(100);
}

SDL_Delay(2000);

SDL_Quit();
}