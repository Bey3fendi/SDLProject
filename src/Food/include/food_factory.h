

#include "Snake.h"
#include "food.h"
#include "render_manager.h"
#include <memory>

class FoodFactory {
public:
    static std::shared_ptr<Food> Create(const std::shared_ptr<RenderManager>& render, const std::shared_ptr<Snake>& snake) {
        return std::make_shared<Food>(render, snake);
    }   
    

};
