#pragma once
#include <math.h>
#include "includes.h"

float bcZ(float f1, float f2, float f3, vec3f ratio);


vec3f vec3Matrix3Mult(vec3f v1, matrix3 m1)
{
	vec3f temp;

	temp.x = ((v1.x * m1.Xx) + (v1.y * m1.Yx) + (v1.z * m1.Zx));
	temp.y = ((v1.x * m1.Xy) + (v1.y * m1.Yy) + (v1.z * m1.Zy));
	temp.z = ((v1.x * m1.Xz) + (v1.y * m1.Yz) + (v1.z * m1.Zz));

	return temp;
}

vec4f vec4Matrix4Mult(vec4f v1, matrix4 m1)
{
	vec4f temp;

	temp.x = ((v1.x * m1.Xx) + (v1.y * m1.Yx) + (v1.z * m1.Zx) + (v1.w * m1.Tx));
	temp.y = ((v1.x * m1.Xy) + (v1.y * m1.Yy) + (v1.z * m1.Zy) + (v1.w * m1.Ty));
	temp.z = ((v1.x * m1.Xz) + (v1.y * m1.Yz) + (v1.z * m1.Zz) + (v1.w * m1.Tz));
	temp.w = ((v1.x * m1.Xt) + (v1.y * m1.Yt) + (v1.z * m1.Zt) + (v1.w * m1.Tt));

	return temp;
}

matrix4 identiyMatrix()
{
	matrix4 temp;
	for (unsigned int i = 0; i < 4; i++)
	{
		for (unsigned int j = 0; j < 4; j++)
		{
			temp.twoD[i][j] = 0;
		}
	}

	for (unsigned int i = 0; i < 4; i++)
	{
		for (unsigned int j = 0; j < 4; j++)
		{
			if (j == i)
			{
				temp.twoD[i][j] = 1;
			}
		}
	}
	return temp;
}

matrix3 matrix3Multiply(matrix3 m1, matrix3 m2)
{
	matrix3 temp;

	temp.Xx = ((m1.Xx * m2.Xx) + (m1.Xy * m2.Yx) + (m1.Xz * m2.Zx));
	temp.Xy = ((m1.Xx * m2.Xy) + (m1.Xy * m2.Yy) + (m1.Xz * m2.Zy));
	temp.Xz = ((m1.Xx * m2.Xz) + (m1.Xy * m2.Yz) + (m1.Xz * m2.Zz));

	temp.Yx = ((m1.Yx * m2.Xx) + (m1.Yy * m2.Yx) + (m1.Yz * m2.Zx));
	temp.Yy = ((m1.Yx * m2.Xy) + (m1.Yy * m2.Yy) + (m1.Yz * m2.Zy));
	temp.Yz = ((m1.Yx * m2.Xz) + (m1.Yy * m2.Yz) + (m1.Yz * m2.Zz));

	temp.Zx = ((m1.Zx * m2.Xx) + (m1.Zy * m2.Yx) + (m1.Zz * m2.Zx));
	temp.Zy = ((m1.Zx * m2.Xy) + (m1.Zy * m2.Yy) + (m1.Zz * m2.Zy));
	temp.Zz = ((m1.Zx * m2.Xz) + (m1.Zy * m2.Yz) + (m1.Zz * m2.Zz));

	return temp;
}

matrix4 matrix4Multiply(matrix4 m1, matrix4 m2)
{
	matrix4 temp;

	temp.Xx = ((m1.Xx * m2.Xx) + (m1.Xy * m2.Yx) + (m1.Xz * m2.Zx) + (m1.Xt * m2.Tx));
	temp.Xy = ((m1.Xx * m2.Xy) + (m1.Xy * m2.Yy) + (m1.Xz * m2.Zy) + (m1.Xt * m2.Ty));
	temp.Xz = ((m1.Xx * m2.Xz) + (m1.Xy * m2.Yz) + (m1.Xz * m2.Zz) + (m1.Xt * m2.Tz));
	temp.Xt = ((m1.Xx * m2.Xt) + (m1.Xy * m2.Yt) + (m1.Xz * m2.Zt) + (m1.Xt * m2.Tt));

	temp.Yx = ((m1.Yx * m2.Xx) + (m1.Yy * m2.Yx) + (m1.Yz * m2.Zx) + (m1.Yt * m2.Tx));
	temp.Yy = ((m1.Yx * m2.Xy) + (m1.Yy * m2.Yy) + (m1.Yz * m2.Zy) + (m1.Yt * m2.Ty));
	temp.Yz = ((m1.Yx * m2.Xz) + (m1.Yy * m2.Yz) + (m1.Yz * m2.Zz) + (m1.Yt * m2.Tz));
	temp.Yt = ((m1.Yx * m2.Xt) + (m1.Yy * m2.Yt) + (m1.Yz * m2.Zt) + (m1.Yt * m2.Tt));

	temp.Zx = ((m1.Zx * m2.Xx) + (m1.Zy * m2.Yx) + (m1.Zz * m2.Zx) + (m1.Zt * m2.Tx));
	temp.Zy = ((m1.Zx * m2.Xy) + (m1.Zy * m2.Yy) + (m1.Zz * m2.Zy) + (m1.Zt * m2.Ty));
	temp.Zz = ((m1.Zx * m2.Xz) + (m1.Zy * m2.Yz) + (m1.Zz * m2.Zz) + (m1.Zt * m2.Tz));
	temp.Zt = ((m1.Zx * m2.Xt) + (m1.Zy * m2.Yt) + (m1.Zz * m2.Zt) + (m1.Zt * m2.Tt));

	temp.Tx = ((m1.Tx * m2.Xx) + (m1.Ty * m2.Yx) + (m1.Tz * m2.Zx) + (m1.Tt * m2.Tx));
	temp.Ty = ((m1.Tx * m2.Xy) + (m1.Ty * m2.Yy) + (m1.Tz * m2.Zy) + (m1.Tt * m2.Ty));
	temp.Tz = ((m1.Tx * m2.Xz) + (m1.Ty * m2.Yz) + (m1.Tz * m2.Zz) + (m1.Tt * m2.Tz));
	temp.Tt = ((m1.Tx * m2.Xt) + (m1.Ty * m2.Yt) + (m1.Tz * m2.Zt) + (m1.Tt * m2.Tt));

	return temp;
}

matrix4 matrix4Inverse(matrix4 m1)
{
	matrix4 inverse;
	matrix3 transpose;
	vec3f temp;

	transpose = {
		m1.Xx, m1.Yx, m1.Zx,
		m1.Xy, m1.Yy, m1.Zy,
		m1.Xz, m1.Yz, m1.Zz
	};

	temp = { m1.Tx, m1.Ty, m1.Tz };

	temp = vec3Matrix3Mult(temp, transpose);

	temp.x *= -1;
	temp.y *= -1;
	temp.z *= -1;

	inverse = {
		m1.Xx, m1.Yx, m1.Zx, 0,
		m1.Xy, m1.Yy, m1.Zy, 0,
		m1.Xz, m1.Yz, m1.Zz, 0,
		temp.x, temp.y, temp.z, 1
	};

	return inverse;
}

matrix3 matrix3Xrot(float t)
{
	matrix3 temp;

	temp = {
		1, 0, 0,
		0, (float)cos(t), (-1 * (float)sin(t)),
		0, (float)sin(t), (float)cos(t)
	};

	return temp;
}

matrix3 matrix3Yrot(float t)
{
	matrix3 temp;

	temp = {
		(float)cos(t), 0, (float)sin(t),
		0, 1, 0,
		-1 * (float)sin(t), 0, (float)cos(t)
	};

	return temp;
}

matrix3 matrix3Zrot(float t)
{
	matrix3 temp;

	temp = {
		 (float)cos(t), (-1 * (float)sin(t)), 0,
		 (float)sin(t), (float)cos(t), 0,
		0, 0, 1
	};

	return temp;
}

matrix4 matrix4Xrot(float t)
{
	matrix4 temp;

	temp = {
		1, 0, 0, 0,
		0, (float)cos(t), (-1 * (float)sin(t)), 0,
		0, (float)sin(t), (float)cos(t), 0,
		0, 0, 0, 1
	};

	return temp;
}

matrix4 matrix4Yrot(float t)
{
	matrix4 temp;

	temp = {
		(float)cos(t), 0, (float)sin(t), 0,
		0, 1, 0, 0,
		-1 * (float)sin(t), 0, (float)cos(t), 0,
		0, 0, 0, 1
	};

	return temp;
}

matrix4 matrix4Zrot(float t)
{
	matrix4 temp;

	temp = {
		(float)cos(t), (-1 * (float)sin(t)), 0, 0,
		(float)sin(t), (float)cos(t), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	return temp;
}

matrix4 matrix4trans(vec3f v1)
{
	matrix4 temp = {
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		v1.x, v1.y, v1.z, 0
	};

	return temp;
}

matrix4 perspectiveMatrix(float fov, float aspect, float near, float far)
{
	float rad = (float)(fov * RADS) / 2.0f;
	
	float t = (float)tan(rad);
	float yScale = 1.0f / (float)tan(rad);
	float xScale = yScale * aspect;
	float zNear;
	float zFar;

	if (near != 0)
		zNear = near;
	else
		zNear = 0.1f;

	if (near < far)
		zFar = far;
	float zz = zFar / (zFar - zNear);

	matrix4 persp = {
		xScale, 0, 0, 0,
		0, yScale, 0, 0,
		0, 0, zz, 1,
		0, 0, (-(zFar * zNear) / (zFar - zNear)), 0
	};

	return persp;
}


unsigned int convertCoor(unsigned int x, unsigned int y, unsigned int width = REZ_X)
{
	return((y*width) + x);
}

unsigned int convertNDCX(float x, unsigned int width = REZ_X)
{
	return ((unsigned int)((x + 1)*(width / 2)));
}

unsigned int convertNDCY(float y, unsigned int height = REZ_Y)
{
	return ((unsigned int)((1 - y) * (height / 2)));
}

int implicitLineEquation(int x1, int x2, int y1, int y2, int midx, int midy)
{
	return (((y1 - y2)*midx) + ((x2 - x1)*midy) + ((x1*y2) - (y1*x2)));
}

vec3f barycentric(float x1, float y1, float x2, float y2, float x3, float y3, int checkX, int checkY)
{
	int a1 = convertNDCX(x1);
	int a2 = convertNDCX(x2);
	int a3 = convertNDCX(x3);
	int b1 = convertNDCY(y1);
	int b2 = convertNDCY(y2);
	int b3 = convertNDCY(y3);

	/*int gamma = implicitLineEquation(x1, x2, y1, y2, x3, y3);
	int alpha = implicitLineEquation(x2, x3, y2, y3, x1, y1);
	int beta = implicitLineEquation(x3, x1, y3, y1, x2, y2);
	int temp1 = implicitLineEquation(x1, x2, y1, y2, checkX, checkY);
	int temp2 = implicitLineEquation(x2, x3, y2, y3, checkX, checkY);
	int temp3 = implicitLineEquation(x3, x1, y3, y1, checkX, checkY);*/

	int gamma = implicitLineEquation(a1, a2, b1, b2, a3, b3);
	int alpha = implicitLineEquation(a2, a3, b2, b3, a1, b1);
	int beta = implicitLineEquation(a3, a1, b3, b1, a2, b2);
	int temp1 = implicitLineEquation(a1, a2, b1, b2, checkX, checkY);
	int temp2 = implicitLineEquation(a2, a3, b2, b3, checkX, checkY);
	int temp3 = implicitLineEquation(a3, a1, b3, b1, checkX, checkY);

	float ratio1 = (float)temp1 / gamma;
	float ratio2 = (float)temp2 / alpha;
	float ratio3 = (float)temp3 / beta;

	vec3f temp;
	temp.x = ratio2;
	temp.y = ratio3;
	temp.z = ratio1;

	if (ratio1 >= 0 && ratio1 <= 1 && ratio2 >= 0 && ratio2 <= 1 && ratio3 >= 0 && ratio3 <= 1)
		return temp;
	else
		return{ 0, 0, 0 };
}

float bcAdd(float f1, float f2, float f3, vec3f ratio)
{
	return ((f1 * ratio.x) + (f2 * ratio.y) + (f3 * ratio.z));
}

unsigned int colorSwap(unsigned int color)
{
	unsigned int temp1 = (color & 0xFF000000) >> 24;
	unsigned int temp2 = (color & 0x00FF0000) >> 8;
	unsigned int temp3 = (color & 0x0000FF00) << 8;
	unsigned int temp4 = (color & 0x000000FF) << 24;

	return (temp1 | temp2 | temp3 | temp4);
}

unsigned int texelU(float u, unsigned int width)
{
	return (u * width);
}

unsigned int texelV(float v, unsigned int height)
{
	return (v * height);
}