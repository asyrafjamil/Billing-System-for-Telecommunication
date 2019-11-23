#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;

struct bill
{
	char name[20];
	string acc;
	string phone;
	char package;
	double minuteTalk;
	double smsRate;
	double usage;
	double total;
};

struct calc
{
	string packageName;
	double priceMin;
	double priceSms;
	double priceUsage;
	double total1;
};

void solo();
void detail(bill[], int);
void menu();
void jam ();
double process(calc[], bill[], int);
double boo(calc[], bill[], int);
double ioo(calc[], bill[], int);
double aoo(calc[], bill[], int);
void error (calc[], bill[], int);
void receipt(bill[], calc[], int);
void digi();
void logo();
string setcolor(unsigned short color);
void shutdown();
void getbill(bill[], calc[], int);

int x=0;

int main()
{
//hi
	solo();
//bye
system("pause");
}















void solo()
{
	int noOfbill;
	char response='Y';
	
	cout<<endl<<endl<<endl;
	setcolor (4) ;
	jam();
	logo();
	cout<<"\n\n\t\t\t\t\t\t\t ";
	cout<<" LET'S INSPIRE \5 \5 \5 ";
	cin.ignore();
	system("CLS");
	setcolor (4);
	digi();
	setcolor (14) ;
	cout<<endl<<endl;
	cout<<" \2 \2 \2 ";
	setcolor (10) ;
	cout<<" Hi! Welcome to DiGi's billing system." ;
	setcolor (14) ;
	cout<<" \2 \2 \2"<<endl;
	
	while (response == 'Y' || response == 'y')
	{
		setcolor (7) ;
		cout<<"\n\n How many phone numbers do you want to make your bill payment : ";
		cin>>noOfbill;
		system("CLS");
	
		bill info[noOfbill];
		calc price[noOfbill];
	
		detail(info, noOfbill);
		process(price, info, noOfbill);	
		getbill(info, price, noOfbill);
		
		cout<<"\n\n Do you want to continue ? ";
		cout<<"\n [Y] to continue, [X] to exit	: ";
		cin>>response;
		system("CLS");
	}
	logo();
	cout<<endl<<endl<<endl;
	shutdown();
	cout<<"\t\t\t\t\t\t\t";
	cout<<"Thank you for using DiGi ";
	cout<<endl<<endl<<endl;
}

void detail(bill info[], int noOfbill)
{
	for(int i=0; i<noOfbill; i++)
	{
		setcolor (6) ;
		digi();
		setcolor (11) ;
		cout<<"\n Person "<<i+1;
		setcolor (7) ;
		cout<<"\n\n Enter name	: ";
		cin.ignore();
		cin.getline(info[i].name,20);
		cout<<"\n Enter account number	: ";
		cin>>info[i].acc;
		cout<<"\n Enter phone number	: ";
		cin>>info[i].phone;
		menu();
		setcolor (11) ;
		cout<<"\n\n Enter package [B] [I] [A] : ";
		setcolor (13) ;
		cin>>info[i].package;
		setcolor (1) ;
		cout<<"\n Enter minute(s) of talk	: ";
		cin>>info[i].minuteTalk;
		cout<<"\n Enter how many text(s) you have sent	: ";
		cin>>info[i].smsRate;
		cout<<"\n Enter internet usage (mb)	: ";
		cin>>info[i].usage;
		system("CLS");
	}
}

void menu()
{
	setcolor (14) ;
	cout<<"\n Our packages come with Basic, Intermediate and Advance. ";
	cout<<"\n\n B for Basic 		3.00 GB internet ";
	cout<<"\n I for Intermediate 	5.00 GB internet ";
	cout<<"\n A for Advance 		7.00 GB internet ";
}

double process(calc price[], bill info[], int noOfbill)
{	
	for(int i=0; i<noOfbill; i++)
	{
		if(info[i].package=='B'|| info[i].package=='b')
		{
			price[i].total1=boo(price, info, i);
			setcolor (i+1);
			digi();
			receipt(info, price, i);
		}
		else if(info[i].package=='I' || info[i].package=='i')
		{
			price[i].total1=ioo(price, info, i);
			setcolor (i+1);
			digi();
			receipt(info, price, i);
		}
		else if(info[i].package=='A' || info[i].package=='a')
		{
			price[i].total1=aoo(price, info, i);
			setcolor (i+1);
			digi();
			receipt(info, price, i);
		}
		else
		{
			error(price, info, i);	
			setcolor (i+1);
			digi();
			receipt(info, price, i);
		}
	}
}

double boo(calc price[], bill info[], int i)
{
	price[i].packageName="Basic";
	price[i].priceMin=info[i].minuteTalk*0.10;
	price[i].priceSms=info[i].smsRate*0.05;			
	if(info[i].usage<=3000)
		price[i].priceUsage=30.00;
	else
		price[i].priceUsage=(info[i].usage-3000)*0.20+30.00;	
	price[i].total1=price[i].priceUsage+price[i].priceSms+price[i].priceMin;
}

double ioo(calc price[], bill info[], int i)
{
	price[i].packageName="Intermediate";
	price[i].priceMin=info[i].minuteTalk*0.20;
	price[i].priceSms=info[i].smsRate*0.10;	
	if(info[i].usage<=5000)
		price[i].priceUsage=50.00;
	else
		price[i].priceUsage=(info[i].usage-5000)*0.20+50.00;
	price[i].total1=price[i].priceUsage+price[i].priceSms+price[i].priceMin;
}

double aoo(calc price[], bill info[], int i)
{
	price[i].packageName="Advance";
	price[i].priceMin=info[i].minuteTalk*0.30;
	price[i].priceSms=info[i].smsRate*0.20;
	if(info[i].usage<=7000)
		price[i].priceUsage=70.00;
	else
		price[i].priceUsage=(info[i].usage-7000)*0.20+70.00;
	price[i].total1=price[i].priceUsage+price[i].priceSms+price[i].priceMin;
}

void error(calc price[], bill info[], int i)
{
	price[i].packageName="PACKAGE ERROR";
	price[i].priceMin=00.00;
	price[i].priceSms=00.00;
	price[i].priceUsage=00.00;
	price[i].total1=price[i].priceUsage+price[i].priceSms+price[i].priceMin;
}

void receipt(bill info[],calc price[], int i)
{
	setcolor (7) ;
	cout<<"\n\n\n";
	cout<<"\t\t\t\t _______________________________________________________________________"<<endl<<"\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t|"; 
	setcolor (12) ;
	cout<<"  \3 \3 \3";
	setcolor (10) ;
	cout<<"	DiGi'S BILLING INFORMATION";
	setcolor (12) ;
	cout<<"\t\3 \3 \3     "<<endl;
	setcolor (7) ;
	cout<<"\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t|";
	setcolor (5) ;
	cout<<" NAME			: "<<info[i].name<<endl;
	setcolor (7) ;
	cout<<"\t\t\t\t|";
	setcolor (5) ;
	cout<<" ACCOUNT NUMBER	: "<<info[i].acc<<endl;
	setcolor (7) ;
	cout<<"\t\t\t\t|";
	setcolor (14) ;
	cout<<" ================================================"<<endl;
	setcolor (7) ;
	cout<<"\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t|";
	setcolor (5) ;
	cout<<" Phone Number				:	"<<info[i].phone<<endl;
	setcolor (7) ;
	cout<<"\t\t\t\t|";
	setcolor (5) ;
	cout<<" Package Name				:	"<<price[i].packageName<<endl;
	setcolor (7) ;
	cout<<"\t\t\t\t|";
	setcolor (5) ;
	cout<<" Package Type				:	"<<info[i].package<<endl;
	setcolor (7) ;
	cout<<"\t\t\t\t|";
	setcolor (5) ;
	cout<<" Internet usage			:	"<<info[i].usage<< " MB(s)"<<endl;
	setcolor (7) ;
	cout<<"\t\t\t\t|";
	setcolor (5) ;
	cout<<" Minute talk				:	"<<info[i].minuteTalk<< " Minute(s)"<<endl;
	setcolor (7) ;
	cout<<"\t\t\t\t|";
	setcolor (5) ;
	cout<<" SMS					:	"<<info[i].smsRate<< " Text Message(s)"<<endl;
	setcolor (7) ;
	cout<<"\t\t\t\t|";
	setcolor (5) ;
	cout<<" Price for internet usage		:	RM "<<price[i].priceUsage<<endl;
	setcolor (7) ;
	cout<<"\t\t\t\t|";
	setcolor (5) ;
	cout<<" Price for minute talk			:	RM "<<price[i].priceMin<<endl;
	setcolor (7) ;
	cout<<"\t\t\t\t|";
	setcolor (5) ;
	cout<<" Price for sms				:	RM "<<price[i].priceSms<<endl<<"\t\t\t\t|"<<endl;
	setcolor (7) ;
	cout<<"\t\t\t\t|";
	setcolor (5) ;
	cout<<" TOTAL	: RM "<<price[i].total1<<endl;
	setcolor (7) ;
	cout<<"\t\t\t\t|";
	setcolor (14) ;
	cout<<" ================================================"<<endl;
	setcolor (7) ;
	cout<<"\t\t\t\t|"<<endl;
	cout<<"\t\t\t\t| You can do your payment through Visa or Maybank2u. "<<endl;
	cout<<"\t\t\t\t| Please refer to our DiGiHelpline 1800-26-26 if you have any problem. "<<endl;
	cout<<"\t\t\t\t| Thank you for using DiGi."<<endl;
	cout<<"\t\t\t\t|_______________________________________________________________________"<<endl;
	cout<<endl<<endl;
	
	x=i;
}

void digi()
{
	cout<<"\t\t\t\t\t"<< " 0000000000       00000      0000000000      00000 "<<endl;       
	cout<<"\t\t\t\t\t"<< " 00000000000      00000     000000000000     00000 "<<endl;       
	cout<<"\t\t\t\t\t"<< " 000     0000     00000    000        000    00000 "<<endl;       
	cout<<"\t\t\t\t\t"<< " 000      0000             000        000          "<<endl;       
	cout<<"\t\t\t\t\t"<< " 000       000    00000    000               00000 "<<endl;       
	cout<<"\t\t\t\t\t"<< " 000       000    00000    000    0000000    00000 "<<endl;       
	cout<<"\t\t\t\t\t"<< " 000       000    00000    000    0000000    00000 "<<endl;       
	cout<<"\t\t\t\t\t"<< " 000       000    00000    000        000    00000 "<<endl;       
	cout<<"\t\t\t\t\t"<< " 000     0000     00000    000        000    00000 "<<endl;       
   	cout<<"\t\t\t\t\t"<< " 00000000000      00000     000000000000     00000 "<<endl;           
   	cout<<"\t\t\t\t\t"<< " 0000000000       00000      0000000000      00000 "<<endl;
}

void logo()
{
	setcolor (14) ;
	cout<<"\t\t\t\t\t\t"<< "                           00000000 " <<endl;
	cout<<"\t\t\t\t\t\t"<< "                     000000000000000" <<endl;      
    cout<<"\t\t\t\t\t\t"<< "              0000000000000000000000" <<endl;
    cout<<"\t\t\t\t\t\t"<< "          00000000000000000000000000" <<endl;
    cout<<"\t\t\t\t\t\t"<< "    00000000000000000000000000000000" <<endl;
    cout<<"\t\t\t\t\t\t"<< "  0000000000000000000000000000000000" <<endl;
    cout<<"\t\t\t\t\t\t"<< " 00000000000000000000000000000000000" <<endl;
    cout<<"\t\t\t\t\t\t"<< " 00000000000000000000000000000000000" <<endl;
    cout<<"\t\t\t\t\t\t"<< " 00000000000000000000000000000000000" <<endl;
    cout<<"\t\t\t\t\t\t"<< " 00000000000000000000000000000000000" <<endl;
    cout<<"\t\t\t\t\t\t"<< " 00000000000000000000000000000000000" <<endl;
    cout<<"\t\t\t\t\t\t"<< " 00000000000000000000000000000000000" <<endl;
    cout<<"\t\t\t\t\t\t"<< " 00    00000   0000       0000   000" <<endl;
    cout<<"\t\t\t\t\t\t"<< " 00  0   000   000  00000  000   000" <<endl;
    cout<<"\t\t\t\t\t\t"<< " 00  00  000000000  0000000000000000" <<endl;
    cout<<"\t\t\t\t\t\t"<< " 00  00  000   000  00     000   000" <<endl;
    cout<<"\t\t\t\t\t\t"<< " 00  0   000   000  00000  000   000" <<endl;
    cout<<"\t\t\t\t\t\t"<< " 00    00000   0000       0000   000" <<endl;
    cout<<"\t\t\t\t\t\t"<< " 00000000000000000000000000000000000" <<endl;
    cout<<"\t\t\t\t\t\t"<< "  000000000000000000000000000000000 " <<endl;
}

string setcolor(unsigned short color) 
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
	return "";
}

void getbill(bill info[], calc price[], int noOfbill)
{
	ofstream bill;
		
	bill.open("bill.txt", ios::app);
	bill<<endl<<endl<<endl;
	bill<<"\t\t\t\t _______________________________________________________________________"<<endl<<"\t\t\t\t|"<<endl;
	bill<<"\t\t\t\t|"; 
	bill<<"  \3 \3 \3\t";
	bill<<"	DiGi'S BILLING INFORMATION";
	bill<<"\t\3 \3 \3     "<<endl;
	bill<<"\t\t\t\t|"<<endl;
	bill<<"\t\t\t\t|";
	bill<<" NAME			: "<<info[x].name<<endl;
	bill<<"\t\t\t\t|";
	bill<<" ACCOUNT NUMBER	: "<<info[x].acc<<endl;
	bill<<"\t\t\t\t|";
	bill<<" ================================================"<<endl;
	bill<<"\t\t\t\t|"<<endl;
	bill<<"\t\t\t\t|";
	bill<<" Phone Number				:	"<<info[x].phone<<endl;
	bill<<"\t\t\t\t|";
	bill<<" Package Name				:	"<<price[x].packageName<<endl;
	bill<<"\t\t\t\t|";
	bill<<" Package Type				:	"<<info[x].package<<endl;
	bill<<"\t\t\t\t|";
	bill<<" Internet usage			:	"<<info[x].usage<< " MB(s)"<<endl;
	bill<<"\t\t\t\t|";
	bill<<" Minute talk				:	"<<info[x].minuteTalk<< " Minute(s)"<<endl;
	bill<<"\t\t\t\t|";
	bill<<" SMS					:	"<<info[x].smsRate<< " Text Message(s)"<<endl;
	bill<<"\t\t\t\t|";
	bill<<" Price for internet usage		:	RM "<<price[x].priceUsage<<endl;
	bill<<"\t\t\t\t|";
	bill<<" Price for minute talk			:	RM "<<price[x].priceMin<<endl;
	bill<<"\t\t\t\t|";
	bill<<" Price for sms				:	RM "<<price[x].priceSms<<endl<<"\t\t\t\t|"<<endl;
	bill<<"\t\t\t\t|";
	bill<<" TOTAL	: RM "<<price[x].total1<<endl;
	bill<<"\t\t\t\t|";
	bill<<" ================================================"<<endl;
	bill<<"\t\t\t\t|"<<endl;
	bill<<"\t\t\t\t| You can do your payment through Visa or Maybank2u. "<<endl;
	bill<<"\t\t\t\t| Please refer to our DiGiHelpline 1800-26-26 if you have any problem. "<<endl;
	bill<<"\t\t\t\t| Thank you for using DiGi."<<endl;
	bill<<"\t\t\t\t|_______________________________________________________________________"<<endl;
	bill<<endl<<endl;	
	bill.close();
}

void jam ()
{
	 // current date/time based on current system
   time_t now = time(0);
   
   // convert now to string form
   char* dt = ctime(&now);

   cout << "The local date and time is: " << dt << endl;

   // convert now to tm struct for UTC
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   cout << "The UTC date and time is:"<< dt << endl;
}

void shutdown()
{
	int c;
	
	cout<<" 1.Shutdown \n";
	cout<<" 2.Restart \n";
	cout<<" 3.Cancel \n\n";
	cout<<"\n Enter your choice	: ";
	cin>>c;
	
	switch(c)
	{
		case 1:	cout<<"Your system will be closed after 10 seconds \n\n";
		system("c:\\windows\\system32\\shutdown /s /t 10 \n\n");
		break;

		case 2:	cout<<"Your system will be restarted in 10 seconds \n\n";
		system("c:\\windows\\system32\\shutdown /r /t 10\n\n");
		break;
		
		deafault:
		cout<<"Invalid Chioce \n\n";
	}
}


