#include "Mode.hpp"

#include "Scene.hpp"

#include <glm/glm.hpp>

#include <vector>
#include <deque>
#include "Fruit.hpp"

struct PlayMode : Mode {
	PlayMode();
	virtual ~PlayMode();

	//functions called by main loop:
	virtual bool handle_event(SDL_Event const &, glm::uvec2 const &window_size) override;
	virtual void update(float elapsed) override;
	virtual void draw(glm::uvec2 const &drawable_size) override;
	virtual void Start() override;

	//----- game state -----

	//input tracking:
	struct Button {
		uint8_t downs = 0;
		uint8_t pressed = 0;
	} space;

	//local copy of the game scene (so code can change it during gameplay):
	Scene scene;

	std::unordered_map<std::string, glm::vec3> velocities;

	//camera:
	Scene::Camera *camera = nullptr;

	Scene::Transform *lightTransform = nullptr;

	std::vector<Fruit> fruits;
	void InstantiateFruit(const std::string& meshName, glm::vec3 position);
 
	void DestroyFruit(int index);

	void HandleSpacePressed();
};
