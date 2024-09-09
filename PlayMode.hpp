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

	int displayPoints = 0;
	std::string displayText = "0";

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
		{ 1, BANANA},
		{ 2, ORANGE},
		{ 4, BANANA},
		{ 4.5f, ORANGE},
		{ 7, BANANA},
		{ 7.7f, ORANGE},
		{ 8, BANANA},
	};

	void UpdateSpawn();
};
