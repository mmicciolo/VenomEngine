/*
File : Console.h
Author: Matthew Micciolo

This class provides functions to write to a console and log. The console starts out as a system console
and will be replicated in the GUI in the engine.
*/

#ifndef __CONSOLE_MANAGER_
#define __CONSOLE_MANAGER_

#include "Manager.h"
#include "../Engine/EngineDefs.h"
#include "../Common/Singleton.h"
#include <iostream>
#include <fstream>
#include <io.h>
#include <fcntl.h>

#include <Windows.h>

namespace VenomEngine {
	class ConsoleManager : public Manager, public Singleton<ConsoleManager> {
	public:
		ConsoleManager();
		~ConsoleManager() {};
		bool Init();
		void Update();
		bool Shutdown();
		void WriteCon(std::string message);
		void WriteLog(std::string message);
		void WriteAll(std::string message);
		void AddCommand(std::string command, void(ConsoleManager::*myFunction)());
		void echo();
	protected:
	private:
		HANDLE console_out;
		std::ofstream logFile;
		void InitFileSystem();
	};
}

#endif
