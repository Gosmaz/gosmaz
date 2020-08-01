#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

#define col GetStdHandle(STD_OUTPUT_HANDLE)
#define RED SetConsoleTextAttribute( col ,0x000c);
#define YELLOW SetConsoleTextAttribute( col ,0x000e);
#define WHITE SetConsoleTextAttribute( col ,0x000f);
#define BLUE SetConsoleTextAttribute( col ,0x000b);
#define GREEN SetConsoleTextAttribute( col ,0x000a);
#define PURPLE SetConsoleTextAttribute( col ,0x000d);

typedef enum USER_ANGLE{
	up = 1,
	down,
	left,
	right,
	stay
}ANG;

struct PLAYER{
	ANG player_ang; //플레이어가 보고 있는 방향
	int player_x; //플레이어 X좌표
	int player_y; //플레이어 y좌표
};

struct STATE{
		int HP;
		int MP;
		int STR;
		int DEX;
		int LUCK;
		int INT;
		int DO;
		int BONUS;
		int LEV;
		int EXP;
		int GOLD;
};

struct wh_select{
	int w_min;
	int w_max;
	int h_min;
	int h_max;
};

struct window_size{
	int width;
	int height;
};

typedef enum MAP{
	wall = 1,
	monster,
	rolling_stone,
	user,
	blank,
	item_star
} MAP;

typedef enum ITEM_LIST {
	HAMER_PAPER = 70,
	HAMER_WOOD = 71,
	HAMER_IRON = 72,
	HAMER_GOLD = 73,
	HAMER_DIA = 74,

	FIST_PAPER = 60,
	FIST_WOOD = 61,
	FIST_IRON = 62,
	FIST_GOLD = 63,
	FIST_DIA = 64,
	FIST_ONE_PUNCH = 65,
	FIST_ONLY_ONE_PUNCH = 66,

	SWORD_PAPER = 50,
	SWORD_WOOD = 51,
	SWORD_IRON = 52,
	SWORD_GOLD = 53,
	SWORD_DIA = 54,

	HEAD_PAPER = 40,
	HEAD_WOOD = 41,
	HEAD_IRON = 42,
	HEAD_GOLD = 43,
	HEAD_DIA = 44,

	BODY_PAPER = 30,
	BODY_WOOD = 31,
	BODY_IRON = 32,
	BODY_GOLD = 33,
	BODY_DIA = 34,

	ARM_PAPER = 20,
	ARM_WOOD = 21,
	ARM_IRON = 22,
	ARM_GOLD = 23,
	ARM_DIA = 24,

	LEG_PAPER = 10,
	LEG_WOOD = 11,
	LEG_IRON = 12,
	LEG_GOLD = 13,
	LEG_DIA = 14,

	FOOT_PAPER = 0,
	FOOT_WOOD = 1,
	FOOT_IRON = 2,
	FOOT_GOLD = 3,
	FOOT_DIA = 4
} ITEM;

typedef enum WASD {
	RIGHT = 77,
	LEFT = 75,
	UP = 72,
	DOWN = 80,
	SPACE = 32,
	ESC = 27,
	ENTER = 13 } WASD;

typedef enum SELECT_MAIN_LIST { 
	SELECT1 = 11, 
	SELECT2 = 12,
	SELECT3 = 13, 
	SELECT4 = 21, 
	SELECT5 = 22,
	SELECT6 = 23, 
	Option = 14, 
	Gameinfo = 24
} SELECT;

typedef enum SELECT_SHOP_LIST {
	SHOP1 = 1,
	SHOP2 = 2,
	SHOP3 = 3
} SELECT_SHOP;


typedef enum WHERE_YOU_FROM {
	MAIN = 1,
	SHOP = 2,
	STATUS = 3,
	INVENTORY = 4,
	CAVE = 5
} FROM;

typedef enum MINI_GAME{
	BLOCK = 1
} PAD;

void CursorView(int show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor; 
	hConsole = col;
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void shop_title(void);

void printf_item(ITEM item)
{
	switch(item)
	{
	case HAMER_PAPER:
		printf("HAMER_PAPER");
		break;

	case HAMER_WOOD:
		printf("HAMER_WOOD");
		break;

	case HAMER_IRON:
		printf("HAMER_IRON");
		break;

	case HAMER_GOLD:
		printf("HAMER_GOLD");
		break;

	case HAMER_DIA:
		printf("HAMER_DIA");
		break;

	case FIST_PAPER:
		printf("FIST_PAPER");
		break;

	case FIST_WOOD:
		printf("FIST_WOOD");
		break;

	case FIST_IRON:
		printf("FIST_IRON");
		break;

	case FIST_GOLD:
		printf("FIST_GOLD");
		break;

	case FIST_DIA:
		printf("FIST_DIA");
		break;

	case FIST_ONE_PUNCH:
		printf("FIST_ONE_PUNCH");
		break;

	case FIST_ONLY_ONE_PUNCH:
		printf("FIST_ONLY_ONE_PUNCH");
		break;


	case SWORD_PAPER:
		printf("SWORD_PAPER");
		break;

	case SWORD_WOOD:
		printf("SWORD_WOOD");
		break;

	case SWORD_IRON:
		printf("SWORD_IRON");
		break;

	case SWORD_GOLD:
		printf("SWORD_GOLD");
		break;

	case SWORD_DIA:
		printf("SWORD_DIA");
		break;


	case HEAD_PAPER:
		printf("HEAD_PAPER");
		break;

	case HEAD_WOOD:
		printf("HEAD_WOOD");
		break;

	case HEAD_IRON:
		printf("HEAD_IRON");
		break;

	case HEAD_GOLD:
		printf("HEAD_GOLD");
		break;

	case HEAD_DIA:
		printf("HEAD_DIA");
		break;


	case BODY_PAPER:
		printf("BODY_PAPER");
		break;

	case BODY_WOOD:
		printf("BODY_WOOD");
		break;

	case BODY_IRON:
		printf("BODY_IRON");
		break;

	case BODY_GOLD:
		printf("BODY_GOLD");
		break;

	case BODY_DIA:
		printf("BODY_DIA");
		break;

	case ARM_PAPER:
		printf("ARM_PAPER");
		break;

	case ARM_WOOD:
		printf("ARM_WOOD");
		break;

	case ARM_IRON:
		printf("ARM_IRON");
		break;

	case ARM_GOLD:
		printf("ARM_GOLD");
		break;

	case ARM_DIA:
		printf("ARM_DIA");
		break;

	case LEG_PAPER:
		printf("LEG_PAPER");
		break;

	case LEG_WOOD:
		printf("LEG_WOOD");
		break;

	case LEG_IRON:
		printf("LEG_IRON");
		break;

	case LEG_GOLD:
		printf("LEG_GOLD");
		break;

	case LEG_DIA:
		printf("LEG_DIA");
		break;

	case FOOT_PAPER:
		printf("FOOT_PAPE");
		break;

	case FOOT_WOOD:
		printf("FOOT_WOOD");
		break;

	case FOOT_IRON:
		printf("FOOT_IRON");
		break;

	case FOOT_GOLD:
		printf("FOOT_GOLD");
		break;

	case FOOT_DIA:
		printf("FOOT_DIA");
		break;

	}

	return;
}

int random_item_star(void)
{
	int buffer = 0;
	
	buffer = rand()%8;
	switch(buffer)
	{
	case 0:
		buffer += rand() % 5;
		break;

	case 1:
		buffer *= 10;
		buffer += rand()%5;
		break;

	case 2:
		buffer *= 10;
		buffer += rand()%5;
		break;

	case 3:
		buffer *= 10;
		buffer += rand()%5;
		break;

	case 4:
		buffer *= 10;
		buffer += rand()%5;
		break;

	case 5:
		buffer *= 10;
		buffer += rand()%5;
		break;

	case 6:
		buffer *= 10;
		buffer += rand()%7;
		break;

	case 7:
		buffer *= 10;
		buffer += rand()%5;
		break;

	}

	return buffer;
}

int where_x()
{
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo={0};

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);

	return bufferInfo.dwCursorPosition.X;
}

int where_y()
{
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo={0};

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);

	return bufferInfo.dwCursorPosition.Y;
}

int gotoxy(int x, int y)
{
	COORD coord={x, y};
	SetConsoleCursorPosition(col, coord);
	return 0;
}

int choice(struct window_size *size, int w_miner, int w_p_miner, int h_miner, int h_p_miner, int w_select_min, int w_select_max, int h_select_min, int h_select_max, FROM where)
{
	WASD get;
	int pointed=11;
 	SELECT main_gets=0;
	SELECT_SHOP shop_gets=0;
	BLUE;
	gotoxy(size->width*w_miner/w_p_miner-3,size->height*h_miner/h_p_miner);
	printf("=>");
	gotoxy(size->width*w_miner/w_p_miner-3,size->height*h_miner/h_p_miner);

	while(1)
	{
		if(kbhit()==1)
		{
			get=_getch();
			switch(get)
			{
			case 'D':
			case 'd':
			case RIGHT:
				BLUE;
				w_miner++;
				if(w_miner > w_select_max)
				{
					w_miner--;
					pointed--;
				}
				printf("  ");
				gotoxy(size->width*w_miner/w_p_miner-3 , size->height*h_miner/h_p_miner);
				printf("=>");
				gotoxy(size->width*w_miner/w_p_miner-3 , size->height*h_miner/h_p_miner);
				pointed++;
				break;
			case 'A':
			case 'a':
			case LEFT:
				BLUE;
				w_miner--;
				if(w_miner < w_select_min)
				{
					w_miner++;
					pointed++;
				}
				printf("  ");
				gotoxy(size->width*w_miner/w_p_miner-3 , size->height*h_miner/h_p_miner);
				printf("=>");
				gotoxy(size->width*w_miner/w_p_miner-3 , size->height*h_miner/h_p_miner);
				pointed--;
				break;
			case 'S':
			case 's':
			case DOWN:
				BLUE;
				h_miner++;
				if(h_miner > h_select_max)
				{
					h_miner--;
					pointed-=10;
				}
				printf("  ");
				gotoxy(size->width*w_miner/w_p_miner-3 , size->height*h_miner/h_p_miner);
				printf("=>");
				gotoxy(size->width*w_miner/w_p_miner-3 , size->height*h_miner/h_p_miner);
				pointed+=10;
				break;
			case 'W':
			case 'w':
			case UP:
				BLUE;
				h_miner--;
				if(h_miner < h_select_min)
				{
					h_miner++;
					pointed+=10;
				}
				printf("  ");
				gotoxy(size->width*w_miner/w_p_miner-3 , size->height*h_miner/h_p_miner);
				printf("=>");
				gotoxy(size->width*w_miner/w_p_miner-3 , size->height*h_miner/h_p_miner);
				pointed-=10;
				break;

				if(where == MAIN)
				{
				case 6:
					main_gets=SELECT6;
					return main_gets;
				case 'O':
				case 'o':
					main_gets=Option;
					return main_gets;
				case 'I':
				case 'i':
					main_gets=Gameinfo;
					return main_gets;
				}
			}
			if(get==SPACE)
			{
				printf("  ");
				return pointed;
			}
			else if(get==ESC)
			{
				return ESC;
			}
		}
		else
		{
			switch(where)
			{
			case SHOP:
				shop_title();
				gotoxy(size->width*w_miner/w_p_miner-3 , size->height*h_miner/h_p_miner);
				_sleep(100);
				break;
			}
		}
	}
}
int shop_select(struct window_size *size, struct STATE *status)
{
	struct wh_select select = {0, 0, 2, 4};
	int buffer=1;
	FROM where = SHOP;

	gotoxy(0,3);
	while(buffer<=size->width/2)
	{
		BLUE;
		printf("◆");
		buffer++;
	}
	gotoxy(0, size->height-2);
	buffer=1;
	while(buffer<=size->width/2)
	{
		printf("◆");
		buffer++;
	}
	
	WHITE;
	gotoxy(size->width/10, size->height*2/7);
	printf("1. 무기 뽑기");
	YELLOW;
	printf(" (100G)");
	WHITE;
	gotoxy(size->width/10, size->height*3/7);
	printf("2. 방어구 뽑기");
	YELLOW;
	printf(" (100G)");
	WHITE;
	gotoxy(size->width/10, size->height*4/7);
	printf("3. 골드 뽑기");
	YELLOW;
	printf(" (100G)");
	gotoxy(size->width*2/3, size->height/3-2);
	printf("%d GOLD", status->GOLD);
	WHITE;

	return choice(size, 1, 10, 2, 7, select.w_min, select.w_max, select.h_min, select.h_max, where);
}

int main_select(struct window_size *size)
{
	struct wh_select select = {1,4,5,6};
	int buffer=1;
	FROM where = MAIN;
	gotoxy(0,size->height*3/5);

	while(buffer<=size->width/2)
	{
		BLUE;
		printf("◆");
		buffer++;
	}

	buffer=size->height*3/5;

	while(buffer<size->height)
	{
		gotoxy(size->width*5/7+2, buffer);
		printf("◆");
		gotoxy(size->width/7 ,buffer);
		printf("◆");
		buffer++;
	}

	WHITE;
	gotoxy(2,size->height*5/7);
	printf("나가기[ESC]");
	gotoxy(size->width/5 ,size->height*5/7);
	printf("1. 상태창 ");
	gotoxy(size->width*2/5 ,size->height*5/7);
	printf("2. 휴식처 ");
	gotoxy(size->width*3/5 ,size->height*5/7);
	printf("3. 인벤토리 ");
	gotoxy(size->width/5 ,size->height*6/7);
	printf("4. 던전 ");
	gotoxy(size->width*2/5 ,size->height*6/7);
	printf("5. 미니(리듬)게임 ");
	gotoxy(size->width*3/5 ,size->height*6/7);
	printf("6. 상점 ");

	gotoxy(size->width*4/5 ,size->height*5/7);
	printf("옵션[O]");
	gotoxy(size->width*4/5 ,size->height*6/7);
	printf("게임 정보[i]");

	return choice(size, 1, 5, 5, 7, select.w_min, select.w_max, select.h_min, select.h_max, where);
}

int help(struct window_size *size)
{
	WASD i=0; 
	GREEN;
	gotoxy(2,1);
	printf("i-------i 게임 정보 i-------i");
	WHITE;
	gotoxy(2, 3);
	printf("이 게임은 제작자가 친구의 아이디어가 재미있어서 만들기 시작한 게임 입니다.");
	gotoxy(2,4);
	printf("재밌게 플레이 해주세요.");
	gotoxy(3,size->height/3);
	printf("STR : 물리 공격력, 체력, 최대*최소 데미지에 영향을 미칩니다.");
	gotoxy(3,size->height/3+1);
	printf("DEX : 회피율, 체력, 치명타율에 영향을 미칩니다.");
	gotoxy(3,size->height/3+2);
	printf("INT : 스킬 공격력, 마나, 방어력에 영향을 미칩니다.");
	gotoxy(3,size->height/3+3);
	printf("LUCK : 게임에서의 모든 확률에 영향을 미칩니다.");
	gotoxy(3,size->height/3+4);
	printf("DO : 던전에서의 턴 수, 회복력에 영향을 미칩니다.");
	gotoxy(2, size->height-2);
	printf("[ESC] 나가기");
	while(1)
	{
		i=_getch();
		if(i==ESC) 
		{
			system("cls");
			return 0;
		}
	}
}
int random_color()
{
	int t = rand()%6;
	switch(t)
	{
	case 0:
		WHITE;
		break;
	case 1:
		RED;
		break;
	case 2:
		YELLOW;
		break;
	case 3:
		GREEN;
		break;
	case 4:
		BLUE;
		break;
	case 5:
		PURPLE;
		break;
	}
	return t;
}

void shop_title(void)
{
	char buffer[256]=" [랜덤 가챠 상점]";
	int i=0;
	gotoxy(0,1);
	while(1)
	{
			if(buffer[i] == ']')
			{
				WHITE;
				printf("%c",buffer[i]);
				break;
			}
			else if(buffer[i] == '[')
			{
				WHITE;
				printf("%c",buffer[i]);
				i++;
			}
			else
			{
				random_color();
				printf("%c",buffer[i]);
				i++;
			}
	}
}
void option_drow(struct window_size *size, int i, int j)
{
	int k=0;
	gotoxy(0,2);
	printf(" [Option] ");
	for(k=1; k<5; k++)
	{	
		WHITE;
		gotoxy(size->width/10, size->height*k/5);
		switch(k)
		{
		case 1:
			printf("창 크기 가로 : %d", size->width);
			break;

		case 2:
			printf("창 크기 세로 : %d", size->height);
			break;
		case 3:
			printf("3");
			break;
		case 4:
			printf("4");
			break;
		}
		BLUE;
		gotoxy(size->width/3, size->height*k/5);
		printf("▲  ▼");
	}

	WHITE;
	if(i==1)
	{
		gotoxy(size->width/3, size->height*j/5);
		printf("△");
		gotoxy(size->width/3, size->height*j/5);
	}
	else if(i==2)
	{
		gotoxy(size->width/3+4, size->height*j/5);
		printf("▽");
		gotoxy(size->width/3+4, size->height*j/5);
	}

	return;
}
void option(struct window_size *size)
{
	int i=1;
	int j=1;
	int temp=0;
	WASD wasd=0;
	
	option_drow(size,i,j);

	while(1)
	{
		char buffer[128]={0};
		wasd=_getch();
		BLUE;
		if(i==1)
		{
			gotoxy(size->width/3, size->height*j/5);
			printf("▲");
		}
		else if(i==2)
		{
			gotoxy(size->width/3+4, size->height*j/5);
			printf("▼");
		}
		WHITE;
		switch(wasd)
		{
		case 'A':
		case 'a':
		case LEFT:
			if(i>1)
				i--;
			break;
		case 'D':
		case 'd':
		case RIGHT:
			if(i<2)
				i++;
			break;
		case 'W':
		case 'w':
		case UP:
			if(j>1)
				j--;
			break;
		case 'S':
		case 's':
		case DOWN:
			if(j<4)
				j++;
			break;
		case SPACE:
			temp=i;
			switch(i)
			{
			case 1: //+
				switch(j)
				{
				case 1:
					if(size->width < GetSystemMetrics(SM_CXSCREEN))
					{
						size->width+=8;
						sprintf(buffer,"mode con: cols=%d lines=%d", size->width, size->height);
						system(buffer);
						option_drow(size,i,j);
					}
					break;
				case 2:
					if(size->height < GetSystemMetrics(SM_CYSCREEN))
					{
						size->height+=4;
						sprintf(buffer,"mode con: cols=%d lines=%d", size->width, size->height);
						system(buffer);
						option_drow(size,i,j);
					}
					break;
				case 3:
					break;
				case 4:
					break;
				}
				break;
			case 2: //-
				switch(j)
				{
				case 1:
					if(size->width>100)
					{
						size->width-=8;
						sprintf(buffer,"mode con: cols=%d lines=%d", size->width, size->height);
						system(buffer);
						option_drow(size,i,j);
					}
					break;
				case 2:
					if(size->height>26)
					{
						size->height-=4;
						sprintf(buffer,"mode con: cols=%d lines=%d", size->width, size->height);
						system(buffer);
						option_drow(size,i,j);
					}
					break;
				case 3:
					break;
				case 4:
					break;
				}
				break;
			}
			 break;
		case ESC:
			return;
		}
		switch(i)
		{
		case 1:
			gotoxy(size->width/3, size->height*j/5);
			printf("△");
			gotoxy(size->width/3, size->height*j/5);
			break;
		case 2:
			gotoxy(size->width/3+4, size->height*j/5);
			printf("▽");
			gotoxy(size->width/3+4, size->height*j/5);
			break;
		}
	}

}

int main_shop(struct window_size *size, struct STATE *status)
{
	WASD get=0;
	SELECT_SHOP buffer=0;
	int item=0;
		
	while(1)
	{
		if(kbhit()==0)
		{
			shop_title();
			_sleep(100);
		}
		get=shop_select(size, status);
		
		switch(get)
		{
		case ESC:
			system("cls");
			return 0;
		case 11: //무기 뽑기
			if(status->GOLD>=100)
			{
				status->GOLD-=100;
				item = rand()%3+5;
				switch(item)
				{
				case 5://sword
					item=item*10+rand()%5;
					break;
				case 6://fist
					break;
					item=item*10+rand()%7;
				case 7://hamer
					item=item*10+rand()%5;
					break;
				}
			}
			break;
		case 21: //방어구 뽑기
			if(status->GOLD>=100)
			{
				status->GOLD-=100;
				item=(rand()%6*10)+rand()%5;
			}
			break; 
		case 31: //골드 뽑기
			if(status->GOLD>=100)
			{
				status->GOLD-=100;
				buffer=rand()%200+status->LUCK;
				status->GOLD+=buffer;
				gotoxy(size->width*2/3, size->height/3);
				YELLOW;
				gotoxy(size->width*2/3, size->height/3);
				printf("             ");
				gotoxy(size->width*2/3, size->height/3);
				printf("+%d GOLD!",buffer);
				gotoxy(size->width*2/3, size->height/3-2);
				printf("             ");
				gotoxy(size->width*2/3, size->height/3-2);
				printf("%d GOLD", status->GOLD);
	
			}
			break;
		}
	}
}

int mini_game(struct window_size *size)
{
	PAD pad=0;
	WASD temp=0;
	char buffer[128]={0};
	int max_width=30;
	int max_height=16;
	int turn=1;
	int i=0;
	int j=0;
	int score=0;
	int pad_rail[4][14]={0};
	sprintf(buffer,"mode con: cols=%d lines=%d",max_width,max_height);
	system(buffer);
	gotoxy(2,1);
	printf("■■■");
	gotoxy(4,3);
	printf("■");
	gotoxy(22,1);
	printf("■■■");
	gotoxy(24,3);
	printf("■");
	gotoxy(12,5);
	printf("■");
	gotoxy(16,5);
	printf("■");

	while(temp < max_width-1)
	{
		gotoxy(temp,max_height-4);
		printf("■");
		gotoxy(temp,max_height-2);
		printf("■");
		temp++;
	}
	
	while(turn)
	{
		int tmp_x = 0;
		int tmp_y = 0;

		if(kbhit()==1)
		{
			temp=_getch();
			if(temp=='A' || temp=='a')
			{
				if(pad_rail[0][max_height-3-4]==BLOCK)
						score++;
					pad_rail[0][max_height-3-4]=0;
			}
			if(temp=='D' || temp=='d')
			{
				if(pad_rail[1][max_height-3-6]==BLOCK)
						score++;
					pad_rail[1][max_height-3-6]=0;
			}
			if(temp=='J' || temp=='j')
			{
				if(pad_rail[2][max_height-3-6]==BLOCK)
						score++;
					pad_rail[2][max_height-3-6]=0;
			}
			if(temp=='L' || temp=='l')
			{
				if(pad_rail[3][max_height-3-4]==BLOCK)
						score++;
					pad_rail[3][max_height-3-4]=0;
			}
			if(temp==ESC)
			{
				turn=0;
			}
		}
		if(kbhit()==0)
		{
			temp=rand()%4;
			pad_rail[temp][0] = BLOCK;

			gotoxy(0,0);
			BLUE;
			printf("SCORE : %d",score);

			for(i=0; i <= max_height; i++)
			{
				for(j=0; j<=3; j++)
				{
					switch (j)
					{
					case 0:
						tmp_x = 4;
						tmp_y = 4 + i;
						break;

					case 1:
						tmp_x = 12;
						tmp_y = 6 + i;
						break;

					case 2:
						tmp_x = 16;
						tmp_y = 6 + i;
						break;

					case 3:
						tmp_x = 24;
						tmp_y = 4 + i;
						break;
					}

					gotoxy(tmp_x, tmp_y);
					if(tmp_y >= max_height)
						continue;

					if(pad_rail[j][i]==BLOCK)
					{
						random_color();
						printf("▣");
						gotoxy(4,3);
						printf("■");
						gotoxy(24,3);
						printf("■");
					}
					else
						printf(tmp_y == max_height - 2 || tmp_y == max_height - 4 ? "■" : "  ");
				}
				_sleep(50);
			}
			for(i=0; i<13; i++)
			{
				for(j=0; j<=3; j++)
				{
					if(pad_rail[j][12 - i]==BLOCK)
					{
						pad_rail[j][12 - i]=0;
						pad_rail[j][13 - i]=BLOCK;
					}
				}
			
			}
		}


	}
	sprintf(buffer,"mode con: cols=%d lines=%d",size->width,size->height);
	system(buffer);
		return 0;
}

int stat(struct window_size *size, struct STATE *status)
{
	int i=0;
	int j=0;
	int temp=0;
	WASD wasd=0;
	status->HP=100+status->STR*5+status->DEX*10;
	status->MP=100+status->INT*12;
	system("cls");
	for(i=0; i < size->width; i+=2)
	{
		gotoxy(i,2);
		printf("◆");
		gotoxy(i,size->height-2);
		printf("◆");
	}
	WHITE;
	for(i=1; i<=6; i++)
	{
		gotoxy(size->width/6, size->height*i/7);
		switch(i)
		{
		case 1:
			printf("STR : %d",status->STR);
			gotoxy(size->width*3/4, size->height*i/7);
			YELLOW;
			printf("LEVEL %d",status->LEV);
			WHITE;
			break;
		case 2:
			printf("DEX : %d",status->DEX);
			gotoxy(size->width*3/4, size->height*i/7);
			GREEN;
			printf("HP : %d",status->HP);
			WHITE;
			break;
		case 3:
			printf("INT : %d",status->INT);
			gotoxy(size->width*3/4, size->height*i/7);
			BLUE;
			printf("MP : %d",status->MP);
			break;
		case 4:
			printf("LUCK : %d",status->LUCK);
			gotoxy(size->width*3/4, size->height*i/7);
			WHITE;
			printf("EXP %d",status->EXP);
			break;
		case 5:
			printf("DO : %d",status->DO);
			gotoxy(size->width/4, size->height-3);
			WHITE;
			printf("능력치에 대한 자세한 설명은 게임 정보를 이용해주세요.");
			break;
		case 6:
			printf("bonus point : %d",status->BONUS);
			gotoxy(size->width*3/4, size->height*i/7);
			YELLOW;
			printf("GOLD : %d",status->GOLD);
			break;
		}
		if(i==6)
			continue;
		else
		{
			BLUE;
			gotoxy(size->width/4+2, size->height*i/7);
			printf("▲");
			gotoxy(size->width/4+6, size->height*i/7);
			printf("▼");
			WHITE;
		}
	}

	i=1;
	j=1;

	gotoxy(size->width/4+2*i, size->height*j/7);
	printf("△");
	gotoxy(size->width/4+2*i, size->height*j/7);

	while(1)
	{
		
		wasd=_getch();
		BLUE;
		if(i==1)
			printf("▲");
		else if(i==2)
			printf("▼");
		WHITE;
		switch(wasd)
		{
		case 'A':
		case 'a':
		case LEFT:
			if(i>1)
				i--;
			break;
		case 'D':
		case 'd':
		case RIGHT:
			if(i<2)
				i++;
			break;
		case 'W':
		case 'w':
		case UP:
			if(j>1)
				j--;
			break;
		case 'S':
		case 's':
		case DOWN:
			if(j<5)
				j++;
			break;
		case SPACE:
			temp=i;
			switch(i)
			{
			case 1:
				switch(j)
				{
				case 1:
					if(status->BONUS>0)
					{
						status->BONUS--;
						status->STR++;
					}
					break;
				case 2:
					if(status->BONUS>0)
					{
						status->BONUS--;
						status->DEX++;
					}
					break;
				case 3:
					if(status->BONUS>0)
					{
						status->BONUS--;
						status->INT++;
					}
					break;
				case 4:
					if(status->BONUS>0)
					{
						status->BONUS--;
						status->LUCK++;
					}
					break;
				case 5:
					if(status->BONUS>0)
					{
						status->BONUS--;
						status->DO++;
					}
					break;
				}
				break;
			case 2:
				switch(j)
				{
				case 1:
					if(status->STR>0)
					{
						status->BONUS++;
						status->STR--;
					}
					break;
				case 2:
					if(status->DEX>0)
					{
						status->BONUS++;
						status->DEX--;
					}
					break;
				case 3:
					if(status->INT>0)
					{
						status->BONUS++;
						status->INT--;
					}
					break;
				case 4:
					if(status->LUCK>0)
					{
						status->BONUS++;
						status->LUCK--;
					}
					break;
				case 5:
					if(status->DO>0)
					{
						status->BONUS++;
						status->DO--;
					}
					break;
				}
				break;
			}
			for(i=1; i<=6; i++)
			{
				gotoxy(size->width/6, size->height*i/7);
				printf("          ");
				gotoxy(size->width/6, size->height*i/7);
				switch(i)
				{
				case 1:
					printf("STR : %d",status->STR);
					gotoxy(size->width*3/4, size->height*i/7);
					YELLOW;
					printf("LEVEL %d",status->LEV);
					WHITE;
					break;
				case 2:
					printf("DEX : %d",status->DEX);
					gotoxy(size->width*3/4, size->height*i/7);
					GREEN;
					status->HP=100+status->STR*5+status->DEX*10;
					printf("HP : %d",status->HP);
					WHITE;
					break;
				case 3:
					printf("INT : %d",status->INT);
					gotoxy(size->width*3/4, size->height*i/7);
					BLUE;
					status->MP=100+status->INT*12;
					printf("MP : %d",status->MP);
					WHITE;
					break;
				case 4:
					printf("LUCK : %d",status->LUCK);
					gotoxy(size->width*3/4, size->height*i/7);
					WHITE;
					printf("EXP %d",status->EXP);
					break;
				case 5:
					printf("DO : %d", status->DO);
					break;
				case 6:
					printf("                     ");
					gotoxy(size->width/6, size->height*i/7);
					printf("bonus point : %d",status->BONUS);
					gotoxy(size->width*3/4, size->height*i/7);
					YELLOW;
					printf("GOLD : %d",status->GOLD);
					break;
					}
			}
			i=temp;
			break;
		case ESC:
			return 0;
		}
		switch(i)
		{
		case 1:
			gotoxy(size->width/4+2, size->height*j/7);
			printf("△");
			gotoxy(size->width/4+2, size->height*j/7);
			break;
		case 2:
			gotoxy(size->width/4+6, size->height*j/7);
			printf("▽");
			gotoxy(size->width/4+6, size->height*j/7);
			break;
		}
	}

		
	BLUE;	
}

int game_map_create(struct window_size *size, MAP**map, int width, int height, struct PLAYER *player)
{
	int i=0;
	int j=0;

	for(i=0; i < width; i++)
	{
		for(j=0; j < height; j++)
		{
			map[j][i] = blank;
		}
	}

	for(i=0; i < width; i++) //width 2 line
	{
		map[0][i]=wall;//up
		map[height-1][i] = wall;//down
	}
	for(j=1; j < height; j++)//height 2 line
	{
		map[j][0] = wall; //left
		map[j][width-1] = wall; //right
	}
	/*for(i=0; i < height; i++)
	{
		if(i%2==1)
		{
			for(j=0; j < width-2; j+=2)
			{
				map[i][j]=wall;
			}
		}
		else
			for(j=2; j < width-1; j+=2)
			{
				map[i][j]=wall;
			}

	}*/


	player->player_x = 1;
	player->player_y = 1;
	map[player->player_y][player->player_x] = user;

	map[width-2][height-2] = item_star;
	return **map;
}

/*void game_map_patten(int width, int height, Map **map)
{
	int random=0;
	width-=1;
	height-=1;
	
	random = rand();
	return;
}*/

void game_map_print(struct window_size *size, MAP **map, int width, int height, struct PLAYER *player)
{
	int i=0;
	int j=0;
	int m_height = 3;

	WHITE;
	gotoxy(0, m_height + 1);

	for(j=0; j < height; j++)
	{
		for(i=0; i < width; i++)//조건식은 여기에 추가
		{
			if(map[j][i] == wall)
			{
				WHITE;
				printf("■");
			}
			else if(map[j][i] == user)
			{
				YELLOW;
				if(player->player_ang == up)
					printf("△");
				if(player->player_ang == left)
					printf("◁");
				if(player->player_ang == right)
					printf("▷");
				if(player->player_ang == down)
					printf("▽");
				if(player->player_ang == stay)
					printf("○");
			}
			else if(map[j][i] == blank)
				printf("  ");
			else if (map[j][i] == rolling_stone)
			{
				WHITE;
				printf("◎");
			}
			else if(map[j][i] == item_star)
			{
				YELLOW;
				printf("☆");
			}
		}
	}
	
	WHITE;
	for(i=0; i < size->width - 1; i+=2)
	{
		gotoxy(i , 0);
		printf("■");
	}
	for(i=0; i <= m_height; i++)
	{
		gotoxy(0, i);
		printf("■");
		gotoxy(size->width-2, i);
		printf("■");
	}

	return;
}

int user_next_check(MAP **map, struct PLAYER *player, WASD key)
{
	switch(key)
	{
	case UP:
		player->player_y-=1;

		if(map[player->player_y][player->player_x] == wall)
		{
			player->player_y += 1;
		}

		else if(map[player->player_y][player->player_x] == rolling_stone)
		{
			if(map[player->player_y - 1][player->player_x] == wall)
			{
				player->player_y += 1;
			}
			else
				map[player->player_y-1][player->player_x] = rolling_stone;
		}

		else if(map[player->player_y][player->player_x] == item_star)
		{
			WHITE;
			gotoxy(4,2);
			printf_item(random_item_star());
			printf(" 획득!");
		}
		break;
		
	case DOWN:
		player->player_y+=1;

		if(map[player->player_y][player->player_x] == wall)
		{
			player->player_y -= 1;
		}

		else if(map[player->player_y][player->player_x] == rolling_stone)
		{
			if(map[player->player_y + 1][player->player_x] == wall)
			{
				player->player_y -= 1;
			}
			else
				map[player->player_y+1][player->player_x] = rolling_stone;
		}

		else if(map[player->player_y][player->player_x] == item_star)
		{
			WHITE;
			gotoxy(4,2);
			printf_item(random_item_star());
			printf(" 획득!");
		}
		break;

	case LEFT:
		player->player_x-=1;

		if(map[player->player_y][player->player_x] == wall)
		{
			player->player_x += 1;
		}

		else if(map[player->player_y][player->player_x] == rolling_stone)
		{
			if(map[player->player_y][player->player_x - 1] == wall)
			{
				player->player_x += 1;
			}
			else
				map[player->player_y][player->player_x - 1] = rolling_stone;
		}

		else if(map[player->player_y][player->player_x] == item_star)
		{
			WHITE;
			gotoxy(4,2);
			printf_item(random_item_star());
			printf(" 획득!");
		}
		break;

	case RIGHT:
		player->player_x+=1;

		if(map[player->player_y][player->player_x] == wall)
		{
			player->player_x -= 1;
		}

		else if(map[player->player_y][player->player_x] == rolling_stone)
		{
			if(map[player->player_y][player->player_x + 1] == wall)
			{
				player->player_x -= 1;
			}
			else
				map[player->player_y][player->player_x + 1] = rolling_stone;
		}

		else if(map[player->player_y][player->player_x] == item_star)
		{
			WHITE;
			gotoxy(4,2);
			printf_item(random_item_star());
			printf(" 획득!");
		}
		break;
	}

	return **map;
}

int game_control(struct window_size *size, MAP **map, int width, int height, struct PLAYER *player, WASD key)
{
	map[player->player_y][player->player_x] = blank;

	switch(key)
	{
	case UP:
		player->player_ang = up;
		**map = user_next_check(map, player, key);
		break;

	case DOWN:
		player->player_ang = down; 
		**map = user_next_check(map, player, key);
		break;

	case LEFT:
		player->player_ang = left;
		**map = user_next_check(map, player, key);
		break;

	case RIGHT:
		player->player_ang = right;
		**map = user_next_check(map, player, key);
		break;

	case 'R':
	case 'r':
		**map = game_map_create(size, map, width, height, player);
		player->player_ang = stay;
		break;
	}

	map[player->player_y][player->player_x] = user;

	return **map;
}

void main_game(struct window_size *size, struct STATE *status)
{
	const int width = size->width/2;
	const int height = size->height - 4;
	struct PLAYER player = {stay};
	int i=0; //width
	int j=0; //height
	WASD key=0;

	MAP **map = malloc(sizeof(int *) * height);
	int **print_map = malloc(sizeof(int) * height);

	for(i=0; i < height; i++)
	{
		map[i] = malloc(sizeof(int) * width);
		print_map[i] = malloc(sizeof(int) * width);
	}

	**map = game_map_create(size, map, width, height, &player);

	while(key != ESC)
	{
		game_map_print(size, map, width, height, &player);
		key=_getch();
		**map = game_control(size, map, width, height, &player, key);
	}
			for(i=0; i < height; i++)
			{
				free(map[i]);
				free(print_map[i]);
			}
			free(map);
			free(print_map);
			system("cls");
			return;
}

void main_home(struct window_size *size)
{
	struct STATE status = {100, 100, 10, 10, 10, 10, 5, 10, 1, 0, 100};
	int loop = 1;

	while(loop)
	{
 		SELECT pointed = main_select(size);
		system("cls");

		switch(pointed)
		{
		case SELECT1: //상태창
			stat(size, &status);
			system("cls");
			break;
		case SELECT2: //휴식처
			break;
		case SELECT3: //인벤토리
			break;
		case SELECT4: //던전
			main_game(size, &status);
			break;
		case SELECT5: //미니(리듬)게임
			mini_game(size);
			break;
		case SELECT6: //가챠상점
			main_shop(size, &status);
			break;
		case Option: //옵션
			option(size);
			system("cls");
			continue;
		case Gameinfo: //게임 설명
			help(size);
			break;
		case ESC:
			loop = 0;
			break;
		}
	}
}


void main(void)
{
	int i=0;
	int j=0;
	char buffer[128]={0};
	struct window_size size = {100,30};
	char loading[128] = "Loading";
	system("cls");
	CursorView(0);
	srand(time(NULL));

	WHITE;
	sprintf(buffer,"mode con: cols=%d lines=%d",size.width*2/3 ,size.height/2);
	system(buffer);
	printf("\n\n\n 그럼 이제 게임을 시작하겠습니다. \n");
	YELLOW;

	for(i=0; i<2; i++)
	{
		for(j=1; j<=3; j++)
		{
			sprintf(loading, "%s .",loading);
			gotoxy(0,5);
			printf("                    ");
			gotoxy(0,5);
			printf("  %s",loading);
			_sleep(400);
			if(j==3)
			{
				sprintf(loading, "Loading");
				
			}
		}
	}
	/*RED;
	sprintf(buffer,"Do you want a play game?");
	for(i=0; i<25; i++)
	{
		gotoxy(2, 5);
		for(j=0; j<=i; j++)
			printf("%c",buffer[j]);
		_sleep(300);
	}*/

	WHITE;
	system("cls");
	system("color 7F");
	_sleep(50);
	sprintf(buffer, "mode con: cols=%d lines=%d", size.width, size.height);
	system(buffer);
	_sleep(50);
	system("color 07");
	
	main_home(&size);
}
 
