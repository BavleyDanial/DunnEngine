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


#include <DunnEngine.h>

using namespace DunnEngine;

class Sandbox : public DunnEngine::Application
{
public:
	void OnInit() override
	{
		LOG_INFO("Initialized sandbox successfully!");
	}

	void OnUpdate() override
	{
		// move it to show test
		//LOG_INFO("MouseX: {0}, MouseY: {1}", Input::GetMousePosition().first, Input::GetMousePosition().second);

		if (Input::IsMouseButtonPressed(TDE_MOUSE_LEFT))
		{
			LOG_INFO("Left mouse button pressed!");
		}
	}

	void OnKeyEvent() override
	{

	}

	void OnMouseEvent() override
	{

	}

private:

};

DunnEngine::Application* DunnEngine::CreateApplication()
{
	return new Sandbox();
}