이 코드는 OpenGl을 사용하여 한글 문자를 그리는 프로그램이다. GLUT 라이브러리를 사용하여 윈도우를 생성하고 랜더링한다.

주요 함수들은 다음과 같다.

1. draw_circle
• 이 함수는 주어진 반지름(rad)과 중심 좌표(dx, dy)를 기반으로 원을 그린다.
• 360도 각도를 사용하여 원의 모든 꼭지점을 계산하고 glVertex2f를 통해 그린다.


void draw_circle(double rad, double dx, double dy){
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        double angle = i * 3.141592 / 180; // 각도를 라디안으로 변환
        double x = rad * cos(angle); // x 좌표 계산
        double y = rad * sin(angle); // y 좌표 계산
        glVertex2f(x + dx, y + dy); // 최종 좌표로 그리기
    }
    glEnd();
}


draw_ㅇ
• "ㅇ" 글자를 그리는 함수이다. 먼저 큰 원을 그리고, 그 안에 작은 원을 그려 내부를 비워준다.
• 외부 원은 검정색, 내부 원은 흰색으로 설정하여 "ㅇ" 모양을 완성한다.

void draw_ㅇ(double rad, double dx, double dy) {
    draw_circle(rad, dx, dy); // 외부 원 그리기
    glColor3f(1, 1, 1); // 내부 원 색상 (흰색)
    draw_circle(rad - 0.07, dx, dy); // 내부 원 그리기
    glColor3f(0, 0, 0); // 외부 원 색상 (검정색)
}


draw_ㅈ
• "ㅈ" 글자를 그리는 함수입니다. 여러 꼭지점을 사용하여 복잡한 다각형 형태를 만들어낸다.
• 각 꼭지점의 좌표를 설정하여 "ㅈ" 모양을 완성한다.

void draw_ㅈ(double dx, double dy) {
    glBegin(GL_POLYGON);
    glVertex2f(-0.05f + dx, -0.1f + dy); // 아래 왼쪽
    glVertex2f(-0.2f + dx, -0.1f + dy); // 아래 왼쪽
    glVertex2f(-0.2f + dx, 0.0f + dy); // 위쪽 왼쪽
    glVertex2f(0.2f + dx, 0.0f + dy); // 위쪽 오른쪽
    glVertex2f(0.2f + dx, -0.1f + dy); // 아래 오른쪽
    glVertex2f(0.05f + dx, -0.1f + dy); // 아래 오른쪽 내부
    glVertex2f(0.2f + dx, -0.3f + dy); // 아래 오른쪽 끝
    glVertex2f(0.1f + dx, -0.3f + dy); // 아래 오른쪽 끝 내부
    glVertex2f(0.0f + dx, -0.15f + dy); // 중앙
    glVertex2f(-0.1f + dx, -0.3f + dy); // 아래 왼쪽 끝
    glVertex2f(-0.2f + dx, -0.3f + dy); // 아래 왼쪽 끝
    glVertex2f(-0.05f + dx, -0.1f + dy); // 시작점으로 돌아오기
    glEnd();
}


draw_ㅏ
• "ㅏ" 글자를 그리는 함수로, "ㅗ" 모양을 90도 회전시켜 그린다.
• glPushMatrix와 glPopMatrix를 사용하여 변환 행렬을 저장하고 복원한다.

void draw_ㅏ(double dx, double dy) {
    glPushMatrix(); // 현재 변환 행렬을 저장
    glTranslatef(dx, dy, 0.0f); // 원하는 위치로 이동
    glRotatef(-90.0f, 0.0f, 0.0f, 1.0f); // 90도 회전
    draw_ㅗ(0.0, 0.0); // 회전된 위치에서 "ㅗ" 그리기
    glPopMatrix(); // 변환 행렬 복원
}


draw_ㅎ
• "ㅎ" 글자를 그리는 함수이다. "ㅗ"를 그린 후 그 아래에 "ㅇ"을 추가하여 만든다.
• "ㅇ"은 "ㅎ"의 아래쪽에 적절히 배치된다.


void draw_ㅎ(double rad, double dx, double dy) {
    draw_ㅗ(dx, dy); // "ㅗ" 그리기
    draw_ㅇ(rad, dx + 0.0025, dy - 0.25); // "ㅇ" 그리기
}


draw_ㄱ
• "ㄱ" 글자를 그리는 함수이다. 세로선과 가로선을 사용하여 "ㄱ" 모양을 만든다.
• 두 선의 두께를 조정하여 형태를 더 강조한다.

void draw_ㄱ(double dx, double dy) {
    // 세로선
    glBegin(GL_POLYGON);
    glVertex2f(dx + 0.05f, dy + 0.2f); // 세로선 위쪽
    glVertex2f(dx + 0.05f, dy - 0.1f); // 세로선 아래쪽
    glVertex2f(dx - 0.05f, dy - 0.1f); // 세로선 아래쪽
    glVertex2f(dx - 0.05f, dy + 0.2f); // 세로선 위쪽
    glEnd();

    // 가로선
    glBegin(GL_POLYGON);
    glVertex2f(dx - 0.05f, dy + 0.2f); // 오른쪽 위
    glVertex2f(dx - 0.15f, dy + 0.2f); // 왼쪽 위
    glVertex2f(dx - 0.15f, dy + 0.1f); // 왼쪽 아래
    glVertex2f(dx - 0.05f, dy + 0.1f); // 오른쪽 아래
    glEnd();
}

draw_ㅕ
• "ㅕ" 글자를 그리는 함수이다. 세로선과 두 개의 가로선을 조합하여 "ㅕ" 모양을 형성한다.
• 세로선은 중앙에 위치하며, 두 개의 가로선은 적절히 배치되어 있습니다.

void draw_ㅕ(double dx, double dy) {
    // 세로선
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

display_name
• 이 함수는 화면에 "장혁"이라는 글자를 그리는 주 함수이다. 각각의 글자 함수들을 호출하여 전체 글자를 조합한다.
• glClear를 통해 화면을 지우고, 각 글자의 위치를 설정하여 그린다.

void display_name(){
    glClear(GL_COLOR_BUFFER_BIT); // 화면 지우기
    glColor3f(0.0f, 0.0f, 0.0f); // 글자 색상 (검정색)

    double rad = 0.13; // 원의 반지름 설정
    draw_ㅇ(rad, -0.4, 0.0); // "ㅇ" 그리기
    draw_ㅈ(-0.25, 0.0); // "ㅈ" 그리기
    draw_ㅏ(0.0, 0.0); // "ㅏ" 그리기
    draw_ㅎ(0.0, 0.0); // "ㅎ" 그리기
    draw_ㄱ(0.15, 0.0); // "ㄱ" 그리기
    draw_ㅕ(0.3, 0.0); // "ㅕ" 그리기

    glFlush(); // 화면에 그리기
}
