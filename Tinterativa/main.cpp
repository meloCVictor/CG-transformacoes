#include <GL/glut.h>

float x_offset = 0.0f;
float y_offset = 0.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Aplica a translação
    glTranslatef(x_offset, y_offset, 0.0f);

    // Desenha um quadrado
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f( 0.1f, -0.1f);
        glVertex2f( 0.1f,  0.1f);
        glVertex2f(-0.1f,  0.1f);
    glEnd();

    glutSwapBuffers();
}

void keyPressed(unsigned char key, int x, int y) {
    if (key == 'w') y_offset += 0.1f;  // Mover para cima
    if (key == 's') y_offset -= 0.1f;  // Mover para baixo
    if (key == 'a') x_offset -= 0.1f;  // Mover para a esquerda
    if (key == 'd') x_offset += 0.1f;  // Mover para a direita

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
    glutCreateWindow("Translação Interativa");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyPressed);
    glutMainLoop();
    return 0;
}
