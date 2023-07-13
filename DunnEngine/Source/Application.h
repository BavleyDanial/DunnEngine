#pragma once

// Auther: Bavley Danial
// Date: 7/11/2023
//
// TDE - The Dunn Engine
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to DunnGames to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//


#include <memory>
#include "Graphics/Window.h"

namespace DunnEngine {

	class Application
	{
	public:
		Application();  // Constructs the Application
		~Application(); // Destroys the Application

		// Internal methods that take care of backend stuff
		void Run();
		void OnEvent();

		// Methods to be overriden by the client
		virtual void OnInit() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnKeyEvent() = 0;
		virtual void OnMouseEvent() = 0;
	private:
		std::shared_ptr<Window> m_Window; // Stores a pointer to the window
		bool m_IsRunning = true;          // Keeping track if the application is still running

	private:
		static Application* s_Instance;   // Stores the ONLY instance of the application
	};

	Application* CreateApplication();     // Function to create the application instance, it MUST be defined in the client
}