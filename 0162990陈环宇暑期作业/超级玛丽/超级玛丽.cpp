// ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"supermary.h"

using namespace std;

int main()
{
	initiaze();  //��ʼ��
	while (if_gameover())
	{
		//�����������˶�����
		control(); //�����������������˶�����
		Draw_mary();    //��������
		Draw_background();    //��ͼ�������ơ���ˮ�ܣ�������ש��
		//С�ֵĿ���
		//Enemy();       //С����ǰ�˶�������С�ֻ��߱�С�ִ���
		Sleep(60);
	}
	system("pause");
    return 0;
}

