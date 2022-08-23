#include <stdio.h>
//只需要遍历一遍：从左边找第一个偶数，从右边找第一个奇数，交换arr[left]和arr[right]
//left++，right++，再找再交换，直到left>right

void move(int* arr,int lenth)
{
	int left = 0;
	int right = lenth - 1;

	while (left<right)
	{
		//要两个while，因为两个进程独立，不知道谁先遇到偶数or奇数
		while ((left < right) && (arr[left] % 2 == 1))//这要防止越界访问，万一全是奇数呢？
		{
			left++;
		}
		while ((left < right) && (arr[right] % 2 == 0))//同理防止越界，万一全是偶数呢？
		{
			right--;
		}

		//这里要有判断，因为最后一次进入大循环的时候
		//不知道下一次交换时 左 是不是 大于 右,不判断就是1 9 3 7 6 5...了
		if (left < right)
		{
			int t = arr[left];
			arr[left] = arr[right];
			arr[right] = t;
		}//OK,至此一轮交换结束	
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