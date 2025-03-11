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

void draw_ㅇ(double rad, double dx, double dy) {
    draw_circle(rad, dx, dy);
    glColor3f(1, 1, 1);
    draw_circle(rad - 0.07, dx, dy);
    glColor3f(0, 0, 0);
}

void draw_ㅈ(double dx, double dy) {
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

void draw_ㅗ(double dx, double dy) {
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


void draw_ㅏ(double dx, double dy) {
    glPushMatrix();
    glTranslatef(dx, dy, 0.0f);
    glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
    draw_ㅗ(0.0, 0.0);
    glPopMatrix();
}


void draw_ㅎ(double rad, double dx, double dy) {
    draw_ㅗ(dx, dy);
    draw_ㅇ(rad, dx + 0.0025, dy - 0.25);
}

void draw_ㄱ(double dx, double dy) {
    // 세로선 (두께 조정)
    glBegin(GL_POLYGON);
    glVertex2f(dx + 0.05f, dy + 0.2f);   // 세로선 위쪽
    glVertex2f(dx + 0.05f, dy - 0.1f);   // 세로선 아래쪽
    glVertex2f(dx - 0.05f, dy - 0.1f);   // 세로선 아래쪽
    glVertex2f(dx - 0.05f, dy + 0.2f);   // 세로선 위쪽
    glEnd();

    // 가로선 (두께 조정)
    glBegin(GL_POLYGON);
    glVertex2f(dx - 0.05f, dy + 0.2f);   // 오른쪽 위
    glVertex2f(dx - 0.15f, dy + 0.2f);   // 왼쪽 위
    glVertex2f(dx - 0.15f, dy + 0.1f);   // 왼쪽 아래
    glVertex2f(dx - 0.05f, dy + 0.1f);    // 오른쪽 아래
    glEnd();
}




void draw_ㅕ(double dx, double dy) {
    // 세로 선 
    glBegin(GL_POLYGON);
    glVertex2f(-0.05f + dx, -0.05f + dy); 
    glVertex2f(-0.05f + dx, 0.4f + dy);    
    glVertex2f(0.05f + dx, 0.4f + dy);
    glVertex2f(0.05f + dx, -0.05f + dy);   
    glEnd();

    // 첫 번째 가로선
    glBegin(GL_POLYGON);
    glVertex2f(-0.2f + dx, 0.25f + dy);
    glVertex2f(0.05f + dx, 0.25f + dy);
    glVertex2f(0.05f + dx, 0.15f + dy);
    glVertex2f(-0.2f + dx, 0.15f + dy);
    glEnd();

    // 두 번째 가로선
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

    // "장"
    draw_ㅈ(-0.7, 0.5);
    draw_ㅏ(-0.3, 0.4);
    draw_ㅇ(rad, -0.5, 0.0);

    // "혁"
    draw_ㅎ(rad, 0.2, 0.5);
    draw_ㅕ(0.6, 0.2);
    draw_ㄱ(0.5, -0.1);

    glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); //GLUT 라이브러리 초기화 및 기반 플랫폼의 윈도우 시스템과 연결
	glutCreateWindow //창 생성
	("OpenGL");
	glutDisplayFunc(display_name); //함수 가시화
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //배경 색 설정
	glutMainLoop(); //무한 이벤트 루프
	return 0;
}


