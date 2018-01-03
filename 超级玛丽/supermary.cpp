#include "stdafx.h"
#include "supermary.h"
#include <Windows.h>
//保存玛丽的图像信息
marymove the_mary;
//生成一个玛丽的对象——初级玛丽
person pri_mary = {200,295,1,1,15,10,0,0,0,1,0,60};
//用这个全局变量来消除玛丽的原始图像
IMAGE ima_privious;
//保存地砖
IMAGE brick;
//保存水管
IMAGE shut;
//保存水管的参数
vector<my_shut> q;
//保存砖块的参数
vector<my_brick> p;
//用这两个变量保存上一次的x，y坐标
int pre_x=200, pre_y=295;
//地图位置
int map;
//地图前位置
int pri_map;
//游戏的初始化
void initiaze()
{
	//怎么有多个玛丽的形态 //用一个标志变量控制玛丽的形态
	initgraph(600, 400, NULL); //初始化画布
	//对于玛丽的图像存储
	IMAGE mary1,mary2;
	loadimage(&mary1, "mary//玛丽1.BMP");
	loadimage(&mary2, "mary//玛丽2.BMP");
	//虚拟图一的存储
	putimage(0, 0, &mary1);
	//向右走
	getimage(&the_mary.ringt.mary1[0], 30 + 50 * 3, 20 + 55 * 1, 40, 45);
	getimage(&the_mary.ringt.mary1[1], 30 + 50 * 4-5, 20 + 55 * 1, 40, 45);
	getimage(&the_mary.ringt.mary1[2], 30 + 50 * 5 - 5, 20 + 55 * 1, 40, 45);
	//向左走
	getimage(&the_mary.left.mary1[0], 30 + 50 * 3, 20 + 55 * 0, 40, 45);
	getimage(&the_mary.left.mary1[1], 30 + 50 * 2+3, 20 + 55 * 0, 40, 45);
	getimage(&the_mary.left.mary1[2], 30 + 50 * 1, 20 + 55 * 0, 40, 45);
	//向右跳跃
	getimage(&the_mary.jump_right.mary1[0], 30 + 50 * 3, 20 + 55 * 1, 40, 45);
	getimage(&the_mary.jump_right.mary1[1], 30 + 50 * 6, 20 + 55 * 1, 40, 45);
	//向左跳跃
	getimage(&the_mary.jump_left.mary1[0], 30 + 50 * 3, 20 + 55 * 0, 40, 45);
	getimage(&the_mary.jump_left.mary1[1], 30 + 50 * 0, 20 + 55 * 0, 40, 45);
	//虚拟图二的存储
	putimage(0, 0, &mary2);
	//向右走
	getimage(&the_mary.ringt.mary2[0], 30 + 50 * 3, 20 + 55 * 1, 40, 45);
	getimage(&the_mary.ringt.mary2[1], 30 + 50 * 4 - 5, 20 + 55 * 1, 40, 45);
	getimage(&the_mary.ringt.mary2[2], 30 + 50 * 5 - 5, 20 + 55 * 1, 40, 45);
	//向左走
	getimage(&the_mary.left.mary2[0], 30 + 50 * 3, 20 + 55 * 0, 40, 45);
	getimage(&the_mary.left.mary2[1], 30 + 50 * 2 + 3, 20 + 55 * 0, 40, 45);
	getimage(&the_mary.left.mary2[2], 30 + 50 * 1 , 20 + 55 * 0, 40, 45);
	//向右跳跃
	getimage(&the_mary.jump_right.mary2[0], 30 + 50 * 3, 20 + 55 * 1, 40, 45);
	getimage(&the_mary.jump_right.mary2[1], 30 + 50 * 6, 20 + 55 * 1, 40, 45);
	//向左跳跃
	getimage(&the_mary.jump_left.mary2[0], 30 + 50 * 3, 20 + 55 * 0, 40, 45);
	getimage(&the_mary.jump_left.mary2[1], 30 + 50 * 0, 20 + 55 * 0, 40, 45);
	//加载地图
	IMAGE map;
	loadimage(&map, "res//mapsky.bmp", 600, 1800);
	putimage(0, 0, 600, 400, &map, 0, 0);
	getimage(&ima_privious, pri_mary.x, pri_mary.y, 40, 45);
	//加载地砖
	loadimage(&brick, "res//砖.bmp");
	//加载水管
	loadimage(&shut, "res//水管.bmp");
	//初始化砖块
	init_brick();
	for (int i = 0; i <= 1; i++) //i是层数
	{
		for (int j = 0; j <= 20; j++) //j是多少
		{
			putimage(30 * j, 340 + i * 30, 30, 30, &brick, 30, 0);
		}
	}
	//加载初期的玛丽
	putimage(pri_mary.x, pri_mary.y, &the_mary.ringt.mary1[0], SRCAND);
	putimage(pri_mary.x, pri_mary.y, &the_mary.ringt.mary2[0], SRCPAINT);
}
//初始化砖块
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
//玛丽的移动
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
//复位
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
//玛丽的移动标准版——控制引擎
void control()
{
	//跳跃控制
	if (pri_mary.isjumping)
	{
 		if (pri_mary.high < pri_mary.max_high && pri_mary.height == 0)   //且未达到最大高度
		{
			if (!judge_up()) //上跳的时候上面没东西
			{
				pri_mary.high += pri_mary.vy;
				pri_mary.y -= pri_mary.vy;
			}
			else    //头上有东西
			{
				pri_mary.height = 1;
			}
		}
		else    //到了最高高度
		{
			pri_mary.height = 1;
			if (!judge_down())   //降落的时候下面没东西
			{
				pri_mary.y += pri_mary.vy;
				pri_mary.high -= pri_mary.vy;
			}
			else   //站在上面
			{
				pri_mary.isjumping = 0;    
				pri_mary.height = 0;
				pri_mary.high = 0;
			}
		}
		
	}
	else
	{
		if (!judge_down())   //脱离了水管什么的要掉下来
		{
			if (pri_mary.y < 295)
			{
				pri_mary.y += pri_mary.vy;
				if (pri_mary.y >= 295)
					pri_mary.y = 295;
			}
		}
	}
	//按键控制
	if (GetAsyncKeyState(VK_RIGHT))  //接收到右按键
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
	else if(GetAsyncKeyState(VK_LEFT))  //接收到左按键
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
	//跳跃
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
//画图信息匹配
void Draw_mary()
{
	//正在跳跃中
	if (pri_mary.isjumping)    
	{
		if (pri_mary.ismove)  //跳跃途中接收按键消息
		{
			pri_mary.ismove = 0;
		}

		if (pri_mary.high<pri_mary.max_high && pri_mary.height == 0)   //向上跳跃
		{
			putimage(pre_x, pre_y, &ima_privious);
			getimage(&ima_privious, pri_mary.x, pri_mary.y, 40, 45);
			pre_x = pri_mary.x;
			pre_y = pri_mary.y;
		}
		else  //回落
		{
			putimage(pre_x, pre_y, &ima_privious);
			getimage(&ima_privious, pri_mary.x, pri_mary.y, 40, 45);
			pre_x = pri_mary.x;
			pre_y = pri_mary.y;
		}

		if (pri_mary.dir == 1 || pri_mary.dir == 0)  //方向为右
		{
			putimage(pri_mary.x, pri_mary.y, &the_mary.jump_right.mary1[1], SRCAND);
			putimage(pri_mary.x, pri_mary.y, &the_mary.jump_right.mary2[1], SRCPAINT);
		}
		else if (pri_mary.dir == -1)  //方向为左
		{
			putimage(pri_mary.x, pri_mary.y, &the_mary.jump_left.mary1[1], SRCAND);
			putimage(pri_mary.x, pri_mary.y, &the_mary.jump_left.mary2[1], SRCPAINT);
		}

		if (pri_mary.y >= 295)  //回到了地面
		{
			pri_mary.y = 295;
			pri_mary.vy = 10;
			pri_mary.isjumping = 0;
			pri_mary.height = 0;
			pri_mary.high = 0;
		}
	}
	//不在跳跃中
	else
	{
		if (pri_mary.ismove)   //接收到了按键消息
		{
			move(pri_mary.step);
			pri_mary.ismove = 0;
		}
		//如果没有接收到按键一定要归位
		else
		{
			reset();
		}
	}
}
//游戏是否结束
bool if_gameover()
{
	return true;
}
//地图背景控制——水管，河流，砖块
void Draw_background()
{
	if (map > pri_map)
	{
		pri_map = map;
		//当玛丽走到地图中央的时候应该地图动
		for (int i = 0; i <= 3; i++) //i是层数
		{
			for (int j = 0; j <= 20; j++) //j是多少
			{
				putimage(-15 + pri_mary.step * 15 + 30 * j, 340 + i * 30, 30, 30, &brick, 30, 0);
			}
		}
		//当map到这么多出现水管 
		if (map == 10||map==25 ||map==70 || map==100 || map==50)
		{
			//用一个容器存放水管，每次都画出所有的水管
			my_shut post;
			post.x = 600;
			post.y = 280;
			post.height = 60;
			post.width = 60;
			q.push_back(post);
		}

		shut_move();
		//当map到这么多出现砖块
		brick_move();
	}
}
//与小怪的互动
void Enemy()
{

}
//移动判断——上面是否有东西
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
//移动判断——下面是否有东西
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
//移动判断——左边是否有东西
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
//移动判断——右边是否有东西
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
//水管产生与移动控制
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
//砖块的产生和移动控制
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