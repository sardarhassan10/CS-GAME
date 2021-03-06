#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<stdbool.h>
#include<conio.h>
#include<MMSystem.h>
#define ROW 23
#define COLOUM 17
#define R 1
#define C 3

void startmessage(void);
void intialisearray(char a[][COLOUM]);
void print(char a[][COLOUM]);
void left(char a[][COLOUM]);
void right(char a[][COLOUM]);
void obstacleleft(char a[][COLOUM]);
void obstaclecenter(char a[][COLOUM]);
void obstacleright(char a[][COLOUM]);
void detectcrash(char a[][COLOUM]);
void highscoreentry(void);
void tcr(void);
void sc(void);
void bc(void);
void continuegame(void);
void playcrash();
void gamemusic(void);


char a[ROW][COLOUM] = {
	"   ",
	"   ",
	"   ",
	"   ",
};
int highscore[R][C] = { { 0, 0, 0 } };
int shift = 0, positionl = 0, positionc = 0, positionr = 0, score = 0, xl = 0, xc = 0, xr = 0, level = 1, lives = 3, blocks = 0, msec = 0;
int randoml = 2, randomc = 18, randomr = 7, check = 0;
int moviechoice;
char continued = 'y';
clock_t start, end, difference;
bool crash = FALSE;
bool lifesubtracted = FALSE;
bool songplayed = FALSE;
bool safe = FALSE;

main()
{

	startmessage();
	
	do
	{
		system("clr");
		intialisearray(a);
		print(a);
		while (lives != 0)
		{
			sc();

			if (_kbhit())
			{
				switch (_getch())
				{
				case 'a':
					left(a);
					Beep(1000, 50);
					break;
				case 'd':
					right(a);
					Beep(1000, 50);
					break;
				case 'n':
					if ((moviechoice == 1) || (moviechoice == 2))
					{
						songplayed = FALSE;
						start = clock();
					}
					else
					{
						songplayed = FALSE;
						start = clock();
					}
					break;
				default:
					break;
				}


			}

			detectcrash(a);
			bc();
			system("cls");
			print(a);
			gamemusic();
			tcr();
			printf("Your score is: %d \t Level: %d \t Lives Remaining:%d", score, level, lives);


		}
		puts("");
		highscoreentry();
		score = 0;
		puts("");
		continuegame();
	} while (continued == 'y');
	puts("");
	system("pause");
}

void intialisearray(char a[][COLOUM])
{


	int i = 0, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COLOUM; j++)
		{
			a[i][j] = ' ';
		}
	}


	a[ROW - 6][2] = 'o';
	a[ROW - 6][3] = ' ';
	a[ROW - 6][4] = ' ';
	a[ROW - 6][5] = 'o';

	a[ROW - 5][2] = ' ';
	a[ROW - 5][3] = '#';
	a[ROW - 5][4] = '#';
	a[ROW - 5][5] = ' ';

	a[ROW - 4][2] = ' ';
	a[ROW - 4][3] = '#';
	a[ROW - 4][4] = '#';
	a[ROW - 4][5] = ' ';

	a[ROW - 3][2] = 'o';
	a[ROW - 3][3] = ' ';
	a[ROW - 3][4] = ' ';
	a[ROW - 3][5] = 'o';

	for (int count1 = 0; count1<ROW; count1++)
	{
		a[count1][6] = '|';
		a[count1][11] = '|';

	}
	for (i = 0; i<ROW; i++)
	{
		for (j = 1; j < COLOUM; j++)
		{
			if (i == 0)
			{
				a[0][j] = 'x';
				/*a[1][j] = 'x';*/
			}
			else if (i == ROW - 1)
			{
				a[ROW - 1][j] = 'x';
				/*a[ROW - 2][j] = 'x';*/
			}
			else
			{
				a[i][1] = 'x';
				a[i][COLOUM - 1] = 'x';
				/*a[i][1] = 'x';
				a[i][COLOUM - 2] = 'x';*/
			}


		}

	}

}

void print(char a[][COLOUM])
{
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COLOUM; j++)
		{
			printf("%c", a[i][j]);
		}
		puts("");

	}
}

void left(char a[][COLOUM])
{
	if (shift > 0)
	{
		for (int i = 17; i < ROW; i++)
		{
			for (int j = 0; j < COLOUM; j++)
			{
				a[i][j] = ' ';
			}
		}
		for (int count1 = 0; count1<ROW; count1++)
		{
			a[count1][6] = '|';
			a[count1][11] = '|';

		}
		for (int i = 0; i<ROW; i++)
		{
			for (int j = 1; j < COLOUM; j++)
			{
				if (i == 0)
				{
					a[0][j] = 'x';
					/*a[1][j] = 'x';*/
				}
				else if (i == ROW - 1)
				{
					a[ROW - 1][j] = 'x';
					/*a[ROW - 2][j] = 'x';*/
				}
				else
				{
					a[i][1] = 'x';
					a[i][COLOUM - 1] = 'x';
					/*a[i][1] = 'x';
					a[i][COLOUM - 2] = 'x';*/
				}


			}

		}


		if (shift == 1)
		{


			a[ROW - 6][2] = 'o';
			a[ROW - 6][3] = ' ';
			a[ROW - 6][4] = ' ';
			a[ROW - 6][5] = 'o';

			a[ROW - 5][2] = ' ';
			a[ROW - 5][3] = '#';
			a[ROW - 5][4] = '#';
			a[ROW - 5][5] = ' ';

			a[ROW - 4][2] = ' ';
			a[ROW - 4][3] = '#';
			a[ROW - 4][4] = '#';
			a[ROW - 4][5] = ' ';

			a[ROW - 3][2] = 'o';
			a[ROW - 3][3] = ' ';
			a[ROW - 3][4] = ' ';
			a[ROW - 3][5] = 'o';

			shift = 0;

		}
		else if (shift == 2)
		{


			a[ROW - 6][7] = 'o';
			a[ROW - 6][8] = ' ';
			a[ROW - 6][9] = ' ';
			a[ROW - 6][10] = 'o';

			a[ROW - 5][7] = ' ';
			a[ROW - 5][8] = '#';
			a[ROW - 5][9] = '#';
			a[ROW - 5][10] = ' ';

			a[ROW - 4][7] = ' ';
			a[ROW - 4][8] = '#';
			a[ROW - 4][9] = '#';
			a[ROW - 4][10] = ' ';

			a[ROW - 3][7] = 'o';
			a[ROW - 3][8] = ' ';
			a[ROW - 3][9] = ' ';
			a[ROW - 3][10] = 'o';

			shift = 1;
		}

	}




}
void right(char a[][COLOUM])
{
	if (shift < 2)
	{
		for (int i = 17; i < ROW; i++)
		{
			for (int j = 0; j < COLOUM; j++)
			{
				a[i][j] = ' ';
			}

		}
		for (int count1 = 0; count1<ROW; count1++)
		{
			a[count1][6] = '|';
			a[count1][11] = '|';

		}
		for (int i = 0; i<ROW; i++)
		{
			for (int j = 1; j < COLOUM; j++)
			{
				if (i == 0)
				{
					a[0][j] = 'x';
					/*a[1][j] = 'x';*/
				}
				else if (i == ROW - 1)
				{
					a[ROW - 1][j] = 'x';
					/*a[ROW - 2][j] = 'x';*/
				}
				else
				{
					a[i][1] = 'x';
					a[i][COLOUM - 1] = 'x';
					/*a[i][1] = 'x';
					a[i][COLOUM - 2] = 'x';*/
				}


			}

		}
		if (shift == 0)
		{
			a[ROW - 6][7] = 'o';
			a[ROW - 6][8] = ' ';
			a[ROW - 6][9] = ' ';
			a[ROW - 6][10] = 'o';

			a[ROW - 5][7] = ' ';
			a[ROW - 5][8] = '#';
			a[ROW - 5][9] = '#';
			a[ROW - 5][10] = ' ';

			a[ROW - 4][7] = ' ';
			a[ROW - 4][8] = '#';
			a[ROW - 4][9] = '#';
			a[ROW - 4][10] = ' ';

			a[ROW - 3][7] = 'o';
			a[ROW - 3][8] = ' ';
			a[ROW - 3][9] = ' ';
			a[ROW - 3][10] = 'o';

			shift = 1;
		}

		else if (shift == 1)
		{


			a[ROW - 6][12] = 'o';
			a[ROW - 6][13] = ' ';
			a[ROW - 6][14] = ' ';
			a[ROW - 6][15] = 'o';

			a[ROW - 5][12] = ' ';
			a[ROW - 5][13] = '#';
			a[ROW - 5][14] = '#';
			a[ROW - 5][15] = ' ';

			a[ROW - 4][12] = ' ';
			a[ROW - 4][13] = '#';
			a[ROW - 4][14] = '#';
			a[ROW - 4][15] = ' ';

			a[ROW - 3][12] = 'o';
			a[ROW - 3][13] = ' ';
			a[ROW - 3][14] = ' ';
			a[ROW - 3][15] = 'o';

			shift = 2;

		}
	}
}

void obstacleleft(char a[][COLOUM])
{



	if (positionl <= 20)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 2; j < 6; j++)
			{
				a[i + positionl][j] = ' ';
			}
		}

		if (positionl >= 1)
		{
			for (int j = 2; j < 6; j++)
			{
				a[0][j] = 'x';
			}
		}


		positionl++;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 2; j < 6; j++)
			{
				a[i + positionl][j] = '#';
			}
		}
	}
	if ((shift == 0) && (a[ROW - 3][2] != 'o'))
	{
		crash = TRUE;

	}

	if ((shift == 0) && (a[ROW - 6][2] != 'o'))
	{
		crash = TRUE;

		a[ROW - 3][2] = 'o';
		a[ROW - 3][5] = 'o';
	}




	if ((positionl == ROW - 4) && (crash == FALSE))
	{
		for (int j = 2; j < 6; j++)
		{
			a[positionl][j] = ' ';
			a[positionl + 1][j] = ' ';
			a[positionl + 2][j] = ' ';
			a[ROW - 1][j] = 'x';
			/*a[ROW - 2][j] = ' ';
			a[ROW - 3][j] = ' ';*/
		}

	}
	xl++;
	if ((xl <= 6) && (xc<=1))
		safe = FALSE;
	else
		safe = TRUE;

	if ((xl == 19) && (crash == FALSE))
	{
		xl = 0;
		score++;
		positionl = 0;
		blocks--;
	}



}
void obstaclecenter(char a[][COLOUM])
{


	if (positionc <= 20)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 7; j < 11; j++)
			{
				a[i + positionc][j] = ' ';
			}
		}


		if (positionc >= 1)
		{
			for (int j = 7; j < 11; j++)
			{
				a[0][j] = 'x';
			}
		}


		positionc++;


		for (int i = 0; i < 3; i++)
		{
			for (int j = 7; j < 11; j++)
			{
				a[i + positionc][j] = '#';
			}
		}
	}


	if ((shift == 1) && (a[ROW - 3][7] != 'o'))
	{
		crash = TRUE;

	}
	if ((shift == 1) && (a[ROW - 6][7] != 'o'))
	{
		crash = TRUE;

		a[ROW - 3][7] = 'o';
		a[ROW - 3][10] = 'o';
	}




	if ((positionc == ROW - 4) && (crash == FALSE))
	{
		for (int j = 7; j < 11; j++)
		{
			a[positionc][j] = ' ';
			a[positionc + 1][j] = ' ';
			a[positionc + 2][j] = ' ';
			a[ROW - 1][j] = 'x';
			/*a[ROW - 2][j] = ' ';
			a[ROW - 3][j] = ' ';*/
		}

	}
	xc++;
	if ((xc == 19) && (crash == FALSE))
	{

		xc = 0;
		score++;
		positionc = 0;
		blocks--;
	}


}
void obstacleright(char a[][COLOUM])
{




	if (positionr <= 20)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 12; j < 16; j++)
			{
				a[i + positionr][j] = ' ';
			}
		}


		if (positionr >= 1)
		{
			for (int j = 12; j < 16; j++)
			{
				a[0][j] = 'x';
			}
		}


		positionr++;


		for (int i = 0; i < 3; i++)
		{
			for (int j = 12; j < 16; j++)
			{
				a[i + positionr][j] = '#';
			}
		}
	}



	if ((shift == 2) && (a[ROW - 6][12] != 'o'))
	{
		crash = TRUE;

		a[ROW - 3][12] = 'o';
		a[ROW - 3][15] = 'o';
	}
	if ((shift == 2) && (a[ROW - 3][12] != 'o'))
	{
		crash = TRUE;

	}

	if ((positionr == ROW - 4) && (crash == FALSE))
	{
		for (int j = 12; j < 16; j++)
		{
			a[positionr][j] = ' ';
			a[positionr + 1][j] = ' ';
			a[positionr + 2][j] = ' ';
			a[ROW - 1][j] = 'x';
			/*a[ROW - 2][j] = ' ';
			a[ROW - 3][j] = ' ';*/
		}

	}

	xr++;

	if ((xr == 19) && (crash == FALSE))
	{
		xr = 0;
		score++;
		positionr = 0;
		blocks--;
	}
}


void detectcrash(char a[][COLOUM])
{

	if (a[ROW - 7][2] == '#')
	{
		if (a[ROW - 6][2] == 'o')
		{
			crash = TRUE;

		}


	}


	else if ((a[ROW - 6][2] == '#') && (a[ROW - 3][2] == 'o'))
	{
		crash = TRUE;
		if (lifesubtracted == FALSE);


	}

	else if ((a[ROW - 7][2] == '#') && (a[ROW - 3][2] == 'o'))
	{
		crash = TRUE;

	}

	else if ((a[ROW - 4][2] == '#') && (a[ROW - 3][2] == 'o'))
	{
		crash = TRUE;

	}




	if (a[ROW - 7][7] == '#')
	{
		if (a[ROW - 6][7] == 'o')
		{
			crash = TRUE;

		}
	}
	else if ((a[ROW - 7][7] == '#') && (a[ROW - 3][7] == 'o'))
	{
		crash = TRUE;


	}

	else if ((a[ROW - 4][7] == '#') && (a[ROW - 3][7] == 'o'))
	{
		crash = TRUE;

	}
	else if ((a[ROW - 6][7] == '#') && (a[ROW - 3][7] == 'o'))
	{
		crash = TRUE;

	}




	if (a[ROW - 7][12] == '#')
	{
		if (a[ROW - 6][12] == 'o')
		{
			crash = TRUE;

		}


	}
	else if ((a[ROW - 6][12] == '#') && (a[ROW - 3][12] == 'o'))
	{
		crash = TRUE;

	}
	else if ((a[ROW - 7][12] == '#') && (a[ROW - 3][12] == 'o'))
	{
		crash = TRUE;

	}

	else if ((a[ROW - 4][12] == '#') && (a[ROW - 3][12] == 'o'))
	{
		crash = TRUE;
	}

}

void highscoreentry(void)
{
	if (score>highscore[0][0])
		highscore[0][0] = score;
	else if (score>highscore[0][1])
		highscore[0][1] = score;
	else if (score>highscore[0][2])
		highscore[0][2] = score;


	printf("High scores are: \n");
	for (int j = 0; j < 3; j++)
	{
		printf("%d\n", highscore[0][j]);

	}
}

void tcr(void)
{
	if (crash == TRUE)
	{
		playcrash();
		Sleep(12000);
		intialisearray(a);
		xl = 0;
		xc = 0;
		xr = 0;
		positionl = 0;
		positionc = 0;
		positionr = 0;
		crash = FALSE;
		shift = 0;
		blocks = 0;
		lifesubtracted = FALSE;
		lives--;
		start = clock();
		songplayed = FALSE;

	}




}

void sc(void)
{
	if (score < 5)
	{
		Sleep(200);
	}

	else if ((score >= 5) && (score < 12))
	{
		Sleep(100);
		level = 2;
	}
	else
	{
		Sleep(50);
		level = 3;
	}

}

void bc(void)
{

	if (blocks < 2)
	{
		if ((xl == 0) && (blocks<2))
		{
			srand(time(NULL));
			randoml = (rand() % 50 + 11);
			if (randoml % 3 == 0)
			{
				blocks++;

			}
		}
		if ((xc == 0) && (blocks < 2))
		{
			srand(time(NULL));
			randomc = (rand() % 100 + 1);
			
			
				if (randomc % 2 == 0)
				{
					blocks++;

				}
			
		}
		if ((xr == 0) && (blocks<2))
		{
			srand(time(NULL));
			randomr = (rand() % 50 + 1);
			if (randomr % 7 == 0)
			{
				blocks++;

			}
		}


	}

	if (randoml % 3 == 0)
	{
		if (blocks <= 2)
		{
			obstacleleft(a);

		}
	}

	if (randomc % 2 == 0)
	{
		if ((blocks <= 2) && (safe==TRUE))
		{
			obstaclecenter(a);

		}
	}
	if (randomr % 7 == 0)
	{
		if (blocks <= 2)
		{
			obstacleright(a);

		}
	}



}

void continuegame(void)
{
	printf("Enter 'y' to play again\nEnter 'n' to exit\n");
	fflush(stdin);
	scanf_s("%c", &continued);
	while ((continued != 'n') && (continued != 'y'))

	{
		printf("please enter your choice again\n");
		fflush(stdin);
		scanf_s("%c", &continued);
	}
	if (continued == 'y')
	{

		xl = 0;
		xc = 0;
		xr = 0;
		positionl = 0;
		positionc = 0;
		positionr = 0;
		crash = FALSE;
		shift = 0;
		blocks = 0;
		lifesubtracted = FALSE;
		lives = 3;
		start = clock();
		songplayed = FALSE;
	}

}

void playcrash()
{
	PlaySound(TEXT("channamereya.wav"), NULL, SND_SYNC | SND_ASYNC);
	songplayed = FALSE;

}
void gamemusic()
{
	end = clock();
	difference = end - start;
	msec = difference * 1000 / CLOCKS_PER_SEC;
	if (msec >= 225000)
	{
		songplayed = FALSE;
		start = clock();
	}


	if (songplayed == FALSE)
	{
		songplayed = TRUE;
		if (moviechoice == 1)
		{
			PlaySound(TEXT("letitgo.wav"), NULL, SND_SYNC | SND_ASYNC);
			moviechoice = 2;

		}
		else if (moviechoice == 2)
		{
			PlaySound(TEXT("atlastisee.wav"), NULL, SND_SYNC | SND_ASYNC);
			moviechoice = 3;
		}
		else if (moviechoice == 3)
		{
			PlaySound(TEXT("forthefirsttimeinforever.wav"), NULL, SND_SYNC | SND_ASYNC);
			moviechoice++;
		}
		else if (moviechoice == 4)
		{
			moviechoice = 1;
			songplayed = FALSE;
		}
	}

}
void startmessage()
{
	printf("Before we introduce you to the GREATESET game ever in like the history of ever,\nwe need to ask you something VERY VERY VERT IMPORTANT:\nFROZEN or TANGLED\nEnter '1' for Frozen and '2' for Tangled\n");
	fflush(stdin);
	scanf_s("%d", &moviechoice);
	while ((moviechoice != 1) && (moviechoice != 2))
	{
		printf("Enter again\n");
		fflush(stdin);
		scanf_s("%d", &moviechoice);

	}
	system("cls");


	printf("Press 'a' to move left & 'd' to move right.\nYou have 3 live.\nGame will begin in 4 seconds.\nPress 'n' to change the song.\nRemember if you crash, the song changes. \nGOOD LUCK!");
	Sleep(4000);
	system("clr");
	clock_t start = clock();
}
