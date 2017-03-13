#include "ConsoleManager.h"
#include "../Engine/EngineDefs.h"

namespace VenomEngine {
	ConsoleManager::ConsoleManager() {
		SetType(CONSOLE_MANAGER);
		Init();
		AddCommand("Echo", &ConsoleManager::echo);
	}

	bool ConsoleManager::Init() {
		AllocConsole();
		freopen("conin$", "r", stdin);
		freopen("conout$", "w", stdout);
		freopen("conout$", "w", stderr);

		InitFileSystem();

		WriteCon("Console Starting...\n");
		WriteLog("Logging Starting...\n");

		return true;
	}

	void ConsoleManager::Update() {

	}

	bool ConsoleManager::Shutdown() {
		FreeConsole();
		fclose(stdin);
		fclose(stdout);
		fclose(stderr);
		logFile.close();
		return true;
	}

	void ConsoleManager::WriteCon(std::string message) {
		printf(message.c_str());
	}

	void ConsoleManager::WriteLog(std::string message) {
		logFile << message.c_str() << std::endl;
	}

	void ConsoleManager::WriteAll(std::string message) {
		WriteCon(message);
		WriteLog(message);
	}

	void ConsoleManager::InitFileSystem() {
		logFile.open("venom.log", std::ofstream::out);
	}

	void ConsoleManager::AddCommand(std::string command, void(ConsoleManager::*myFunction)()) {
		(this->*myFunction)();
	}

	void ConsoleManager::echo() {

	}
}
