#include "Manager.h"

namespace VenomEngine {
	Manager::Manager() {

	}

	Manager::~Manager() {

	}

	void Manager::SetType(std::string type) {
		this->type = type;
	}

	bool Manager::Init() {
		this->isStarted = true;
		return true;
	}

	void Manager::Update() {

	}

	bool Manager::Shutdown() {
		return true;
	}

	bool Manager::GetIsStarted() {
		return this->isStarted;
	}

	std::string Manager::GetType() {
		return type;
	}

	//void Manager::EventHandler(Event * event) {

	//}
}