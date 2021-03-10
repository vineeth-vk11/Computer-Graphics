#include<GL/glut.h>
#include <stdio.h>
#include <math.h>
#define pi 3.142857

void Initialise(){
    glClearColor(255.0, 255.0, 255.0, 255.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	gluOrtho2D(-780, 780, -420, 420);
}

void Draw(void){

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POINTS);
        int x = 0;
        int y = 200;
        float decision = 1 - 100;
        glVertex2f(x, y);

        while (y > x)
        {
            if (decision < 0)
            {
                decision += 2*x+3;
            }
            else
            {
                decision += 2*(x-y)+5;
                y--;
            }

            x++;

            glVertex2f(x, y);
            glVertex2f(x, -y);
            glVertex2f(-x, y);
            glVertex2f(-x, -y);
            glVertex2f(y, x);
            glVertex2f(-y, x);
            glVertex2f(y, -x);
            glVertex2f(-y, -x);
        }
    glEnd();    
    glFlush();
}

int main(int argc, char** argv){

    glutInit(&argc,argv);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Line Drawing");
    Initialise();
    glutDisplayFunc(Draw);
    glutMainLoop();

    return 0;

}