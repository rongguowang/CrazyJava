/*simple.c second version*/
/*this programe draw a white rectangle on a black background*/

#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>

/*glut.h include gl.h and glu.h*/
void vertexArray()
{
  glVertex2f(-0.5, -0.5);
  glVertex2f(-0.7, 0);
  glVertex2f(-0.5, 0.5);
  glVertex2f(0, 0.7);
  glVertex2f(0.5, 0.5);
  glVertex2f(0.7, 0);
  glVertex2f(0.5, -0.5);
  glVertex2f(0, -0.7);
}
void displayLineLoop()
{
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1.0, 1.0, 0.0);
  glLineWidth(1.0);
  glEnable(GL_LINE_STIPPLE);
  glLineStipple(3, 0xcccc);

  glBegin(GL_LINE_LOOP);
  vertexArray();
  glEnd();
  glFlush();
}

void displayLineStrip()
{
  glClear(GL_COLOR_BUFFER_BIT);
  
  glBegin(GL_LINE_STRIP);
  vertexArray();
  glEnd();
  glFlush();
}

void displayLine()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINES);
  //  vertexArray();
  glColor3f(1.0, 1.0, 1.0);
  glVertex2f(-0.5, -0.5);
  
  glColor3f(1.0, 0.0, 0.0);
  glVertex2f(-0.5, 0.5);
  
  glColor3f(0.0, 0.0, 1.0);
  glVertex2f(0.5, 0.5);

  glColor3f(0.0, 1.0, 0.0);
  glVertex2f(0.5, -0.5);
  glEnd();

  glFlush();
}

void displayPoint()
{
  glClear(GL_COLOR_BUFFER_BIT);

  glPointSize(5.0);

  glBegin(GL_POINTS);
  glColor3f(1.0, 1.0, 1.0);
  glVertex2f(-0.5, -0.5);
  
  glColor3f(1.0, 0.0, 0.0);
  glVertex2f(-0.5, 0.5);
  
  glColor3f(0.0, 0.0, 1.0);
  glVertex2f(0.5, 0.5);

  glColor3f(0.0, 1.0, 0.0);
  glVertex2f(0.5, -0.5);
  glEnd();

  glFlush();
}

void displayRect()
{
  glClear(GL_COLOR_BUFFER_BIT);
  //  glRectf(-0.5, 0.5, 0.5, -0.5);
  //  glRecti(-1, 1, 1, -1);
  glRectd(-0.7, 0.3, 0.7, -0.3);
  glFlush();
}

void displayStar()
{
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_LINES);
  glColor3f(1.0, 0.0, 0.0);
  glVertex2f(-0.7, 0.3);
  glColor3f(0.0, 1.0, 0.0);
  glVertex2f(0.7, 0.3);
  glEnd();

  glBegin(GL_LINES);
  glVertex2f(-0.7, 0.3);
  glColor3f(0.0, 0.0, 1.0);
  glVertex2f(0.5, -0.5);
  glEnd();

  glBegin(GL_LINES);
  glVertex2f(0, 0.6);
  glColor3f(1.0, 1.0, 0.0);
  glVertex2f(-0.5, -0.5);
  glEnd();
  
  glBegin(GL_LINES);
  glVertex2f(0, 0.6);
  glColor3f(0.0, 1.0, 1.0);
  glVertex2f(0.5, -0.5);
  glEnd();

  glBegin(GL_LINES);
  glVertex2f(0.7, 0.3);
  glColor3f(1.0, 1.0, 1.0);
  glVertex2f(-0.5, -0.5);
  glEnd();

  glFlush();
}

void displayPolygonEdgeFlag()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  
  glBegin(GL_TRIANGLE_FAN);
  glEnable(GL_EDGE_FLAG);
  glEdgeFlag(GL_FALSE);
  vertexArray();
  glEnd();
  glFlush();
}

void displayPolygon()
{
  glClear(GL_COLOR_BUFFER_BIT);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glColor3f(1.0, 1.0, 0.0);
  
  glBegin(GL_POLYGON);
  vertexArray();
  glEnd();
  
  glEnable(GL_POLYGON_OFFSET_LINE);
  glPolygonOffset(1.0, 2.0);

  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glColor3f(0.0, 1.0, 0.0);

  glLineWidth(2.0);
  glEnable(GL_LINE_STIPPLE);
  glLineStipple(3, 0xcccc);
  glBegin(GL_POLYGON);
  vertexArray();
  glEnd();

  glFlush();
}

void triangle(GLfloat *a, GLfloat *b, GLfloat *c)
{
     glBegin(GL_TRIANGLES);
     glVertex2fv(a);
     glVertex2fv(b);
     glVertex2fv(c);
     glEnd();
}

void divide_triangle(GLfloat * a, GLfloat * b, GLfloat * c, int m)
{
     GLfloat v[3][2];
     int j = 0;
  
     if( m > 0)
     {
	  for(j = 0; j < 2; j++)
	  {
	       v[0][j] = (a[j] + b[j]) / 2;
	  }

	  for(j = 0; j < 2; j++)
	  {
	       v[1][j] = (a[j] + c[j]) / 2;
	  }

	  for(j = 0; j < 2; j++)
	  {
	       v[2][j] = (b[j] + c[j]) / 2;
	  }

	  divide_triangle(a, v[0], v[1], (m - 1));
	  divide_triangle(v[0], b, v[2], (m - 1));
	  divide_triangle(v[1], v[2], c, (m - 1));
	  divide_triangle(v[0], v[1], v[2], (m - 1));
     }
     else
     {
	  triangle(a, b, c);
     }
     
}

void displayDivideTriangle()
{
  GLfloat v[3][2] = {{-0.8, -0.8}, {0, 0.8}, {0.8, -0.8}};

  glClear(GL_COLOR_BUFFER_BIT);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  divide_triangle(v[0], v[1], v[2], 4);
  glFlush();
}
void display()
{
     /*clear window*/
     glClear(GL_COLOR_BUFFER_BIT);
  
     /*draw unit square polygon*/
     glBegin(GL_POLYGON);
     //  glBegin(GL_TRIANGLES);
     //  glBegin(GL_TRIANGLE_STRIP);
     //  glBegin(GL_TRIANGLE_FAN);
     //  glBegin(GL_QUADS);
     //glBegin(GL_QUAD_STRIP);
     vertexArray();
     glEnd();

     /*flush GL buffers*/
     glFlush();
}

void init()
{
     /*set clear color to black*/
     glClearColor(0.0, 0.0, 0.0, 0.0);

     /*set fill color to white*/
     glColor3f(0.0, 1.0, .0);

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
  glutDisplayFunc(displayDivideTriangle);
  //  glutDisplayFunc(displayStar);
  //  glutDisplayFunc(displayPolygon);
  //  glutDisplayFunc(displayPolygonEdgeFlag);
  //  glutDisplayFunc(display);
  //  glutDisplayFunc(displayRect);
  //  glutDisplayFunc(displayPoint);
  //  glutDisplayFunc(displayLine);
  //  glutDisplayFunc(displayLineStrip);
  //  glutDisplayFunc(displayLineLoop);
  init();
  glutMainLoop();
}
