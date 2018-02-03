#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<stdlib.h>
int Q,f1=0,f2=0,f3=0;
ofstream fof;
struct kbcq  //structure for question
{ char q[200];
  char a[30];
  char b[30];
  char c[30];
  char d[30];
  int cor;
}que;
char nam[20];

/********************************************************************************************************************/
//class
class KBC
{ char name[20];
  char score[8];
  void qt(char a[]);  //function for question

  void set(int j)   //space function
  { int i;
	 for(i=1;i<=j;i++)
	  cout<<" ";
  }
  public:
  KBC()  //costructor
  { strcpy(score,"0");
	 strcpy(name,nam);
  }
/********************************************************************************/
  char* sco(int i,int j=-1)  //score function
  { if(j==1)
	 { switch(i)
		{ case 1:strcpy(score,"1000");break;
		  case 2:strcpy(score,"5000");break;
		  case 3:strcpy(score,"10000");break;
		  case 4:strcpy(score,"20000");break;
		  case 5:strcpy(score,"40000");break;
		  case 6:strcpy(score,"60000");break;
		  case 7:strcpy(score,"80000");break;
		  case 8:strcpy(score,"100000");break;
		  case 9:strcpy(score,"500000");break;
		  case 10:strcpy(score,"1000000");break;
		}
		return score;
	 }
	 else if(j==-1)
	 { switch(i)
		{ case 1:return "1000";
		  case 2:return "5000";
		  case 3:return "10000";
		  case 4:return "20000";
		  case 5:return "40000";
		  case 6:return "60000";
		  case 7:return "80000";
		  case 8:return "100000";
		  case 9:return "500000";
		  case 10:return "1000000";
		}
	 }
	 else
	  return score;
  }
/********************************************************************************/
  int check(char a,char b)  //function to check
  { if((a==b)||(a=='`'))
	  return 1;
	 else
	  return 0;
  }
/********************************************************************************/
  char* l_1()  //life 1
  { if(f1==1)
	  return "     ";
	 else
	  return "50-50";
  }
  char* l_2()  //life 2
  { if(f2==1)
	  return "    ";
	 else
	  return "Flip";
  }
  char* l_3()  //life 3
  { if(f3==1)
	  return "    ";
	 else
	  return "XCom";
  }
/********************************************************************************/
  void qt(char);  //function for question
  char disp(kbcq, int);  //Display
  char f_50(kbcq ,int );  //50-50
  void show()
  { cout<<"\nName:"<<name;
	 cout<<"\nScore:"<<score;
	 cout<<endl<<endl;
  }
};
/********************************************************************************/
  void KBC::qt(char a[])  //function for question
  { int i=0,j,k=0,len,sp=0,f;
	 len=strlen(a);
	 if(len<56)
	 { cout<<"\t| "<<a;set(56-len);cout<<" |"<<endl;}
	 else
	 { while(k>=0)
		{ cout<<"\t| ";
		  for(j=i;j<=(i+55);j++)
		  { if(a[i+55]==' ')
			 { f=i+55;
				break;
			 }
			 else if(a[j]=='\0')
			 { f=j;
				break;
			 }
			 else if(a[j]==' ')
			  f=j;
		  }
		  sp=0;
		  while(i<f)
		  { sp++;
			 cout<<a[i];
			 i++;
		  }
        i=f+1;
		  set(56-sp);
		  cout<<" |"<<endl;
		  if(a[f]=='\0')
			 break;
		  k++;
		}
	 }
  }
/***********************************************************************************/
  char KBC::disp(kbcq a, int b)  //Display
  { clrscr();
	 char c;
	 cout<<"\t\t-----------------------"<<endl;
	 cout<<"\t\t| "<<l_1()<<" | "<<l_2()<<" | "<<l_3()<<" |"<<endl;
	 cout<<"\t\t-----------------------"<<endl;
	 cout<<"\n"<<name<<" Question for "<<sco(b)<<" :"<<endl;
	 cout<<"\n\t------------------------------------------------------------"<<endl;
	 qt(a.q);
	 cout<<"\t------------------------------------------------------------"<<endl;
	 cout<<endl;
	 cout<<"\t---------------------------\t---------------------------"<<endl;
	 cout<<"\t|A. "<<a.a;set(22-strlen(a.a));cout<<"|\t|B. "<<a.b;set(22-strlen(a.b));cout<<"|"<<endl;
	 cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
	 cout<<"\t---------------------------\t---------------------------"<<endl;
	 cout<<"\t|C. "<<a.c;set(22-strlen(a.c));cout<<"|\t|D. "<<a.d;set(22-strlen(a.d));cout<<"|"<<endl;
	 cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
	 cout<<"Enter your option in caps:";
	 cin>>c;
	 return c;
  }
/********************************************************************************/
  char KBC::f_50(kbcq a,int b)  //50-50
  { f1=1;
	 randomize();
	 clrscr();
	 char c,ch;
	 cout<<"\t\t-----------------------"<<endl;
	 cout<<"\t\t| "<<l_1()<<" | "<<l_2()<<" | "<<l_3()<<" |"<<endl;
	 cout<<"\t\t-----------------------"<<endl;
	 cout<<"\n"<<name<<" Question for "<<sco(b)<<" :"<<endl;
	 cout<<"\n\t------------------------------------------------------------"<<endl;
	 qt(a.q);
	 cout<<"\t------------------------------------------------------------"<<endl;
	 switch(a.cor)
	 { case 'A':{ do
					  { ch=random(4)+65;
					  }while(ch=='A');
					  switch(ch)
						 { case 'B':{ cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|A. "<<a.a;set(22-strlen(a.a));cout<<"|\t|B. "<<a.b;set(22-strlen(a.b));cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|C. ";set(22);cout<<"|\t|D. ";set(22);cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  break;
										}
							case 'C':{ cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|A. "<<a.a;set(22-strlen(a.a));cout<<"|\t|B. ";set(22);cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|C. "<<a.c;set(22-strlen(a.c));cout<<"|\t|D. ";set(22);cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  break;
										}
							case 'D':{ cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|A. "<<a.a;set(22-strlen(a.a));cout<<"|\t|B. ";set(22);cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|C. ";set(22);cout<<"|\t|D. "<<a.d;set(22-strlen(a.d));cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  break;
										}
						 }
					  }
					  break;
		case 'B':{ do
					  { ch=random(4)+65;
					  }while(ch=='B');
					  switch(ch)
						 { case 'A':{ cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|A. "<<a.a;set(22-strlen(a.a));cout<<"|\t|B. "<<a.b;set(22-strlen(a.b));cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|C. ";set(22);cout<<"|\t|D. ";set(22);cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  break;
										}
							case 'C':{ cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|A. ";set(22);cout<<"|\t|B. "<<a.b;set(22-strlen(a.b));cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|C. "<<a.c;set(22-strlen(a.c));cout<<"|\t|D. ";set(22);cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  break;
										}
							case 'D':{ cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|A. ";set(22);cout<<"|\t|B. "<<a.b;set(22-strlen(a.b));cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|C. ";set(22);cout<<"|\t|D. "<<a.d;set(22-strlen(a.d));cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  break;
										}
						 }
					  }
					  break;
		case 'C':{ do
					  { ch=random(4)+65;
					  }while(ch=='C');
					  switch(ch)
						 { case 'B':{ cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|A. ";set(22);cout<<"|\t|B. "<<a.b;set(22-strlen(a.b));cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|C. "<<a.c;set(22-strlen(a.c));cout<<"|\t|D. ";set(22);cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  break;
										}
							case 'A':{ cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|A. "<<a.a;set(22-strlen(a.a));cout<<"|\t|B. ";set(22);cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|C. "<<a.c;set(22-strlen(a.c));cout<<"|\t|D. ";set(22);cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  break;
										}
							case 'D':{ cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|A. ";set(22);cout<<"|\t|B. ";set(22);cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|C. "<<a.c;set(22-strlen(a.c));cout<<"|\t|D. "<<a.d;set(22-strlen(a.d));cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  break;
										}
						 }
					  }
					  break;
		case 'D':{ do
					  { ch=random(4)+65;
					  }while(ch=='D');
					  switch(ch)
						 { case 'B':{ cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|A. ";set(22);cout<<"|\t|B. "<<a.b;set(22-strlen(a.b));cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|C. ";set(22);cout<<"|\t|D. "<<a.d;set(22-strlen(a.d));cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  break;
										}
							case 'C':{ cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|A. ";set(22);cout<<"|\t|B. ";set(22);cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|C. "<<a.c;set(22-strlen(a.c));cout<<"|\t|D. "<<a.d;set(22-strlen(a.d));cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  break;
										}
							case 'A':{ cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|A. "<<a.a;set(22-strlen(a.a));cout<<"|\t|B. ";set(22);cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl;
										  cout<<"\t|C. ";set(22);cout<<"|\t|D. "<<a.d;set(22-strlen(a.d));cout<<"|"<<endl;
										  cout<<"\t---------------------------\t---------------------------"<<endl<<endl;
										  break;
										}
						 }
					  }
					  break;

	 }
	 cout<<"Enter your option in caps:";
	 cin>>c;
	 return (c);
  }
  void front()
  {   char ch;
		do{
		clrscr();
		cout<<"\t......WELCOME TO KBC......"<<endl;
		cout<<"\n--------------------------------------------"<<endl;
		cout<<"\n1. Play."<<endl;
		cout<<"2. High Score."<<endl;
		cout<<"3. Administrator."<<endl;
		cout<<"4. Instructions."<<endl;
		cout<<"5. Exit."<<endl;
		cout<<"Enter your choice:";
		ch=getch();
		switch(ch)
		{ case'1':clrscr();
					 cout<<"\t......WELCOME TO KBC......"<<endl;
					 cout<<"\n--------------------------------------------"<<endl;
					 cout<<"\n\nEnter your name:";
					 gets(nam);
					 break;
		  case'2':{ifstream fif;
					 KBC a;
					 fif.open("play.kbc",ios::in|ios::binary);
					 clrscr();
					 cout<<"\t...... KBC players High score......"<<endl;
					 cout<<"\n--------------------------------------------"<<endl;
					 while(!fif.eof())
					 { fif.read((char*)&a,sizeof(a));
						a.show();
					 }
					 fif.close();
					 cout<<"Press any key to main menu:";
					 ch=getch();
					 break;}
		  case'3':{ cout<<"\nEnter pass key:";
                 ch=getch();
					  if(ch=='`')
					  { clrscr();
						 cout<<"\t......Administrator Setting......"<<endl;
						 cout<<"\nEnter correct choice:"<<endl;
						 cout<<"1. Q ( 1,000-20,000 )."<<endl;
						 cout<<"2. Q ( 40,000-80,000 )."<<endl;
						 cout<<"3. Q ( 1 lakh-10 lakh )."<<endl;
						 cout<<"Press any key for back to game."<<endl;
						 ch=getch();
						 if(ch=='1')
						 { fof.open("pd1.kbc",ios::app|ios::binary);
							if(!fof)
							{ cout<<"Previous file doesnot exist!!!!"<<endl;
							  cout<<"Creating new file!!!! Press any key";
							  getch();
							}
						 }
						 else if(ch=='2')
						 { fof.open("pd2.kbc",ios::app|ios::binary);
							if(!fof)
							{ cout<<"Previous file doesnot exist!!!!"<<endl;
							  cout<<"Creating new file!!!! Press any key";
							  getch();
							}
						 }
						 else if(ch=='3')
						 { fof.open("pd3.kbc",ios::app|ios::binary);
							if(!fof)
							{ cout<<"Previous file doesnot exist!!!!"<<endl;
							  cout<<"Creating new file!!!! Press any key";
							  getch();
							}
						 }
						 else
						  break;
						 do
						 { clrscr();
							fof.seekp(0,ios::end);
							Q=fof.tellp();
							Q=Q/sizeof(que);
							cout<<"Number of questions:"<<Q<<endl;
							cout<<"\n*Enter Question:";
							gets(que.q);
							cout<<"\nEnter options:"<<endl;
							cout<<"\nA :";
							gets(que.a);
							cout<<"\nB :";
							gets(que.b);
							cout<<"\nC :";
							gets(que.c);
							cout<<"\nD :";
							gets(que.d);
							cout<<"\nEnter correct option in caps:"<<endl;
							cin>>ch;
							que.cor=(int)ch;
							cout<<"\nWant to enter more(y/n):";
							ch=getch();
							fof.write((char*)&que,sizeof(que));
						 }while(ch=='y'||ch=='Y');
						 fof.close();
						 cout<<"\nFile closed!!!";
						}
					  else
					  { cout<<"\nWrong pass key!!";
						 cout<<"\nPress any key to main menu:";
						 getch();
					  }
					  break;}
		  case'4':clrscr();
					 cout<<"\n\t......RULES......"<<endl;
					 cout<<"\n--------------------------------------------"<<endl;
					 cout<<"\n1. Press correct option in capital letters."<<endl;
					 cout<<"2. Press '5' for lifeline 50-50."<<endl;
					 cout<<"3. Press 'F' for lifeline Flip."<<endl;
					 cout<<"4. Press 'X' for lifeline comp-advice."<<endl;
					 cout<<"4. Press 'Q' for Quit the game."<<endl;
					 cout<<"Press any key to main menu:";
					 getch();
					 break;
		  case'5':abort();
		}}while((ch!='5')&&(ch!='1'));
  }
/************************************************************************************/









/***********************************************************************************/
void main()
{ randomize();
  char ch;
  int flag,b,i;
  front();
/*****************************************************************************************************/
//game
	 KBC K;
	 ifstream ifof;
	 for(i=1;i<=10;i++)
	 { if(i==1)  //pd1
		{ clrscr();
		  cout<<"\nLet's begin with Stage 1"<<endl;
		  cout<<"Press any key:";
		  getch();
		  ifof.open("pd1.kbc",ios::binary);
		  if(!ifof)
		  { cout<<"\n\t!!!!Question file doesnot exist!!!!"<<endl;
			 abort();
		  }
		  else
		  { ifof.seekg(0,ios::end);
			 Q=ifof.tellg();
			 Q=Q/sizeof(que);
		  }
		}
		else if(i==5)  //pd2
		{ clrscr();
		  cout<<"\n....Stage 1 completed...."<<endl;
		  cout<<"\nLet's begin with Stage 2"<<endl;
		  cout<<"Press any key:";
		  getch();
		  ifof.close();
		  ifof.open("pd2.kbc",ios::binary);
		  if(!ifof)
		  { cout<<"\n\t!!!!Question file doesnot exist!!!!"<<endl;
			 abort();
		  }
		  else
		  { ifof.seekg(0,ios::end);
			 Q=ifof.tellg();
			 Q=Q/sizeof(que);
		  }
		}
		else if(i==8)  //pd3
		{ clrscr();
		  cout<<"\n....Stage 2 completed...."<<endl;
		  cout<<"\nLet's begin with Stage 3"<<endl;
		  cout<<"Press any key:";
		  getch();
		  ifof.close();
		  ifof.open("pd3.kbc",ios::binary);
		  if(!ifof)
		  { cout<<"\n\t!!!!Question file doesnot exist!!!!"<<endl;
			 abort();
		  }
		  else
		  { ifof.seekg(0,ios::end);
			 Q=ifof.tellg();
			 Q=Q/sizeof(que);
		  }
		}
		b=random(Q);
		ifof.seekg(b*sizeof(que),ios::beg);
		ifof.read((char*)& que,sizeof(que));
		ch=K.disp(que,i);
		do
		{ flag=0;
		  if(ch=='Q')
			abort();
		  else if(ch=='5')
		  {
			 if(f1==0)
			 { cout<<"\n To use 50-50 press any key:";
				getch();
				ch=K.f_50(que,i);

			 }
			 else
			 { cout<<"\nSORRY You have used this lifeline!!!"<<endl;
				cout<<"Enter your choice:";
				cin>>ch;
			 }flag=1;
		  }
		  else if(ch=='F')
		  {
			 if(f2==0)
			 { cout<<"\n To use Flip press any key:";
				getch();
				f2=1;
				b=random(Q);
				ifof.seekg(b*sizeof(que),ios::beg);
				ifof.read((char*)& que,sizeof(que));
				ch=K.disp(que,i);

			 }
			 else
			 { cout<<"\nSORRY You have used this lifeline!!!"<<endl;
				cout<<"Enter your choice:";
				cin>>ch;
			 }flag=1;
		  }
		  else if(ch=='X')
		  {
			 if(f3==0)
			 { cout<<"\n To have computer advice, press any key:";
				getch();
				cout<<endl<<"The correct option is:"<<(char)que.cor;
				f3=1;
				cout<<"\nDo you go for this option?";
				cin>>ch;

			 }
			 else
			 { cout<<"\nSORRY You have used this lifeline!!!"<<endl;
				cout<<"Enter your choice:";
				cin>>ch;
			 } flag=1;
		  }
		}while(flag==1);
		if(K.check(ch,(char)que.cor))
		{ if(i==10)
		  { clrscr();
			 cout<<"\t......You Won KBC......"<<endl;
			 cout<<"You have "<<K.sco(i,K.check(ch,(char)que.cor))<<" rupees."<<endl;
			 cout<<"\t......Well played......"<<endl;
			 ofstream pla;
			 pla.open("play.kbc",ios::app|ios::binary);
			 pla.write((char*)&K,sizeof(K));
			 pla.close();
			 cout<<"Player info saved..."<<endl;
			 cout<<"Press any key to exit..";
			 ifof.close();
			 getch();
			 abort();
		  }
		  clrscr();
		  cout<<"\t......You Won......"<<endl;
		  cout<<"You have "<<K.sco(i,K.check(ch,(char)que.cor))<<" rupees."<<endl;
		  cout<<"\t......Well played......"<<endl;
		  cout<<"\nPress any key to move to next question..:";
		  getch();
		}
		else
		{ clrscr();
		  cout<<"\t......You loose......"<<endl;
		  cout<<"You have "<<K.sco(i,K.check(ch,(char)que.cor))<<" rupees."<<endl;
		  cout<<"\t......Well played......"<<endl;
		  ofstream pla;
		  pla.open("play.kbc",ios::app|ios::binary);
		  pla.write((char*)&K,sizeof(K));
		  pla.close();
		  cout<<"Player info saved..."<<endl;
		  cout<<"Press any key to exit..";
		  ifof.close();
		  getch();
		  abort();
		}
	 }
  }













