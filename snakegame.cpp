/**
 *  This is a simple snakegame written in c++
 *  You can use it or modify it.
 *  Author : "Poetic Flamingo"
 */
 
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<process.h>
#include<stdio.h>
#define  UP 72
#define  DOWN 80
#define  RIGHT 77
#define  LEFT 75

using namespace std;

int length,life,bend_no,len;
char key;

void print();
void gotoxy(int x,int y);
void GotoXY(int x,int y);
void load();
void Border();
void Food();
void Move();
void Up();
void Down();
void Right();
void Left();
void ExitGame();
void Bend();
void record();
int Score();
int Scoreonly();
void Delay(long double k);

struct coordinate
{
	int x,y,direction;
};

typedef struct coordinate coordinate;

coordinate head,bend[500],food,body[30];

int main() // Opening of main() 
{
	system("cls");
	print();
	system("cls");
	load();
	length=12; //length at beginning
	head.x=37; 
	head.y=13;
	head.direction=RIGHT;
	Border();  //print the border
	Food();     //print the food randomly
	life=3;    //max life 
	bend[0]=head;
	Move();
	return 0; // closing the main
}	
	
	void print()
	{
	 system("color 0a");	
     system("title SNAKE GAME"); 	  
	 cout<<"\n\t\t  ******** **    *   ***   *   * *******    ********   ***   **    ** ******* ";
	 cout<<"\n\t\t  **       * *   *  ** **  *  *  *          *         ** **  * *  * * *       ";
	 cout<<"\n\t\t  ******** *  *  * ******* ***   ******     *  ***** ******* *  **  * ******  ";
	 cout<<"\n\t\t        ** *   * * **   ** *  *  *          *      * **   ** *      * *       ";
     cout<<"\n\t\t  ******** *    ** **   ** *   * *******    ******** **   ** *      * ******* ";
	 cout<<"\n\n\t\t\t\t\t\t\t\t\t Written By : Poetic Flamingo";
	 cout<<"\n\n\t\t\t\t\t     Welcome To Mini SnakeGame\n\n";
	 cout<<"\n  [+] This is a simple snakegame which is written in C++";
	 cout<<"\n  [+] You can modify the code as you can and devlop it";
	 cout<<"\n\n\t\t\t                         Game Instructions\n";
	 cout<<"\n  [+] Click the Right,Left,Up or Down arrow to move the snake Right,Left,Up or Down.";
	 cout<<"\n  [+] Your length will get increases as you eat a fruit.";
	 cout<<"\n  [+] You are provided with three life and each time you strike the cross or snake\n\tbody . Your life will decreases by one."; 
	 cout<<"\n  [+] Press 'ESC' to Exit The Game at Any Moment!!!\n\n";
     cout<<"\n Press Any Key To Continue...";
     if(getch()==27)
     exit(0);
     }
    
	void load()
	{   
	    char ch;
		int i,j;
		gotoxy(50,12);
	    cout<<"loading...";
		ch=178;
		gotoxy(45,13);
		for(i=0;i<19;i++)
		{
          for(j=0;j<100000000;j++);	  
    	  cout<<ch;
		  }
	}
	
	void Border()
   {
     system("cls");
     int i;
	 GotoXY(food.x,food.y);   
     cout<<"O";
	 for(i=11;i<109;i++)
	 {
       GotoXY(i,0);
	   cout<<"X";
	   GotoXY(i,27);
       cout<<"X";
	   
	 }	   
	 
     for(i=10;i<110;i++)
    {
     GotoXY(i,1);
     cout<<"X";
	 GotoXY(i,26);
	 cout<<"X";
    
    }
	 
	 for(i=2;i<26;i++)
	 {
		GotoXY(9,i);
        cout<<"X";
        GotoXY(110,i);
        cout<<"X";		
	 }	 
	
     for(i=2;i<27;i++)
    {
     GotoXY(10,i);
     cout<<"X";
     GotoXY(109,i);
     cout<<"X";
    }
     GotoXY(26,6);
	 cout<<"XXXXX";
	 GotoXY(62,7);
	 cout<<"XXXXX";
	 GotoXY(92,6);
	 cout<<"X";
	 GotoXY(92,7);
	 cout<<"X";
	 GotoXY(72,14);
	 cout<<"XXXXX";
	 GotoXY(92,20);
	 cout<<"XXXXX";
	 GotoXY(45,10);
	 cout<<"X";
	 GotoXY(45,11);
	 cout<<"X";
	 GotoXY(45,12);
	 cout<<"X";
	 GotoXY(26,20);
	 cout<<"X";
	 GotoXY(26,21);
	 cout<<"X";
	 GotoXY(26,22);
	 cout<<"XXXX";
	 GotoXY(66,23);
	 cout<<"XX";
	 
	
  }
	
	void Food()
   {
     if(head.x==food.x&&head.y==food.y)
    {
      length++;
      time_t a;
   	  a=time(0);
      srand(a);
      food.x=rand()%109;
      if(food.x<=10)
        food.x+=11;
        food.y=rand()%26;
      if(food.y<=10)
        food.y+=11;
    }
     else
       if(food.x==0)
   {
      food.x=rand()%109;
       if(food.x<=10)
        food.x+=11;
        food.y=rand()%26;
    
	   if(food.y<=10)
        food.y+=11;
    }
   }
   
   void Move()
{
  int a,i;
   do{
      Food();
      fflush(stdin);
	  len=0;
    
	for(i=0;i<30;i++)
	{
	   body[i].x=0;
       body[i].y=0;
      if(i==length)
     break;
    }
    Delay(length);
    Border();
    
	if(head.direction==RIGHT)
        Right();
	else
    if(head.direction==LEFT)
        Left();
    else
    if(head.direction==DOWN)
        Down();
    else
    if(head.direction==UP)
        Up();
    
	 ExitGame();
    
	}while(!kbhit());
	
	 a=getch();
 
  if(a==27)        
  {
    system("cls");
	exit(0);
  }
    key=getch();
    if((key==RIGHT&&head.direction!=LEFT&&head.direction!=RIGHT)||(key==LEFT&&head.direction!=RIGHT&&head.direction!=LEFT)||(key==UP&&head.direction!=DOWN&&head.direction!=UP)||(key==DOWN&&head.direction!=UP&&head.direction!=DOWN))
    {
     bend_no++;
     bend[bend_no]=head;
     head.direction=key;
    
	 if(key==UP)
       head.y--;
    
	 if(key==DOWN)
       head.y++;
    
	 if(key==RIGHT)
       head.x++;
    
	 if(key==LEFT)
       head.x--;
    
	 Move();
    }
    
	 else
     if(key==27)
    {
     system("cls");
     exit(0);
    }
  
    else
    {
     printf("\a");
     Move();
    }
}
   
    void gotoxy(int x,int y)
    {
      COORD coord;
      coord.X = x;
      coord.Y = y;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    }
	
	void GotoXY(int x,int y)
    {
		
     HANDLE a;
     COORD b;
     fflush(stdout);
     b.X = x;
     b.Y = y;
     a = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleCursorPosition(a,b);
    }
	
	void Right()
    {
	 int i;
     for(i=0;i<=(head.x-bend[bend_no].x)&&len<length;i++)
     {
       body[len].x=head.x-i;
       body[len].y=head.y;
       GotoXY(body[len].x,body[len].y);
      {
       if(len==0)
        printf(">");
       else
        printf("O");
      }
       len++;
     }
	   Bend();
      if(!kbhit())
       head.x++;
   }
	
	void Left()
    {
     int i;
    
	 for(i=0;i<=(bend[bend_no].x-head.x)&&len<length;i++)
     {
      GotoXY((head.x+i),head.y);
      {
       if(len==0)
        printf("<");
       else
        printf("O");
      }
      body[len].x=head.x+i;
      body[len].y=head.y;
      len++;
     }
    
	 Bend();
      if(!kbhit())
       head.x--;
   }
   
   void Down()
  {
    int i;
	
    for(i=0;i<=(head.y-bend[bend_no].y)&&len<length;i++)
    {
      GotoXY(head.x,head.y-i);
      {
       if(len==0)
         printf("v");
       else
         printf("O");
        }
       body[len].x=head.x;
       body[len].y=head.y-i;
       len++;
    }
      Bend();
      if(!kbhit())
        head.y++;
   }
   
   void Up()
    {		
     int i;
     for(i=0;i<=(bend[bend_no].y-head.y)&&len<length;i++)
      {
       GotoXY(head.x,head.y+i);
       {
        if(len==0)
         printf("^");
        else
         printf("O");
       }
       body[len].x=head.x;
       body[len].y=head.y+i;
       len++;
      }
      Bend();
       if(!kbhit())
        head.y--;
    }


   void ExitGame()
   {
    int i,check=0;	
	for(i=4;i<length;i++)
	{ 
     if(body[0].x==body[i].x&&body[0].y==body[i].y)
     {
      check++;    
      }
     if(i==length||check!=0)
      break;
    }
	  if(head.x<=10||head.x>=110||head.y<=1||head.y>=26||(head.x==26&&head.y==6)||(head.x==27&&head.y==6)||(head.x==28&&head.y==6)||(head.x==29&&head.y==6)||(head.x==30&&head.y==6)||(head.x==62&&head.y==7)||(head.x==63&&head.y==7)||(head.x==64&&head.y==7)||(head.x==65&&head.y==7)||(head.x==66&&head.y==7)||(head.x==72&&head.y==14)||(head.x==73&&head.y==14)||(head.x==74&&head.y==14)||(head.x==75&&head.y==14)||(head.x==76&&head.y==14)||(head.x==92&&head.y==20)||(head.x==93&&head.y==20)||(head.x==94&&head.y==20)||(head.x==95&&head.y==20)||(head.x==96&&head.y==20)||(head.x==26&&head.y==22)||(head.x==27&&head.y==22)||(head.x==28&&head.y==22)||(head.x==29&&head.y==22)||(head.x==66&&head.y==23)||(head.x==67&&head.y==23)||(head.x==92&&head.y==6)||(head.x==92&&head.y==7)||(head.x==45&&head.y==10)||(head.x==45&&head.y==11)||(head.x==45&&head.y==12)||(head.x==26&&head.y==20)||(head.x==26&&head.y==21)||check!=0)
	 {
      life--;
      if(life>0)
      {
       head.x=42;
       head.y=13;
       bend_no=0;
       head.direction=RIGHT;
       Move();
      }
      else
     {
      system("cls");
      cout<<"\n\n  All The Life Have Been Finished!!!";
      cout<<"\n\n  Press any Key To Quit...";	
      getch();	  
	  record();
	  cout<<"\n Press Any Key To Continue...";
	  getch();
      exit(0);
     }
   }
  }
   void record()
  {
    char plname[20],nplname[20],cha,c;
    int i,j,px;
    
	FILE *info;
    info=fopen("record.txt","a+");    
	getch();
    system("cls");
	cout<<" [+] Enter your name\n  => ";
    scanf("%[^\n]",plname);
    
	for(j=0;plname[j]!='\0';j++)
	{                                   
      nplname[0]=toupper(plname[0]);
      
	  if(plname[j-1]==' ')
	 {
	   nplname[j]=toupper(plname[j]);
       nplname[j-1]=plname[j-1];
	 }
      else
       nplname[j]=plname[j];
    }
      
	 nplname[j]='\0';
     
	 fprintf(info,"Player Name :%s\n",nplname);
     
      time_t mytime;
      mytime = time(NULL);
      fprintf(info,"Played Date:%s",ctime(&mytime));
      fprintf(info,"Score:%d\n",px=Scoreonly());
      for(i=0;i<=50;i++)
      fprintf(info,"%c",'_');
      fprintf(info,"\n");
      fclose(info);
      cout<<" [+] wanna see past records press(y/n)...\n  => ";
      cha=getch();
      system("cls");
      if(cha=='y'){
      info=fopen("record.txt","r");
      do{
        putchar(c=getc(info));
       }while(c!=EOF);
	   cout<<"\n\n\n";
	   }
      fclose(info);
    }
	int Score()
   {
    int score;
	GotoXY(15,28);
    score=length-12;
    cout<<"SCORE : "<<length-12;
	score=length-12;
    GotoXY(100,28);
    cout<<"Life : "<<life;
    return score;
   }
    
	int Scoreonly()
   {
    int score=Score();
     system("cls");
     return score;
   }
    
	void Bend()
    {
     int i,j,diff;
     
	 for(i=bend_no;i>=0&&len<length;i--)
    {
      if(bend[i].x==bend[i-1].x)
      {
       diff=bend[i].y-bend[i-1].y;
      if(diff<0)
       for(j=1;j<=(-diff);j++)
      {
        body[len].x=bend[i].x;
        body[len].y=bend[i].y+j;
        GotoXY(body[len].x,body[len].y);
        cout<<"O";
        len++;
    
	   if(len==length)
        break;
      }
       else
       if(diff>0)
    
       for(j=1;j<=diff;j++)
    {         
	 body[len].x=bend[i].x;
     body[len].y=bend[i].y-j;
     GotoXY(body[len].x,body[len].y);
     cout<<"O";
     len++;
    
	 if(len==length)
     break;
    }
   }
     else
     if(bend[i].y==bend[i-1].y)
    {
      diff=bend[i].x-bend[i-1].x;
      if(diff<0)
       for(j=1;j<=(-diff)&&len<length;j++)
      {
       	body[len].x=bend[i].x+j;
        body[len].y=bend[i].y;
        GotoXY(body[len].x,body[len].y);
        cout<<"O";
        len++;
        if(len==length)
        break;
      }
        else
        if(diff>0)
        for(j=1;j<=diff&&len<length;j++)
       {
         body[len].x=bend[i].x-j;
         body[len].y=bend[i].y;
         GotoXY(body[len].x,body[len].y);
         cout<<"O";
         len++;
         if(len==length)
         break;
       }
    }
   }
  }
	
	void Delay(long double k)
  {
     Score();
     long double i;
     for(i=0;i<=(10000000);i++);
  }