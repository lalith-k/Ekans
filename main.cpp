#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<ctime>

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;

enum Direction{STOP =0, LEFT, RIGHT, UP, DOWN};

Direction dir;

void setup()
{
  gameOver = false;
  dir = STOP;
  x = width/2;
  y = height/2;

//  srand(static_cast<unsigned>(time(0)));

  fruitX = rand() % width;
  fruitY = rand() % height;
  score = 0;

   
}

void draw()
{

    system("cls");
    for(int i=0; i<=width+1; i++)
    {
        std::cout<<"#";
    }
    std::cout<< std::endl;
   
   for(int i=0; i<height; i++)
   {   

    for(int j =0; j< width;j++)
    {

    if(j==0){std::cout<<"#";}

    if(j==x && i==y){std::cout<<"0";} //Head

    else if(i==fruitY && j==fruitX){std::cout<<"F";} //Fruit

    else {

        bool tailPrint = false;        
        for(int k=0; k<nTail; k++)
        {               
            if(tailX[k] ==j && tailY[k] ==i )
            {
                std::cout<<"o";
                tailPrint = true;
            }
            
        }

        if(!tailPrint)std::cout<<" ";
        
        } 

    if(j==width-1){std::cout<<"#";}     
   
   }

   std::cout<<std::endl;
   }



   for(int i=0; i<=width+1; i++)
    {
       std::cout<<"#";
    }
    std::cout<<std::endl;
    std::cout<< "Score : "<< score;

}

void input()
{
  if(_kbhit())
  {
    switch(_getch())
    {
        case 'w':
            dir = UP;
            break;
        case 'a':
            dir = LEFT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'x':
            gameOver = true;
            break;
        default:
            break;                    
    }
  }
}

void logic()
{
    tailX[0] = x;
	tailY[0] = y;
    int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX; //pushing xHead
		tailY[i] = prevY; //pushing yHead
		prevX = prev2X;  //last elemnt of xtail
		prevY = prev2Y;  //last element of ytail

        
	}

    switch(dir) //Direction logic
    {
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        default:
            break;                         
    }
    
    if(x>=width){x = 0;} else if(x < 0) {x = width-1;}
    if(y>=height ){y=0;} else if(y < 0){ y = height -1;}

    if(x==fruitX && y==fruitY) //Score logic
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++; 
    }
   
    for(int i=0; i<nTail; i++)
    {
        if(tailX[i]==x && tailY[i] ==y){gameOver = true;} 
    }

}

int main()
{
    setup();
    while(!gameOver)
    {
        
        draw();
        input();
        logic();
        Sleep(10);
       
    }
   return 0;
}