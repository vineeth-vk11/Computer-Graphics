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

    int a = 0, b = 0;
    int ctr = 0;

    while(ctr < 15){
            int p = a, q = b;
            int count = 50;
            int ptr = 0;
            while(ptr<10){
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
                    }

                glEnd();    

                p = p + count;
                q = q + count;
                ptr++;
        }

        a = a + count;
        b = 0;
        ctr++;
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