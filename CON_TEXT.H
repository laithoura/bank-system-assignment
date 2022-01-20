#ifndef ControlText_H
#define ControlText_H
#define MAX 50
#include<graphics.h>
#include<string.h>
#include<dos.h>
#include<conio.h>

void Cursor(int x, int y,char str[30])
{
  while(!kbhit()){
  setcolor(0);outtextxy(x+textwidth(str),y+2,"|");delay(65);
  setcolor(15);outtextxy(x+textwidth(str),y+2,"|");delay(65);
  }
}

char inputbuf[MAX];
char passControl[50];
void inputPass(int x,int y,int limit,char str[50])
{
 char c;
 int input_pos = 0;
 int the_end = 0;
 strcpy(passControl,"");
 strcpy(inputbuf,"");

 do
 {
   setfillstyle(1,15);
   bar(x,y,x+limit*8,y+10);
   setcolor(0);settextstyle(0,0,1); outtextxy(x,y+2, passControl);Cursor(x,y,passControl);
   c = getch();
   switch (c)
   {
	case 8:
	  if (input_pos)
	  {
	     input_pos--;
	     inputbuf[input_pos] =0;
	     passControl[input_pos]=0;
	  }
	  break;
	case 13:
	  the_end = 1;
	  break;
	case 27:
	  inputbuf[0] = 0;
	  the_end = 1;
	  break;
	default:
	if (input_pos < limit-1 && c!=80&& c!=77&& c!=75&& c!=72){
	 if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' ||c >= '0' && c <= '9' || c==32 || c>='!'&& c<='@'|| c==95)
	  {
	     inputbuf[input_pos] = c;
	     passControl[input_pos]='*';
	     input_pos++;
	     inputbuf[input_pos] = 0;
	     passControl[input_pos]=0;
	  }
	}
   }
 }while (!the_end);
 strcpy(str,inputbuf);
}

void inputText(int x,int y,int limit,char str[50])
{
  char c;
  int the_end = 0;
  int input_pos = 0;
  strcpy(inputbuf,"");
  do
  {
   setfillstyle(1,15);
   bar(x,y,x+limit*8,y+10);
   setcolor(0);settextstyle(0,0,1); outtextxy(x,y+2, inputbuf);Cursor(x,y,inputbuf);
   c = getch();
   switch (c)
   {
	case 8:
	  if (input_pos)
	  {
	     input_pos--;
	     inputbuf[input_pos] =0;
	  }
	  break;
	case 13:
	  the_end = 1;
	  break;
	case 27:
	  inputbuf[0] = 0;
	  the_end = 1;
	  break;
	default:
	 if (input_pos < limit-1 && c!=80&& c!=77&& c!=75&& c!=72){
	   if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c==32)
	   {
	     inputbuf[input_pos] = c;
	     input_pos++;
	     inputbuf[input_pos] = 0;
	   }
	 }
    }
  }while (!the_end);
 strcpy(str,inputbuf);
}

void inputNumber(int x,int y,int limit,char str[50])
{
  char c;
  int the_end = 0;
  int input_pos = 0;
  strcpy(inputbuf,"");

  do
  {
   setfillstyle(1,15);
   bar(x,y,x+limit*8,y+10);
   setcolor(0);settextstyle(0,0,1); outtextxy(x,y+2, inputbuf);Cursor(x,y,inputbuf);
   c = getch();
   switch (c)
   {
	case 8:
	  if (input_pos)
	  {
	     input_pos--;
	     inputbuf[input_pos] =0;
	  }
	  break;
	case 13:
	  the_end = 1;
	  break;
	case 27:
	  inputbuf[0] = 0;
	  the_end = 1;
	  break;
	default:
	 if (input_pos < limit-1 && c!=80&& c!=77&& c!=75&& c!=72){
	    if (c >= '0' && c <= '9' || c=='.')
	    {
	      inputbuf[input_pos] = c;
	      input_pos++;
	      inputbuf[input_pos] = 0;
	    }
	 }
    }
  }while (!the_end);
 strcpy(str,inputbuf);
}

void inputALL(int x,int y,int limit,char str[50])
{
  char c;
  int input_pos = 0;
  int the_end = 0;
  strcpy(inputbuf,"");
  do
  {
    setfillstyle(1,15);
    bar(x,y,x+limit*8,y+10);
    setcolor(0);settextstyle(0,0,1); outtextxy(x,y+2, inputbuf);Cursor(x,y,inputbuf);
    c = getch();
    switch (c)
    {
	case 8:
	  if (input_pos)
	  {
	     input_pos--;
	     inputbuf[input_pos] =0;
	  }
	  break;
	case 13:  the_end = 1;
	  break;
	case 27:
	  inputbuf[0] = 0;
	  the_end = 1;
	  break;
	default:
	  if (input_pos < limit-1 && c!=80&& c!=77&& c!=75&& c!=72){
	   if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' ||c >= '0' && c <= '9'|| c==32)
	   {
	     inputbuf[input_pos] = c;
	     input_pos++;
	     inputbuf[input_pos] = 0;
	   }
	 }
	break;
     }
   }while (!the_end);
 strcpy(str,inputbuf);
}
#endif