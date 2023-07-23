// Auther: Bavley Danial
// Date: 7/11/2023
//
// TDE - The Dunn Engine

#include <DunnEngine.h>

using namespace DunnEngine;

class Sandbox : public DunnEngine::Application
{
public:
	sf::Sound soundPlayer;	// Should be managed by engine in future versions. Will result in a warning for now due to lack of destruction

	Time soundTimer;		// Used to show examples on using Time in this version
	Time clickTimer;		// Used to show examples on using Time in this version

	glm::vec2 spritePos;	// Used to show examples on drawing a Sprite in this version
	float spriteRot;		// Used to show examples on drawing a Sprite in this version
	glm::vec2 spriteScale;	// Used to show examples on drawing a Sprite in this version

	glm::vec2 textPos;		// Used to show examples on drawing a Text in this version
	float textRot;			// Used to show examples on drawing a Text in this version
	glm::vec2 textScale;	// Used to show examples on drawing a Text in this version
public:
	void OnInit() override
	{
		LOG_INFO("Initialized sandbox successfully!");
		
		// Testing stuff
		{
			// Window
			Window::Create("Hello!", 1280, 720, false, true); // This is how you create a window. Here are the list of current arguments: Title, window width, window height, fullscreen, vsync.
			int width = Window::GetWidth();					  // This is how you get the width of the screen if you need it.
			int height = Window::GetHeight();				  // This is how you get the height of the screen if you need it.
			bool isFullscreenOn = Window::IsFullScreen();	  // This is how you get if the window is in windowed or fullscreen mode.
			bool isVSyncOn = Window::IsVSync();				  // This is how you check if vsync is on or off.
			Window::SetFullScreen(false);					  // This sets fullscreen on or off. The parameter is true for fullscreen or false for windowed mode.
			Window::SetVSync(true);							  // This sets vsync on or off. The parameter is true for fullscreen or false for windowed mode.
			// Other functions found in Window Should NOT be called from the client application unless you have a specific reason to do so.

			// Logging
			LOG_TRACE("This is a trace! You can use it if you want to trace a variable or something in the console. You can also use it as a normal message since it is colored white");
			LOG_INFO("This is an info! You can use it if you want to give yourself some information in the console");
			LOG_WARN("This is a warning! You can use it if you want to show that something is possibly wrong in the console");
			LOG_ERROR("This is an error! You can use it if you want to show that something is wrong in the console");
			LOG_INFO("You can print variables by writing {index of argument} and a comma after the quotes. Like this next line");
			LOG_TRACE("Window Width: {0} || Window Height: {1}", Window::GetWidth(), Window::GetHeight());
			// DE_ASSERT(false, "if the condition is false this will trigger the application to break at this line and will print the message provided here as an error. Be careful because this is only intended for use in the debug configuration. In release configuration this line will be DELETED automatically");

			// Input
			Input::GetMousePosition();					 // Returns the mouse position in a 2D vector form. See the Math section for more info on vectors and math
			Input::SetMousePoisiton(0, 0);				 // Sets the mouse position to the coordinates 0, 0
			Input::IsKeyPressed(TDE_KEY_A);				 // Returns true if the key has been pressed. or false if it was not. All keycodes can be found in the file KeyCodes.h and follow a consistant naming scheme
			Input::IsMouseButtonPressed(TDE_MOUSE_LEFT); // Returns true if the button has been pressed. or false if it was not. All mousecodes can be found in the file MouseButtonCodes.h and follow a consistant naming scheme

			// Resource management
			ResourceManager::LoadTexture("TestTexture", "Resources/TestTexture.png"); // This is how to load a texture. The arguments are as follows: the name of the texture inside the memory, the path to the file relative to DunnSandbox folder 
			ResourceManager::LoadSound("TestSound", "Resources/TestAudio.wav");		  // This is how to load a sound. The arguments are as follows: the name of the sound inside the memory, the path to the file relative to DunnSandbox folder
			ResourceManager::LoadFont("TestFont", "Resources/TestFont.ttf");		  // This is how to load a font. The arguments are as follows: the name of the font inside the memory, the path to the file relative to DunnSandbox folder
			// All the load functions should be used in OnInit() not OnUpdate() as it sorts the buffer every time it is used which slows the program down. If you must use it in OnUpdate just be aware of the performance consequence.
			// Tested formats so far: .png for textures, .wav for sounds, .ttf for fonts
			DE_Texture* texture = ResourceManager::GetTexture("TestTexture");		  // Gets the pointer to a texture. This takes in a name of the texture you previously loaded. If it is not able to find it, it will return a nullptr
			DE_Sound* sound = ResourceManager::GetSound("TestSound");				  // Gets the pointer to a sound. This takes in a name of the sound you previously loaded. If it is not able to find it, it will return a nullptr
			DE_Font* font = ResourceManager::GetFont("TestFont");					  // Gets the pointer to a font. This takes in a name of the font you previously loaded. If it is not able to find it, it will return a nullptr
			// There are also delete functions like:
			// ResourceManager::DeleteTexture("TestTexture");		// Deletes the texture with this name. Will print an error when no texture found.
			// ResourceManager::DeleteSound("TestSound");			// Deletes the sound with this name. Will print an error when no sound found.
			// ResourceManager::DeleteFont("TestFont");				// Deletes the font with this name. Will print an error when no font found.
			// ResourceManager::DeleteAllResources();				// Deletes all resources.

			spritePos = glm::vec2(Window::GetWidth() / 2, Window::GetHeight() / 2);
			spriteScale = glm::vec2(1);
			spriteRot = 0;

			textPos = glm::vec2(Window::GetWidth() / 2, (Window::GetHeight() / 2) - (Window::GetHeight() / 3));
			textScale = glm::vec2(1);
			textRot = 0;

			// Math
			// For now there is no built in math functions. You can use glm to use math. See the glm documentation here https://glm.g-truc.net/0.9.9/api/index.html
		}
	}

	void OnUpdate() override
	{
		// Example for displaying sprites on screen in this version
		DE_Texture* texture = ResourceManager::GetTexture("TestTexture");
		Graphics::DrawSprite(texture, spritePos, spriteRot, spriteScale);
		if (Input::IsKeyPressed(TDE_KEY_W))
			spritePos.y += 300 * Time::GetDeltaTime().asSeconds();
		if (Input::IsKeyPressed(TDE_KEY_S))
			spritePos.y -= 300 * Time::GetDeltaTime().asSeconds();
		if (Input::IsKeyPressed(TDE_KEY_D))
			spritePos.x += 300 * Time::GetDeltaTime().asSeconds();
		if (Input::IsKeyPressed(TDE_KEY_A))
			spritePos.x -= 300 * Time::GetDeltaTime().asSeconds();

		if (Input::IsKeyPressed(TDE_KEY_E))
			spriteRot += 10 * Time::GetDeltaTime().asSeconds();
		if (Input::IsKeyPressed(TDE_KEY_Q))
			spriteRot -= 10 * Time::GetDeltaTime().asSeconds();

		// Example for displaying a text in this version
		DE_Font* font = ResourceManager::GetFont("TestFont");
		Text text;
		text.SetFont(font, 50);
		text.SetString("Hello, world!");
		Graphics::Print(text, textPos, textRot, textScale);

		// Example for playing sound in this version
		DE_Sound* sound = ResourceManager::GetSound("TestSound");
		if (!soundPlayer.getBuffer())
			soundPlayer.setBuffer(*sound->Sound);
		
		if (Input::IsKeyPressed(TDE_KEY_F) && soundTimer.GetTime().asMilliseconds() <= 0)
		{
			soundPlayer.play();
			soundTimer = soundPlayer.getBuffer()->getDuration(); // Add delay that is equal to the length of the track. Should be managed by engine side
		}
		else
		{
			soundTimer -= Time::GetDeltaTime();
		}

		// Example for logging something
		if (Input::IsMouseButtonPressed(TDE_MOUSE_LEFT) && clickTimer.GetTime().asMicroseconds() <= 0)
		{
			LOG_INFO("Left Clicked!");
			clickTimer.SetTime(1);
		}
		else
		{
			clickTimer -= Time::GetDeltaTime();
		}

		Graphics::DrawCircle(glm::vec2(Window::GetWidth() / 2, Window::GetHeight() / 2), glm::vec2(100), glm::vec4(0, 0, 255, 255));
		Graphics::DrawQuad(glm::vec2(Window::GetWidth() / 4, Window::GetHeight() / 2), 35, glm::vec2(50), glm::vec4(255, 0, 0, 255));
		Graphics::DrawTriangle(glm::vec2(Window::GetWidth() - Window::GetWidth() / 4, Window::GetHeight() / 2), 35, glm::vec2(50), glm::vec4(0, 255, 0, 255));
	}

	void OnKeyEvent() override
	{
		
	}

	void OnMouseEvent() override
	{

	}
};

DunnEngine::Application* DunnEngine::CreateApplication()
{
	return new Sandbox();
}