#include "Mode.hpp"

#include "Scene.hpp"

#include <glm/glm.hpp>

#include <vector>
#include <deque>
#include "Fruit.hpp"

#define MAX_LEVELS 7

struct PlayMode : Mode {
	PlayMode();
	virtual ~PlayMode();

	//functions called by main loop:
	virtual bool handle_event(SDL_Event const &, glm::uvec2 const &window_size) override;
	virtual void update(float elapsed) override;
	virtual void draw(glm::uvec2 const &drawable_size) override;
	virtual void Start() override;

	//----- game state -----
	float time = 0;

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

	std::string displayText;

	void HandleSpacePressed();


	enum FruitType : uint8_t
	{		
		BANANA = 0,
		APPLE = 1,
		ORANGE = 2,
		COCONUT = 3
	};

	// spawning
	struct SpawnTimeStamp
	{
		float timeStamp;
		FruitType fruitType;
	};

	int currentSpawnIndex = 0;

	const SpawnTimeStamp spawnPattern[MAX_LEVELS] = {
		{ 0.5f, BANANA},
		{ 1, ORANGE},
		{ 2, BANANA},
		{ 3, ORANGE},
		{ 4, BANANA},
		{ 5, ORANGE},
		{ 5, BANANA},
	};

	void UpdateSpawn();
};
