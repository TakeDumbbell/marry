#include "stdafx.h"
#include "supermary.h"
#include <Windows.h>
//����������ͼ����Ϣ
marymove the_mary;
//����һ�������Ķ��󡪡���������
person pri_mary = {200,295,1,1,15,10,0,0,0,1,0,60};
//�����ȫ�ֱ���������������ԭʼͼ��
IMAGE ima_privious;
//�����ש
IMAGE brick;
//����ˮ��
IMAGE shut;
//����ˮ�ܵĲ���
vector<my_shut> q;
//����ש��Ĳ���
vector<my_brick> p;
//������������������һ�ε�x��y����
int pre_x=200, pre_y=295;
//��ͼλ��
int map;
//��ͼǰλ��
int pri_map;
//��Ϸ�ĳ�ʼ��
void initiaze()
{
	//��ô�ж����������̬ //��һ����־����������������̬
	initgraph(600, 400, NULL); //��ʼ������
	//����������ͼ��洢
	IMAGE mary1,mary2;
	loadimage(&mary1, "mary//����1.BMP");
	loadimage(&mary2, "mary//����2.BMP");
	//����ͼһ�Ĵ洢
	putimage(0, 0, &mary1);
	//������
	getimage(&the_mary.ringt.mary1[0], 30 + 50 * 3, 20 + 55 * 1, 40, 45);
	getimage(&the_mary.ringt.mary1[1], 30 + 50 * 4-5, 20 + 55 * 1, 40, 45);
	getimage(&the_mary.ringt.mary1[2], 30 + 50 * 5 - 5, 20 + 55 * 1, 40, 45);
	//������
	getimage(&the_mary.left.mary1[0], 30 + 50 * 3, 20 + 55 * 0, 40, 45);
	getimage(&the_mary.left.mary1[1], 30 + 50 * 2+3, 20 + 55 * 0, 40, 45);
	getimage(&the_mary.left.mary1[2], 30 + 50 * 1, 20 + 55 * 0, 40, 45);
	//������Ծ
	getimage(&the_mary.jump_right.mary1[0], 30 + 50 * 3, 20 + 55 * 1, 40, 45);
	getimage(&the_mary.jump_right.mary1[1], 30 + 50 * 6, 20 + 55 * 1, 40, 45);
	//������Ծ
	getimage(&the_mary.jump_left.mary1[0], 30 + 50 * 3, 20 + 55 * 0, 40, 45);
	getimage(&the_mary.jump_left.mary1[1], 30 + 50 * 0, 20 + 55 * 0, 40, 45);
	//����ͼ���Ĵ洢
	putimage(0, 0, &mary2);
	//������
	getimage(&the_mary.ringt.mary2[0], 30 + 50 * 3, 20 + 55 * 1, 40, 45);
	getimage(&the_mary.ringt.mary2[1], 30 + 50 * 4 - 5, 20 + 55 * 1, 40, 45);
	getimage(&the_mary.ringt.mary2[2], 30 + 50 * 5 - 5, 20 + 55 * 1, 40, 45);
	//������
	getimage(&the_mary.left.mary2[0], 30 + 50 * 3, 20 + 55 * 0, 40, 45);
	getimage(&the_mary.left.mary2[1], 30 + 50 * 2 + 3, 20 + 55 * 0, 40, 45);
	getimage(&the_mary.left.mary2[2], 30 + 50 * 1 , 20 + 55 * 0, 40, 45);
	//������Ծ
	getimage(&the_mary.jump_right.mary2[0], 30 + 50 * 3, 20 + 55 * 1, 40, 45);
	getimage(&the_mary.jump_right.mary2[1], 30 + 50 * 6, 20 + 55 * 1, 40, 45);
	//������Ծ
	getimage(&the_mary.jump_left.mary2[0], 30 + 50 * 3, 20 + 55 * 0, 40, 45);
	getimage(&the_mary.jump_left.mary2[1], 30 + 50 * 0, 20 + 55 * 0, 40, 45);
	//���ص�ͼ
	IMAGE map;
	loadimage(&map, "res//mapsky.bmp", 600, 1800);
	putimage(0, 0, 600, 400, &map, 0, 0);
	getimage(&ima_privious, pri_mary.x, pri_mary.y, 40, 45);
	//���ص�ש
	loadimage(&brick, "res//ש.bmp");
	//����ˮ��
	loadimage(&shut, "res//ˮ��.bmp");
	//��ʼ��ש��
	init_brick();
	for (int i = 0; i <= 1; i++) //i�ǲ���
	{
		for (int j = 0; j <= 20; j++) //j�Ƕ���
		{
			putimage(30 * j, 340 + i * 30, 30, 30, &brick, 30, 0);
		}
	}
	//���س��ڵ�����
	putimage(pri_mary.x, pri_mary.y, &the_mary.ringt.mary1[0], SRCAND);
	putimage(pri_mary.x, pri_mary.y, &the_mary.ringt.mary2[0], SRCPAINT);
}
//��ʼ��ש��
void init_brick()
{
	my_brick post;
	post.num = 5;
	post.width = 30;
	post.height = 30;
	post.x = 590;
	post.y = 250;
	post.loc = 115;
	p.push_back(post);
}
//�������ƶ�
void move(int step)
{
	if (pri_mary.dir == 1)
	{
		putimage(pre_x, pre_y, &ima_privious);
		getimage(&ima_privious, pri_mary.x, pri_mary.y, 40, 45);
		pre_x = pri_mary.x;
		pre_y = pri_mary.y;
		putimage(pri_mary.x, pri_mary.y, &the_mary.ringt.mary1[step], SRCAND);
		putimage(pri_mary.x, pri_mary.y, &the_mary.ringt.mary2[step], SRCPAINT);
	}
	else if (pri_mary.dir == -1)
	{
		putimage(pre_x, pre_y, &ima_privious);
		getimage(&ima_privious, pri_mary.x, pri_mary.y, 40, 45);
		pre_x = pri_mary.x;
		pre_y = pri_mary.y;
		putimage(pri_mary.x, pri_mary.y, &the_mary.left.mary1[step], SRCAND);
		putimage(pri_mary.x, pri_mary.y, &the_mary.left.mary2[step], SRCPAINT);
	}
}
//��λ
void reset()
{
	putimage(pre_x, pre_y, &ima_privious);
	getimage(&ima_privious, pri_mary.x, pri_mary.y, 40, 45);
	pre_x = pri_mary.x;
	pre_y = pri_mary.y;
	if (pri_mary.dir == 1)
	{
		putimage(pri_mary.x, pri_mary.y, &the_mary.ringt.mary1[0], SRCAND);
		putimage(pri_mary.x, pri_mary.y, &the_mary.ringt.mary2[0], SRCPAINT);
	}
	else if (pri_mary.dir == -1)
	{
		putimage(pri_mary.x, pri_mary.y, &the_mary.left.mary1[0], SRCAND);
		putimage(pri_mary.x, pri_mary.y, &the_mary.left.mary2[0], SRCPAINT);
	}
}
//�������ƶ���׼�桪����������
void control()
{
	//��Ծ����
	if (pri_mary.isjumping)
	{
 		if (pri_mary.high < pri_mary.max_high && pri_mary.height == 0)   //��δ�ﵽ���߶�
		{
			if (!judge_up()) //������ʱ������û����
			{
				pri_mary.high += pri_mary.vy;
				pri_mary.y -= pri_mary.vy;
			}
			else    //ͷ���ж���
			{
				pri_mary.height = 1;
			}
		}
		else    //������߸߶�
		{
			pri_mary.height = 1;
			if (!judge_down())   //�����ʱ������û����
			{
				pri_mary.y += pri_mary.vy;
				pri_mary.high -= pri_mary.vy;
			}
			else   //վ������
			{
				pri_mary.isjumping = 0;    
				pri_mary.height = 0;
				pri_mary.high = 0;
			}
		}
		
	}
	else
	{
		if (!judge_down())   //������ˮ��ʲô��Ҫ������
		{
			if (pri_mary.y < 295)
			{
				pri_mary.y += pri_mary.vy;
				if (pri_mary.y >= 295)
					pri_mary.y = 295;
			}
		}
	}
	//��������
	if (GetAsyncKeyState(VK_RIGHT))  //���յ��Ұ���
	{
		if (pri_mary.x <= 200)
		{
			if(!judge_right())
				pri_mary.x += pri_mary.vx;
		}
		else
		{
			if (!judge_right())
				map++;
		}
		pri_mary.dir = 1;
		pri_mary.ismove = 1;
		pri_mary.step = 1 + pri_mary.step % 2;
	}
	else if(GetAsyncKeyState(VK_LEFT))  //���յ��󰴼�
	{
		if (pri_mary.x > 0)
		{
			if (!judge_left())
			{
				pri_mary.x -= pri_mary.vx;
			}
		}
		pri_mary.dir = -1;
		pri_mary.ismove = 1;
		pri_mary.step = 1 + pri_mary.step % 2;
	}
	//��Ծ
	 if (GetAsyncKeyState(VK_SPACE)) 
	{
		if (!pri_mary.isjumping)
		{
			pri_mary.vy = 10;
			pri_mary.isjumping = 1;
			pri_mary.y -= pri_mary.vy;
		}
	}

}
//��ͼ��Ϣƥ��
void Draw_mary()
{
	//������Ծ��
	if (pri_mary.isjumping)    
	{
		if (pri_mary.ismove)  //��Ծ;�н��հ�����Ϣ
		{
			pri_mary.ismove = 0;
		}

		if (pri_mary.high<pri_mary.max_high && pri_mary.height == 0)   //������Ծ
		{
			putimage(pre_x, pre_y, &ima_privious);
			getimage(&ima_privious, pri_mary.x, pri_mary.y, 40, 45);
			pre_x = pri_mary.x;
			pre_y = pri_mary.y;
		}
		else  //����
		{
			putimage(pre_x, pre_y, &ima_privious);
			getimage(&ima_privious, pri_mary.x, pri_mary.y, 40, 45);
			pre_x = pri_mary.x;
			pre_y = pri_mary.y;
		}

		if (pri_mary.dir == 1 || pri_mary.dir == 0)  //����Ϊ��
		{
			putimage(pri_mary.x, pri_mary.y, &the_mary.jump_right.mary1[1], SRCAND);
			putimage(pri_mary.x, pri_mary.y, &the_mary.jump_right.mary2[1], SRCPAINT);
		}
		else if (pri_mary.dir == -1)  //����Ϊ��
		{
			putimage(pri_mary.x, pri_mary.y, &the_mary.jump_left.mary1[1], SRCAND);
			putimage(pri_mary.x, pri_mary.y, &the_mary.jump_left.mary2[1], SRCPAINT);
		}

		if (pri_mary.y >= 295)  //�ص��˵���
		{
			pri_mary.y = 295;
			pri_mary.vy = 10;
			pri_mary.isjumping = 0;
			pri_mary.height = 0;
			pri_mary.high = 0;
		}
	}
	//������Ծ��
	else
	{
		if (pri_mary.ismove)   //���յ��˰�����Ϣ
		{
			move(pri_mary.step);
			pri_mary.ismove = 0;
		}
		//���û�н��յ�����һ��Ҫ��λ
		else
		{
			reset();
		}
	}
}
//��Ϸ�Ƿ����
bool if_gameover()
{
	return true;
}
//��ͼ�������ơ���ˮ�ܣ�������ש��
void Draw_background()
{
	if (map > pri_map)
	{
		pri_map = map;
		//�������ߵ���ͼ�����ʱ��Ӧ�õ�ͼ��
		for (int i = 0; i <= 3; i++) //i�ǲ���
		{
			for (int j = 0; j <= 20; j++) //j�Ƕ���
			{
				putimage(-15 + pri_mary.step * 15 + 30 * j, 340 + i * 30, 30, 30, &brick, 30, 0);
			}
		}
		//��map����ô�����ˮ�� 
		if (map == 10||map==25 ||map==70 || map==100 || map==50)
		{
			//��һ���������ˮ�ܣ�ÿ�ζ��������е�ˮ��
			my_shut post;
			post.x = 600;
			post.y = 280;
			post.height = 60;
			post.width = 60;
			q.push_back(post);
		}

		shut_move();
		//��map����ô�����ש��
		brick_move();
	}
}
//��С�ֵĻ���
void Enemy()
{

}
//�ƶ��жϡ��������Ƿ��ж���
bool judge_up()
{
	for (int i = 0; i < p.size(); i++)
	{
 		if (pri_mary.y == p[i].y+p[i].height-5 &&pri_mary.x + 42 >= p[i].x&&pri_mary.x < p[i].x + p[i].width*p[i].num)
		{
			return true;
		}
	}
	return false;
}
//�ƶ��жϡ��������Ƿ��ж���
bool judge_down()
{
	for (int i = 0; i < q.size(); i++)
	{
		if (pri_mary.x+30 >= q[i].x&&pri_mary.x <= q[i].x + q[i].width && pri_mary.y+45==q[i].y)
		{
			return true;
		}
	}
	for (int i = 0; i < p.size(); i++)
	{
		if (pri_mary.x + 30 >= p[i].x&&pri_mary.x <= p[i].x + p[i].width*p[i].num && pri_mary.y + 45 == p[i].y)
		{
			return true;
		}
	}
	return false;
}
//�ƶ��жϡ�������Ƿ��ж���
bool judge_left()
{
	for (int i = 0; i < q.size(); i++)
	{
 		if (pri_mary.x -5 == q[i].x +q[i].width  &&pri_mary.y + 45>q[i].y)
		{
			return true;
		}
	}
	for (int i = 0; i < p.size(); i++)
	{
		if (pri_mary.x == p[i].x+p[i].width*p[i].num &&pri_mary.y + 45>p[i].y&&pri_mary.y <p[i].y + p[i].height)
		{
			return true;
		}
	}
	return false;
}
//�ƶ��жϡ����ұ��Ƿ��ж���
bool judge_right()
{
	for (int i = 0; i < q.size(); i++)
	{
		if (pri_mary.x + 40 == q[i].x&&pri_mary.y+45>q[i].y)
		{
			return true;
		}
	}

	for (int i = 0; i < p.size(); i++)
	{
		if (pri_mary.x + 45 >= p[i].x&&pri_mary.y + 45>p[i].y&&pri_mary.y <p[i].y+p[i].height)
		{
			return true;
		}
	}
	return false;
}
//ˮ�ܲ������ƶ�����
void shut_move()
{
	for(int i=0;i<q.size();i++)
	{
		if (q[i].x <= -65)
		{
			q.erase(q.begin());
			i -= 1;
			continue;
		}
		q[i].x -= 15;
		putimage(q[i].x+15, q[i].y, &q[i].pri_shut);
		getimage(&q[i].pri_shut, q[i].x, q[i].y, q[i].width, q[i].height);
		putimage(q[i].x, q[i].y,q[i].width,q[i].height, &shut,0, 265);
	}
}
//ש��Ĳ������ƶ�����
void brick_move()
{
	for (int i = 0; i<p.size(); i++)
	{
		if (p[i].x <= -(p[i].width+p[i].width*p[i].num+5 ))
		{
			p.erase(p.begin());
			i -= 1;
			continue;
		}
		if (map < p[i].loc)
			continue;
		p[i].x -= 15;
		putimage(p[i].x + 15, p[i].y, &p[i].pri_brick);
		getimage(&p[i].pri_brick, p[i].x, p[i].y, p[i].width*p[i].num, p[i].height);
		for(int j=0;j<p[i].num;j++)
			putimage(p[i].x+j*p[i].width, p[i].y, p[i].width, p[i].height, &brick, 30,0 );
	}
}