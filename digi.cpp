#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;

struct bill
{
	char name[20];
	char acc[20];
	char phone[20];
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
	
	printf("\n\n\n");	
	setcolor (4) ;
	
	logo();
	printf("\n\n\t\t\t\t\t\t\t ");
	printf(" LET'S INSPIRE \5 \5 \5 ");
	cin.ignore();
	system("CLS");
	setcolor (4);
	digi();
	setcolor (14) ;
	printf("\n\n\n\n");
	printf(" \2 \2 \2 ");
	setcolor (10) ;
	printf(" Hi! Welcome to DiGi's billing system.") ;
	setcolor (14) ;
	printf(" \2 \2 \2");
	printf("\n");
	
	while (response == 'Y' || response == 'y')
	{
		setcolor (7) ;
		printf("\n\n How many phone numbers do you want to make your bill payment : ");
		scanf("%d",&noOfbill);
		system("CLS");
	
		bill info[noOfbill];
		calc price[noOfbill];
	
		detail(info, noOfbill);
		process(price, info, noOfbill);	
		
		
		printf("\n\n Do you want to continue ? ");
		printf("\n [Y] to continue, [X] to exit	: ");
		scanf("%s",&response);
		system("CLS");
	}
	logo();
	printf("\n\n\n");
	shutdown();
	printf("\t\t\t\t\t\t\t");
	printf("Thank you for using DiGi ");
	printf("\n\n\n");
		
}

void detail(bill info[], int noOfbill)
{
	for(int i=0; i<noOfbill; i++)
	{
		setcolor (6) ;
		digi();
		setcolor (11) ;
		printf("\n Person "+i+1);
		setcolor (7) ;
		printf("\n\n Enter name	: ");
		cin.ignore();
		cin.getline(info[i].name,20);
		printf("\n Enter account number	: ");
		scanf("%s",&info[i].acc);
		printf("\n Enter phone number	: ");
		scanf("%s",&info[i].phone);
		menu();
		setcolor (11) ;
		printf("\n\n Enter package [B] [I] [A] : ");
		setcolor (13) ;
		cin>>info[i].package;
		//printf("%s",info[i].package);
		setcolor (1) ;
		printf("\n Enter minute(s) of talk	: ");
		scanf("%f",&info[i].minuteTalk);
		printf("\n Enter how many text(s) you have sent	: ");
		scanf("%f",&info[i].smsRate);
		printf("\n Enter internet usage (mb)	: ");
		scanf("%f",&info[i].usage);
		system("CLS");
	}
}

void menu()
{
	setcolor (14) ;
	printf("\n Our packages come with Basic, Intermediate and Advance. ");
	printf("\n\n B for Basic 		3.00 GB internet ");
	printf("\n I for Intermediate 	5.00 GB internet ");
	printf("\n A for Advance 		7.00 GB internet ");
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
{/*
	printf(" DiGi'S BILLING INFORMATION");
	printf(" NAME			:  %d ",info[i].name);
	printf(" ACCOUNT NUMBER	: %s",info[i].acc);
	printf(" Phone Number				: %d ",info[i].phone);
	//printf(" Package Name				: %s ",price[i].packageName);
	printf(" Package Name				:	"<<price[i].packageName<<endl;
	printf(" Package Type				:	"<<info[i].package<<endl;
	printf(" Internet usage			:	%d  MB(s)", info[i].usage);
	printf(" Minute talk				:  %d  ",info[i].minuteTalk);
	printf(" SMS					:	%d  Text Message(s)",info[i].smsRate);
	printf(" Price for internet usage		:	RM %f",price[i].priceUsage);
	printf(" Price for minute talk			:	RM %f",price[i].priceMin);
	printf(" Price for sms				:	RM %f \t\t\t\t|",price[i].priceSms);
	printf(" TOTAL	: RM %f ",price[i].total1);
	printf("\t\t\t\t| You can do your payment through Visa or Maybank2u. ");
	printf("\t\t\t\t| Please refer to our DiGiHelpline 1800-26-26 if you have any problem. ");
	printf("\t\t\t\t| Thank you for using DiGi.");
	printf("\t\t\t\t|_______________________________________________________________________");
	printf("\n\n\n");
	x=i;
*/
	
	setcolor(7) ;
	printf("\n\n\n");
	printf("\t\t\t\t _______________________________________________________________________\n\t\t\t\t\n");
	printf("\t\t\t\t"); 
	setcolor (12) ;
	printf("  \3 \3 \3");
	setcolor (10) ;
	printf("	DiGi'S BILLING INFORMATION");
	setcolor (12) ;
	printf("\t\3 \3 \3     \n");
	setcolor (7) ;
	printf("\t\t\t\t\n");
	printf("\t\t\t\t");
	setcolor (5) ;
	printf(" NAME			: %d",&info[i].name);
	setcolor (7) ;
	printf("\t\t\t\t");
	setcolor (5) ;
	printf(" ACCOUNT NUMBER	: %s",&info[i].acc);
	setcolor (7) ;
	printf("\t\t\t\t");
	setcolor (14) ;
	printf(" ================================================\n");
	setcolor (7) ;
	printf("\t\t\t\t\n");
	printf("\t\t\t\t|");
	setcolor (5) ;
	printf(" Phone Number				:%d",&info[i].phone);
	setcolor (7) ;
	printf("\t\t\t\t");
	setcolor (5) ;
	printf(" Package Name				:%s",&price[i].packageName);
	setcolor (7) ;
	printf("\t\t\t\t");
	setcolor (5) ;
	printf(" Package Type				: %s" ,&info[i].package);
	setcolor (7) ;
	printf("\t\t\t\t");
	setcolor (5) ;
	printf(" Internet usage			: %f" ,&info[i].usage);
	setcolor (7) ;
	printf("\t\t\t\t");
	setcolor (5) ;
	printf(" Minute talk				: %f	/n",&info[i].minuteTalk);
	setcolor (7) ;
	printf("\t\t\t\t");
	setcolor (5) ;
	printf(" SMS					: %f \n ",info[i].smsRate);
	setcolor (7) ;
	printf("\t\t\t\t");
	setcolor (5) ;
	printf(" Price for internet usage		:	RM %f ",&price[i].priceUsage);
	setcolor (7) ;
	printf("\t\t\t\t");
	setcolor (5) ;
	printf(" Price for minute talk			:	RM %f ",&price[i].priceMin);
	setcolor (7) ;
	printf("\t\t\t\t");
	setcolor (5) ;
	printf("Price for sms				:	RM %f \n\t\t\t\t",&price[i].priceSms);
	setcolor (7) ;
	printf("\t\t\t\t|");
	setcolor (5) ;
	printf(" TOTAL	: RM %f \n ",&price[i].total1);
	setcolor (7) ;
	printf("\t\t\t\t");
	setcolor (14) ;
	printf(" ================================================");
	printf("\n");
	setcolor (7) ;
	printf("\t\t\t\t|");
	printf("\n");
	printf("\t\t\t\t| You can do your payment through Visa or Maybank2u. ");
	printf("\n");
	printf("\t\t\t\t| Please refer to our DiGiHelpline 1800-26-26 if you have any problem. ");
	printf("\n");
	printf("\t\t\t\t| Thank you for using DiGi.");
	printf("\n");
	printf("\t\t\t\t|_______________________________________________________________________");
	printf("\n");
	printf("\n");
	
	x=i;

}

void digi()
{
	printf("\t\t\t\t\t"<< " 0000000000       00000      0000000000      00000 "<<endl;       
	printf("\t\t\t\t\t"<< " 00000000000      00000     000000000000     00000 "<<endl;       
	printf("\t\t\t\t\t"<< " 000     0000     00000    000        000    00000 "<<endl;       
	printf("\t\t\t\t\t"<< " 000      0000             000        000          "<<endl;       
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

/*void getbill(bill info[], calc price[], int noOfbill)
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
}*/

/*void jam ()
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
}*/

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


