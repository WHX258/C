#include "game.h"
void menu()
{
	printf("******************************\n");
	printf("******    1. play        *****\n");
	printf("******    0. exit        *****\n");
	printf("******************************\n\n");
}

void InitBoard(char board[ROW][COL], int row, int col)
{
	for(int i=0;i<row;i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void PrintBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if(j < col-1)
			{
				printf("|");
			}
		}
		printf("\n");//这两处忘了换行了
		for (int j = 0; j < col; j++)
		{
			printf("---");
			if(j<col-1)
			{
				printf("|");
			}
		}
		printf("\n");
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)//走一步
{
	int x = 0;
	int y = 0;
	printf("玩家走\n");
	while (1)//这个循环是怕输入错了
	{
		printf("请输入坐标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ') //又把判断变赋值啦！
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该点被占，重输\n");//输入*和#的情况都被涵盖了
			}
		}
		else
		{
			printf("坐标非法，重输\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("\n电脑走\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		//不用判断了，范围在取余时已定
		if (board[x - 1][y - 1] == ' ') 
		{
			board[x - 1][y - 1] = '#';
			break;				
		}
	}
}

char IsWin(char board[ROW][COL], int row, int col) 
{
	//判断三行
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return  board[i][1];
		}
	}
	//判断三列
	for (int i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//判断对角线、反对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//判断平局
	//如果棋盘满了返回1， 不满返回0
	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}
	//继续
	return 'C';
}

int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//棋盘没满
			}
		}
	}
	return 1;//棋盘满了
}