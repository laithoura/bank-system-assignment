#include<stdio.h>
#include<graphics.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#include<fstream.h>

FILE *file;
FILE *file9;
FILE *Tree;

struct Login{
  char username[15];
  char password[15];
};
Login Lo;
union REGS t,o;
struct customerType{
	char AccountID[10];
	char Name[15];
	char Gender[7];
	char Phone[10];
	double Money;
	char Date[11];
};
customerType *cus;
char AccID[10],name[15],gender[7],phone[10],data[10],money[10];

struct treeType{
	customerType item;
	treeType *Left;
	treeType *Right;
};
treeType *root=NULL,*p=NULL;
void ShowCustomer(treeType *root,char show[10]);
void ReadFile_into_Tree();
void WriteToFile(treeType *root);
///////////////////////
treeType *Insert(treeType *root,customerType newItem,int &eror);
treeType *searchCustomerbyName(treeType *root,customerType newdata);
treeType *searchCustomerbyAccountID(treeType *root,customerType newdata);
int count(treeType *root);
int countFemale();
double Sum(treeType *root);
treeType *FindMin(treeType *root);
void maxItem(treeType *root,customerType &m);
treeType *DeletebyName(treeType *root,customerType keyItem);
treeType *DeletebyAccountID(treeType *root,customerType keyItem);
void AddMoneybyName(treeType *root,customerType keyItem);
void AddMoneybyAccountID(treeType *root,customerType keyItem);
void MinusMoneybyAccountID(treeType *root,customerType keyItem);
void MinusMoneybyName(treeType *root,customerType keyItem);

void StyleButton();
void OKbutton();
void QuitWindow();
void Interface();
void ClearWindow();
int menu(int menu1);
void logoIn();
void logo();
void welgr();
void Loading();
//////////
void button(char name[15],int x1,int y1,int x2 ,int y2,int c);
void inputbox(int x,int y,int limit,int bkc);
void drawwindow(char head[30],int x1, int y1, int x2, int y2, int c);

int buttonm,xm,ym,gd=9,gm=1,set=1,midx,midy;
//int gd=9,gm=1,midx,midy;


// Mouse
int initmouse();
void showmouse();
void hidemouse();
void setmousepos(int &xpos,int &ypos);
void restrictmouse(int x1,int y1,int x2,int y2);
void getmousepos(int *buttonm,int *x, int *y);



// File Account.................
void CreateAccount(char user[15],char pass[15],int &eror);
void DeleteUser(char user[15],char pass[15],int &eror);
void ChangeUser(char user[15],char pass[15],int &eror);
void InputNewPassword(char user[15]);
void RemoveAllUserAccount();

// Function control input from Keyboard...............
void inputALL(int x,int y,int limit,char str[50]);
void inputPass(int x,int y,int limit,char str[50]);
void inputText(int x,int y,int limit,char str[50]);
void inputNumber(int x,int y,int limit,char str[50]);
// MENU (button).........................
void menuDisplay(int select);
void menuClear_Save_Cancel(int select);
void menuOK_EXIT(int select);
void menuUserAccount(int select);
void MenuControlAccount(char buttonName[15],int select);
void MenuYes_No(int select);

// Interfaces......................
void CreateCustomer(char header[50]);
void Display(int option);
void AboutUs();
void ChooseToDisplay();
void CreateCustomerList();
void ChooseToUpdate();
/// update.customer....................
void ChooseToUpdate_By(char update[10]);
void InputAccountIDtoUpdate(char update[10]);
void InputNametoUpdate(char update[10]);
void InputMoney(char process[10],char money[10],char Tell[10]);

// search...customer................
void InputName_AccIDtoSearch();
void ShowItemSearching(treeType *p);

// Delete...customer..................
void ChooseToDelete();
void InputAccountIDtoDelete();
void InputNametoDelete();

// Security. (User account)...........
void MessageShow(char msg[50]);
void LoginForm();
void AccountProcess();
void CreateUserAccount();
void ChangePassword();
void RemoveAccount();

typedef char option[20];
option MMenu[]={"Create","Insert","Display","Update","Search","Delete","About","Account","Help","Quit"};

void main(){
int menu1=-1;
int i,done;
 ReadFile_into_Tree();
 initgraph(&gd,&gm,"..//BGI");
 clrscr();
 midx=getmaxx()/2;
 midy=getmaxy()/2;
 welgr();
 LoginForm();
   Interface();

 restrictmouse(10,10,getmaxx()-10,getmaxy()-10);
 setmousepos(midx,midy);
 showmouse();
 getmousepos(&buttonm,&xm,&ym);
 while(1)
 {
  showmouse();
  getmousepos(&buttonm,&xm,&ym);
  if(buttonm==1)
  {
      if(xm>=13&&xm<=30&&ym>=10&&ym<=25)
      {
	   setcolor(2);
	   settextstyle(1, 0, 3);
	   outtextxy(15,0,"\360");
	   delay(100);
	   menu(menu1);
	   while(1)
	   {
		i = done = 0;
		showmouse();
		getmousepos(&buttonm,&xm,&ym);
		if(buttonm==1)
		{
		     int X7=20,X90=95;
		     if(xm>=X7&&xm<=X90&&ym>=40&&ym<=60){
		       menu1=0;done=1;
		      }else if(xm>=X7&&xm<=X90&&ym>=60&&ym<=80){
		      menu1=1; done=1;
		      }else if(xm>=X7&&xm<=X90&&ym>=80&&ym<=100){
		       menu1=2;done=1;
		      }else if(xm>=X7&&xm<=X90&&ym>=100&&ym<=120){
		       menu1=3;done=1;
		      }else if(xm>=X7&&xm<=X90&&ym>=120&&ym<=140){
		       menu1=4;done=1;
		      }else if(xm>=X7&&xm<=X90&&ym>=140&&ym<=160){
		       menu1=5;done=1;
		      }else if(xm>=X7&&xm<=X90&&ym>=170&&ym<=190){
		       menu1=6;done=1;
		      }else if(xm>=X7&&xm<=X90&&ym>=190&&ym<=210){
		       menu1=7;done=1;
		      }else if(xm>=X7&&xm<=X90&&ym>=210&&ym<=230){
		       menu1=8;done=1;
		      }else if(xm>=X7&&xm<=X90&&ym>=230&&ym<=250){
		       menu1=9;done=1;
		      }else if(xm>=610&&xm<=628&&ym>=10&&ym<=25){
		       menu1=10;done=1;
		      }else menu1=-1;
		}
		else if(kbhit())
		{
			int key = getch();
			switch (key)
			{
			 case 0: key = getch();
			    switch (key)
			    {
			       case 72:   menu1--;
				  if (menu1 <0) menu1 = 9; break;

			       case 80: menu1++;
				  if (menu1 >9) menu1 = 0; break;
			     }
			   break;
			   case 13: done = 1;
			 }
		   menu(menu1);
		}
	       int dl=150;
	       if(done==1){
		       menu(menu1);
		       switch(menu1){
		       case 0: delay(dl);CreateCustomerList();break;
		       case 1: delay(dl);CreateCustomer("Insert Customer List");break;
		       case 2: delay(dl);WriteToFile(root);ReadFile_into_Tree();ChooseToDisplay();break;
		       case 3: delay(dl);ChooseToUpdate();break;
		       case 4: delay(dl);InputName_AccIDtoSearch();break;
		       case 5: delay(dl);ChooseToDelete();break;
		       case 6: delay(dl);AboutUs(); break;
		       case 7: delay(dl);AccountProcess();break;
		       case 8: delay(dl);break;
		       case 9: delay(dl);QuitWindow();break;
		       case 10: delay(dl);QuitWindow();break;

		     }
	       }
	   }// while loop
       }// if click
     if(xm>=610&&xm<=628&&ym>=10&&ym<=25)
     {
	setcolor(2);
	settextstyle(1, 0, 3);
	outtextxy(612,-1,"x");
	delay(50);
	QuitWindow();
     }
   }// buttonm1
  }// loop
}


// Choosing Menu by ARROW KEY......................

void menuClear_Save_Cancel(int select)
{
 setfillstyle(1,0);
 bar(443,243,493,258);
 bar(383,243,433,258);
 bar(323,243,373,258);
 settextstyle(2, 0, 4);
 button("Cancel",440,240,490,256,7);
 button("Save",380,240,430,256,7);
 button("Clear",320,240,370,256,7);
 switch(select){
   case 0: settextstyle(2, 0, 4);  button("Clear",320,240,370,256,2); break;
   case 1: settextstyle(2, 0, 4);  button("Save",380,240,430,256,2); break;
   case 2: settextstyle(2, 0, 4);   button("Cancel",440,240,490,256,2); break;
 }
}
//////// DISPLAY DATA IN TABLE........................
void menuDisplay(int select)
{
 int y1=190,y2=206;
 settextstyle(2, 0, 4);
 button("Preorder",250,y1,310,y2,7);
 button("Inorder",318,y1,377,y2,7);
 button("Postorder",385,y1,445,y2,7);
 setcolor(0);
 settextstyle(1, 0, 2);
 outtextxy(447,106,"x");
  switch(select)
  {
    case 0: settextstyle(1, 0, 2); setcolor(4);outtextxy(447,106,"x"); break;
    case 1: settextstyle(2, 0, 4);  button("Preorder",250,y1,310,y2,2); break;
    case 2: settextstyle(2, 0, 4);  button("Inorder",318,y1,377,y2,2); break;
    case 3: settextstyle(2, 0, 4);  button("Postorder",385,y1,445,y2,2); break;
  }
}

void menuUpdateCustomer(int select)
{
 settextstyle(2, 0, 4);
 int y1=190,y2=206;
 button("Deposit",270,y1,335,y2,7);
 button("Withdraw",353,y1,412,y2,7);
 setcolor(0);
 settextstyle(1, 0, 2);
 outtextxy(447,106,"x");
  switch(select)
  {
    case 0: settextstyle(1, 0, 2); setcolor(4);outtextxy(447,106,"x"); break;
    case 1: settextstyle(2, 0, 4);  button("Deposit",270,y1,335,y2,2); break;
    case 2: settextstyle(2, 0, 4);  button("Withdraw",353,y1,412,y2,2); break;
  }
}
/// Update by. ..NAME OR ACCOUNT IT.................
void menuUpdateByName_AccID(int select)
{
 settextstyle(2, 0, 4);
 int y1=190,y2=206;
 button("By Name",260,y1,335,y2,7);
 button("Account ID",353,y1,427,y2,7);
 setcolor(0);
 settextstyle(1, 0, 2);
 outtextxy(447,106,"x");
  switch(select)
  {
    case 0: settextstyle(1, 0, 2); setcolor(4);outtextxy(447,106,"x"); break;
    case 1: settextstyle(2, 0, 4);  button("By Name",260,y1,335,y2,2); break;
    case 2: settextstyle(2, 0, 4);  button("Account ID",353,y1,427,y2,2); break;
  }
}

// MENU OK AND EIXT.........FROM WINDOWS FORM
void menuOK_EXIT(int select)
{
  int y1=190,y2=206;
  hidemouse();
  settextstyle(2, 0, 4);
  button("OK",328,y1,367,y2,7);
  setcolor(0);
  settextstyle(1, 0, 2);
  outtextxy(447,106,"x");
  showmouse();
  switch(select)
  {
    case 0:hidemouse(); settextstyle(1, 0, 2); setcolor(4);outtextxy(447,106,"x"); break;
    case 1:hidemouse(); settextstyle(2, 0, 4); button("OK",328,y1,367,y2,2); break;
  }
  showmouse();
}

// Y E S  OR  N O................
void MenuYes_No(int select)
{
  hidemouse();
  settextstyle(2, 0, 4);
  button("Yes",280,192,320,208,7);
  button("No",365,192,405,208,7);
  showmouse();
  switch(select)
  {
    case 1: hidemouse(); button("Yes",280,192,320,208,2); break;
    case 0: hidemouse();button("No",365,192,405,208,2); break;
  }
  showmouse();
}

// MENU USER ACCOUNT.........................
void menuUserAccount(int select)
{
  int x1=247,x2=445;
  setcolor(0);
  settextstyle(1, 0, 2);
  outtextxy(444,111,"x");
  settextstyle(2, 0, 4);
  button("Create Account",x1,145,x2,161,7);
  button("Change Password",x1,165,x2,181,7);
  button("Remove Account",x1,185,x2,201,7);
  button("Remove All Accounts",x1,205,x2,221,7);
  switch(select)
  {
    case 0:  settextstyle(1, 0, 2); setcolor(4);outtextxy(444,111,"x"); break;
    case 1: settextstyle(2, 0, 4); button("Create Account",x1,145,x2,161,2); break;
    case 2: settextstyle(2, 0, 4); button("Change Password",x1,165,x2,181,2);break;
    case 3: settextstyle(2, 0, 4); button("Remove Account",x1,185,x2,201,2); break;
    case 4: settextstyle(2, 0, 4); button("Remove All Accounts",x1,205,x2,221,2); break;
  }
}
//.........
void MenuControlAccount(char buttonName[15],int select)
{
  setfillstyle(1,0);
  bar(398,193,448,208);
  bar(338,193,388,208);
  settextstyle(2, 0, 4);
  button(buttonName,335,190,385,206,7);
  button("Cancel",395,190,445,206,7);
  switch(select)
  {
    case 0: button("Cancel",395,190,445,206,2);break;
    case 1: button(buttonName,335,190,385,206,2);break;
  }
}

// Insert OR Create customer list............................
void CreateCustomer(char Header[50])
{
  again:
  customerType newItem;
  struct date da;
  char date9[11];
  getdate(&da);
  sprintf(date9,"%02d/%02d/%d",da.da_day,da.da_mon,da.da_year);
  int k=0,eror=0;

  char sex[2][7];
  strcpy(sex[0],"Male");
  strcpy(sex[1],"Female");
  char ch;
  strcpy(AccID,""); strcpy(name,"");strcpy(gender,"");strcpy(phone,"");strcpy(money,"");;
  int xText=200,xBox=330,LimitLength=20;
  drawwindow(Header,182,90,508,273,9);
  setfillstyle(1,0);
  int xBack=xBox-3;
  bar(xBox+1,110+1,LimitLength*8+6+xBack,110+14);
  bar(xBox+1,135+1,LimitLength*8+6+xBack,135+14);
  bar(xBox+1,160+1,LimitLength*8+6+xBack,160+14);
  bar(xBox+1,185+1,LimitLength*8+6+xBack,185+14);
  bar(xBox+1,210+1,LimitLength*8+6+xBack,210+14);
  menuClear_Save_Cancel(-1);

  settextstyle(0,0,1);
  setcolor(0);
  moveto(xText,113);
  outtext("Account ID     :");inputbox(xBox,110,LimitLength,15);
  moveto(xText,138);
  outtext("Customer's Name:");inputbox(xBox,135,LimitLength,15);
  moveto(xText,163);
  outtext("Gender         :");inputbox(xBox,160,LimitLength,15);
  moveto(xText,188);
  outtext("Phone Number   :");inputbox(xBox,185,LimitLength,15);
  moveto(xText,213);
  outtext("Total Money ($):");inputbox(xBox,210,LimitLength,15);

  // IF STRING IS EMPTY, IT COMES BACK TO INPUT AGAIN............
  Acc9: if(strlen(AccID)==0)inputNumber(xBox+3,110,11,AccID);
  name9:if(strlen(name)==0)inputText(xBox+3,135,16,name);
	k=0;
	setcolor(0);
	outtextxy(xBox+6,163,"<<");
	outtextxy(xBox+75,163,">>");
	setfillstyle(1,15);
	bar(xBox+25,162,xBox+74,170);
	outtextxy(xBox+25,163,sex[0]);
	do{
	    ch=getch();
	    switch(ch)
	    {
	      case 77:k++;if(k>1) k=0;break;
	      case 75:k--;if(k<0) k=1;break;
	    }
	   setfillstyle(1,15);
	   bar(xBox+25,162,xBox+74,170);
	   outtextxy(xBox+25,163,sex[k]);
	}while(ch!=13);
   strcpy(gender,sex[k]);
   phone9: if(strlen(phone)==0)inputNumber(xBox+3,185,11,phone);
   money9: if(strlen(money)==0)inputNumber(xBox+3,210,11,money);
   menuClear_Save_Cancel(1);
   int i,done;
   done = 0;
   i=1;
   do
   {
      int key = getch();
      switch (key)
      {
	case 0: key = getch();
	  switch (key)
	  {
	       case 75:   i--;
		if (i == -1) i = 3-1; break;
	       case 77: i++;
		if (i == 3) i = 0; break;
	  }
	break;
	case 13: done = 1;
      }
      menuClear_Save_Cancel(i);
   }while(!done);
   if(done==1)
   {
     if(i==0) goto again;
     else if(i==2) ClearWindow();
     else if(i==1)
     {
	int a=0,b = 0,c=0,count=0;
	count=strlen(phone);
	if(strlen(AccID)>0 && strlen(name)>0 && strlen(gender)>0 &&strlen(phone)>0 && strlen(money)>0)
	{
	  a=0;b=0;c=0;
	  for(int z=0;z<strlen(AccID);z++)
	  {
	    if(AccID[z]=='0') a=1;
	    else c=1;
	  }
	  if(a==1 && c!=1) {strcpy(AccID,"");goto Acc9;}
	  else
	  {
	    if(count>=9 && count<=10 && phone[0] == '0' && phone[1] != '0') b=0;
	    else {b = 1;strcpy(phone,""); goto phone9;}
	    if(a==1 && c==1 && b!=1 || a!=1 && c==1 && b!=1)
	    {
	      strcpy(newItem.AccountID,AccID);
	      strcpy(newItem.Name,name);
	      strcpy(newItem.Gender,gender);
	      strcpy(newItem.Phone,phone);
	      newItem.Money=strtod(money,NULL);
	      strcpy(newItem.Date,date9);
	      eror=0;
	      root=Insert(root,newItem,eror);//WriteToFile(newItem);
	      if(eror==1){ WriteToFile(root); ReadFile_into_Tree(); MessageShow("Saved Successfully!");}
	      else if(eror==0)
	      {
		strcpy(AccID,"");
		strcpy(name,"");
		strcpy(phone,"");
		strcpy(money,"");
		MessageShow("Account Number aleady exist");goto again;
	      }
	    }
	  }//
	}// if empty string.....................
	else if(strlen(AccID)==0){strcpy(AccID,""); goto Acc9;}
	else if(strlen(name)==0) {strcpy(name,"");goto name9;}
	else if(strlen(phone)==0){strcpy(phone,"");goto phone9;}
	else if(strlen(money)==0){strcpy(money,""); goto money9;}
     }
   }// done
}
// Show data in BTS....................there are 3 methods......
void ChooseToDisplay(){
  drawwindow("Display",232,130,458,223,9);
  settextstyle(2, 0, 5);
  outtextxy(250,140,"Please choose one to show");
  outtextxy(250,160,"customer list.");
  menuDisplay(1);
   int i,done;
   i =1; done = 0;
   do
   {
      int key = getch();
      switch (key)
      {
	 case 0: key = getch();
	    switch (key)
	    {
	       case 75:   i--;
		if (i == -1) i = 4-1; break;
	       case 77: i++;
		if (i == 4) i = 0; break;
	    }
	    break;
	 case 13: done = 1;
      }
      menuDisplay(i);
   }while(!done);

   if(done==1 && i!=0) Display(i);
   ClearWindow();
}

// Show in the table 3 ways...........AFTER CHOSE BY FUNCTION ABOVE
void Display(int option)
{
 int y9=313;
 drawwindow("Display Customer List",104,52,622,332,9);
 setcolor(0);
 settextstyle(1, 0, 2);
 outtextxy(610,28,"x");
 setcolor(0);
 settextstyle(0,0,1);
 outtextxy(452,y9,"Total");
 outtextxy(115,y9,"Customer");
 outtextxy(260,y9,"Female");
 int a=310,b=323;
 // Total
 setfillstyle(1,15);
 bar(500,a,610,b);
 setcolor(0);
 line(611,a-1,611,b+1);
 line(500,b+1,611,b+1);
 setcolor(8);
 line(499,a-1,499,b+1);
 line(499,a-1,611,a-1);
 // Customer
 setfillstyle(1,15);
 bar(185,a,245,b);
 setcolor(0);
 line(245,a-1,245,b+1);
 line(184,b+1,245,b+1);
 setcolor(8);
 line(184,a-1,184,b+1);
 line(184,a-1,246,a-1);
 // Female
 setfillstyle(1,15);
 bar(315,a,376,b);
 setcolor(0);
 line(376,a-1,376,b+1);
 line(314,b+1,376,b+1);
 setcolor(8);
 line(314,a-1,314,b+1);
 line(314,a-1,376,a-1);

 int n=0,F=0;double sum=0;
 char node[5],total[15],F9[5];
 setcolor(0);
 n=count(root);
 sprintf(node,"%d",n);
 outtextxy(107+92,y9,node);
 sum=Sum(root);
 sprintf(total,"%.2lf",sum);
 outtextxy(462+55,y9,total);
//////////////
 F=0;
 F=countFemale();
 sprintf(F9,"%d",F);
 outtextxy(325,y9,F9);
 if(option==1)ShowCustomer(root,"PreOrder");
 else if(option==2)ShowCustomer(root,"InOrder");
 else if(option==3) ShowCustomer(root,"PostOrder");
//  ClearWindow();
}

// Input n number to create list of customer.....................
void CreateCustomerList(){
 int menu1=-1;
 char str[10]="";
 int n=0;
 drawwindow("Create",232,130,458,223,9);
 outtextxy(250,145,"Enter number of customer ");
 outtextxy(250,167,"to create");

 get:
 menuOK_EXIT(menu1);
 inputbox(250+85,165,13,15);
 inputNumber(250+85,165,3,str);
   int done;
	   do{
		done = 0;
		showmouse();
		getmousepos(&buttonm,&xm,&ym);
		if(buttonm==1)
		{
		     if(xm>=328&&xm<=367&&ym>=190&&ym<=206){// ok
		       menu1=1;done=1;
		      }else if(xm>=447&&xm<=462&&ym>=106&&ym<=126){// exit
		      menu1=0; done=1;
		      }else if(xm>=250+85&&xm<=250+85+15*8&&ym>=165&&ym<=178){
		      menu1=2; done=1;
		      }else menu1=-1;
		}
		else if(kbhit())
		{
			int key = getch();
			switch (key)
			{
			 case 0: key = getch();
			    switch (key)
			    {
			       case 75:   menu1--;
				  if (menu1 <0) menu1 = 1; break;

			       case 77: menu1++;
				  if (menu1 >1) menu1 = 0; break;
			     }
			   break;
			   case 13: done = 1;
			 }
			   //   menu(i);
		  menuOK_EXIT(menu1);
		}
	      }while(done!=1);
	   if(done==1)
	   {
	     menuOK_EXIT(menu1);
	     delay(200);
	     if(menu1==0) ClearWindow();
	     else if(menu1==1){
		n=atoi(str);
		if(n>10 || strlen(str)==0) goto get;
		else
		   for(int j=0;j<n;j++)
		   CreateCustomer("Insert Customer List");
	     }
	     else if(menu1==2) goto get;
	   }
}
// Choosing to update money..............................
void ChooseToUpdate(){
  char update[10]="";
  drawwindow("Update",232,130,458,223,9);
  settextstyle(2, 0, 5);
  outtextxy(242,140,"Please choose one to update");
  outtextxy(242,160,"money of customer.");
   menuUpdateCustomer(1);
   int i,done;
   i =1; done = 0;
   do
   {
      int key = getch();
      switch (key)
      {
	 case 0: key = getch();
	    switch (key)
	    {
	       case 75:   i--;
		if (i == -1) i = 3-1; break;
	       case 77: i++;
		if (i == 3) i = 0; break;
	    }
	    break;
	 case 13: done = 1;
      }
      menuUpdateCustomer(i);
   }while(!done);

   if(done==1)
   {
     if(i==0) ClearWindow();
     else if(i==1){strcpy(update,"Deposit");ChooseToUpdate_By(update);}
     else if(i==2){strcpy(update,"Withdraw");ChooseToUpdate_By(update);}

   }
}

void ChooseToUpdate_By(char update[10])
{
 drawwindow(update,232,130,458,223,9);
 settextstyle(2, 0, 5);
 outtextxy(242,150,"Please choose one to update");
   menuUpdateByName_AccID(1);
   int i,done;
   i =1; done = 0;
   do
   {
      int key = getch();
      switch (key)
      {
	 case 00: key = getch();
	    switch (key)
	    {
	       case 75:   i--;
		if (i == -1) i = 3-1; break;
	       case 77: i++;
		if (i == 3) i = 0; break;
	    }
	    break;
	 case 13: done = 1;
      }
      menuUpdateByName_AccID(i);
   }while(!done);

   if(done==1)
   {
	 if(i==1 && strcmp(update,"Deposit")==0) InputNametoUpdate("Deposit");// name
	 else if(i==1 && strcmp(update,"Withdraw")==0) InputNametoUpdate("Withdraw");// name
	 else if(i==2 && strcmp(update,"Deposit")==0) InputAccountIDtoUpdate("Deposit");// id
	 else if(i==2 && strcmp(update,"Withdraw")==0) InputAccountIDtoUpdate("Withdraw");// id
	 else if(i==0) ClearWindow();
   }
}

void InputNametoUpdate(char update[10])
{
 char Name[15];
 customerType keyItem;
 drawwindow(update,232,130,458,223,9);
 settextstyle(2, 0, 5);
 outtextxy(248,140,"Enter customer's name");
 inputname:
 menuOK_EXIT(-1);
 inputbox(250,165,23,15);
 inputText(250,165,16,Name);
 menuOK_EXIT(1);
   int i,done;
   i = 1;done = 0;
   do
   {
      int key = getch();
      switch (key)
      {
	 case 0: key = getch();
	    switch (key)
	    {
	       case 75:   i--;
		if (i == -1) i =1; break;
	       case 77: i++;
		if (i == 2) i = 0; break;
	    }
	    break;
	 case 13: done = 1;
      }
      menuOK_EXIT(i);
   }while(!done);

   if(done==1)
   {
     if(i==0) ClearWindow();
     else if(i==1)
     {    if(strlen(Name)>0)
	  {
	    strcpy(keyItem.Name,Name);
	    p=searchCustomerbyName(root,keyItem);
	    if(p==NULL){ MessageShow("Searching is not found");InputNametoUpdate(update);}
	    else
	    {
	      if(i==1 && strcmp(update,"Deposit")==0 && p!=NULL) { AddMoneybyName(root,keyItem);}
	      else if(i==1 && strcmp(update,"Withdraw")==0 && p!=NULL){ MinusMoneybyName(root,keyItem);}
	    }
	  }
	  else goto inputname;
     }
   }
}

void InputAccountIDtoUpdate(char update[10])
{
 char AccID[10];
 customerType keyItem;
 drawwindow(update,232,130,458,223,9);
 settextstyle(2, 0, 5);
 outtextxy(248,140,"Enter account number (ID)");
 id:
 menuOK_EXIT(-1);
 inputbox(250,165,23,15);
 inputNumber(250,165,11,AccID);
 menuOK_EXIT(1);
   int i,done;
   i =1; done = 0;
   do
   {
      int key = getch();
      switch (key)
      {
	 case 0: key = getch();
	    switch (key)
	    {
	       case 75:   i--;
		if (i == -1) i =1; break;
	       case 77: i++;
		if (i == 2) i = 0; break;
	    }
	    break;
	 case 13: done = 1;
      }
      menuOK_EXIT(i);
   }while(!done);

   if(done==1)
   {
     if(i==0) ClearWindow();
     else if(i==1)
     {    if(strlen(AccID)>0)
	  {
	    strcpy(keyItem.AccountID,AccID);
	    p=searchCustomerbyAccountID(root,keyItem);
	    if(p==NULL){ MessageShow("Searching is not found");InputAccountIDtoUpdate(update);}
	    else if(i==1 && strcmp(update,"Deposit")==0 && p!=NULL) { AddMoneybyAccountID(root,keyItem);}
	    else if(i==1 && strcmp(update,"Withdraw")==0 && p!=NULL){ MinusMoneybyAccountID(root,keyItem);}
	  }
	  else goto id;
     }
   }
}

// Input money to + or -............................
void InputMoney(char process[10],char money[10],char Tell[10])
{
 drawwindow(process,232,130,458,223,9);
 settextstyle(2, 0, 5);
 outtextxy(248,140,"Enter number of money");
 Inputmoney:
 menuOK_EXIT(-1);
 inputbox(250,165,23,15);
 inputNumber(250,165,11,money);
 menuOK_EXIT(1);
   int i,done;
   i =1; done = 0;
   do
   {
      int key = getch();
      switch (key)
      {
	 case 00: key = getch();
	    switch (key)
	    {
	       case 75:   i--;
		if (i == -1) i =2-1; break;
	       case 77: i++;
		if (i == 2) i = 0; break;
	    }
	    break;
	 case 13: done = 1;
      }
      menuOK_EXIT(i);
   }while(!done);

   if(done==1)
   {
     if(i==0){ strcpy(Tell,"close"); ClearWindow(); }
     else if(i==1 && strlen(money)==0) goto Inputmoney;
   }
}

// Search.........................
void InputName_AccIDtoSearch()
{
 char search[15];
 customerType keyItem;
 treeType *p;
 int a=0,b=0;
 drawwindow("Search",232,130,458,223,9);
 settextstyle(2, 0, 5);
 outtextxy(248,140,"Enter Name/Account Number");
 back:
 menuOK_EXIT(-1);
 inputbox(250,165,23,15);
 inputALL(250,165,16,search);
 menuOK_EXIT(1);
   int i,done;
   i = 1;done = 0;
   do
   {
      int key = getch();
      switch (key)
      {
	 case 0: key = getch();
	    switch (key)
	    {
	       case 75:   i--;
		if (i == -1) i =2-1; break;
	       case 77: i++;
		if (i == 2) i = 0; break;
	    }
	    break;
	 case 13: done = 1;
      }
      menuOK_EXIT(i);
   }while(!done);

   if(done==1)
   {
	if(i==0) ClearWindow();
	else if(i==1 && strlen(search)>0)
	{
	   a=0;b=0;
	   for(int i=0;i<strlen(search);i++)
	   {
	     if(search[i]>='0' && search[i]<='9') a=1;
	     else if(search[i]>='a' && search[i]<='z' || search[i]>='A' && search[i]<='Z' || search[i]==32) b=1;
	   }
	   p=NULL;
	   if(a==1 && b!=1)
	   {
	      strcpy(keyItem.AccountID,search);
	      p=searchCustomerbyAccountID(root,keyItem);
	   }
	   else if(a!=1 && b==1)
	   {
	      strcpy(keyItem.Name,search);
	      p=searchCustomerbyName(root,keyItem);
	   }
	   if(p==NULL || a==1 && b==1){ MessageShow("Searching is not found");InputName_AccIDtoSearch();}
	   else ShowItemSearching(p);
	 }
	else goto back;
   }//done..
}

void ShowItemSearching(treeType *p)
{
 int xText=200,xBox=330,LimitLength=20;
 drawwindow("Search",182,90,508,273,9);
 setcolor(0);
 settextstyle(0,0,1);
 moveto(xText,113);
 outtext("Account ID     :");inputbox(xBox,110,LimitLength,15);
 moveto(xText,138);
 outtext("Customer's Name:");inputbox(xBox,135,LimitLength,15);
 moveto(xText,163);
 outtext("Gender         :");inputbox(xBox,160,LimitLength,15);
 moveto(xText,188);
 outtext("Phone Number   :");inputbox(xBox,185,LimitLength,15);
 moveto(xText,213);
 outtext("Total Money ($):");inputbox(xBox,210,LimitLength,15);
 setfillstyle(1,0);
 bar(443,243,493,258);
 bar(383,243,433,258);
 bar(323,243,373,258);
 settextstyle(2, 0, 4);
 button("Cancel",440,240,490,256,7);
 button("Save",380,240,430,256,7);
 button("Clear",320,240,370,256,7);

 char money[20]="";
 sprintf(money,"%.2lf",p->item.Money);

 setcolor(0);
 moveto(xBox+2,110); outtext(p->item.AccountID);
 moveto(xBox+2,135); outtext(p->item.Name);
 moveto(xBox+2,160); outtext(p->item.Gender);
 moveto(xBox+2,185); outtext(p->item.Phone);
 moveto(xBox+2,210); outtext(money);
 do
 {
   settextstyle(2, 0, 4);
   button("Cancel",440,240,490,256,2);
 }while(getch()!=13);
 ClearWindow();
}

/// Form Delete............................
void ChooseToDelete(){
  drawwindow("Delete",232,130,458,223,9);
  settextstyle(2, 0, 5);
  outtextxy(245,140,"Please choose one to Delete");
  outtextxy(245,160,"number of customer.");
  menuUpdateByName_AccID(1);
  int i,done;
  i =1; done = 0;
  do{
     int key = getch();
     switch (key)
     {
       case 00: key = getch();
	  switch (key)
	  {
	     case 75:   i--;
	     if (i == -1) i = 3-1; break;
	     case 77: i++;
	     if (i == 3) i = 0; break;
	  }
       break;
       case 13: done = 1; break;
      }
      menuUpdateByName_AccID(i);
   }while(!done);

   if(done==1)
   {
	if(i==1) InputNametoDelete();
	else if(i==2)InputAccountIDtoDelete();
	else ClearWindow();
   }
 }

void InputNametoDelete()
{
 char Name[15]="";
 customerType keyItem;
 drawwindow("Delete",232,130,458,223,9);
 settextstyle(2, 0, 5);
 outtextxy(248,140,"Enter customer's name");
 back:
 menuOK_EXIT(-1);
 inputbox(250,165,23,15);
 inputText(250,165,16,Name);
 menuOK_EXIT(1);
   int i,done;
   i =1; done = 0;
   do
   {
      int key = getch();
      switch (key)
      {
	 case 0: key = getch();
	    switch (key)
	    {
	       case 75:   i--;
		if (i == -1) i =2-1; break;
	       case 77: i++;
		if (i == 2) i = 0; break;
	    }
	    break;
	 case 13: done = 1;
      }
      menuOK_EXIT(i);
   }while(!done);

   if(done==1)
   {
	if(i==0) ClearWindow();
	else if(i==1 && strlen(Name)>0)
	{
	  strcpy(keyItem.Name,Name);
	  delay(100);root=DeletebyName(root,keyItem);
	}
	else goto back;
  }
}

// Delete ............................
void InputAccountIDtoDelete()
{
 char ID[10]="";
 customerType keyItem;
 drawwindow("Delete",232,130,458,223,9);
 settextstyle(2, 0, 5);
 outtextxy(248,140,"Enter Account Number (ID)");
 back:
 menuOK_EXIT(-1);
 inputbox(250,165,23,15);
 inputNumber(250,165,11,ID);
 menuOK_EXIT(1);
   int i,done;
   i =1; done = 0;
   do
   {
      int key = getch();
      switch (key)
      {
	 case 00: key = getch();
	    switch (key)
	    {
	       case 75:   i--;
		if (i == -1) i =2-1; break;
	       case 77: i++;
		if (i == 2) i = 0; break;
	    }
	    break;
	 case 13: done = 1;
      }
      menuOK_EXIT(i);
   }while(!done);
   if(done==1){
	if(i==0) ClearWindow();
	else if(i==1 && strlen(ID)>0)
	{
	   strcpy(keyItem.AccountID,ID); delay(100);
	   root=DeletebyAccountID(root,keyItem);
	}
	else goto back;
   }
}

void Interface()
{
 struct date da;
 char date[10];
 drawwindow("",10,30,630,340,9);
 setfillstyle(1,7);
 bar(9,8,630,28);
 setcolor(15);
 line(9,8,631,8);
 line(9,8,9,30);
 setcolor(0);
 line(9,28,631,28);
 line(631,8,631,28);
 setcolor(0);
 settextstyle(1, 0, 3);
 outtextxy(15,0,"\360");
 setfillstyle(1,15);
 //bar(13,10,30,25);
 setcolor(0);
 settextstyle(1, 0, 3);
 outtextxy(612,-1,"x");
// bar(610,10,628,25);

  getdate(&da);
  sprintf(date,"%02d/%02d/%d",da.da_day,da.da_mon,da.da_year);
  setcolor(0);
  settextstyle(0, 0, 1);
  outtextxy(510,15,date);
 setcolor(0);
 settextstyle(0,0,1);
 outtextxy(getmaxx()/2-textwidth("National Bank of Cambodia")/2,15,"National Bank of Cambodia");
// logoIn();
}

/// Show message error..............................
void MessageShow(char msg[50])
{
 int L=textwidth(msg);
 int y1=190,y2=206;
 char ch;
 int done=0;
 hidemouse();
 drawwindow("Message",232,130,458,223,9);
 settextstyle(2, 0, 5);
 outtextxy(232+(456-232)/2-L/2-20,150,msg);
 settextstyle(2, 0, 4);
 button("OK",328,y1,367,y2,2);
  showmouse();
   do{
    done=0;
    showmouse();
    getmousepos(&buttonm,&xm,&ym);
    if(buttonm==1){
	if(xm>=328&&xm<=367&&ym>=190&&ym<=206) done=1;
    }
    else if(kbhit()){
	ch=getch();
	if(ch==13) done=1;
     }
 }while(done!=1);
 ClearWindow();
}

void ClearWindow()
{
  hidemouse();
  setfillstyle(1,9);
  bar(103,37,623,333);
  showmouse();
}

void welgr(){
 clrscr();
  int x,y,i;
  x=getmaxx()/2;
  y=getmaxy()/2-10;
  int a=getmaxx()/2-textwidth("<<<                       >>>")/2;
  setbkcolor(3);
  setcolor(BLUE);
  settextstyle(SMALL_FONT, HORIZ_DIR, 10);
  for(int k=1;k<y-100;k++)
  {
	delay(25);
	cleardevice();
	line(x-290,1,x-290,k+10);
	line(x-315+textwidth("WELCOME"),1,x-315+textwidth("WELCOME"),k+10);
	setfillstyle(1,7);
	bar(x-305+3,k+12+3,x-305+textwidth("WELCOME")+4,40+k+4);
	setfillstyle(1,15);
	bar(x-306,k+12,x-304+textwidth("WELCOME"),41+k);
	outtextxy(x-300,k+2,"WELCOME");
	outtextxy(x-299,k+3,"WELCOME");
  }
  outtextxy(x-200,y-50,"TO");
  outtextxy(x-199,y-49,"TO");
  outtextxy(x-140,y-50,"THE");
  outtextxy(x-139,y-49,"THE");
  int z=1;
  do
  {
      delay(100);
      setfillstyle(1,3);
      bar(x-120,y-5,620+10*z,y+60*z);
      settextstyle(SMALL_FONT, HORIZ_DIR, z);
      outtextxy(x-z*10,y+5,"NATIONAL BANK OF");
      outtextxy(x,y+60,"CAMBODIA");
  z++;
 }while(z!=11);
 settextstyle(SMALL_FONT, HORIZ_DIR,10);
 outtextxy(x-99,y+6,"NATIONAL BANK OF");
 outtextxy(x+1,y+61,"CAMBODIA");
 setfillstyle(1,BLUE);
 setcolor(9);
 do{
  settextstyle(0, 0, 1);
  setcolor(BLUE);
  outtextxy(a,getmaxy()-30,"<<<                       >>>");
  setcolor(15);
  outtextxy(a,getmaxy()-30,"    PRESS KEY TO CONTINUE    ");
  delay(250);
  setcolor(BLUE);
  outtextxy(a,getmaxy()-30,"<<<                       >>>");
  setcolor(15);
  outtextxy(a,getmaxy()-30,"  < PRESS KEY TO CONTINUE >  ");
  delay(250);
  setcolor(BLUE);
  outtextxy(a,getmaxy()-30,"<<<                       >>>");
  setcolor(15);
  outtextxy(a,getmaxy()-30," << PRESS KEY TO CONTINUE >> ");
  delay(250);
  setcolor(BLUE);
  outtextxy(a,getmaxy()-30,"<<<                       >>>");
  setcolor(15);
  outtextxy(a,getmaxy()-30,"<<< PRESS KEY TO CONTINUE >>>");
  delay(250);if(kbhit()){getch();break;}
 }while(1);
 setcolor(9);
 for(i=getmaxy()/2+1;i>=0;i--){
  delay(10);
  rectangle(i,i,getmaxx()-i,getmaxy()-i);
 }

}

void logoIn()
{
 setcolor(15);
 for(int k=20;k<25;k++)
 circle(73,26,k);

 setcolor(2);
 circle(73,26,25);
 circle(73,26,19);
 setcolor(2);
 settextstyle(1, 0,1);
 outtextxy(57,14,"NBC");
}

void logo()
{
 setfillstyle(1,BLUE);
 setcolor(15);
 for(int k=48;k<53;k++)
 circle(65,50,k);
 floodfill(201,201,WHITE);
 setcolor(2);
 circle(65,50,53);
 circle(65,50,47);
 setcolor(15);
 settextstyle(4, 0, 5);
 outtextxy(25,23,"NBC");
}

void drawwindow(char head9[50],int x1, int y1, int x2, int y2, int c){
 hidemouse();
 setfillstyle(1,0);
 setfillstyle(1,7);
 bar(x1,y1-14,x2,y1-2);
 setfillstyle(1,c);
 bar(x1,y1,x2,y2);
 setcolor(15);
 line(x1-1,y1-15,x2+1,y1-15);
 line(x1-1,y1-15,x1-1,y2+1);
 setcolor(0);
 line(x2+1,y1-14,x2+1,y2+1);
 line(x1-1,y2+1,x2+1,y2+1);
 line(x1,y1-1,x2,y1-1);
 setcolor(15);
 rectangle(x1+5,y1+5,x2-5,y2-5);
// rectangle(x1+6,y1+6,x2-6,y2-6);
 setcolor(0);
 settextstyle(0,0,1);
 outtextxy((x2+x1-textwidth(head9))/2,y1-12,head9);
 showmouse();
}

void ShowMenu(int x1,int y1,int x2,int y2)
{
 setfillstyle(1,9);
 setcolor(15);
 //hidemouse();
 line(x1,y1,x2,y1);
 line(x1,y1,x1,y2);
 setcolor(0);
 line(x2,y1,x2,y2);
 line(x1,y2,x2,y2);
 bar(x1+1,y1+1,x2-1,y2-1);
 setcolor(15);
 rectangle(x1+5,y1+5,x2-5,y2-5);
}

int menu(int select){
 char menu[11][20]={"Create","Insert","Display","Update","Search","Delete","About","Account","Help","Quit"};
 char date[10];
 hidemouse();
 ShowMenu(15,35,100,334);
 StyleButton();
 setcolor(0);
 settextstyle(0,0,1);
 int x9=30;
 outtextxy(x9,50,menu[0]);
 outtextxy(x9,70,menu[1]);
 outtextxy(x9,90,menu[2]);
 outtextxy(x9,110,menu[3]);
 outtextxy(x9,130,menu[4]);
 outtextxy(x9,150,menu[5]);
 outtextxy(x9,180,menu[6]);
 outtextxy(x9,200,menu[7]);
 outtextxy(x9,223,menu[8]);
 outtextxy(x9,243,menu[9]);
 setcolor(15);
 line(x9-10,170,95,170);
 showmouse();
 int style=1,color=2;
  switch(select){
   case 0: hidemouse();
    setfillstyle(style,color);
    setcolor(0);
    bar(24,45,92,62);
    line(23,44,93,44);
    line(23,44,23,63);
    setcolor(15);
    line(23,63,93,63);
    line(93,44,93,63);
    outtextxy(x9,50,menu[0]);
    break;
   case 1: hidemouse();
    setfillstyle(style,color);
    setcolor(0);
    bar(24,65,92,82);
    line(23,64,93,64);
    line(23,64,23,83);
    setcolor(15);
    line(23,83,93,83);
    line(93,64,93,83);
    outtextxy(x9,70,menu[1]);
    break;
   case 2: hidemouse();
    setfillstyle(style,color);
    setcolor(0);
    bar(24,85,92,103);
    line(23,84,93,84);
    line(23,84,23,103);
    setcolor(15);
    line(23,103,93,103);
    line(93,84,93,103);
    outtextxy(x9,90,menu[2]);
    break;
   case 3: hidemouse();
    setfillstyle(style,color);
    setcolor(0);
    bar(24,105,92,122);
    line(23,104,93,104);
    line(23,104,23,123);
    setcolor(15);
    line(23,123,93,123);
    line(93,104,93,123);
    outtextxy(x9,110,menu[3]);
    break;
   case 4: hidemouse();
    setfillstyle(style,color);
    setcolor(0);
    bar(24,125,92,142);
    line(23,124,93,124);
    line(23,124,23,143);
    setcolor(15);
    line(23,143,93,143);
    line(93,124,93,143);

    outtextxy(x9,130,menu[4]);
    break;
    case 5: hidemouse();
    setfillstyle(style,color);
    setcolor(0);
    bar(24,145,92,162);
    line(23,144,93,144);
    line(23,144,23,163);
    setcolor(15);
    line(23,163,93,163);
    line(93,144,93,163);
    outtextxy(x9,150,menu[5]);
    break;
  case 6: hidemouse();
    setfillstyle(style,color);
    setcolor(0);
    bar(24,175,92,193);
    line(23,174,93,174);
    line(23,174,23,194);
    setcolor(15);
    line(23,194,93,194);
    line(93,174,93,194);
    outtextxy(x9,180,menu[6]);
    break;
  case 7: hidemouse();
    setfillstyle(style,color);
    setcolor(0);
    bar(24,196,92,214);
    line(23,195,93,195);
    line(23,195,23,215);
    setcolor(15);
    line(23,215,93,215);
    line(93,195,93,215);

    outtextxy(x9,200,menu[7]);
    break;
    case 8: hidemouse();
    setfillstyle(style,color);
    setcolor(0);
    bar(24,217,92,235);
    line(23,216,93,216);
    line(23,216,23,236);
    setcolor(15);
    line(23,236,93,236);
    line(93,216,93,236);

    outtextxy(x9,223,menu[8]);
    break;
    case 9: hidemouse();
    setfillstyle(style,color);
    setcolor(0);
    bar(24,238,92,256);
    line(23,237,93,237);
    line(23,237,23,257);
    setcolor(15);
    line(23,257,93,257);
    line(93,237,93,257);
    outtextxy(x9,243,menu[9]);
    break;
  }
  showmouse();
 return select;
}

void OKbutton()
{
 do{
 setcolor(15);
 settextstyle(2, 0, 4);
 button("OK",326,282,366,298,2);
 }while(getch()!=13);
 ClearWindow();
}

void AboutUs()
{
 drawwindow("About Us",177,70,513,313,9);
 int x=190;
 setcolor(WHITE);
 settextstyle(11,0,4);
 //outtextxy(x,90,"This 3	program was created by :");
 outtextxy(x,110,"CS Students,Class SLS, Year II,19th");
 outtextxy(x,90,"Lecturer:    PHAP BOUNG           ");
 outtextxy(x,130,"Group Member:                     ");
 //setcolor(WHITE);
 outtextxy(x,150,"             LAI THOURA           ");
 outtextxy(x,170,"             CHHIM CHANTHOEUN     ");
 outtextxy(x,190,"             MOM SAMBATH          ");
 outtextxy(x,210,"             NHEN SOKKONG         ");
 outtextxy(x,230,"             RY SOPHEALUE         ");
 outtextxy(x,250,"             UM SAREN             ");
 outtextxy(x,270,"             SOK PISEY            ");
 OKbutton();
}

void inputbox(int x,int y,int limit,int bkc)
{
 setfillstyle(1,bkc);
 bar(x-2,y-1,x+limit*8+2,y+12);
 setcolor(0);
 line(x-3,y-2,x-3,y+12);
 line(x-3,y-2,x+limit*8+2,y-2);
}

void button(char name9[50],int x1,int y1,int x2 ,int y2,int c)
{
 setfillstyle(1,c);
 setcolor(15);
 line(x1,y1,x2,y1);
 line(x1,y1,x1,y2);
 setcolor(0);
 line(x2,y1,x2,y2);
 line(x1,y2,x2,y2);
 bar(x1+1,y1+1,x2-1,y2-1);
 outtextxy((x2+x1-textwidth(name9))/2+1,(y2+y1-textheight(name9))/2-2,name9);
}

void StyleButton()
{
    setfillstyle(1,7);
    bar(24,45,92,62);
    setcolor(15);
    line(23,44,93,44);
    line(23,44,23,63);
    setcolor(0);
    line(23,63,93,63);
    line(93,44,93,63);

    bar(24,65,92,82);
    setcolor(15);
    line(23,64,93,64);
    line(23,64,23,83);
    setcolor(0);
    line(23,83,93,83);
    line(93,64,93,83);

    bar(24,85,92,103);
    setcolor(15);
    line(23,84,93,84);
    line(23,84,23,103);
    setcolor(0);
    line(23,103,93,103);
    line(93,84,93,103);

    bar(24,105,92,122);
    setcolor(15);
    line(23,104,93,104);
    line(23,104,23,123);
    setcolor(0);
    line(23,123,93,123);
    line(93,104,93,123);

    bar(24,125,92,142);
    setcolor(15);
    line(23,124,93,124);
    line(23,124,23,143);
    setcolor(0);
    line(23,143,93,143);
    line(93,124,93,143);

    bar(24,145,92,162);
    setcolor(15);
    line(23,144,93,144);
    line(23,144,23,163);
    setcolor(0);
    line(23,163,93,163);
    line(93,144,93,163);

    bar(24,175,92,193);
    setcolor(15);
    line(23,174,93,174);
    line(23,174,23,194);
    setcolor(0);
    line(23,194,93,194);
    line(93,174,93,194);

    bar(24,196,92,215);
    setcolor(15);
    line(23,195,93,195);
    line(23,195,23,215);
    setcolor(0);
    line(23,215,93,215);
    line(93,195,93,215);

    bar(24,217,92,235);
    setcolor(15);
    line(23,216,93,216);
    line(23,216,23,236);
    setcolor(0);
    line(23,236,93,236);
    line(93,216,93,236);

    bar(24,238,92,256);
    setcolor(15);
    line(23,237,93,237);
    line(23,237,23,257);
    setcolor(0);
    line(23,257,93,257);
    line(93,237,93,257);

}

void TextBoxUser_Password(int xBox,int xBack,int xText,int LimitLength)
{
  setfillstyle(1,0);
  bar(xBox+1-5,145+1,LimitLength*8+6+xBack+5,145+15);
  bar(xBox+1-5,170+1,LimitLength*8+6+xBack+5,170+15);
  settextstyle(2, 0, 5);
  setcolor(0);moveto(xText+42,142);
  outtext("Username:");inputbox(xBox-5,145,LimitLength+1,15);
  moveto(xText+42,167);
  outtext("Password:");inputbox(xBox-5,170,LimitLength+1,15);//
}
//...................LOGIN FORM........................

void logoLogin()
{
 int mid=getmaxx()/2;
 int cy=85;
 setcolor(15);
 circle(mid,cy,51);
 setfillstyle(SOLID_FILL,15);
 floodfill(mid,cy,15);
 //set green in area of circle
 setcolor(2);
 circle(mid,cy,45);
 setfillstyle(SOLID_FILL,GREEN);
 floodfill(mid,cy,GREEN);
 setcolor(15);
 settextstyle(4, 0, 5);
 outtextxy(mid-textwidth("NBC")/2+2,cy-27,"NBC");
}
void Buttonlogin(int tc,int tb,int Rtc)
{
  int x1B=getmaxx()/2-30-1,x2B=getmaxx()/2+30-1;
  setfillstyle(1,tb);
  bar(x1B,292,x2B,308);
  setcolor(Rtc);
  rectangle(x1B-1,291,x2B+1,309);
  setcolor(tc);
  settextstyle(2,0,5);
  outtextxy(getmaxx()/2-textwidth("LOG IN")/2,292,"LOG IN");
}

void UsernameText(int xBox1,int xBox2)
{
  setfillstyle(1,15);
  bar(xBox1+2,190+2,xBox2-2,210-2);
  setcolor(8);
  settextstyle(2,0,4);
  outtextxy(xBox1+3,194,"Username");
}
void PasswordText(int xBox1,int xBox2)
{
  setfillstyle(1,15);
  bar(xBox1+2,220+2,xBox2-2,240-2);
  setcolor(8);
  settextstyle(2,0,4);
  outtextxy(xBox1+3,224,"Password");
}
void LoginForm()
{
 setbkcolor(9);
 int correct=0,u=0,p=0,incorrect=0,stop=0;
 int xText=170,xBox=200,LimitLength=15;
// int xBack=xBox-3;
 char user[15]="",pass[15]="";
 setcolor(7);
 for(int j=0;j<3;j++)
 rectangle(216-j,14-j,424+j,334+j);
 setfillstyle(1,1);
 bar(217,15,423,333);
 setfillstyle(1,3);
 bar(227,100,413,323);
 setcolor(7);
 rectangle(227,100,413,323);
 logoLogin();
 setcolor(15);
 settextstyle(2,HORIZ_DIR,7);
 outtextxy(getmaxx()/2-textwidth("Sign In")/2,150,"Sign In");
 // Text box
 setfillstyle(1,15);
 int xBox1=250,xBox2=388;
 bar(xBox1,190,xBox2,210);
 bar(xBox1,220,xBox2,240);
 setcolor(8);
 rectangle(xBox1,190,xBox2,210);
 rectangle(xBox1,220,xBox2,240);
////
 UsernameText(xBox1,xBox2);
 PasswordText(xBox1,xBox2);
 setcolor(0);
 settextstyle(2,0,4);
 outtextxy(388-textwidth("forgot passowrd"),248,"forgot passowrd");
 Buttonlogin(0,15,8);
 // input username...........
 getch();
 User:
 Buttonlogin(0,15,8);
 if(strlen(user)==0)
 {
    setfillstyle(1,15);
    bar(xBox1+2,190+2,xBox2-2,210-2);
    inputText(xBox1+3,194,LimitLength+1,user);
    if(strlen(user)==0) UsernameText(xBox1,xBox2);
 }
 // input Password...........
  Pass:
  Buttonlogin(0,15,8);
  if(strlen(pass)==0)
  {
     setfillstyle(1,15);
     bar(xBox1+2,220+2,xBox2-2,240-2);
     inputPass(xBox1+3,224,LimitLength+1,pass);
     if(strlen(pass)==0) PasswordText(xBox1,xBox2);
   }
    do{
       Buttonlogin(15,2,15);
       setcolor(8);
       rectangle(xBox1,190,xBox2,210);
       rectangle(xBox1,220,xBox2,240);
    }while(getch()!=13);
     if(stop<3)
     {
	file=fopen("Login.txt","rb");
	rewind(file);
	if(file!=NULL)
	{
	   while(fread(&Lo,sizeof(Login),1,file))
	   {
	     if ((strcmp(user,"admin")==0 && strcmp(pass,"admin")==0) || (strcmp(Lo.username,user)==0 && strcmp(Lo.password,pass)==0)){ correct=1;break;}
	     else if ((strcmp(user,"admin")!=0 && strcmp(pass,"admin")==0) || (strcmp(Lo.username,user)!=0 && strcmp(Lo.password,pass)==0)) u=1;
	     else if ((strcmp(user,"admin")==0 && strcmp(pass,"admin")!=0) || (strcmp(Lo.username,user)==0 && strcmp(Lo.password,pass)!=0)) p=1;
	     else if ((strcmp(user,"admin")!=0 && strcmp(pass,"admin")!=0) || (strcmp(Lo.username,user)!=0 && strcmp(Lo.password,pass)!=0)) incorrect=1;
	   }
	   if(correct!=1)
	   {
	      if(u==1)
	      {
		setcolor(4);
		rectangle(xBox1,190,xBox2,210);
		stop++; strcpy(user,""); goto User;
	      }
	      else if( p==1)
	      {
		setcolor(4);
		rectangle(xBox1,220,xBox2,240);
		stop++; strcpy(pass,""); goto Pass;
	      }
	      else if(incorrect==1)
	      {
		 setcolor(4);
		 rectangle(xBox1,190,xBox2,210);
		 rectangle(xBox1,220,xBox2,240);
		 stop++; strcpy(user,""); strcpy(pass,"");goto User;
	      }
	   }
	   else Loading();
	}
	fclose(file);
     }// if stop>3.............
     else {cleardevice();exit(0);}
}

void AccountProcess()
{
 drawwindow("Account",237,135,455,230,9);
 menuUserAccount(1);
   int i,done;
   i =1;done = 0;
   do
   {
      int key = getch();
      switch (key)
      {
	 case 00: key = getch();
	    switch (key)
	    {
	       case 72:   i--;
			  if (i == -1) i = 5-1; break;

	       case 80: i++;
			  if (i ==5) i = 0; break;
	    }
	    break;
	 case 13: done = 1;
      }
      menuUserAccount(i);
   }
   while (!done);
	//menu(menu1);
	ClearWindow();
	int dl=150;
	switch(i){
	case 0: delay(dl);ClearWindow(); break;
	case 1: delay(dl);CreateUserAccount(); break;
	case 2: delay(dl);ChangePassword(); break;
	case 3: delay(dl);RemoveAccount();break;
	case 4: delay(dl);RemoveAllUserAccount();break;
   }
}
////////////////////////////////////////////////////////////////////

void CreateUserAccount()
{
 int eror=-1;
 char user[15]="",pass[15]="";
 int xText=200,xBox=320,LimitLength=15;
 int xBack=xBox-3;
 drawwindow("Create account",232,130,458,223,9);
 MenuControlAccount("Create",-1);
 TextBoxUser_Password(xBox,xBack,xText,LimitLength);
 User:inputText(xBox-5,145,LimitLength+1,user);
 Pass:inputPass(xBox-5,170,LimitLength+1,pass);
 MenuControlAccount("Create",1);
   int i,done;
   i =1; done = 0;
   do
   {
      int key = getch();
      switch (key)
      {
	 case 0: key = getch();
	    switch (key)
	    {
		case 75:   i--;
		if (i == -1) i =1; break;
		case 77: i++;
		if (i == 2) i = 0; break;
	    }
	    break;
	 case 13: done = 1;
      }
       MenuControlAccount("Create",i);
   }while(!done);
   if(done==1)
   {
	if(i==1)
	{
	   if(strlen(user)==0) goto User;
	   else if(strlen(pass)==0) goto Pass;
	   else{
		CreateAccount(user,pass,eror);
		if(eror==0) {MessageShow("Username already exist!");CreateUserAccount();}
		else if(eror==1)MessageShow("Created successfully !");
	    }
	}
	else if(i==0) ClearWindow();
   }
}

void ChangePassword()
{
 int eror=-1;
 char user[15]="",pass[15]="";
 int xText=200,xBox=320,LimitLength=15;
 int xBack=xBox-3;
 back:
 drawwindow("Change Password",232,130,458,223,9);
 MenuControlAccount("OK",-1);
 TextBoxUser_Password(xBox,xBack,xText,LimitLength);
 inputText(xBox-5,145,LimitLength+1,user);
 inputPass(xBox-5,170,LimitLength+1,pass);
 MenuControlAccount("OK",1);
 int i,done;
   i=1;done = 0;
   do
   {
      int key = getch();
      switch (key)
      {
	 case 00: key = getch();
	    switch (key)
	    {
		case 75:   i--;
		if (i == -1) i =1; break;
		case 77: i++;
		if (i == 2) i = 0; break;
	    }
	    break;
	 case 13: done = 1;
      }
       MenuControlAccount("OK",i);
   }while(!done);
   ClearWindow();
   if(done==1)
   {
	if(i==0) ClearWindow();
	else if(i==1)
	{
	  if(strlen(user)==0 || strlen(pass)==0) goto back;
	  else
	  {
	    ChangeUser(user,pass,eror);
	    if(eror==1) InputNewPassword(user);
	    else if(eror==0) MessageShow("Searching not found !");
	  }
	}
   }
}

void RemoveAccount()
{
 char user[30]="",pass[30]="";
 int eror=-1;
 int xText=200,xBox=320,LimitLength=15;
 int xBack=xBox-3;
 drawwindow("Remove Account",232,130,458,223,9);
 MenuControlAccount("OK",-1);
 setfillstyle(1,0);
 TextBoxUser_Password(xBox,xBack,xText,LimitLength);
 User: inputText(xBox,145,LimitLength,user);
 Pass: inputPass(xBox,170,LimitLength,pass);
 MenuControlAccount("OK",1);
 int i,done;
   i =1; done = 0;
   do
   {
      int key = getch();
      switch (key)
      {
	 case 00: key = getch();
	    switch (key)
	    {
	      case 75:   i--;
	      if (i == -1) i =1; break;
	      case 77: i++;
	      if (i == 2) i = 0; break;
	    }
	    break;
	 case 13: done = 1;
      }
      MenuControlAccount("OK",i);
   }while(!done);
   if(done==1)
   {
	if(i==0) ClearWindow();
	else if(i==1)
	{
	       if(strlen(user)==0) goto User;
	       else if(strlen(pass)==0) goto Pass;
	       else
	       {
		 DeleteUser(user,pass,eror);
		 if(eror==0) MessageShow("Searching not found !");
		 else if(eror==1) MessageShow("Removed successfully !");
	       }
	}
   }
}

void DeleteUser(char user[30],char pass[30],int &eror)
{
 int b=0;
		file=fopen("Login.txt","rb");
		file9=fopen("Login9.txt","wb");
		rewind(file);
		b=0;
		while(fread(&Lo,sizeof(Login),1,file)==1)
		{
		  if(strcmp(Lo.username , user)==0 && strcmp(Lo.password,pass)==0) b=1;
		  else fwrite(&Lo,sizeof(Login),1,file9);
		}
		fclose(file);
		fclose(file9);
		remove("Login.txt");
		rename("Login9.txt","Login.txt");
  eror=b;
}//delete

void InputNewPassword(char user[15])
{
 char pass[15]="";
 drawwindow("Change Password",232,130,458,223,9);
 settextstyle(2, 0, 5);
 outtextxy(248,140,"Enter your new password ");
 Pass:
 menuOK_EXIT(-1);
 inputbox(250,165,23,15);
 inputPass(250,165,16,pass);
 menuOK_EXIT(1);
   int i,done;
   i =1; done = 0;
   do
   {
      int key = getch();
      switch (key)
      {
	 case 00: key = getch();
	    switch (key)
	    {
	       case 75:   i--;
		if (i == -1) i =2-1; break;
	       case 77: i++;
		if (i == 2) i = 0; break;
	    }
	    break;
	 case 13: done = 1;
      }
      menuOK_EXIT(i);
   }while(!done);
   if(done==1){
	if(i==0) ClearWindow();
	else if(i==1 && strlen(pass)>0)
	{
		file=fopen("Login.txt","rb");
		rewind(file);
		file9=fopen("Login9.txt","wb");
		while(fread(&Lo,sizeof(Login),1,file))
		{
		  if(strcmp(Lo.username , user)==0) strcpy(Lo.password,pass);
		  fwrite(&Lo,sizeof(Login),1,file9);
		}
		fclose(file);
		fclose(file9);
		remove("Login.txt");
		rename("Login9.txt","Login.txt");
		MessageShow("Changed successfully !");
	}
	else if(strlen(pass)==0) goto Pass;
   }
}

void ChangeUser(char user[15],char pass[15],int &eror)
{
  int b=0;
	file=fopen("Login.txt","rb");
	rewind(file);
	b=0;
	while(fread(&Lo,sizeof(Login),1,file))
	  if(strcmp(Lo.username , user)==0 && strcmp(Lo.password,pass)==0)b=1;
	fclose(file);
	eror=b;
}

void CreateAccount(char user[15],char pass[15],int &eror)
{
  int send=-1;
	int a=0;
	file=fopen("Login.txt","rb");
	rewind(file);
	if(file!=NULL)
	{
	   while(fread(&Lo,sizeof(Login),1,file)==1)
	      if(strcmp(Lo.username,user)==0) {a=1;send=0;break;}
	}
	fclose(file);
	if(a!=1)
	{
	  strcpy(Lo.username,user);
	  strcpy(Lo.password,pass);
	  file=fopen("Login.txt","a+b");
	  rewind(file);
	  fwrite(&Lo,sizeof(Login),1,file);
	  fclose(file);
	  send=1;
	}
	eror=send;
}

void RemoveAllUserAccount()
{
 int menu1=-1;
 drawwindow("Remove account",243,140,447,223,9);
 setcolor(0);
 settextstyle(2, 0, 5);
 outtextxy(432-207+30,155,"Are you sure to remove?");
  int done;
	   MenuYes_No(menu1);
	   do{
		done = 0;
		showmouse();
		getmousepos(&buttonm,&xm,&ym);
		if(buttonm==1)
		{
		     int Y1=192,Y2=208;
		     if(xm>=280&&xm<=320&&ym>=Y1&&ym<=Y2){
		       menu1=1;done=1;
		      }else if(xm>=365&&xm<=405&&ym>=Y1&&ym<=Y2){
		      menu1=0; done=1;
		      }else menu1=-1;
		}
		else if(kbhit())
		{
			int key = getch();
			switch (key)
			{
			 case 0: key = getch();
			    switch (key)
			    {
			       case 75:   menu1--;
				  if (menu1 <0) menu1 = 1; break;

			       case 77: menu1++;
				  if (menu1 >1) menu1 = 0; break;
			     }
			   break;
			   case 13: done = 1;
			 }
			   //   menu(i);
		   MenuYes_No(menu1);
		 }
	      }while(done!=1);
	   if(done==1)
	   {
		MenuYes_No(menu1);
		delay(200);
		if(menu1==0) ClearWindow();
		else if(menu1==1)
		{
		  file=fopen("Login.txt","rb");
		  fclose(file);
		  remove("Login.txt");
		  MessageShow("Removed successfully !");
		}
	   }
}

void QuitWindow()
{
int menu1=-1;
 drawwindow("Exit",243,140,447,223,9);
 setcolor(0);
 settextstyle(2, 0, 5);
 outtextxy(432-207+40,155,"Are you sure to exit?");
 int done;
	   MenuYes_No(menu1);
	   do{
		done = 0;
		showmouse();
		getmousepos(&buttonm,&xm,&ym);
		if(buttonm==1)
		{
		     int Y1=192,Y2=208;
		     if(xm>=280&&xm<=320&&ym>=Y1&&ym<=Y2){
		       menu1=1;done=1;
		      }else if(xm>=365&&xm<=405&&ym>=Y1&&ym<=Y2){
		      menu1=0; done=1;
		      }else menu1=-1;
		}
		else if(kbhit())
		{
			int key = getch();
			switch (key)
			{
			 case 0: key = getch();
			    switch (key)
			    {
			       case 75:   menu1--;
				  if (menu1 <0) menu1 = 1; break;

			       case 77: menu1++;
				  if (menu1 >1) menu1 = 0; break;
			     }
			   break;
			   case 13: done = 1;
			 }
			   //   menu(i);
		   MenuYes_No(menu1);
		 }
	      }while(done!=1);
		if(done==1)
		{
		  MenuYes_No(menu1);
		  delay(200);
		  if(menu1==0) ClearWindow();
		  else if(menu1==1){ WriteToFile(root);cleardevice();exit(0);}
		}
}

void Cursor(int x, int y,char str[30])
{
  while(!kbhit()){
  setcolor(0);outtextxy(x+textwidth(str),y+2,"|");delay(65);
  setcolor(15);outtextxy(x+textwidth(str),y+2,"|");delay(65);
  }
}

#define MAX 50
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
  //strcpy(inputbuf,str);
  //input_pos=strlen(inputbuf);
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
   /*
       the_end=0;
       getmousepos(&buttonm,&xm,&ym);
       if(buttonm==1)
	if(xm>0 && xm<getmaxx()&&ym>0 && ym<getmaxy()) the_end=1;
   */
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

// Insert customer................................................
treeType *Insert(treeType *root,customerType newItem,int &eror)
{
	int a=-1;
	treeType *p,*ptr;
	p=(treeType *)malloc(sizeof(treeType));
	p->item=newItem;
	p->Left=NULL;
	p->Right=NULL;
	if(root==NULL){ a=1; root=p;}
	else
	{
	    ptr=root;
	    while(1)
	    {
		if(strcmp(newItem.AccountID,ptr->item.AccountID)==0){ a=0; break;}
		else
		{
		   a=1;
//		   if(strcmp(newItem.AccountID,ptr->item.AccountID)<0)
		   if(newItem.Money<ptr->item.Money)
		   {
			if(ptr->Left!=NULL) ptr=ptr->Left;
			else {  ptr->Left=p; break; }
		   }
		   else
		   {
		   if(ptr->Right!=NULL) ptr=ptr->Right;
			else{ ptr->Right=p; break; }
		   }
		}// else
	    }// loop
	}
	eror=a;
	return root;
}

//  ...... Deleting by Name .......................................
treeType *DeletebyName(treeType *root,customerType keyItem){
	treeType *Temp;
	if(root==NULL)MessageShow("Searching is not found");//cout<<"Search not found !"<<endl;
	else if(strcmp(keyItem.Name,root->item.Name)<0)root->Left=DeletebyName(root->Left,keyItem);
	else if(strcmp(keyItem.Name,root->item.Name)>0)root->Right=DeletebyName(root->Right,keyItem);
	else if(root->Left&&root->Right){
		Temp=FindMin(root->Right);
		root->item=Temp->item;
		root->Right=DeletebyName(root->Right,root->item);
	}
	else{
		Temp=root;
		if(root->Left==NULL)root=root->Right;
		else if(root->Right==NULL)root=root->Left;
		free(Temp);
		MessageShow("Deleted successfully");
	}
	return root;
}

//  ...... Deleting by Account Number (ID) ...........................
treeType *DeletebyAccountID(treeType *root,customerType keyItem){
	treeType *Temp;
	if(root==NULL) MessageShow("Searching is not found");//cout<<"Search not found !"<<endl;
	else if(strcmp(keyItem.AccountID,root->item.AccountID)<0)root->Left=DeletebyAccountID(root->Left,keyItem);
	else if(strcmp(keyItem.AccountID,root->item.AccountID)>0)root->Right=DeletebyAccountID(root->Right,keyItem);
	else if(root->Left&&root->Right){
		Temp=FindMin(root->Right);
		root->item=Temp->item;
		root->Right=DeletebyAccountID(root->Right,root->item);
	}
	else{
		Temp=root;
		if(root->Left==NULL)root=root->Right;
		else if(root->Right==NULL)root=root->Left;
		free(Temp);
		MessageShow("Deleted successfully");
	}
	return root;
}
// ...........Maximum...........
void maxItem(treeType *root,customerType &m){
	static customerType max=root->item;
	if(root!=NULL){
		if(max.Money<root->item.Money)max=root->item;
		maxItem(root->Left,m);
		maxItem(root->Right,m);
	}
	m=max;
}

//   .......Searching to find minimum node.........
treeType *FindMin(treeType *root){
	if(root==NULL||root->Left==NULL)return root;
	else return FindMin(root->Left);
}


int count(treeType *root)
{
  int c=1;
  if(root==NULL) return 0;
  else
  {
    c+=count(root->Left);
    c+=count(root->Right);
    return c;
  }
}

int countFemale()
{
    int F=0;
    customerType item;
    Tree=fopen("Text.bin","rb");
    rewind(Tree);
    if(Tree!=NULL)
    {
	while(fread(&item,sizeof(customerType),1,Tree))
	if(strcmp(item.Gender,"Female")==0) F++;
    }
    fclose(Tree);
   return F;
}


double Sum(treeType *root)
{
  if(root==NULL) return 0;
  else return (root->item.Money+Sum(root->Left)+Sum(root->Right));
}

void AddMoneybyAccountID(treeType *root,customerType keyItem){
	treeType *p;
	double money=0;
	char money9[20]="",Tell[10]="";
	InputMoney("Deposit",money9,Tell);
	if(strcmp(Tell,"close")!=0)
	{
	   money=strtod(money9,NULL);
	   p=searchCustomerbyAccountID(root,keyItem);
	   p->item.Money=p->item.Money+money;
	   MessageShow("Updated successfully");
	}
}

void MinusMoneybyAccountID(treeType *root,customerType keyItem){
	treeType *p;
	double money=0;
	char money9[20]="",Tell[10]="";
	aa:
	InputMoney("Withdraw",money9,Tell);
	if(strcmp(Tell,"close")!=0)
	{
	  p=searchCustomerbyAccountID(root,keyItem);
	  money=strtod(money9,NULL);
	  if(p->item.Money>=money)
	  {
	    p->item.Money=p->item.Money-money;
	    MessageShow("Updated successfully");
	  }
	  else{	MessageShow("It is greater than yours.");goto aa; }
	}
}

void AddMoneybyName(treeType *root,customerType keyItem){
	treeType *p;
	double money=0;
	char money9[20]="",Tell[10]="";
	InputMoney("Deposit",money9,Tell);
	if(strcmp(Tell,"close")!=0)
	{
	   money=strtod(money9,NULL);
	   p=searchCustomerbyName(root,keyItem);
	   p->item.Money=p->item.Money+money;
	   MessageShow("Updated successfully");
	}
}

void MinusMoneybyName(treeType *root,customerType keyItem){
	treeType *p;
	double money=0;
	char money9[20]="",Tell[10]="";
	aa:
	InputMoney("Withdraw",money9,Tell);
	if(strcmp(Tell,"close")!=0)
	{
	  p=searchCustomerbyName(root,keyItem);
	  money=strtod(money9,NULL);
	  if(p->item.Money>=money)
	  {
	    p->item.Money=p->item.Money-money;
	    MessageShow("Updated successfully");
	  }
	  else{	MessageShow("It is greater than yours."); goto aa; }
	}
}

treeType *searchCustomerbyName(treeType *root,customerType keyItem)
{
	if(root==NULL || strncmp(keyItem.Name,root->item.Name,15)==0) return root;
	else{
		if(strcmp(keyItem.Name,root->item.Name)<0)
		     return searchCustomerbyName(root->Left,keyItem);
		else return searchCustomerbyName(root->Right,keyItem);
	     }
}

treeType *searchCustomerbyAccountID(treeType *root,customerType keyItem){
	if(root==NULL || strcmp(keyItem.AccountID,root->item.AccountID)==0) return root;
	else
	{
	   if(strcmp(keyItem.AccountID,root->item.AccountID)<=0)
		return searchCustomerbyAccountID(root->Left,keyItem);
	   else return searchCustomerbyAccountID(root->Right,keyItem);
	}
}

void Table()
{
 int y1=56,y2=306;
 setcolor(15);
 rectangle(109,y1,617,75);
 rectangle(109,y1,193,y2);
 rectangle(193,y1,321,y2);
 rectangle(321,y1,374,y2);
 rectangle(374,y1,458,y2);
 rectangle(458,y1,532,y2);
 rectangle(532,y1,617,y2);
}
void FieldName()
{
  int y1=56,y2=306;
  setcolor(0);
  settextstyle(0,0,1);
  outtextxy(112,y1+6,"Account ID");
  outtextxy(219,y1+6,"Customer");
  outtextxy(325,y1+6,"Gender");
  outtextxy(393,y1+6,"Phone");
  outtextxy(470,y1+6,"Amount");
  outtextxy(561,y1+6,"Date");

}
// display Preorder,Inorder,and Postorder..................
void DisplayList(customerType cus[],int n)
{
  char money[10];
  int time=19,y1=64;
  int k1=0;
  int j=0,i=0,scroll=0;
  int y11=56,y22=306;

  char ch;
  FieldName();
  if(n>12)
  {
     k1=0;
     j=0;
     scroll=1;
     do{
	k1=0;
	setfillstyle(1,9);
	bar(110,y11+20,616,y22);
	Table();
	setfillstyle(1,7);
       if(scroll<=12) bar(111,y1+scroll*time-4,615,y1+scroll*time+10);
	for(i=j;i<j+12;i++)
	{
	   k1++;
	   setcolor(0);
	   sprintf(money,"%.0lf",cus[i].Money);
	   outtextxy(112,y1+k1*time,cus[i].AccountID);
	   outtextxy(196,y1+k1*time,cus[i].Name);
	   outtextxy(324,y1+k1*time,cus[i].Gender);
	   outtextxy(377,y1+k1*time,cus[i].Phone);
	   outtextxy(462,y1+k1*time,money);
	   outtextxy(536,y1+k1*time,cus[i].Date);
	}
	Table();
	ch=getch();
	if(ch==80)
	{
	   if(scroll<=12)
	   {
	      scroll++;
	      if(scroll>12)
	      {
		scroll=12;j++;
		if(j+12>n) j--;
	      }
	   }
	}
	else if(ch==72)
	{
	  if(scroll>1)
	  {
	      scroll--;
	      if(scroll==1)
	      {
		j--; if(j<0) j++;
	      }
	  }
	}
     }while(ch!=27);
   }
   else
   {
	scroll=1;
      do{
	 setfillstyle(1,9);
	 bar(110,y11+20,616,y22);
	 Table();
	 k1=0;
	 setfillstyle(1,7);
	 if(scroll<=n) bar(111,y1+scroll*time-4,615,y1+scroll*time+10);
	 for(i=0;i<n;i++)
	 {
	   k1++;
	   setcolor(0);
	   sprintf(money,"%.0lf",cus[i].Money);
	   outtextxy(112,y1+k1*time,cus[i].AccountID);
	   outtextxy(196,y1+k1*time,cus[i].Name);
	   outtextxy(324,y1+k1*time,cus[i].Gender);
	   outtextxy(377,y1+k1*time,cus[i].Phone);
	   outtextxy(462,y1+k1*time,money);
	   outtextxy(536,y1+k1*time,cus[i].Date);
	 }
	 Table();
	 ch=getch();
	 if(ch==80){if(scroll<=n) scroll++;if(scroll>n) scroll--; }
	 else if(ch==72){ if(scroll>1) scroll--; else if(scroll<1) scroll++; }
    }while(ch!=27);
   }
}

// read from tree to object..........................
void Pre_WriteToObject(treeType *root,customerType *cus,int &z)
{  customerType item;
  if(root!=NULL)
  {
     cus[z]=root->item; z++;
     Pre_WriteToObject(root->Left,cus,z);
     Pre_WriteToObject(root->Right,cus,z);
  }
}

// read from tree to object..........................
void In_WriteToObject(treeType *root,customerType *cus,int &z)
{  customerType item;
  if(root!=NULL)
  {
     In_WriteToObject(root->Left,cus,z);
     cus[z]=root->item; z++;
     In_WriteToObject(root->Right,cus,z);
  }
}
// read from tree to object..........................
void Post_WriteToObject(treeType *root,customerType *cus,int &z)
{  customerType item;
  if(root!=NULL)
  {
     Post_WriteToObject(root->Left,cus,z);
     Post_WriteToObject(root->Right,cus,z);
     cus[z]=root->item; z++;
  }
}

// show Preorder, Inorder, and Postorder...............
void ShowCustomer(treeType *root,char show[10])
{
  int z=0;
  int n=count(root);
  cus=(customerType *)malloc(n*sizeof(customerType));
  if(strcmp(show,"PreOrder")==0) Pre_WriteToObject(root,cus,z);
  else if(strcmp(show,"InOrder")==0) In_WriteToObject(root,cus,z);
  else if(strcmp(show,"PostOrder")==0) Post_WriteToObject(root,cus,z);
  if(root!=NULL)DisplayList(cus,n);
}

//    file to tree......................
void ReadFile_into_Tree()
{
 customerType item;
 int eror=0;
 Tree=fopen("Text.bin","rb");
 rewind(Tree);
 if(Tree!=NULL)
 {
   while(fread(&item,sizeof(customerType),1,Tree))
   root=Insert(root,item,eror);
  }
 fclose(Tree);
}
//   tree to file...........................
void Write_node(treeType *root,FILE *Tree)
{
  customerType item;
  if(root!=NULL)
  {
	fwrite(&(root->item),sizeof(customerType),1,Tree);
	Write_node(root->Left,Tree);
	Write_node(root->Right,Tree);
   }
}

void WriteToFile(treeType *root)
{
  FILE *Tree;
  Tree=fopen("Text.bin","wb");
  Write_node(root,Tree);
  fclose(Tree);
}



void Loading()
{
 int x,y,i;
 cleardevice();
 x=getmaxx()/2;
 y=getmaxy()/2-10;
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
 setbkcolor(rand());
 setcolor(15);
 int c=150;
  for(int e=0;e<5;e++) //Change 15 to your desired value
  {
    for(int i=50;i<100;i++)
    {
     settextstyle(SMALL_FONT, HORIZ_DIR, 10);
     outtextxy(x,y,"Loading...");
     settextstyle(SMALL_FONT, HORIZ_DIR, 5);
     outtextxy(x+5,y+5,"Please Wait... ");
     circle(x,y,i);
     circle(x,y,c);
     c--;
     delay(5);
     cleardevice();
    }
   }
    setbkcolor(0);
 }

 int initmouse(){
 t.x.ax=0;//for  initialising mouse.
 int86(0x33,&t,&o);
 return (o.x.ax);
}

void showmouse(){
 t.x.ax=1; // for displaying mouse pointer.
 int86(0x33,&t,&o);
}
void hidemouse(){
 t.x.ax=2;
 int86(0x33,&t,&o);
}

void setmousepos(int &xpos,int &ypos){
 t.x.ax=4;
 t.x.cx=xpos;
 t.x.dx=ypos;
 int86(0x33,&t,&o);
}

void restrictmouse(int x1,int y1,int x2,int y2){
 t.x.ax=7;     //to define the upper left boundry of mouse.
 t.x.cx=x1;
 t.x.dx=x2;
 int86(0x33,&t,&o);
 t.x.ax=8;   //to define the bottom right boundry of mouse.
 t.x.cx=y1;
 t.x.dx=y2;
 int86(0x33,&t,&o);
}
void getmousepos(int *buttonm,int *x, int *y){
 t.x.ax=3; //to move mouse.
 int86(0x33,&t,&o);
 *buttonm=o.x.bx;
 *x=o.x.cx;
 *y=o.x.dx;
}
