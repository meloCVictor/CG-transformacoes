#include <GL/glut.h>

float angle = 0.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Aplica a rotação
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    // Desenha um quadrado
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f( 0.1f, -0.1f);
        glVertex2f( 0.1f,  0.1f);
        glVertex2f(-0.1f,  0.1f);
    glEnd();

    glutSwapBuffers();
}

void keyPressed(unsigned char key, int x, int y) {
    if (key == 'r') angle += 5.0f;  // Rotaciona no sentido horário
    if (key == 'l') angle -= 5.0f;  // Rotaciona no sentido anti-horário

    glutPostRedisplay();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotação com Teclas");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyPressed);
    glutMainLoop();
    return 0;
}
