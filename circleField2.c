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

void drawCoordinates(int x, int y, int p, int count, int q, float a){
            glVertex2f(x + p + count/2,y + count/2 + q);
            glVertex2f(x + p + count/2,-y + count/2 + q);
            glVertex2f(-x + p + count/2,y + count/2 + q);
            glVertex2f(-x + p + count/2,-y + count/2 + q);
            glVertex2f(y + p + count/2,x + count/2 + q);
            glVertex2f(y + p + count/2,-x + count/2 + q);
            glVertex2f(-y + p + count/2,x + count/2 + q);
            glVertex2f(-y + p + count/2,-x + count/2 + q);

            glVertex2f(x - p - count/2,y + count/2 + q);
            glVertex2f(x - p - count/2,-y + count/2 + q);
            glVertex2f(-x - p - count/2,y + count/2 + q);
            glVertex2f(-x - p - count/2,-y + count/2 + q);
            glVertex2f(y - p - count/2,x + count/2 + q);
            glVertex2f(y - p - count/2,-x + count/2 + q);
            glVertex2f(-y - p - count/2,x + count/2 + q);
            glVertex2f(-y - p - count/2,-x + count/2 + q);

            glVertex2f(x + p + count/2,y - count/2 - q);
            glVertex2f(x + p + count/2,-y - count/2 - q);
            glVertex2f(-x + p + count/2,y - count/2 - q);
            glVertex2f(-x + p + count/2,-y - count/2 - q);
            glVertex2f(y + p + count/2,x - count/2 - q);
            glVertex2f(y + p + count/2,-x - count/2 - q);
            glVertex2f(-y + p + count/2,x - count/2 - q);
            glVertex2f(-y + p + count/2,-x - count/2 - q);

            glVertex2f(x - p - count/2,y - count/2 - q);
            glVertex2f(x - p - count/2,-y - count/2 - q);
            glVertex2f(-x - p - count/2,y - count/2 - q);
            glVertex2f(-x - p - count/2,-y - count/2 - q);
            glVertex2f(y - p - count/2,x - count/2 - q);
            glVertex2f(y - p - count/2,-x - count/2 - q);
            glVertex2f(-y - p - count/2,x - count/2 - q);
            glVertex2f(-y - p - count/2,-x - count/2 - q);

            glVertex2f(y + count/2 + q, x + p + count/2 );
            glVertex2f(-y + count/2 + q, x + p + count/2);
            glVertex2f(y + count/2 + q,-x + p + count/2);
            glVertex2f(-y + count/2 + q, -x + p + count/2);
            glVertex2f(x + count/2 + q, y + p + count/2);
            glVertex2f(-x + count/2 + q, y + p + count/2);
            glVertex2f(x + count/2 + q, -y + p + count/2);
            glVertex2f(-x + count/2 + q, -y + p + count/2);

            glVertex2f(y + count/2 + q, x - p - count/2);
            glVertex2f(-y + count/2 + q, x - p - count/2);
            glVertex2f(y + count/2 + q,-x - p - count/2);
            glVertex2f(-y + count/2 + q, -x - p - count/2);
            glVertex2f(x + count/2 + q, y - p - count/2);
            glVertex2f(-x + count/2 + q, y - p - count/2);
            glVertex2f(x + count/2 + q, -y - p - count/2);
            glVertex2f(-x + count/2 + q, -y - p - count/2);

            glVertex2f(y - count/2 - q, x - p - count/2);
            glVertex2f(-y - count/2 - q, x - p - count/2);
            glVertex2f(y - count/2 - q,-x - p - count/2);
            glVertex2f(-y - count/2 - q, -x - p - count/2);
            glVertex2f(x - count/2 - q, y - p - count/2);
            glVertex2f(-x - count/2 - q, y - p - count/2);
            glVertex2f(x - count/2 - q, -y - p - count/2);
            glVertex2f(-x - count/2 - q, -y - p - count/2);

            glVertex2f(y - count/2 - q, x + p + count/2);
            glVertex2f(-y - count/2 - q, x + p + count/2);
            glVertex2f(y - count/2 - q,-x + p + count/2);
            glVertex2f(-y - count/2 - q, -x + p + count/2);
            glVertex2f(x - count/2 - q, y + p + count/2);
            glVertex2f(-x - count/2 - q, y + p + count/2);
            glVertex2f(x - count/2 - q, -y + p + count/2);
            glVertex2f(-x - count/2 - q, -y + p + count/2);

            glVertex2f(x + a,y);
            glVertex2f(x + a,-y);
            glVertex2f(-x + a,y);
            glVertex2f(-x + a,-y);
            glVertex2f(y + a,x);
            glVertex2f(y + a,-x);
            glVertex2f(-y + a,x);
            glVertex2f(-y + a,-x);

            glVertex2f(x - a,y);
            glVertex2f(x - a,-y);
            glVertex2f(-x - a,y);
            glVertex2f(-x - a,-y);
            glVertex2f(y - a,x);
            glVertex2f(y - a,-x);
            glVertex2f(-y - a,x);
            glVertex2f(-y - a,-x);

            glVertex2f(x,y - a);
            glVertex2f(x,-y - a);
            glVertex2f(-x,y - a);
            glVertex2f(-x,-y - a);
            glVertex2f(y,x - a);
            glVertex2f(y,-x - a);
            glVertex2f(-y,x - a);
            glVertex2f(-y,-x - a);

            glVertex2f(x,y + a);
            glVertex2f(x,-y + a);
            glVertex2f(-x,y + a);
            glVertex2f(-x,-y + a);
            glVertex2f(y,x + a);
            glVertex2f(y,-x + a);
            glVertex2f(-y,x + a);
            glVertex2f(-y,-x + a);
}

void Draw(void){

    glClear(GL_COLOR_BUFFER_BIT);

    int p = 0, q = 0;
    int count = 50;
    float a = count/sqrt(2);
    int ptr = 0;

    while(ptr<20){
        glBegin(GL_POINTS);
            float centrex = p+(count/2);
            float centrey = count/2;

            float radius = count/sqrt(2);

            float x = 0;
            float y = radius;
            float d = 1 - radius;
            float deltaE = 3;
            float deltaSE = -2 *radius  + 5;

            drawCoordinates(x,y,p,count,q,a);

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
                drawCoordinates(x,y,p,count,q,a);

            }

        glEnd();    

        p = p + 2*count;
        q = q + count;
        a = a + 2*count;
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