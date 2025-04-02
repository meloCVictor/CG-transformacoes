#include <GL/glut.h>

float scale_factor = 1.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glScalef(scale_factor, scale_factor, 1.0f);  // Aplica a escala

    // Desenha um quadrado
    glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f( 0.1f, -0.1f);
        glVertex2f( 0.1f,  0.1f);
        glVertex2f(-0.1f,  0.1f);
    glEnd();

    glutSwapBuffers();
}

void keyPressed(unsigned char key, int x, int y) {
    if (key == 'i') scale_factor += 0.1f;  // Aumenta a escala
    if (key == 'd') scale_factor -= 0.1f;  // Diminui a escala

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
    glutCreateWindow("Escala com Teclas");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyPressed);
    glutMainLoop();
    return 0;
}
