#include "draw.h"
#include "XTime.h"

XTime timer;

int main()
{
	RS_Initialize(REZ_X, REZ_Y);

	timer.Restart();

	original.v1.point = { -0.25,  0.5, -0.25, 1.0f};
	original.v1.color = 0xFF00FF00;

	original.v2.point = { 0.25,  0.5, -0.25, 1.0f};
	original.v2.color = 0xFF00FF00;

	original.v3.point = { -0.25,  0  , -0.25, 1.0f};
	original.v3.color = 0xFF00FF00;

	original.v4.point = { 0.25,  0  , -0.25, 1.0f };
	original.v4.color = 0xFF00FF00;

	original.v5.point = { -0.25,  0.5,  0.25, 1.0f};
	original.v5.color = 0xFF00FF00;

	original.v6.point = { 0.25,  0.5,  0.25, 1.0f };
	original.v6.color = 0xFF00FF00;

	original.v7.point = { -0.25,  0  ,  0.25, 1.0f};
	original.v7.color = 0xFF00FF00;

	original.v8.point = { 0.25,  0  ,  0.25, 1.0f };
	original.v8.color = 0xFF00FF00;

	for (unsigned int i = 0; i < 11; ++i)
	{
		gridTop[i].point.x = i * 0.1f - 0.5f;
		gridTop[i].point.y = 0.0;
		gridTop[i].point.z = 0.5;
		gridTop[i].point.w = 1;
		gridTop[i].color = 0xFFFFFFFF;

		gridLeft[i].point.x = -0.5;
		gridLeft[i].point.y = 0.0;
		gridLeft[i].point.z = i * 0.1f - 0.5f;
		gridLeft[i].point.w = 1;
		gridLeft[i].color = 0xFFFFFFFF;


		gridBottom[i].point.x = i * 0.1f - 0.5f;
		gridBottom[i].point.y = 0;
		gridBottom[i].point.z = -0.5;
		gridBottom[i].point.w = 1;
		gridBottom[i].color = 0xFFFFFFFF;

		gridRight[i].point.x = 0.5;
		gridRight[i].point.y = 0.0;
		gridRight[i].point.z = i * 0.1f - 0.5f;
		gridRight[i].point.w = 1;
		gridRight[i].color = 0xFFFFFFFF;
	}

	matrix4 r = matrix4Xrot(-18.0f*(float)RADS);
	vec3f v = { 0, 0, -1 };
	matrix4 t = matrix4trans(v);

	matrix4 cameraMatrix = matrix4Multiply(t, r);
	SV_ViewMatrix = matrix4Inverse(cameraMatrix);

	
	SV_PerspectiveMatrix = perspectiveMatrix(90, (float)REZ_Y/REZ_X, 0.1f, 10);

	float theta = 0;

	while (RS_Update(colorArray, REZ_X*REZ_Y))
	{
		clearBuffer(0x00000000);

		timer.Signal();
		theta += (float)timer.Delta();

		VertexShader = VS_World;
		PixelShader = PS_Green;

		SV_WorldMatrix = identiyMatrix();
		for (unsigned int i = 0; i < 11; i++)
		{
			drawLine(gridTop[i], gridBottom[i]);
			drawLine(gridLeft[i], gridRight[i]);
		}

		PixelShader = PS_Yellow;
		SV_WorldMatrix = matrix4Yrot(theta);

		drawLine(original.v1, original.v2);
		drawLine(original.v2, original.v4);
		drawLine(original.v4, original.v3);
		drawLine(original.v3, original.v1);

		drawLine(original.v5, original.v6);
		drawLine(original.v6, original.v8);
		drawLine(original.v8, original.v7);
		drawLine(original.v7, original.v5);

		drawLine(original.v1, original.v5);
		drawLine(original.v2, original.v6);
		drawLine(original.v4, original.v8);
		drawLine(original.v3, original.v7);

		//filling triangles
		colorTriangle(original.v1.point, original.v2.point, original.v3.point, 0xFF00FF00);
		colorTriangle(original.v4.point, original.v3.point, original.v2.point, 0xFF641E16);

		colorTriangle(original.v2.point, original.v6.point, original.v4.point, 0xFF512E5F);
		colorTriangle(original.v8.point, original.v4.point, original.v6.point, 0xFF154360);

		colorTriangle(original.v6.point, original.v5.point, original.v8.point, 0xFF0B5345);
		colorTriangle(original.v7.point, original.v8.point, original.v5.point, 0xFF7D6608);

		colorTriangle(original.v5.point, original.v1.point, original.v7.point, 0xFF6E2C00);
		colorTriangle(original.v3.point, original.v7.point, original.v1.point, 0xFF7B7D7D);

	}
	
	RS_Shutdown();
	return 0;
}