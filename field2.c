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

    int p = 0, q = 0, a = 0;
    int count = 50;
    int ptr = 0;

    while(ptr<20){
        glBegin(GL_POINTS);
            int x1 = p, y1 = q, x2 = p + count, y2 = q + count;

            int dx = x2 - x1;
            int dy = y2 - y1;

            int d = 2*dy - dx;

            int incrE = 2*dy;
            int incrNE = 2*(dy - dx);

            int x = x1, y = y1;

            glVertex2f(x,y);

            while(x<x2){
                if(d <= 0){
                    d = d + incrE;
                }
                else{
                    d = d + incrNE;
                    y ++;
                }

                x++;
                glVertex2f(x,y);
                glVertex2f(x,-y);
                glVertex2f(-x,y);
                glVertex2f(-x,-y);
                glVertex2f(y,x);
                glVertex2f(y,-x);
                glVertex2f(-y,x);
                glVertex2f(-y,-x);

                int k = a;

                while(a-k<count*sqrt(2)){
                    glVertex2f(a,0);
                    glVertex2f(0,a);
                    glVertex2f(-a,0);
                    glVertex2f(0,-a);

                    a++;
                }

                a = a + count;
            }

        glEnd();    

        p = p + 2*count;
        q = q + count;
        ptr++;
    }

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











