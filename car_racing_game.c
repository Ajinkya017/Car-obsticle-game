//Importing Libraries

#include<conio.h> 
#include<process.h> 
#include<stdio.h> 
#include<dos.h> 
#include<stdlib.h> 
#include<fstream.h> 
#include<graphics.h> 
#define LEFT 75 
#define RIGHT 77 
#define UP 72 
#define DOWN 80 
#define ENTER 13 

//Car Class
class CAR 
{ 
    public: 
	int vel, cp, init, op1, op2, op3, level; 
	long score; 
	long lev_score[ 5 ]; 
	char player[ 20 ]; 
	CAR::CAR() 
	{ 
	    level = 1; 
	    vel = 1; 
	    cp = 300; 
	    init = 0; 
	    op1 = 0; 
	    op2 = -20; 
	    op3 = -40; 
	    score = 0; 
	    lev_score[ 0 ] = 10000; 
	    lev_score[ 1 ] = 30000; 
	    lev_score[ 2 ] = 60000; 
	    lev_score[ 3 ] = 100000; 
	    lev_score[ 4 ] = 150000; 
	} 
} 
car; 
int randx( void ) 
{ 
    int x = random( 56 * 8 ); 
    if ( x < 22 * 8 ) 
    { 
	x = x + ( 22 * 8 ); 
    } 
    return ( x ); 
} 
void right() 
{ 
    if ( car.cp < 420 ) 
    { 
	car.cp += 10; 
    } 
    return ; 
} 
void left() 
{ 
    if ( car.cp > 180 ) 
    { 
	car.cp -= 10; 
    } 
    return ; 
} 
void score_store() 
{ 
    cleardevice(); 
    setcolor( 4 ); 
    settextstyle( 2, 0, 6 ); 
    outtextxy( 10, 0, "Your score is" ); 
    gotoxy( 20, 2 ); 
    cout << car.score; 
    outtextxy( 10, 40, "Enter your name to store :" ); 
    gotoxy( 35, 4 ); 
    gets( car.player ); 
    ofstream score; 
    score.open( "score.dat", ios::app ); 
    score << "\n"; 
    score.write( car.player, 20 ); 
    score << car.score; 
    score.close(); 
} 
void disp_score() 
{ 
    cleardevice(); 
    setcolor( 5 ); 
    settextstyle( 2, 0, 9 ); 
    outtextxy( 200, 20, "SCORE BOARD" ); 
    ifstream score( "score.dat" ); 
    char ch; 
    int i = 0; 
    gotoxy( 1, 5 ); 
    while ( score.get( ch ) ) 
    { 
	score.seekg( i, ios::beg ); 
	score.get( ch ); 
	cout << ch; 
	i++; 
    } 
    getch(); 
    return ; 
} 
void bgmove() 
{ 
    if ( car.init > 5 ) 
    { 
	car.init = 1; 
    } 
    else 
    { 
	car.init += car.vel; 
    } 
    setcolor( RED ); 
    setfillstyle( SOLID_FILL, RED ); 
    sector( car.cp + 20, 330, 0, 180, 20, 30 ); 
    setfillstyle( SOLID_FILL, YELLOW ); 
    bar3d( car.cp, 333, car.cp + 37, 360, 4, 4 ); 
    sector( car.cp + 20, 362, 180, 360, 20, 10 ); 
    for ( int i = car.init;i < 70;i += 5 ) 
    { 
	setcolor( GREEN ); 
	setfillstyle( 9, GREEN ); 
	bar( 16 * 8, i * 8, 20 * 8, ( i + 2 ) * 8 ); 
	bar( 60 * 8, i * 8, 64 * 8, ( i + 2 ) * 8 ); 
    } 
    return ; 
} 
void opp1( int x1 ) 
{ 
    if ( car.op1 < 600 ) 
    { 
	car.op1 += 10; 
	setfillstyle( 1, RED ); 
	bar3d( x1, car.op1, x1 + 30, car.op1 + 30, 2, 3 ); 
    } 
    else 
    { 
	car.op1 = 0; 
    } 
    return ; 
} 
void opp2( int x2 ) 
{ 
    if ( car.op2 < 600 ) 
    { 
	car.op2 += 10; 
	setfillstyle( 1, YELLOW ); 
	bar3d( x2, car.op2, x2 + 30, car.op2 + 30, 2, 3 ); 
    } 
    else 
    { 
	car.op2 = 0; 
    } 
    return ; 
} 
void opp3( int x3 ) 
{ 
    if ( car.op3 < 600 ) 
    { 
	car.op3 += 10; 
	setfillstyle( 1, BLUE ); 
	bar3d( x3, car.op3, x3 + 30, car.op3 + 30, 2, 3 ); 
    } 
    else 
    { 
	car.op3 = 0; 
    } 
    return ; 
} 
int check( int x, int op, int cp ) 
{ 
    int a[ 31 ], b[ 31 ], c[ 40 ], d[ 50 ]; 
    for ( int i = 0;i < 30;i++ ) 
    { 
	a[ i ] = x + i; 
    } 
    for ( i = 0;i < 30;i++ ) 
    { 
	b[ i ] = op + i; 
    } 
    for ( i = 0;i < 40;i++ ) 
    { 
	c[ i ] = cp + i; 
    } 
 
    for ( i = 0;i < 50;i++ ) 
    { 
	d[ i ] = 300 + i; 
    } 
    for ( i = 0;i < 40;i++ ) 
    { 
	for ( int j = 0;j < 50;j++ ) 
	{ 
	    for ( int k = 0;k < 30;k++ ) 
	    { 
		if ( a[ k ] == c[ i ] && b[ k ] == d[ j ] ) 
		    return 1; 
	    } 
	} 
    } 
    return 0; 
} void main()
 {
  int driver,mode;
  driver = DETECT;
  initgraph(&driver,&mode,"\\tc\\bgi");
  int x=300,y=350,ch,life=3,score=0;
  char choice;
  cout<<"\n\n\n\n\n\t\t\t* ADVENTURE PURSUIT RACING *";
  cout<<"\n\t\t\t ---------------";
  cout<<"\n\n\tLong long ago the state of alfheim was attacked by the";
  cout<<"\n\n\tenemies and were defeated. Every soldier and citizen was";
  cout<<"\n\n\tkilled except the beautiful princess snow and you";
  cout<<"\n\n\twho survived. Enemies want to kill her and she is in your";
  cout<<"\n\n\tcar right now. If you have the guts save her from enemies'";
  cout<<"\n\n\tcars and marry her.";
  cout<<"\n\n\tSo all the best...";
  delay(20000);
  for(int m=1;m<25;m++)
	for(int n=1;n<80;n++) {
		gotoxy(n,m);
		cout<<" ";
		} 





void logo () 
{ 
    for ( int i = 1;i < 250;i++ ) 
    { 
	int p; 
	setcolor( YELLOW ); 
	setfillstyle( SOLID_FILL, LIGHTBLUE ); 
	settextstyle( 4, HORIZ_DIR, 5 ); 
	outtextxy( 100, 100, "ADVENTURE PURSUIT" ); 
	outtextxy( 200, 140, "RACING" ); 
	setcolor( 4 ); 
	bar3d( 50, 200, 550, 220, 10, 40 ); 
	setcolor( WHITE ); 
	settextstyle( 2, HORIZ_DIR, 5 ); 
	setfillstyle( SOLID_FILL, GREEN ); 
	bar( 190, 400, 190 + i, 420 ); 
	rectangle( 190, 400, 440, 420 ); 
	delay( 15 ); 
    } 
    delay( 10000 ); 
    cleardevice(); 
    return ; 
} 
 
void loss( void ) 
{ 
    setcolor( 10 ); 
    settextstyle( 2, 0, 9 ); 
    outtextxy( 180, 150, "ONE CHANCE LOST" ); 
    delay( 1000 ); 
    return ; 
} 
void over( void ) 
{ 
    for ( int i = 1;i < 35;i++ ) 
    { 
	cleardevice();delay( 20 ); 
	settextstyle( 1, 0, 6 ); 
	setcolor( RED ); 
	outtextxy( 150, 100, "GAME OVER" ); 
	delay( 20 ); 
    } 
    delay( 2000 ); 
    cleardevice(); 
    score_store(); 
    getch(); 
    return ; 
} 
void score() 
{ 
    car.score = car.score + 11 * car.vel; 
    setcolor( 5 ); 
    settextstyle( 2, 0, 6 ); 
    outtextxy( 530, 12, "Score " ); 
    gotoxy( 75, 2 ); 
    cout << car.score; 
    return ; 
} 
void win() 
{ 
    cleardevice(); 
    for ( int k = 0;k < 2;k++ ) 
    { 
	for ( int i = 0;i < 15;i++ ) 
	{ 
	    setcolor( i ); 
	    settextstyle( 4, 0, 5 ); 
	    outtextxy( 200, 100, "Congrats!!" ); 
	    setcolor( i + 1 ); 
	    outtextxy( 150, 200, "You won the race" ); 
	    delay( 150 ); 
	} 
    } 
    delay( 3000 ); 
    score_store(); 
    return ; 
} 
void level( void ) 
{ 
    int level = car.level; 
    if ( car.score > car.lev_score[ level - 1 ] ) 
    { 
	if ( car.level < 5 ) 
	{ 
	    car.level++; 
	    if ( car.vel < 4 ) 
	    { 
		car.vel++; 
	    } 
	} 
	else 
	{win();} 
    } 
    settextstyle( 2, 0, 6 ); 
    setcolor( 5 ); 
    outtextxy( 4, 12, "Level" ); 
    gotoxy( 8, 2 ); 
    cout << car.level; 
    return ; 
} 
void about() 
{ 
    char opt; 
    while ( !kbhit() ) 
    { 
	for ( int i = 300;kbhit() == 0;i++ ) 
	{ 
	    cleardevice(); 
	    setcolor( 9 ); 
	    settextstyle( 4, 0, 5 ); 
	    setfillstyle( 9, 12 ); 
	    outtextxy( 220, 0, "ABOUT" ); 
	    bar( 220, 60, 370, 62 ); 
	    settextstyle( 2, 0, 5 ); 
	    setcolor( 2 ); 
	    outtextxy( 20, 100, "We had completed our work as a part of our VAP project work." ); 
	    outtextxy( 3, 115, "We had tried to reduce maximum problems in our program. Eventhough it may " ); 
	    outtextxy( 3, 130, "consist several technical and logical problems." ); 
	    outtextxy( 3, 165, "WE ARE........." ); 
	    outtextxy( 3, 180, "Hold a key to enter menu...." ); 
	    setcolor( 6 ); 
	    settextstyle( 2, 0, 6 ); 
	    outtextxy( 600 - i, 600 - i, "Ajinkya Sonawale" ); 
	    outtextxy( i - 150, 215, "Keshav Mishra" ); 
	    outtextxy( i - 30, i - 130, "Shubham Bangar " ); 
	    outtextxy( 600 - i, i - 150, "Manohar Dhumal" ); 
	    setfillstyle( 1, 4 ); 
	    bar3d( 180, 380, 450, 460, 4, 6 ); 
	    setcolor( 1 ); 
	    settextstyle( 2, 0, 10 ); 
	    outtextxy( 280, 380, "S2C" ); 
	    outtextxy( 215, 420, "2009-2010" ); 
	    delay( 60 ); 
	} 
    } 
    getch(); 
    return ; 
} 
int play( void ) 
{ 
    car.score = 0; 
    int life = 3, m, x1, x2, x3, s; 
re: 
    while ( life ) 
    { 
	cleardevice(); 
	if ( car.op1 == 0 ) 
	{ 
	    x1 = randx(); 
	    car.op1++; 
	} 
	else 
	{ 
	    opp1( x1 ); 
	} 
	if ( car.op2 == 0 ) 
	{ 
	    x2 = randx(); 
	    car.op2++; 
	} 
	else if ( car.op2 < 1 ) 
	{car.op2++;} 
	else 
	{ 
	    opp2( x2 ); 
	} 
	if ( car.op3 == 0 ) 
	{ 
	    x3 = randx(); 
	    car.op3++; 
	} 
	else if ( car.op3 < 1 ) 
	{car.op3++;} 
	else 
	{ 
	    opp3( x3 ); 
	} 
	setcolor( 10 ); 
	setfillstyle( 0, 0 ); 
	bar3d( 0, 0, 80, 70, 4, 3 ); 
	bgmove(); 
	level(); 
	score(); 
	settextstyle( 2, 0, 6 ); 
	setcolor( 5 ); 
	outtextxy( 4, 44, "Life" ); 
	gotoxy( 8, 4 );cout << life; 
	if ( check( x2, car.op2, car.cp ) || check( x1, car.op1, car.cp ) || check( x3, car.op3, car.cp ) ) 
	{ 
	    loss(); 
	    life--; 
	    if ( life == 0 ) 
	    { 
		over(); 
	    } 
	    car.op1 = 1; 
	    car.op2 = -16; 
	    car.op3 = -32; 
	    goto re; 
	} 
	if ( kbhit() ) 
	{ 
	    m = getch(); 
	    switch ( m ) 
	    { 
	    case LEFT: left(); 
		break; 
	    case RIGHT: right(); 
		break; 
	    case 'q': exit( 0 ); 
	    } 
	} 
	else 
	{ 
	    delay( 100 ); 
	} 
    } 
    getch(); 
    return ( 0 ); 
} 
void help() 
{ 
    cleardevice(); 
    settextstyle( 4, 0, 6 ); 
    setcolor( 13 ); 
    outtextxy( 200, 10, "HELP" ); 
    textcolor( YELLOW ); 
    gotoxy( 3, 6 ); 
    cout << "\n\n\n\n\n\n\nDPR (Adventure pursuit Racing is a simple game in which you have to lead a car by avoiding blocks on road.\nYou have to use the following keys to controll the car\n\n->UP\t--\tForward movement\n->LEFT\t--\tLeftside movement\n->RIGHT\t--\tRightside movement\n->q\t--\tExit from game at any time\n"; 
    getch(); 
    return ; 
} 
//Menu Option
void menu() 
{ 
    int s = 1, t = 0, a, p = 140; 
    do 
    { 
	do 
	{ 
	    cleardevice(); 
	    setcolor( YELLOW ); 
	    settextstyle( 1, 0, 4 ); 
	    outtextxy( 230, 30, "MENU" ); 
	    setfillstyle( 1, 2 ); 
	    bar( 140, 80, 400, 82 ); 
	    settextstyle( 1, 0, 1 ); 
	    setcolor( 10 ); 
	    outtextxy( 220, 137, "LINK START" ); 
	    outtextxy( 220, 167, "SCORES" ); 
	    outtextxy( 220, 197, "HELP" ); 
	    outtextxy( 220, 227, "ABOUT" ); 
	    outtextxy( 220, 257, "EXIT" ); 
	    setcolor( RED ); 
	    rectangle( 200, p, 350, p + 20 ); 
	    a = getch(); 
	    switch ( a ) 
	    { 
	    case UP: if ( p > 140 ) 
		{ 
		    p -= 30; 
		    s--; 
		} 
		break; 
	    case DOWN: if ( p < 260 ) 
		{ 
		    p += 30; 
		    s++; 
		}; 
		break; 
	    case ENTER: a = 1; 
		break; 
	    default: break; 
	    } 
	} 
	while ( a != 1 ); 
	switch ( s ) 
	{ 
	case 1: play(); 
	   	 break; 
	case 2: disp_score(); 
	  	  break; 
	case 3: help(); 
	   	 break; 
	case 4: about(); 
	    	break; 
	case 5: exit( 0 ); 
		 break; 
	} 
    } 
    while ( t == 0 ); 
    getch(); 
} 
// Main File for Execution
void main() 
{ 
    int gdriver = DETECT, gmode, errorcode; 
    initgraph( &gdriver, &gmode, "C:\\Turboc3\\BGI" ); 
    cleardevice(); 
    logo(); 
    menu(); 
    closegraph(); 
}
