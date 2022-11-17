

//Using SDL, SDL_image, standard IO, and strings
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <ctime>
#include <iostream>
#include <conio.h>
using namespace std;

bool movemade=false;
int runsnl=0;
int RedposnSnl=0;
int GreenposnSnl=0;
int BlueposnSnl=0;
int YellowposnSnl=0;


//Screen dimension constants
int Dice(){
	return (1+(rand()%6));
};
void modifierSnL(int roll){};
const int SCREEN_WIDTH = 1100;
const int SCREEN_HEIGHT = 600;
const int BOARD_WIDTH=500;
const int BOARD_HEIGHT=500;

//StartSnLs up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees medi	a and shuts down SDL
void close();

//Loads individual image as texture
SDL_Texture* loadTexture( std::string pathSnL );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Current displayed texture
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
SDL_Texture* gRedCSnlonsole = NULL;
SDL_Texture* gBlueCSnLonsole = NULL;
SDL_Texture* gYellowCSnLonsole = NULL;
SDL_Texture* gGreenCSnLonsole = NULL;
SDL_Texture* gWelcomeConsole = NULL;
SDL_Texture* gBlueRollMessage=NULL;
SDL_Texture* gRedRollMessage=NULL;
SDL_Texture* gYellowRollMessage=NULL;
SDL_Texture* gGreenRollMessage=NULL;
SDL_Texture* gBlueCSnLontn=NULL;
SDL_Texture* gRedCSnlontn=NULL;
SDL_Texture* gYellowCSnLontn=NULL;
SDL_Texture* gGreenCSnLontn=NULL;
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
		gWindow =SDL_CreateWindow("Game",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, 1, SDL_RENDERER_ACCELERATED );
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



class Piece{
public:
SDL_Rect Goti;



};

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load texture
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
	gYellowCSnLonsole = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/YellowCSnLonsole.png" );
	gRedCSnlonsole = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/RedCSnlonsole.png" );
	gBlueCSnLonsole = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/BlueCSnLonsole.png" );
	gGreenCSnLonsole = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/GreenCSnLonsole.png" );
	gWelcomeConsole = loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/Welcome.png" );
	gBlueRollMessage=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/BlueRolled.png" );
    gRedRollMessage=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/RedRolled.png" );
    gYellowRollMessage=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/YellowRolled.png" ); 
    gGreenRollMessage=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/GreenRolled.png" );
    gBlueCSnLontn=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/BlueCSnLontn.png" ); 
    gRedCSnlontn=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/RedCSnlontn.png" ); 
    gYellowCSnLontn=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/YellowCSnLontn.png" ); 
    gGreenCSnLontn=loadTexture( "E:/Uni/Projects/FinalDraftforLudo/src/Imagefiles/GreenCSnLontn.png" ); 
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
	if( gBoardSnL == NULL )
	{
		printf( "Failed to load texture image!\n" );
		success = false;
	}


	//Nothing to load
	return success;
}

void close()
{
	//Free loaded image
	SDL_DestroyTexture( gBoardSnL );
	gBoardSnL = NULL;

	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture( std::string pathSnL )

{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified pathSnL
	SDL_Surface* loadedSurface = IMG_Load( pathSnL.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", pathSnL.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", pathSnL.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

Grid SNL(10);	
Piece RedCSnl;
Piece BlueCSnL;
Piece GreenCSnL;
Piece YellowCSnL;
class SpawnSnL
{
	public:
	SDL_Rect Red;
	SDL_Rect Yellow;
	SDL_Rect Green;
	SDL_Rect Blue;
	SpawnSnL()
	{
		Yellow=SNL.Box[0][9];

		Blue=SNL.Box[0][9];


		Red=SNL.Box[0][9];

		Green=SNL.Box[0][9];

	}
	

};
SpawnSnL StartSnL;

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
void modifierSnL(int roll,int color,int piece){
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
		if(movemade=true){
			RedCSnl.Goti=pathSnL.playarea[RedposnSnl];
		}
	}


}

void PieceplacementSnL()
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


int SnLGame( int argc, char* args[] ){

 	bool InstantSnL=false;//false when using dice true when choosing piece
	//StartSnL up SDL and create window
	runsnl=0;
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
			DiceViewport.w = SCREEN_WIDTH-BOARD_WIDTH;
			DiceViewport.h = SCREEN_HEIGHT /3 ;
			SDL_Rect Die;
			Die.x =BOARD_WIDTH+(SCREEN_WIDTH-BOARD_WIDTH)/2;
			Die.y = SCREEN_HEIGHT/6;
			Die.w = (SCREEN_WIDTH-BOARD_WIDTH)/6;
			Die.h = SCREEN_HEIGHT /6 ;
			int roll;
			SDL_Rect ConsoleViewport;
			ConsoleViewport.x = BOARD_WIDTH;
			ConsoleViewport.y = SCREEN_HEIGHT /3 ;
			ConsoleViewport.w = SCREEN_WIDTH-BOARD_WIDTH;
			ConsoleViewport.h = 2*SCREEN_HEIGHT / 3;
			SDL_Rect Console;
			Console.x = BOARD_WIDTH;
			Console.y = (5*SCREEN_HEIGHT /6) ;
			Console.w = SCREEN_WIDTH-BOARD_WIDTH;
			Console.h = SCREEN_HEIGHT / 6;
			SDL_Rect RollMsg;
			RollMsg.x = BOARD_WIDTH;
			RollMsg.y = (ConsoleViewport.y) ;
			RollMsg.w = 2*(SCREEN_WIDTH-BOARD_WIDTH)/3;
			RollMsg.h = SCREEN_HEIGHT / 6;
			SDL_Rect ContnMsg;
			ContnMsg.x = BOARD_WIDTH;
			ContnMsg.y = (ConsoleViewport.y+RollMsg.h) ;
			ContnMsg.w = SCREEN_WIDTH-BOARD_WIDTH;
			ContnMsg.h = SCREEN_HEIGHT / 6;
			SDL_Rect RollNum;
			RollNum.x = BOARD_WIDTH+RollMsg.w;
			RollNum.y = (ConsoleViewport.y) ;
			RollNum.w = (SCREEN_WIDTH-BOARD_WIDTH)/3;
			RollNum.h = SCREEN_HEIGHT / 6;

			//While application is runsnlning
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					
					

					
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				
					
					//Clear screen
					SDL_SetRenderDrawColor( gRenderer, 0000, 0000, 0000, 0000 );
					SDL_RenderClear( gRenderer );

					
					SDL_RenderSetViewport( gRenderer, &DiceViewport );
					SDL_RenderCopy( gRenderer, gDice, NULL, NULL );
					
					SDL_RenderSetViewport( gRenderer, &Die );
					
					mousestate=SDL_GetMouseState(&mousex,&mousey);
					if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=Die.x&&mousex<=Die.x+Die.w&&mousey>=Die.y&&mousey<=Die.y+Die.h &&InstantSnL==false)
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
						
					
							
							if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=RedCSnl.Goti.x&&mousex<=RedCSnl.Goti.x+RedCSnl.Goti.w&&mousey>=RedCSnl.Goti.y&&mousey<=RedCSnl.Goti.y+RedCSnl.Goti.h && InstantSnL==true)
							{							
								modifierSnL(roll,runsnl,1);
								snake();
								ladder();
								CutcheckSnL(roll);
								
								if (movemade=true)
								{
									InstantSnL=false;
									roll=0;
								}
										
							}
						
						
								
					}
					if(runsnl==2){

							if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=YellowCSnL.Goti.x&&mousex<=YellowCSnL.Goti.x+YellowCSnL.Goti.w&&mousey>=YellowCSnL.Goti.y&&mousey<=YellowCSnL.Goti.y+YellowCSnL.Goti.h && InstantSnL==true){
								modifierSnL(roll,runsnl,1);
								snake();
								ladder();
								CutcheckSnL(roll);
								if (movemade=true)
								{
									InstantSnL=false;
									roll=0;
								}
								
							}
						
					}
					if(runsnl==1){

							if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=GreenCSnL.Goti.x&&mousex<=GreenCSnL.Goti.x+GreenCSnL.Goti.w&&mousey>=GreenCSnL.Goti.y&&mousey<=GreenCSnL.Goti.y+GreenCSnL.Goti.h && InstantSnL==true){
								modifierSnL(roll,runsnl,1);
								snake();
								ladder();
								CutcheckSnL(roll);
								if (movemade=true)
								{
									InstantSnL=false;
									roll=0;
								}
							}
						
					}
					if(runsnl==3){

							if (e.type==SDL_MOUSEBUTTONDOWN && mousex>=BlueCSnL.Goti.x&&mousex<=BlueCSnL.Goti.x+BlueCSnL.Goti.w&&mousey>=BlueCSnL.Goti.y&&mousey<=BlueCSnL.Goti.y+BlueCSnL.Goti.h && InstantSnL==true){
								modifierSnL(roll,runsnl,1);
								snake();
								ladder();
								CutcheckSnL(roll);
								if (movemade=true)
								{
									InstantSnL=false;
									roll=0;
								}
							}
						
					}
				
					
					PieceplacementSnL();
					
					

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
					SDL_RenderCopy( gRenderer, gGreenCSnLonsole, NULL, NULL );
					}else{
						SDL_RenderCopy( gRenderer, gGreenCSnLontn, NULL, NULL );
					}
					break;
					case 2:
					if(InstantSnL==false){
					SDL_RenderCopy( gRenderer, gYellowCSnLonsole, NULL, NULL );
					}else{
						SDL_RenderCopy( gRenderer, gYellowCSnLontn, NULL, NULL );
					}
					break;
					case 4:
					if(InstantSnL==false){
					SDL_RenderCopy( gRenderer, gRedCSnlonsole, NULL, NULL );
					}else{
						SDL_RenderCopy( gRenderer, gRedCSnlontn, NULL, NULL );
					}
					break;
					case 3:
					if(InstantSnL==false){
					SDL_RenderCopy( gRenderer, gBlueCSnLonsole, NULL, NULL );
					}else{
						SDL_RenderCopy( gRenderer, gBlueCSnLontn, NULL, NULL );
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
	}
	

	//Free resources and close SDL
	close();

	return 0;
}