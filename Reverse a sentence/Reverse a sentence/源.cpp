//˼·��
//1.���䵹����
//2.use ��     ���ͽ�β����\0 to distinguish the word
//3.�ٰѵ��ʵ�����
#include <stdio.h>
#include <string.h>

//���԰ѵ���д������
//���ҽ�����Ȼ��++ --����>��Ϊֹ
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
								//���ˣ��ѵ�ַ��ֵ��ָ�루�����ʱ����*l��
	reverse(arr, arr + len - 1);// 0 1 2 \0 strlen��3��arr+3ָ��\0���-1
	
	//�������ҵ���
	char* start = arr;
	//*start����'\0'��ʱ���ִ��
	while(*start)
	{
		char* end = start;
		while (*end != ' ' && *end != '\0') 
			{
				end++;
			}
		//���end�����˿ո�
		reverse(start, end - 1);
		//ֻ��end���ڿո���ܸ�start��Ҫ��ȻԽ�磡
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