#ifndef __APPLICATION_
#define __APPLICATION_

#include <Windows.h>
#include "VenomEngine.h"

using namespace VenomEngine;

class Application {
public:
	Application();
	~Application();
	virtual bool Init(Engine * engine);
	virtual void Update(Engine * engine);
	virtual void Shutdown(Engine * engine);
protected:
	Engine * engine;
private:
};

static Application *app;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int cmdShow) {

	app = new Application();
	Engine * engine = Engine::Instance();

	if (app->Init(engine)) {}

	while (engine->getRunning()) {
		app->Update(engine);
	}

	app->Shutdown(engine);
}

#endif