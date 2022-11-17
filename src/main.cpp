/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <ctime>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
bool movemade=false;
int winningcolor=0;
bool Instant=false;//false when using dice true when choosing PieceSnL
//Start up SDL and create window
int run=1;
bool RedRotated[5];
bool YellowRotated[5];
bool GreenRotated[5];
bool BlueRotated[5];
int Redposn[5]={0,0,0,0,0};
int Greenposn[5]={0,0,0,0,0};
int Blueposn[5]={0,0,0,0,0};
int Yellowposn[5]={0,0,0,0,0};
bool redhome[5]={false,false,false,false,false};
bool yellowhome[5]={false,false,false,false,false};
bool greenhome[5]={false,false,false,false,false};
bool bluehome[5]={false,false,false,false,false};
int screenstate=1;

int runsnl=0;
int RedposnSnl=0;
int GreenposnSnl=0;
int BlueposnSnl=0;
int YellowposnSnl=0;
int Dice(){
	
	
	return (1+(rand()%6));
};
void modifierSnL(int roll){};

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image as texture
SDL_Texture* loadTexture( std::string path );




const int screen_width = 800;
const int screen_height = 800;
int BOARD_WIDTH=screen_width-2*screen_width/10;
int BOARD_HEIGHT=screen_height-screen_height/10;
//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Current displayed texture
SDL_Texture* Bckround = NULL;
SDL_Texture* Pybtn = NULL;
SDL_Texture* Htp = NULL;
SDL_Texture* Ext = NULL;
SDL_Texture* LudoPic = NULL;
SDL_Texture* SnLdr = NULL;
SDL_Texture* back= NULL;
SDL_Texture* exitscrn= NULL;
SDL_Texture* Ludoinstrn=NULL;
SDL_Texture* SnLinstrn=NULL;
SDL_Texture* gBoardSnL = NULL;
SDL_Texture* gDice = NULL;
SDL_Texture* gConsole = NULL;
SDL_Texture* gRed=NULL;
SDL_Texture* gBlue=NULL;
SDL_Texture* gGreen=NULL;
SDL_Texture* gYellow=NULL;
SDL_Texture* gDice1 = NULL;
SDL_Texture* gDice2 = NULL;
SDL_Texture* gDice3 = NULL;
SDL_Texture* gDice4 = NULL;
SDL_Texture* gDice5 = NULL;
SDL_Texture* gDice6 = NULL;
SDL_Texture* gRedConsole = NULL;
SDL_Texture* gBlueConsole = NULL;
SDL_Texture* gYellowConsole = NULL;
SDL_Texture* gGreenConsole = NULL;
SDL_Texture* gWelcomeConsole = NULL;
SDL_Texture* gBlueRollMessage=NULL;
SDL_Texture* gRedRollMessage=NULL;
SDL_Texture* gYellowRollMessage=NULL;
SDL_Texture* gGreenRollMessage=NULL;
SDL_Texture* gBlueContn=NULL;
SDL_Texture* gRedContn=NULL;
SDL_Texture* gYellowContn=NULL;
SDL_Texture* gGreenContn=NULL;
SDL_Texture* Redroll1=NULL;
SDL_Texture* Redroll2=NULL;
SDL_Texture* Redroll3=NULL;
SDL_Texture* Redroll4=NULL;
SDL_Texture* Redroll5=NULL;
SDL_Texture* Redroll6=NULL;
SDL_Texture*  Blueroll1=NULL;
SDL_Texture*  Blueroll2=NULL;
SDL_Texture*  Blueroll3=NULL;
SDL_Texture*  Blueroll4=NULL;
SDL_Texture*  Blueroll5=NULL;
SDL_Texture*  Blueroll6=NULL;
SDL_Texture*  Greenroll1=NULL;
SDL_Texture*  Greenroll2=NULL;
SDL_Texture*  Greenroll3=NULL;
SDL_Texture*  Greenroll4=NULL;
SDL_Texture*  Greenroll5=NULL;
SDL_Texture*  Greenroll6=NULL;
SDL_Texture*  Yellowroll1=NULL;
SDL_Texture*  Yellowroll2=NULL;
SDL_Texture*  Yellowroll3=NULL;
SDL_Texture*  Yellowroll4=NULL;
SDL_Texture*  Yellowroll5=NULL;
SDL_Texture*  Yellowroll6=NULL;
SDL_Texture*  DiceBrdr=NULL;
SDL_Texture*  _2xRed =NULL;
SDL_Texture*  _3xRed =NULL;
SDL_Texture*  _4xRed =NULL;
SDL_Texture*  _2xBlue =NULL;
SDL_Texture*  _3xBlue =NULL;
SDL_Texture*  _4xBlue =NULL;
SDL_Texture*  _2xGreen =NULL;
SDL_Texture*  _3xGreen =NULL;
SDL_Texture*  _4xGreen =NULL;
SDL_Texture*  _2xYellow =NULL;
SDL_Texture*  _3xYellow =NULL;
SDL_Texture*  _4xYellow =NULL;
SDL_Texture*  gBoard =NULL;
SDL_Texture* winnerB=NULL;
SDL_Texture* winnerY=NULL;
SDL_Texture* winnerG=NULL;
SDL_Texture* winnerR=NULL;
bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow =SDL_CreateWindow("Game",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,screen_width, screen_height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

class Grid{
public:
SDL_Rect Box[15][15];
int divider;
Grid(int frctn)
{
	divider=frctn;
	for (int Xcord=0;Xcord<=divider;Xcord++){
		for(int Ycord=0;Ycord<=divider;Ycord++){
			Box[Xcord][Ycord].x=((BOARD_WIDTH/divider)*Xcord);
			Box[Xcord][Ycord].y=((BOARD_HEIGHT/divider)*Ycord);
			Box[Xcord][Ycord].w=((BOARD_WIDTH/divider));
			Box[Xcord][Ycord].h=((BOARD_HEIGHT/divider));
	}
}
}
};



class PieceSnL{
public:
SDL_Rect Goti;



};


class Piece{
public:
SDL_Rect Goti[4];



};
bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load texture
	
	gBoard = loadTexture( "E:/Uni/Projects/LudoSnL/src/Imagefiles/Ludo.png" );
	_2xRed = loadTexture( "E:/Uni/Projects/LudoSnL/src/Imagefiles/Red2x.png" );
	_3xRed = loadTexture( "E:/Uni/Projects/LudoSnL/src/Imagefiles/Red3x.png" );
  	_4xRed = loadTexture( "E:/Uni/Projects/LudoSnL/src/Imagefiles/Red4x.png" );
  	_2xBlue = loadTexture( "E:/Uni/Projects/LudoSnL/src/Imagefiles/Blue2x.png" );
  	_3xBlue = loadTexture( "E:/Uni/Projects/LudoSnL/src/Imagefiles/Blue3x.png" );
  	_4xBlue = loadTexture( "E:/Uni/Projects/LudoSnL/src/Imagefiles/Blue4x.png" );
  	_2xGreen = loadTexture( "E:/Uni/Projects/LudoSnL/src/Imagefiles/Green2x.png" );
  	_3xGreen = loadTexture( "E:/Uni/Projects/LudoSnL/src/Imagefiles/Green3x.png" );
  	_4xGreen = loadTexture( "E:/Uni/Projects/LudoSnL/src/Imagefiles/Green4x.png" );
  	_2xYellow = loadTexture( "E:/Uni/Projects/LudoSnL/src/Imagefiles/Yellow2x.png" );
  	_3xYellow = loadTexture( "E:/Uni/Projects/LudoSnL/src/Imagefiles/Yellow3x.png" );
  	_4xYellow = loadTexture( "E:/Uni/Projects/LudoSnL/src/Imagefiles/Yellow4x.png" );

	 Bckround = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/page.png" );
 	 Pybtn = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/play.png" );
 	 Htp = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/howtoplay.png" );
 	 Ext = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/exit.png" );
 	 LudoPic = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/oludo.png" );
 	 SnLdr = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/osnl.png" );
	 back = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/back.png" );
	 exitscrn = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/Exitscrn.png" );
	 Ludoinstrn =loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/Ludoinstrn.png" );
	 SnLinstrn =loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/SnLinstrn.png" );
	 gBoardSnL = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/SNLL.png" );
	gDice = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/Diceholder.png" );
	gConsole = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/consoleplaceholder.png" );
	gRed=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/Red.png" );
	gBlue=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/Blue.png" );
	gGreen=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/Green.png" );
	gYellow=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/Yellow.png" );
	gDice1 = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/Die1.png" );
	gDice2= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/Die2.png" );
	gDice3 = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/Die3.png" );
	gDice4 = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/Die4.png" );
	gDice5 = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/Die5.png" );
	gDice6 = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/Die6.png" );
	gYellowConsole = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/YellowConsole.png" );
	gRedConsole = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/RedConsole.png" );
	gBlueConsole = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/BlueConsole.png" );
	gGreenConsole = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/GreenConsole.png" );
	gWelcomeConsole = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/Welcome.png" );
	gBlueRollMessage=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/BlueRolled.png" );
    gRedRollMessage=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/RedRolled.png" );
    gYellowRollMessage=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/YellowRolled.png" ); 
    gGreenRollMessage=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/GreenRolled.png" );
    gBlueContn=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/BlueContn.png" ); 
    gRedContn=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/RedContn.png" ); 
    gYellowContn=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/YellowContn.png" ); 
    gGreenContn=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/GreenContn.png" ); 
    Redroll1= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/1Red.png" );
 	Redroll2= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/2Red.png" );
 	Redroll3= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/3Red.png" );
 	Redroll4= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/4Red.png" );
 	Redroll5= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/5Red.png" );
 	Redroll6= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/6Red.png" );
  	Blueroll1= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/1Blue.png" );
  	Blueroll2= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/2Blue.png" );
  	Blueroll3= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/3Blue.png" );
  	Blueroll4= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/4Blue.png" );
  	Blueroll5= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/5Blue.png" );
  	Blueroll6= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/6Blue.png" );
  	Greenroll1= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/1Green.png" );
  	Greenroll2= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/2Green.png" );
  	Greenroll3= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/3Green.png" );
  	Greenroll4= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/4Green.png" );
  	Greenroll5= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/5Green.png" );
  	Greenroll6= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/6Green.png" );
  	Yellowroll1= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/1Yellow.png" );
  	Yellowroll2= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/2Yellow.png" );
  	Yellowroll3= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/3Yellow.png" );
  	Yellowroll4= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/4Yellow.png" );
  	Yellowroll5= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/5Yellow.png" );
  	Yellowroll6= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/6Yellow.png" );
	DiceBrdr= loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/DiceBorder.png" );
	winnerB=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/cblues.png" );
 	winnerY=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/cyellows.png" );
 	winnerG=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/cgreens.png" );
 	winnerR=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/creds.png" );
	//Nothing to load
	return success;
}

void close()
{
	//Free loaded image
	
	

	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture( std::string path )

{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

Grid SNL(10);	
Grid Ludo(15);
PieceSnL RedCSnl;
PieceSnL BlueCSnL;
PieceSnL GreenCSnL;
PieceSnL YellowCSnL;
class SpawnSnL
{
	public:
	SDL_Rect Red;
	SDL_Rect Yellow;
	SDL_Rect Green;
	SDL_Rect Blue;
	SpawnSnL()
	{
		Yellow.y=9*screen_height/10;
		Yellow.x=BOARD_WIDTH/10;
		Yellow.h=screen_height/10;
		Yellow.w=BOARD_WIDTH/10;

		Green.y=9*screen_height/10;
		Green.x=0;
		Green.h=screen_height/10;
		Green.w=BOARD_WIDTH/10;

		Blue.y=9*screen_height/10;
		Blue.x=2*BOARD_WIDTH/10;
		Blue.h=screen_height/10;
		Blue.w=BOARD_WIDTH/10;

		Red.y=9*screen_height/10;
		Red.x=3*BOARD_WIDTH/10;
		Red.h=screen_height/10;
		Red.w=BOARD_WIDTH/10;


	}
	

};
SpawnSnL StartSnL;

Piece RedC;
Piece BlueC;
Piece GreenC;
Piece YellowC;


class playzone
{

	public:
	int p=1;
	int xcor;
	int ycor;
	SDL_Rect playarea[100];
	playzone(){
	xcor=0;
	ycor=6;
    for(int i=1;i<=6;i++)
    {
       playarea[p]=Ludo.Box[xcor][ycor];
        p=p+1;
        xcor=xcor+1;

    }
    xcor=6;
    ycor=5;
    for(int i=1;i<=6;i++)
    {
       playarea[p]=Ludo.Box[xcor][ycor];
        p=p+1;
        ycor=ycor-1;


    }
    xcor=7;
    ycor=0;
    for(int i=1;i<=2;i++)
    {
       playarea[p]=Ludo.Box[xcor][ycor];
        p=p+1;
        xcor=xcor+1;

    }
    xcor=8;
    ycor=1;
    for(int i=1;i<=5;i++)
    {
       playarea[p]=Ludo.Box[xcor][ycor];
        p=p+1;
        ycor=ycor+1;

    }

    //.........................................................................

    xcor=9;
    ycor=6;
    for(int i=1;i<=6;i++)
    {
       playarea[p]=Ludo.Box[xcor][ycor];
        p=p+1;
        xcor=xcor+1;


    }
    xcor=14;
    ycor=7;
    for(int i=1;i<=2;i++)
    {
       playarea[p]=Ludo.Box[xcor][ycor];
        p=p+1;
        ycor=ycor+1;

    }
    xcor=13;
    ycor=8;
    for(int i=1;i<=5;i++)
    {
       playarea[p]=Ludo.Box[xcor][ycor];
        p=p+1;
        xcor=xcor-1;


    }
    //.........................................................................

    xcor=8;
    ycor=9;
    for(int i=1;i<=6;i++)
    {
       playarea[p]=Ludo.Box[xcor][ycor];
        p=p+1;
        ycor=ycor+1;


    }
    xcor=7;
    ycor=14;
    for(int i=1;i<=2;i++)
    {
       playarea[p]=Ludo.Box[xcor][ycor];
        p=p+1;
        xcor=xcor-1;

    }
    xcor=6;
    ycor=13;
    for(int i=1;i<=5;i++)
    {
       playarea[p]=Ludo.Box[xcor][ycor];
        p=p+1;
        ycor=ycor-1;

    }
	
	

 //.........................................................................

    xcor=5;
    ycor=8;
    for(int i=1;i<=6;i++)
    {
       playarea[p]=Ludo.Box[xcor][ycor];
        p=p+1;
        xcor=xcor-1;


    }
    xcor=0;
    ycor=7;
    for(int i=1;i<2;i++)
    {
       playarea[p]=Ludo.Box[xcor][ycor];
        p=p+1;
        ycor=ycor-1;

    }
	xcor=1;
	ycor=7;
	for(int i=1;i<=6;i++){
		playarea[p]=Ludo.Box[xcor][ycor];
		p=p+1;
		xcor=xcor+1;
	}
		playarea[59]=Ludo.Box[7][1];
		playarea[60]=Ludo.Box[7][2];
		playarea[61]=Ludo.Box[7][3];
		playarea[62]=Ludo.Box[7][4];
		playarea[63]=Ludo.Box[7][5];
		playarea[64]=Ludo.Box[7][6];



		playarea[65]=Ludo.Box[13][7];
		playarea[66]=Ludo.Box[12][7];
		playarea[67]=Ludo.Box[11][7];
		playarea[68]=Ludo.Box[10][7];
		playarea[69]=Ludo.Box[9][7];
		playarea[70]=Ludo.Box[8][7];



		playarea[71]=Ludo.Box[7][13];
		playarea[72]=Ludo.Box[7][12];
		playarea[73]=Ludo.Box[7][11];
		playarea[74]=Ludo.Box[7][10];
		playarea[75]=Ludo.Box[7][9];
		playarea[76]=Ludo.Box[7][8];




	}
};
playzone path;
class Spawn
{
	public:
	SDL_Rect Red[5];
	SDL_Rect Yellow[5];
	SDL_Rect Green[5];
	SDL_Rect Blue[5];
	Spawn()
	{
		Yellow[1]=Ludo.Box[11][2];
		Yellow[2]=Ludo.Box[11][3];
		Yellow[3]=Ludo.Box[12][2];
		Yellow[4]=Ludo.Box[12][3];
		Blue[1]=Ludo.Box[11][11];
		Blue[2]=Ludo.Box[11][12];
		Blue[3]=Ludo.Box[12][11];
		Blue[4]=Ludo.Box[12][12];
		Red[1]=Ludo.Box[2][11];
		Red[2]=Ludo.Box[2][12];
		Red[3]=Ludo.Box[3][11];
		Red[4]=Ludo.Box[3][12];
		Green[1]=Ludo.Box[2][2];
		Green[2]=Ludo.Box[2][3];
		Green[3]=Ludo.Box[3][2];
		Green[4]=Ludo.Box[3][3];
	}
	

};
Spawn Start;
void SpawnPlacement(){
	for (int i=1;i<=4;i++){
		RedC.Goti[i]=Start.Red[i];
		BlueC.Goti[i]=Start.Blue[i];
		YellowC.Goti[i]=Start.Yellow[i];
		GreenC.Goti[i]=Start.Green[i];
	}
	run=1;
}
void modifier(int roll,int color,int piece)
{
	movemade=false;
	bool allspawn=false;

	switch(color){
		case 1:
		if (Greenposn[1]==0 &&Greenposn[2]==0 &&Greenposn[3]==0 &&Greenposn[4]==0){allspawn=true;}
		break; 
		case 2:
		if (Yellowposn[1]==0 && Yellowposn[2]==0 && Yellowposn[3]==0 && Yellowposn[4]==0){allspawn=true;}
		break; 
		case 3:
		if (Blueposn[1]==0 &&Blueposn[2]==0 &&Blueposn[3]==0 &&Blueposn[4]==0){allspawn=true;}
		break; 
		case 4:
		if (Redposn[1]==0 && Redposn[2]==0 && Redposn[3]==0 && Redposn[4]==0){allspawn=true;}
		break;
		default:
		break;
		
	}

		if(color==1)
		{
			if (Greenposn[piece]>10)
			{
				GreenRotated[piece]=true;
			}
			if (roll!=6 && allspawn==true){return;}

			if (Greenposn[piece]==0 && roll==6){
				Greenposn[piece]=2;
				movemade=true;
			
			}
			else if(Greenposn[piece]!=0){
				Greenposn[piece]=Greenposn[piece]+roll;
				movemade=true;
				
			} 
			
			
			if(Greenposn[piece]>52 && GreenRotated[piece]==true){
				int kval=Greenposn[piece]-52;
				int jval=0;
				if ((Greenposn[piece]>58)){
					jval=Greenposn[piece]-58;
					kval=6-jval;
				}
				Greenposn[piece]=52+kval;
				
				movemade=true;
			}

				

			if(Greenposn[piece]==0 && roll<6 && allspawn==true){
				movemade=true;
				return;}
			else if (Greenposn[piece]==0 && roll<6 && allspawn!=true){
				movemade=false;
				return;
			}
			if(Greenposn[piece]==58){greenhome[piece]=true;}
			if(movemade==true){
			GreenC.Goti[piece]=path.playarea[Greenposn[piece]];
			}

			
		}
		if(color==2)
		{
			
			if (roll!=6 && allspawn==true){return;}
			if (Yellowposn[piece]==0 && roll==6){
				Yellowposn[piece]=15;
				movemade=true;
			}
			else if (Yellowposn[piece]!=0){
				Yellowposn[piece]=Yellowposn[piece]+roll;
				movemade=true;
			} 
			
			
			 if(Yellowposn[piece]>52 && Yellowposn[piece]<59){
				Yellowposn[piece]=Yellowposn[piece]-52;
				YellowRotated[piece]=true;
			}else if(Yellowposn[piece]>13 && YellowRotated[piece]==true){
				int kval=Yellowposn[piece]-13;
				int jval=0;
				if ((Yellowposn[piece]>64)){
					jval=Yellowposn[piece]-64;
					kval=6-jval;
				}
				Yellowposn[piece]=59+kval-1;
				
				movemade=true;
			}


			if(Yellowposn[piece]==0 && roll<6 && allspawn==true){
				movemade=true;
				return;}
			else if (Yellowposn[piece]==0 && roll<6 && allspawn!=true){
				movemade=false;
				return;
			}	
			if(Yellowposn[piece]==64){yellowhome[piece]=true;}
				
				YellowC.Goti[piece]=path.playarea[Yellowposn[piece]];
				
			
		}
		if(color==3)
		{
			
			if (roll!=6 && allspawn==true){return;}
			if (Blueposn[piece]==0 && roll==6){
				Blueposn[piece]=28;
				movemade=true;
			}
			else if (Blueposn[piece]!=0){
				Blueposn[piece]=Blueposn[piece]+roll;
				movemade=true;
			} 
			
			
			 if(Blueposn[piece]>52 && Blueposn[piece]<65){
				Blueposn[piece]=Blueposn[piece]-52;
				BlueRotated[piece]=true;
			}else if(Blueposn[piece]>26 && BlueRotated[piece]==true){
				int kval=Blueposn[piece]-26;
				int jval=0;
				if ((Blueposn[piece]>70)){
					jval=Blueposn[piece]-70;
					kval=6-jval;
				}
				Blueposn[piece]=65+kval-1;
				
				movemade=true;
			}


			if(Blueposn[piece]==0 && roll<6 && allspawn==true){
				movemade=true;
				return;}
			else if (Blueposn[piece]==0 && roll<6 && allspawn!=true){
				movemade=false;
				return;
			}	
				
				BlueC.Goti[piece]=path.playarea[Blueposn[piece]];
			if(Blueposn[piece]==0 && roll<6 && allspawn==true){
				movemade=true;
				return;}
			else if (Blueposn[piece]==0 && roll<6 && allspawn!=true){
				movemade=false;
				return;
			}
			if(Blueposn[piece]==70){bluehome[piece]=true;}
			BlueC.Goti[piece]=path.playarea[Blueposn[piece]];
			
		}
		if(color==4)
		{
			
			if (roll!=6 && allspawn==true){return;}
			if (Redposn[piece]==0 && roll==6){
				Redposn[piece]=41;
				movemade=true;
			}
			else if(Redposn[piece]!=0){
				Redposn[piece]=Redposn[piece]+roll;
				movemade=true;
			} 
			if(Redposn[piece]>52 && Redposn[piece]<71){
				Redposn[piece]=Redposn[piece]-52;
				RedRotated[piece]=true;
			}else if(Redposn[piece]>39 && RedRotated[piece]==true){
				int kval=Redposn[piece]-39;
				int jval=0;
				if ((Redposn[piece]>76)){
					jval=Redposn[piece]-76;
					kval=6-jval;
				}
				Redposn[piece]=71+kval-1;
				
				movemade=true;
			}

			
			if(Redposn[piece]==0 && roll<6 && allspawn==true){
				movemade=true;
				return;}
			else if (Redposn[piece]==0 && roll<6 && allspawn!=true){
				movemade=false;
				return;

			}
			if(Redposn[piece]==76){redhome[piece]=true;}
			if(movemade==true){
			RedC.Goti[piece]=path.playarea[Redposn[piece]];
			}
		}
	





}
void Stackcheck(int run)
{
	SDL_Rect RedStackIndicator;
	SDL_Rect BlueStackIndicator;
	SDL_Rect YellowStackIndicator;
	SDL_Rect GreenStackIndicator;
	int stackflag[5]={0,0,0,0};
	int piecestacked[5]={0,0,0,0};
	
	
	
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++)
		if(Redposn[i]==Redposn[j] && i!=j && Redposn[i]!=0 && Redposn[j]!=0)
		{
			stackflag[4]=stackflag[4]+1;
			piecestacked[4]=i;
		}
	}
	stackflag[4]=stackflag[4]/2;
	
	
	RedStackIndicator=RedC.Goti[piecestacked[4]];
	RedStackIndicator.w=BOARD_WIDTH/30;
	RedStackIndicator.h=BOARD_HEIGHT/30;

	SDL_RenderSetViewport( gRenderer, &RedStackIndicator );
	switch (stackflag[4]){
		case 1:
			SDL_RenderCopy( gRenderer,_2xRed , NULL, NULL );
			break;
		case 3:
			SDL_RenderCopy( gRenderer,_3xRed , NULL, NULL );
			break;
		case 6:
			SDL_RenderCopy( gRenderer,_4xRed , NULL, NULL );
			break;
	}
	
	
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++)
		if(Blueposn[i]==Blueposn[j] && i!=j && Blueposn[i]!=0 && Blueposn[j]!=0)
		{
			stackflag[3]=stackflag[3]+1;
			piecestacked[3]=i;
		}
	}
	stackflag[3]=stackflag[3]/2;
	
	BlueStackIndicator=BlueC.Goti[piecestacked[3]];
	BlueStackIndicator.w=BOARD_WIDTH/30;
	BlueStackIndicator.h=BOARD_HEIGHT/30;

	SDL_RenderSetViewport( gRenderer, &BlueStackIndicator );
	switch (stackflag[3]){
		case 1:
			SDL_RenderCopy( gRenderer,_2xBlue , NULL, NULL );
			break;
		case 3:
			SDL_RenderCopy( gRenderer,_3xBlue , NULL, NULL );
			break;
		case 6:
			SDL_RenderCopy( gRenderer,_4xBlue , NULL, NULL );
			break;
	}
	
	
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++)
		if(Yellowposn[i]==Yellowposn[j] && i!=j && Yellowposn[i]!=0 && Yellowposn[j]!=0)
		{
			stackflag[2]=stackflag[2]+1;
			piecestacked[2]=i;
		}
	}
	stackflag[2]=stackflag[2]/2;
	
	YellowStackIndicator=YellowC.Goti[piecestacked[2]];
	YellowStackIndicator.w=BOARD_WIDTH/30;
	YellowStackIndicator.h=BOARD_HEIGHT/30;

	SDL_RenderSetViewport( gRenderer, &YellowStackIndicator );
	switch (stackflag[2]){
		case 1:
			SDL_RenderCopy( gRenderer,_2xYellow , NULL, NULL );
			break;
		case 3:
			SDL_RenderCopy( gRenderer,_3xYellow , NULL, NULL );
			break;
		case 6:
			SDL_RenderCopy( gRenderer,_4xYellow, NULL, NULL );
			break;
	}
	
	
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++)
		if(Greenposn[i]==Greenposn[j] && i!=j && Greenposn[i]!=0 && Greenposn[j]!=0)
		{
			stackflag[1]=stackflag[1]+1;
			piecestacked[1]=i;
		}
	}
	stackflag[1]=stackflag[1]/2;
	
	GreenStackIndicator=GreenC.Goti[piecestacked[1]];
	GreenStackIndicator.w=BOARD_WIDTH/30;
	GreenStackIndicator.h=BOARD_HEIGHT/30;

	SDL_RenderSetViewport( gRenderer, &GreenStackIndicator );
	
	
	switch (stackflag[1]){
		case 1:
			SDL_RenderCopy( gRenderer,_2xGreen , NULL, NULL );
			break;
		case 3:
			SDL_RenderCopy( gRenderer,_3xGreen , NULL, NULL );
			break;
		case 6:
			SDL_RenderCopy( gRenderer,_4xGreen , NULL, NULL );
			break;
		}
		
		
	
		
	
		
	
	
	




}
	
	


void Winner(int color)
{
	
	Uint32 mousestate;
	int mousex,mousey;
	SDL_Event e;
	bool clicked=true;
	SDL_Rect screen;
	screen.h=screen_height;
	screen.w=screen_width;
	screen.x=0;
	screen.y=0;
			SDL_RenderSetViewport(gRenderer,&screen);
			switch (color)
			{
				case 1:
				SDL_RenderCopy( gRenderer,winnerG , NULL, NULL );
				
				break;	
				case 2:
				SDL_RenderCopy( gRenderer,winnerY , NULL, NULL );
				
				break;	
				case 3:
				SDL_RenderCopy( gRenderer,winnerB , NULL, NULL );
				
				break;	
				case 4:
				SDL_RenderCopy( gRenderer,winnerR , NULL, NULL );
				
				break;	
						

			
	
			}
			
			

}



void Pieceplacement()
{
	
	
	
	

	for(int i=1;i<=4;i++){
		SDL_RenderSetViewport( gRenderer, &RedC.Goti[i] );
		SDL_RenderCopy( gRenderer, gRed, NULL, NULL );
		
		SDL_RenderSetViewport( gRenderer, &BlueC.Goti[i] );	
		SDL_RenderCopy( gRenderer, gBlue, NULL, NULL );

		SDL_RenderSetViewport( gRenderer, &GreenC.Goti[i] );	
		SDL_RenderCopy( gRenderer, gGreen, NULL, NULL );

		SDL_RenderSetViewport( gRenderer, &YellowC.Goti[i] );	
		SDL_RenderCopy( gRenderer, gYellow, NULL, NULL );
	}





	

	
}
void Cutcheck(int roll)
{
	bool killsuccess;
	killsuccess=false;
	for (int i=1;i<=4;i++){
		
		for (int j=1;j<=4;j++)
		{
			if(Greenposn[i]==Redposn[j] && Greenposn[i]!=0 && Redposn[j]!=0 ){ 
				if (run==1 && Redposn[j]!=41&& Redposn[j]!=2 && Redposn[j]!=15 && Redposn[j]!=28){
					Redposn[j]=0;
					RedC.Goti[j]=Start.Red[j];
					killsuccess=true;
					RedRotated[j]=false;
				}else if ( run==4&& Greenposn[i]!=2&& Greenposn[i]!=41 && Greenposn[i]!=15&& Greenposn[i]!=28){
					Greenposn[i]=0;
					GreenC.Goti[i]=Start.Green[i];
					killsuccess=true;
					Greenposn[i]=false;
				}
			}
			if(Greenposn[j]==Redposn[i] && Greenposn[j]!=0 && Redposn[i]!=0){ 
				if (run==1 && Redposn[i]!=41&& Redposn[i]!=28&& Redposn[i]!=15&& Redposn[i]!=2){
					Redposn[i]=0;
					RedRotated[i]=false;
					RedC.Goti[i]=Start.Red[i];
					killsuccess=true;
				}else if ( run==4 && Greenposn[j]!=2 && Greenposn[j]!=41 && Greenposn[j]!=15&& Greenposn[j]!=28){
					Greenposn[j]=0;
					GreenRotated[j]=false;
					GreenC.Goti[j]=Start.Green[j];
					killsuccess=true;
				}
			}
		}

		for (int j=1;j<=4;j++){
		if(Blueposn[i]==Yellowposn[j] && Blueposn[i]!=0 && Yellowposn[j]!=0 )
		{ 
			if (run==3 && Yellowposn[j]!=15&& Yellowposn[j]!=28&& Yellowposn[j]!=2&& Yellowposn[j]!=41)
			{
				Yellowposn[j]=0;
				YellowRotated[j]=false;
				YellowC.Goti[j]=Start.Yellow[j];
				killsuccess=true;
			}
			else if ( run==2 && Blueposn[i]!=28 && Blueposn[i]!=41 && Blueposn[i]!=15 && Blueposn[i]!=2){
				Blueposn[i]=0;
				BlueRotated[i]=false;
				BlueC.Goti[i]=Start.Blue[i];
				killsuccess=true;
			}
		}
		if(Blueposn[j]==Yellowposn[i] && Blueposn[j]!=0 && Yellowposn[i]!=0  )
		{ 
			if (run==3 && Yellowposn[i]!=15 && Yellowposn[i]!=28 && Yellowposn[i]!=2 && Yellowposn[i]!=41)
			{
				Yellowposn[i]=0;
				YellowRotated[i]=false;
				YellowC.Goti[i]=Start.Yellow[i];
				killsuccess=true;
			}
			else if ( run==2 && Blueposn[j]!=28&& Blueposn[j]!=2&& Blueposn[j]!=15 && Blueposn[j]!=41){
				Blueposn[j]=0;
				BlueRotated[j]=false;
				BlueC.Goti[j]=Start.Blue[j];
				killsuccess=true;
			}
		}
		}
		for (int j=1;j<=4;j++){
			if(Yellowposn[i]==Redposn[j]&& Yellowposn[i]!=0 && Redposn[j]!=0  ){ 
				if (run==2 && Redposn[j]!=41&& Redposn[j]!=2 && Redposn[j]!=15 && Redposn[j]!=28){
					Redposn[j]=0;
					RedRotated[j]=false; 
					RedC.Goti[j]=Start.Red[j];
					killsuccess=true;
				}else if ( run==4 && Yellowposn[i]!=28 && Yellowposn[i]!=41 && Yellowposn[i]!=15 && Yellowposn[i]!=2){
					Yellowposn[i]=0;
					YellowRotated[i]=false;
					YellowC.Goti[i]=Start.Yellow[i];
					killsuccess=true;
				}
			}
			if(Yellowposn[j]==Redposn[i]&& Yellowposn[j]!=0 && Redposn[i]!=0){ 
				if (run==2 && Redposn[i]!=41 && Redposn[i]!=28 && Redposn[i]!=2 && Redposn[i]!=15){
					Redposn[i]=0;
					RedRotated[i]=false;
					RedC.Goti[i]=Start.Red[i];
					killsuccess=true;
				}else if ( run==4 && Yellowposn[j]!=28&& Yellowposn[j]!=2&& Yellowposn[j]!=15 && Yellowposn[j]!=41){
					Yellowposn[j]=0;
					YellowRotated[j]=false;
					YellowC.Goti[j]=Start.Yellow[j];
					killsuccess=true;
				}
			}
		}
	
		for (int j=1;j<=4;j++){
			if(Blueposn[i]==Redposn[j]&& Blueposn[i]!=0 && Redposn[j]!=0  ){ 
				if (run==3 && Redposn[j]!=41&& Redposn[j]!=2 && Redposn[j]!=15 && Redposn[j]!=28){
					Redposn[j]=0;
					RedRotated[j]=false; 
					RedC.Goti[j]=Start.Red[j];
					killsuccess=true;
				}else if ( run==4 && Blueposn[i]!=28 && Blueposn[i]!=41 && Blueposn[i]!=15 && Blueposn[i]!=2){
					Blueposn[i]=0;
					BlueRotated[i]=false;
					BlueC.Goti[i]=Start.Blue[i];
					killsuccess=true;
				}
			}
			if(Blueposn[j]==Redposn[i]&& Blueposn[j]!=0 && Redposn[i]!=0){ 
				if (run==3&& Redposn[i]!=41 && Redposn[i]!=28 && Redposn[i]!=2 && Redposn[i]!=15){
					Redposn[i]=0;
					RedRotated[i]=false;
					RedC.Goti[i]=Start.Red[i];
					killsuccess=true;
				}else if ( run==4 && Blueposn[j]!=28&& Blueposn[j]!=2&& Blueposn[j]!=15 && Blueposn[j]!=41){
					Blueposn[j]=0;
					BlueRotated[j]=false;
					BlueC.Goti[j]=Start.Blue[j];
					killsuccess=true;
				}
			}
		}
		for(int j=1;j<=4;j++)
		{
			if(Blueposn[i]==Greenposn[j]&& Greenposn[j]!=0 && Blueposn[i]!=0 ){ 
				if (run==3 && Greenposn[j]!=2 && Greenposn[j]!=41 && Greenposn[j]!=15&& Greenposn[j]!=28)
				{
					Greenposn[j]=0;
					GreenRotated[j]=false;
					GreenC.Goti[j]=Start.Green[j];
					killsuccess=true;
					
				}
				else if ( run==1 && Blueposn[i]!=28 && Blueposn[i]!=41 && Blueposn[i]!=15 && Blueposn[i]!=2)
				{
					Blueposn[i]=0;
					BlueRotated[i]=false;
					BlueC.Goti[i]=Start.Blue[i];
					killsuccess=true;
				}
			}
			if(Blueposn[j]==Greenposn[i]&& Greenposn[i]!=0 && Blueposn[j]!=0 ){ 
				if (run==3 && Greenposn[i]!=2&& Greenposn[i]!=41 && Greenposn[i]!=15&& Greenposn[i]!=28)
				{
					Greenposn[i]=0;
					GreenRotated[i]=false;
					GreenC.Goti[i]=Start.Green[i];
					killsuccess=true;
					
				}
				else if ( run==1&& Blueposn[j]!=28&& Blueposn[j]!=2&& Blueposn[j]!=15 && Blueposn[j]!=41)
				{
					Blueposn[j]=0;
					BlueRotated[j]=false;
					BlueC.Goti[j]=Start.Blue[j];
					killsuccess=true;
				}
			}
		}
		for(int j=1;j<=4;j++)
		{		
			if(Yellowposn[j]==Greenposn[i]&& Greenposn[i]!=0 && Yellowposn[j]!=0)
			{ 
				if (run==2&& Greenposn[i]!=2&& Greenposn[i]!=41 && Greenposn[i]!=15&& Greenposn[i]!=28 ){
					Greenposn[i]=0;
					GreenRotated[i]=false;
					GreenC.Goti[i]=Start.Green[i];
					killsuccess=true;
				}else if ( run==1 && Yellowposn[j]!=15 && Yellowposn[j]!=28 && Yellowposn[j]!=2 && Yellowposn[j]!=41){
					Yellowposn[j]=0;
					YellowRotated[j]=false;
					YellowC.Goti[j]=Start.Yellow[j];
					killsuccess=true;
				}
			}	
			if(Yellowposn[i]==Greenposn[j]&& Greenposn[j]!=0 && Yellowposn[i]!=0 )
			{ 
				if (run==2&& Greenposn[j]!=2 && Greenposn[j]!=41 && Greenposn[j]!=15&& Greenposn[j]!=28){
					Greenposn[j]=0;
					GreenRotated[j]=false;
					GreenC.Goti[j]=Start.Green[j];
					killsuccess=true;
				}else if ( run==1 && Yellowposn[i]!=15 && Yellowposn[i]!=28 && Yellowposn[i]!=2 && Yellowposn[i]!=41){
					Yellowposn[i]=0;
					YellowRotated[i]=false;
					YellowC.Goti[i]=Start.Yellow[i];
					killsuccess=true;
				}
			}
		}

	}
	
	if(killsuccess!=true && roll<6 ){
		run=run+1;
		if(run>4){run=1;}
	}	
		
	


}

int LudoGame()
{
	run=0;
	
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;
			//Top left corner viewport
			SDL_Rect WholeBg;
			WholeBg.x=0;
			WholeBg.y=0;
			WholeBg.h=screen_height;
			WholeBg.w=screen_width;
			SDL_Rect BoardViewport;
			BoardViewport.x = 0;
			BoardViewport.y = 0;
			BoardViewport.w = BOARD_WIDTH ;
			BoardViewport.h = BOARD_HEIGHT ;
			int mousex,mousey;
			Uint32 mousestate;
			bool Diceroll;
			bool Movelegal;
			//Top right viewport
			SDL_Rect DiceViewport;
			DiceViewport.x =BOARD_WIDTH;
			DiceViewport.y = 0;
			DiceViewport.w = screen_width-BOARD_WIDTH;
			DiceViewport.h = screen_height /3 ;
			SDL_Rect Die;
			Die.x =BOARD_WIDTH+(screen_width-BOARD_WIDTH)/2;
			Die.y = screen_height/6;
			Die.w = (screen_width-BOARD_WIDTH)/6;
			Die.h = screen_height /6 ;
			int roll;
			SDL_Rect ConsoleViewport;
			ConsoleViewport.x = BOARD_WIDTH;
			ConsoleViewport.y = screen_height /3 ;
			ConsoleViewport.w = screen_width-BOARD_WIDTH;
			ConsoleViewport.h = 2*screen_height / 3;
			SDL_Rect Console;
			Console.x = BOARD_WIDTH;
			Console.y = (5*screen_height /6) ;
			Console.w = screen_width-BOARD_WIDTH;
			Console.h = screen_height / 6;
			SDL_Rect RollMsg;
			RollMsg.x = BOARD_WIDTH;
			RollMsg.y = (ConsoleViewport.y) ;
			RollMsg.w = 2*(screen_width-BOARD_WIDTH)/3;
			RollMsg.h = screen_height / 6;
			SDL_Rect ContnMsg;
			ContnMsg.x = BOARD_WIDTH;
			ContnMsg.y = (ConsoleViewport.y+RollMsg.h) ;
			ContnMsg.w = screen_width-BOARD_WIDTH;
			ContnMsg.h = screen_height / 6;
			SDL_Rect RollNum;
			RollNum.x = BOARD_WIDTH+RollMsg.w;
			RollNum.y = (ConsoleViewport.y) ;
			RollNum.w = (screen_width-BOARD_WIDTH)/3;
			RollNum.h = screen_height / 6;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					
					

					
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						exit(30);
						screenstate=4;
						return 0;
					}
				
					
					//Clear screen
					SDL_SetRenderDrawColor( gRenderer, 0000, 0000, 0000, 0000 );
					SDL_RenderClear( gRenderer );

					
					SDL_RenderSetViewport( gRenderer, &DiceViewport );
					SDL_RenderCopy( gRenderer, gDice, NULL, NULL );
					
					SDL_RenderSetViewport( gRenderer, &Die );
					
					mousestate=SDL_GetMouseState(&mousex,&mousey);
					if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=Die.x&&mousex<=Die.x+Die.w&&mousey>=Die.y&&mousey<=Die.y+Die.h &&Instant==false)
					{
					 	roll=Dice();
						Instant=true;
						movemade=false;				 	

					 
					}
					
					switch (roll)  {
					case 1:
					SDL_RenderCopy( gRenderer, gDice1, NULL, NULL );
					break;

					case 2:
					SDL_RenderCopy( gRenderer, gDice2, NULL, NULL );
					break;
					case 3:
					SDL_RenderCopy( gRenderer, gDice3, NULL, NULL );
					break;
					case 4:
					SDL_RenderCopy( gRenderer, gDice4, NULL, NULL );
					break;
					case 5:
					SDL_RenderCopy( gRenderer, gDice5, NULL, NULL );
					break;
					case 6:
					SDL_RenderCopy( gRenderer, gDice6, NULL, NULL );
					break;
					default:
					SDL_RenderCopy( gRenderer, DiceBrdr, NULL, NULL );
					break;

					
					
					}	


					
					
				
					
					
					
					SDL_RenderSetViewport( gRenderer, &BoardViewport );
					
					//Render texture to screen
					SDL_RenderCopy( gRenderer, gBoard, NULL, NULL );
					
					if (run==0){
						SpawnPlacement();
					}
				
					bool allspawn=false;
						switch(run){
							case 1:
							if (Greenposn[1]==0 &&Greenposn[2]==0 &&Greenposn[3]==0 &&Greenposn[4]==0){allspawn=true;}
							break; 
							case 2:
							if (Yellowposn[1]==0 && Yellowposn[2]==0 && Yellowposn[3]==0 && Yellowposn[4]==0){allspawn=true;}
							break; 
							case 3:
							if (Blueposn[1]==0 &&Blueposn[2]==0 &&Blueposn[3]==0 &&Blueposn[4]==0){allspawn=true;}
							break; 
							case 4:
							if (Redposn[1]==0 && Redposn[2]==0 && Redposn[3]==0 && Redposn[4]==0){allspawn=true;}
							break;
							default:
							break;
							
						}

						bool Mav=true;
						if (allspawn==true&&roll<6){Mav=false;}
						
					Clicker:
					if(run==4)
					{
						
						for(int i=1;i<=4;i++)
						{
							
							if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=RedC.Goti[i].x&&mousex<=RedC.Goti[i].x+RedC.Goti[i].w&&mousey>=RedC.Goti[i].y&&mousey<=RedC.Goti[i].y+RedC.Goti[i].h && Instant==true)
							{							
								modifier(roll,run,i);
								Cutcheck(roll);
								Instant=false;
								int winflag=0;
								for (int ll=1;ll<=4;ll++)
								{
									if(redhome[ll]=true){winflag=winflag+1;}
								}
								if (winflag==4)
								{
									screenstate=9;
									winningcolor=run;
									
								}

								roll=0;
								
										
							}
							}
						
						
								
					}
					if(run==2){
						
						for(int i=1;i<=4;i++){
							
							if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=YellowC.Goti[i].x&&mousex<=YellowC.Goti[i].x+YellowC.Goti[i].w&&mousey>=YellowC.Goti[i].y&&mousey<=YellowC.Goti[i].y+YellowC.Goti[i].h && Instant==true){
								modifier(roll,run,i);
								Cutcheck(roll);
								Instant=false;
								int winflag=0;
								for (int ll=1;ll<=4;ll++)
								{
									if(yellowhome[ll]=true){winflag=winflag+1;}
								}
								if (winflag==4)
								{
									screenstate=9;
									winningcolor=run;
									
								}

								roll=0;
								
								
							}
							
						}
						
					}
					if(run==1){
						
						for(int i=1;i<=4;i++){
							if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=GreenC.Goti[i].x&&mousex<=GreenC.Goti[i].x+GreenC.Goti[i].w&&mousey>=GreenC.Goti[i].y&&mousey<=GreenC.Goti[i].y+GreenC.Goti[i].h && Instant==true){
								modifier(roll,run,i);
								Cutcheck(roll);
								Instant=false;
								int winflag=0;
								for (int ll=1;ll<=4;ll++)
								{
									if(greenhome[ll]=true){winflag=winflag+1;}
								}
								if (winflag==4)
								{
									screenstate=9;
									winningcolor=run;
									
								}

								roll=0;
							}
						}
					}
					
					if(run==3){
						
						for(int i=1;i<=4;i++){
							if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=BlueC.Goti[i].x&&mousex<=BlueC.Goti[i].x+BlueC.Goti[i].w&&mousey>=BlueC.Goti[i].y&&mousey<=BlueC.Goti[i].y+BlueC.Goti[i].h && Instant==true){
								modifier(roll,run,i);
								Cutcheck(roll);
								Instant=false;
								int winflag=0;
								for (int ll=1;ll<=4;ll++)
								{
									if(bluehome[ll]=true){winflag=winflag+1;}
								}
								if (winflag==4)
								{
									screenstate=9;
									winningcolor=run;
									
								}

								roll=0;
							}
						}
					}
			
					
					Pieceplacement();
					Stackcheck(run);
					

					//Bottom viewport


					SDL_RenderSetViewport( gRenderer, &ConsoleViewport );
					SDL_RenderCopy( gRenderer, gConsole, NULL, NULL );
					if(Instant==true){
					SDL_RenderSetViewport(gRenderer,&RollMsg);
					switch (run){
						case 1:
						SDL_RenderCopy( gRenderer, gGreenRollMessage, NULL, NULL );
						break;
						case 2:
						SDL_RenderCopy( gRenderer, gYellowRollMessage, NULL, NULL );
						break;
						case 3:
						SDL_RenderCopy( gRenderer, gBlueRollMessage, NULL, NULL );
						break;
						case 4:
						SDL_RenderCopy( gRenderer, gRedRollMessage, NULL, NULL );

						break;						
					}
					SDL_RenderSetViewport(gRenderer,&RollNum);
					switch (run){
						case 1:
							switch (roll){
								case 1:
								SDL_RenderCopy( gRenderer, Greenroll1, NULL, NULL );
								break;
								case 2:
								SDL_RenderCopy( gRenderer, Greenroll2, NULL, NULL );
								break;
								case 3:
								SDL_RenderCopy( gRenderer, Greenroll3, NULL, NULL );
								break;
								case 4:
								SDL_RenderCopy( gRenderer, Greenroll4, NULL, NULL );
								break;
								case 5:
								SDL_RenderCopy( gRenderer, Greenroll5, NULL, NULL );
								break;
								case 6:
								SDL_RenderCopy( gRenderer, Greenroll6, NULL, NULL );
								break;
							}
						break;
						case 2:
						switch (roll){
								case 1:
								SDL_RenderCopy( gRenderer, Yellowroll1, NULL, NULL );
								break;
								case 2:
								SDL_RenderCopy( gRenderer, Yellowroll2, NULL, NULL );
								break;
								case 3:
								SDL_RenderCopy( gRenderer, Yellowroll3, NULL, NULL );
								break;
								case 4:
								SDL_RenderCopy( gRenderer, Yellowroll4, NULL, NULL );
								break;
								case 5:
								SDL_RenderCopy( gRenderer, Yellowroll5, NULL, NULL );
								break;
								case 6:
								SDL_RenderCopy( gRenderer, Yellowroll6, NULL, NULL );
								break;
							}
						break;
						case 3:
						switch (roll){
								case 1:
								SDL_RenderCopy( gRenderer, Blueroll1, NULL, NULL );
								break;
								case 2:
								SDL_RenderCopy( gRenderer, Blueroll2, NULL, NULL );
								break;
								case 3:
								SDL_RenderCopy( gRenderer, Blueroll3, NULL, NULL );
								break;
								case 4:
								SDL_RenderCopy( gRenderer, Blueroll4, NULL, NULL );
								break;
								case 5:
								SDL_RenderCopy( gRenderer, Blueroll5, NULL, NULL );
								break;
								case 6:
								SDL_RenderCopy( gRenderer, Blueroll6, NULL, NULL );
								break;
							}
						break;
						case 4:
						switch (roll){
								case 1:
								SDL_RenderCopy( gRenderer, Redroll1, NULL, NULL );
								break;
								case 2:
								SDL_RenderCopy( gRenderer, Redroll2, NULL, NULL );
								break;
								case 3:
								SDL_RenderCopy( gRenderer, Redroll3, NULL, NULL );
								break;
								case 4:
								SDL_RenderCopy( gRenderer, Redroll4, NULL, NULL );
								break;
								case 5:
								SDL_RenderCopy( gRenderer, Redroll5, NULL, NULL );
								break;
								case 6:
								SDL_RenderCopy( gRenderer, Redroll6, NULL, NULL );
								break;
							}
						break;						
					}
					}
					//Render texture to screen
					
					
					
					SDL_RenderSetViewport( gRenderer, &Console );
					
					switch(run){
					case 1:
					if(Instant==false){
					SDL_RenderCopy( gRenderer, gGreenConsole, NULL, NULL );
					}else{
						SDL_RenderCopy( gRenderer, gGreenContn, NULL, NULL );
					}
					break;
					case 2:
					if(Instant==false){
					SDL_RenderCopy( gRenderer, gYellowConsole, NULL, NULL );
					}else{
						SDL_RenderCopy( gRenderer, gYellowContn, NULL, NULL );
					}
					break;
					case 4:
					if(Instant==false){
					SDL_RenderCopy( gRenderer, gRedConsole, NULL, NULL );
					}else{
						SDL_RenderCopy( gRenderer, gRedContn, NULL, NULL );
					}
					break;
					case 3:
					if(Instant==false){
					SDL_RenderCopy( gRenderer, gBlueConsole, NULL, NULL );
					}else{
						SDL_RenderCopy( gRenderer, gBlueContn, NULL, NULL );
					}
					break;
					default:
					SDL_RenderCopy( gRenderer, gWelcomeConsole, NULL, NULL );
					}

				
					//Update screen
					SDL_RenderPresent( gRenderer );
				}

				
				
			}
		
	}
	

	//Free resources and close SDL
	close();

	return 0;
}

class playzoneSnL{
	public:
	int p=1;
	int xcor;
	int ycor;
	SDL_Rect playarea[60];
	playzoneSnL(){
	xcor=0;
	ycor=9;
	for(int i=1;i<=10;i++){
		xcor=0;
		for(int j=1;j<=10;j++){
		playarea[p]=SNL.Box[xcor][ycor];
        p=p+1;
        xcor=xcor+1;
		}
		ycor=ycor-1;
	}
	}
};

void SpawnSnLPlacement(){
		RedCSnl.Goti=StartSnL.Red;
		BlueCSnL.Goti=StartSnL.Blue;
		YellowCSnL.Goti=StartSnL.Yellow;
		GreenCSnL.Goti=StartSnL.Green;
		runsnl=1;
}

playzoneSnL pathSnL;
void modifierSnL(int roll,int color,int PieceSnL){
	SDL_Rect screen;
	screen.h=screen_height;
	screen.w=screen_width;
	screen.x=0;
	screen.y=0;
	bool allSpawnSnL=false;
	switch(color){
		case 1:
		if(GreenposnSnl==0){allSpawnSnL=true;}
		break;
		case 2:
		if(YellowposnSnl==0){allSpawnSnL=true;}
		break;		
		case 3:
		if(BlueposnSnl==0){allSpawnSnL=true;}
		break;		
		case 4:
		if(RedposnSnl==0){allSpawnSnL=true;}
		break;		
		default:
		break;
	}
	if(color==1){
		if (roll!=6 && allSpawnSnL==true){return;}
		if (GreenposnSnl==0 && roll==6){
			GreenposnSnl=1;
			movemade=true;
		
		}
		else if(GreenposnSnl!=0){
			GreenposnSnl=GreenposnSnl+roll;
			movemade=true;		
		}

		if(GreenposnSnl==0 && roll<6 && allSpawnSnL==true){
			movemade=true;
			return;}
		else if (GreenposnSnl==0 && roll<6 && allSpawnSnL!=true){
			movemade=false;
			return;
		}
		if(GreenposnSnl>100){GreenposnSnl=100-(GreenposnSnl-100);}
		if(GreenposnSnl==100)
		{
			
			winningcolor=color;
			return;
			
		}
		if(movemade=true){
			GreenCSnL.Goti=pathSnL.playarea[GreenposnSnl];
		}
	}	
	if(color==2){
		if (roll!=6 && allSpawnSnL==true){return;}
		if (YellowposnSnl==0 && roll==6){
			YellowposnSnl=1;
			movemade=true;
		
		}
		else if(YellowposnSnl!=0){
			YellowposnSnl=YellowposnSnl+roll;
			movemade=true;		
		}

		if(YellowposnSnl==0 && roll<6 && allSpawnSnL==true){
			movemade=true;
			return;}
		else if (YellowposnSnl==0 && roll<6 && allSpawnSnL!=true){
			movemade=false;
			return;
		}
		if(YellowposnSnl>100){YellowposnSnl=100-(YellowposnSnl-100);}
		if(YellowposnSnl==100)
		{
			winningcolor=color;
			return;
			
		}
		if(movemade=true){
			YellowCSnL.Goti=pathSnL.playarea[YellowposnSnl];
		}
	}
	if(color==3){
		if (roll!=6 && allSpawnSnL==true){return;}
		if (BlueposnSnl==0 && roll==6){
			BlueposnSnl=1;
			movemade=true;
		
		}
		else if(BlueposnSnl!=0){
			BlueposnSnl=BlueposnSnl+roll;
			movemade=true;		
		}

		if(BlueposnSnl==0 && roll<6 && allSpawnSnL==true){
			movemade=true;
			return;}
		else if (BlueposnSnl==0 && roll<6 && allSpawnSnL!=true){
			movemade=false;
			return;
		}
		if(BlueposnSnl>100){BlueposnSnl=100-(BlueposnSnl-100);}
		if(BlueposnSnl==100)
		{
			winningcolor=color;
			return;
		}
		if(movemade=true){
			BlueCSnL.Goti=pathSnL.playarea[BlueposnSnl];
		}
	}	
	if(color==4){
		if (roll!=6 && allSpawnSnL==true){return;}
		if (RedposnSnl==0 && roll==6){
			RedposnSnl=1;
			movemade=true;
		
		}
		else if(RedposnSnl!=0){
			RedposnSnl=RedposnSnl+roll;
			movemade=true;		
		}

		if(RedposnSnl==0 && roll<6 && allSpawnSnL==true){
			movemade=true;
			return;}
		else if (RedposnSnl==0 && roll<6 && allSpawnSnL!=true){
			movemade=false;
			return;
		}
		if(RedposnSnl>100){RedposnSnl=100-(RedposnSnl-100);}
		if(RedposnSnl==100)
		{
			winningcolor=color;
			return;
		}
		if(movemade=true){
			RedCSnl.Goti=pathSnL.playarea[RedposnSnl];
		}
	}


}

void PieceSnLplacementSnL()
{

		SDL_RenderSetViewport( gRenderer, &RedCSnl.Goti );
		SDL_RenderCopy( gRenderer, gRed, NULL, NULL );
		
		SDL_RenderSetViewport( gRenderer, &BlueCSnL.Goti );	
		SDL_RenderCopy( gRenderer, gBlue, NULL, NULL );

		SDL_RenderSetViewport( gRenderer, &GreenCSnL.Goti );	
		SDL_RenderCopy( gRenderer, gGreen, NULL, NULL );

		SDL_RenderSetViewport( gRenderer, &YellowCSnL.Goti );	
		SDL_RenderCopy( gRenderer, gYellow, NULL, NULL );
	
}


void CutcheckSnL(int roll)
{
	bool killsuccess;
	killsuccess=false;

			if(GreenposnSnl==RedposnSnl && GreenposnSnl!=0 && RedposnSnl!=0 ){ 
				if (runsnl==1){
					RedposnSnl=0;
					RedCSnl.Goti=StartSnL.Red;
					killsuccess=true;
				}else if ( runsnl==4){
					GreenposnSnl=0;
					GreenCSnL.Goti=StartSnL.Green;
					killsuccess=true;
				}
			}
			if(GreenposnSnl==RedposnSnl && GreenposnSnl!=0 && RedposnSnl!=0 ){ 
				if (runsnl==1){
					RedposnSnl=0;
					RedCSnl.Goti=StartSnL.Red;
					killsuccess=true;
				}else if ( runsnl==4){
					GreenposnSnl=0;
					GreenCSnL.Goti=StartSnL.Green;
					killsuccess=true;
				}
			}
		

		
		if(BlueposnSnl==YellowposnSnl && BlueposnSnl!=0 && YellowposnSnl!=0)
		{ 
			if (runsnl==3)
			{
				YellowposnSnl=0;
				YellowCSnL.Goti=StartSnL.Yellow;
				killsuccess=true;
			}
			else if ( runsnl==2){
				BlueposnSnl=0;
				BlueCSnL.Goti=StartSnL.Blue;
				killsuccess=true;
			}
		}
		if(BlueposnSnl==YellowposnSnl && BlueposnSnl!=0 && YellowposnSnl!=0)
		{ 
			if (runsnl==3)
			{
				YellowposnSnl=0;
				YellowCSnL.Goti=StartSnL.Yellow;
				killsuccess=true;
			}
			else if ( runsnl==2){
				BlueposnSnl=0;
				BlueCSnL.Goti=StartSnL.Blue;
				killsuccess=true;
			}
		
		}
		
		if(RedposnSnl==YellowposnSnl && YellowposnSnl!=0 && RedposnSnl!=0)
		{ 
			if (runsnl==4){
				YellowposnSnl=0;
				YellowCSnL.Goti=StartSnL.Yellow;
				killsuccess=true;
			}else if ( runsnl==2){
				RedposnSnl=0;
				RedCSnl.Goti=StartSnL.Red;
				killsuccess=true;
			}
		}
		
		if(RedposnSnl==YellowposnSnl && YellowposnSnl!=0 && RedposnSnl!=0)
		{ 
			if (runsnl==4){
				YellowposnSnl=0;
				YellowCSnL.Goti=StartSnL.Yellow;
				killsuccess=true;
			}else if ( runsnl==2){
				RedposnSnl=0;
				RedCSnl.Goti=StartSnL.Red;
				killsuccess=true;
			}
		
		}

		
			if(BlueposnSnl==RedposnSnl&& BlueposnSnl!=0 && RedposnSnl!=0){ 
				if (runsnl==3){
					RedposnSnl=0;
					RedCSnl.Goti=StartSnL.Red;
					killsuccess=true;
				}else if ( runsnl==4){
					BlueposnSnl=0;
					BlueCSnL.Goti=StartSnL.Blue;
					killsuccess=true;
				}
			}
			if(BlueposnSnl==RedposnSnl && BlueposnSnl!=0 && RedposnSnl!=0){ 
				if (runsnl==3){
					RedposnSnl=0;
					RedCSnl.Goti=StartSnL.Red;
					killsuccess=true;
				}else if ( runsnl==4){
					BlueposnSnl=0;
					BlueCSnL.Goti=StartSnL.Blue;
					killsuccess=true;
				}
			}
		
		
			if(BlueposnSnl==GreenposnSnl && GreenposnSnl!=0 && BlueposnSnl!=0){ 
				if (runsnl==3)
				{
					GreenposnSnl=0;
					GreenCSnL.Goti=StartSnL.Green;
					killsuccess=true;
					
				}
				else if ( runsnl==1)
				{
					BlueposnSnl=0;
					BlueCSnL.Goti=StartSnL.Blue;
					killsuccess=true;
				}
			}
			if(BlueposnSnl==GreenposnSnl && GreenposnSnl!=0 && BlueposnSnl!=0){ 
				if (runsnl==3)
				{
					GreenposnSnl=0;
					GreenCSnL.Goti=StartSnL.Green;
					killsuccess=true;
					
				}
				else if ( runsnl==1)
				{
					BlueposnSnl=0;
					BlueCSnL.Goti=StartSnL.Blue;
					killsuccess=true;
				}
			}
		
		
			if(YellowposnSnl==GreenposnSnl && GreenposnSnl!=0 && YellowposnSnl!=0)
			{ 
				if (runsnl==2){
					GreenposnSnl=0;
					GreenCSnL.Goti=StartSnL.Green;
					killsuccess=true;
				}else if ( runsnl==1){
					YellowposnSnl=0;
					YellowCSnL.Goti=StartSnL.Yellow;
					killsuccess=true;
				}
			}	
			if(YellowposnSnl==GreenposnSnl&& GreenposnSnl!=0 && YellowposnSnl!=0)
			{ 
				if (runsnl==2){
					GreenposnSnl=0;
					GreenCSnL.Goti=StartSnL.Green;
					killsuccess=true;
				}else if ( runsnl==1){
					YellowposnSnl=0;
					YellowCSnL.Goti=StartSnL.Yellow;
					killsuccess=true;
				}
			}
		

	
	if(killsuccess!=true && roll<6){
		runsnl=runsnl+1;
		if(runsnl>4){runsnl=1;}
	}
}


void snake(){
	if(GreenposnSnl==25){
		GreenposnSnl=5;
		GreenCSnL.Goti=pathSnL.playarea[GreenposnSnl];
	}
	if(GreenposnSnl==34){
		GreenposnSnl=1;
		GreenCSnL.Goti=pathSnL.playarea[GreenposnSnl];
	}
	if(GreenposnSnl==47){
		GreenposnSnl=19;
		GreenCSnL.Goti=pathSnL.playarea[GreenposnSnl];
	}
	if(GreenposnSnl==65){
		GreenposnSnl=52;
		GreenCSnL.Goti=pathSnL.playarea[GreenposnSnl];
	}
	if(GreenposnSnl==87){
		GreenposnSnl=57;
		GreenCSnL.Goti=pathSnL.playarea[GreenposnSnl];
	}
	if(GreenposnSnl==91){
		GreenposnSnl=61;
		GreenCSnL.Goti=pathSnL.playarea[GreenposnSnl];
	}
	if(GreenposnSnl==99){
		GreenposnSnl=69;
		GreenCSnL.Goti=pathSnL.playarea[GreenposnSnl];
	}

	if(RedposnSnl==25){
		RedposnSnl=5;
		RedCSnl.Goti=pathSnL.playarea[RedposnSnl];
	}
	if(RedposnSnl==34){
		RedposnSnl=1;
		RedCSnl.Goti=pathSnL.playarea[RedposnSnl];
	}
	if(RedposnSnl==47){
		RedposnSnl=19;
		RedCSnl.Goti=pathSnL.playarea[RedposnSnl];
	}
	if(RedposnSnl==65){
		RedposnSnl=52;
		RedCSnl.Goti=pathSnL.playarea[RedposnSnl];
	}
	if(RedposnSnl==87){
		RedposnSnl=57;
		RedCSnl.Goti=pathSnL.playarea[RedposnSnl];
	}
	if(RedposnSnl==91){
		RedposnSnl=61;
		RedCSnl.Goti=pathSnL.playarea[RedposnSnl];
	}
	if(RedposnSnl==99){
		RedposnSnl=69;
		RedCSnl.Goti=pathSnL.playarea[RedposnSnl];
	}

	if(YellowposnSnl==25){
		YellowposnSnl=5;
		YellowCSnL.Goti=pathSnL.playarea[YellowposnSnl];
	}
	if(YellowposnSnl==34){
		YellowposnSnl=1;
		YellowCSnL.Goti=pathSnL.playarea[YellowposnSnl];
	}
	if(YellowposnSnl==47){
		YellowposnSnl=19;
		YellowCSnL.Goti=pathSnL.playarea[YellowposnSnl];
	}
	if(YellowposnSnl==65){
		YellowposnSnl=52;
		YellowCSnL.Goti=pathSnL.playarea[YellowposnSnl];
	}
	if(YellowposnSnl==87){
		YellowposnSnl=57;
		YellowCSnL.Goti=pathSnL.playarea[YellowposnSnl];
	}
	if(YellowposnSnl==91){
		YellowposnSnl=61;
		YellowCSnL.Goti=pathSnL.playarea[YellowposnSnl];
	}
	if(YellowposnSnl==99){
		YellowposnSnl=69;
		YellowCSnL.Goti=pathSnL.playarea[YellowposnSnl];
	}

	if(BlueposnSnl==25){
		BlueposnSnl=5;
		BlueCSnL.Goti=pathSnL.playarea[BlueposnSnl];
	}
	if(BlueposnSnl==34){
		BlueposnSnl=1;
		BlueCSnL.Goti=pathSnL.playarea[BlueposnSnl];
	}
	if(BlueposnSnl==47){
		BlueposnSnl=19;
		BlueCSnL.Goti=pathSnL.playarea[BlueposnSnl];
	}
	if(BlueposnSnl==65){
		BlueposnSnl=52;
		BlueCSnL.Goti=pathSnL.playarea[BlueposnSnl];
	}
	if(BlueposnSnl==87){
		BlueposnSnl=57;
		BlueCSnL.Goti=pathSnL.playarea[BlueposnSnl];
	}
	if(BlueposnSnl==91){
		BlueposnSnl=61;
		BlueCSnL.Goti=pathSnL.playarea[BlueposnSnl];
	}
	if(BlueposnSnl==99){
		BlueposnSnl=69;
		BlueCSnL.Goti=pathSnL.playarea[BlueposnSnl];
	}
}

void ladder(){
	if(BlueposnSnl==3){
		BlueposnSnl=51;
		BlueCSnL.Goti=pathSnL.playarea[BlueposnSnl];
	}
	if(BlueposnSnl==6){
		BlueposnSnl=27;
		BlueCSnL.Goti=pathSnL.playarea[BlueposnSnl];
	}
	if(BlueposnSnl==20){
		BlueposnSnl=70;
		BlueCSnL.Goti=pathSnL.playarea[BlueposnSnl];
	}
	if(BlueposnSnl==36){
		BlueposnSnl=55;
		BlueCSnL.Goti=pathSnL.playarea[BlueposnSnl];
	}
	if(BlueposnSnl==63){
		BlueposnSnl=95;
		BlueCSnL.Goti=pathSnL.playarea[BlueposnSnl];
	}
	if(BlueposnSnl==68){
		BlueposnSnl=98;
		BlueCSnL.Goti=pathSnL.playarea[BlueposnSnl];
	}

	if(RedposnSnl==3){
		RedposnSnl=51;
		RedCSnl.Goti=pathSnL.playarea[RedposnSnl];
	}
	if(RedposnSnl==6){
		RedposnSnl=27;
		RedCSnl.Goti=pathSnL.playarea[RedposnSnl];
	}
	if(RedposnSnl==20){
		RedposnSnl=70;
		RedCSnl.Goti=pathSnL.playarea[RedposnSnl];
	}
	if(RedposnSnl==36){
		RedposnSnl=55;
		RedCSnl.Goti=pathSnL.playarea[RedposnSnl];
	}
	if(RedposnSnl==63){
		RedposnSnl=95;
		RedCSnl.Goti=pathSnL.playarea[RedposnSnl];
	}
	if(RedposnSnl==68){
		RedposnSnl=98;
		RedCSnl.Goti=pathSnL.playarea[RedposnSnl];
	}

	if(YellowposnSnl==3){
		YellowposnSnl=51;
		YellowCSnL.Goti=pathSnL.playarea[YellowposnSnl];
	}
	if(YellowposnSnl==6){
		YellowposnSnl=27;
		YellowCSnL.Goti=pathSnL.playarea[YellowposnSnl];
	}
	if(YellowposnSnl==20){
		YellowposnSnl=70;
		YellowCSnL.Goti=pathSnL.playarea[YellowposnSnl];
	}
	if(YellowposnSnl==36){
		YellowposnSnl=55;
		YellowCSnL.Goti=pathSnL.playarea[YellowposnSnl];
	}
	if(YellowposnSnl==63){
		YellowposnSnl=95;
		YellowCSnL.Goti=pathSnL.playarea[YellowposnSnl];
	}
	if(YellowposnSnl==68){
		YellowposnSnl=98;
		YellowCSnL.Goti=pathSnL.playarea[YellowposnSnl];
	}

	if(GreenposnSnl==3){
		GreenposnSnl=51;
		GreenCSnL.Goti=pathSnL.playarea[GreenposnSnl];
	}
	if(GreenposnSnl==6){
		GreenposnSnl=27;
		GreenCSnL.Goti=pathSnL.playarea[GreenposnSnl];
	}
	if(GreenposnSnl==20){
		GreenposnSnl=70;
		GreenCSnL.Goti=pathSnL.playarea[GreenposnSnl];
	}
	if(GreenposnSnl==36){
		GreenposnSnl=55;
		GreenCSnL.Goti=pathSnL.playarea[GreenposnSnl];
	}
	if(GreenposnSnl==63){
		GreenposnSnl=95;
		GreenCSnL.Goti=pathSnL.playarea[GreenposnSnl];
	}
	if(GreenposnSnl==68){
		GreenposnSnl=98;
		GreenCSnL.Goti=pathSnL.playarea[GreenposnSnl];
	}

}


void SnLGame(  ){

 	bool InstantSnL=false;//false when using dice true when choosing PieceSnL
	//StartSnL up SDL and create window
	runsnl=0;
			if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event esnL;
			//Top left corner viewport
			SDL_Rect BoardViewport;
			BoardViewport.x = 0;
			BoardViewport.y = 0;
			BoardViewport.w = BOARD_WIDTH ;
			BoardViewport.h = BOARD_HEIGHT ;
			int mousex,mousey;
			Uint32 mousestate;
			bool Diceroll;
			bool Movelegal;
			//Top right viewport
			SDL_Rect DiceViewport;
			DiceViewport.x =BOARD_WIDTH;
			DiceViewport.y = 0;
			DiceViewport.w = screen_width-BOARD_WIDTH;
			DiceViewport.h = screen_width /3 ;
			SDL_Rect Die;
			Die.x =BOARD_WIDTH+(screen_width-BOARD_WIDTH)/2;
			Die.y = screen_height/6;
			Die.w = (screen_width-BOARD_WIDTH)/6;
			Die.h = screen_height /6 ;
			int roll;
			SDL_Rect ConsoleViewport;
			ConsoleViewport.x = BOARD_WIDTH;
			ConsoleViewport.y = screen_height /3 ;
			ConsoleViewport.w = screen_width-BOARD_WIDTH;
			ConsoleViewport.h = 2*screen_height / 3;
			SDL_Rect Console;
			Console.x = BOARD_WIDTH;
			Console.y = (5*screen_height /6) ;
			Console.w = screen_width-BOARD_WIDTH;
			Console.h = screen_height / 6;
			SDL_Rect RollMsg;
			RollMsg.x = BOARD_WIDTH;
			RollMsg.y = (ConsoleViewport.y) ;
			RollMsg.w = 2*(screen_width-BOARD_WIDTH)/3;
			RollMsg.h = screen_height / 6;
			SDL_Rect ContnMsg;
			ContnMsg.x = BOARD_WIDTH;
			ContnMsg.y = (ConsoleViewport.y+RollMsg.h) ;
			ContnMsg.w = screen_width-BOARD_WIDTH;
			ContnMsg.h = screen_height / 6;
			SDL_Rect RollNum;
			RollNum.x = BOARD_WIDTH+RollMsg.w;
			RollNum.y = (ConsoleViewport.y) ;
			RollNum.w = (screen_width-BOARD_WIDTH)/3;
			RollNum.h = screen_height / 6;

			//While application is runsnlning
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &esnL ) != 0 )
				{
					
					

					
					//User requests quit
					if( esnL.type == SDL_QUIT )
					{
						exit(30);
						screenstate=4;
						return;
					}
				
					
					//Clear screen
					SDL_SetRenderDrawColor( gRenderer, 0000, 0000, 0000, 0000 );
					SDL_RenderClear( gRenderer );

					
					SDL_RenderSetViewport( gRenderer, &DiceViewport );
					SDL_RenderCopy( gRenderer, gDice, NULL, NULL );
					
					SDL_RenderSetViewport( gRenderer, &Die );
					
					mousestate=SDL_GetMouseState(&mousex,&mousey);
					if (esnL.type==SDL_MOUSEBUTTONDOWN && mousex>=Die.x&&mousex<=Die.x+Die.w&&mousey>=Die.y&&mousey<=Die.y+Die.h &&InstantSnL==false)
					{
					 	roll=Dice();
						InstantSnL=true;
						movemade=false;				 	

					 
					}
					
					switch (roll)  {
					case 1:
					SDL_RenderCopy( gRenderer, gDice1, NULL, NULL );
					break;

					case 2:
					SDL_RenderCopy( gRenderer, gDice2, NULL, NULL );
					break;
					case 3:
					SDL_RenderCopy( gRenderer, gDice3, NULL, NULL );
					break;
					case 4:
					SDL_RenderCopy( gRenderer, gDice4, NULL, NULL );
					break;
					case 5:
					SDL_RenderCopy( gRenderer, gDice5, NULL, NULL );
					break;
					case 6:
					SDL_RenderCopy( gRenderer, gDice6, NULL, NULL );
					break;
					default:
					SDL_RenderCopy( gRenderer, DiceBrdr, NULL, NULL );
					break;
					}	


					
					
				
					
					
					
					SDL_RenderSetViewport( gRenderer, &BoardViewport );
					
					//Render texture to screen
					SDL_RenderCopy( gRenderer, gBoardSnL, NULL, NULL );
					
					if (runsnl==0){
						SpawnSnLPlacement();
					}
				
					bool allSpawnSnL=false;
						switch(runsnl){
							case 1:
							if (GreenposnSnl==0){allSpawnSnL=true;}
							break; 
							case 2:
							if (YellowposnSnl==0){allSpawnSnL=true;}
							break; 
							case 3:
							if (BlueposnSnl==0){allSpawnSnL=true;}
							break; 
							case 4:
							if (RedposnSnl==0){allSpawnSnL=true;}
							break;
							default:
							break;
							
						}

						bool Mav=true;
						if (allSpawnSnL==true&&roll<6){Mav=false;}
						
					if(runsnl==4)
					{
						
					
							
							if (esnL.type==SDL_MOUSEBUTTONDOWN && mousex>=RedCSnl.Goti.x&&mousex<=RedCSnl.Goti.x+RedCSnl.Goti.w&&mousey>=RedCSnl.Goti.y&&mousey<=RedCSnl.Goti.y+RedCSnl.Goti.h && InstantSnL==true)
							{							
								modifierSnL(roll,runsnl,1);
								snake();
								ladder();
								CutcheckSnL(roll);
								if(winningcolor !=0){return;}
								if (movemade=true)
								{
									InstantSnL=false;
									roll=0;
								}
										
							}
						
						
								
					}
					if(runsnl==2){

							if (esnL.type==SDL_MOUSEBUTTONDOWN && mousex>=YellowCSnL.Goti.x&&mousex<=YellowCSnL.Goti.x+YellowCSnL.Goti.w&&mousey>=YellowCSnL.Goti.y&&mousey<=YellowCSnL.Goti.y+YellowCSnL.Goti.h && InstantSnL==true){
								modifierSnL(roll,runsnl,1);
								snake();
								ladder();
								CutcheckSnL(roll);
								if(winningcolor !=0){return;}
								if (movemade=true)
								{
									InstantSnL=false;
									roll=0;
								}
								
							}
						
					}
					if(runsnl==1){

							if (esnL.type==SDL_MOUSEBUTTONDOWN && mousex>=GreenCSnL.Goti.x&&mousex<=GreenCSnL.Goti.x+GreenCSnL.Goti.w&&mousey>=GreenCSnL.Goti.y&&mousey<=GreenCSnL.Goti.y+GreenCSnL.Goti.h && InstantSnL==true){
								modifierSnL(roll,runsnl,1);
								snake();
								ladder();
								CutcheckSnL(roll);
								if(winningcolor !=0){return;}
								if (movemade=true)
								{
									InstantSnL=false;
									roll=0;
								}
							}
						
					}
					if(runsnl==3){

							if (esnL.type==SDL_MOUSEBUTTONDOWN && mousex>=BlueCSnL.Goti.x&&mousex<=BlueCSnL.Goti.x+BlueCSnL.Goti.w&&mousey>=BlueCSnL.Goti.y&&mousey<=BlueCSnL.Goti.y+BlueCSnL.Goti.h && InstantSnL==true){
								modifierSnL(roll,runsnl,1);
								snake();
								ladder();
								CutcheckSnL(roll);
								if(winningcolor !=0){return;}
								if (movemade=true)
								{
									InstantSnL=false;
									roll=0;
								}
							}
						
					}
				
					
					PieceSnLplacementSnL();
					
					

					//Bottom viewport


					SDL_RenderSetViewport( gRenderer, &ConsoleViewport );
					SDL_RenderCopy( gRenderer, gConsole, NULL, NULL );
					if(InstantSnL==true){
					SDL_RenderSetViewport(gRenderer,&RollMsg);
					switch (runsnl){
						case 1:
						SDL_RenderCopy( gRenderer, gGreenRollMessage, NULL, NULL );
						break;
						case 2:
						SDL_RenderCopy( gRenderer, gYellowRollMessage, NULL, NULL );
						break;
						case 3:
						SDL_RenderCopy( gRenderer, gBlueRollMessage, NULL, NULL );
						break;
						case 4:
						SDL_RenderCopy( gRenderer, gRedRollMessage, NULL, NULL );

						break;						
					}
					SDL_RenderSetViewport(gRenderer,&RollNum);
					switch (runsnl){
						case 1:
							switch (roll){
								case 1:
								SDL_RenderCopy( gRenderer, Greenroll1, NULL, NULL );
								break;
								case 2:
								SDL_RenderCopy( gRenderer, Greenroll2, NULL, NULL );
								break;
								case 3:
								SDL_RenderCopy( gRenderer, Greenroll3, NULL, NULL );
								break;
								case 4:
								SDL_RenderCopy( gRenderer, Greenroll4, NULL, NULL );
								break;
								case 5:
								SDL_RenderCopy( gRenderer, Greenroll5, NULL, NULL );
								break;
								case 6:
								SDL_RenderCopy( gRenderer, Greenroll6, NULL, NULL );
								break;
							}
						break;
						case 2:
						switch (roll){
								case 1:
								SDL_RenderCopy( gRenderer, Yellowroll1, NULL, NULL );
								break;
								case 2:
								SDL_RenderCopy( gRenderer, Yellowroll2, NULL, NULL );
								break;
								case 3:
								SDL_RenderCopy( gRenderer, Yellowroll3, NULL, NULL );
								break;
								case 4:
								SDL_RenderCopy( gRenderer, Yellowroll4, NULL, NULL );
								break;
								case 5:
								SDL_RenderCopy( gRenderer, Yellowroll5, NULL, NULL );
								break;
								case 6:
								SDL_RenderCopy( gRenderer, Yellowroll6, NULL, NULL );
								break;
							}
						break;
						case 3:
						switch (roll){
								case 1:
								SDL_RenderCopy( gRenderer, Blueroll1, NULL, NULL );
								break;
								case 2:
								SDL_RenderCopy( gRenderer, Blueroll2, NULL, NULL );
								break;
								case 3:
								SDL_RenderCopy( gRenderer, Blueroll3, NULL, NULL );
								break;
								case 4:
								SDL_RenderCopy( gRenderer, Blueroll4, NULL, NULL );
								break;
								case 5:
								SDL_RenderCopy( gRenderer, Blueroll5, NULL, NULL );
								break;
								case 6:
								SDL_RenderCopy( gRenderer, Blueroll6, NULL, NULL );
								break;
							}
						break;
						case 4:
						switch (roll){
								case 1:
								SDL_RenderCopy( gRenderer, Redroll1, NULL, NULL );
								break;
								case 2:
								SDL_RenderCopy( gRenderer, Redroll2, NULL, NULL );
								break;
								case 3:
								SDL_RenderCopy( gRenderer, Redroll3, NULL, NULL );
								break;
								case 4:
								SDL_RenderCopy( gRenderer, Redroll4, NULL, NULL );
								break;
								case 5:
								SDL_RenderCopy( gRenderer, Redroll5, NULL, NULL );
								break;
								case 6:
								SDL_RenderCopy( gRenderer, Redroll6, NULL, NULL );
								break;
							}
						break;						
					}
					}
					//Render texture to screen
					
					
					
					SDL_RenderSetViewport( gRenderer, &Console );
					
					switch(runsnl){
					case 1:
					if(InstantSnL==false){
					SDL_RenderCopy( gRenderer, gGreenConsole, NULL, NULL );
					}else{
						SDL_RenderCopy( gRenderer, gGreenContn, NULL, NULL );
					}
					break;
					case 2:
					if(InstantSnL==false){
					SDL_RenderCopy( gRenderer, gYellowConsole, NULL, NULL );
					}else{
						SDL_RenderCopy( gRenderer, gYellowContn, NULL, NULL );
					}
					break;
					case 4:
					if(InstantSnL==false){
					SDL_RenderCopy( gRenderer, gRedConsole, NULL, NULL );
					}else{
						SDL_RenderCopy( gRenderer, gRedContn, NULL, NULL );
					}
					break;
					case 3:
					if(InstantSnL==false){
					SDL_RenderCopy( gRenderer, gBlueConsole, NULL, NULL );
					}else{
						SDL_RenderCopy( gRenderer, gBlueContn, NULL, NULL );
					}
					break;
					default:
					SDL_RenderCopy( gRenderer, gWelcomeConsole, NULL, NULL );
					}

				
					//Update screen
					SDL_RenderPresent( gRenderer );
				}

				
				
			}
		
	}
	

	//Free resources and close SDL
	close();

	return ;
}
int main( int argc, char* args[] )
{
	Uint32 mousestate;
	int mousex,mousey;
	//your code here definations only
	SDL_Rect PLAYBTNN;

	PLAYBTNN.x = screen_width/4;
	PLAYBTNN.y = 3*screen_height/10;
	PLAYBTNN.h= screen_height/10;
	PLAYBTNN.w=screen_width/2;

	SDL_Rect RULES;
	RULES.x = screen_width/4;
	RULES.y = 5*screen_height/10;
	RULES.h = screen_height/10;
	RULES.w =screen_width/2;

	SDL_Rect EXIT;
	EXIT.x = screen_width/4;
	EXIT.y = 7*screen_height/10;
	EXIT.h= screen_height/10;
	EXIT.w=screen_width/2;
	SDL_Rect LUDO;
	LUDO.x = screen_width/4;
	LUDO.y = 3*screen_height/10;
	LUDO.h = screen_height/10;
	LUDO.w = screen_width/2;

	SDL_Rect SNL;
	SNL.x = screen_width/4;
	SNL.y = 6*screen_height/10;
	SNL.h = screen_height/10;
	SNL.w = screen_width/2;
	SDL_Rect MenuBg;
	MenuBg.x=0;
	MenuBg.y=0;
	MenuBg.h=screen_height;
	MenuBg.w=screen_width;
	SDL_Rect BackButton;
	BackButton.x=7*screen_width/10;
	BackButton.y=7*screen_height/10;
	BackButton.h=screen_height/10;
	BackButton.w=screen_width/10;

	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						screenstate=4;
					}
					mousestate=SDL_GetMouseState(&mousex,&mousey);
					//Update screen
					SDL_RenderPresent( gRenderer );
					SDL_RenderClear( gRenderer );
					SDL_SetRenderDrawColor(gRenderer,0000,0000,0000,0000);

					switch(screenstate)
					{
						case 1:
							SDL_RenderSetViewport( gRenderer, &MenuBg );
							SDL_RenderCopy( gRenderer,Bckround , NULL, NULL );
							SDL_RenderSetViewport( gRenderer, &PLAYBTNN );
							SDL_RenderCopy( gRenderer,Pybtn, NULL, NULL );
							SDL_RenderSetViewport( gRenderer, &RULES );
							SDL_RenderCopy( gRenderer, Htp, NULL, NULL );
							SDL_RenderSetViewport( gRenderer, &EXIT );
							SDL_RenderCopy( gRenderer,Ext , NULL, NULL );

							if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=PLAYBTNN.x&&mousex<=PLAYBTNN.x+PLAYBTNN.w&&mousey>=PLAYBTNN.y&&mousey<=PLAYBTNN.y+PLAYBTNN.h )
								{
									screenstate=2;
								}
							if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=RULES.x&&mousex<=RULES.x+RULES.w&&mousey>=RULES.y&&mousey<=RULES.y+RULES.h )
								{
									screenstate=3;
								}
							if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=EXIT.x&&mousex<=EXIT.x+EXIT.w&&mousey>=EXIT.y&&mousey<=EXIT.y+EXIT.h )
								{
									screenstate=4;
								}
						break;
						case 2:
							SDL_RenderSetViewport( gRenderer, &MenuBg );
							SDL_RenderCopy( gRenderer,Bckround , NULL, NULL );
							SDL_RenderSetViewport( gRenderer, &LUDO );
							SDL_RenderCopy( gRenderer,LudoPic, NULL, NULL );
							SDL_RenderSetViewport( gRenderer, &SNL );
							SDL_RenderCopy( gRenderer, SnLdr, NULL, NULL );
							SDL_RenderSetViewport( gRenderer, &BackButton );
							SDL_RenderCopy( gRenderer,back, NULL, NULL );
							if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=LUDO.x&&mousex<=LUDO.x+LUDO.w&&mousey>=LUDO.y&&mousey<=LUDO.y+LUDO.h )
								{
									screenstate=5;
								}
							if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=SNL.x&&mousex<=SNL.x+SNL.w&&mousey>=SNL.y&&mousey<=SNL.y+SNL.h )
								{
									screenstate=6;
								}
							if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=BackButton.x&&mousex<=BackButton.x+BackButton.w&&mousey>=BackButton.y&&mousey<=BackButton.y+BackButton.h )
								{
									screenstate=1;
								}
							break;
						case 3:
							SDL_RenderSetViewport( gRenderer, &MenuBg );
							SDL_RenderCopy( gRenderer,Bckround , NULL, NULL );
							SDL_RenderSetViewport( gRenderer, &LUDO );
							SDL_RenderCopy( gRenderer,LudoPic, NULL, NULL );
							SDL_RenderSetViewport( gRenderer, &SNL );
							SDL_RenderCopy( gRenderer, SnLdr, NULL, NULL );
							SDL_RenderSetViewport( gRenderer, &BackButton );
							SDL_RenderCopy( gRenderer,back, NULL, NULL );
							if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=LUDO.x&&mousex<=LUDO.x+LUDO.w&&mousey>=LUDO.y&&mousey<=LUDO.y+LUDO.h )
								{
									screenstate=7;
								}
							if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=SNL.x&&mousex<=SNL.x+SNL.w&&mousey>=SNL.y&&mousey<=SNL.y+SNL.h )
								{
									screenstate=8;
								}
							if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=BackButton.x&&mousex<=BackButton.x+BackButton.w&&mousey>=BackButton.y&&mousey<=BackButton.y+BackButton.h )
								{
									screenstate=1;
								}
							break;
						case 4:
							SDL_RenderSetViewport( gRenderer, &MenuBg );
							SDL_RenderCopy( gRenderer,exitscrn , NULL, NULL );
							if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=MenuBg.x&&mousex<=MenuBg.x+MenuBg.w&&mousey>=MenuBg.y&&mousey<=MenuBg.y+MenuBg.h )
									{
										quit=true;
									}
							
							
							
							break;
						case 5:
							LudoGame();
							break;
						case 6:
							SnLGame();
							if(winningcolor !=0){screenstate=9;}
							break;
						case 7:
							SDL_RenderSetViewport( gRenderer, &MenuBg );
							SDL_RenderCopy( gRenderer,Ludoinstrn , NULL, NULL );
							if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=MenuBg.x&&mousex<=MenuBg.x+MenuBg.w&&mousey>=MenuBg.y&&mousey<=MenuBg.y+MenuBg.h )
									{
										screenstate=1;
									}
							break;
						case 8:
							SDL_RenderSetViewport( gRenderer, &MenuBg );
							SDL_RenderCopy( gRenderer,SnLinstrn , NULL, NULL );
							if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=MenuBg.x&&mousex<=MenuBg.x+MenuBg.w&&mousey>=MenuBg.y&&mousey<=MenuBg.y+MenuBg.h )
									{
										screenstate=1;
									}
							break;
							case 9:
							Winner(winningcolor);
							if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=MenuBg.x&&mousex<=MenuBg.x+MenuBg.w&&mousey>=MenuBg.y&&mousey<=MenuBg.y+MenuBg.h )
									{
										screenstate=1;
										runsnl=0;
									}

							default:
							break;
					}


					}
					
				}

				//Clear screen
				
				
				
			}
		}
	
	
	//Free resources and close SDL
	close();
	

				
				

	return 0;
}