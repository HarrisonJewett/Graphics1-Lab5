#pragma once
#include "mathEquations.h"

// The active vertex shader. Modifies an incoming vertex. Pre-Rasterization. 
void(*VertexShader)(vec4f&) = 0;
// The active pixel shader. Modifies an outgoing pixel. Post-Rasterization.
void(*PixelShader)(unsigned int&) = 0;

// All Shader Variables (Always Pre-fixed by “SV_”)
matrix4 SV_WorldMatrix;
matrix4 SV_ViewMatrix;
matrix4 SV_PerspectiveMatrix;

// Various custom vertex and pixel shaders, (Pre-fixed by “VS_” & “PS_”)
// Can be swapped using above function pointers as needed for flexibility. 

// Applys the current world matrix to all
void VS_World(vec4f &multiplyMe)
{

	multiplyMe = vec4Matrix4Mult(multiplyMe, SV_WorldMatrix);
	multiplyMe = vec4Matrix4Mult(multiplyMe, SV_ViewMatrix);
	multiplyMe = vec4Matrix4Mult(multiplyMe, SV_PerspectiveMatrix);
	
	multiplyMe.x /= multiplyMe.w;
	multiplyMe.y /= multiplyMe.w;
	multiplyMe.z /= multiplyMe.w;
}
// Basic pixel shader returns the color white
void PS_White(unsigned int &makeWhite)
{
	makeWhite = 0xFFFFFFFF;
}

// Basic pixel shader returns the color white
void PS_Green(unsigned int &makeWhite)
{
	makeWhite = 0xFF00FF00;
}

void PS_Yellow(unsigned int &makeWhite)
{
	makeWhite = 0xFFFFFF00;
}