// 超级玛丽.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"supermary.h"

using namespace std;

int main()
{
	initiaze();  //初始化
	while (if_gameover())
	{
		//玛丽的所有运动控制
		control(); //控制器——玛丽的运动控制
		Draw_mary();    //画出玛丽
		Draw_background();    //地图背景控制——水管，河流，砖块
		//小怪的控制
		//Enemy();       //小怪向前运动，打死小怪或者被小怪打死
		Sleep(60);
	}
	system("pause");
    return 0;
}

