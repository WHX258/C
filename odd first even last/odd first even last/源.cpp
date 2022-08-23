#include <stdio.h>
//ֻ��Ҫ����һ�飺������ҵ�һ��ż�������ұ��ҵ�һ������������arr[left]��arr[right]
//left++��right++�������ٽ�����ֱ��left>right

void move(int* arr,int lenth)
{
	int left = 0;
	int right = lenth - 1;

	while (left<right)
	{
		//Ҫ����while����Ϊ�������̶�������֪��˭������ż��or����
		while ((left < right) && (arr[left] % 2 == 1))//��Ҫ��ֹԽ����ʣ���һȫ�������أ�
		{
			left++;
		}
		while ((left < right) && (arr[right] % 2 == 0))//ͬ���ֹԽ�磬��һȫ��ż���أ�
		{
			right--;
		}

		//����Ҫ���жϣ���Ϊ���һ�ν����ѭ����ʱ��
		//��֪����һ�ν���ʱ �� �ǲ��� ���� ��,���жϾ���1 9 3 7 6 5...��
		if (left < right)
		{
			int t = arr[left];
			arr[left] = arr[right];
			arr[right] = t;
		}//OK,����һ�ֽ�������	
	}	
}

void print(int* arr,int lenth)
{
	for (int i = 0; i < lenth; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int lenth = sizeof(arr) / sizeof(arr[0]);
	move(arr,lenth);
	print(arr,lenth);

	return 0;
}