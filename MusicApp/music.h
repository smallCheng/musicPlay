#ifndef _MUSIC_H_
#define _MUSIC_H_

#include<time.h>
#include<stdlib.h>
#include<iostream>
#include <string>
#include <vector>
#include <fstream>
#include<io.h>
#include<stdio.h>
#include<windows.h>
#include "mmsystem.h"
#include<stdlib.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
#pragma warning(disable:4996)

//界面调色
void m_setColor();

//程序界面
void musicFace();
//用户交互
void musicFunction();
//音乐信息导入向量容器
void musicList();


//人工播放-----1
void peopleMusic();


//人工播放选项
void playMusic();


//顺序播放-----2
void orderMusic();

//随机播放----3
void randomMusic();

//循环播放-----4
void circulationMusic();

//选择播放-----5
void seleteMusic();

//显示播放列表-----6
void listMusic();
void listMusic1();

#endif