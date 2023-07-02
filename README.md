# DunnEngine
A 2D game engine made for DunnGames
It is designed to run at 60+ FPS and the scripting language is C++ 17

# Installaion
- Clone the git repository by typing this command in the terminal
```git clone --recursive https://github.com/BavleyDanial/TDE.git```
- Then run the GenerateProjects.bat file, this will create a visual studio 2022 solution.
- If you have an older version of visual studio you can edit the GenerateProjects.bat file to run vs(version name).<br/>
  (2022 is the only version that has been tested but it should work on older visual studio versions and other IDEs).
- If you have a different IDE that you want to use you can edit the GenerateProjects.bat to run a different IDE, more info on how to do so is here https://premake.github.io/docs/using-premake.<br/>
  (2022 is the only version that has been tested but it should work on older visual studio versions and other IDEs).
- You can change the DunnSandbox project name to the name of the game you are developing by editing the premake5.lua file and change all instances of DunnSandbox to your game's name.
### Now you can build and develop your games!

 # Documentation
 ## TBD

# To-Do list
- Adding a logging functionality
- Fixing ASSERTs
- Setting graphics commands
- Adding a resource manager
- Adding inputs
- Adding math
