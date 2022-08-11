#include "game.h"

void game()
{
	char mineBoard[ROWS][COLS] = { 0 };
	char showBoard[ROWS][COLS] = { 0 };
	//初始化棋盘
	Initial(mineBoard, ROWS, COLS, '0');
	Initial(showBoard, ROWS, COLS, '*');
	//打印棋盘
	Display(showBoard, ROW, COL);
	//布置雷
	srand((unsigned int)time(NULL));
	setmine(mineBoard, ROW, COL);
	int win = 0;
	//判断什么时候结束
	while (win<ROW * COL - EASY_COUNT)
	{
		Findmine(mineBoard, showBoard, ROW, COL);
		//应该先判断这里是不是雷
		// if不是，再计算周围有多少雷
		//应该把结果放到showboard上
		// if是，直接输出被炸死
	}
	if (win == ROW * COL - EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
		Display(mineBoard, ROW, COL);
	}
}

int main()
{
	int input = 0;

	do {
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
				break;
		case 0:
			printf("退出游戏\n");
				break;
		default:
			printf("输入错误，请重新输入\n");
				break;
		}
	} while (input);
	return 0;
}