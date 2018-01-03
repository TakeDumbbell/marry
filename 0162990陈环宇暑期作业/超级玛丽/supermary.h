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
	mary ringt;//向右走
	mary left; //向左走
	mary jump_right; //向右跳跃
	mary jump_left;  //向左跳跃
}marymove;
//玛丽的信息
typedef struct person
{
	int x;    //玛丽横坐标
	int y;    //玛丽纵坐标
	int dir;  //当前方向 1代表右 -1 代表左
	int life;     //生命
	int vx;     //横向速度
	int vy;      //纵向速度
	int isjumping;    //是否在跳跃
	bool height;       //跳的是否达到最大高度
	int ismove;      //是否能移动
	int step;       //步伐
	int high;       //相对高度
	int max_high;       //跳跃能达到的最大高度
}person;
//水管的信息
typedef struct my_shut
{
	int x;        //x坐标
	int y;        //y坐标
	int width;    //宽
	int height;   //高
	IMAGE pri_shut; //原来的水管
}my_shut;
//砖块的信息
typedef struct  my_brick
{
	int x;    //x坐标
	int y;    //y坐标
	int width;   //一块砖的宽度
	int height;   //一块砖的高度
	int num;      //砖条的数目
	int loc;      //出现的时机
	IMAGE pri_brick; //原来的砖块
}my_brick;
//保存玛丽的基本图片
extern marymove the_mary;
//生成一个玛丽的对象——初级玛丽
extern person pri_mary;
//用这个全局变量来消除玛丽的原始图像
extern IMAGE ima_privious;
//用这两个变量保存上一次的x，y坐标
extern int pre_x, pre_y;
//地图位置
extern int map;
//地图前位置
extern int pri_map;
//砖块控制器
extern int run;
//保存地砖
extern IMAGE brick;
//保存水管的图片
extern IMAGE shut;
//保存水管的参数
extern vector<my_shut> q;
//保存砖块的参数
extern vector<my_brick> p;
//游戏的初始化
void initiaze();
//初始化砖块
void init_brick();
//玛丽的移动
void move(int step);
//复位
void reset();
//玛丽的移动标准版
void control();
//画图信息匹配
void Draw_mary();
//游戏是否结束
bool if_gameover();
//地图背景控制——水管，河流，砖块
void Draw_background();
//与小怪的互动
void Enemy();
//移动判断——上面是否有东西
bool judge_up();
//移动判断——下面是否有东西
bool judge_down();
//移动判断——左边是否有东西
bool judge_left();
//移动判断——右边是否有东西
bool judge_right();
//水管产生与移动控制
void shut_move();
//砖块的产生和移动控制
void brick_move();
