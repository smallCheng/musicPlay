#include"music.h"

//音乐清单
vector<string> files;
//音乐路径清单
vector<string> musicfiles;

//读取res文件夹MP3格式文件，文件名及文件路径分别加载进向量容器
void m_setColor()
{
	system("color F3");


}
void musicList()
{
	//如果res文件夹不存在 ，则创建
	if(CreateDirectory("..\\res",NULL))
	{
		cout<<endl;
		cout<<"已创建res文件夹"<<endl;
		cout<<"请向res文件夹添加mp3格式音乐文件，再重启播放器!!!!!!!"<<endl;
		cout<<endl;
		Sleep(10000);
		exit(1);
	}
	
	//文件句柄
	long   hFile   =   0;
	//文件信息
	struct _finddata_t fileinfo;
	string path="..\\res";
	string pathName,exdName,exd="mp3";

	if (0 != strcmp(exd.c_str(), ""))
	{
		exdName = "\\*." + exd;
	}
	else
	{
		exdName = "\\*";
	}

	if((hFile = _findfirst(pathName.assign(path).append(exdName).c_str(),&fileinfo)) !=  -1)
	{
		do
		{
			//如果是文件夹中仍有文件夹,迭代之
			//如果不是,加入列表
			// 不推荐使用，硬要使用的话，需要修改else 里面的语句
			/*if((fileinfo.attrib &  _A_SUBDIR))
			{
			if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
			getFiles( pathName.assign(path).append("\\").append(fileinfo.name), exd, files );
			}
			else */
			{
				if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
					//files.push_back(pathName.assign(path).append("\\").append(fileinfo.name)); // 要得到绝对目录使用该语句
					//如果使用
				{
					files.push_back(fileinfo.name); // 只要得到文件名字使用该语句
					string pn="open "+path+"\\"+fileinfo.name+" alias music";
					//cout<<pn<<endl;
					musicfiles.push_back (pn);
					//cout<<fileinfo.name<<endl;
				}
			}
		}while(_findnext(hFile, &fileinfo)  == 0);
		_findclose(hFile);
	}
	//对res文件夹判空
	if(1==files.empty())
	{
		cout<<endl;
		cout<<"res文件夹为空"<<endl;
		cout<<"请向res文件夹添加mp3格式音乐文件，再重启播放器!!!!!!!"<<endl;
		cout<<endl;
		Sleep(10000);
		exit(1);

	}
}
//欢迎页面，主菜单
void musicFace()
{
	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"-----------------------------欢迎使用本播放器-------------------------"<<endl;
	cout<<"-------------------------------QQ:314086782---------------------------"<<endl;
	cout<<"-----------------注：除人工模式外，其他模式均为固定模式---------------"<<endl;
	cout<<"按键使用相应的功能"<<endl;
	cout<<"1---人工播放模式\t\t";
	cout<<"2---顺序播放模式\t\t";
	cout<<"3---随机播放模式"<<endl;;
	cout<<"4---循环播放模式\t\t";
	cout<<"5---选择播放模式\t\t";
	cout<<"L---显示播放列表"<<endl;
	cout<<"Q---退出播放器"<<endl<<endl;
	cout<<"请输入功能键: ";

}

//人工模式播放选项
void playMusic()
{
	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"播放上一首---1\t\t";
	cout<<"播放下一首---2\t\t";
	cout<<"点歌播放-----C"<<endl;
	cout<<"暂停播放-----P\t\t";
	cout<<"恢复播放-----R\t\t";
	cout<<"停止播放，返回主菜单---U"<<endl;
	cout<<"歌曲清单-----L\t\t";
	cout<<"音量增大---(+)\t\t";
	cout<<"音量减小---(-)"<<endl;
	cout<<"退出播放器---Q"<<endl<<endl;
}
//人工播放-----1
void peopleMusic()
{
	//当前音乐状态
	char m_post;
	unsigned int i=0;
	if(mciSendString(musicfiles[i].c_str(),NULL,0,NULL))//打开文件
		cout<<"打开音乐失败"<<endl;
	if(mciSendString("play music repeat",NULL,0,NULL))//播放音乐
		cout<<"播放音乐失败"<<endl;
	cout<<files[i].c_str()<<" 正在播放"<<endl;

	while(1)
	{
		//人工选项
		playMusic();
		//获取操作
		cout<<"请输入功能键: ";
		//scanf("%d",&m_post);
		fflush(stdin);
		m_post=getchar();
		switch(m_post)
		{
			//暂停播放音乐
		case 'p':
		case 'P':
			if(mciSendString("pause music", NULL, 0, NULL))// 暂停播放 
				cout<<"暂停失败<<endl";
			cout<<files[i].c_str()<<" 已暂停播放"<<endl;

			while(1)
			{
				//scanf("%d",&m_post);
				fflush(stdin);
				m_post=getchar();
				if('r'==m_post||'R'==m_post)
				{

					if(mciSendString("resume music", NULL, 0, NULL))//恢复播放音乐
						cout<<"恢复播放失败"<<endl;
					cout<<files[i].c_str()<<" 已恢复播放"<<endl;
					break;
				}

			}
			break;
			//case 1 包含 (恢复播放)
		case 'r':
		case 'R':

			break;
			//停止播放返回主菜单
		case 'u':
		case 'U':
			if(mciSendString("close music", NULL, 0, NULL))//关闭音乐
				cout<<"关闭音乐失败"<<endl;
			cout<<"关闭音乐成功"<<endl;
			return ;
			break;
			//上一首(循环)
		case '1':
			if(i>0)
			{
				mciSendString("close music", NULL, 0, NULL);
				i--;
				mciSendString(musicfiles[i].c_str(),NULL,0,NULL);
				mciSendString("play music repeat",NULL,0,NULL);
				cout<<files[i].c_str()<<" 正在播放"<<endl;
			}
			else
			{
				mciSendString("close music", NULL, 0, NULL);
				i=files.size ()-1;
				mciSendString(musicfiles[i].c_str(),NULL,0,NULL);
				mciSendString("play music repeat",NULL,0,NULL);
				cout<<files[i].c_str()<<" 正在播放"<<endl;
				//cout<<files[i].c_str()<<" 已经是第一首"<<endl;
			}
			break;
			//下一首（循环）
		case '2':
			if(i<(files.size()-1))
			{
				mciSendString("close music", NULL, 0, NULL);
				i++;
				mciSendString(musicfiles[i].c_str(),NULL,0,NULL);
				mciSendString("play music repeat",NULL,0,NULL);
				cout<<files[i].c_str()<<" 正在播放"<<endl;
			}
			else
			{
				mciSendString("close music", NULL, 0, NULL);
				i=0;
				mciSendString(musicfiles[i].c_str(),NULL,0,NULL);
				mciSendString("play music repeat",NULL,0,NULL);
				cout<<files[i].c_str()<<" 正在播放"<<endl;
				//cout<<files[i].c_str()<<" 已经是最后首"<<endl;
			}

			break;
			//点歌播放
		case 'c':
		case 'C':
			while(1)
			{
				listMusic1();//显示歌曲清单
				cout<<"请输入歌曲序号:"<<"1~~"<<files.size()<<endl;
				scanf("%d",&i);
				fflush(stdin);
				if(i>0&&i<=(files.size()))
				{
					if(mciSendString("close music", NULL, 0, NULL))//关闭音乐
						cout<<"关闭音乐失败"<<endl;
					if(mciSendString(musicfiles[i-1].c_str(),NULL,0,NULL))//打开文件
						cout<<"打开音乐失败"<<endl;
					else
					{
						cout<<"正在播放:"<<files[i-1].c_str()<<endl;
					}
					if(mciSendString("play music repeat",NULL,0,NULL))//播放音乐
						cout<<"播放音乐失败"<<endl;
					else
					{
						break;

					}

				}
				else
				{
					cout<<"输入歌曲序号不在歌曲序号范围内，请重新输入"<<endl;
				}
			}
			break;
		case 'L':
			listMusic1();//歌曲清单

			break;
			//增大音量
		case '+':
			char chVolume[256];
			char aaa[255];
			char bbb[255];
			memset(bbb,0,255);
			long lVolume;
			mciSendString("status music volume",chVolume,255,0);
			lVolume=strtol(chVolume,NULL,10);
			lVolume+=100;
			if(lVolume>=1000)
			{
				mciSendString("setaudio music volume to 1000",NULL,0,NULL);
				cout<<"当前为最大音量"<<endl;
				break;
			}

			itoa(lVolume,aaa,10);

			//cout<<aaa<<endl;
			strcat(bbb,"setaudio music volume to ");
			strcat(bbb,aaa);
			//cout<<bbb<<endl;
			mciSendString(bbb,NULL,0,NULL);// 'V是设置的音量值
			cout<<"当前播放音量 "<<lVolume<<endl;
			break;
			//减小音量
		case '-':
			{
				char chVolume[256];
				char aaa[255];
				char bbb[255];
				memset(bbb,0,255);
				memset(chVolume,0,256);
				long lVolume;
				mciSendString("status music volume",chVolume,255,0);
				lVolume=strtol(chVolume,NULL,10);
				lVolume-=100;
				if(lVolume<=0)
				{
					mciSendString("setaudio music volume to 0",NULL,0,NULL);
					cout<<"当前为最小音量"<<endl;
					break;

				}

				itoa(lVolume,aaa,10);

				//cout<<aaa<<endl;
				strcat(bbb,"setaudio music volume to ");
				strcat(bbb,aaa);
				//cout<<bbb<<endl;
				mciSendString(bbb,NULL,0,NULL);// 'V是设置的音量值
				cout<<"当前播放音量 "<<lVolume<<endl;
			}
			break;
		case 'Q':
			//关闭播放器
			exit(1);
			break;
		default:
			cout<<"输入错误"<<endl;

		}

	}

}
//顺序播放-----2
void orderMusic()
{
	unsigned int i;
	for(i=0;i<files.size();i++)
	{

		if(mciSendString(musicfiles[i].c_str(),NULL,0,NULL))//打开文件
			cout<<"打开音乐失败"<<endl;
		cout<<files[i].c_str()<<" 正在播放"<<endl;
		if(mciSendString("play music wait",NULL,0,NULL))//播放音乐
			cout<<"播放音乐失败"<<endl;

		else
		{
			cout<<files[i].c_str() <<"播放完成"<<endl;
		}
	}
	cout<<"所有歌曲播放完毕"<<endl;
	musicFace();
}
//随机播放----3
void randomMusic()
{
	while(1)
	{
		srand((unsigned int)time(NULL));
		unsigned int i;
		i=rand()%(files.size());
		if(mciSendString(musicfiles[i].c_str(),NULL,0,NULL))//打开文件
			cout<<"打开音乐失败"<<endl;
		else
		{
			cout<<"正在播放:"<<files[i].c_str()<<endl;
		}
		if(mciSendString("play music wait",NULL,0,NULL))//播放音乐
			cout<<"播放音乐失败"<<endl;
		if(mciSendString("close music", NULL, 0, NULL))//关闭音乐
			cout<<"关闭音乐失败"<<endl;
		else
		{
			cout<<files[i].c_str() <<"播放完成"<<endl;
		}
	}

}
//循环播放-----4
void circulationMusic()
{
	int i=0;
	while(1)
	{

		if(mciSendString(musicfiles[i].c_str(),NULL,0,NULL))//打开文件
			cout<<"打开音乐失败"<<endl;
		else
		{
			cout<<"正在播放:"<<files[i].c_str()<<endl;
		}
		if(mciSendString("play music wait",NULL,0,NULL))//播放音乐
			cout<<"播放音乐失败"<<endl;
		if(mciSendString("close music", NULL, 0, NULL))//关闭音乐
			cout<<"关闭音乐失败"<<endl;
		else
		{
			cout<<files[i].c_str() <<"播放完成"<<endl;
		}
		i++;
		if(i==files.size())
			i=0;
	}

}
//选择播放-----5
void seleteMusic()
{
	while(1)
	{
		listMusic1();
		cout<<"请输入歌曲序号:"<<"1~~"<<files.size()<<endl;
		unsigned int i;
		scanf("%d",&i);
		fflush(stdin);
		if(i>0&&i<=files.size())
		{
			if(mciSendString(musicfiles[i-1].c_str(),NULL,0,NULL))//打开文件
				cout<<"打开音乐失败"<<endl;
			else
			{
				cout<<"正在播放:"<<files[i-1].c_str()<<endl;
			}
			if(mciSendString("play music wait",NULL,0,NULL))//播放音乐
				cout<<"播放音乐失败"<<endl;
			if(mciSendString("close music", NULL, 0, NULL))//关闭音乐
				cout<<"关闭音乐失败"<<endl;
			else
			{
				cout<<files[i-1].c_str() <<"播放完成"<<endl;
			}
		}
		else
		{
			cout<<"输入歌曲序号不在歌曲序号范围内"<<endl;
		}
	}
}
//显示播放列表-----6
void listMusic()
{
	unsigned int i;
	for(i=0;i<files.size();i++)
	{
		cout<<files[i].c_str()<<"\t"<<"第 "<<i+1<<" 首"<<endl;
	}
	cout<<"共 "<<files.size()<<" 首音乐"<<endl;

}
void listMusic1()
{
	unsigned int i;
	for(i=0;i<files.size();i++)
	{
		cout<<files[i].c_str()<<"\t"<<"第 "<<i+1<<" 首"<<endl;
	}
	cout<<"共 "<<files.size()<<" 首音乐"<<endl;
}
void musicFunction()
{

	//int m_key;
	char m_key;
	while(1)
	{
		//程序界面
		musicFace();

		//scanf("%d",&m_key);
		fflush(stdin);
		m_key=getchar();
		switch(m_key)
		{
			//人工播放----1
		case '1':
			peopleMusic();
			break;
			//顺序播放---2
		case '2':
			orderMusic();
			break;
			//随机播放---3
		case '3':
			randomMusic();
			break;

			//循环播放---4
		case '4':
			circulationMusic();

			break;
			//选择播放---5
		case '5':
			seleteMusic();
			break;
			//显示播放列表---6
		case 'l':
		case 'L':
			listMusic();
			break;
			//退出播放器
		case 'q':
		case 'Q':
			exit(1);
			break;
		default:
			cout<<"输入错误"<<endl;
		}
	}
}