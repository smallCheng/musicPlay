#include"music.h"

//�����嵥
vector<string> files;
//����·���嵥
vector<string> musicfiles;

//��ȡres�ļ���MP3��ʽ�ļ����ļ������ļ�·���ֱ���ؽ���������
void m_setColor()
{
	system("color F3");


}
void musicList()
{
	//���res�ļ��в����� ���򴴽�
	if(CreateDirectory("..\\res",NULL))
	{
		cout<<endl;
		cout<<"�Ѵ���res�ļ���"<<endl;
		cout<<"����res�ļ������mp3��ʽ�����ļ���������������!!!!!!!"<<endl;
		cout<<endl;
		Sleep(10000);
		exit(1);
	}
	
	//�ļ����
	long   hFile   =   0;
	//�ļ���Ϣ
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
			//������ļ����������ļ���,����֮
			//�������,�����б�
			// ���Ƽ�ʹ�ã�ӲҪʹ�õĻ�����Ҫ�޸�else ��������
			/*if((fileinfo.attrib &  _A_SUBDIR))
			{
			if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
			getFiles( pathName.assign(path).append("\\").append(fileinfo.name), exd, files );
			}
			else */
			{
				if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
					//files.push_back(pathName.assign(path).append("\\").append(fileinfo.name)); // Ҫ�õ�����Ŀ¼ʹ�ø����
					//���ʹ��
				{
					files.push_back(fileinfo.name); // ֻҪ�õ��ļ�����ʹ�ø����
					string pn="open "+path+"\\"+fileinfo.name+" alias music";
					//cout<<pn<<endl;
					musicfiles.push_back (pn);
					//cout<<fileinfo.name<<endl;
				}
			}
		}while(_findnext(hFile, &fileinfo)  == 0);
		_findclose(hFile);
	}
	//��res�ļ����п�
	if(1==files.empty())
	{
		cout<<endl;
		cout<<"res�ļ���Ϊ��"<<endl;
		cout<<"����res�ļ������mp3��ʽ�����ļ���������������!!!!!!!"<<endl;
		cout<<endl;
		Sleep(10000);
		exit(1);

	}
}
//��ӭҳ�棬���˵�
void musicFace()
{
	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"-----------------------------��ӭʹ�ñ�������-------------------------"<<endl;
	cout<<"-------------------------------QQ:314086782---------------------------"<<endl;
	cout<<"-----------------ע�����˹�ģʽ�⣬����ģʽ��Ϊ�̶�ģʽ---------------"<<endl;
	cout<<"����ʹ����Ӧ�Ĺ���"<<endl;
	cout<<"1---�˹�����ģʽ\t\t";
	cout<<"2---˳�򲥷�ģʽ\t\t";
	cout<<"3---�������ģʽ"<<endl;;
	cout<<"4---ѭ������ģʽ\t\t";
	cout<<"5---ѡ�񲥷�ģʽ\t\t";
	cout<<"L---��ʾ�����б�"<<endl;
	cout<<"Q---�˳�������"<<endl<<endl;
	cout<<"�����빦�ܼ�: ";

}

//�˹�ģʽ����ѡ��
void playMusic()
{
	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"������һ��---1\t\t";
	cout<<"������һ��---2\t\t";
	cout<<"��貥��-----C"<<endl;
	cout<<"��ͣ����-----P\t\t";
	cout<<"�ָ�����-----R\t\t";
	cout<<"ֹͣ���ţ��������˵�---U"<<endl;
	cout<<"�����嵥-----L\t\t";
	cout<<"��������---(+)\t\t";
	cout<<"������С---(-)"<<endl;
	cout<<"�˳�������---Q"<<endl<<endl;
}
//�˹�����-----1
void peopleMusic()
{
	//��ǰ����״̬
	char m_post;
	unsigned int i=0;
	if(mciSendString(musicfiles[i].c_str(),NULL,0,NULL))//���ļ�
		cout<<"������ʧ��"<<endl;
	if(mciSendString("play music repeat",NULL,0,NULL))//��������
		cout<<"��������ʧ��"<<endl;
	cout<<files[i].c_str()<<" ���ڲ���"<<endl;

	while(1)
	{
		//�˹�ѡ��
		playMusic();
		//��ȡ����
		cout<<"�����빦�ܼ�: ";
		//scanf("%d",&m_post);
		fflush(stdin);
		m_post=getchar();
		switch(m_post)
		{
			//��ͣ��������
		case 'p':
		case 'P':
			if(mciSendString("pause music", NULL, 0, NULL))// ��ͣ���� 
				cout<<"��ͣʧ��<<endl";
			cout<<files[i].c_str()<<" ����ͣ����"<<endl;

			while(1)
			{
				//scanf("%d",&m_post);
				fflush(stdin);
				m_post=getchar();
				if('r'==m_post||'R'==m_post)
				{

					if(mciSendString("resume music", NULL, 0, NULL))//�ָ���������
						cout<<"�ָ�����ʧ��"<<endl;
					cout<<files[i].c_str()<<" �ѻָ�����"<<endl;
					break;
				}

			}
			break;
			//case 1 ���� (�ָ�����)
		case 'r':
		case 'R':

			break;
			//ֹͣ���ŷ������˵�
		case 'u':
		case 'U':
			if(mciSendString("close music", NULL, 0, NULL))//�ر�����
				cout<<"�ر�����ʧ��"<<endl;
			cout<<"�ر����ֳɹ�"<<endl;
			return ;
			break;
			//��һ��(ѭ��)
		case '1':
			if(i>0)
			{
				mciSendString("close music", NULL, 0, NULL);
				i--;
				mciSendString(musicfiles[i].c_str(),NULL,0,NULL);
				mciSendString("play music repeat",NULL,0,NULL);
				cout<<files[i].c_str()<<" ���ڲ���"<<endl;
			}
			else
			{
				mciSendString("close music", NULL, 0, NULL);
				i=files.size ()-1;
				mciSendString(musicfiles[i].c_str(),NULL,0,NULL);
				mciSendString("play music repeat",NULL,0,NULL);
				cout<<files[i].c_str()<<" ���ڲ���"<<endl;
				//cout<<files[i].c_str()<<" �Ѿ��ǵ�һ��"<<endl;
			}
			break;
			//��һ�ף�ѭ����
		case '2':
			if(i<(files.size()-1))
			{
				mciSendString("close music", NULL, 0, NULL);
				i++;
				mciSendString(musicfiles[i].c_str(),NULL,0,NULL);
				mciSendString("play music repeat",NULL,0,NULL);
				cout<<files[i].c_str()<<" ���ڲ���"<<endl;
			}
			else
			{
				mciSendString("close music", NULL, 0, NULL);
				i=0;
				mciSendString(musicfiles[i].c_str(),NULL,0,NULL);
				mciSendString("play music repeat",NULL,0,NULL);
				cout<<files[i].c_str()<<" ���ڲ���"<<endl;
				//cout<<files[i].c_str()<<" �Ѿ��������"<<endl;
			}

			break;
			//��貥��
		case 'c':
		case 'C':
			while(1)
			{
				listMusic1();//��ʾ�����嵥
				cout<<"������������:"<<"1~~"<<files.size()<<endl;
				scanf("%d",&i);
				fflush(stdin);
				if(i>0&&i<=(files.size()))
				{
					if(mciSendString("close music", NULL, 0, NULL))//�ر�����
						cout<<"�ر�����ʧ��"<<endl;
					if(mciSendString(musicfiles[i-1].c_str(),NULL,0,NULL))//���ļ�
						cout<<"������ʧ��"<<endl;
					else
					{
						cout<<"���ڲ���:"<<files[i-1].c_str()<<endl;
					}
					if(mciSendString("play music repeat",NULL,0,NULL))//��������
						cout<<"��������ʧ��"<<endl;
					else
					{
						break;

					}

				}
				else
				{
					cout<<"���������Ų��ڸ�����ŷ�Χ�ڣ�����������"<<endl;
				}
			}
			break;
		case 'L':
			listMusic1();//�����嵥

			break;
			//��������
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
				cout<<"��ǰΪ�������"<<endl;
				break;
			}

			itoa(lVolume,aaa,10);

			//cout<<aaa<<endl;
			strcat(bbb,"setaudio music volume to ");
			strcat(bbb,aaa);
			//cout<<bbb<<endl;
			mciSendString(bbb,NULL,0,NULL);// 'V�����õ�����ֵ
			cout<<"��ǰ�������� "<<lVolume<<endl;
			break;
			//��С����
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
					cout<<"��ǰΪ��С����"<<endl;
					break;

				}

				itoa(lVolume,aaa,10);

				//cout<<aaa<<endl;
				strcat(bbb,"setaudio music volume to ");
				strcat(bbb,aaa);
				//cout<<bbb<<endl;
				mciSendString(bbb,NULL,0,NULL);// 'V�����õ�����ֵ
				cout<<"��ǰ�������� "<<lVolume<<endl;
			}
			break;
		case 'Q':
			//�رղ�����
			exit(1);
			break;
		default:
			cout<<"�������"<<endl;

		}

	}

}
//˳�򲥷�-----2
void orderMusic()
{
	unsigned int i;
	for(i=0;i<files.size();i++)
	{

		if(mciSendString(musicfiles[i].c_str(),NULL,0,NULL))//���ļ�
			cout<<"������ʧ��"<<endl;
		cout<<files[i].c_str()<<" ���ڲ���"<<endl;
		if(mciSendString("play music wait",NULL,0,NULL))//��������
			cout<<"��������ʧ��"<<endl;

		else
		{
			cout<<files[i].c_str() <<"�������"<<endl;
		}
	}
	cout<<"���и����������"<<endl;
	musicFace();
}
//�������----3
void randomMusic()
{
	while(1)
	{
		srand((unsigned int)time(NULL));
		unsigned int i;
		i=rand()%(files.size());
		if(mciSendString(musicfiles[i].c_str(),NULL,0,NULL))//���ļ�
			cout<<"������ʧ��"<<endl;
		else
		{
			cout<<"���ڲ���:"<<files[i].c_str()<<endl;
		}
		if(mciSendString("play music wait",NULL,0,NULL))//��������
			cout<<"��������ʧ��"<<endl;
		if(mciSendString("close music", NULL, 0, NULL))//�ر�����
			cout<<"�ر�����ʧ��"<<endl;
		else
		{
			cout<<files[i].c_str() <<"�������"<<endl;
		}
	}

}
//ѭ������-----4
void circulationMusic()
{
	int i=0;
	while(1)
	{

		if(mciSendString(musicfiles[i].c_str(),NULL,0,NULL))//���ļ�
			cout<<"������ʧ��"<<endl;
		else
		{
			cout<<"���ڲ���:"<<files[i].c_str()<<endl;
		}
		if(mciSendString("play music wait",NULL,0,NULL))//��������
			cout<<"��������ʧ��"<<endl;
		if(mciSendString("close music", NULL, 0, NULL))//�ر�����
			cout<<"�ر�����ʧ��"<<endl;
		else
		{
			cout<<files[i].c_str() <<"�������"<<endl;
		}
		i++;
		if(i==files.size())
			i=0;
	}

}
//ѡ�񲥷�-----5
void seleteMusic()
{
	while(1)
	{
		listMusic1();
		cout<<"������������:"<<"1~~"<<files.size()<<endl;
		unsigned int i;
		scanf("%d",&i);
		fflush(stdin);
		if(i>0&&i<=files.size())
		{
			if(mciSendString(musicfiles[i-1].c_str(),NULL,0,NULL))//���ļ�
				cout<<"������ʧ��"<<endl;
			else
			{
				cout<<"���ڲ���:"<<files[i-1].c_str()<<endl;
			}
			if(mciSendString("play music wait",NULL,0,NULL))//��������
				cout<<"��������ʧ��"<<endl;
			if(mciSendString("close music", NULL, 0, NULL))//�ر�����
				cout<<"�ر�����ʧ��"<<endl;
			else
			{
				cout<<files[i-1].c_str() <<"�������"<<endl;
			}
		}
		else
		{
			cout<<"���������Ų��ڸ�����ŷ�Χ��"<<endl;
		}
	}
}
//��ʾ�����б�-----6
void listMusic()
{
	unsigned int i;
	for(i=0;i<files.size();i++)
	{
		cout<<files[i].c_str()<<"\t"<<"�� "<<i+1<<" ��"<<endl;
	}
	cout<<"�� "<<files.size()<<" ������"<<endl;

}
void listMusic1()
{
	unsigned int i;
	for(i=0;i<files.size();i++)
	{
		cout<<files[i].c_str()<<"\t"<<"�� "<<i+1<<" ��"<<endl;
	}
	cout<<"�� "<<files.size()<<" ������"<<endl;
}
void musicFunction()
{

	//int m_key;
	char m_key;
	while(1)
	{
		//�������
		musicFace();

		//scanf("%d",&m_key);
		fflush(stdin);
		m_key=getchar();
		switch(m_key)
		{
			//�˹�����----1
		case '1':
			peopleMusic();
			break;
			//˳�򲥷�---2
		case '2':
			orderMusic();
			break;
			//�������---3
		case '3':
			randomMusic();
			break;

			//ѭ������---4
		case '4':
			circulationMusic();

			break;
			//ѡ�񲥷�---5
		case '5':
			seleteMusic();
			break;
			//��ʾ�����б�---6
		case 'l':
		case 'L':
			listMusic();
			break;
			//�˳�������
		case 'q':
		case 'Q':
			exit(1);
			break;
		default:
			cout<<"�������"<<endl;
		}
	}
}