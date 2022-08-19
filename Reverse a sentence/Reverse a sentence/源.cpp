//思路：
//1.整句倒过来
//2.use ’     ‘和结尾处的\0 to distinguish the word
//3.再把单词倒过来
#include <stdio.h>
#include <string.h>

//可以把倒置写个函数
//左右交换，然后++ --到左>右为止
void reverse(char* l, char* r)
{
	while (l < r)
	{
		char t = 0;
		t = *l;
		*l = *r;
		*r = t;

		l++;
		r--;
	}
}
int main() {
	char arr[100];
	gets_s(arr);
	int len = strlen(arr);
								//忘了，把地址赋值给指针（定义的时候是*l）
	reverse(arr, arr + len - 1);// 0 1 2 \0 strlen得3，arr+3指向\0因此-1
	
	//接下来找单词
	char* start = arr;
	//*start不是'\0'的时候就执行
	while(*start)
	{
		char* end = start;
		while (*end != ' ' && *end != '\0') 
			{
				end++;
			}
		//最后end落在了空格处
		reverse(start, end - 1);
		//只有end落在空格才能给start，要不然越界！
		if(*end ==' ')
		{
			start = end + 1;
		}
		else
		{
			start = end;
		}
	}
	printf("%s\n", arr);
	return 0;
}