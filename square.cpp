#include <stdio.h>
#include <GL/glut.h>

int width = 30;

void square(int bx, int by){
    glBegin(GL_POLYGON);
    glVertex2f(bx + 0, by + 0);
    glVertex2f(bx + 0, by + width);
    glVertex2f(bx + width, by + width);
    glVertex2f(bx + width, by + 0);
    glEnd();
}

void display(void)
{
    glClear( GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    square(100 + 100, 100 + 100);
    square(0, 0);
    glFlush();
}

int main(int argc, char **argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB);

 glutInitWindowPosition(100,100);
 glutInitWindowSize(300,300);
 glutCreateWindow ("square");

 glClearColor(0.0, 0.0, 0.0, 0.0);         // black background
 glMatrixMode(GL_PROJECTION);              // setup viewing projection
//  glLoadIdentity();                           // start with identity matrix
 gluOrtho2D(0.0, 300.0, 0.0, 300.0);   // setup a 10x10x2 viewing world

 glutDisplayFunc(display);
 glutMainLoop();

 return 0;
}