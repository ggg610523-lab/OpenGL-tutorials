#define GL_SILENCE_DEPRECATION

#include <GLUT/glut.h>

// Square position and size
float squareX = 0.0f;
float squareY = 0.0f;
const float squareSize = 0.1f;

// Movement speed per frame
const float speed = 0.9f;

// Window size
int windowWidth = 600;
int windowHeight = 600;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw square
    glColor3f(0.2f, 0.7f, 0.3f);
    glBegin(GL_QUADS);
        glVertex2f(squareX - squareSize, squareY - squareSize);
        glVertex2f(squareX + squareSize, squareY - squareSize);
        glVertex2f(squareX + squareSize, squareY + squareSize);
        glVertex2f(squareX - squareSize, squareY + squareSize);
    glEnd();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    windowWidth = w;
    windowHeight = h;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Use coordinate system from -1 to 1 in both directions
    gluOrtho2D(-1, 1, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Keyboard input for movement
void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            squareY += speed;
            if (squareY + squareSize > 1.0f) squareY = 1.0f - squareSize;
            break;
        case GLUT_KEY_DOWN:
            squareY -= speed;
            if (squareY - squareSize < -1.0f) squareY = -1.0f + squareSize;
            break;
        case GLUT_KEY_LEFT:
            squareX -= speed;
            if (squareX - squareSize < -1.0f) squareX = -1.0f + squareSize;
            break;
        case GLUT_KEY_RIGHT:
            squareX += speed;
            if (squareX + squareSize > 1.0f) squareX = 1.0f - squareSize;
            break;
    }
    glutPostRedisplay();
}

void timer(int value) {
    // Update game state here if needed (physics, AI, etc.)

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // ~60 FPS
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Basic GLUT Game");

    glClearColor(0.0, 0.0, 0.0, 1.0);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys); // For arrow keys
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}

