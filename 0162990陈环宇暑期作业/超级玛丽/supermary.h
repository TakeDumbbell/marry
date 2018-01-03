#pragma once
#include <easyx.h>
#include <graphics.h>
#include <vector>
using namespace std;
typedef struct  mary
{
	IMAGE mary1[5];
	IMAGE mary2[5];
}mary;
typedef struct marymove
{
	mary ringt;//������
	mary left; //������
	mary jump_right; //������Ծ
	mary jump_left;  //������Ծ
}marymove;
//��������Ϣ
typedef struct person
{
	int x;    //����������
	int y;    //����������
	int dir;  //��ǰ���� 1������ -1 ������
	int life;     //����
	int vx;     //�����ٶ�
	int vy;      //�����ٶ�
	int isjumping;    //�Ƿ�����Ծ
	bool height;       //�����Ƿ�ﵽ���߶�
	int ismove;      //�Ƿ����ƶ�
	int step;       //����
	int high;       //��Ը߶�
	int max_high;       //��Ծ�ܴﵽ�����߶�
}person;
//ˮ�ܵ���Ϣ
typedef struct my_shut
{
	int x;        //x����
	int y;        //y����
	int width;    //��
	int height;   //��
	IMAGE pri_shut; //ԭ����ˮ��
}my_shut;
//ש�����Ϣ
typedef struct  my_brick
{
	int x;    //x����
	int y;    //y����
	int width;   //һ��ש�Ŀ��
	int height;   //һ��ש�ĸ߶�
	int num;      //ש������Ŀ
	int loc;      //���ֵ�ʱ��
	IMAGE pri_brick; //ԭ����ש��
}my_brick;
//���������Ļ���ͼƬ
extern marymove the_mary;
//����һ�������Ķ��󡪡���������
extern person pri_mary;
//�����ȫ�ֱ���������������ԭʼͼ��
extern IMAGE ima_privious;
//������������������һ�ε�x��y����
extern int pre_x, pre_y;
//��ͼλ��
extern int map;
//��ͼǰλ��
extern int pri_map;
//ש�������
extern int run;
//�����ש
extern IMAGE brick;
//����ˮ�ܵ�ͼƬ
extern IMAGE shut;
//����ˮ�ܵĲ���
extern vector<my_shut> q;
//����ש��Ĳ���
extern vector<my_brick> p;
//��Ϸ�ĳ�ʼ��
void initiaze();
//��ʼ��ש��
void init_brick();
//�������ƶ�
void move(int step);
//��λ
void reset();
//�������ƶ���׼��
void control();
//��ͼ��Ϣƥ��
void Draw_mary();
//��Ϸ�Ƿ����
bool if_gameover();
//��ͼ�������ơ���ˮ�ܣ�������ש��
void Draw_background();
//��С�ֵĻ���
void Enemy();
//�ƶ��жϡ��������Ƿ��ж���
bool judge_up();
//�ƶ��жϡ��������Ƿ��ж���
bool judge_down();
//�ƶ��жϡ�������Ƿ��ж���
bool judge_left();
//�ƶ��жϡ����ұ��Ƿ��ж���
bool judge_right();
//ˮ�ܲ������ƶ�����
void shut_move();
//ש��Ĳ������ƶ�����
void brick_move();
