#include <iostream>
#include <GL/glut.h>



void draw_circle(double rad, double dx, double dy) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        double angle = i * 3.141592 / 180;
        double x = rad * cos(angle);
        double y = rad * sin(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void draw_��(double rad, double dx, double dy) {
    draw_circle(rad, dx, dy);
    glColor3f(1, 1, 1);
    draw_circle(rad - 0.07, dx, dy);
    glColor3f(0, 0, 0);
}

void draw_��(double dx, double dy) {
    glBegin(GL_POLYGON);
    glVertex2f(-0.05f + dx, -0.1f + dy);
    glVertex2f(-0.2f + dx, -0.1f + dy);
    glVertex2f(-0.2f + dx, 0.0f + dy);
    glVertex2f(0.2f + dx, 0.0f + dy);
    glVertex2f(0.2f + dx, -0.1f + dy);
    glVertex2f(0.05f + dx, -0.1f + dy);
    glVertex2f(0.2f + dx, -0.3f + dy);
    glVertex2f(0.1f + dx, -0.3f + dy);
    glVertex2f(0.0f + dx, -0.15f + dy);
    glVertex2f(-0.1f + dx, -0.3f + dy);
    glVertex2f(-0.2f + dx, -0.3f + dy);
    glVertex2f(-0.05f + dx, -0.1f + dy);
    glEnd();
}

void draw_��(double dx, double dy) {
    glBegin(GL_POLYGON);
    glVertex2f(-0.05f + dx, 0.0f + dy);
    glVertex2f(-0.05f + dx, 0.1f + dy);
    glVertex2f(0.05f + dx, 0.1f + dy);
    glVertex2f(0.05f + dx, 0.0f + dy);
    glVertex2f(0.2f + dx, 0.0f + dy);
    glVertex2f(0.2f + dx, -0.1f + dy);
    glVertex2f(-0.2f + dx, -0.1f + dy);
    glVertex2f(-0.2f + dx, -0.1f + dy);
    glVertex2f(-0.2f + dx, 0.0f + dy);
    glVertex2f(-0.05f + dx, 0.0f + dy);
    glEnd();
}


void draw_��(double dx, double dy) {
    glPushMatrix();
    glTranslatef(dx, dy, 0.0f);
    glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
    draw_��(0.0, 0.0);
    glPopMatrix();
}


void draw_��(double rad, double dx, double dy) {
    draw_��(dx, dy);
    draw_��(rad, dx + 0.0025, dy - 0.25);
}

void draw_��(double dx, double dy) {
    // ���μ� (�β� ����)
    glBegin(GL_POLYGON);
    glVertex2f(dx + 0.05f, dy + 0.2f);   // ���μ� ����
    glVertex2f(dx + 0.05f, dy - 0.1f);   // ���μ� �Ʒ���
    glVertex2f(dx - 0.05f, dy - 0.1f);   // ���μ� �Ʒ���
    glVertex2f(dx - 0.05f, dy + 0.2f);   // ���μ� ����
    glEnd();

    // ���μ� (�β� ����)
    glBegin(GL_POLYGON);
    glVertex2f(dx - 0.05f, dy + 0.2f);   // ������ ��
    glVertex2f(dx - 0.15f, dy + 0.2f);   // ���� ��
    glVertex2f(dx - 0.15f, dy + 0.1f);   // ���� �Ʒ�
    glVertex2f(dx - 0.05f, dy + 0.1f);    // ������ �Ʒ�
    glEnd();
}




void draw_��(double dx, double dy) {
    // ���� �� 
    glBegin(GL_POLYGON);
    glVertex2f(-0.05f + dx, -0.05f + dy); 
    glVertex2f(-0.05f + dx, 0.4f + dy);    
    glVertex2f(0.05f + dx, 0.4f + dy);
    glVertex2f(0.05f + dx, -0.05f + dy);   
    glEnd();

    // ù ��° ���μ�
    glBegin(GL_POLYGON);
    glVertex2f(-0.2f + dx, 0.25f + dy);
    glVertex2f(0.05f + dx, 0.25f + dy);
    glVertex2f(0.05f + dx, 0.15f + dy);
    glVertex2f(-0.2f + dx, 0.15f + dy);
    glEnd();

    // �� ��° ���μ�
    glBegin(GL_POLYGON);
    glVertex2f(-0.2f + dx, 0.1f + dy);
    glVertex2f(0.05f + dx, 0.1f + dy);
    glVertex2f(0.05f + dx, 0.0f + dy);
    glVertex2f(-0.2f + dx, 0.0f + dy);
    glEnd();
}

void display_name() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f);

    double rad = 0.13;

    // "��"
    draw_��(-0.7, 0.5);
    draw_��(-0.3, 0.4);
    draw_��(rad, -0.5, 0.0);

    // "��"
    draw_��(rad, 0.2, 0.5);
    draw_��(0.6, 0.2);
    draw_��(0.5, -0.1);

    glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); //GLUT ���̺귯�� �ʱ�ȭ �� ��� �÷����� ������ �ý��۰� ����
	glutCreateWindow //â ����
	("OpenGL");
	glutDisplayFunc(display_name); //�Լ� ����ȭ
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //��� �� ����
	glutMainLoop(); //���� �̺�Ʈ ����
	return 0;
}


