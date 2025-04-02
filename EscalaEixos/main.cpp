#include <GL/glut.h>

float x_scale = 1.0f;
float y_scale = 1.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glScalef(x_scale, y_scale, 1.0f);  // Escala separada nos eixos X e Y

    // Desenha um quadrado
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f( 0.1f, -0.1f);
        glVertex2f( 0.1f,  0.1f);
        glVertex2f(-0.1f,  0.1f);
    glEnd();

    glutSwapBuffers();
}

void update(int value) {
    x_scale += 0.01f;  // Aumenta a escala no eixo X
    y_scale += 0.02f;  // Aumenta a escala mais rápido no eixo Y

    if (x_scale > 2.0f) x_scale = 1.0f;
    if (y_scale > 2.0f) y_scale = 1.0f;

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
    glutCreateWindow("Escala Diferente nos Eixos");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);
    glutMainLoop();
    return 0;
}
