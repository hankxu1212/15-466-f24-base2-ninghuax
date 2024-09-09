#include "Fruit.hpp"
#include "Math.h"

Fruit::Fruit(Scene::Drawable &_drawable)
{
    drawable = &_drawable;
    rotationDirection = glm::quat(glm::vec3(0, 0,  Noire::Math::Random(-90, 90)));
    drawable->transform->rotation = rotationDirection;
}

void Fruit::Update(float deltaTime)
{
    currentVelocity += 3 * deltaTime;
    drawable->transform->position -= glm::vec3(0, 0, deltaTime * currentVelocity);
}
