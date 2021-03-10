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

    int p = 0, q = 0;
    int count = 50;
    int ptr = 0;

    while(ptr<1){
        glBegin(GL_POINTS);
            float centrex = (p+(count/2));
            float centrey = count/2;

            float radius = count / sqrt(2);

            float x = p + count/2;
            float y = count/2 + radius;
            float d = 1 - radius;
            float deltaE = 3;
            float deltaSE = -2 *radius  + 5;

            glVertex2f(x,y);
            glVertex2f(x,-y);
            glVertex2f(-x,y);
            glVertex2f(-x,-y);
            glVertex2f(y,x);
            glVertex2f(y,-x);
            glVertex2f(-y,x);
            glVertex2f(-y,-x);

            while(y > x){
                if(d < 0){
                    d += deltaE;
                    deltaE += 2;
                    deltaSE += 2;
                }
                else{
                    d += deltaSE;
                    deltaE += 2;
                    deltaSE += 4;
                    y--;
                }
                x++;
                glVertex2f(x + p + count/2,y + count/2);
                glVertex2f(x + p + count/2,-y + count/2);
                glVertex2f(-x + p + count/2,y + count/2);
                glVertex2f(-x + p + count/2,-y + count/2);
                glVertex2f(y + p + count/2,x + count/2);
                glVertex2f(y + p + count/2,-x + count/2);
                glVertex2f(-y + p + count/2,x + count/2);
                glVertex2f(-y + p + count/2,-x + count/2);
            }

        glEnd();    

        p = p + count;
        q = 0;
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