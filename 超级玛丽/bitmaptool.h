#pragma once
#include <easyx.h>
#include <graphics.h>
//ͼ�������
//�����������еľ�̬ͼ��
//��������һ����ϵ���Ժ�supermary����ĺ����������ã����һ������ǲ���ģ�ֻ����ԭ���ı�����װ��������
//�Ժ�ĳ���Ҳ������ˣ�һЩ�ౣ�������һ��cpp�����߼�����������������
class bitmaptool
{
public:
	bitmaptool(int x,int y);
	~bitmaptool();
public:
	//��ô����ͼ�񣬲����ں������������ų�ȫ�ֱ�������Ҫ��ʲô������
	int p_x; //ͼ���x����
	int p_y; //ͼ���y����
public:
	//����ͼ��
	void load(IMAGE &ima,char name[30]);
	//���ͼ��
	void get(IMAGE &ima,int w,int h);  //��ô���ֱ����Ͳ��� Ӧ����һ��ʲôģʽȥ���֣����Ժ���ʲô��
	//��ӡͼ��
	void put(IMAGE &ima);
};

//
