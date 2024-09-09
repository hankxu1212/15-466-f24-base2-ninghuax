#pragma once
#include "Scene.hpp"

struct Fruit
{
	Fruit(Scene::Drawable& drawable);
	~Fruit() = default;

	Scene::Drawable* drawable;
	void Update(float deltaTime);

    float currentVelocity;
    glm::quat rotationDirection;

	float timeOfInstantiation;
};