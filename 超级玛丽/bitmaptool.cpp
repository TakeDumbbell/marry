#include "stdafx.h"
#include "bitmaptool.h"


bitmaptool::bitmaptool(int x,int y)
{
	p_x = x;
	p_y = y;
}

bitmaptool::~bitmaptool()
{

}

void bitmaptool::load(IMAGE &ima, char name[30])
{
	loadimage(&ima,name);
}
void bitmaptool::get(IMAGE &ima, int w, int h)
{
	getimage(&ima, p_x, p_y, w, h);
}

void bitmaptool::put(IMAGE &ima)
{
	putimage(p_x, p_y, &ima);
}