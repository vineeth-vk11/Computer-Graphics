#include<GL/glut.h>
#include <stdio.h>
#include <math.h>

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
        float x1 = 0, y1 = 0, x2 = 100, y2 = 200;
        float y;

        float x = x1;
        float yexact = y1;

        float m = (y2 - y1)/(x2 - x1);

        while(x<x2){
            yexact = yexact + m;
            y = floor(0.5 + yexact);
            glVertex2f(x,y);
            x=x+1;    
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