#include<iostream>
#include<fstream>
#include<conio.h>
#include<ctime>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include <cstdlib>
using namespace std;
void Bookticket();
void admin_pass();
int seat_dec;
int *tp,*sp;
class Persontype      
{
	protected:	
		string name;
		string  Id;
		string  phone_num;
	
	public:
		void set_data()	
		{
		    ofstream fout;
			fout.open("userlogin.txt",ios::app);
			while(1)
			{
			    char arr[]={'U','S','E','R',' ',' ','D','A','T','A'};
				cout<<"\n\t\t\t";
				for(int i=0;i<10;i++)
				{
					cout<<arr[i];
					Sleep(30);
                }
                cout<<endl;
				cout<<"Enter your name: ";
				cin>>name;
				fout<<name<<endl;
				cout<<"Enter your Cnic id: ";
				cin>>Id;
				fout<<Id<<endl;
				cout<<"Enter your Phone Number : ";
				cin>>phone_num;
				fout<<phone_num<<endl;
             
                fout.close();
				break;
		    }
	    }
    void get_data()
    { 
		ifstream fin;
	    fin.open("userlogin.txt");
		while(!fin.eof())
        {
	        fin>>name;
	        fin>>Id;
	        fin>>phone_num;
	
	        break;
        }
	}
	string return_phn()
	{
	    ifstream fin;
        fin.open("userlogin.txt");
	   while(!fin.eof())
       {
	        fin>>phone_num;
	        return phone_num;
	   }
    }

};
class user:public Persontype          
{
	protected:
        string conf_pass;
		string user_name;
	public:
		void password()
		{
			ofstream fout;
			fout.open("userpassword.txt",ios::app);
			cout<<"Enter your username: ";
			cin>>user_name;
			fout<<user_name<<endl;
			cout<<"Enter your confirm password: ";
			cin>>conf_pass;
			fout<<conf_pass<<endl;
			fout.close();
			user_log();	
		}
		void user_log()
		{	 
			string *Dptr;
			string *Dptr1;	
			Dptr=new string;
			Dptr1=new string;
			system("cls");
			getch();
			char arr[]={'U','S','E','R',' ',' ','L','O','G','I','N'};
			cout<<"\n\t\t\t";
			for(int i=0;i<11;i++)
			{
				cout<<arr[i];
				Sleep(30);
            } 
            cout<<endl;
			cout<<"\t\t\t\t username:";
			cin>>*Dptr;
			cout<<"\n\t\t\t\t Password :";
			cin>>*Dptr1;
			ifstream fin;
			fin.open("userpassword.txt");
			bool login=false;
			while(!fin.eof())
			{
				string un,pw;
				fin>>un;
			         
					fin>>pw;
					 
					if(un==*Dptr && pw==*Dptr1)
					{	
						login=true;	
				        system("cls");
                	    char arr[]={'C','O','N','G','R','A','J','U','L','A','T','I','O','N',' ',' ','Y','O','U',' ',' ','E','N','T','E','R','!'};
			            cout<<"\n\t\t\t";
			            for(int i=0;i<27;i++)
						{
				            cout<<arr[i];
				            Sleep(30);
                        }
                        cout<<endl;
				  	    int*ch= new int ;
				  	    cout<<"\n\t\t\t\t User login:"<<endl;
				  	    cout<<"\t\t\t\t 1.----bookticket----"<<endl;
				        cout<<"\t\t\t\t 2.----exit----"<<endl;
				        cout<<"\t\t\t\t Enter :";
				        cin>>*ch;
				  switch(*ch)
				    {
				  	 case 1:
				  	{
				  		Bookticket();
				  		break;
					}
					case2:
				  	{
						break;
					}
				   }
				  	delete ch;
				    delete Dptr;
				    
					
				
				
					
			
			} if(login==false)
			{
				cout<<"username not found !!!";
			}
			
			  		}
		void user_login()
		{ 
			int *n=new int ;
			cout<<"\n\t\t\t\t 1.sign "<<endl;
			cout<<"\n\t\t\t\t 2.login"<<endl;
			cin>>*n;
			if(*n==1)
			{
				system("cls");
				Persontype::set_data();
				char arr[]={'A','C','C','O','U','N','T',' ',' ','M','A','D','E','!'};
			    cout<<"\n\t\t\t";
		        for(int i=0;i<14;i++)
				{
				    cout<<arr[i];
				    Sleep(30);
                }
                cout<<endl;
				getch();
				system("cls");
				password();	
				}
				if(*n==2)
				{	
					user_log();
				}
				delete n;
		} 
	}
};
void Bookticket()
	{
		system("cls");
		ofstream fout;
		fout.open("Train list.txt",ios::app); 
	    ifstream fin;
	    int tn;
	    int s;
		fin.open("Train Details.txt",ios::in);
		fin>>tn;
		fin>>s;
		int *n=new int;
		cout<<"Enter how many ticket you want to book:";
		cin>>*n;
		int Tnum;
	cout<<"Enter train_number:";
		cin>>Tnum;
		string phn_num;
		cout<<"Enter the phone number of the person:";
		cin>>phn_num;
		fout<<phn_num<<" ";
			while(!fin.eof())
			{   int *ptr=new int;
		    	*ptr=0;
				if(Tnum==tn)
				{
				     *ptr=1;
				if(*n>=1)
				{
					cout<<"number of tickets booked:";
				    cout<<*n<<endl;
				    fout<<"Seat No("<<s-*n<<")";
				    cout<<"you got seat number "<<s-*n;
				    fout<<endl;
				    
				    break;
				}
				
		    if(*ptr==0)
		    {
				cout<<"\n\t\t\t Train  not found!!!!!"<<endl;
				break;
				
			}}
			
		        fin.close();
		        fout.close();
		        delete ptr;
			}
		}
class admin
{
	private:
		int train_number[5];
		int seat;
	public:
		int *ptr=new int;
		void front_end()
        { 
	       	system("cls");
	        cout<<"\n     ==================================================================";
	    	char arr[]={'R','A','I','L','W','A','Y',' ',' ','M','A','N','G','E','M','E','N','T',' ','S','Y','S','T','E','M'};
			cout<<"\n\t\t\t";
			for(int i=0;i<25;i++)
			{
				cout<<arr[i];
				Sleep(30);
            }
	        cout<<"\n     ====================================================================";
			cout<<"\n\n";
			cout<<"           <<<<<<<<<<<<<<<WELCOME_ADMIN>>>>>>>>>>>>>>>\n";
			cout<<"\n\n";
			cout<<"              ************************************\n";
			cout<<"              ||      CHOOSE YOUR OPERATION     ||\n";
			cout<<"              ||--------------------------------||\n";
			cout<<"              ||      [1] VIEW PASSENGERS       ||\n";
			cout<<"              ||      [2] ADD TRAIN             ||\n";
			cout<<"              ||      [3]  EXIT                 ||\n";
			cout<<"              ||                                ||\n";
			cout<<"              ************************************\n\n";
			cout<<"     **********************************************************\n";
			cout<<"\n\t\tENTER YOUR CHOICE: ";
			cin>>*ptr;
	        switch(*ptr)
	        {
		        case 1:
			    {
			        View_passengers ();
				    break;	
			    }
	        	case 2:
			    {
				    Add_train(); 	
				    break;
			    }
		        case 3:
					system("cls");
					getch();
					break;  
					default:
						getch();
						printf("\n\t\t\tyou entered wrong KEY!!!!");
						getch();
						system("cls");
			}
	        getch();
		}	
		void View_passengers()
		{  string l ;
		    string s ;
			ifstream fin;
			fin.open("Train list.txt",ios::in);
			fin>>l;
		   	fin>>s;
		   	int n;
	        cout<<"enter  line you  want to see:";
	        cin>>n;
		   	if(l=="0")
		   	{
		   		cout<<"the train is not booked "<<endl;
			   }  	   
			   for(int i=0;i<n;i++)
			   {
			   
	         if(!fin.eof())
	       	{
					   
		    cout<<"the phone number of passenger is :"<<l<<endl;
		   	cout<<"the seat number given to passenger is:"<<s;		
		}
			 
		}
			fin.close(); 
		}
		void Add_train()
		{
			system("cls");
			getch();
			ofstream fout;
			fout.open("Train Details.txt",ios::app);
		    int i= 0;
		    for( i=0;i<5;i++)
			{
				cout<<"\n\t\t\t ******Want to add Train******";
				cout<<"\n\t\t\tEnter train number:"<<endl;
				cin>>train_number[i];
				fout<<train_number[i]<<endl;
				cout<<"\n\t\t\t Enter number of seats:";
				cin>>seat;
				fout<<seat<<endl;
				sp=&seat;
				tp=&train_number[5];
				char ch;
				cout<<"\n\t\t\tWant to enter data (Y/N)";
				cin>>ch;
			    if(ch=='n'||ch=='N')
			    {
			        break;
			    }
			    else
			    {
			       continue;
			    }
			}   
		} 	
};
void admin_pass()
{
	int p;
	int*pas=new int ;
	ifstream fin;
	ofstream fout;
	fout.open("Admin_password.txt",ios::app);
	fin.open("Admin_password.txt");
	fin>>p;
	cout<<"\n\t\t\tenter password: ";
	cin>>*pas;
	if(*pas==p)
	{
		cout<<"\n\n\t\t\t<<<<<login successfully>>>>>";
		getch();
		system("cls");
		admin a;
		a.front_end();
		delete pas;
	}
	else
	{
		cout<<"\n\n\t\t\t\t   ERROR!!!!!";
		cout<<"\n\n\t\t\t<<<<<<<<wrong password>>>>>>>>";
		getch();
		system("cls");
    }
}
int main()
{
	time_t ttime = time(0);
    char* dt = ctime(&ttime);
    cout << "\n\t\t\t  "<< dt << endl;
	char arr[]={'R','A','I','L','W','A','Y',' ',' ','M','A','N','G','E','M','E','N','T',' ','S','Y','S','T','E','M'};
	cout<<"\n\t\t\t";
	for(int i=0;i<25;i++)
	{
		cout<<arr[i];
		Sleep(30);
    }
	cout<<"\n\t\t\t*********************************\n";
	cout<<"\n\t\t\t<<<<<<<<<<WELCOME USERS>>>>>>>>>>\n";
	cout<<"\n\n\t\t\t\t      MENU\n";
	cout<<"\n\t\t\t[1] USER LOGIN \n";
	cout<<"\n\t\t\t[2] ADMIN";
	cout<<"\n\n\t\t\t[3] EXIT\n";
	cout<<"\n\t\t\t********************************";
	cout<<"\n\t\t\tENTER YOUR CHOICE: ";
	int*ptr=new int;
	cin>>*ptr;
	switch(*ptr)
	{
		case 1:
		{
			user u;
			u.user_login();
			break;	
		}
	    case 2:
      	{
      	    admin_pass();
      		break;	
		}
		case 3:
		{ 
			system("cls");
			cout<<"\n\t\t\t =========================================\n";
			cout<<"\t\t\t\t\t*******RAILWAY RESERVATION SYSTEM*******\n";
			cout<<"\t\t\t ===============================================\n";
			cout<<"\n\n\t\t\BROUGHT TO YOU BY \n\n AYYAN IQBAL\n TAHA JABBAR";
			getch();
			break;
			default:
			system("cls");
			cout<<"\n\t\t\t==============================================\n";
			cout<<"\t\t\t\t\t*******RAILWAY RESERVATION SYSTEM*******\n";
			cout<<"\n\n\t\t\t<<<<<<<<YOU ENTERED WRONG CHOICE>>>>>>>>\n";
			cout<<"\t\t\t<<<<<<<<PLEASE ENTER RIGHT THING>>>>>>>>\n";
			getch();
			system("cls");		
			main();
        }
return 0;
}

}
