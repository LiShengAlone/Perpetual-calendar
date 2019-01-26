#include<graphics.h>
#include<stdio.h>
#include<time.h>

#define WINDOW_HEIGHH 810//窗口高
#define WINDOW_WDITH 1550//窗口宽
#define SPACE 180//数字与汉字间隔

VOID initsubtitles();//初始化字幕
VOID TimeChange();//时间变化
VOID WriteTime();//写时间

IMAGE bkimage;
TCHAR shi[] = _T("时");
TCHAR fen[] = _T("分");
TCHAR miao[] = _T("秒");
TCHAR yue[] = _T("月");
TCHAR ri[] = _T("日");
TCHAR xingqi[] = _T("星期");
TCHAR nian[] = _T("年");
TCHAR yi[] = _T("一");
TCHAR er[] = _T("二");
TCHAR san[] = _T("三");
TCHAR si[] = _T("四");
TCHAR wu[] = _T("五");
TCHAR liu[] = _T("六");
TCHAR qi[] = _T("日");
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
	time(&t);//获取时间
	it = localtime(&t);//转为时间结构
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
		printf("请输入当前年、月、日、时、分、秒、星期。中间用空格或回车分开：\n");
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
		printf("%d/%d/%d\t%d:%d:%d\t星期%d\n", NIAN, YUE, RI, SHI, FEN, MIAO, XINGQI);
	}
	
}

VOID WriteTime()
{
	settextcolor(RED);
	settextstyle(80, 80, L"宋体");

	//时显示
	_stprintf_s(hour, _T("%d"), SHI);
	outtextxy(60, 80, hour);

	//分显示
	_stprintf_s(minute, _T("%d"), FEN);
	outtextxy(380, 80, minute);

	//秒显示
	_stprintf_s(seconds, _T("%d"), MIAO);
	outtextxy(700, 80, seconds);

	//月显示
	_stprintf_s(month, _T("%d"), YUE);
	outtextxy(140, 240, month);

	//日显示
	_stprintf_s(date, _T("%d"), RI);
	outtextxy(480, 240, date);

	//年显示
	_stprintf_s(year, _T("%d"), NIAN);
	outtextxy(100, 560, year);


	settextstyle(80, 63, L"方正舒体");//方正舒体 华文新魏
	settextcolor(BLUE);

	outtextxy(60 + SPACE, 80, shi);

	outtextxy(380 + SPACE, 80, fen);

	outtextxy(700 + SPACE, 80, miao);

	outtextxy(150 + SPACE, 240, yue);

	outtextxy(490 + SPACE, 240, ri);

	outtextxy(120, 400, xingqi);

	outtextxy(100 + SPACE * 2, 560, nian);


	//星期显示
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