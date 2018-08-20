//#include<stdio.h>
//#include<stdlib.h>
//#include<glut.h>
//#include<GLAux.h>
//
//#include"vgl.h"
//#include"vermilion.h"
#include<stdio.h>
#include<stdlib.h>
#include"glm.h"

#include<glut.h>
#include<GLAux.h>
void RenderScene(void)
{
	static GLfloat dark[4] = { 0.0,0.0,0.0,1.0 };
	static GLfloat normal[4] = { 0.5,0.5,0.5,1.0 };
	static GLfloat bright[4] = { 1.0,1.0,1.0,1.0 };
	static GLfloat pos[4] = { -0.2588,0.0,0.9659,0.0 };



	//Clear the window
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	

	//Setup for drawing
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	GLMmodel *pmodel;
	pmodel = glmReadOBJ("./objmodel/consensus.obj");//load the obj model
	if (!pmodel)
		exit(0);
	glmUnitize(pmodel);//united the model
	glmFacetNormals(pmodel);//caculate the normal vector
	glmVertexNormals(pmodel,90.0);
	
	
	//vglImageData *image = new vglImageData;
	//vglLoadImage("E:\\ZJU\\people_snapshot_public\\people_snapshot_public\\female-1-casual\\tex-female-1-casual.jpg", image);
	//vglLoadTexture("E:\\ZJU\\people_snapshot_public\\people_snapshot_public\\female-1-casual\\tex-female-1-casual.jpg", 0, image);


	//glTranslatef(0, 0, -3);
	//glDisable(GL_BLEND);
	//glDisable(GL_TEXTURE_2D);
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, dark);
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, dark);
	//glLightfv(GL_LIGHT0, GL_SPECULAR, bright);
	//glLightfv(GL_LIGHT0, GL_POSITION, pos);
	//glMaterialfv(GL_FRONT, GL_AMBIENT, dark);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, dark);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, bright);
	//glMateriali(GL_FRONT, GL_SHININESS, 128);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	//glTexImage2D(GL_TEXTURE_2D, image->mipLevels, image->internalFormat, 1000, 1000, 0, image->format, image->type, image->mip);
	glPushMatrix();
	//glTranslatef(0, 0, -3);
	static float i = 0;
	i += 3.0f;
	if (i > 360) i = 0;
	glRotatef(i, 0, 1, 0);
	glBlendFunc(GL_ONE, GL_ONE);
	//glEnable(GL_BLEND);	//启动透明
	glEnable(GL_TEXTURE_2D);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, normal);

	glLightfv(GL_LIGHT0, GL_AMBIENT, normal);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, normal);
	glLightfv(GL_LIGHT0, GL_SPECULAR, dark);
	glMaterialfv(GL_FRONT, GL_AMBIENT, normal);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, normal);
	glMaterialfv(GL_FRONT, GL_SPECULAR, dark);
	glMateriali(GL_FRONT, GL_SHININESS, 0);

	glmDraw(pmodel, GLM_SMOOTH | GLM_TEXTURE );
	glPopMatrix();
	
	glutSwapBuffers();
	//glFlush();
}
//
//int main()
//{
//	//RenderScene();
//	//GLMmodel *model = glmReadOBJ("E:\\ZJU\\people_snapshot_public\\people_snapshot_public\\female-1-casual\\consensus.obj");
//	//glmDraw(model, GLM_SMOOTH);
//	
//	
//	
//	glutInitWindowPosition(0, 0);
//	glutInitWindowSize(640, 480);
//	glutCreateWindow("OpenGL-test");
//	glBegin(GL_TRIANGLES);
//	glColor3f(1.0f, 0.0f, 0.0f);			// 红色
//	glVertex3f(0.0f, 1.0f, 0.0f);			// 三角形的上顶点 (前侧面)
//	glColor3f(0.0f, 1.0f, 0.0f);			// 绿色
//	glVertex3f(-1.0f, -1.0f, 1.0f);			// 三角形的左下顶点 (前侧面)
//	glColor3f(0.0f, 0.0f, 1.0f);			// 蓝色
//	glVertex3f(1.0f, -1.0f, 1.0f);
//	glColor3f(1.0f, 0.0f, 0.0f);			// 红色
//	glVertex3f(0.0f, 1.0f, 0.0f);			// 三角形的上顶点 (右侧面)
//	glColor3f(0.0f, 0.0f, 1.0f);			// 蓝色
//	glVertex3f(1.0f, -1.0f, 1.0f);			// 三角形的左下顶点 (右侧面)
//	glColor3f(0.0f, 1.0f, 0.0f);			// 绿色
//	glVertex3f(1.0f, -1.0f, -1.0f);
//	glColor3f(1.0f, 0.0f, 0.0f);			// 红色
//	glVertex3f(0.0f, 1.0f, 0.0f);			// 三角形的上顶点 (后侧面)
//	glColor3f(0.0f, 1.0f, 0.0f);			// 绿色
//	glVertex3f(1.0f, -1.0f, -1.0f);			// 三角形的左下顶点 (后侧面)
//	glColor3f(0.0f, 0.0f, 1.0f);			// 蓝色
//	glVertex3f(-1.0f, -1.0f, -1.0f);
//	glColor3f(1.0f, 0.0f, 0.0f);			// 红色
//	glVertex3f(0.0f, 1.0f, 0.0f);			// 三角形的上顶点 (左侧面)
//	glColor3f(0.0f, 0.0f, 1.0f);			// 蓝色
//	glVertex3f(-1.0f, -1.0f, -1.0f);			// 三角形的左下顶点 (左侧面)
//	glColor3f(0.0f, 1.0f, 0.0f);			// 绿色
//	glVertex3f(-1.0f, -1.0f, 1.0f);
//	glEnd();
//	glutMainLoop();
//	system("pause");
//	return 0;
//}


#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glut32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut.lib")
#pragma comment(lib, "GLAux.lib")

UINT g_bmp[1];//贴图编号
GLUquadricObj *g_text;//贴图指针

void Box(float x, float y, float z) //长方体
{
	glPushMatrix();
	glScalef(x, y, z);
	glEnable(GL_TEXTURE_2D); //贴图有效
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);// 前
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 后
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);// 上
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 下
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);// 左
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 右
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);//取消贴图
	glPopMatrix();
}

bool LoadT8(char *filename, GLuint &texture)
{
	AUX_RGBImageRec *pImage = NULL;
	pImage = auxDIBImageLoadA(filename); //装入位图
	if (pImage == NULL)
		return false;
	glGenTextures(1, &texture); //生成贴图
	glBindTexture(GL_TEXTURE_2D, g_bmp[0]); //贴图生效
	gluBuild2DMipmaps(GL_TEXTURE_2D, 4, pImage->sizeX, pImage->sizeY,
		GL_RGB, GL_UNSIGNED_BYTE, pImage->data); //贴图数据
	free(pImage->data);//释放位图内存
	free(pImage);
	return true;
}

void renderScene(void)
{
	static float i = 0;
	i += 0.01f;
	if (i > 360) i = 0;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(0, 0, -1.5);
	glRotatef(i, 1, 1, 1);
	Box(0.3f, 0.3f, 0.3f);

	glutSwapBuffers();
}
void changeSize(int w, int h)
{
	if (h == 0) h = 1;
	float ratio = 1.0* w / h;
	glMatrixMode(GL_PROJECTION);// 单位化投影矩阵。
	glLoadIdentity();
	glViewport(0, 0, w, h);// 设置视口大小为整个窗口大小
	gluPerspective(45, ratio, 1, 1000);// 设置正确的投影矩阵
	glMatrixMode(GL_MODELVIEW);//下面是设置模型视图矩阵
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, -1.0, 0.0f, 1.0f, 0.0f);//设置观测点
}
int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Render");
	glutDisplayFunc(RenderScene);
	glutIdleFunc(RenderScene); //指定程序空闲时调用函数
	glutReshapeFunc(changeSize); //指定窗口形状变化时的回调函数
	//glEnable(GL_DEPTH_TEST);


	g_text = gluNewQuadric(); //申请贴图缓存
	LoadT8("./texturemap/1.bmp", g_bmp[0]);
	glutMainLoop();
	return 0;
}