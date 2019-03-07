#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
char ch,c1,c2='t',c3='t',c4;
int limx,limy;
long double speed=70;
int roadx1,roadx2,roady;
float chocospeed=0;
int flag=0,flag2=0,flagg1,flagg;
int kalu=0,balu=0,x1,x2,score=0;
char stri[5],st[20];
float y;

void choco()
{
 if(flag==0)
 {
  chocospeed=0;
  kalu=x1;
// sprintf(stri,"%d",kalu);
  flag=1;
  flagg1=0;
 }
  if(kalu==0&&flag==1)
  circle(limx/8,0+chocospeed,5);
  else
  circle(3*limx/8,0+chocospeed,5);

  chocospeed+=8;
  if(chocospeed>=limy)
  flag=0;

  if(flagg1==0)
  if(chocospeed>=350&&chocospeed<=400)
  {  if(kalu==0&&c1=='t')
     {
     score++;
     flagg1=1;
    // chocospeed=0;
     }
     if(kalu==1&&c2=='t')
     {
     score++;
     flagg1=1;
     //chocospeed=0;
     }

  }

  sprintf(stri,"%d",score);
  outtextxy(620,50,stri);

}


void choco2()
{
 // outtextxy(250,250,stri);
 if(flag2==0)
 {
  chocospeed=0;
  balu=x2;
// sprintf(stri,"%d",balu);
  flag2=1;
  flagg=0;
 }
 if(balu==0&&flag2==1)
 circle(5*limx/8,0+chocospeed,5);
 else
 circle(7*limx/8,0+chocospeed,5);

 chocospeed+=8;
 if(chocospeed>=limy)
 flag2=0;

   if(flagg==0)
  if(chocospeed>=350&&chocospeed<=400)
  {  if(balu==0&&c3=='t')
     {
     score++;
     flagg=1;
    // chocospeed=0;
     }
     if(balu==1&&c4=='t')
     {
     score++;
     flagg=1;
    // chocospeed=0;
     }

  }


}

void level()
{

int l=0;

  line(0,0,0,limy);
  line(limx/2,0,limx/2,limy);
  line(limx,0,limx,limy);
  rectangle(roadx1,roady,roadx1+5,(limy/5)+roady);
  floodfill((limx/4)+2,2+roady,WHITE);
   rectangle(roadx1,(2*limy/5)+roady,roadx1+5,y=((3*limy/5)+roady));
 floodfill((limx/4)+2,(2*limy/5)+2+roady,WHITE);
  rectangle(roadx1,(4*limy/5)+roady,roadx1+5,limy+roady);
 floodfill((limx/4)+2,(4*limy/5)+2+roady,WHITE);
   rectangle(roadx1,-(limy/5)+roady,roadx1+5,-limy+roady);
 floodfill((limx/4)+2,-(limy/5)-2+roady,WHITE);
   rectangle(roadx2,roady,roadx2+5,(limy/5)+roady);
   floodfill((3*limx/4)+2,2+roady,WHITE);
   rectangle(roadx2,(2*limy/5)+roady,roadx2+5,y=((3*limy/5)+roady));
 floodfill((3*limx/4)+2,(2*limy/5)+2+roady,WHITE);
   rectangle(roadx2,(4*limy/5)+roady,roadx2+5,limy+roady);
 floodfill((3*limx/4)+2,(4*limy/5)+2+roady,WHITE);
   rectangle(roadx2,-(limy/5)+roady,roadx2+5,-limy+roady);
 floodfill((3*limx/4)+2,-(limy/5)-2+roady,WHITE);

 if(y==limy)
 roady=0;

 switch(ch)
 {
 case 'a':c1='t';
 c2='f';break;
 case 'd':c1='f';
 c2='t';break;
 case 'j':c3='t';c4='f';break;
 case 'l':c3='f';c4='t';break;
 default:break;
 }

 if(c1=='t')
 {
 rectangle((limx/8)-5,350,(limx/8)+5,400);

  floodfill((limx/8)-2,375,WHITE);
  }
 else
{
rectangle((3*limx/8)-5,350,(3*limx/8)+5,400);
 floodfill((3*limx/8)-2,375,WHITE);
}
 if(c3=='t')
{ rectangle((5*limx/8)-5,350,(5*limx/8)+5,400);
  floodfill((5*limx/8)-2,375,WHITE);
 }
 else
 {rectangle((7*limx/8)-5,350,(7*limx/8)+5,400);
 floodfill((7*limx/8)-2,375,WHITE);
  }
}

void main2()
{
 int gm,gd=DETECT;
 char st[10];
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 randomize();
 limx=getmaxx();
 limy=getmaxy();
 roadx1=limx/4;
 roadx2=3*limx/4;
 roady=0;


 while(1)
 {
   if(y==limy)
   {
   x1=rand()%2;
   x2=rand()%2;
   }
 //  sprintf(st,"%d",x);
 //  outtextxy(400,400,st);


   level();
   choco();
   choco2();
   if(speed<=30)
   break;
   delay(speed-29);
   speed=speed-0.01;
   roady=roady+8;

 setbkcolor(BLUE);

   cleardevice();

   if(!kbhit())
   {

   }
   else
   {
    ch=getch();
   }

  if(ch=='e')
  break;
 }
 sprintf(st,"your score is %d ",score);
 outtextxy(320,240,st);
 getch();
}
