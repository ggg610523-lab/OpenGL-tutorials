#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

float angle = 0.0f;  // Rotation angle

void init() {
    glEnable(GL_DEPTH_TEST);  // Enable depth testing for 3D
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);  // Dark background
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    // Move the cube slightly away from the camera
    glTranslatef(0.0f, 0.0f, -7.0f);

    // Rotate the cube on X and Y axis
    glRotatef(angle, 1.0f, 1.0f, 0.0f);

    // Draw cube faces with different colors
    glBegin(GL_QUADS);

    // Front face (red)
    glColor3f(1.0f, 0.0f, 0.0f); 
    glVertex3f(-1.0f, -1.0f,  1.0f); 
    glVertex3f( 1.0f, -1.0f,  1.0f); 
    glVertex3f( 1.0f,  1.0f,  1.0f); 
    glVertex3f(-1.0f,  1.0f,  1.0f); 

    // Back face (green)
    glColor3f(0.0f, 1.0f, 0.0f); 
    glVertex3f(-1.0f, -1.0f, -1.0f); 
    glVertex3f(-1.0f,  1.0f, -1.0f); 
    glVertex3f( 1.0f,  1.0f, -1.0f); 
    glVertex3f( 1.0f, -1.0f, -1.0f); 

    // Top face (blue)
    glColor3f(0.0f, 0.0f, 1.0f); 
    glVertex3f(-1.0f,  1.0f, -1.0f); 
    glVertex3f(-1.0f,  1.0f,  1.0f); 
    glVertex3f( 1.0f,  1.0f,  1.0f); 
    glVertex3f( 1.0f,  1.0f, -1.0f); 

    // Bottom face (yellow)
    glColor3f(1.0f, 1.0f, 0.0f); 
    glVertex3f(-1.0f, -1.0f, -1.0f); 
    glVertex3f( 1.0f, -1.0f, -1.0f); 
    glVertex3f( 1.0f, -1.0f,  1.0f); 
    glVertex3f(-1.0f, -1.0f,  1.0f); 

    // Right face (cyan)
    glColor3f(0.0f, 1.0f, 1.0f); 
    glVertex3f( 1.0f, -1.0f, -1.0f); 
    glVertex3f( 1.0f,  1.0f, -1.0f); 
    glVertex3f( 1.0f,  1.0f,  1.0f); 
    glVertex3f( 1.0f, -1.0f,  1.0f); 

    // Left face (magenta)
    glColor3f(1.0f, 0.0f, 1.0f); 
    glVertex3f(-1.0f, -1.0f, -1.0f); 
    glVertex3f(-1.0f, -1.0f,  1.0f); 
    glVertex3f(-1.0f,  1.0f,  1.0f); 
    glVertex3f(-1.0f,  1.0f, -1.0f); 

    glEnd();

    glutSwapBuffers();
}

void timer(int value) {
    angle += 1.0f;
    if (angle > 360) angle -= 360;
    glutPostRedisplay();            // Request display update
    glutTimerFunc(16, timer, 0);   // Approx 60 FPS
}

void reshape(int w, int h) {
    if (h == 0) h = 1;
    float aspect = (float)w / (float)h;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspect, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("3D Spinning Cube");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}

