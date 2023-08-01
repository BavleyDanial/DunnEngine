#pragma once

// Auther: Bavley Danial
// Date: 7/11/2023
//
// TDE - The Dunn Engine
//

/// <summary>
/// 
/// This file includes everything that the client project needs to use the engine.
/// It should NEVER be included in the engine hence the location of the file outside of all other folders.
/// 
/// </summary>

// Core:
#include "Core/Application.h"
#include "Core/Logger.h"
#include "Core/ResourceManager.h"
#include "Core/AudioPlayer.h"
#include "Core/Time.h"

// Graphics:
#include "Graphics/Graphics.h"
#include "Graphics/Text.h"
#include "Graphics/Window.h"

// Input:
#include "Input/Input.h"
#include "Input/KeyCodes.h"
#include "Input/MouseButtonCodes.h"

// Math
#include <glm/glm.hpp>
