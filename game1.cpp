#define Gl_SILENCE_DEPRECATION

#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <cstdlib>

float squareX = 0.0f;
float squareY = -0.8f;     // Start near bottom
const float squareSize = 0.1f;

float speed = 0.4f;
float jumpSpeed = 0.05f;
bool isJumping = false;
float verticalVelocity = 0.0f;
const float gravity = -0.002f;

int windowWidth = 1920;
int windowHeight = 1080;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

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
    gluOrtho2D(-1, 1, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void specialKeys(int key, int x, int y) {
    // arrow keys for slow movement
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

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': // faster up
            squareY += speed * 3;
            if (squareY + squareSize > 1.0f) squareY = 1.0f - squareSize;
            break;
        case 's': // faster down
            squareY -= speed * 3;
            if (squareY - squareSize < -1.0f) squareY = -1.0f + squareSize;
            break;
        case 'a': // faster left
            squareX -= speed * 3;
            if (squareX - squareSize < -1.0f) squareX = -1.0f + squareSize;
            break;
        case 'd': // faster right
            squareX += speed * 3;
            if (squareX + squareSize > 1.0f) squareX = 1.0f - squareSize;
            break;
        case ' ': // space = jump if not already jumping
            if (!isJumping) {
                isJumping = true;
                verticalVelocity = jumpSpeed;
            }
            break;
        case 27: // ESC key exit
            exit(0);
    }
    glutPostRedisplay();
}

void timer(int value) {
    // Handle jumping physics
    if (isJumping) {
        squareY += verticalVelocity;
        verticalVelocity += gravity;

        // Stop falling when hits ground level
        if (squareY - squareSize <= -0.8f) {
            squareY = -0.8f + squareSize;
            isJumping = false;
            verticalVelocity = 0.0f;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // ~60 FPS
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("GLUT Basic Game: Jump & Move");

    glClearColor(0, 0, 0, 1);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}

