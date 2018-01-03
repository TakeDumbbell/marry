#pragma once
#include <easyx.h>
#include <graphics.h>
//图像处理基类
//用来处理所有的静态图像
//是这样的一个关系，以后supermary里面的函数还是有用，并且基本上是不变的，只是我原来的变量封装更方便了
//以后的程序也大体如此，一些类保存变量，一个cpp处理逻辑，主函数处理流程
class bitmaptool
{
public:
	bitmaptool(int x,int y);
	~bitmaptool();
public:
	//怎么处理图像，不都在函数参数不都放成全局变量了吗，要有什么操作呢
	int p_x; //图像的x坐标
	int p_y; //图像的y坐标
public:
	//加载图像
	void load(IMAGE &ima,char name[30]);
	//获得图像
	void get(IMAGE &ima,int w,int h);  //怎么区分变量和参数 应该以一种什么模式去区分，他以后有什么用
	//打印图像
	void put(IMAGE &ima);
};

//
