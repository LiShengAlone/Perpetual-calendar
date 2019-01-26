#include<graphics.h>
#include<stdio.h>
#include<time.h>

#define WINDOW_HEIGHH 810//���ڸ�
#define WINDOW_WDITH 1550//���ڿ�
#define SPACE 180//�����뺺�ּ��

VOID initsubtitles();//��ʼ����Ļ
VOID TimeChange();//ʱ��仯
VOID WriteTime();//дʱ��

IMAGE bkimage;
TCHAR shi[] = _T("ʱ");
TCHAR fen[] = _T("��");
TCHAR miao[] = _T("��");
TCHAR yue[] = _T("��");
TCHAR ri[] = _T("��");
TCHAR xingqi[] = _T("����");
TCHAR nian[] = _T("��");
TCHAR yi[] = _T("һ");
TCHAR er[] = _T("��");
TCHAR san[] = _T("��");
TCHAR si[] = _T("��");
TCHAR wu[] = _T("��");
TCHAR liu[] = _T("��");
TCHAR qi[] = _T("��");
TCHAR hour[20];
TCHAR minute[20];
TCHAR seconds[20];
TCHAR year[100];
TCHAR month[20];
TCHAR date[20];
int SHI;
int FEN;
int MIAO;
int YUE;
int RI;
int XINGQI;
int NIAN;

int main(void)
{
	initsubtitles();
	TimeChange();
	return 0;
}

VOID initsubtitles()
{
	initgraph(WINDOW_WDITH, WINDOW_HEIGHH);
	loadimage(&bkimage, L"wannianli.jpg", WINDOW_WDITH, WINDOW_HEIGHH);
	putimage(0, 0, &bkimage);
	time_t t;
	struct tm* it;
	time(&t);//��ȡʱ��
	it = localtime(&t);//תΪʱ��ṹ
	NIAN = it->tm_year + 1900;
	YUE = it->tm_mon + 1;
	RI = it->tm_mday;
	SHI = it->tm_hour;
	FEN = it->tm_min;
	MIAO = it->tm_sec;
	XINGQI = it->tm_wday;
	if (XINGQI == 0)
		XINGQI = 7;
	if (YUE == 0)
	{
		initgraph(WINDOW_WDITH, WINDOW_HEIGHH,1);
		putimage(0, 0, &bkimage);
		printf("�����뵱ǰ�ꡢ�¡��ա�ʱ���֡��롢���ڡ��м��ÿո��س��ֿ���\n");
		scanf("%d", &NIAN);
		scanf("%d", &YUE);
		scanf("%d", &RI);
		scanf("%d", &SHI);
		scanf("%d", &FEN);
		scanf("%d", &MIAO);
		scanf("%d", &XINGQI);
	}
	setbkmode(0);
}

VOID TimeChange()
{
	while (1)
	{
		Sleep(1000);
		putimage(0, 0, &bkimage);
		MIAO++;
		if (MIAO == 60)
		{
			MIAO = 0;
			FEN++;
			printf("\a");
		}
		if (FEN == 60)
		{
			FEN = 0;
			SHI++;
		}
		if (SHI == 24)
		{
			SHI = 0;
			RI++;
			XINGQI++;
			if (XINGQI == 8)
			{
				XINGQI = 1;
			}
		}

		if (YUE == 1 || YUE == 3 || YUE == 5 || YUE == 7 || YUE == 8 || YUE == 10 || YUE == 12)
		{
			if (RI == 32)
			{
				RI = 1;
				YUE++;
			}
		}else
			if (YUE == 2)
			{
				if (NIAN % 4)
				{
					if (RI == 29)
					{
						RI = 1;
						YUE++;
					}
				}else
					if (RI == 30)
					{
						RI = 1;
						YUE++;
					}
			}
			else if (RI == 31)
			{
				RI = 1;
				YUE++;
			}


		if (YUE == 13)
		{
			YUE = 1;
			NIAN++;
		}
		WriteTime();
		printf("%d/%d/%d\t%d:%d:%d\t����%d\n", NIAN, YUE, RI, SHI, FEN, MIAO, XINGQI);
	}
	
}

VOID WriteTime()
{
	settextcolor(RED);
	settextstyle(80, 80, L"����");

	//ʱ��ʾ
	_stprintf_s(hour, _T("%d"), SHI);
	outtextxy(60, 80, hour);

	//����ʾ
	_stprintf_s(minute, _T("%d"), FEN);
	outtextxy(380, 80, minute);

	//����ʾ
	_stprintf_s(seconds, _T("%d"), MIAO);
	outtextxy(700, 80, seconds);

	//����ʾ
	_stprintf_s(month, _T("%d"), YUE);
	outtextxy(140, 240, month);

	//����ʾ
	_stprintf_s(date, _T("%d"), RI);
	outtextxy(480, 240, date);

	//����ʾ
	_stprintf_s(year, _T("%d"), NIAN);
	outtextxy(100, 560, year);


	settextstyle(80, 63, L"��������");//�������� ������κ
	settextcolor(BLUE);

	outtextxy(60 + SPACE, 80, shi);

	outtextxy(380 + SPACE, 80, fen);

	outtextxy(700 + SPACE, 80, miao);

	outtextxy(150 + SPACE, 240, yue);

	outtextxy(490 + SPACE, 240, ri);

	outtextxy(120, 400, xingqi);

	outtextxy(100 + SPACE * 2, 560, nian);


	//������ʾ
	settextcolor(RED);
	switch (XINGQI)
	{
	case 1:
		outtextxy(120 + SPACE * 2, 400, yi);
		break;
	case 2:
		outtextxy(120 + SPACE * 2, 400, er);
		break;
	case 3:
		outtextxy(120 + SPACE * 2, 400, san);
		break;
	case 4:
		outtextxy(120 + SPACE * 2, 400, si);
		break;
	case 5:
		outtextxy(120 + SPACE * 2, 400, wu);
		break;
	case 6:
		outtextxy(120 + SPACE * 2, 400, liu);
		break;
	case 7:
		outtextxy(120 + SPACE * 2, 400, qi);
		break;
	}
}