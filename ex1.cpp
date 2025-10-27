#define GL_SILENCE_DEPRECATION 

#include <GLUT/glut.h>
#include "ero.h"


void init(){//setup 
      glClearColor (0.0,0.0,0.0,0.0);
      glMatrixMode(GL_PROJECTION);
      gluOrtho2D(0.0,400,300,0.0);


}

void line(){
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0,0.4,0.2);
  glBegin(GL_LINES);
      glVertex2i(180,15);
      glVertex2i(10,145);
      


  glEnd();
  glFlush();


}

int main(int argc ,char** argv){
  glutInit(&argc,argv);//requires &argc ,argv
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(50,100);
  glutInitWindowSize(400,300);
  glutCreateWindow("mango");

  init();
  glutDisplayFunc(line);
  glutMainLoop();



  return 0;
}
