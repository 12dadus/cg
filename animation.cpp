#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

int frame = 0;  

void drawWindmill() {
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, 0);
    glVertex2f(-0.05, 3);
    glVertex2f(0.05, 3);
    glVertex2f(0.05, 0);
    glEnd();

    glTranslatef(0, 3, 0);
    glColor3f(1, 0, 0);
    glRotated(frame * 4, 0, 0, 1);
    
    for(int i = 0; i < 4; i++) {
        glRotated(90, 0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex2f(0, 0);
        glVertex2f(1, 0.2);
        glVertex2f(1, -0.2);
        glEnd();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix();
    glTranslated(2.2, 1.6, 0); 
    glScaled(0.4, 0.4, 1);     
    drawWindmill();
    glPopMatrix();

    glPushMatrix();
    glTranslated(3.7, 0.8, 0); 
    glScaled(0.7, 0.7, 1);     
    drawWindmill();
    glPopMatrix();

    glutSwapBuffers();
}

void doFrame(int v) {
    frame++;
    glutPostRedisplay(); 
    glutTimerFunc(10, doFrame, 0); 
}

void init() {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 7, -1, 4, -1, 1); 
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("WINDMILL");
    
    init();
    glutDisplayFunc(display);
    glutTimerFunc(200, doFrame, 0);
    glutMainLoop();

    return 0;
}
