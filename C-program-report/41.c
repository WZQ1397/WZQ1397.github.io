//include "stdafx.h"
#include <stdio.h>
#include <ctype.h> //���ڴ�Сдת��
#include <windows.h>
#include <stdlib.h> //system������Ҫ�˱�׼���ļ�
#include <conio.h> //��Ҫ�õ�kbhit��������Ҫ��ͷ�ļ�
#include <time.h> //�ڼ�ʱ����Ҫ�õ�clock��������Ҫ��ͷ�ļ�
#define N 5
void help();
void play();
void color();
void setcolor();
void chal();
void save();
void open();
int timefun();
int sc;
struct SC
{
	char    name[10];
	int     score;
	char    addr[20];
}point;
main()
{
	int n;
	system("color 8f");//������ɫ
	printf("\t\t\t====++=====MEUN=====++====\n\t\t");
	printf("\t�d   1.PLAY THE GAME\t�g\n\t\t");
	printf("\t�d   2.HELP\t\t�g\n\t\t");
	printf("\t�d   3.COLOR SET\t�g\n\t\t");
	printf("\t�d   4.CHALLANGE MODE\t�g\n\t\t");
	printf("\t�d   5.EXIT\t\t�g\n\t\t");
	printf("\t�d   6.TOP BROAD\t�g\n");
	printf("\t\t\t===++POWER BY WZQ1397++===\n");
	printf("\nplease input your choose!\n");
	timefun();//������ʱ�ж��û���ҳͣ��ʱ��
	printf("\n:\n");
	scanf("%d",&n);
	system("CLS");//����
	switch(n)//����Ϊ�˵�
	{
	case 1: 
		play();
		break;
	case 2: 
		help();
		break;
	case 3: 
		color();
		break;
	case 4: 
		chal();
		break;
	case 5: 
		exit(0);
		break;
	case 6: 
		open();
		break;
	default:
		printf("error!");
		system("CLS");
		exit(0);
	}
	getch();
	return 0;
}
int timefun()//��ʱ����
{
	int i;
	double t;
	clock_t start,finish;//����start �� finish
	start=clock();//��ʼ��ʱ
	for(i=0;;i++)
	{
		finish=clock();//������ʱ
		t=(double)(finish-start)/CLOCKS_PER_SEC;//ʱ�侫ȷ��ǧ��֮һ�룬CLOCKS_PER_SECΪtickʱ��
		
		printf("you have wait %.3f sec\r",t);
		if((float)t==30)
		{
			setcolor(12,3);//������ɫ���֣���������
			printf("Do you want to exit?\t\tIf you want to go on.Please input select:\r");
			continue;
		}
		if(t>=60)//ʱ�����60s�޲�����������Զ��˳�
			
		{
			printf("\n");
			exit(0);
		}
		if(kbhit())//��enter���²����򴥷�
			break;
	}
	system("color 8e");
}
void help() //��Ϸ��������
{
	int cho;
	printf("\teasy:\nRandom 25 nums from 50 nums\n\n");
	printf("\thard:\nRandom 25 nums from 100 nums\n\n");
	printf("\tmaster:\nRandom 25 nums from 200 nums\n\n");
	printf("\tX:\nRandom 25 nums from 75 nums\n\n\n");
	printf("challenge mode will account your score\n\n");
	printf("press 1 return\tpress 2 play the game\n");
	scanf("%d",&cho);
	system("CLS");//��������ǰ������
	if(cho==2)
		play();
	if(cho==1)
		main();
	else
		exit(0);
	getch();
}
void color()//��ɫ���ں���
{
	int n,w;
	printf("\t\t===++POWER BY WZQ1397++===\n\nplease choose color!:\n");
	printf("0=��ɫ 1=��ɫ 2=��ɫ 9=����ɫ 4=��ɫ 5=��ɫ 6=��ɫ 7=��ɫ 8=��ɫ\n");
	scanf("%d",&n);
	switch(n)
	{	
	case 1: 
		system("color 1b");
		break;
	case 0: 
		system("color 0c");
		break;
	case 4: 
		system("color 4f");
		break;
	case 2: 
		system("color 2b");
		break;
	case 7: 
		system("color 7c");
		break;
	case 9: 
		system("color 9f");
		break;
	case 6: 
		system("color 6a");
		break;
	case 5: 
		system("color 5f");
		break;
	case 8: 
		system("color 8f");
		break;
	}
	printf("\npress 1 return\tpress 2 play the game\n:");
	scanf("%d",&w);	
	system("CLS");//��������ǰ������
	if(w==2)
		play();
	if(w==1)
		main();
	else
		exit(0);
	getch();
}
void play()//��ͨģʽ��Ϸ������
{  
	int key,a[N][N]={0};
	int flag=0,i,j,*p,w,M,t,u,v,s=0,x,q;
	printf("please choose stage:\n\t\t��������������������������\n\t\t|\t1.easy\t\t|\n\t\t|\t2.hard\t\t|\n");
	printf("\t\t|\t3.master\t|\n\t\t|    X.(other).normal   |\n\t\t��������������������������\n\nanswer: \n");
	scanf("%d",&w);
	switch(w)
	{
		/*����Ϊ�Ѷ�ѡ��˵��ӵ͵����Ѷȣ�MԽ���Ѷ�Խ��*/
	case 1: 
		M=50;
		break;
	case 2: 
		M=100;
		break;
	case 3: 
		M=200;
		break;
	default: 
		M=75;
	}
	/*��ʱ����Ϊseed��������������������������rand������ϲ���α�����*/
	srand(time(NULL));
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			a[i][j]=rand()%M;//�ö�ά�������������֣���ΧΪ0~(M-1)
			flag=1;
			p=&a[i][j];//ָ��ָ��һ����ά����
			while((p+1)!=a)
				if(*(--p)==a[i][j])
				{
					flag=0;
					break;
				}
				if(!flag) 
				{
					j--;
					continue;
				}
		}
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
				printf("%4d ",a[i][j]);
			printf("\n");
		}
		system("CLS");
		printf("please input num:\n(auto choose 1\t choose num by yourself choose 2\n)");
		scanf("%d",&q);
		if(q==1)
		{
			while(!kbhit())//���������κβ����򴥷�
			{
				key=rand()%M;
				printf("your num is:%d\r",key);
			}
			printf("\n");
		}
		if(q==2)
		{
			printf("please input your num:\n");
			scanf("%d",&key);
			printf("your num is:%d\n",key);
		}
		else
		{
		exit(0);
		}
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(a[i][j]==key)
				{
					t=1;
					if(s<1)
					{
						u=i;
						v=j;
						s+=1;
					}
				}
			}
		}
		if(t==1)
		{
			printf("bingo! %d target at <%d,%d>\nPOWER BY WZQ1397",key,v,u);//V,U is location
		}
		else
			printf("you failed\nPOWER BY WZQ1397");
		printf("\n PRESS 1 BACK!\n");
		scanf("%d",&x);
		if(x==1)
		{	
			system("CLS");
			main();
		}
		else
		{
		exit(0);
		}
		getch();
}
void chal()//��սģʽ
{
	int M=50,i,j,key,in=1,flag,right;
	int a[N][N]={0},*p,cho;
	int kk[10];
	int judge;
	srand(time(NULL));
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			a[i][j]=rand()%M;//�ö�ά�������������֣���ΧΪ0~(M-1)
			flag=1;
			p=&a[i][j];//ָ��ָ��һ����ά����
			
			while((p+1)!=a)
				if(*(--p)==a[i][j])
				{
					flag=0;
					break;
				}
				if(!flag) 
				{
					j--;
					continue;
				}
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf("%4d ",a[i][j]);
		printf("\n");
	}
	system("CLS");
	system("CLS");
	printf("please input 10 num:\n");
	/*��ȡ�û���������Ϣ�������ж��Ƿ���У�������ӷ�*/
	for(;in<=10;in++)
	{
		scanf("%d",&kk[in-1]);
		printf("your [%d]. num is:%d\n",in,kk[in-1]);
	}
	system("CLS");
	for(in=0;in<10;in++)
	{
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				if(kk[in]==a[i][j])
				{
					printf("you have guess right %4d\t",kk[in]);
					right++;
					if(right%2==0)
					{
						printf("\n");
					}
				}
			}
		}
	}
	sc=right*10;
	printf("you score is : %d\n",sc);
	printf("\nDo you want to save your score? press 1 to save\n:");
	getch();
	scanf("%d",&judge);
	if(judge==1 || judge==1)
	{
		scanf("\n%s%s",point.name,point.addr);//�����û���Ϣ
		save();
		switch(cho)
		{
		case 1:
			main();
			break;
		case 2:
			play();
			break;
		default:
			exit(0);
		}
	}
	else
	{
		main();
	}	
}
void save( )//�ѳɼ����浽�ļ���
{
	FILE *fp;
	if((fp=fopen("score.dat","wb"))==NULL) 
	{
		printf("cannot open file\n");
		return;
	}
	point.score=sc;
	if(fwrite (&point,sizeof (struct SC),1,fp)!=1)
		printf ("file write error\n");
	fclose(fp);
	system("CLS");
	main();
}
void open()//�򿪲��鿴�ϴγɼ�
{
	FILE *fp;
	printf("\t\t++++===TOP SCORE===++++\n");
	printf("\tNAME\t\tADDRESS\t\tSCORE\n");
	if((fp=fopen("score.dat","rb"))==NULL)
	{
		printf("can not open file !\n");
		exit(0);
	}
	if(fread(&point,sizeof(struct SC),1,fp)!=1)
		printf("error!");
	printf("\n  %10s%12s%4d",point.name,point.addr,point.score);
	printf("\n   *******************************     \n\n");
	fclose(fp);
	printf("press enter return main\n");
	getch();
	system("CLS");
	main();
}
void setcolor(unsigned short Font,unsigned short Back)//�Ե��е�����ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(Font%16)|(Back%16*16)); 
}