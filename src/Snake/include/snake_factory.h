

#include "Snake.h"
#include "render_manager.h"
#include <memory>
//TODO:will add namespace
class SnakeFactory {
    public:
    static std::shared_ptr<Snake> Create(std::shared_ptr<RenderManager> render) {
        return std::make_shared<Snake>(render);
    }
};