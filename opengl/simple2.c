/*simple.c second version*/
/*this programe draw a white rectangle on a black background*/

#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>

/*glut.h include gl.h and glu.h*/

void display()
{
  /*clear window*/
  glClear(GL_COLOR_BUFFER_BIT);

  /*draw unit square polygon*/
  glBegin(GL_POLYGON);
  glVertex2f(-0.5, -0.5);
  glVertex2f(-0.5, 0.5);
  glVertex2f(0.5, 0.5);
  glVertex2f(0.5, -0.5);
  glEnd();

  /*flush GL buffers*/
  glFlush();
}

void init()
{
  /*set clear color to black*/
  glClearColor(0.0, 1.0, 0.0, 0.0);

  /*set fill color to white*/
  glColor3f(1.0, 0.0, 0.0);

  /*set up standard orthogonal view with clipping
   *box as cub of side 2 centered at origin
   *this is default view and these statement could
   *be removed.
   */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  //  gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char ** argv)
{
  /**
   *initialize mode and open a window in uppper-left
   *corner of screen. Window tile is name of programe
   *(arg[0])
   */
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(768, 768);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("simple2");
  glutDisplayFunc(display);
  init();
  glutMainLoop();
}
