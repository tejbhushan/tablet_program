#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
//#include<stick_hero_game.h>
#include<2_cars_game.h>
struct date d;
struct time t1;
char msg[20],f='t',f1='f',f2='f',ct;
int limx,limy,tx,tbutton,xs,h=0,xa,ya;
float xr;
union REGS i,o;

void showmouseptr()
{
i.x.ax=1;
int86(0X33,&i,&o);
}
void getmousepos(int *button,int *x,int *y)
{
i.x.ax=3;
int86(0X33,&i,&o);
*button=o.x.bx;
*x=o.x.cx;
*y=o.x.dx;
}
void assistivetouch()
{
 setcolor(WHITE);
 rectangle(limx/2-30,limy/2-30,limx/2+30,limy/2+30);
}

void defaults()
{
 setcolor(WHITE);
 rectangle(0,0,limx,limy);
 rectangle(0,limy/40,limx,limy/10);
 sprintf(msg,"apps %c",'\n');
 outtextxy(30,20,msg);
 line(limx/3,limy/40,limx/3,limy/10);
 sprintf(msg,"widgets %c",'\n');
 outtextxy(limx/3+30,20,msg);
 line(2*limx/3,limy/40,2*limx/3,limy/10);
 sprintf(msg,"dwn(s) %c",'\n');
 outtextxy(2*limx/3+30,20,msg);
 rectangle(0,limy-20,limx,limy);
 rectangle(limx/2-30,limy-20,limx/2+30,limy);
 rectangle(limx/2-70,limy-20,limx/2-30,limy);
 rectangle(limx/2+30,limy-20,limx/2+70,limy);
 rectangle(xa,ya,limx,limy/2+10);
}

void shortcut(int t)
{
 rectangle(0,0,t,limy-20);
 sprintf(msg,"widgets %c",'\n');
 outtextxy(limx/3+30,20,msg);
 line(2*limx/3,0,2*limx/3,limy/10);
 sprintf(msg,"dwn(s) %c",'\n');
 outtextxy(2*limx/3+30,20,msg);
 rectangle(limx/3,0,limx,limy/10);
 rectangle(0,limy-20,limx,limy);
 rectangle(limx/2-30,limy-20,limx/2+30,limy);
 rectangle(limx/2-70,limy-20,limx/2-30,limy);
 rectangle(limx/2+30,limy-20,limx/2+70,limy);
 line(0,limy/6,t,limy/6);
 line(0,limy/3,t,limy/3);
 line(0,limy/2,t,limy/2);
 line(0,4*limy/6,t,4*limy/6);
}
void notifybar(int t)
{
 gettime(&t1);
 sprintf(msg,"%2d|%02d|%02d",t1.ti_hour,t1.ti_min,t1.ti_sec);
 outtextxy(limx/16-7,limy/55,msg);
 getdate(&d);
 sprintf(msg,"%d|%d|%d",d.da_mon,d.da_day,d.da_year);
 outtextxy(limx/16,limy/25,msg);
 rectangle(0,0,limx,t);
 rectangle(0,0,limx,limy/15);
 line(4*limx/5,0,4*limx/5,limy/15);
 line(limx/4,0,limx/4,limy/15);
 line(4*limx/5+3,limy/45,limx-3,limy/45);
 line(4*limx/5+3,2*limy/45,limx-3,2*limy/45);
 rectangle(limx/2-30,limy-20,limx/2+30,limy);
 rectangle(limx/2-70,limy-20,limx/2-30,limy);
 rectangle(limx/2+30,limy-20,limx/2+70,limy);
 rectangle(0,limy-20,limx,limy);
 rectangle(0,0,limx,limy);
}
void screen1(float xr)
{
 setcolor(BLUE);
 //setfillstyle(SOLID_FILL,BLUE);
 rectangle(xr,limy/5-20,xr+40,limy/5+20);
 //rectangle(xr,3*limy/5-20,xr+40,3*limy/5+20);
 //rectangle(xr+limx/5,limy/5-20,xr+limx/5+40,limy/5+20);
 //rectangle(xr+limx/5,3*limy/5-20,xr+limx/5+40,3*limy/5+20);
 rectangle(limx/2-20,limy-45,limx/2-10,limy-35);
 setcolor(WHITE);
}
void screen2(float xr)
{
 setcolor(RED);
 //setfillstyle(SOLID_FILL,BLUE);
 rectangle(xr,limy/5-20,xr+40,limy/5+20);
 //rectangle(xr,3*limy/5-20,xr+40,3*limy/5+20);
 //rectangle(xr+limx/5,limy/5-20,xr+limx/5+40,limy/5+20);
 //rectangle(xr+limx/5,3*limy/5-20,xr+limx/5+40,3*limy/5+20);
 rectangle(limx/2+10,limy-45,limx/2+20,limy-35);
 setcolor(WHITE);
}

void main()
{
 int gd=DETECT,gm,button,x,y,t1,t2;
 char c;
 initgraph(&gd,&gm,"..//BGI");
 limx=getmaxx();
 limy=getmaxy();
 xr=limx/5-20;
 xa=limx-20;
 ya=limy/2-10;

 label:

  sprintf(msg," %d @ %d,%d",button,x,y);
  rectangle(0,0,limx,limy/40);
  outtextxy(2,2,msg);
  rectangle(0,0,limx,limy);
  circle(limx/2,limy-40,15);
  rectangle(0,limy-20,limx,limy);
  rectangle(limx/2-30,limy-20,limx/2+30,limy);
  rectangle(limx/2-70,limy-20,limx/2-30,limy);
  rectangle(limx/2+30,limy-20,limx/2+70,limy);
  showmouseptr();
  tbutton=button;
  getmousepos(&button,&x,&y);
  rectangle(xa,ya,limx,limy/2+10);

  if(x>limx-20&&x<limx&&y<limy/2+10&&y>limy/2-10&&button==1)
  {
   assistivetouch();
  }
  if(y==0&&button==1)
  {
   t1=-y;
   for(;button==1&&y<=limy-20;)
   {
    notifybar(y+t1);
    showmouseptr();
    getmousepos(&button,&x,&y);
    delay(100);
    cleardevice();
    if(y!=0)
     f2='t';
    else
     f2='f';
   }
  }

  while(f2=='t')
  {
   notifybar(limy-20);
   getmousepos(&button,&x,&y);
   if(x>3*limx/4&&x<limx&&y<limy/15&&y>0&&button==1)
   {
    rectangle(0,limy/15,limx,2*limy/15);
   }
   if((y==limy-20&&button==1)||(button==1&&x>limx/2-70&&x<limx/2+30&&y>limy-20))
   {
    f2='f';
    t1=limy-20;
    for(;t1>=0;t1--)
    {
     notifybar(t1);
     delay(1);
     cleardevice();
    }
    break;
   }
   delay(10);
   cleardevice();
  }

  delay(10);
  cleardevice();
  if(button==1&&x>limx/2-15&&x<limx/2+15&&y<limy-25&&y>limy-55&&tbutton!=1)
  {
   while(!kbhit())             //loop      loop
   {
    defaults();
    if(f=='t')
    screen1(xr);
    else
    screen2(xr);
    while(f1=='t')
    {
     shortcut(limx/3);
     getmousepos(&button,&x,&y);
     if(x>limx/3&&button==1)
     {
      f1='f';
      t1=limx/3;
      for(;t1>=0;t1--)
      {
       defaults();
       shortcut(t1);
       delay(1);
       cleardevice();
      }
     }
     delay(10);
     cleardevice();
    }
    while(f2=='t')
    {
     notifybar(limy-20);
     getmousepos(&button,&x,&y);
     if(x>3*limx/4&&x<limx&&y<limy/15&&y>0&&button==1)
     {
       rectangle(0,limy/15,limx,2*limy/15);
     }
     if((y==limy-20&&button==1)||(button==1&&x>limx/2-70&&x<limx/2+30&&y>limy-20))
     {
      f2='f';
      t1=limy-20;
      for(;t1>=0;t1--)
      {
       notifybar(t1);
       delay(1);
       cleardevice();
      }
      break;
     }
     delay(50);
     cleardevice();
    }
    tx=x;
    showmouseptr();
    getmousepos(&button,&x,&y);
    if(button==1)
    {
     //button=-1;
     sprintf(msg," left ptr @ %d,%d",x,y);
     outtextxy(2,2,msg);
     if(tx>x&&f=='t')
     {
      t1=xr-x;
      t2=limx-x;
      for(;button==1;)
      {
       showmouseptr();
       getmousepos(&button,&x,&y);
       screen1(x+t1);
       screen2(x+t2-20);
       delay(100);
       cleardevice();
       defaults();
      }
      xr=limx/5-20;
      screen2(xr);
      f='f';
     }
     if(tx<x&&f=='f')
     {
      t1=-limx/2-x;
      t2=xr-x;
      for(;button==1;)
      {
       showmouseptr();
       getmousepos(&button,&x,&y);
       screen1(x+t1);
       screen2(x+t2-20);
       delay(100);
       cleardevice();
       defaults();
      }
      xr=limx/5-20;
      screen1(xr);
      f='t';
     }
     if(x==0)
     {
      t1=-x;
      for(;button==1&&x<=limx/3;)
      {
       shortcut(x+t1);
       showmouseptr();
       getmousepos(&button,&x,&y);
       delay(100);
       cleardevice();
       defaults();
      }
      f1='t';
     }
     if(y==0)
     {
      for(;button==1&&y<=limy-20;)
      {
       notifybar(y);
       showmouseptr();
       getmousepos(&button,&x,&y);
       delay(100);
       cleardevice();
       if(y!=0)
       f2='t';
       else
       f2='f';
      }
     }
     if(x<limx/2+30&&x>limx/2-30&&y<limy&&y>limy-20)
     break;
     if(x>limx/2-70&&x<limx/2-30&&y<limy&&y>limy-20)
     break;
     while((x<limx/2+70&&x>limx/2+30&&y<limy&&y>limy-20)||tbutton==0)
     {
       showmouseptr();
       if(h==0)
       tbutton=0;
       h=1;
       getmousepos(&button,&x,&y);
       tbutton=button;
       cleardevice();
       delay(100);
     }
     h=0;
    }
    else if(button==2)
    {
     //button=-1;
     sprintf(msg," right ptr @ %d,%d",x,y);
     outtextxy(2,2,msg);
     if((x>limx/5-20)&&(x<limx/5+20)&&(y<limy/5+20)&&(y>limy/5-20)&&(f=='t'))//new
     {
      sprintf(msg," tej1 ",x,y);					 //new
      outtextxy(100,100,msg);
      //main1();
     }
     if((x>limx/5-20)&&(x<limx/5+20)&&(y<limy/5+20)&&(y>limy/5-20)&&(f=='f'))//new
     {
      sprintf(msg," tej2 ",x,y);					 //new
      outtextxy(100,100,msg);
      main2();
     }
    }
    else
    {
     //button=-1;
     sprintf(msg," only ptr @ %d,%d ",x,y);
     outtextxy(2,2,msg);
    }
    delay(100);
    cleardevice();
   }
   //getch();
  }
  if(!kbhit())
  goto label;
  getch();
}
