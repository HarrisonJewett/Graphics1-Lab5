#pragma once
#include <math.h>
#include "includes.h"

float bcZ(float f1, float f2, float f3, float r1, float r2, float r3);


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

bool barycentricCheck(int x1, int y1, int x2, int y2, int x3, int y3, int pointX, int pointY)
{
	int gamma = implicitLineEquation(x1, x2, y1, y2, x3, y3);
	int alpha = implicitLineEquation(x2, x3, y2, y3, x1, y1);
	int beta = implicitLineEquation(x3, x1, y3, y1, x2, y2);
	int temp1 = implicitLineEquation(x1, x2, y1, y2, pointX, pointY);
	int temp2 = implicitLineEquation(x2, x3, y2, y3, pointX, pointY);
	int temp3 = implicitLineEquation(x3, x1, y3, y1, pointX, pointY);

	float check1 = (float)temp1 / gamma;
	float check2 = (float)temp2 / alpha;
	float check3 = (float)temp3 / beta;

	return (check1 >= 0 && check1 <= 1 && check2 >= 0 && check2 <= 1 && check3 >= 0 && check3 <= 1);
}

float barycentric(vec4f v1, vec4f v2, vec4f v3, int checkX, int checkY)
{
	int x1 = convertNDCX(v1.x);
	int x2 = convertNDCX(v2.x);
	int x3 = convertNDCX(v3.x);
	int y1 = convertNDCY(v1.y);
	int y2 = convertNDCY(v2.y);
	int y3 = convertNDCY(v3.y);

	int gamma = implicitLineEquation(x1, x2, y1, y2, x3, y3);
	int alpha = implicitLineEquation(x2, x3, y2, y3, x1, y1);
	int beta = implicitLineEquation(x3, x1, y3, y1, x2, y2);
	int temp1 = implicitLineEquation(x1, x2, y1, y2, checkX, checkY);
	int temp2 = implicitLineEquation(x2, x3, y2, y3, checkX, checkY);
	int temp3 = implicitLineEquation(x3, x1, y3, y1, checkX, checkY);

	float ratio1 = (float)temp1 / gamma;
	float ratio2 = (float)temp2 / alpha;
	float ratio3 = (float)temp3 / beta;

	return bcZ(v3.z, v1.z, v2.z, ratio1, ratio2, ratio3);
}

float bcZ(float f1, float f2, float f3, float r1, float r2, float r3)
{
	return ((f1 * r1) + (f2 * r2) + (f3 * r3));
}

float baryU(vertex vert1, vertex vert2, vertex vert3, float cX, float cY)
{
	int u1 = convertNDCX(vert1.U, TreeOfLife_width);
	int u2 = convertNDCX(vert2.U, TreeOfLife_width);
	int u3 = convertNDCX(vert3.U, TreeOfLife_width);
	int v1 = convertNDCY(vert1.V, TreeOfLife_width);
	int v2 = convertNDCY(vert2.V, TreeOfLife_width);
	int v3 = convertNDCY(vert3.V, TreeOfLife_width);

	int gamma = implicitLineEquation(u1, u2, v1, v2, u3, v3);
	int alpha = implicitLineEquation(u2, u3, v2, v3, u1, v1);
	int beta = implicitLineEquation(u3, u1, v3, v1, u2, v2);
	int t1 = implicitLineEquation(u1, u2, v1, v2, cX, cY);
	int t2 = implicitLineEquation(u2, u3, v2, v3, cX, cY);
	int t3 = implicitLineEquation(u3, u1, v3, v1, cX, cY);

	float r1 = (float)t1 / gamma;
	float r2 = (float)t2 / alpha;
	float r3 = (float)t3 / beta;
	
	return bcZ(vert3.U, vert1.U, vert2.U, r1, r2, r3);
}

float baryV(vertex vert1, vertex vert2, vertex vert3, float cX, float cY)
{
	int u1 = convertNDCX(vert1.U, TreeOfLife_width);
	int u2 = convertNDCX(vert2.U, TreeOfLife_width);
	int u3 = convertNDCX(vert3.U, TreeOfLife_width);
	int v1 = convertNDCY(vert1.V, TreeOfLife_width);
	int v2 = convertNDCY(vert2.V, TreeOfLife_width);
	int v3 = convertNDCY(vert3.V, TreeOfLife_width);

	int gamma = implicitLineEquation(u1, u2, v1, v2, u3, v3);
	int alpha = implicitLineEquation(u2, u3, v2, v3, u1, v1);
	int beta = implicitLineEquation(u3, u1, v3, v1, u2, v2);
	int t1 = implicitLineEquation(u1, u2, v1, v2, cX, cY);
	int t2 = implicitLineEquation(u2, u3, v2, v3, cX, cY);
	int t3 = implicitLineEquation(u3, u1, v3, v1, cX, cY);

	float r1 = (float)t1 / gamma;
	float r2 = (float)t2 / alpha;
	float r3 = (float)t3 / beta;

	return bcZ(vert3.V, vert1.V, vert2.V, r1, r2, r3);
}