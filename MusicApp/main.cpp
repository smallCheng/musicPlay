#include"music.h"
int main()
{
	//界面调色
	m_setColor();
	//音乐信息导入向量容器(初始化)
	musicList();
	//用户交互
	musicFunction();
	return 0;
}