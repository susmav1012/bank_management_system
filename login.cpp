/*#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<windows.h>*/
class entry{
	protected:
	char uname[30];
	char pwd[20];
	
	public:
		virtual int getdata(char*){}
		virtual void putfile(entry&,char*){}
		
};

class signup:public entry{
	
	public:
		int getdata(char* fil)
		{
		    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t  LOGIN PAGE"<<endl;
		    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t-----------------"<<endl;
		    blue();  
		    cout <<"\t\t\t\t\t\t\t\t\t|1.Signup to proceed your banking experience            |\n\t\t\t\t\t\t\t\t\t|2.Enter the user name and password to sign up          |\n\t\t\t\t\t\t\t\t\t|3.Enter tab bar to confirm the password                |" << endl<<endl;
			reset();
			int i=0;char ch;
			cout<<"\n\t\t\t\t\t\t\t\t\t_________________________________________________"<<endl;
			cout<<"\n\t\t\t\t\t\t\t\t\t          ENTER USERNAME:";
			fflush(stdin);
			cin.getline(uname,30);
			cout<<"\n\t\t\t\t\t\t\t\t\t          ENTER PASSWORD:";
			while((ch=getch())!='\n')
			{
				if(ch=='\t')
				break;
				else if(ch=='\b')
				{
					i=i-1;
                	cout<<"\b";
				}
				else if(ch!='\n'&&ch!='\r')
				{
					pwd[i++]=ch;
					putch('*');
				}
			}
			pwd[i]='\0';
			if(upvalidate(uname,fil))
			return 1;
			else
			return 0;
			
		}
		
		void putfile(entry& obj,char* fil)
		{
			ofstream file(fil,ios::binary|ios::app);
			file.write((char*)&obj,sizeof(obj));
			file.close();
			
			cout <<"\n\t\t\t\t\t\t\t\t\t=================================================================================" <<endl;
			green();
			cout<<"\t\t\t\t\t\t\t\t\tSIGNUP SUCCESSFUL!!!\n"<<endl;
			reset();
			cout <<"\t\t\t\t\t\t\t\t\t=================================================================================" <<endl;
			
		}
		
		int upvalidate(char* user,char* fil)
		{
			signup temp;
			ifstream file(fil,ios::binary);
			while(file.read((char*)&temp,sizeof(temp)))
			{
				if(!strcmp(temp.uname,user))
				{
					
					cout <<"\n\t\t\t\t\t\t\t\t\t=================================================================================" <<endl;
					red();
					cout<<"\t\t\t\t\t\t\t\t\tUSERNAME ALREADY EXIST!!\n\t\t\t\t\t\t\t\t\tPLEASE TRY AGAIN\n"<<endl;
					reset();
					cout <<"\t\t\t\t\t\t\t\t\t=================================================================================" <<endl;
					
					return 0;
				}
			}
			return 1;
		}
};

class signin:public entry{
	public:
		int getdata(char* fil)
		{
			cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t  LOGIN PAGE"<<endl;
		    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t-----------------"<<endl;
		    blue();  
		    cout <<"\t\t\t\t\t\t\t\t\t|1.Signin to proceed your banking experience            |\n\t\t\t\t\t\t\t\t\t|2.Enter the user name and password to sign up          |\n\t\t\t\t\t\t\t\t\t|3.Enter tab bar to confirm the password                |" << endl<<endl;
			reset();
			int i=0;char ch;
			cout<<"\n\t\t\t\t\t\t\t\t\t_________________________________________________"<<endl;
			cout<<"\n\t\t\t\t\t\t\t\t\t          ENTER USERNAME:";
			fflush(stdin);
			cin.getline(uname,30);
			cout<<"\n\t\t\t\t\t\t\t\t\t          ENTER PASSWORD:";
			while((ch=getch())!='\n')
			{
				if(ch=='\t')
				break;
				else if(ch=='\b')
				{
					i=i-1;
                	cout<<"\b";
				}
				else if(ch!='\n'&&ch!='\r')
				{
					pwd[i++]=ch;
					putch('*');
				}
			}
			pwd[i]='\0';
			if(invalidate(uname,pwd,fil))
				return 1;
			else
				return 0;
		}
		
		int invalidate(char* user,char* pass,char* fil)
		{
			signin temp;
			ifstream file(fil,ios::binary);
			while(file.read((char*)&temp,sizeof(temp)))
			{
				if(!strcmp(temp.uname,user))
				{
					if(!strcmp(temp.pwd,pass))
					{
						
						cout <<"\n\t\t\t\t\t\t\t\t\t=================================================================================" << endl;
						green();
						cout<<"\n\t\t\t\t\t\t\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!"<<endl;
						reset();
						cout <<"\t\t\t\t\t\t\t\t\t=================================================================================" << endl;
						
						return 1;
					}
					else
					{
						
						cout <<"\n\t\t\t\t\t\t\t\t\t=================================================================================" << endl;
						red();
						cout<<"\n\t\t\t\t\t\t\t\t\tYOUR PASSWORD IS INCORRECT!!!PLEASE TRY AGAIN LATER!!!!"<<endl;
						reset();
						cout <<"\t\t\t\t\t\t\t\t\t=================================================================================" <<endl;
						
						return 0;
					}
				}
			}
			cout <<"\n\t\t\t\t\t\t\t\t\t=================================================================================" <<endl;
			red();
			cout<<"\n\t\t\t\t\t\t\t\t\tUSER NOT FOUND!!"<<endl;
			reset();
			cout <<"\t\t\t\t\t\t\t\t\t=================================================================================" <<endl;
			return 0;
		}
};

void sign_up_user()
{
	char ufile[15]="login.dat";
	entry *ptr;
	ptr=new signup;
	do
	{
		if(ptr->getdata(ufile))
		{
			ptr->putfile(*ptr,ufile);
			break;
		}
	}while(1);	
	system("pause");
}

void sign_in_user()
{
	char ufile[15]="login.dat";
	entry *ptr;
	ptr=new signin;
	do
	{
		if(ptr->getdata(ufile))
			break;
		else
		{
			red();
			//cout <<"\n\t\t\t\t\t\t\t\t\t=================================================================================" <<endl;
			cout<<"\t\t\t\t\t\t\t\t\tSIGN IN UNSUCCESSFUL\n\t\t\t\t\t\t\t\t\tPLEASE TRY AGAIN LATER!!!\n"<<endl;
			reset();
			cout <<"\t\t\t\t\t\t\t\t\t=================================================================================" <<endl;
			
		}
	}while(1);	
	system("pause");
}

void sign_up_off()
{
	system("cls");
	char ufile[15]="offlogin.dat";
	entry *ptr;
	ptr=new signup;
	do
	{
		if(ptr->getdata(ufile))
		{
			ptr->putfile(*ptr,ufile);
			break;
		}
	}while(1);	
	system("pause");
}

void sign_in_off()
{
	system("cls");
	char ufile[15]="offlogin.dat";
	entry *ptr;
	ptr=new signin;
	do
	{
		if(ptr->getdata(ufile))
			break;
		else
		{
			red();
			//cout <<"\n\t\t\t\t\t\t\t\t\t=================================================================================" <<endl;
			cout<<"\t\t\t\t\t\t\t\t\tSIGN IN UNSUCCESSFUL\n\t\t\t\t\t\t\t\t\tPLEASE TRY AGAIN LATER!!!\n"<<endl;
			reset();
			cout <<"\t\t\t\t\t\t\t\t\t=================================================================================" <<endl;
			
		}
	}while(1);	
	system("pause");
}

/*int main()
{
	int ch;
	do
	{
	cout<<"\t\tMenu"<<endl;
	cout<<"1.Sign-Up\n2.Sign-IN\n0.Exit\nEnter the Choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:
			sign_up_off();
            break;
		case 2:
			sign_in_off();
            break;
        case 0:
            cout<<"Thank You!";
            break;
		default:
			cout<<"Invalid Choice"<<endl;
	}
	}while(ch);
}*/
