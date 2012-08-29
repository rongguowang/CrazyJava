/*simple.c*/

#include<GL/glut.h>

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
  glVertex2f(-0.7, -0.7);
  glVertex2f(-0.7, 0.7);
  glVertex2f( 0.7, 0.7);
  glVertex2f( 0.7, -0.7);
  glEnd();

  glFlush();
}

int main(int argc, char ** argv)
{
  glutInit(&argc, argv);
  glutCreateWindow("simple");
  glutDisplayFunc(display);
  glutMainLoop();
}
