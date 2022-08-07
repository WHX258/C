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
		printf("\n");//���������˻�����
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

void PlayerMove(char board[ROW][COL], int row, int col)//��һ��
{
	int x = 0;
	int y = 0;
	printf("�����\n");
	while (1)//���ѭ�������������
	{
		printf("���������꣺");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ') //�ְ��жϱ丳ֵ����
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�õ㱻ռ������\n");//����*��#���������������
			}
		}
		else
		{
			printf("����Ƿ�������\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("\n������\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		//�����ж��ˣ���Χ��ȡ��ʱ�Ѷ�
		if (board[x - 1][y - 1] == ' ') 
		{
			board[x - 1][y - 1] = '#';
			break;				
		}
	}
}

char IsWin(char board[ROW][COL], int row, int col) 
{
	//�ж�����
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return  board[i][1];
		}
	}
	//�ж�����
	for (int i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//�ж϶Խ��ߡ����Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//�ж�ƽ��
	//����������˷���1�� ��������0
	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}
	//����
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
				return 0;//����û��
			}
		}
	}
	return 1;//��������
}