#include "game.h"

void game()
{
	printf("\n开始游戏\n");
	char board[ROW][COL];
	InitBoard(board, ROW, COL);
	PrintBoard(board, ROW, COL);
	char ret = 0;//接受游戏状态
	srand((unsigned int)time(NULL));
	while (1)
	{
		PlayerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;

		ComputerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("玩家赢了\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局\n");
	}
	PrintBoard(board, ROW, COL);
}

int main() 
{
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("\n退出游戏\n");
				break;
			default:
				printf("\n选错啦重来\n");
				break;
		}
	} while (input);
	
	return 0;
}