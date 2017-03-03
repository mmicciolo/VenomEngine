#include "../VenomEngine/Engine/VenomEngine.h"
#include "../VenomEngine/Engine/Application.h"
#include "../VenomEngine/Object/VenomObject.h"
#include "../VenomEngine/Object/Model/OBJ/OBJModel.h"
#include "../VenomEngine/Object/VenomObjectFactory.h"
#include "../VenomEngine/Managers/GraphicsManager.h"
#include "../VenomEngine/Managers//SceneManager.h"
#include "../VenomEngine/Object/Camera/Camera.h"

using namespace VenomEngine;

Application::Application() {}

Application::~Application() {}

bool Application::Init(Engine * engine) {

	/* Perform any initialization tasks here*/
	engine->Init();

	//Create a window
	engine->CreateApplicationWindowAndRenderer("My Venom Application!", 0, 0, 800, 600, WindowManager::WindowType::WINDOW_TITLEBAR);

	//Create a camera to view the scene
	IVenomObject * camera = new Camera();
	camera->SetPosition(Vector3(0.0f, 3.0f, -7.0f));
	SceneManager::Instance()->AddObject(camera);

	//Load and add an object
	IVenomObject * myModel = VenomObjectFactory::Load<OBJModel>("sample2.obj");
	SceneManager::Instance()->AddObject(myModel);

	//Load a second object and reposition it
	OBJModel * myModel2 = VenomObjectFactory::Load<OBJModel>("sample2.obj");
	Vector3 * vec = new Vector3(0, 2, 10);
	myModel2->SetPosition(*vec);
	SceneManager::Instance()->AddObject(myModel2);

	//Return if we were successful or not
	return true;
}

void Application::Update(Engine * engine) {

	/* Perform any update tasks here */
	
	//Tell the engine to update
	engine->Update();
}

void Application::Shutdown(Engine * engine) {

	/* Perform any shutdown tasks here */

	//Tell the engine to shutdown
	engine->Shutdown();
}