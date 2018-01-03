// 调试.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
#include <stdio.h>
//根据先序序列建立二叉树
using namespace std;
//二叉链表
typedef struct node
{
	char data; //数据
	struct node *lchild; //左孩子指针
	struct node *rchild; //右孩子指针
}BiTNode, *BiTree;
//根据先序遍历建立树

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
//先序输出
void show(BiTree T)
{
	if (T)
	{
		cout << T->data;
		show(T->lchild);
		show(T->rchild);
	}
}
//显示树高
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
//计算叶子结点个数
int nodecount(BiTree T)
{
	if (T == NULL) return 0;
	if (T->lchild == NULL&&T->rchild == NULL)
		return 1;
	else
		return nodecount(T->lchild) + nodecount(T->rchild);
}
//复制二叉树
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
//二叉排序树的插入
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
//建立二叉排序树
void CreatSortTree(BiTree &T)
{
	int num[10] = { 1,8,6,5,0,2,9,99,52,10 };
	T = NULL;
	for (int i = 0; i<10; i++)
	{
		InsertBst(T, num[i]);
	}
}

//中序遍历输出
//输出
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
