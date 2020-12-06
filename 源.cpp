#include <glut.h>  
#include <stdlib.h>  
//<<<<<<<<<<<<<<<<<<< axis >>>>>>>>>>>>>>

static GLfloat spin = 0.0;
static GLfloat spin1 = 0.0;

void myinit(void)
{
	GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };

	GLfloat light0_diffuse[] = { 0.0, 0.0, 1.0, 1.0 };
	GLfloat light0_position[] = { 1.0, 1.0, 1.0, 0.0 };

	GLfloat light1_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat light1_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat light1_specular[] = { 1.0, 0.6, 0.6, 1.0 };
	GLfloat light1_position[] = { -3.0, -3.0, 3.0, 1.0 };

	GLfloat spot_direction[] = { 3.0,3.0,-3.0 };


	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	//glEnable(GL_DEPTH_TEST);

}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<< displayWire >>>>>>>>>>>>>>>>>>>>>>
void displayWire(void)
{
	//glEnable(GL_CULL_FACE);
	//glViewport(0, 0, 320, 240);
	glMatrixMode(GL_PROJECTION); // set the view volume shape
	glLoadIdentity();
	glOrtho(-2.0 * 64 / 48.0, 2.0 * 64 / 48.0, -2.0, 2.0, -10, 100);
	//	gluPerspective(120.0f, (GLfloat)64 / (GLfloat)48, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW); // position and aim the camera
	glLoadIdentity();
	gluLookAt(1.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	//glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); // clear the screen
	glClear(GL_COLOR_BUFFER_BIT );
	glColor3d(0, 0, 0); // draw black lines

	glPushMatrix();
	glRotated(spin, 1, 1, 0);
	glRotated(spin1, 0, 1, 0);
	glColor3d(1, 0, 0.1);
	glScaled(1, 6, 1); // big cube at (0.5, 0.5, 0.5)
	glutSolidCube(0.2);
	glPopMatrix();

	glPushMatrix();
	glRotated(spin, 1, 1, 0);
	glRotated(spin1, 0, 1, 0);
	glColor3d(1, 0, 0.1);
	glTranslated(0.6, 0, 0);
	glScaled(1, 6, 1); // big cube at (0.5, 0.5, 0.5)
	glutSolidCube(0.2);
	glPopMatrix();

	glPushMatrix();
	glRotated(spin, 1, 1, 0);
	glRotated(spin1, 0, 1, 0);
	glColor3d(1, 0, 0.1);
	glTranslated(0, 0, -0.6);
	glScaled(1, 6, 1); // big cube at (0.5, 0.5, 0.5)
	glutSolidCube(0.2);
	glPopMatrix();

	glPushMatrix();
	glRotated(spin, 1, 1, 0);
	glRotated(spin1, 0, 1, 0);
	glColor3d(1, 0, 0.1);
	glTranslated(0.6, 0, -0.6);
	glScaled(1, 6, 1); // big cube at (0.5, 0.5, 0.5)
	glutSolidCube(0.2);

	glPopMatrix();
	glPushMatrix();
	glRotated(spin, 1, 1, 0);
	glRotated(spin1, 0, 1, 0);
	glColor3d(1, 0.5, 0.1);
	glTranslated(0.3, 0.7, -0.3);
	glScaled(5, 0.9, 5); // big cube at (0.5, 0.5, 0.5)
	glutSolidCube(0.2);
	glPopMatrix();

	glPushMatrix();

	glRotated(spin, 1, 1, 0);
	glRotated(spin1, 0, 1, 0);
	glColor3d(0.1, 0.5, 0.1);

	glTranslated(0.28, 1.3, -0.8);
	glRotated(-90, 1, 0, 0);
	glScaled(5, 0.6, 6); // big cube at (0.5, 0.5, 0.5)
	glutSolidCube(0.2);

	glPopMatrix();

	glFlush();
}
void spinDisplay(void)
{
	spin = spin + 0.1;
	if (spin > 360.0)
		spin = 0;
	glutPostRedisplay();  //屏幕重绘
}
void spinDisplay1(void)
{
	spin1 = spin1 + 0.1;
	if (spin1 > 360.0)
		spin1 = 0;
	glutPostRedisplay();  //屏幕重绘
}
void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			//glutIdleFunc(spinDisplay);  //设备空闲时调用的函数
			//glutIdleFunc(spinDisplay1);
		}

		break;
	case GLUT_MIDDLE_BUTTON:
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay1);
		break;
	default:
		break;
	}
}
//<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Transformation Test - wireframes");
	glutDisplayFunc(displayWire);
	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // background is white
	glutMouseFunc(mouse);  //注册鼠标动作函数
	myinit();
	glEnable(GL_NORMALIZE);
	glutMainLoop();
}