#include<dir.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<iomanip.h>
#include<graphics.h>
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
int count=0,count1=0;
char Nebuf[200]="",SNebuf[200]="",knodes[100][100];

class music;

class IOBUFFER
{
   public:
	   void initialize()
	{
	    Nextbyte=0;Buffersize=75;Buffer[0]=0;
	}

	virtual int Read(istream &,int)=0;
	virtual int Write(ostream &)=0;
	virtual int pack(music &,fstream &)=0;
	virtual int unpack(music &,fstream &)=0;

   protected:
	char Buffer[100];
	int Buffersize;
	int Nextbyte;
};

class FixedLengthBuffer:public IOBUFFER
{
public:
int Read(istream &,int);
int Write(ostream &);
};

class VariableFieldBuffer:public FixedLengthBuffer
{
    public:
	int pack(music &,fstream &);
	int unpack(music &,fstream &);
};

/*musicent class*/

class music
{
public:
char sno[30],composer[30],song[30],type[30],year[30];
	music()
	 {
	   sno[0]=0;
	   composer[0]=0;
	   song[0]=0;
	   type[0]=0;
	   year[0]=0;

	 }
    void Input();
    void Modify();
    void Assign1(music &);
    void Assign();
    void Display();
    void Secondary();
    int  Binary(char *);
    void SecondSort();
    void Index();
    void del();
    void KeySort();
    void Indexdisplay(int);
    void Secondsearch(char *);
    void Invertprimary();
    void Invertsecondary();
	void Invertsecondarysort();
	void CheckDup();
    void InvertSecondarySort();
    int  InvertSecondSearch(char *);
};

class fsearch
{
 public:
 int Search(char *);
};

int music::Binary(char *key)
{
 int mid=0,k,ptr1,low,high,i=0;
 low=0;
 high=count-1;
 char ncomposer[20]="",recaddr[10],*endptr;
 int l=strlen(key);
    while(1)
	  {         for(int j=0;j<15;j++)
			ncomposer[j]='\0';
		mid=(low+high)/2;

		if(low>high)
			return -1;

		for(i=0;knodes[mid][i]!='|';i++)
			ncomposer[i]=knodes[mid][i];
		i++;

		for(int n=0;knodes[mid][i]!='|';i++)
			recaddr[n++]=knodes[mid][i];

		int num=strtol(recaddr,&endptr,10);
		ptr1 = strnicmp(ncomposer,key,l);

		if (ptr1 > 0)
		      high=mid-1;
		else if (ptr1 < 0)
			   low=mid+1;
		else if(ptr1==0)
		return num;

	}
}

music s1,s2;
void music::Modify()
{
	char key[20],Buff[100];
	int size=0,found=0,asize=75,Next=0;
	clrscr();
	cout<<"\n\tENTER THE SEARCH KEY: ";
	cin>>key;
	VariableFieldBuffer b;
	fstream file("list.txt",ios::in|ios::out|ios::ate|ios::binary);
	file.seekg(0,ios::beg);
	while(b.unpack(*this,file))
	  {
		if(strcmpi(sno,key)==0)
		  {
		found=1;
		break;
	      }
	     size=size+75;
	  }
	if(found==1)
	 {
		char choice[10];
		cout<<"\n\n\t\t\t\tRecord is found ...."<<endl<<endl;
		cout<<"\n\t\t\tDetails Of Record";
		cout<<"\n\t\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\n\n";
		cout<<"\n\t\t\tSerial Number      :"<<sno<<endl;
		cout<<"\n\t\t\tcomposer     :"<<composer<<endl;
		cout<<"\n\t\t\tsong :"<<song<<endl;
		cout<<"\n\t\t\ttype :"<<type<<endl;
		cout<<"\n\t\t\tyear   :"<<year<<endl;
		cout<<"\n\n\t\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\n\n";
		cout<<"\nDo You Want To Update Serial Number(Y/N)       :";
		cin>>choice;
	   if(choice[0]=='y'||choice[0]=='Y')
	    {
		cout<<"\n\t\tENTER THE Serial Number            :";
		cin>>sno;
	    }
	    cout<<"\nDO You Want To Update composer(Y/N)      :";
	    cin>>choice;
	    if(choice[0]=='y'||choice[0]=='Y')
	     {
		 cout<<"\n\t\tENTER THE composer           :";
		 cin>>composer;
	     }

	    cout<<"\nDO You Want To Update song(Y/N)   :";
	    cin>>choice;

	    if(choice[0]=='y'||choice[0]=='Y')
	      {
		  cout<<"\n\t\tENTER THE song        :";
		  cin>>song;
		  }
	     cout<<"\nDO You Want To Update type(Y/N)  :";
	    cin>>choice;

	    if(choice[0]=='y'||choice[0]=='Y')
	      {
		  cout<<"\n\t\tENTER THE type      :";
		  cin>>type;
	      }
	    cout<<"\nDO You Want To Update year(Y/N)    :";
	    cin>>choice;

	    if(choice[0]=='y'||choice[0]=='Y')
	      {
		  cout<<"\n\t\tENTER THE year         :";
		  cin>>year;
	      }

	      for(int i=0;i<75;i++)
		   {
		  Buff[i]=' ';
	       }

	       this->Assign1(s1);
	       memcpy(&Buff,&asize,sizeof(asize));
	       strcpy(Buff,s1.sno); strcat(Buff,"|");
	       strcat(Buff,s1.composer);strcat(Buff,"|");
	       strcat(Buff,s1.song);strcat(Buff,"|");
	       strcat(Buff,s1.type);strcat(Buff,"|");
	       strcat(Buff,s1.year);strcat(Buff,"|");
	       Next=strlen(Buff);

	       if(Next>asize)
		  cout<<"\n\n\t\t\tRecord Overflow .... \n";
	       else
		 {
		   file.seekp(size);
		   file.write(Buff,asize);
		   cout<<"\n\n\t\t\t\tRecord Is Updated ....\n";
		 }

	 }

    else
		cout<<setw(40)<<"\n\n\n\t\t\tRecord Not Found ....\n";

     file.close();
     getch();
}

void music::Assign1(music &s1)
{
	strcpy(s1.sno,sno);
	strcpy(s1.composer,composer);
	strcpy(s1.song,song);
	strcpy(s1.type,type);
	strcpy(s1.year,year);
}

void music::Input()
{
	int k,value;
	char usn[30];
	music a;
	fsearch v;
	VariableFieldBuffer b;
	fstream file;
	clrscr();
	cout<<"\n\t--------------------------------------------------\n\n";
	cout<<"\n\tENTER THE Serial number     :";;
	cin>>sno;
	while(v.Search(sno)==1)
	 {
		cout<<"\n\nDuplicate Entry Re-Enter The Serial number Value: ";;
		cin>>sno;
	 }
	 cout<<"\n\tENTER THE composer    :";
	 cin>>composer;
	 cout<<"\n\tENTER THE song :";
	 cin>>song;
	 cout<<"\n\tENTER THE type:";
	 cin>>type;
	 cout<<"\n\tENTER THE year  :";
	 cin>>year;
	 file.open("list.txt",ios::app);
	 k=b.pack(*this,file);
	 file.close();
	 if(k==1)
	 cout<<"\n\n\t\t\tRecord Inserted ....\n\n";
	else
	 cout<<"some problem";
}

/*Display function*/

void music :: Display()
{
	VariableFieldBuffer c;
	fstream file("list.txt",ios::in);
	file.seekg(0,ios::beg);
	while(c.unpack(*this,file))
	 {
	   clrscr();
	   cout<<endl<<endl<<endl;
	   cout<<setw(25)<<" "<<"DISPLAYING RECORD'S"<<endl<<endl<<endl<<endl;
	   for(int i=0;i<80;i++)   cout<<'*';   cout<<endl<<endl<<endl;
	   cout<<setw(20)<<" "<<" Serial Number :  "<<sno<<endl<<endl<<endl;
	   cout<<setw(20)<<" "<<" composer              :  "<<composer<<endl<<endl<<endl;
	   cout<<setw(20)<<" "<<" song           :  "<<song<<endl<<endl<<endl;
	   cout<<setw(20)<<" "<<" type         :  "<<type<<endl<<endl<<endl;
	   cout<<setw(20)<<" "<<" year            :  "<<year<<endl<<endl<<endl<<endl;
	   for(i=0;i<80;i++) cout<<'*';
	   cout<<endl<<endl<<setw(39)<<" ";
	   getch();
	 }
      if(!(c.unpack(*this,file)))
       {
	 cout<<endl<<endl<<endl<<endl<<setw(40)<<"NO RECORDS FOUND ....";
	 getch();
	 return;
	   }

    file.clear();
    file.close();
}

/*Assign function*/

void music::Assign()
{
	char key[20],Buff[100];
	int size=0,found=0,asize=75,Next=0;
	clrscr();
	cout<<"\n\tENTER THE SEARCH KEY  :";
	cin>>key;
	VariableFieldBuffer b;
	fsearch v;
	fstream file("list.txt",ios::app|ios::in|ios::out|ios::ate|ios::binary);
	file.seekg(0,ios::beg);
	while(b.unpack(*this,file))
	  {
	    if(strcmpi(sno,key)==0)
	      {
		found=1;
		break;
	      }
	     size=size+75;
	  }
	if(found==1)
	 {
	  char choice[10];
	  cout<<"\n\n\t\t\t\tRecord is found ...."<<endl<<endl;
	  cout<<"\n\t\t\tDetails Of Record";
	  cout<<"\n\t\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\n\n";
	  cout<<"\n\t\t\t Serial Number :"<<sno<<endl;
	  cout<<"\n\t\t\t composer :"<<composer<<endl;
	  cout<<"\n\t\t\t song :"<<song<<endl;
	  cout<<"\n\t\t\t type :"<<type<<endl;
	  cout<<"\n\t\t\t year :"<<year<<endl;
	  cout<<"\n\n\t\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\vs\v\v\v\v\v\v\v\v\v\v\v\v\v\n\n";

	  cout<<"\n\t\tENTER THE Serial Number            :";
	  cin>>sno;

		while(v.Search(sno)==1)
		{
			cout<<"\n\nDuplicate Entry Re-Enter The Serial Number Value  :";
			cin>>sno;
		}
	  cout<<"\n\t\tENTER THE composer           :";
	  cin>>composer;

	  cout<<"\nDO You Want To Update song(Y/N)   :";
	  cin>>choice;

		if(choice[0]=='y'||choice[0]=='Y')
		{
		  cout<<"\n\t\tENTER THE song        :";
		  cin>>song;
		}

	  cout<<"\nDO You Want To Update ID type(Y/N)  :";
	  cin>>choice;

		if(choice[0]=='y'||choice[0]=='Y')
		{
		  cout<<"\n\t\tENTER THE type      :";
		  cin>>type;
		}

	    cout<<"\nDO You Want To Update year(Y/N)    :";
	    cin>>choice;

		if(choice[0]=='y'||choice[0]=='Y')
		{
		  cout<<"\n\t\tENTER THE year         :";
		  cin>>year;
		}

		for(int i=0;i<75;i++)
		{
		  Buff[i]=' ';
		}

	       this->Assign1(s1);
	       memcpy(&Buff,&asize,sizeof(asize));
	       strcpy(Buff,s1.sno); strcat(Buff,"|");
	       strcat(Buff,s1.composer);strcat(Buff,"|");
	       strcat(Buff,s1.song);strcat(Buff,"|");
	       strcat(Buff,s1.type);strcat(Buff,"|");
	       strcat(Buff,s1.year);strcat(Buff,"|");
	       Next=strlen(Buff);

	       if(Next>asize)
		  cout<<"\n\n\t\t\tRecord Overflow .... \n";
	      else
		 {
		   file.write(Buff,asize);
		   cout<<"\n\n\t\t\t\tRecord Is Updated ....\n";
		 }

	 }

    else
	cout<<setw(40)<<"\n\n\n\t\t\tRecord Not Found ....\n";

     file.close();
     getch();
}

/*Delete function*/

void music::del()
{
char key[20],Buff[100];
	int size=0,asize=75,found=0;
	clrscr();
	cout<<"\nENTER THE RECORD KEY TO BE DELETED  :";
	cin>>key;
	fsearch u;
	found=u.Search(key);
	if(found==1)
	cout<<"\n\n\n\t\t\tRecord Is Found ....";
	else
	cout<<"\n\n\n\t\t\tRecord Is Not Found ....";

	VariableFieldBuffer b;
	fstream file,file1;
	if(found==1)
	{
	file.open("list.txt",ios::app|ios::in|ios::out|ios::ate|ios::binary);
	file.seekg(0,ios::beg);
	file1.open("llist.txt",ios::out);
	file1.seekg(0,ios::beg);
	 while(b.unpack(*this,file))
	 {
	    if(strcmp(sno,key)==0)
	      {
	      cout<<"\n\n\n\n\t\tRecord Is Deleted ....\n";

	      }
	      else
	      {
	       for(int i=0;i<75;i++)
	       {
		  Buff[i]=' ';
	       }
	       this->Assign1(s1);
	       memcpy(&Buff,&asize,sizeof(asize));
	       strcpy(Buff,s1.sno); strcat(Buff,"|");
	       strcat(Buff,s1.composer);strcat(Buff,"|");
	       strcat(Buff,s1.song);strcat(Buff,"|");
	       strcat(Buff,s1.type);strcat(Buff,"|");
	       strcat(Buff,s1.year);strcat(Buff,"|");
	       file1.write(Buff,asize);
	       size=size+75;
	      }
	  }
	}
	  /*if(found==1)
	  {
	  unlink("list.txt");
	  rename("llist.txt","list.txt");
	   }*/


	 file1.close();
	 file.close();
	 unlink("list.txt");
	 rename("llist.txt","list.txt");
	 getch();
}

/*Key sorting*/

void music::KeySort()
{
char Buffer[15],str1[15]="",str2[15]="";
int length=15,ptr,i=0;
fstream file("index.txt",ios::in);
file.seekg(0,ios::beg);

while(1)
{
	file.read(Buffer,length);
		if(file.fail())
			break;
		for(int j=0;j<15;j++)
			knodes[i][j]=Buffer[j];
		i++;
}

for(int j=0;j<15;j++)
knodes[i][j]=Buffer[j];
file.close();

for(i=0;i<count;i++)
{
	for(int m=0;m<15;m++)
	str1[m]=knodes[i][m];
	j=i-1;
	a:
	for(m=0;m<15;m++)
	str2[m]=knodes[j][m];
	ptr=strnicmp(str1,str2,10);
	while(j>=0&&ptr<0)
	{
	     for(m=0;m<15;m++)
	     knodes[j+1][m]=knodes[j][m];
	     j--;
	 goto a;
	}

	for(m=0;m<15;m++)
	knodes[j+1][m]=str1[m];
}

knodes[i][j]=Buffer[j];
}

void  music::Index()
{
	int size=0,length=75;
	char uns[15]="0",IBuff[75]="";
	count=0;
	ifstream ofile("list.txt",ios::in);
	ofile.seekg(0,ios::beg);
	fstream nfile("index.txt",ios::out);
	if(ofile.fail())
		 cout<<"file not exist";
	else
		 while(1)
		  {
			 ofile.read(IBuff,length);
			 if(ofile.fail())
			 break;
			 for(int i=0;IBuff[i]!='|';i++)
			 uns[i]=IBuff[i];
			 count++;
			 nfile.seekp(size);
			 nfile<<uns<<"|"<<count<<"|";
			 size=size+15;
		  }
	 nfile.close();
	 ofile.close();
}

void music::Secondary()
{
	int size=0,length=75;
	char uns[20]="0",composer[20]="0",Buffer[75]="";
	count=0;
	ifstream ofile("list.txt",ios::in);
	ofile.seekg(0,ios::beg);
	fstream nfile("Second.txt",ios::out);
	if(ofile.fail())
		 cout<<"file not exist";
	else
		 while(1)
		  {
			 ofile.read(Buffer,length);
			 if(ofile.fail())
			  break;
	       int j=0;

	       for(int i=0;Buffer[i] != '|';i++)
			uns[j++]=Buffer[i];
	       uns[j]='\0';
	       i++;

	       for(j=0;Buffer[i]!='|' ;i++)
		       composer[j++]=Buffer[i];
	       composer[j]='\0';

			 count++;
			 nfile.seekp(size);
			 nfile<<composer<<"|"<<uns<<"|";
			 size=size+30;
		  }
	 nfile.close();
	 ofile.close();
}

void music::SecondSort()
{
char Buffer[30],str1[30]="",str2[30]="";
int length=30,ptr,i=0;
fstream file("second.txt",ios::in);
file.seekg(0,ios::beg);
while(1)
{
	file.read(Buffer,length);
		if(file.fail())
			break;

		for(int j=0;j<30;j++)
			knodes[i][j]=Buffer[j];
		i++;
}

for(int j=0;j<30;j++)
	knodes[i][j]=Buffer[j];

file.close();

for(i=0;i<count;i++)
{     j=0;
	for(int m=0;m<30;m++)
		str1[m]=knodes[i][m];
	j=i-1;
	a:

	for(m=0;m<30;m++)
		str2[m]=knodes[j][m];
	ptr=strnicmp(str1,str2,10);

	while(j>=0&&ptr<0)
	{
	     for(m=0;m<30;m++)
	     knodes[j+1][m]=knodes[j][m];
	     j--;
	 goto a;
	}

	for(m=0;m<30;m++)
		knodes[j+1][m]=str1[m];
}

knodes[i][j]=Buffer[j];
}

void music :: Indexdisplay(int size)
{
	VariableFieldBuffer c;
	fstream file("list.txt",ios::in);
	file.seekg(size,ios::beg);
	c.unpack(*this,file);
	   clrscr();
	   cout<<endl<<endl<<endl;
	   cout<<setw(25)<<" "<<"DISPLAYING RECORD'S"<<endl<<endl<<endl<<endl;

	   for(int i=0;i<80;i++)   cout<<'*';   cout<<endl<<endl<<endl;
	   cout<<setw(20)<<" "<<" serial Number :  "<<sno<<endl<<endl<<endl;
	   cout<<setw(20)<<" "<<" composer              :  "<<composer<<endl<<endl<<endl;
	   cout<<setw(20)<<" "<<" song          :  "<<song<<endl<<endl<<endl;
	   cout<<setw(20)<<" "<<" type          :  "<<type<<endl<<endl<<endl;
	   cout<<setw(20)<<" "<<" year       :  "<<year<<endl<<endl<<endl<<endl;
	   for(i=0;i<80;i++) cout<<'*';
	   cout<<endl<<endl<<setw(39)<<" ";
	   getch();
    file.clear();
    file.close();
}

  void music::Secondsearch(char *key)
  {
  char ncomposer[20]="",unn[20]="";
  int l,ptr1;
  music ss;

    while(1)
	{
		for(int k=0;k<count;k++)
		{
		for(int i=0;knodes[k][i]!='|';i++)
		ncomposer[i]=knodes[k][i];
		i++;
		l=strlen(key);
		for(int n=0;knodes[k][i]!='|';i++)
		unn[n++]=knodes[k][i];
		ptr1 = strnicmp(ncomposer,key,l);
		if(ptr1==0)
		{
		  ss.Index();
		  ss.KeySort();
		  int a=ss.Binary(unn);

			if(a==-1)
			cout<<"Record not found.......!";
			else
			{
				//int b=a;
					a=a-1;
					a=a*75;
				ss.Indexdisplay(a);
				cout<<"\n\n\nRecord found successfull ....  ";
				ss.Secondary();
				ss.SecondSort();
			}
		   }
		if(count-1==k)
		break;
	      }
	      break;

   }


}


//##############################################################################
void music::Invertprimary()
{
int size=0,length=75;
	char uns[20]="0",IBuff[75]="";
	count=0;
	ifstream ofile("list.txt",ios::in);
	ofile.seekg(0,ios::beg);
	fstream nfile("index1.txt",ios::out);
	if(ofile.fail())
		 cout<<"file not exist";
	else
		 while(1)
		  {
			 ofile.read(IBuff,length);
			 if(ofile.fail())
			  break;
			 for(int i=0;IBuff[i]!='|';i++)
			 uns[i]=IBuff[i];
			 count++;
			 nfile.seekp(size);
			 nfile<<count<<"|"<<uns<<"|"<<-1<<"|";
			 size=size+25;
		  }

	 nfile.close();
	 ofile.close();
}

//#########################################################################################
void music::Invertsecondary()
{
int size=0,length=75;
	char uns[20]="0",IBuff[75]="",composer[20]="";
      count=0;
      music as;
	ifstream ofile("list.txt",ios::in);
	ofile.seekg(0,ios::beg);
	fstream nfile("second1.txt",ios::out);
	if(ofile.fail())
		 cout<<"file not exist";
	else
		 while(1)
		  {
			 ofile.read(IBuff,length);
			 if(ofile.fail())
				  break;

			 for(int i=0;IBuff[i]!='|';i++)
				 uns[i]=IBuff[i];
			 i++;

			 for(int k=0;IBuff[i]!='|';i++)
				composer[k++]=IBuff[i];
			 composer[k]='\0';
			 count++;
			 nfile.seekp(size);
			 nfile<<composer<<"|"<<count<<"|";
			 size=size+25;
		  }
	 nfile.close();
	 ofile.close();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void music::Invertsecondarysort()
{
char Buffer[25],str1[30]="",str2[30]="";
int length=25,ptr,i=0;
fstream file("second1.txt",ios::in);
file.seekg(0,ios::beg);
for(int j=0;j<25;j++)
knodes[i][j]='\0';
while(1)
{
	for(int j=0;j<25;j++)
		Buffer[j]='\0';
	file.read(Buffer,length);

	if(file.fail())
		break;

	for( j=0;j<25;j++)
		knodes[i][j]=Buffer[j];
	i++;
}

for( j=0;j<25;j++)
	knodes[i][j]=Buffer[j];

file.close();

for(i=0;i<count;i++)
{      j=0;
	for(int m=0;m<25;m++)
		str1[m]=knodes[i][m];
	j=i-1;
	a:
	for(m=0;m<25;m++)
		str2[m]=knodes[j][m];
		ptr=strnicmp(str1,str2,10);

	while(j>=0&&ptr<0)
	{
	     for(m=0;m<25;m++)
		    knodes[j+1][m]=knodes[j][m];
	     j--;
	goto a;
	}

	for(m=0;m<25;m++)
		knodes[j+1][m]=str1[m];
}

knodes[i][j]=Buffer[j];
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void music::CheckDup()
{
	  int found,size=0,length=75;
	  char ncomposer[25]="",kcomposer[20]="",klen[5]="",*endptr,Buffer[75]="",ukk[15]="";
	  music sss;
	  fstream qfile("second3.txt",ios::out);
	  qfile.seekp(0,ios::beg);
	  fstream ffile("second2.txt",ios::out);
	  ffile.seekp(0,ios::beg);
	  fstream file("second1.txt",ios::in|ios::out);
	  file.seekg(0,ios::beg);
	   found=count;
	  int i=0;
	  while(i<count)
	  {
	  int l=0;
		 for(int m=0;m<20;m++)
			 kcomposer[m]='\0';
		 for(int j=0;knodes[i][j]!='|';j++)
			 kcomposer[j]=knodes[i][j];
		 j++;

		for(int n=0;knodes[i][j]!='|';j++)
			 klen[n++]=knodes[i][j];


		int p=strlen(kcomposer);
		int  ptr=strnicmp(kcomposer,ncomposer,p);

		if(ptr==0)
		{
		ffile<<klen<<"|";
			fstream nfile("list.txt",ios::in);
			nfile.seekg(0,ios::beg);
			int  num=strtol(klen,&endptr,10);
			num=num-1;
			num=num*75;
			nfile.seekg(num);
			nfile.read(Buffer,length);
			 for(int i=0;Buffer[i] != '|';i++)
				ukk[l++]=Buffer[i];
			 ukk[l]='\0';
			 qfile<<ukk<<"|";

		found=found+1;
		nfile.close();
		}

	       if(ptr>0)
		 {
			ffile.seekp(size);
			strcpy(ncomposer,kcomposer);
			ffile<<kcomposer<<"|"<<klen<<"|";
			fstream nfile("list.txt",ios::in);
			nfile.seekg(0,ios::beg);
			int  num=strtol(klen,&endptr,10);
			num=num-1;
			num=num*75;
			nfile.seekg(num);

			nfile.read(Buffer,length);

			for(int i=0;Buffer[i] != '|';i++)
				ukk[l++]=Buffer[i];

			ukk[l]='\0';
			qfile.seekp(size);
			qfile<<kcomposer<<"|"<<ukk<<"|";
			nfile.close();
			size=size+30;
		 }

		i++;
	     found--;
	}
  ffile.close();
  file.close();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void music::InvertSecondarySort()
{
char Buffer[30],str1[30]="",str2[30]="";
int length=30,ptr,i=0;
fstream file("second3.txt",ios::in);
file.seekg(0,ios::beg);

while(1)
{
	file.read(Buffer,length);
	if(file.fail())
		break;

	for(int j=0;j<30;j++)
		knodes[i][j]=Buffer[j];
	i++;
}

	for(int j=0;j<30;j++)
		knodes[i][j]=Buffer[j];
	file.close();

for(i=0;i<count;i++)
{     j=0;
	for(int m=0;m<30;m++)
		str1[m]=knodes[i][m];
	j=i-1;
	a:

	for(m=0;m<30;m++)
		str2[m]=knodes[j][m];
	ptr=strnicmp(str1,str2,10);

	while(j>=0&&ptr<0)
	{
	     for(m=0;m<30;m++)
		     knodes[j+1][m]=knodes[j][m];
	     j--;
	 goto a;
	}

	for(m=0;m<30;m++)
		knodes[j+1][m]=str1[m];
}

knodes[i][j]=Buffer[j];

for(i=0;i<count;i++)
	 for(j=0;j<30;j++)
		cout<<knodes[i][j];
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int  music::InvertSecondSearch(char *key)
{
clrscr();
char str1[30]="";
int found=0;
char Buffer[30];
int length=30,ptr,i=0;
fstream file("second3.txt",ios::in);
file.seekg(0,ios::beg);

while(1)
{
	file.read(Buffer,length);
	if(file.fail())
	break;
	for(int j=0;j<30;j++)
		knodes[i][j]=Buffer[j];
	i++;
}

for(int j=0;j<30;j++)
knodes[i][j]=Buffer[j];

for( i=0;i<count;i++)
{
 for(int j=0;knodes[i][j]!='|';j++)
     str1[j]=knodes[i][j];
     str1[j]='\0';
     int l=strlen(key);
     int ptr=strnicmp(str1,key,l);
     if(ptr==0)
     {
	found=1;
	break;
	 }
 }

if(found==1)

{
	for(int j=0;j<30;j++)
		cout<<knodes[i][j];
return 1;
}
	else
		return -1;
}

//$////////////////////////////////////////////////////////////////////////////////////////////////////////

int FixedLengthBuffer::Read(istream &stream,int size)
{
stream.read(Buffer,Buffersize+size);
return stream.good();
}

int FixedLengthBuffer::Write(ostream &stream)
{
stream.write(Buffer,Buffersize);
return stream.good();
}
//3333333333333333
//class music;
//class fsearch;

//--------------------------------------------------------------
/*Pack Function*/
void normal();
void screen();
void screen1();
int VariableFieldBuffer::pack(music &s,fstream &file)
{
	int value;
	initialize();

	for(int i=0;i<75;i++)
	{
	   Buffer[i]=' ';
	}

	memcpy(&Buffer[0],&Buffersize,sizeof(Buffersize));
	strcpy(Buffer,s.sno); strcat(Buffer,"|");
	strcat(Buffer,s.composer);strcat(Buffer,"|");
	strcat(Buffer,s.song);strcat(Buffer,"|");
	strcat(Buffer,s.type);strcat(Buffer,"|");
	strcat(Buffer,s.year);strcat(Buffer,"|");
	Nextbyte=strlen(Buffer);

	if(Nextbyte>Buffersize)
	  return 0;

	else
	  value=Write(file);
	  return value;
}

/*Unpack Function*/

int VariableFieldBuffer::unpack(music &s,fstream &file)
{
	initialize();
	Nextbyte=0;
	int value = Read(file,Nextbyte);
	if(value==0) return 0;
	if(Buffersize > 0)
	{
	int j=0;
	      for(int i=0;Buffer[i] != '|';i++)
	       s.sno[j++]=Buffer[i];
	       s.sno[j]='\0';
	       i++;

	      for(j=0;Buffer[i]!='|' ;i++)
	       s.composer[j++]=Buffer[i];
	       s.composer[j]='\0';
		   i++;

	      for(j=0;Buffer[i]!= '|';i++)
		s.song[j++]=Buffer[i];
		s.song[j]='\0';
		i++;

	      for(j=0;Buffer[i]!= '|';i++)
		s.type[j++]=Buffer[i];
		s.type[j]='\0';
		i++;


	      for(j=0;Buffer[i]!= '|';i++)
		 s.year[j++]=Buffer[i];
		 s.year[j]='\0';
		 i++;

	       Nextbyte=Buffersize+75;
	       return 1;
	}
return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/*Function to search a key*/

int fsearch::Search(char *key)
{
	  int found=0;
	  music s1;
	  VariableFieldBuffer b;
	  fstream file("list.txt",ios::in||ios::out);
	  file.seekg(0,ios::beg);
	  while(b.unpack(s1,file))
		 if(strcmpi(s1.sno,key)==0)
		  found=1;
		 file.close();
	  return found;
}

/*Douoblebox design*/
/*
void drawdoublelinebox(int x,int y,int len,int bdt)
{
	gotoxy(x,y);


	cprintf("É");
		gotoxy(x,y+bdt);
	cprintf("È");
	gotoxy(x+len,y);
	cprintf("»");
	gotoxy(x+len,y+bdt);
	cprintf("¼");
	for(int i=x+1;i<x+len;i++)
	{
		gotoxy(i,y);
		cprintf("Í");
		gotoxy(i,y+bdt);
		cprintf("Í");
	}
	for(int j=y+1;j<y+bdt;j++)
	{
		gotoxy(x,j);
		cprintf("º");
		gotoxy(x+len,j);
		cprintf("º");
			}
}

/*Double box design*/
  /*
void drawsinglelinebox(int x,int y,int len,int bdt)
{                                            // (x,y) : co.ord. of 1st tip
	gotoxy(x,y);                         // len : length of box
	cprintf("Ú");                        // bdt : breadth of box
	gotoxy(x,y+bdt);
	cprintf("À");
	gotoxy(x+len,y);
	cprintf("¿");
	gotoxy(x+len,y+bdt);
	cprintf("Ù");

	for(int i=x+1;i<x+len;i++)
	{
		gotoxy(i,y);
		cprintf("Ä");
		gotoxy(i,y+bdt);
		cprintf("Ä");
	}
	for(int j=y+1;j<y+bdt;j++)
	{
		gotoxy(x,j);
		cprintf("³");
		gotoxy(x+len,j);
		cprintf("³");
	}
}
  */

/*Main function*/

void main()
{
int choice,ch,cho,a;
char key[15];
music s;
clrscr();
do
{
     screen();

     cout<<"     PLEASE ENTER YOUR CHOICE [1-3]  :   ";
     cin>>ch;
	  switch(ch)
	  {
	     case 1:do
	      {
	      clrscr();
	     // drawdoublelinebox(17,7,44,14);
	      textcolor(8);
	      textbackground(RED);
		  clrscr();
		  textbackground(BLACK);
	      gotoxy(25,3);
	      textcolor(YELLOW);
	      cprintf("        music RECORDS       ");
	      gotoxy(25,4);
	      cprintf(" ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ ");
	      int z=19,q=10;
	      textcolor(YELLOW);
	     // drawdoublelinebox(17,7,44,14);
	      gotoxy(28,7);
	      textbackground(RED);
	      textcolor(YELLOW);
	      cprintf("  M A I N    M E N U " );
	      normal();
	      textcolor(WHITE);
	      gotoxy(z,q++);
	      cout<<"1.>  INSERT";
	      gotoxy(z,q++);
	      cout<<"2.>  UPDATE";
		  gotoxy(z,q++);
		  cout<<"3.>  DISPLAY ALL";
		  gotoxy(z,q++);
	      cout<<"4.>  DELETE";
	      gotoxy(z,q++);
	      cout<<"5.>  QUIT";
	      gotoxy(z,q++);
	      gotoxy(z,q++);
	      gotoxy(z,q++);
	      cout<<"     PLEASE ENTER YOUR CHOICE : ";
	      cin>>choice;

		 switch(choice)
		 {
		  case 1:s.Input();  //input is inbsurt function
			 break;

		  case 2:s.Modify(); //modify is update function
			 break;

		  case 3:s.Display();
			 break;

		  case 4:s.del();
			 break;

		  case 5:clrscr();
			 screen();
			 break;

		  default:exit(0);
		}
	}while(choice!=5);break;

case 2:
	 //int g=19,h=10;

     do
     {
      screen1();
      cout<<"     PLEASE ENTER YOUR CHOICE  : ";
      cin>>cho;

	switch(cho)
	{


	case 1: s.Invertprimary();
	s.Invertsecondary();
	s.Invertsecondarysort();
	s.CheckDup();
	clrscr();
      //	drawsinglelinebox(20,15,40,15);
	gotoxy(25,20);
	cout<<"Enter the Secondary key: ";
	cin>>key;
	a=s.Binary(key);
	if(a==-1)
	{gotoxy(25,40);
	cout<<"Record not found....!";}
	s.InvertSecondarySort();
	int b=s.InvertSecondSearch(key);
	if(b==1)
	{
	s.Index();
	s.KeySort();
	gotoxy(20,25);
      //	drawsinglelinebox(20,15,40,15);
	gotoxy(25,20);
	cprintf("Enter the Primary key: ");
	cin>>key;
	a=s.Binary(key);
	if(a==-1)
	{gotoxy(25,40);
	cout<<"Record not found....!";}
	else
	{
		//int b=a;
		a=a-1;
		a=a*75;
		s.Indexdisplay(a);
		cout<<"\n\n\nSuccessfull search......  :";
	}getch();
	 }

	//////


else
{
	clrscr();
	gotoxy(20,25);
	cout<<"Record not found...!";
}
break;

case 2:clrscr();
}
}

while(cho!=2);screen();break;

case 3:exit(0);

default: exit(0);//sound(100);delay(500);nosound();break;
}
}while(ch!=3);
}

void screen()
{
 int g=19,h=10;

     clrscr();
      clrscr();
/*	   clrscr();
     textbackground(BLACK);
    textcolor(RED);
    cout<<"\n\t\t\t****************************";
    cout<<"\n\t\t\t* music MANAGEMENT PROJECT *";
    cout<<"\n\t\t\t****************************";
   sleep(2);
     cout<<"\n\n\n\n\t\tMade By:";
   sleep(2);
    cout<<" Aparth Pandey  and Mihir Kumar Jha";
   sleep(2);
    cout<<"\n\n\n\n\n\t\t\t\tPress any key to continue!!";
   // clrscr();
    getch();
    */
    clrscr();

     //textbackground(BLUE);
     gotoxy(22,3);
     textcolor(YELLOW);
     cprintf("                FILE STRUCTURE       ");
     gotoxy(25,4);
     cprintf("   ******************************* ");
    // drawdoublelinebox(17,7,44,14);
     gotoxy(28,7);
     textbackground(RED);
	 textcolor(YELLOW);
	 cprintf("   WELCOME TO music RECORD SYSTEM " );
     normal();
     textcolor(WHITE);
     gotoxy(g,h++);
     cout<<"   * music RECORDS";
     gotoxy(g,h++);
     cout<<"   * INDEXING";
     gotoxy(g,h++);
     cout<<"   * QUIT";
     gotoxy(g,h++);
     gotoxy(g,h++);
     gotoxy(g,h++);
     normal();
}

void normal()  // to obtain normal background
{
	textattr(WHITE); // textattr sets text attributes for text-window functions
	textcolor(WHITE);// textcolor selects a new character color in text mode
	textbackground(BLACK);//textbackground selects a new text background color
	_setcursortype(_NORMALCURSOR); /* sets cursor type to normal underscore
						 type cursor  */

					    }

void screen1()
{

     int b,g=19,h=10;
     clrscr();
     textbackground(BLUE);
     gotoxy(25,3);
     textcolor(YELLOW);
     cprintf("        INDEXING      ");
     gotoxy(25,4);
     cprintf(" ************************ ");
	// drawdoublelinebox(17,7,44,14);
	 gotoxy(28,7);
	 textbackground(RED);
	 textcolor(YELLOW);
	 cprintf("  M A I N    M E N U " );
	 normal();
	 textcolor(WHITE);
	 /*
	 gotoxy(g,h++);
	 cout<<"* SIMPLE INDEX";
	 gotoxy(g,h++);
	 cout<<"* SECONDARY KEY";*/

	 gotoxy(g,h++);

	 cout<<"* INVERTED LIST";
	 gotoxy(g,h++);
	 cout<<"* QUIT";
	 gotoxy(g,h++);
	 gotoxy(g,h++);
	 gotoxy(g,h++);
}
