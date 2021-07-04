#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;
float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mousedown = false;

void myinit(void);
void tampilan(void);
void keyboard(unsigned char, int, int);
void mouseMove(int x, int y);
void resize(int, int);
void mouseButton(int button, int state, int x, int y);

int is_depth;
void mouseMove(int x, int y) {
    if (mousedown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mousedown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else {
        mousedown = false;
    }
    glutPostRedisplay();
}


void tampilan()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);

    //Alas
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.1, 0.0);
    glVertex3f(10.0, 1.0, 10.0);
    glVertex3f(-10.0, 1.0, 10.0);
    glVertex3f(-10.0, 1.0, -10.0);
    glVertex3f(10.0, 1.0, -10.0);
    glEnd();

    // DEPAN
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.3, 0.1);
    glVertex3f(1.0, 4.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(4.0, 1.0, 0.0);
    glVertex3f(4.0, 4.0, 0.0);
    glEnd();
    glFlush;
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 4.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(4.0, 1.0, 0.0);
    glVertex3f(4.0, 4.0, 0.0);
    glEnd();
    glFlush;

    // kanan
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 1.0);
    glVertex3f(4.0, 1.0, 0.0);
    glVertex3f(4.0, 4.0, 0.0);
    glVertex3f(4.0, 4.0, -5.0);
    glVertex3f(4.0, 1.0, -5.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.0, 1.0, 0.0);
    glVertex3f(4.0, 4.0, 0.0);
    glVertex3f(4.0, 4.0, -5.0);
    glVertex3f(4.0, 1.0, -5.0);
    glEnd();
    glFlush();

    //Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 1.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, 4.0, 0.0);
    glVertex3f(1.0, 4.0, -5.0);
    glVertex3f(1.0, 1.0, -5.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, 4.0, 0.0);
    glVertex3f(1.0, 4.0, -5.0);
    glVertex3f(1.0, 1.0, -5.0);
    glEnd();
    glFlush();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.3, 0.1);
    glVertex3f(1.0, 4.0, -5.0);
    glVertex3f(1.0, 1.0, -5.0);
    glVertex3f(4.0, 1.0, -5.0);
    glVertex3f(4.0, 4.0, -5.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 4.0, -5.0);
    glVertex3f(1.0, 1.0, -5.0);
    glVertex3f(4.0, 1.0, -5.0);
    glVertex3f(4.0, 4.0, -5.0);
    glEnd();
    glFlush();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 1.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(4.0, 1.0, 0.0);
    glVertex3f(4.0, 1.0, -5.0);
    glVertex3f(1.0, 1.0, -5.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(4.0, 1.0, 0.0);
    glVertex3f(4.0, 1.0, -5.0);
    glVertex3f(1.0, 1.0, -5.0);
    glEnd();
    glFlush();

    //Atas
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 1.0);
    glVertex3f(1.0, 4.0, 0.0);
    glVertex3f(4.0, 4.0, 0.0);
    glVertex3f(4.0, 4.0, -5.0);
    glVertex3f(1.0, 4.0, -5.0);
    glEnd();
    glFlush();

    //Atap depan
    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.3, 0.1);
    glVertex3f(1.3, 4.0, 0.0);
    glVertex3f(3.7, 4.0, 0.0);
    glVertex3f(2.5, 6.0, 0.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3f(1.2, 4.0, 0.0);
    glVertex3f(3.7, 4.0, 0.0);
    glVertex3f(2.5, 6.0, 0.0);
    glEnd();
    glFlush();

    //TAMBAHAN SISI ATAP DEPAN  KIRI
        //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 4.0, 0.0);
    glVertex3f(1.0, 4.5, 0.0);
    glVertex3f(1.5, 4.5, 0.0);
    glVertex3f(1.5, 5.0, 0.0);
    glVertex3f(1.9, 5.0, 0.0);
    glVertex3f(1.9, 5.5, 0.0);
    glVertex3f(2.2, 5.5, 0.0);
    glVertex3f(2.2, 6.0, 0.0);
    glVertex3f(2.5, 6.0, 0.0);
    glVertex3f(1.3, 4.0, 0.0);
    glVertex3f(1.0, 4.0, 0.0);
    glEnd();
    glFlush();
    //ISI
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 4.0, 0.0);
    glVertex3f(1.0, 4.5, 0.0);
    glVertex3f(1.5, 4.5, 0.0);
    glVertex3f(1.3, 4.0, 0.0);
    glVertex3f(1.0, 4.0, 0.0);
    glEnd();
    glFlush();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1.5, 4.5, 0.0);
    glVertex3f(1.5, 5.0, 0.0);
    glVertex3f(1.9, 5.0, 0.0);
    glEnd();
    glFlush;
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(2.2, 5.5, 0.0);
    glVertex3f(2.2, 6.0, 0.0);
    glVertex3f(2.5, 6.0, 0.0);
    glEnd();
    glFlush;
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1.9, 5.0, 0.0);
    glVertex3f(1.9, 5.5, 0.0);
    glVertex3f(2.2, 5.5, 0.0);
    glEnd();
    glFlush;


    //TAMBAHAN SISI ATAP DEPAN KANAN
        //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.0, 4.0, 0.0);
    glVertex3f(4.0, 4.5, 0.0);
    glVertex3f(3.4, 4.5, 0.0);
    glVertex3f(3.4, 5.0, 0.0);
    glVertex3f(3.1, 5.0, 0.0);
    glVertex3f(3.1, 5.5, 0.0);
    glVertex3f(2.8, 5.5, 0.0);
    glVertex3f(2.8, 6.0, 0.0);
    glVertex3f(2.5, 6.0, 0.0);
    glVertex3f(3.7, 4.0, 0.0);
    glVertex3f(4.0, 4.0, 0.0);
    glEnd();
    glFlush();
    //ISI
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.0, 4.0, 0.0);
    glVertex3f(4.0, 4.5, 0.0);
    glVertex3f(3.4, 4.5, 0.0);
    glVertex3f(3.7, 4.0, 0.0);
    glVertex3f(4.0, 4.0, 0.0);
    glEnd();
    glFlush();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(3.4, 4.5, 0.0);
    glVertex3f(3.4, 5.0, 0.0);
    glVertex3f(3.1, 5.0, 0.0);
    glEnd();
    glFlush;
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(3.1, 5.0, 0.0);
    glVertex3f(3.1, 5.5, 0.0);
    glVertex3f(2.8, 5.5, 0.0);
    glEnd();
    glFlush;
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(2.8, 5.5, 0.0);
    glVertex3f(2.8, 6.0, 0.0);
    glVertex3f(2.5, 6.0, 0.0);
    glEnd();
    glFlush;



    //Atap belakang
    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.3, 0.1);
    glVertex3f(1.3, 4.0, -5.0);
    glVertex3f(3.7, 4.0, -5.0);
    glVertex3f(2.5, 6.0, -5.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.3, 4.0, -5.0);
    glVertex3f(3.7, 4.0, -5.0);
    glVertex3f(2.5, 6.0, -5.0);
    glEnd();
    glFlush();

    //TAMBAHAN SISI ATAP BELAKANG  KIRI
        //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 4.0, -5.0);
    glVertex3f(1.0, 4.5, -5.0);
    glVertex3f(1.5, 4.5, -5.0);
    glVertex3f(1.5, 5.0, -5.0);
    glVertex3f(1.9, 5.0, -5.0);
    glVertex3f(1.9, 5.5, -5.0);
    glVertex3f(2.2, 5.5, -5.0);
    glVertex3f(2.2, 6.0, -5.0);
    glVertex3f(2.5, 6.0, -5.0);
    glVertex3f(1.3, 4.0, -5.0);
    glVertex3f(1.0, 4.0, -5.0);
    glEnd();
    glFlush();
    //ISI
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 4.0, -5.0);
    glVertex3f(1.0, 4.5, -5.0);
    glVertex3f(1.5, 4.5, -5.0);
    glVertex3f(1.3, 4.0, -5.0);
    glVertex3f(1.0, 4.0, -5.0);
    glEnd();
    glFlush();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1.5, 4.5, -5.0);
    glVertex3f(1.5, 5.0, -5.0);
    glVertex3f(1.9, 5.0, -5.0);
    glEnd();
    glFlush;
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(2.2, 5.5, -5.0);
    glVertex3f(2.2, 6.0, -5.0);
    glVertex3f(2.5, 6.0, -5.0);
    glEnd();
    glFlush;
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1.9, 5.0, -5.0);
    glVertex3f(1.9, 5.5, -5.0);
    glVertex3f(2.2, 5.5, -5.0);
    glEnd();
    glFlush;

    //TAMBAHAN SISI ATAP BELAKANG KANAN
        //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.0, 4.0, -5.0);
    glVertex3f(4.0, 4.5, -5.0);
    glVertex3f(3.4, 4.5, -5.0);
    glVertex3f(3.4, 5.0, -5.0);
    glVertex3f(3.1, 5.0, -5.0);
    glVertex3f(3.1, 5.5, -5.0);
    glVertex3f(2.8, 5.5, -5.0);
    glVertex3f(2.8, 6.0, -5.0);
    glVertex3f(2.5, 6.0, -5.0);
    glVertex3f(3.7, 4.0, -5.0);
    glVertex3f(4.0, 4.0, -5.0);
    glEnd();
    glFlush();
    //ISI
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.0, 4.0, -5.0);
    glVertex3f(4.0, 4.5, -5.0);
    glVertex3f(3.4, 4.5, -5.0);
    glVertex3f(3.7, 4.0, -5.0);
    glVertex3f(4.0, 4.0, -5.0);
    glEnd();
    glFlush();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(3.4, 4.5, -5.0);
    glVertex3f(3.4, 5.0, -5.0);
    glVertex3f(3.1, 5.0, -5.0);
    glEnd();
    glFlush;
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(3.1, 5.0, -5.0);
    glVertex3f(3.1, 5.5, -5.0);
    glVertex3f(2.8, 5.5, -5.0);
    glEnd();
    glFlush;
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(2.8, 5.5, -5.0);
    glVertex3f(2.8, 6.0, -5.0);
    glVertex3f(2.5, 6.0, -5.0);
    glEnd();
    glFlush;


    //atap samping kanan
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(2.5, 6.0, 0.0);
    glVertex3f(3.7, 4.0, 0.0);
    glVertex3f(3.7, 4.0, -5.0);
    glVertex3f(2.5, 6.0, -5.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(2.5, 6.0, 0.0);
    glVertex3f(3.7, 4.0, 0.0);
    glVertex3f(3.7, 4.0, -5.0);
    glVertex3f(2.5, 6.0, -5.0);
    glEnd();
    glFlush();

    //ATAP KANAN 2
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.0, 6.0, -2.5);
    glVertex3f(4.0, 5.0, -2.0);
    glVertex3f(4.0, 5.0, -3.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.0, 6.0, -2.5);
    glVertex3f(4.0, 5.0, -2.0);
    glVertex3f(4.0, 5.0, -3.0);
    glEnd();
    glFlush();
    //ATAP KANAN 2 ATAP KIRI
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(4.0, 6.0, -2.5);
    glVertex3f(2.5, 6.0, -2.5);
    glVertex3f(3.0, 5.0, -2.0);
    glVertex3f(4.0, 5.0, -2.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.0, 6.0, -2.5);
    glVertex3f(2.5, 6.0, -2.5);
    glVertex3f(3.0, 5.0, -2.0);
    glVertex3f(4.0, 5.0, -2.0);
    glEnd();
    glFlush();
    //ATAP KANAN 2 ATAP KANAN
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(4.0, 6.0, -2.5);
    glVertex3f(2.5, 6.0, -2.5);
    glVertex3f(3.0, 5.0, -3.0);
    glVertex3f(4.0, 5.0, -3.0);
    glEnd();
    glFlush();
    //LINES
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.0, 6.0, -2.5);
    glVertex3f(2.5, 6.0, -2.5);
    glVertex3f(3.0, 5.0, -3.0);
    glVertex3f(4.0, 5.0, -3.0);
    glEnd();
    glFlush();
    //BAWAH ATAP 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.0, 5.0, -2.0);
    glVertex3f(4.0, 5.0, -3.0);
    glVertex3f(4.0, 4.0, -3.0);
    glVertex3f(4.0, 4.0, -2.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.0, 5.0, -2.0);
    glVertex3f(4.0, 5.0, -3.0);
    glVertex3f(4.0, 4.0, -3.0);
    glVertex3f(4.0, 4.0, -2.0);
    glEnd();
    glFlush();
    //SAMPING KANAN BAWAH ATAP 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.0, 5.0, -3.0);
    glVertex3f(4.0, 4.0, -3.0);
    glVertex3f(3.7, 4.0, -3.0);
    glVertex3f(3.0, 5.0, -3.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.0, 5.0, -3.0);
    glVertex3f(4.0, 4.0, -3.0);
    glVertex3f(3.7, 4.0, -3.0);
    glVertex3f(3.0, 5.0, -3.0);
    glEnd();
    glFlush();
    //SAMPING KIRI BAWAH ATAP 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.0, 5.0, -2.0);
    glVertex3f(4.0, 4.0, -2.0);
    glVertex3f(3.7, 4.0, -2.0);
    glVertex3f(3.0, 5.0, -2.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.0, 5.0, -2.0);
    glVertex3f(4.0, 4.0, -2.0);
    glVertex3f(3.7, 4.0, -2.0);
    glVertex3f(3.0, 5.0, -2.0);
    glEnd();
    glFlush();


    //atap samping kiri
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(2.5, 6.0, 0.0);
    glVertex3f(1.3, 4.0, 0.0);
    glVertex3f(1.3, 4.0, -5.0);
    glVertex3f(2.5, 6.0, -5.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(2.5, 6.0, 0.0);
    glVertex3f(1.3, 4.0, 0.0);
    glVertex3f(1.3, 4.0, -5.0);
    glVertex3f(2.5, 6.0, -5.0);
    glEnd();
    glFlush();

    //PAGAR KANAN BANGUNAN KIRI
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.0, 4.5, 0.0);
    glVertex3f(4.0, 4.5, -2.0);
    glEnd();
    glFlush();
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.0, 4.5, -0.2);
    glVertex3f(4.0, 4.0, -0.2);
    glVertex3f(4.0, 4.5, -0.4);
    glVertex3f(4.0, 4.0, -0.4);
    glVertex3f(4.0, 4.5, -0.6);
    glVertex3f(4.0, 4.0, -0.6);
    glVertex3f(4.0, 4.5, -0.8);
    glVertex3f(4.0, 4.0, -0.8);
    glVertex3f(4.0, 4.5, -1.0);
    glVertex3f(4.0, 4.0, -1.0);
    glVertex3f(4.0, 4.5, -1.2);
    glVertex3f(4.0, 4.0, -1.2);
    glVertex3f(4.0, 4.5, -1.4);
    glVertex3f(4.0, 4.0, -1.4);
    glVertex3f(4.0, 4.5, -1.6);
    glVertex3f(4.0, 4.0, -1.6);
    glVertex3f(4.0, 4.5, -1.8);
    glVertex3f(4.0, 4.0, -1.8);
    glEnd();
    glFlush();

    //PAGAR KANAN BANGUNAN KIRI
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.0, 4.5, -4.8);
    glVertex3f(4.0, 4.0, -4.8);
    glVertex3f(4.0, 4.5, -4.6);
    glVertex3f(4.0, 4.0, -4.6);
    glVertex3f(4.0, 4.5, -4.4);
    glVertex3f(4.0, 4.0, -4.4);
    glVertex3f(4.0, 4.5, -4.2);
    glVertex3f(4.0, 4.0, -4.2);
    glVertex3f(4.0, 4.5, -4.0);
    glVertex3f(4.0, 4.0, -4.0);
    glVertex3f(4.0, 4.5, -3.8);
    glVertex3f(4.0, 4.0, -3.8);
    glVertex3f(4.0, 4.5, -3.6);
    glVertex3f(4.0, 4.0, -3.6);
    glVertex3f(4.0, 4.5, -3.4);
    glVertex3f(4.0, 4.0, -3.4);
    glVertex3f(4.0, 4.5, -3.2);
    glVertex3f(4.0, 4.0, -3.2);

    glEnd();
    glFlush();
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.0, 4.5, -5.0);
    glVertex3f(4.0, 4.5, -3.0);
    glEnd();
    glFlush();

    //tower depan
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.3, 0.1);
    glVertex3f(-1.5, 9.0, -2.0);
    glVertex3f(-2.5, 9.0, -2.0);
    glVertex3f(-2.5, 1.0, -2.0);
    glVertex3f(-1.5, 1.0, -2.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-1.5, 9.0, -2.0);
    glVertex3f(-2.5, 9.0, -2.0);
    glVertex3f(-2.5, 1.0, -2.0);
    glVertex3f(-1.5, 1.0, -2.0);
    glEnd();
    glFlush();

    //tower belakang
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.3, 0.1);
    glVertex3f(-1.5, 9.0, -3.0);
    glVertex3f(-2.5, 9.0, -3.0);
    glVertex3f(-2.5, 1.0, -3.0);
    glVertex3f(-1.5, 1.0, -3.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-1.5, 9.0, -3.0);
    glVertex3f(-2.5, 9.0, -3.0);
    glVertex3f(-2.5, 1.0, -3.0);
    glVertex3f(-1.5, 1.0, -3.0);
    glEnd();
    glFlush();

    //tower kiri
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.3, 0.1);
    glVertex3f(-2.5, 9.0, -2.0);
    glVertex3f(-2.5, 1.0, -2.0);
    glVertex3f(-2.5, 1.0, -3.0);
    glVertex3f(-2.5, 9.0, -3.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-2.5, 9.0, -2.0);
    glVertex3f(-2.5, 1.0, -2.0);
    glVertex3f(-2.5, 1.0, -3.0);
    glVertex3f(-2.5, 9.0, -3.0);
    glEnd();
    glFlush();

    //tower kanan
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.3, 0.1);
    glVertex3f(-1.5, 9.0, -2.0);
    glVertex3f(-1.5, 1.0, -2.0);
    glVertex3f(-1.5, 1.0, -3.0);
    glVertex3f(-1.5, 9.0, -3.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-1.5, 9.0, -2.0);
    glVertex3f(-1.5, 1.0, -2.0);
    glVertex3f(-1.5, 1.0, -3.0);
    glVertex3f(-1.5, 9.0, -3.0);
    glEnd();
    glFlush();

    // tower atas
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 1.0);
    glVertex3f(-1.5, 9.0, -2.0);
    glVertex3f(-1.5, 9.0, -3.0);
    glVertex3f(-2.5, 9.0, -3.0);
    glVertex3f(-2.5, 9.0, -2.0);
    glEnd();
    glFlush();

    //atap tower depan
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.9, 1.0);
    glVertex3f(-2.0, 12.0, -2.5);
    glVertex3f(-1.7, 9.0, -2.2);
    glVertex3f(-2.3, 9.0, -2.2);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-2.0, 12.0, -2.5);
    glVertex3f(-1.7, 9.0, -2.2);
    glVertex3f(-2.3, 9.0, -2.2);
    glEnd();
    glFlush();

    //atap tower belakang
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.9, 1.0);
    glVertex3f(-2.0, 12.0, -2.5);
    glVertex3f(-1.7, 9.0, -2.8);
    glVertex3f(-2.3, 9.0, -2.8);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-2.0, 12.0, -2.5);
    glVertex3f(-1.7, 9.0, -2.8);
    glVertex3f(-2.3, 9.0, -2.8);
    glEnd();
    glFlush();

    //atap tower kiri
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.9, 1.0);
    glVertex3f(-2.0, 12.0, -2.5);
    glVertex3f(-2.3, 9.0, -2.2);
    glVertex3f(-2.3, 9.0, -2.8);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-2.0, 12.0, -2.5);
    glVertex3f(-2.3, 9.0, -2.2);
    glVertex3f(-2.3, 9.0, -2.8);
    glEnd();
    glFlush();

    //atap tower kanan
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.9, 1.0);
    glVertex3f(-2.0, 12.0, -2.5);
    glVertex3f(-1.7, 9.0, -2.2);
    glVertex3f(-1.7, 9.0, -2.8);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-2.0, 12.0, -2.5);
    glVertex3f(-1.7, 9.0, -2.2);
    glVertex3f(-1.7, 9.0, -2.8);
    glEnd();
    glFlush();

    //Pagar tower
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-1.5, 9.0, -2.0);
    glVertex3f(-1.5, 9.3, -2.0);
    glVertex3f(-1.5, 9.0, -3.0);
    glVertex3f(-1.5, 9.3, -3.0);
    glVertex3f(-2.5, 9.0, -3.0);
    glVertex3f(-2.5, 9.3, -3.0);
    glVertex3f(-2.5, 9.0, -2.0);
    glVertex3f(-2.5, 9.3, -2.0);
    glEnd();
    glFlush();
    // KERANGKA PAGAR
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-1.5, 9.3, -2.0);
    glVertex3f(-1.5, 9.3, -3.0);
    glVertex3f(-2.5, 9.3, -3.0);
    glVertex3f(-2.5, 9.3, -2.0);
    glEnd();
    glFlush();
    // PAGAR DEPAN
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-2.3, 9.3, -2.0);
    glVertex3f(-2.3, 9.0, -2.0);
    glVertex3f(-2.1, 9.3, -2.0);
    glVertex3f(-2.1, 9.0, -2.0);
    glVertex3f(-1.9, 9.3, -2.0);
    glVertex3f(-1.9, 9.0, -2.0);
    glVertex3f(-1.7, 9.3, -2.0);
    glVertex3f(-1.7, 9.0, -2.0);
    glEnd();
    glFlush();
    //PAGAR KANAN
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-1.5, 9.3, -2.0);
    glVertex3f(-1.5, 9.0, -2.0);
    glVertex3f(-1.5, 9.3, -2.2);
    glVertex3f(-1.5, 9.0, -2.2);
    glVertex3f(-1.5, 9.3, -2.4);
    glVertex3f(-1.5, 9.0, -2.4);
    glVertex3f(-1.5, 9.3, -2.6);
    glVertex3f(-1.5, 9.0, -2.6);
    glVertex3f(-1.5, 9.3, -2.8);
    glVertex3f(-1.5, 9.0, -2.8);
    glEnd();
    glFlush();
    //PAGAR BELAKANG
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-2.3, 9.3, -3.0);
    glVertex3f(-2.3, 9.0, -3.0);
    glVertex3f(-2.1, 9.3, -3.0);
    glVertex3f(-2.1, 9.0, -3.0);
    glVertex3f(-1.9, 9.3, -3.0);
    glVertex3f(-1.9, 9.0, -3.0);
    glVertex3f(-1.7, 9.3, -3.0);
    glVertex3f(-1.7, 9.0, -3.0);
    glEnd();
    glFlush();
    //PAGAR KIRI
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-2.5, 9.3, -2.0);
    glVertex3f(-2.5, 9.0, -2.0);
    glVertex3f(-2.5, 9.3, -2.2);
    glVertex3f(-2.5, 9.0, -2.2);
    glVertex3f(-2.5, 9.3, -2.4);
    glVertex3f(-2.5, 9.0, -2.4);
    glVertex3f(-2.5, 9.3, -2.6);
    glVertex3f(-2.5, 9.0, -2.6);
    glVertex3f(-2.5, 9.3, -2.8);
    glVertex3f(-2.5, 9.0, -2.8);
    glEnd();
    glFlush();

    // GERBANG 1
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.05, 1.0, -0.3);
    glVertex3f(4.05, 2.0, -0.3);
    glVertex3f(4.05, 2.2, -0.4);
    glVertex3f(4.05, 2.2, -0.6);
    glVertex3f(4.05, 2.0, -0.7);
    glVertex3f(4.05, 1.0, -0.7);
    glVertex3f(4.05, 1.0, -0.3);
    glEnd();
    glFlush();

    //GERBANG 2
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.05, 1.0, -0.8);
    glVertex3f(4.05, 2.0, -0.8);
    glVertex3f(4.05, 2.2, -0.9);
    glVertex3f(4.05, 2.2, -1.1);
    glVertex3f(4.05, 2.0, -1.2);
    glVertex3f(4.05, 1.0, -1.2);
    glVertex3f(4.05, 1.0, -0.8);
    glEnd();
    glFlush();

    //GERBANG 3
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.05, 1.0, -1.3);
    glVertex3f(4.05, 2.0, -1.3);
    glVertex3f(4.05, 2.2, -1.4);
    glVertex3f(4.05, 2.2, -1.6);
    glVertex3f(4.05, 2.0, -1.7);
    glVertex3f(4.05, 1.0, -1.7);
    glVertex3f(4.05, 1.0, -1.3);
    glEnd();
    glFlush();

    //GERBANG 4
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.05, 1.0, -1.8);
    glVertex3f(4.05, 2.0, -1.8);
    glVertex3f(4.05, 2.2, -1.9);
    glVertex3f(4.05, 2.2, -2.1);
    glVertex3f(4.05, 2.0, -2.2);
    glVertex3f(4.05, 1.0, -2.2);
    glVertex3f(4.05, 1.0, -1.8);
    glEnd();
    glFlush();

    //GERBANG 5
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.05, 1.0, -2.3);
    glVertex3f(4.05, 2.0, -2.3);
    glVertex3f(4.05, 2.2, -2.4);
    glVertex3f(4.05, 2.2, -2.6);
    glVertex3f(4.05, 2.0, -2.7);
    glVertex3f(4.05, 1.0, -2.7);
    glVertex3f(4.05, 1.0, -2.3);
    glEnd();
    glFlush();

    //GERBANG 6
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.05, 1.0, -2.8);
    glVertex3f(4.05, 2.0, -2.8);
    glVertex3f(4.05, 2.2, -2.9);
    glVertex3f(4.05, 2.2, -3.1);
    glVertex3f(4.05, 2.0, -3.2);
    glVertex3f(4.05, 1.0, -3.2);
    glVertex3f(4.05, 1.0, -2.8);
    glEnd();
    glFlush();

    //GERBANG 7
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.05, 1.0, -3.3);
    glVertex3f(4.05, 2.0, -3.3);
    glVertex3f(4.05, 2.2, -3.4);
    glVertex3f(4.05, 2.2, -3.6);
    glVertex3f(4.05, 2.0, -3.7);
    glVertex3f(4.05, 1.0, -3.7);
    glVertex3f(4.05, 1.0, -3.3);
    glEnd();
    glFlush();

    //GERBANG 8
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.05, 1.0, -3.8);
    glVertex3f(4.05, 2.0, -3.8);
    glVertex3f(4.05, 2.2, -3.9);
    glVertex3f(4.05, 2.2, -4.1);
    glVertex3f(4.05, 2.0, -4.2);
    glVertex3f(4.05, 1.0, -4.2);
    glVertex3f(4.05, 1.0, -3.8);
    glEnd();
    glFlush();

    //GERBANG 9
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.05, 1.0, -4.3);
    glVertex3f(4.05, 2.0, -4.3);
    glVertex3f(4.05, 2.2, -4.4);
    glVertex3f(4.05, 2.2, -4.6);
    glVertex3f(4.05, 2.0, -4.7);
    glVertex3f(4.05, 1.0, -4.7);
    glVertex3f(4.05, 1.0, -4.3);
    glEnd();
    glFlush();

    //Gerbang KANAN 1
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(3.8, 1.0, -5.05);
    glVertex3f(3.8, 2.0, -5.05);
    glVertex3f(3.7, 2.2, -5.05);
    glVertex3f(3.5, 2.2, -5.05);
    glVertex3f(3.4, 2.0, -5.05);
    glVertex3f(3.4, 1.0, -5.05);
    glVertex3f(3.8, 1.0, -5.05);
    glEnd();
    glFlush();

    //Gerbang KANAN 2
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(3.3, 1.0, -5.05);
    glVertex3f(3.3, 2.0, -5.05);
    glVertex3f(3.2, 2.2, -5.05);
    glVertex3f(3.0, 2.2, -5.05);
    glVertex3f(2.9, 2.0, -5.05);
    glVertex3f(2.9, 1.0, -5.05);
    glVertex3f(3.3, 1.0, -5.05);
    glEnd();
    glFlush();

    //Gerbang KIRI 1
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(3.8, 1.0, 0.05);
    glVertex3f(3.8, 2.0, 0.05);
    glVertex3f(3.7, 2.2, 0.05);
    glVertex3f(3.5, 2.2, 0.05);
    glVertex3f(3.4, 2.0, 0.05);
    glVertex3f(3.4, 1.0, 0.05);
    glVertex3f(3.8, 1.0, 0.05);
    glEnd();
    glFlush();

    //Gerbang KANAN 2
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(3.3, 1.0, 0.05);
    glVertex3f(3.3, 2.0, 0.05);
    glVertex3f(3.2, 2.2, 0.05);
    glVertex3f(3.0, 2.2, 0.05);
    glVertex3f(2.9, 2.0, 0.05);
    glVertex3f(2.9, 1.0, 0.05);
    glVertex3f(3.3, 1.0, 0.05);
    glEnd();
    glFlush();

    //JENDELA 1
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(4.01, 2.5, -0.3);
    glVertex3f(4.01, 3.8, -0.3);
    glVertex3f(4.01, 3.8, -0.8);
    glVertex3f(4.01, 2.5, -0.8);
    glVertex3f(4.01, 2.5, -0.3);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.01, 2.5, -0.3);
    glVertex3f(4.01, 3.8, -0.3);
    glVertex3f(4.01, 3.8, -0.8);
    glVertex3f(4.01, 2.5, -0.8);
    glVertex3f(4.01, 2.5, -0.3);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.01, 3.6, -0.3);
    glVertex3f(4.01, 3.6, -0.8);
    glVertex3f(4.01, 3.3, -0.3);
    glVertex3f(4.01, 3.3, -0.8);
    glVertex3f(4.01, 3.8, -0.45);
    glVertex3f(4.01, 2.5, -0.45);
    glVertex3f(4.01, 3.8, -0.65);
    glVertex3f(4.01, 2.5, -0.65);
    glEnd();
    glFlush();

    //JENDELA 2
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(4.01, 2.5, -0.9);
    glVertex3f(4.01, 3.8, -0.9);
    glVertex3f(4.01, 3.8, -1.4);
    glVertex3f(4.01, 2.5, -1.4);
    glVertex3f(4.01, 2.5, -0.9);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.01, 2.5, -0.9);
    glVertex3f(4.01, 3.8, -0.9);
    glVertex3f(4.01, 3.8, -1.4);
    glVertex3f(4.01, 2.5, -1.4);
    glVertex3f(4.01, 2.5, -0.9);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.01, 3.6, -0.9);
    glVertex3f(4.01, 3.6, -1.4);
    glVertex3f(4.01, 3.3, -0.9);
    glVertex3f(4.01, 3.3, -1.4);
    glVertex3f(4.01, 3.8, -1.05);
    glVertex3f(4.01, 2.5, -1.05);
    glVertex3f(4.01, 3.8, -1.25);
    glVertex3f(4.01, 2.5, -1.25);
    glEnd();
    glFlush();

    //JENDELA 3
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(4.01, 2.5, -1.5);
    glVertex3f(4.01, 3.8, -1.5);
    glVertex3f(4.01, 3.8, -2.0);
    glVertex3f(4.01, 2.5, -2.0);
    glVertex3f(4.01, 2.5, -1.5);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.01, 2.5, -1.5);
    glVertex3f(4.01, 3.8, -1.5);
    glVertex3f(4.01, 3.8, -2.0);
    glVertex3f(4.01, 2.5, -2.0);
    glVertex3f(4.01, 2.5, -1.5);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.01, 3.6, -1.5);
    glVertex3f(4.01, 3.6, -2.0);
    glVertex3f(4.01, 3.3, -1.5);
    glVertex3f(4.01, 3.3, -2.0);
    glVertex3f(4.01, 3.8, -1.65);
    glVertex3f(4.01, 2.5, -1.65);
    glVertex3f(4.01, 3.8, -1.85);
    glVertex3f(4.01, 2.5, -1.85);
    glEnd();
    glFlush();

    //JENDELA 4
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(4.01, 2.5, -2.1);
    glVertex3f(4.01, 3.8, -2.1);
    glVertex3f(4.01, 3.8, -2.6);
    glVertex3f(4.01, 2.5, -2.6);
    glVertex3f(4.01, 2.5, -2.1);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.01, 2.5, -2.1);
    glVertex3f(4.01, 3.8, -2.1);
    glVertex3f(4.01, 3.8, -2.6);
    glVertex3f(4.01, 2.5, -2.6);
    glVertex3f(4.01, 2.5, -2.1);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.01, 3.6, -2.1);
    glVertex3f(4.01, 3.6, -2.6);
    glVertex3f(4.01, 3.3, -2.1);
    glVertex3f(4.01, 3.3, -2.6);
    glVertex3f(4.01, 3.8, -2.25);
    glVertex3f(4.01, 2.5, -2.25);
    glVertex3f(4.01, 3.8, -2.45);
    glVertex3f(4.01, 2.5, -2.45);
    glEnd();
    glFlush();

    //JENDELA 5
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(4.01, 2.5, -2.7);
    glVertex3f(4.01, 3.8, -2.7);
    glVertex3f(4.01, 3.8, -3.2);
    glVertex3f(4.01, 2.5, -3.2);
    glVertex3f(4.01, 2.5, -2.7);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.01, 2.5, -2.7);
    glVertex3f(4.01, 3.8, -2.7);
    glVertex3f(4.01, 3.8, -3.2);
    glVertex3f(4.01, 2.5, -3.2);
    glVertex3f(4.01, 2.5, -2.1);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.01, 3.6, -2.7);
    glVertex3f(4.01, 3.6, -3.2);
    glVertex3f(4.01, 3.3, -2.7);
    glVertex3f(4.01, 3.3, -3.2);
    glVertex3f(4.01, 3.8, -2.85);
    glVertex3f(4.01, 2.5, -2.85);
    glVertex3f(4.01, 3.8, -3.05);
    glVertex3f(4.01, 2.5, -3.05);
    glEnd();
    glFlush();

    //JENDELA 6
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(4.01, 2.5, -3.3);
    glVertex3f(4.01, 3.8, -3.3);
    glVertex3f(4.01, 3.8, -3.8);
    glVertex3f(4.01, 2.5, -3.8);
    glVertex3f(4.01, 2.5, -3.3);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.01, 2.5, -3.3);
    glVertex3f(4.01, 3.8, -3.3);
    glVertex3f(4.01, 3.8, -3.8);
    glVertex3f(4.01, 2.5, -3.8);
    glVertex3f(4.01, 2.5, -3.3);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.01, 3.6, -3.3);
    glVertex3f(4.01, 3.6, -3.8);
    glVertex3f(4.01, 3.3, -3.3);
    glVertex3f(4.01, 3.3, -3.8);
    glVertex3f(4.01, 3.8, -3.45);
    glVertex3f(4.01, 2.5, -3.45);
    glVertex3f(4.01, 3.8, -3.65);
    glVertex3f(4.01, 2.5, -3.65);
    glEnd();
    glFlush();

    //JENDELA 7
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(4.01, 2.5, -3.9);
    glVertex3f(4.01, 3.8, -3.9);
    glVertex3f(4.01, 3.8, -4.4);
    glVertex3f(4.01, 2.5, -4.4);
    glVertex3f(4.01, 2.5, -3.9);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.01, 2.5, -3.9);
    glVertex3f(4.01, 3.8, -3.9);
    glVertex3f(4.01, 3.8, -4.4);
    glVertex3f(4.01, 2.5, -4.4);
    glVertex3f(4.01, 2.5, -3.9);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.01, 3.6, -3.9);
    glVertex3f(4.01, 3.6, -4.4);
    glVertex3f(4.01, 3.3, -3.9);
    glVertex3f(4.01, 3.3, -4.4);
    glVertex3f(4.01, 3.8, -4.05);
    glVertex3f(4.01, 2.5, -4.05);
    glVertex3f(4.01, 3.8, -4.25);
    glVertex3f(4.01, 2.5, -4.25);
    glEnd();
    glFlush();

    //JENDELA 8
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(4.01, 2.5, -4.5);
    glVertex3f(4.01, 3.8, -4.5);
    glVertex3f(4.01, 3.8, -4.9);
    glVertex3f(4.01, 2.5, -4.9);
    glVertex3f(4.01, 2.5, -4.5);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.01, 2.5, -4.5);
    glVertex3f(4.01, 3.8, -4.5);
    glVertex3f(4.01, 3.8, -4.9);
    glVertex3f(4.01, 2.5, -4.9);
    glVertex3f(4.01, 2.5, -4.5);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.01, 3.6, -4.5);
    glVertex3f(4.01, 3.6, -4.9);
    glVertex3f(4.01, 3.3, -4.5);
    glVertex3f(4.01, 3.3, -4.9);
    glVertex3f(4.01, 3.8, -4.65);
    glVertex3f(4.01, 2.5, -4.65);
    glVertex3f(4.01, 3.8, -4.77);
    glVertex3f(4.01, 2.5, -4.77);
    glEnd();
    glFlush();

    //JENDELA KANAN 1
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(3.8, 2.5, -5.01);
    glVertex3f(3.8, 3.8, -5.01);
    glVertex3f(3.3, 3.8, -5.01);
    glVertex3f(3.3, 2.5, -5.01);
    glVertex3f(3.8, 2.5, -5.01);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(3.8, 2.5, -5.01);
    glVertex3f(3.8, 3.8, -5.01);
    glVertex3f(3.3, 3.8, -5.01);
    glVertex3f(3.3, 2.5, -5.01);
    glVertex3f(3.8, 2.5, -5.01);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(3.3, 3.6, -5.01);
    glVertex3f(3.8, 3.6, -5.01);
    glVertex3f(3.3, 3.3, -5.01);
    glVertex3f(3.8, 3.3, -5.01);
    glVertex3f(3.45, 3.8, -5.01);
    glVertex3f(3.45, 2.5, -5.01);
    glVertex3f(3.65, 3.8, -5.01);
    glVertex3f(3.65, 2.5, -5.01);
    glEnd();
    glFlush();

    //JENDELA KANAN 2
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(3.2, 2.5, -5.01);
    glVertex3f(3.2, 3.8, -5.01);
    glVertex3f(2.7, 3.8, -5.01);
    glVertex3f(2.7, 2.5, -5.01);
    glVertex3f(3.2, 2.5, -5.01);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(3.2, 2.5, -5.01);
    glVertex3f(3.2, 3.8, -5.01);
    glVertex3f(2.7, 3.8, -5.01);
    glVertex3f(2.7, 2.5, -5.01);
    glVertex3f(3.2, 2.5, -5.01);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(2.7, 3.6, -5.01);
    glVertex3f(3.2, 3.6, -5.01);
    glVertex3f(2.7, 3.3, -5.01);
    glVertex3f(3.2, 3.3, -5.01);
    glVertex3f(2.85, 3.8, -5.01);
    glVertex3f(2.85, 2.5, -5.01);
    glVertex3f(3.05, 3.8, -5.01);
    glVertex3f(3.05, 2.5, -5.01);
    glEnd();
    glFlush();

    //JENDELA KIRI 1
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(3.8, 2.5, 0.01);
    glVertex3f(3.8, 3.8, 0.01);
    glVertex3f(3.3, 3.8, 0.01);
    glVertex3f(3.3, 2.5, 0.01);
    glVertex3f(3.8, 2.5, 0.01);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(3.8, 2.5, 0.01);
    glVertex3f(3.8, 3.8, 0.01);
    glVertex3f(3.3, 3.8, 0.01);
    glVertex3f(3.3, 2.5, 0.01);
    glVertex3f(3.8, 2.5, 0.01);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(3.3, 3.6, 0.01);
    glVertex3f(3.8, 3.6, 0.01);
    glVertex3f(3.3, 3.3, 0.01);
    glVertex3f(3.8, 3.3, 0.01);
    glVertex3f(3.45, 3.8, 0.01);
    glVertex3f(3.45, 2.5, 0.01);
    glVertex3f(3.65, 3.8, 0.01);
    glVertex3f(3.65, 2.5, 0.01);
    glEnd();
    glFlush();

    //JENDELA KIRI 2
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(3.2, 2.5, 0.01);
    glVertex3f(3.2, 3.8, 0.01);
    glVertex3f(2.7, 3.8, 0.01);
    glVertex3f(2.7, 2.5, 0.01);
    glVertex3f(3.2, 2.5, 0.01);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(3.2, 2.5, 0.01);
    glVertex3f(3.2, 3.8, 0.01);
    glVertex3f(2.7, 3.8, 0.01);
    glVertex3f(2.7, 2.5, 0.01);
    glVertex3f(3.2, 2.5, 0.01);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(2.7, 3.6, 0.01);
    glVertex3f(3.2, 3.6, 0.01);
    glVertex3f(2.7, 3.3, 0.01);
    glVertex3f(3.2, 3.3, 0.01);
    glVertex3f(2.85, 3.8, 0.01);
    glVertex3f(2.85, 2.5, 0.01);
    glVertex3f(3.05, 3.8, 0.01);
    glVertex3f(3.05, 2.5, 0.01);
    glEnd();
    glFlush();


    //GEDUNG KIRI
        //DIDING KIRI
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 1.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(-5.0, 1.0, 0.0);
    glVertex3f(-5.0, 4.0, 0.0);
    glVertex3f(1.0, 4.0, 0.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(-5.0, 1.0, 0.0);
    glVertex3f(-5.0, 4.0, 0.0);
    glVertex3f(1.0, 4.0, 0.0);
    glEnd();
    glFlush();
    //DIDING KANAN
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 1.0);
    glVertex3f(1.0, 1.0, -1.3);
    glVertex3f(-5.0, 1.0, -1.3);
    glVertex3f(-5.0, 4.0, -1.3);
    glVertex3f(1.0, 4.0, -1.3);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 1.0, -1.3);
    glVertex3f(-5.0, 1.0, -1.3);
    glVertex3f(-5.0, 4.0, -1.3);
    glVertex3f(1.0, 4.0, -1.3);
    glEnd();
    glFlush();
    //DIDING BELKANG
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 1.0);
    glVertex3f(-5.0, 1.0, -1.3);
    glVertex3f(-5.0, 1.0, 0.0);
    glVertex3f(-5.0, 4.0, 0.0);
    glVertex3f(-5.0, 4.0, -1.3);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-5.0, 1.0, -1.3);
    glVertex3f(-5.0, 1.0, 0.0);
    glVertex3f(-5.0, 4.0, 0.0);
    glVertex3f(-5.0, 4.0, -1.3);
    glEnd();
    glFlush();
    //DIDING ATAS
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 1.0);
    glVertex3f(-5.0, 4.0, 0.0);
    glVertex3f(1.0, 4.0, 0.0);
    glVertex3f(1.0, 4.0, -1.3);
    glVertex3f(-5.0, 4.0, -1.3);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-5.0, 4.0, 0.0);
    glVertex3f(1.0, 4.0, 0.0);
    glVertex3f(1.0, 4.0, -1.3);
    glVertex3f(-5.0, 4.0, -1.3);
    glEnd();
    glFlush();
    // ATAP DEPAN
    glBegin(GL_TRIANGLES);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(0.9, 4.0, -0.2);
    glVertex3f(0.9, 4.0, -1.1);
    glVertex3f(0.9, 5.0, -0.6);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.9, 4.0, -0.2);
    glVertex3f(0.9, 4.0, -1.1);
    glVertex3f(0.9, 5.0, -0.6);
    glEnd();
    glFlush();
    // ATAP BELAKANG
    glBegin(GL_TRIANGLES);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-4.9, 4.0, -0.2);
    glVertex3f(-4.9, 4.0, -1.1);
    glVertex3f(-4.9, 5.0, -0.6);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-4.9, 4.0, -0.2);
    glVertex3f(-4.9, 4.0, -1.1);
    glVertex3f(-4.9, 5.0, -0.6);
    glEnd();
    glFlush();
    //ATAP KIRI
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(0.9, 5.0, -0.6);
    glVertex3f(0.9, 4.0, -0.2);
    glVertex3f(-4.9, 4.0, -0.2);
    glVertex3f(-4.9, 5.0, -0.6);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.9, 5.0, -0.6);
    glVertex3f(0.9, 4.0, -0.2);
    glVertex3f(-4.9, 4.0, -0.2);
    glVertex3f(-4.9, 5.0, -0.6);
    glEnd();
    glFlush();
    //ATAP KANAN
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(0.9, 5.0, -0.6);
    glVertex3f(0.9, 4.0, -1.1);
    glVertex3f(-4.9, 4.0, -1.1);
    glVertex3f(-4.9, 5.0, -0.6);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.9, 5.0, -0.6);
    glVertex3f(0.9, 4.0, -1.1);
    glVertex3f(-4.9, 4.0, -1.1);
    glVertex3f(-4.9, 5.0, -0.6);
    glEnd();
    glFlush();



    //GEDUNG KANAN
        //DIDING KIRI
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 1.0);
    glVertex3f(1.0, 1.0, -3.7);
    glVertex3f(-5.0, 1.0, -3.7);
    glVertex3f(-5.0, 4.0, -3.7);
    glVertex3f(1.0, 4.0, -3.7);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 1.0, -3.7);
    glVertex3f(-5.0, 1.0, -3.7);
    glVertex3f(-5.0, 4.0, -3.7);
    glVertex3f(1.0, 4.0, -3.7);
    glEnd();
    glFlush();
    //DIDING KANAN
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 1.0);
    glVertex3f(1.0, 1.0, -5.0);
    glVertex3f(-5.0, 1.0, -5.0);
    glVertex3f(-5.0, 4.0, -5.0);
    glVertex3f(1.0, 4.0, -5.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 1.0, -5.0);
    glVertex3f(-5.0, 1.0, -5.0);
    glVertex3f(-5.0, 4.0, -5.0);
    glVertex3f(1.0, 4.0, -5.0);
    glEnd();
    glFlush();
    //DIDING BELKANG
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 1.0);
    glVertex3f(-5.0, 1.0, -3.7);
    glVertex3f(-5.0, 1.0, -5.0);
    glVertex3f(-5.0, 4.0, -5.0);
    glVertex3f(-5.0, 4.0, -3.7);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-5.0, 1.0, -3.7);
    glVertex3f(-5.0, 1.0, -5.0);
    glVertex3f(-5.0, 4.0, -5.0);
    glVertex3f(-5.0, 4.0, -3.7);
    glEnd();
    glFlush();
    //DIDING ATAS
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-5.0, 4.0, -5.0);
    glVertex3f(1.0, 4.0, -5.0);
    glVertex3f(1.0, 4.0, -3.7);
    glVertex3f(-5.0, 4.0, -3.7);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-5.0, 4.0, -5.0);
    glVertex3f(1.0, 4.0, -5.0);
    glVertex3f(1.0, 4.0, -3.7);
    glVertex3f(-5.0, 4.0, -3.7);
    glEnd();
    glFlush();
    // ATAP DEPAN
    glBegin(GL_TRIANGLES);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(0.9, 4.0, -4.8);
    glVertex3f(0.9, 4.0, -3.9);
    glVertex3f(0.9, 5.0, -4.4);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.9, 4.0, -4.8);
    glVertex3f(0.9, 4.0, -3.9);
    glVertex3f(0.9, 5.0, -4.4);
    glEnd();
    glFlush();
    // ATAP BELAKANG
    glBegin(GL_TRIANGLES);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-4.9, 4.0, -4.8);
    glVertex3f(-4.9, 4.0, -3.9);
    glVertex3f(-4.9, 5.0, -4.4);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-4.9, 4.0, -4.8);
    glVertex3f(-4.9, 4.0, -3.9);
    glVertex3f(-4.9, 5.0, -4.4);
    glEnd();
    glFlush();
    //ATAP KIRI
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(0.9, 5.0, -4.4);
    glVertex3f(0.9, 4.0, -3.9);
    glVertex3f(-4.9, 4.0, -3.9);
    glVertex3f(-4.9, 5.0, -4.4);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.9, 5.0, -4.4);
    glVertex3f(0.9, 4.0, -3.9);
    glVertex3f(-4.9, 4.0, -3.9);
    glVertex3f(-4.9, 5.0, -4.4);
    glEnd();
    glFlush();
    //ATAP KANAN
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(0.9, 5.0, -4.4);
    glVertex3f(0.9, 4.0, -4.8);
    glVertex3f(-4.9, 4.0, -4.8);
    glVertex3f(-4.9, 5.0, -4.4);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.9, 5.0, -0.6);
    glVertex3f(0.9, 4.0, -1.1);
    glVertex3f(-4.9, 4.0, -1.1);
    glVertex3f(-4.9, 5.0, -0.6);
    glEnd();
    glFlush();

    //GEDUNG BELAKANG
    glPushMatrix();
    glTranslatef(-4.0, 0.0, -5.0);
    glRotatef(180.0, 0.0, 1.0, 0.0);

    // DEPAN
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.3, 0.1);
    glVertex3f(1.0, 4.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(4.0, 1.0, 0.0);
    glVertex3f(4.0, 4.0, 0.0);
    glEnd();
    glFlush;
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 4.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(4.0, 1.0, 0.0);
    glVertex3f(4.0, 4.0, 0.0);
    glEnd();
    glFlush;

    // kanan
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 1.0);
    glVertex3f(4.0, 1.0, 0.0);
    glVertex3f(4.0, 4.0, 0.0);
    glVertex3f(4.0, 4.0, -5.0);
    glVertex3f(4.0, 1.0, -5.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.0, 1.0, 0.0);
    glVertex3f(4.0, 4.0, 0.0);
    glVertex3f(4.0, 4.0, -5.0);
    glVertex3f(4.0, 1.0, -5.0);
    glEnd();
    glFlush();

    //Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 1.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, 4.0, 0.0);
    glVertex3f(1.0, 4.0, -5.0);
    glVertex3f(1.0, 1.0, -5.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, 4.0, 0.0);
    glVertex3f(1.0, 4.0, -5.0);
    glVertex3f(1.0, 1.0, -5.0);
    glEnd();
    glFlush();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.3, 0.1);
    glVertex3f(1.0, 4.0, -5.0);
    glVertex3f(1.0, 1.0, -5.0);
    glVertex3f(4.0, 1.0, -5.0);
    glVertex3f(4.0, 4.0, -5.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 4.0, -5.0);
    glVertex3f(1.0, 1.0, -5.0);
    glVertex3f(4.0, 1.0, -5.0);
    glVertex3f(4.0, 4.0, -5.0);
    glEnd();
    glFlush();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 1.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(4.0, 1.0, 0.0);
    glVertex3f(4.0, 1.0, -5.0);
    glVertex3f(1.0, 1.0, -5.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(4.0, 1.0, 0.0);
    glVertex3f(4.0, 1.0, -5.0);
    glVertex3f(1.0, 1.0, -5.0);
    glEnd();
    glFlush();

    //Atas
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 1.0);
    glVertex3f(1.0, 4.0, 0.0);
    glVertex3f(4.0, 4.0, 0.0);
    glVertex3f(4.0, 4.0, -5.0);
    glVertex3f(1.0, 4.0, -5.0);
    glEnd();
    glFlush();

    //Atap depan
    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.3, 0.1);
    glVertex3f(1.3, 4.0, 0.0);
    glVertex3f(3.7, 4.0, 0.0);
    glVertex3f(2.5, 6.0, 0.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3f(1.2, 4.0, 0.0);
    glVertex3f(3.7, 4.0, 0.0);
    glVertex3f(2.5, 6.0, 0.0);
    glEnd();
    glFlush();

    //TAMBAHAN SISI ATAP DEPAN  KIRI
        //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 4.0, 0.0);
    glVertex3f(1.0, 4.5, 0.0);
    glVertex3f(1.5, 4.5, 0.0);
    glVertex3f(1.5, 5.0, 0.0);
    glVertex3f(1.9, 5.0, 0.0);
    glVertex3f(1.9, 5.5, 0.0);
    glVertex3f(2.2, 5.5, 0.0);
    glVertex3f(2.2, 6.0, 0.0);
    glVertex3f(2.5, 6.0, 0.0);
    glVertex3f(1.3, 4.0, 0.0);
    glVertex3f(1.0, 4.0, 0.0);
    glEnd();
    glFlush();
    //ISI
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 4.0, 0.0);
    glVertex3f(1.0, 4.5, 0.0);
    glVertex3f(1.5, 4.5, 0.0);
    glVertex3f(1.3, 4.0, 0.0);
    glVertex3f(1.0, 4.0, 0.0);
    glEnd();
    glFlush();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1.5, 4.5, 0.0);
    glVertex3f(1.5, 5.0, 0.0);
    glVertex3f(1.9, 5.0, 0.0);
    glEnd();
    glFlush;
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(2.2, 5.5, 0.0);
    glVertex3f(2.2, 6.0, 0.0);
    glVertex3f(2.5, 6.0, 0.0);
    glEnd();
    glFlush;
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1.9, 5.0, 0.0);
    glVertex3f(1.9, 5.5, 0.0);
    glVertex3f(2.2, 5.5, 0.0);
    glEnd();
    glFlush;


    //TAMBAHAN SISI ATAP DEPAN KANAN
        //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.0, 4.0, 0.0);
    glVertex3f(4.0, 4.5, 0.0);
    glVertex3f(3.4, 4.5, 0.0);
    glVertex3f(3.4, 5.0, 0.0);
    glVertex3f(3.1, 5.0, 0.0);
    glVertex3f(3.1, 5.5, 0.0);
    glVertex3f(2.8, 5.5, 0.0);
    glVertex3f(2.8, 6.0, 0.0);
    glVertex3f(2.5, 6.0, 0.0);
    glVertex3f(3.7, 4.0, 0.0);
    glVertex3f(4.0, 4.0, 0.0);
    glEnd();
    glFlush();
    //ISI
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.0, 4.0, 0.0);
    glVertex3f(4.0, 4.5, 0.0);
    glVertex3f(3.4, 4.5, 0.0);
    glVertex3f(3.7, 4.0, 0.0);
    glVertex3f(4.0, 4.0, 0.0);
    glEnd();
    glFlush();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(3.4, 4.5, 0.0);
    glVertex3f(3.4, 5.0, 0.0);
    glVertex3f(3.1, 5.0, 0.0);
    glEnd();
    glFlush;
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(3.1, 5.0, 0.0);
    glVertex3f(3.1, 5.5, 0.0);
    glVertex3f(2.8, 5.5, 0.0);
    glEnd();
    glFlush;
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(2.8, 5.5, 0.0);
    glVertex3f(2.8, 6.0, 0.0);
    glVertex3f(2.5, 6.0, 0.0);
    glEnd();
    glFlush;



    //Atap belakang
    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.3, 0.1);
    glVertex3f(1.3, 4.0, -5.0);
    glVertex3f(3.7, 4.0, -5.0);
    glVertex3f(2.5, 6.0, -5.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.3, 4.0, -5.0);
    glVertex3f(3.7, 4.0, -5.0);
    glVertex3f(2.5, 6.0, -5.0);
    glEnd();
    glFlush();

    //TAMBAHAN SISI ATAP BELAKANG  KIRI
        //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 4.0, -5.0);
    glVertex3f(1.0, 4.5, -5.0);
    glVertex3f(1.5, 4.5, -5.0);
    glVertex3f(1.5, 5.0, -5.0);
    glVertex3f(1.9, 5.0, -5.0);
    glVertex3f(1.9, 5.5, -5.0);
    glVertex3f(2.2, 5.5, -5.0);
    glVertex3f(2.2, 6.0, -5.0);
    glVertex3f(2.5, 6.0, -5.0);
    glVertex3f(1.3, 4.0, -5.0);
    glVertex3f(1.0, 4.0, -5.0);
    glEnd();
    glFlush();
    //ISI
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 4.0, -5.0);
    glVertex3f(1.0, 4.5, -5.0);
    glVertex3f(1.5, 4.5, -5.0);
    glVertex3f(1.3, 4.0, -5.0);
    glVertex3f(1.0, 4.0, -5.0);
    glEnd();
    glFlush();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1.5, 4.5, -5.0);
    glVertex3f(1.5, 5.0, -5.0);
    glVertex3f(1.9, 5.0, -5.0);
    glEnd();
    glFlush;
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(2.2, 5.5, -5.0);
    glVertex3f(2.2, 6.0, -5.0);
    glVertex3f(2.5, 6.0, -5.0);
    glEnd();
    glFlush;
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1.9, 5.0, -5.0);
    glVertex3f(1.9, 5.5, -5.0);
    glVertex3f(2.2, 5.5, -5.0);
    glEnd();
    glFlush;

    //TAMBAHAN SISI ATAP BELAKANG KANAN
        //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.0, 4.0, -5.0);
    glVertex3f(4.0, 4.5, -5.0);
    glVertex3f(3.4, 4.5, -5.0);
    glVertex3f(3.4, 5.0, -5.0);
    glVertex3f(3.1, 5.0, -5.0);
    glVertex3f(3.1, 5.5, -5.0);
    glVertex3f(2.8, 5.5, -5.0);
    glVertex3f(2.8, 6.0, -5.0);
    glVertex3f(2.5, 6.0, -5.0);
    glVertex3f(3.7, 4.0, -5.0);
    glVertex3f(4.0, 4.0, -5.0);
    glEnd();
    glFlush();
    //ISI
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.0, 4.0, -5.0);
    glVertex3f(4.0, 4.5, -5.0);
    glVertex3f(3.4, 4.5, -5.0);
    glVertex3f(3.7, 4.0, -5.0);
    glVertex3f(4.0, 4.0, -5.0);
    glEnd();
    glFlush();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(3.4, 4.5, -5.0);
    glVertex3f(3.4, 5.0, -5.0);
    glVertex3f(3.1, 5.0, -5.0);
    glEnd();
    glFlush;
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(3.1, 5.0, -5.0);
    glVertex3f(3.1, 5.5, -5.0);
    glVertex3f(2.8, 5.5, -5.0);
    glEnd();
    glFlush;
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(2.8, 5.5, -5.0);
    glVertex3f(2.8, 6.0, -5.0);
    glVertex3f(2.5, 6.0, -5.0);
    glEnd();
    glFlush;


    //atap samping kanan
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(2.5, 6.0, 0.0);
    glVertex3f(3.7, 4.0, 0.0);
    glVertex3f(3.7, 4.0, -5.0);
    glVertex3f(2.5, 6.0, -5.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(2.5, 6.0, 0.0);
    glVertex3f(3.7, 4.0, 0.0);
    glVertex3f(3.7, 4.0, -5.0);
    glVertex3f(2.5, 6.0, -5.0);
    glEnd();
    glFlush();

    //ATAP KANAN 2
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.0, 6.0, -2.5);
    glVertex3f(4.0, 5.0, -2.0);
    glVertex3f(4.0, 5.0, -3.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.0, 6.0, -2.5);
    glVertex3f(4.0, 5.0, -2.0);
    glVertex3f(4.0, 5.0, -3.0);
    glEnd();
    glFlush();
    //ATAP KANAN 2 ATAP KIRI
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(4.0, 6.0, -2.5);
    glVertex3f(2.5, 6.0, -2.5);
    glVertex3f(3.0, 5.0, -2.0);
    glVertex3f(4.0, 5.0, -2.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.0, 6.0, -2.5);
    glVertex3f(2.5, 6.0, -2.5);
    glVertex3f(3.0, 5.0, -2.0);
    glVertex3f(4.0, 5.0, -2.0);
    glEnd();
    glFlush();
    //ATAP KANAN 2 ATAP KANAN
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(4.0, 6.0, -2.5);
    glVertex3f(2.5, 6.0, -2.5);
    glVertex3f(3.0, 5.0, -3.0);
    glVertex3f(4.0, 5.0, -3.0);
    glEnd();
    glFlush();
    //LINES
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.0, 6.0, -2.5);
    glVertex3f(2.5, 6.0, -2.5);
    glVertex3f(3.0, 5.0, -3.0);
    glVertex3f(4.0, 5.0, -3.0);
    glEnd();
    glFlush();
    //BAWAH ATAP 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.0, 5.0, -2.0);
    glVertex3f(4.0, 5.0, -3.0);
    glVertex3f(4.0, 4.0, -3.0);
    glVertex3f(4.0, 4.0, -2.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.0, 5.0, -2.0);
    glVertex3f(4.0, 5.0, -3.0);
    glVertex3f(4.0, 4.0, -3.0);
    glVertex3f(4.0, 4.0, -2.0);
    glEnd();
    glFlush();
    //SAMPING KANAN BAWAH ATAP 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.0, 5.0, -3.0);
    glVertex3f(4.0, 4.0, -3.0);
    glVertex3f(3.7, 4.0, -3.0);
    glVertex3f(3.0, 5.0, -3.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.0, 5.0, -3.0);
    glVertex3f(4.0, 4.0, -3.0);
    glVertex3f(3.7, 4.0, -3.0);
    glVertex3f(3.0, 5.0, -3.0);
    glEnd();
    glFlush();
    //SAMPING KIRI BAWAH ATAP 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.0, 5.0, -2.0);
    glVertex3f(4.0, 4.0, -2.0);
    glVertex3f(3.7, 4.0, -2.0);
    glVertex3f(3.0, 5.0, -2.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.0, 5.0, -2.0);
    glVertex3f(4.0, 4.0, -2.0);
    glVertex3f(3.7, 4.0, -2.0);
    glVertex3f(3.0, 5.0, -2.0);
    glEnd();
    glFlush();


    //atap samping kiri
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(2.5, 6.0, 0.0);
    glVertex3f(1.3, 4.0, 0.0);
    glVertex3f(1.3, 4.0, -5.0);
    glVertex3f(2.5, 6.0, -5.0);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(2.5, 6.0, 0.0);
    glVertex3f(1.3, 4.0, 0.0);
    glVertex3f(1.3, 4.0, -5.0);
    glVertex3f(2.5, 6.0, -5.0);
    glEnd();
    glFlush();

    //PAGAR KANAN BANGUNAN KIRI
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.0, 4.5, 0.0);
    glVertex3f(4.0, 4.5, -2.0);
    glEnd();
    glFlush();
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.0, 4.5, -0.2);
    glVertex3f(4.0, 4.0, -0.2);
    glVertex3f(4.0, 4.5, -0.4);
    glVertex3f(4.0, 4.0, -0.4);
    glVertex3f(4.0, 4.5, -0.6);
    glVertex3f(4.0, 4.0, -0.6);
    glVertex3f(4.0, 4.5, -0.8);
    glVertex3f(4.0, 4.0, -0.8);
    glVertex3f(4.0, 4.5, -1.0);
    glVertex3f(4.0, 4.0, -1.0);
    glVertex3f(4.0, 4.5, -1.2);
    glVertex3f(4.0, 4.0, -1.2);
    glVertex3f(4.0, 4.5, -1.4);
    glVertex3f(4.0, 4.0, -1.4);
    glVertex3f(4.0, 4.5, -1.6);
    glVertex3f(4.0, 4.0, -1.6);
    glVertex3f(4.0, 4.5, -1.8);
    glVertex3f(4.0, 4.0, -1.8);
    glEnd();
    glFlush();

    //PAGAR KANAN BANGUNAN KIRI
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.0, 4.5, -4.8);
    glVertex3f(4.0, 4.0, -4.8);
    glVertex3f(4.0, 4.5, -4.6);
    glVertex3f(4.0, 4.0, -4.6);
    glVertex3f(4.0, 4.5, -4.4);
    glVertex3f(4.0, 4.0, -4.4);
    glVertex3f(4.0, 4.5, -4.2);
    glVertex3f(4.0, 4.0, -4.2);
    glVertex3f(4.0, 4.5, -4.0);
    glVertex3f(4.0, 4.0, -4.0);
    glVertex3f(4.0, 4.5, -3.8);
    glVertex3f(4.0, 4.0, -3.8);
    glVertex3f(4.0, 4.5, -3.6);
    glVertex3f(4.0, 4.0, -3.6);
    glVertex3f(4.0, 4.5, -3.4);
    glVertex3f(4.0, 4.0, -3.4);
    glVertex3f(4.0, 4.5, -3.2);
    glVertex3f(4.0, 4.0, -3.2);

    glEnd();
    glFlush();
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.0, 4.5, -5.0);
    glVertex3f(4.0, 4.5, -3.0);
    glEnd();
    glFlush();

    // GERBANG 1
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.05, 1.0, -0.3);
    glVertex3f(4.05, 2.0, -0.3);
    glVertex3f(4.05, 2.2, -0.4);
    glVertex3f(4.05, 2.2, -0.6);
    glVertex3f(4.05, 2.0, -0.7);
    glVertex3f(4.05, 1.0, -0.7);
    glVertex3f(4.05, 1.0, -0.3);
    glEnd();
    glFlush();

    //GERBANG 2
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.05, 1.0, -0.8);
    glVertex3f(4.05, 2.0, -0.8);
    glVertex3f(4.05, 2.2, -0.9);
    glVertex3f(4.05, 2.2, -1.1);
    glVertex3f(4.05, 2.0, -1.2);
    glVertex3f(4.05, 1.0, -1.2);
    glVertex3f(4.05, 1.0, -0.8);
    glEnd();
    glFlush();

    //GERBANG 3
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.05, 1.0, -1.3);
    glVertex3f(4.05, 2.0, -1.3);
    glVertex3f(4.05, 2.2, -1.4);
    glVertex3f(4.05, 2.2, -1.6);
    glVertex3f(4.05, 2.0, -1.7);
    glVertex3f(4.05, 1.0, -1.7);
    glVertex3f(4.05, 1.0, -1.3);
    glEnd();
    glFlush();

    //GERBANG 4
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.05, 1.0, -1.8);
    glVertex3f(4.05, 2.0, -1.8);
    glVertex3f(4.05, 2.2, -1.9);
    glVertex3f(4.05, 2.2, -2.1);
    glVertex3f(4.05, 2.0, -2.2);
    glVertex3f(4.05, 1.0, -2.2);
    glVertex3f(4.05, 1.0, -1.8);
    glEnd();
    glFlush();

    //GERBANG 5
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.05, 1.0, -2.3);
    glVertex3f(4.05, 2.0, -2.3);
    glVertex3f(4.05, 2.2, -2.4);
    glVertex3f(4.05, 2.2, -2.6);
    glVertex3f(4.05, 2.0, -2.7);
    glVertex3f(4.05, 1.0, -2.7);
    glVertex3f(4.05, 1.0, -2.3);
    glEnd();
    glFlush();

    //GERBANG 6
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.05, 1.0, -2.8);
    glVertex3f(4.05, 2.0, -2.8);
    glVertex3f(4.05, 2.2, -2.9);
    glVertex3f(4.05, 2.2, -3.1);
    glVertex3f(4.05, 2.0, -3.2);
    glVertex3f(4.05, 1.0, -3.2);
    glVertex3f(4.05, 1.0, -2.8);
    glEnd();
    glFlush();

    //GERBANG 7
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.05, 1.0, -3.3);
    glVertex3f(4.05, 2.0, -3.3);
    glVertex3f(4.05, 2.2, -3.4);
    glVertex3f(4.05, 2.2, -3.6);
    glVertex3f(4.05, 2.0, -3.7);
    glVertex3f(4.05, 1.0, -3.7);
    glVertex3f(4.05, 1.0, -3.3);
    glEnd();
    glFlush();

    //GERBANG 8
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.05, 1.0, -3.8);
    glVertex3f(4.05, 2.0, -3.8);
    glVertex3f(4.05, 2.2, -3.9);
    glVertex3f(4.05, 2.2, -4.1);
    glVertex3f(4.05, 2.0, -4.2);
    glVertex3f(4.05, 1.0, -4.2);
    glVertex3f(4.05, 1.0, -3.8);
    glEnd();
    glFlush();

    //GERBANG 9
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.05, 1.0, -4.3);
    glVertex3f(4.05, 2.0, -4.3);
    glVertex3f(4.05, 2.2, -4.4);
    glVertex3f(4.05, 2.2, -4.6);
    glVertex3f(4.05, 2.0, -4.7);
    glVertex3f(4.05, 1.0, -4.7);
    glVertex3f(4.05, 1.0, -4.3);
    glEnd();
    glFlush();

    //Gerbang KANAN 1
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(3.8, 1.0, -5.05);
    glVertex3f(3.8, 2.0, -5.05);
    glVertex3f(3.7, 2.2, -5.05);
    glVertex3f(3.5, 2.2, -5.05);
    glVertex3f(3.4, 2.0, -5.05);
    glVertex3f(3.4, 1.0, -5.05);
    glVertex3f(3.8, 1.0, -5.05);
    glEnd();
    glFlush();

    //Gerbang KANAN 2
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(3.3, 1.0, -5.05);
    glVertex3f(3.3, 2.0, -5.05);
    glVertex3f(3.2, 2.2, -5.05);
    glVertex3f(3.0, 2.2, -5.05);
    glVertex3f(2.9, 2.0, -5.05);
    glVertex3f(2.9, 1.0, -5.05);
    glVertex3f(3.3, 1.0, -5.05);
    glEnd();
    glFlush();

    //Gerbang KIRI 1
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(3.8, 1.0, 0.05);
    glVertex3f(3.8, 2.0, 0.05);
    glVertex3f(3.7, 2.2, 0.05);
    glVertex3f(3.5, 2.2, 0.05);
    glVertex3f(3.4, 2.0, 0.05);
    glVertex3f(3.4, 1.0, 0.05);
    glVertex3f(3.8, 1.0, 0.05);
    glEnd();
    glFlush();

    //Gerbang KANAN 2
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(3.3, 1.0, 0.05);
    glVertex3f(3.3, 2.0, 0.05);
    glVertex3f(3.2, 2.2, 0.05);
    glVertex3f(3.0, 2.2, 0.05);
    glVertex3f(2.9, 2.0, 0.05);
    glVertex3f(2.9, 1.0, 0.05);
    glVertex3f(3.3, 1.0, 0.05);
    glEnd();
    glFlush();


    //JENDELA 1
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(4.01, 2.5, -0.3);
    glVertex3f(4.01, 3.8, -0.3);
    glVertex3f(4.01, 3.8, -0.8);
    glVertex3f(4.01, 2.5, -0.8);
    glVertex3f(4.01, 2.5, -0.3);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.01, 2.5, -0.3);
    glVertex3f(4.01, 3.8, -0.3);
    glVertex3f(4.01, 3.8, -0.8);
    glVertex3f(4.01, 2.5, -0.8);
    glVertex3f(4.01, 2.5, -0.3);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.01, 3.6, -0.3);
    glVertex3f(4.01, 3.6, -0.8);
    glVertex3f(4.01, 3.3, -0.3);
    glVertex3f(4.01, 3.3, -0.8);
    glVertex3f(4.01, 3.8, -0.45);
    glVertex3f(4.01, 2.5, -0.45);
    glVertex3f(4.01, 3.8, -0.65);
    glVertex3f(4.01, 2.5, -0.65);
    glEnd();
    glFlush();

    //JENDELA 2
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(4.01, 2.5, -0.9);
    glVertex3f(4.01, 3.8, -0.9);
    glVertex3f(4.01, 3.8, -1.4);
    glVertex3f(4.01, 2.5, -1.4);
    glVertex3f(4.01, 2.5, -0.9);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.01, 2.5, -0.9);
    glVertex3f(4.01, 3.8, -0.9);
    glVertex3f(4.01, 3.8, -1.4);
    glVertex3f(4.01, 2.5, -1.4);
    glVertex3f(4.01, 2.5, -0.9);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.01, 3.6, -0.9);
    glVertex3f(4.01, 3.6, -1.4);
    glVertex3f(4.01, 3.3, -0.9);
    glVertex3f(4.01, 3.3, -1.4);
    glVertex3f(4.01, 3.8, -1.05);
    glVertex3f(4.01, 2.5, -1.05);
    glVertex3f(4.01, 3.8, -1.25);
    glVertex3f(4.01, 2.5, -1.25);
    glEnd();
    glFlush();

    //JENDELA 3
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(4.01, 2.5, -1.5);
    glVertex3f(4.01, 3.8, -1.5);
    glVertex3f(4.01, 3.8, -2.0);
    glVertex3f(4.01, 2.5, -2.0);
    glVertex3f(4.01, 2.5, -1.5);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.01, 2.5, -1.5);
    glVertex3f(4.01, 3.8, -1.5);
    glVertex3f(4.01, 3.8, -2.0);
    glVertex3f(4.01, 2.5, -2.0);
    glVertex3f(4.01, 2.5, -1.5);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.01, 3.6, -1.5);
    glVertex3f(4.01, 3.6, -2.0);
    glVertex3f(4.01, 3.3, -1.5);
    glVertex3f(4.01, 3.3, -2.0);
    glVertex3f(4.01, 3.8, -1.65);
    glVertex3f(4.01, 2.5, -1.65);
    glVertex3f(4.01, 3.8, -1.85);
    glVertex3f(4.01, 2.5, -1.85);
    glEnd();
    glFlush();

    //JENDELA 4
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(4.01, 2.5, -2.1);
    glVertex3f(4.01, 3.8, -2.1);
    glVertex3f(4.01, 3.8, -2.6);
    glVertex3f(4.01, 2.5, -2.6);
    glVertex3f(4.01, 2.5, -2.1);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.01, 2.5, -2.1);
    glVertex3f(4.01, 3.8, -2.1);
    glVertex3f(4.01, 3.8, -2.6);
    glVertex3f(4.01, 2.5, -2.6);
    glVertex3f(4.01, 2.5, -2.1);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.01, 3.6, -2.1);
    glVertex3f(4.01, 3.6, -2.6);
    glVertex3f(4.01, 3.3, -2.1);
    glVertex3f(4.01, 3.3, -2.6);
    glVertex3f(4.01, 3.8, -2.25);
    glVertex3f(4.01, 2.5, -2.25);
    glVertex3f(4.01, 3.8, -2.45);
    glVertex3f(4.01, 2.5, -2.45);
    glEnd();
    glFlush();

    //JENDELA 5
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(4.01, 2.5, -2.7);
    glVertex3f(4.01, 3.8, -2.7);
    glVertex3f(4.01, 3.8, -3.2);
    glVertex3f(4.01, 2.5, -3.2);
    glVertex3f(4.01, 2.5, -2.7);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.01, 2.5, -2.7);
    glVertex3f(4.01, 3.8, -2.7);
    glVertex3f(4.01, 3.8, -3.2);
    glVertex3f(4.01, 2.5, -3.2);
    glVertex3f(4.01, 2.5, -2.1);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.01, 3.6, -2.7);
    glVertex3f(4.01, 3.6, -3.2);
    glVertex3f(4.01, 3.3, -2.7);
    glVertex3f(4.01, 3.3, -3.2);
    glVertex3f(4.01, 3.8, -2.85);
    glVertex3f(4.01, 2.5, -2.85);
    glVertex3f(4.01, 3.8, -3.05);
    glVertex3f(4.01, 2.5, -3.05);
    glEnd();
    glFlush();

    //JENDELA 6
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(4.01, 2.5, -3.3);
    glVertex3f(4.01, 3.8, -3.3);
    glVertex3f(4.01, 3.8, -3.8);
    glVertex3f(4.01, 2.5, -3.8);
    glVertex3f(4.01, 2.5, -3.3);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.01, 2.5, -3.3);
    glVertex3f(4.01, 3.8, -3.3);
    glVertex3f(4.01, 3.8, -3.8);
    glVertex3f(4.01, 2.5, -3.8);
    glVertex3f(4.01, 2.5, -3.3);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.01, 3.6, -3.3);
    glVertex3f(4.01, 3.6, -3.8);
    glVertex3f(4.01, 3.3, -3.3);
    glVertex3f(4.01, 3.3, -3.8);
    glVertex3f(4.01, 3.8, -3.45);
    glVertex3f(4.01, 2.5, -3.45);
    glVertex3f(4.01, 3.8, -3.65);
    glVertex3f(4.01, 2.5, -3.65);
    glEnd();
    glFlush();

    //JENDELA 7
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(4.01, 2.5, -3.9);
    glVertex3f(4.01, 3.8, -3.9);
    glVertex3f(4.01, 3.8, -4.4);
    glVertex3f(4.01, 2.5, -4.4);
    glVertex3f(4.01, 2.5, -3.9);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.01, 2.5, -3.9);
    glVertex3f(4.01, 3.8, -3.9);
    glVertex3f(4.01, 3.8, -4.4);
    glVertex3f(4.01, 2.5, -4.4);
    glVertex3f(4.01, 2.5, -3.9);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.01, 3.6, -3.9);
    glVertex3f(4.01, 3.6, -4.4);
    glVertex3f(4.01, 3.3, -3.9);
    glVertex3f(4.01, 3.3, -4.4);
    glVertex3f(4.01, 3.8, -4.05);
    glVertex3f(4.01, 2.5, -4.05);
    glVertex3f(4.01, 3.8, -4.25);
    glVertex3f(4.01, 2.5, -4.25);
    glEnd();
    glFlush();

    //JENDELA 8
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(4.01, 2.5, -4.5);
    glVertex3f(4.01, 3.8, -4.5);
    glVertex3f(4.01, 3.8, -4.9);
    glVertex3f(4.01, 2.5, -4.9);
    glVertex3f(4.01, 2.5, -4.5);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.01, 2.5, -4.5);
    glVertex3f(4.01, 3.8, -4.5);
    glVertex3f(4.01, 3.8, -4.9);
    glVertex3f(4.01, 2.5, -4.9);
    glVertex3f(4.01, 2.5, -4.5);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4.01, 3.6, -4.5);
    glVertex3f(4.01, 3.6, -4.9);
    glVertex3f(4.01, 3.3, -4.5);
    glVertex3f(4.01, 3.3, -4.9);
    glVertex3f(4.01, 3.8, -4.65);
    glVertex3f(4.01, 2.5, -4.65);
    glVertex3f(4.01, 3.8, -4.77);
    glVertex3f(4.01, 2.5, -4.77);
    glEnd();
    glFlush();

    //JENDELA KANAN 1
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(3.8, 2.5, -5.01);
    glVertex3f(3.8, 3.8, -5.01);
    glVertex3f(3.3, 3.8, -5.01);
    glVertex3f(3.3, 2.5, -5.01);
    glVertex3f(3.8, 2.5, -5.01);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(3.8, 2.5, -5.01);
    glVertex3f(3.8, 3.8, -5.01);
    glVertex3f(3.3, 3.8, -5.01);
    glVertex3f(3.3, 2.5, -5.01);
    glVertex3f(3.8, 2.5, -5.01);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(3.3, 3.6, -5.01);
    glVertex3f(3.8, 3.6, -5.01);
    glVertex3f(3.3, 3.3, -5.01);
    glVertex3f(3.8, 3.3, -5.01);
    glVertex3f(3.45, 3.8, -5.01);
    glVertex3f(3.45, 2.5, -5.01);
    glVertex3f(3.65, 3.8, -5.01);
    glVertex3f(3.65, 2.5, -5.01);
    glEnd();
    glFlush();

    //JENDELA KANAN 2
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(3.2, 2.5, -5.01);
    glVertex3f(3.2, 3.8, -5.01);
    glVertex3f(2.7, 3.8, -5.01);
    glVertex3f(2.7, 2.5, -5.01);
    glVertex3f(3.2, 2.5, -5.01);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(3.2, 2.5, -5.01);
    glVertex3f(3.2, 3.8, -5.01);
    glVertex3f(2.7, 3.8, -5.01);
    glVertex3f(2.7, 2.5, -5.01);
    glVertex3f(3.2, 2.5, -5.01);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(2.7, 3.6, -5.01);
    glVertex3f(3.2, 3.6, -5.01);
    glVertex3f(2.7, 3.3, -5.01);
    glVertex3f(3.2, 3.3, -5.01);
    glVertex3f(2.85, 3.8, -5.01);
    glVertex3f(2.85, 2.5, -5.01);
    glVertex3f(3.05, 3.8, -5.01);
    glVertex3f(3.05, 2.5, -5.01);
    glEnd();
    glFlush();

    //JENDELA KIRI 1
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(3.8, 2.5, 0.01);
    glVertex3f(3.8, 3.8, 0.01);
    glVertex3f(3.3, 3.8, 0.01);
    glVertex3f(3.3, 2.5, 0.01);
    glVertex3f(3.8, 2.5, 0.01);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(3.8, 2.5, 0.01);
    glVertex3f(3.8, 3.8, 0.01);
    glVertex3f(3.3, 3.8, 0.01);
    glVertex3f(3.3, 2.5, 0.01);
    glVertex3f(3.8, 2.5, 0.01);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(3.3, 3.6, 0.01);
    glVertex3f(3.8, 3.6, 0.01);
    glVertex3f(3.3, 3.3, 0.01);
    glVertex3f(3.8, 3.3, 0.01);
    glVertex3f(3.45, 3.8, 0.01);
    glVertex3f(3.45, 2.5, 0.01);
    glVertex3f(3.65, 3.8, 0.01);
    glVertex3f(3.65, 2.5, 0.01);
    glEnd();
    glFlush();

    //JENDELA KIRI 2
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(3.2, 2.5, 0.01);
    glVertex3f(3.2, 3.8, 0.01);
    glVertex3f(2.7, 3.8, 0.01);
    glVertex3f(2.7, 2.5, 0.01);
    glVertex3f(3.2, 2.5, 0.01);
    glEnd();
    glFlush();
    //LINE
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(3.2, 2.5, 0.01);
    glVertex3f(3.2, 3.8, 0.01);
    glVertex3f(2.7, 3.8, 0.01);
    glVertex3f(2.7, 2.5, 0.01);
    glVertex3f(3.2, 2.5, 0.01);
    glEnd();
    glFlush();
    //TERALIS JENDELA
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(2.7, 3.6, 0.01);
    glVertex3f(3.2, 3.6, 0.01);
    glVertex3f(2.7, 3.3, 0.01);
    glVertex3f(3.2, 3.3, 0.01);
    glVertex3f(2.85, 3.8, 0.01);
    glVertex3f(2.85, 2.5, 0.01);
    glVertex3f(3.05, 3.8, 0.01);
    glVertex3f(3.05, 2.5, 0.01);
    glEnd();
    glFlush();

    glPopMatrix();


    glPopMatrix();

}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'a' || key == 'A') {
        glTranslatef(1.0, 0.0, 0.0);
    }
    if (key == 'd' || key == 'D') {
        glTranslatef(-1.0, 0.0, 0.0);
    }
    if (key == 's' || key == 'S') {
        glTranslatef(0.0, 0.0, -1.0);
    }
    if (key == 'w' || key == 'W') {
        glTranslatef(0.0, 0.0, 1.0);
    }

    tampilan();
}


void resize(int width, int height)
{
    if (height == 0) height = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, width / height, 1.0, 400.0);
    glTranslatef(0.0, -5.0, -15.0);
    glMatrixMode(GL_MODELVIEW);
}

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.0, 1.0, 0.906, 0.0);
    glLineWidth(5.0);
    glEnable(GL_DEPTH_TEST);
}


void main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1080, 720);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Universiteit Bibliotheek KU Leuven");
    glutDisplayFunc(tampilan);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
    glutReshapeFunc(resize);
    myinit();
    glutMainLoop();
}