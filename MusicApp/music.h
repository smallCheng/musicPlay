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

//�����ɫ
void m_setColor();

//�������
void musicFace();
//�û�����
void musicFunction();
//������Ϣ������������
void musicList();


//�˹�����-----1
void peopleMusic();


//�˹�����ѡ��
void playMusic();


//˳�򲥷�-----2
void orderMusic();

//�������----3
void randomMusic();

//ѭ������-----4
void circulationMusic();

//ѡ�񲥷�-----5
void seleteMusic();

//��ʾ�����б�-----6
void listMusic();
void listMusic1();

#endif