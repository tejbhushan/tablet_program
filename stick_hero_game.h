#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
int score=0;
char ch,con,msg[20];
int ic,limx,ylim;
float x,xl,xp,x1,x2,y,xt,yt;

void levelold()
{
  setcolor(BLUE);
  setfillstyle(SOLID_FILL,BLUE);
  rectangle(xp,ylim/2,xl,ylim);
  floodfill(xp+5,ylim/2+3,BLUE);
  setcolor(WHITE);
  rectangle(xl-5,ylim/2-10,xl-1,ylim/2-1);
}
void levelnew()
{
  setcolor(BLUE);
  setfillstyle(SOLID_FILL,BLUE);
  rectangle(x1,ylim/2,x2,ylim);
  floodfill(x1+5,ylim/2+3,BLUE);
}

void main1()
{
int score=0;
char ch=NULL,con=NULL;
int ic=0,limx=0,ylim=0;
float x=0,xl=0,xp=0,x1=0,x2=0,y=0,xt=0,yt=0;
 int gm,gd=DETECT;
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 limx=getmaxx();
 ylim=getmaxy();
 randomize();
 xp=0;
 x1=180;
 xl=limx/4;
 x2=200;

again:
 cleardevice();
 while(1)//GAME LOOP
 {
   levelold();
   levelnew();


   //CONTROLS
   if(!kbhit())
   {

   }
   else
   {
     ch=getch();

    if(ch=='p')
    {
     break;
    }


    if(ch=='a')
    {
	setcolor(RED);
  //	setfillstyle(SOLID_FILL,1);
	rectangle(xl,ylim/2-1,xl,y=ylim/2-ic);
	ic+=4;
     }
  }
  setcolor(WHITE);
  sprintf(msg,"your score is %d",score);
  outtextxy(400,25,msg);

 }

cleardevice();

for(x=xl;x<xl+ic;x+=1)
 for(y=ylim/2-ic;y<ylim/2;y+=1)
if(pow((x-xl),2)+pow((y-ylim/2),2)==ic*ic)
{
setcolor(RED);
line(xl,ylim/2,x,y);
delay(100);
cleardevice();
}
//getch();

levelold();
levelnew();
setcolor(RED);
rectangle(xl,ylim/2,xl+ic,ylim/2);
//cleardevice();
if(xl+ic<x2&&xl+ic>x1)
{
  score++;
  y=xp;
xp=x1;
x=xl;
xt=xl;
xl=x2;
x1-=150;
x2-=150;
while(x1<x2+20)
x1=rand()%200;
while(x2<x1+20)
x2=rand()%300;
//yt=xl;
//yt=x2;
for(;xp>=0;)
{
setcolor(RED);
rectangle(x,ylim/2,x+ic,ylim/2+1);
setcolor(WHITE);
if(xt<xl-xp)
{
rectangle(xt-5,ylim/2-10,xt-1,ylim/2-1);
xt++;
}
else
{
rectangle(xt-5,ylim/2-10,xt-1,ylim/2-1);
xt--;
}
setcolor(BLUE);
rectangle(y--,ylim/2,x--,ylim);
floodfill(x-1,ylim/2+3,BLUE);
rectangle(xp--,ylim/2,xl--,ylim);
floodfill(xp+2,ylim/2+1,BLUE);
rectangle(x1+xp,ylim/2,x2+xp,ylim);
floodfill(x1+xp+1,ylim/2+1,BLUE);
delay(10);
cleardevice();
}
ic=0;
goto again;
}
else
{
cleardevice();
setcolor(RED);
sprintf(msg,"your score is %d",score);
outtextxy(200,225,msg);
}
getch();

}