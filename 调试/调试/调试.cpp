// ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include <iostream>
#include <stdio.h>
//�����������н���������
using namespace std;
//��������
typedef struct node
{
	char data; //����
	struct node *lchild; //����ָ��
	struct node *rchild; //�Һ���ָ��
}BiTNode, *BiTree;
//�����������������

void Creat(BiTree &T)
{
	char ch;
	cin >> ch;
	if (ch == '#')
		T = NULL;
	else
	{
		T = new BiTNode;
		T->data = ch;
		Creat(T->lchild);
		Creat(T->rchild);
	}
}
//�������
void show(BiTree T)
{
	if (T)
	{
		cout << T->data;
		show(T->lchild);
		show(T->rchild);
	}
}
//��ʾ����
int Depth(BiTree T)
{
	if (T == NULL) return 0;
	else
	{
		int m = Depth(T->lchild);
		int n = Depth(T->rchild);
		if (m>n) return (m + 1);
		else return (n + 1);
	}
}
//����Ҷ�ӽ�����
int nodecount(BiTree T)
{
	if (T == NULL) return 0;
	if (T->lchild == NULL&&T->rchild == NULL)
		return 1;
	else
		return nodecount(T->lchild) + nodecount(T->rchild);
}
//���ƶ�����
void BtCopy(BiTree T1, BiTree &T2)
{
	if (T1 == NULL)
	{
		T2 = NULL;
		return;
	}
	else
	{
		T2 = new BiTNode;
		T2->data = T1->data;
		BtCopy(T1->lchild, T2->rchild);
		BtCopy(T1->lchild, T2->rchild);
	}
}
//�����������Ĳ���
void InsertBst(BiTree &T, int e)
{
	if (!T)
	{
		T = new BiTNode;
		T->data = e;
		T->lchild = NULL;
		T->rchild = NULL;
	}
	else if (e < T->data)
	{
		InsertBst(T->lchild, e);
	}
	else if (e > T->data)
	{
		InsertBst(T->rchild, e);
	}
}
//��������������
void CreatSortTree(BiTree &T)
{
	int num[10] = { 1,8,6,5,0,2,9,99,52,10 };
	T = NULL;
	for (int i = 0; i<10; i++)
	{
		InsertBst(T, num[i]);
	}
}

//����������
//���
void Mshow(BiTree T)
{
	if (T)
	{
		cout << T->data;
		show(T->lchild);
		show(T->rchild);
	}
}
int main()
{
	BiTree T;
	CreatSortTree(T);
	Mshow(T);
	//cout << Depth(T) << endl;
	//cout << nodecount(T) << endl;
	return 0;
}
