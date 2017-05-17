#pragma once
#include "TreeOfLife.h"

#define tree_pixels TreeOfLife_pixels

struct vec3f
{
	union
	{
		float coord[3];
		struct
		{
			float x, y, z;
		};
	};
};

struct vec4f
{
	union
	{
		float coord[4];
		struct
		{
			float x, y, z, w;
		};
	};
};

//struct with vec4f and color
struct vertex
{
	vec4f point;
	float U;
	float V;
	unsigned int color;
};

struct matrix3
{
	union
	{
		float members[9];
		struct
		{
			float Xx, Xy, Xz;
			float Yx, Yy, Yz;
			float Zx, Zy, Zz;
		};
	};
};

struct matrix4
{
	union
	{
		float members[16];
		float twoD[4][4];
		struct
		{
			float Xx, Xy, Xz, Xt;
			float Yx, Yy, Yz, Yt;
			float Zx, Zy, Zz, Zt;
			float Tx, Ty, Tz, Tt;
		};
	};
};

#define REZ_X 750
#define REZ_Y 500

#define RADS 0.01745329251994329576923690768489

unsigned int colorArray[REZ_X * REZ_Y];
float zBuffer[REZ_X * REZ_Y];

//cube to create
struct cube
{
	union
	{
		vertex members[8];
		struct
		{
			//front top
			vertex v1, v2;
			//front bottom
			vertex v3, v4;

			//back top
			vertex v5, v6;
			//back bottom
			vertex v7, v8;
		};
	};
};

cube original;

vertex gridTop[11];
vertex gridLeft[11];
vertex gridBottom[11];
vertex gridRight[11];