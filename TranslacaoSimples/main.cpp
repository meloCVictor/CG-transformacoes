#include <GL/glut.h>

float x_offset = 0.0f;  // Variável para controlar o movimento

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Aplica a translação
    glTranslatef(x_offset, 0.0f, 0.0f);  // Mover na direção X

    // Desenha um quadrado
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f( 0.1f, -0.1f);
        glVertex2f( 0.1f,  0.1f);
        glVertex2f(-0.1f,  0.1f);
    glEnd();

    glutSwapBuffers();
}

void update(int value) {
    x_offset += 0.01f;  // Mover para a direita
    if (x_offset > 1.0f) x_offset = -1.0f;  // Reset quando chega ao limite

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Translação Simples");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);
    glutMainLoop();
    return 0;
}
