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


/*
	This file includes mouse codes that corespond to the mouse
	codes found in SFML.
	Probably better in the future to make an internal mouse codes conventions to
	be able to make it cross compatible with other libraries.
*/

// Mouse button definitions
#define TDE_MOUSE_LEFT 0
#define TDE_MOUSE_RIGHT 1
#define TDE_MOUSE_MIDDLE 2    
#define TDE_MOUSE_BUTTON1 3  
#define TDE_MOUSE_BUTTON2 4

// Mouse wheel definitions
#define TDE_MOUSE_VWHEEL 0
#define TDE_MOUSE_HWHEEL 1