# DunnEngine
A 2D game engine made for DunnGames
It is designed to run at 60+ FPS and the scripting language is C++ 17

# Installaion
- Clone the git repository by typing this command in the terminal
```git clone --recursive https://github.com/BavleyDanial/TDE.git```<br/> (Note: The path where you install the project MUST have no spaces for the project to run)
- Then run the GenerateProjects.bat file, this will create a visual studio 2022 solution.
- If you have an older version of visual studio you can edit the GenerateProjects.bat file to run vs(version name).<br/>
  (2022 is the only version that has been tested but it should work on older visual studio versions and other IDEs).
- If you have a different IDE that you want to use you can edit the GenerateProjects.bat to run a different IDE, more info on how to do so is here https://premake.github.io/docs/using-premake.<br/>
  (2022 is the only version that has been tested but it should work on older visual studio versions and other IDEs).
- You can change the DunnSandbox project name to the name of the game you are developing by editing the premake5.lua file and change all instances of DunnSandbox to your game's name.
### Now you can build and develop your games!

 # Documentation
   ## Window Class:
   ```Window::Create(const std::string& title, uint32_t width, uint32_t height, bool fullScreen, bool vSync)```: This function creates a window with the provided data. Vsync currently does not work when used directly here, look at SetVSync for this functionality.<br/>
   
   ```Window::SetWidth(uint32_t width)```: Sets the window width to the specified data.<br/>
   ```Window::SetHeight(uint32_t height)```: Sets the window height to the specified data. <br/>
   ```Window::Resize(uint32_t width, uint32_t height)```: Sets the window width and height to the specified data.<br/>
   
   ```Window::GetWidth()```: Gets the current window's width (returns an int).<br/>
   ```Window::GetHeight()```: Gets the current window's height (returns an int).<br/>

  ```Window::SetVSync(bool enabled)```: Sets vsync to true or false.<br/>
  ```Window::IsVSync()```: Gets the status of vsync (returns true or false)<br/>
  ```Window::SetFullScreen(bool enabled)```: Sets fullscreen to true or false.<br/>
  ```Window::IsFullScreen()```: Gets the status of fullscreen (returns true or false).<br/>

  ## Logger class:
   ```LOG_INFO("Info! {0}", a)```: This is how you log an info message in the terminal. You can use a , after the string and put any variable you want. To use this variable use a placeholder {0} in the string where the number represents the argument number.<br/>
   ```LOG_TRACE("Trace! {0}", a)```: This is how you log a trace message in the terminal. You can use a , after the string and put any variable you want. To use this variable use a placeholder {0} in the string where the number represents the argument number.<br/>
   ```LOG_WARN("Warn! {0}", a)```: This is how you log a warn message in the terminal. You can use a , after the string and put any variable you want. To use this variable use a placeholder {0} in the string where the number represents the argument number.<br/>
   ```LOG_ERROR("Error! {0}", a)```: This is how you log an error message in the terminal. You can use a , after the string and put any variable you want. To use this variable use a placeholder {0} in the string where the number represents the argument number.<br/>
   
  ## ResourceManager class
  
  There are 3 resource types. DE_Texture, DE_Sound, DE_Font
  
  ```LoadTexture(const std::string& name, const std::string& path)```: This is how you load a texture in memory, you provide a custom name for this texture as well as its path. You will be using the custom name later on for deletion.<br/> 
  ```LoadFont(const std::string& name, const std::string& path)```: This is how you load a font in memory,  you provide a custom name for this font as well as its path. You will be using the custom name later on for deletion.<br/>
  ```LoadSound(const std::string& name, const std::string& path)```: This is how you load a sound in memory,  you provide a custom name for this sound as well as its path. You will be using the custom name later on for deletion.<br/>

  ```GetTexture(const std::string& name)```: This is how you get a texture that was previously loaded. (This returns a DE_Texture*).<br/>
  ```GetFont(const std::string& name)```: This is how you get a font that was previously loaded. (This returns a DE_Font*).<br/>
  ```GetSound(const std::string& name)```: This is how you get a sound that was previously loaded. (This returns a DE_Sound*).<br/>

  ```DeleteTexture(const std::string& name)```: This is how you delete a texture that was previously loaded.<br/>
  ```DeleteFont(const std::string& name)```: This is how you delete a font that was previously loaded.<br/>
  ```DeleteSound(const std::string& name)```: This is how you delete a sound that was previously loaded.<br/>
  ```DeleteAllResources()```: This is how you delete all resources.<br/>

  ## Text class
  ```Text(const std::string& textString)```: This is how you create a text object. You will use this to render texts on screen. You do not need to provide a string if you don't need it now but you MUST provide a string if you want to see something on screen.<br/>
  ```SetString(const std::string& textString)```: This sets the text object's string to the value you provide.<br/>
  
  ```SetFont(DE_Font* font, uint32_t fontSize)```: This is how you set a font to the text. For now you MUST provide any font. There is no default option. The font size is set by default to 30 but you can change it however you want.<br/>
  ```SetFontSize(uint32_t fontSize)```: This is how you set the font size to the provided value.<br/>
  
  ```SetStyle(FontStyle fontStyle)```: This is how you set the font style. There is regular, bold, italic, underline, and strikethrough.<br/>
  ```SetSmoothing(bool enabled)```: Sets the smoothing on the texts to true or false. disable for most crisp retro texts.<br/>

  ## Graphics class
  ```DrawQuad(const glm::vec2& position, float rotationAngle, const glm::vec2& scale, const glm::vec4& color)```: Renders a square (or rectangle depending on the scale) with the specified data. rotation is anti-clockwise and scale should be 1 if no scaling is required.<br/>
  ```DrawCircle(const glm::vec2& position, const glm::vec2& scale, const glm::vec4& color)```: Renders a circle (or ellipse) ith the specified data. scale should be 1 if no scaling is required.<br/>
  ```DrawTriangle(const glm::vec2& position, float rotationAngle, const glm::vec2& scale, const glm::vec4& color)```: Renders a triangle with the specified data. rotation is anti-clockwise and scale should be 1 if no scaling is required.<br/>
  ```DrawSprite(DE_Texture* texture, const glm::vec2& position, float rotationAngle, const glm::vec2& scaler)```: Renders a sprite (with a texture that was loaded previously) with the specified data. rotation is anti-clockwise and scale should be 1 if no scaling is required.<br/>
  ```Print(Text& text, const glm::vec2& position, float rotationAngle, const glm::vec2& scale)```: Renders a text with the specified data. rotation is anti-clockwise and scale should be 1 if no scaling is required.<br/>

  ## AudioPlayer class
  ```SetSound(DE_Sound* sound)```: Set the sound to be played by this AudioPlayer object.<br/>
  ```Play()```: Plays the sound that was set before.<br/>
  ```Pause()```: Pauses the sound that was playing before. <br/>
  ```Stop()```: Stops the sound that was playing before.<br/>
  ```SetLoop(bool enabled)```: Enables looping to true or false. By enabling it the sound will play over and over again non-stop.<br/>

# To-Do list
- Adding a logging functionality
- Fixing ASSERTs
- Setting graphics commands
- Adding a resource manager
- Adding inputs
- Adding math
