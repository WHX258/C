#include "game.h"

void game()
{
	char mineBoard[ROWS][COLS] = { 0 };
	char showBoard[ROWS][COLS] = { 0 };
	//��ʼ������
	Initial(mineBoard, ROWS, COLS, '0');
	Initial(showBoard, ROWS, COLS, '*');
	//��ӡ����
	Display(showBoard, ROW, COL);
	//������
	srand((unsigned int)time(NULL));
	setmine(mineBoard, ROW, COL);
	int win = 0;
	//�ж�ʲôʱ�����
	while (win<ROW * COL - EASY_COUNT)
	{
		Findmine(mineBoard, showBoard, ROW, COL);
		//Ӧ�����ж������ǲ�����
		// if���ǣ��ټ�����Χ�ж�����
		//Ӧ�ðѽ���ŵ�showboard��
		// if�ǣ�ֱ�������ը��
	}
	if (win == ROW * COL - EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
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
			printf("�˳���Ϸ\n");
				break;
		default:
			printf("�����������������\n");
				break;
		}
	} while (input);
	return 0;
}