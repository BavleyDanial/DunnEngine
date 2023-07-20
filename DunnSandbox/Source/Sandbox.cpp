// Auther: Bavley Danial
// Date: 7/11/2023
//
// TDE - The Dunn Engine

#include <DunnEngine.h>

using namespace DunnEngine;

class Sandbox : public DunnEngine::Application
{
public:
	sf::Time soundTimer;
	sf::Time clickTimer;
	sf::Time dt;			// Delta time. Should be managed by engine in future versions
	sf::Clock clock;		// Should be managed by engine in future versions
	sf::Sound soundPlayer;	// Should be managed by engine in future versions. Will result in a warning for now due to lack of destruction
	bool isDone = true;
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

			// Math
			// For now there is no built in math functions. You can use glm to use math. See the glm documentation here https://glm.g-truc.net/0.9.9/api/index.html
		}
	}

	void OnUpdate() override
	{
		// Example for displaying sprites on screen in this version
		DE_Texture* texture = ResourceManager::GetTexture("TestTexture");
		sf::Sprite sprite;
		sprite.setTexture(texture->Texture);
		sprite.setOrigin(texture->Texture.getSize().x / 2, texture->Texture.getSize().y / 2); // This is done because sfml by default uses the top left of a sprite as the origin not the center of the sprite.
		sprite.setPosition(Window::GetWidth() / 2, Window::GetHeight() / 2); // The position is relative to the top left of the window, meaning the coordinates of the top left is (0, 0) and buttom right is (window.width, window.height)
		Window::GetSFMLWindow()->draw(sprite);

		// Example for playing sound in this version
		DE_Sound* sound = ResourceManager::GetSound("TestSound");
		if (!soundPlayer.getBuffer())
			soundPlayer.setBuffer(sound->Sound);

		if (Input::IsKeyPressed(TDE_KEY_F) && soundTimer.asMilliseconds() <= 0)
		{
			soundPlayer.play();
			soundTimer = soundPlayer.getBuffer()->getDuration() + sf::seconds(0.5); // Add delay that is equal to the length of the track + 0.5 seconds
																					// The delay of the length of the track should be managed by the engine side
		}
		else
		{
			soundTimer -= dt;
		}

		// Example for logging something
		if (Input::IsMouseButtonPressed(TDE_MOUSE_LEFT) && clickTimer.asMilliseconds() <= 0)
		{
			clickTimer = sf::seconds(1);
			LOG_INFO("Left Clicked!");
		}
		else
		{
			clickTimer -= dt;
		}

		// Example for displaying text on screen in this version
		DE_Font* font = ResourceManager::GetFont("TestFont");
		sf::Text text;
		font->Font.setSmooth(false); // disable any smoothing algorithms for the crisp retro font
		text.setFont(font->Font);
		text.setCharacterSize(50);   // set font size
		text.setString("Hello, world!");
		text.setOrigin(text.getLocalBounds().getSize().x / 2, text.getLocalBounds().getSize().y / 2);
		text.setPosition(Window::GetWidth() / 2, (Window::GetHeight() / 2) - (Window::GetHeight() / 3)); // set position to the upper middle position
		Window::GetSFMLWindow()->draw(text);

		dt = clock.restart(); // should be managed by engine

		// Example for displaying sprites on screen in the future versions
		// DE_Texture* texture = ResourceManager::GetTexture("TestTexture");
		// Graphics::DrawSprite(texture, position, rotation, scale, color(optional), maybe other stuff that will be optional);
		// 
		// Example for playing sounds in the future versions
		// DE_Sound* sound = ResourceManager::GetSound("TestSound");
		// if (Input::IsKeyPressed(TDE_KEY_F) && soundTimer.asMilliseconds() <= 0) // soundTimer will be a DE::Time object
		// {
		// 	soundPlayer.play();
		// 	soundTimer = Time::Seconds(0.5); // Add 0.5 seconds
		// }
		// else
		// {
		// 	soundTimer -= dt;
		// }
		//
		// Example for displaying texts in the future versions
		// DE_Font* font = ResourceManager::GetFont("TestFont");
		// DE::Text text;
		// text.SetFont(font, size);
		// text.SetString("Hello, world!");
		// Graphics::DrawText(text, position, rotation, scale, color,(optional), and maybe other stuff that will be optional);
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