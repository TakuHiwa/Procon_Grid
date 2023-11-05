#include <iostream>
#include <GL/glut.h>

int WINDOW_WIDTH = 500;   // ウィンドウの横幅
int WINDOW_HEIGHT = 500;  // ウィンドウの高さ

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);	// <今から赤色を使用する>
	glBegin(GL_POINTS);
	glVertex2f(10.0, 10.0);		// <空間の座標(x,y)に点を描画する>
	glVertex2f(150.0, 80.0);
	glVertex2f(100.0, 20.0);
	glVertex2f(200.0, 100.0);
	glEnd();
	glFlush();	 // <表示内容を更新>
}

void display4b4(void){
	int grid_width = 200;
	int grid_height = 200;
	int grid_div = grid_width / 4;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);	// <今から赤色を使用する>
	glBegin(GL_LINES);

	int bx = 150;
	int by = 150;
	glVertex2d(bx + 0, by + 0);	
	glVertex2d(bx + 0, by + grid_height);	

	glVertex2d(bx + 0, by + 0);
	glVertex2d(bx + grid_width, by + 0);	

	glVertex2d(bx + 0, by + grid_height);
	glVertex2d(bx + grid_width, by + grid_height);	

	glVertex2d(bx + grid_width, by + grid_height);
	glVertex2d(bx + grid_width, by + 0);	
	
	for (int i = 1; i <= 4; i++)
	{
		glVertex2d(bx + i * grid_div, by + 0);						 // 下から
		glVertex2d(bx + i * grid_div, by + grid_height); // 上へ
	}
	

	glEnd();
	glFlush();	 // <表示内容を更新>
}

void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);	// <背景はホワイトにする>
	glColor3f(1.0, 0.0, 0.0);
	// glPointSize(5.0);					// <点を大きく>
	glLineWidth(5.0);						// <線幅を太く>
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (double)WINDOW_WIDTH, 0.0, (double)WINDOW_HEIGHT); //  <空間を描画する範囲を指定する>
}

int main(int argc, char** argv)
{
	// 1: windowの設定
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(1980-WINDOW_WIDTH, 0);
	glutCreateWindow("Points");

	// 2: 点の描画設定
	glutDisplayFunc(display4b4);

	// 3: windowの描画
	myinit();
	glutMainLoop();
}