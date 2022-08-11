#include "game.h"

void menu()
{
	printf("****************************\n");
	printf("********1. play    *********\n");
	printf("********0. exit    *********\n");
	printf("****************************\n\n");
}
//棋盘初始化，NOTE：此处初始化11*11，否则计算周围雷数有问题
void Initial(char Board[ROWS][COLS], int rows, int cols, char first)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Board[i][j] = first;
		}
	}
}
//print the board, here we just need print 9*9
//we should print the number of cols and rows
void Display(char Board[ROWS][COLS], int row, int col)
{
	printf("------minesweeper------\n");
	for (int i = 0; i < col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");//there should be a newline after print 
	for (int i = 1; i < row; i++)
	{
		printf("%d ", i);		//行数的标记不能从0开始，otherwise横着竖着都有0
		for (int j = 1; j < col; j++)
		{
			printf("%c ", Board[i][j]);
		}
		printf("\n");
	}
	printf("------minesweeper------\n");
}

void setmine(char Board[ROWS][COLS], int row, int col)
{
	//to set 10 mines
	int count = EASY_COUNT;
	while(count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (Board[x][y] == '0')
		{
			Board[x][y] = '1';
		}
		count--;
	}
}

static int Calculate(char mineBoard[ROWS][COLS], int x, int y)
{
	return mineBoard[x - 1][y] +
		mineBoard[x - 1][y - 1] +
		mineBoard[x][y - 1] +
		mineBoard[x + 1][y - 1] +
		mineBoard[x + 1][y] +
		mineBoard[x + 1][y + 1] +
		mineBoard[x][y + 1] +
		mineBoard[x - 1][y + 1] - 8 * '0';
}

int Findmine(char mineBoard[ROWS][COLS], char showBoard[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("请输入坐标");
	scanf("%d%d", &x, &y);
	if (x <= row && x >= 1 && y <= col && y >= 1)
	{
		if (mineBoard[x][y] == '1')
		{
			printf("很遗憾被炸死\n");
			Display(mineBoard, row, col);
		}
		else
		{
			int count = Calculate(mineBoard, x, y);
			showBoard[x][y] = count + '0';//字符数组直接把count放入会换成ASCII码
			Display(showBoard, row, col);
		}
	}
	else
	{
		printf("坐标不合法，请重新输入\n");
	}
}