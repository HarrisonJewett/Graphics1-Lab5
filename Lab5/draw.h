#pragma once
#include "RasterSurface.h"
#include "shader.h"
#include <iostream>
#include <algorithm>
using namespace std;


void parametricAlgorithm(vertex v1, vertex v2);
unsigned int interpColors(unsigned int sourceColor, unsigned int desColor, float ratio);
void drawToRaster(int x, int y, float z, unsigned int color);
void clearBuffer(unsigned int color);
void drawLine(const vertex& v1, const vertex& v2);
void colorTriangle(vec4f v1, vec4f v2, vec4f v3, unsigned int color);


void parametricAlgorithm(vertex v1, vertex v2)
{
	int x1 = convertNDCX(v1.point.x);
	int x2 = convertNDCX(v2.point.x);
	int y1 = convertNDCY(v1.point.y);
	int y2 = convertNDCY(v2.point.y);

	int deltaX = abs(x2 - x1);
	int deltaY = abs(y2 - y1);
	int longest = (deltaX > deltaY) ? deltaX : deltaY;

	for (int i = 0; i < longest; ++i)
	{
		float ratio = i / (float)longest;
		int currX = (int)((x2 - x1) * ratio + x1);
		int currY = (int)((y2 - y1) * ratio + y1);
		float currZ = (v2.point.z - v1.point.z)*ratio + v1.point.z;
		unsigned int c = interpColors(v1.color, v2.color, ratio);
		if (PixelShader)
			PixelShader(c);
		drawToRaster(currX, currY, currZ, c);
	}
}

unsigned int interpColors(unsigned int sourceColor, unsigned int desColor, float ratio)
{
	//(b - a)*r + a
	//Might need to add A to this


	//ARGB
	int r = (sourceColor & 0x00FF0000) >> 16;
	int g = (sourceColor & 0x0000FF00) >> 8;
	int b = (sourceColor & 0x000000FF);

	int newR = (desColor & 0x00FF0000) >> 16;
	int newG = (desColor & 0x0000FF00) >> 8;
	int newB = (desColor & 0x000000FF);

	int finalR = (int)((newR - r) * (ratio)+r);
	int finalG = (int)((newG - g) * (ratio)+g);
	int finalB = (int)((newB - b) * (ratio)+b);

	return((finalR << 16) | (finalG << 8) | finalB);
}

void drawToRaster(int x, int y, float z, unsigned int color)
{
	if (x > REZ_X || y > REZ_Y) {}
	else
	{
		unsigned int c = convertCoor(x, y);
		if (z < zBuffer[c])
		{
			zBuffer[c] = z;
			colorArray[convertCoor(x, y)] = color;
		}
	}
}

void clearBuffer(unsigned int color)
{
	for (unsigned int i = 0; i < (REZ_X * REZ_Y); ++i)
	{
		colorArray[i] = color;
		zBuffer[i] = 1.0f;
	}
}

void drawLine(const vertex& v1, const vertex& v2)
{
	vertex temp1 = v1;
	vertex temp2 = v2;

	if (VertexShader)
	{
		VertexShader(temp1.point);
		VertexShader(temp2.point);
	}
	parametricAlgorithm(temp1, temp2);
}

void colorTriangle(vec4f v1, vec4f v2, vec4f v3, unsigned int color)
{
	vec4f temp1 = v1;
	vec4f temp2 = v2;
	vec4f temp3 = v3;

	if (VertexShader)
	{
		VertexShader(temp1);
		VertexShader(temp2);
		VertexShader(temp3);
	}

	unsigned int x1 = convertNDCX(temp1.x);
	unsigned int x2 = convertNDCX(temp2.x);
	unsigned int x3 = convertNDCX(temp3.x); 
	unsigned int y1 = convertNDCY(temp1.y);
	unsigned int y2 = convertNDCY(temp2.y);
	unsigned int y3 = convertNDCY(temp3.y);

	int startX = std::min(std::min(x1, x2), x3);
	int endX = std::max(std::max(x1, x2), x3);
	int startY = std::min(std::min(y1, y2), y3);
	int endY = std::max(std::max(y1, y2), y3);
	
	

	for (int i = startY; i < endY; ++i)
	{
		for (int j = startX; j < endX; ++j)
		{
			if (barycentricCheck(x1, y1, x2, y2, x3, y3, j, i))
			{
				drawToRaster(j, i, barycentric(temp1, temp2, temp3, j, i), color);
			}
		}
	}
}