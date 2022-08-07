#include "game.h"

void game()
{
	printf("\n��ʼ��Ϸ\n");
	char board[ROW][COL];
	InitBoard(board, ROW, COL);
	PrintBoard(board, ROW, COL);
	char ret = 0;//������Ϸ״̬
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
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	PrintBoard(board, ROW, COL);
}

int main() 
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("\n�˳���Ϸ\n");
				break;
			default:
				printf("\nѡ��������\n");
				break;
		}
	} while (input);
	
	return 0;
}