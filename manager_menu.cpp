class employee                                                                           //employee class
{
	protected:                                                                           //protected data member
		
	int id;
	
	private:                                                                             //private data members
		
	char name[50];
	char dob[11];
	int age;
	char position[30];
	char address[100];
	char phn[11];
	 
	public:                                                                                //public members
	
	friend employee& modify(employee&);
	friend void modifyEmployee();
	friend void deleteEmployee();
	void getData();
	void createFile(employee &s);
	void display();
	int idvalidate(int &n);
	int phnvalidate(char *phn);
	int agevalidate();
	void generate(int l, int r, int count);
};
void employee::generate(int l, int r, int count)                                 // function to generate random account number to the customer
{
		
		id = (rand() % (r - l + 1)) + l; 
		cout << "\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\tEMPLOYEE ID NUMBER IS ";
		yellow();                                                           //sets the account no colour to yellow
		cout << id << endl;
		reset();                                                           // resets to the default colour
		cout << "\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void employee::getData()                                                                    //get data function
{
	
	cout<<"\t\t\t\t\t\t\t\t\t\tENTER EMPLOYEE DETAILS:"<<endl;
	cout <<"\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl<< endl;
	
	
	fflush(stdin);
	cout<<"\t\t\t\t\t\t\t\t\t\tENTER THE EMPLOYEE NAME:";
	cin.getline(name,50);
	
	fflush(stdin);
	cout<<"\t\t\t\t\t\t\t\t\t\tENTER THE EMPLOYEE DOB(DD/MM/YYYY):";
	strcpy(dob,get_date(25));

	fflush(stdin);
	cout<<"\t\t\t\t\t\t\t\t\t\tENTER THE EMPLOYEE AGE:";
	age=agevalidate();
			
	fflush(stdin);
	cout<<"\t\t\t\t\t\t\t\t\t\tENTER EMPLOYEE POSITION:";
	cin.getline(position,30);
			
	fflush(stdin);
	cout<<"\t\t\t\t\t\t\t\t\t\tENTER EMPLOYEE ADDRESS:";
	cin.getline(address,100);
	
	fflush(stdin);
	cout<<"\t\t\t\t\t\t\t\t\t\tENTER EMPLOYEE CONTACT(+91):";
	cin.getline(phn,11);
	do
	{
	if(phnvalidate(phn))                                                                         //check phone number validation
	break;
	}while(1);
	int l = 20051000, r = 20051999, count = 1;
	srand(time(0));                                                       //gets random number
	generate(l, r, count);                                                //generates the account number for the customer
	ofstream file("employee_number.txt",ios::app);
	file<<name<<endl<<id<<endl;                                              // writes those names and ID number in text file for referrence
	file.close();
		
}


void employee::createFile(employee &s)                                                           //create file function
{
	
	ofstream file("employee_details.dat",ios::binary | ios::app);                                //open file in append mode
	if (!file)
	{
		cout << "\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
		red();
		cout << "\t\t\t\t\t\t\t\t\t\tTHERE IS SOME KIND OF SERVER ERROR............" << endl;
		reset();
		cout << "\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
	}
	else
	{
	file.write((char*)&s,sizeof(s));                                                              //write and close the file
	file.close();  
   }
}


void employee::display()                                                                           //display function
{
	cout<<"\t\t\t\t\t\t\t\t\t\t----------------------------------------------"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\tID: "<<id<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\tNAME:"<<name<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\tDOB:"<<dob<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\tAGE:"<<age<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\tPOSITION:"<<position<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\tADDRESS:"<<address<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\tCONTACT: (+91)"<<phn<<endl;
}

int employee::phnvalidate(char *phn)                                                              //function to validate phone number
{
	
	employee obj;
	ifstream f("employee_details.dat",ios::in|ios::binary);
	while (f.read((char*)&obj, sizeof(obj)))
		{
			if (!strcmp(obj.phn, phn))                               // if the contact is same as in the file return 0
			{
				cout << "\t\t\t\t\t\t\t\t\t\t=======================================================" << endl;
				red();
				cout << "\t\t\t\t\t\t\t\t\t\tCONTACT ALREADY EXIST!" << endl;
				reset();
				cout << "\t\t\t\t\t\t\t\t\t\t=======================================================" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\tENTER ANOTHER CONTACT:";
				cin.getline(phn, 100);
				f.close();
				return 0;
			}
			else if(strlen(phn)!=10)
			{
				cout << "\t\t\t\t\t\t\t\t\t\t=======================================================" << endl;
				red();
				cout << "\t\t\t\t\t\t\t\t\t\tCONTACT DOES NOT HAVE 10 NUMBERS!" << endl;
				reset();
				cout << "\t\t\t\t\t\t\t\t\t\t=======================================================" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\tENTER AGAIN:";
				cin.getline(phn, 100);
				f.close();
				return 0;
			}
			else if(phn[0]!='9'&&phn[0]!='8'&&phn[0]!='7'&&phn[0]!='6')
			{
				cout << "\t\t\t\t\t\t\t\t\t\t=======================================================" << endl;
				red();
				cout << "\t\t\t\t\t\t\t\t\t\tCONTACT FORMAT IS WRONG!" << endl;
				reset();
				cout << "\t\t\t\t\t\t\t\t\t\t=======================================================" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\tENTER AGAIN:";
				cin.getline(phn, 100);
				f.close();
				return 0;
			}
		}
		f.close();
		return 1;  
}


int employee::agevalidate()                                                                            //function to validate age 
{
	
	cin>>age;
	while(age<25||age>60)                                                                              //check for the valid age
	{
	red();
	cout<<"\t\t\t\t\t\t\t\t\t\tINVALID AGE!!!\n\t\t\t\t\t\t\t\t\t\tYOU'RE NOT ELIGIBLE TO APPLY";
	reset();
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\tENTER AGE AGAIN:";
	cin>>age;
	}
	return age;
}


void addRecord()                                                                                         //add record function
{
	employee s;
	s.getData();
	s.createFile(s);
}


void readDisplay()                                                                                       //display function
{
	
	char found='f';
	employee s;
	ifstream f("employee_details.dat",ios::in|ios::binary);                                              //open the file in read mode
	if (!f)
	{
		red();
		cout << "\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
		
		cout << "\t\t\t\t\t\t\t\t\t\tTHERE IS SOME SERVER ERROR IN THE BANK............" << endl;
		
		cout << "\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
	    reset();
	}
	else
	{
		yellow();
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tDETAILS OF EMPLOYEE"<<endl<<endl;
	reset();
	cout << "\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	while(f.read((char*)&s,sizeof(s)))
	{
	s.display();                                                                                              //read and dispaly the account details 
	found='t';                                                                                                //assign flag
}
	
	f.close();
if (found == 'f')                                                                                         //if not found print not found
	{
		cout << "\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		red();
		cout << "\t\t\t\t\t\t\t\t\t\tTHERE ARE NO RECORDS IN THE BANK............" << endl<< endl;
		reset();
		cout << "\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}
}
}


employee& modify(employee &emp)                                                                                   //modify menu function
{
	
	int ch,f;
	char phno[11];
	while(1)
	{
		
		system("cls");
	    cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tMODIFY MENU"<<endl;
		cout<<"\n\t\t\t\t\t\t\t\t\t\t============================================="<<endl;
		blue();
		cout<<"\n\t\t\t\t\t\t\t\t\t\t| Please enter the correct field name you want to modify |";
		reset();
		cout<<"\n\t\t\t\t\t\t\t\t\t\t============================================="<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t[1]Name\n\t\t\t\t\t\t\t\t\t\t[2]DOB\n\t\t\t\t\t\t\t\t\t\t[3]Age\n\t\t\t\t\t\t\t\t\t\t[4]Position\n\t\t\t\t\t\t\t\t\t\t[5]Address\n\t\t\t\t\t\t\t\t\t\t[6]Contact\n\t\t\t\t\t\t\t\t\t\t[0]Exit"<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\tENTER THE CHOICE:";
		cin>>ch;
	
		switch(ch)                                                                                                   //get the correct case and modify
		{
			case 1:
				fflush(stdin);
				cout<<"\t\t\t\t\t\t\t\t\t\tOLD NAME:"<<emp.name<<endl;
				cout<<"\t\t\t\t\t\t\t\t\t\tENTER THE NEW NAME:";
				cin.getline(emp.name,50);
				break;
				
			case 2:
				fflush(stdin);
				cout<<"\t\t\t\t\t\t\t\t\t\tOLD DOB:"<<emp.dob<<endl;
				cout<<"\t\t\t\t\t\t\t\t\t\tENTER THE NEW DOB(DD/MM/YYYY):";
				strcpy(emp.dob,get_date(25));
				break;
				
			case 3:
				fflush(stdin);
				cout<<"\t\t\t\t\t\t\t\t\t\tOLD AGE:"<<emp.age<<endl;
				cout<<"\t\t\t\t\t\t\t\t\t\tENTER THE NEW AGE:";
				emp.age=emp.agevalidate();
				break;
				
			case 4:
				fflush(stdin);
				cout<<"\t\t\t\t\t\t\t\t\t\tOLD POSITION:"<<emp.position<<endl;
				cout<<"\t\t\t\t\t\t\t\t\t\tENTER THE NEW POSITION:";
				cin.getline(emp.position,30);
				break;
				
			case 5:
				fflush(stdin);
				cout<<"\t\t\t\t\t\t\t\t\t\tOLD ADDRESS:"<<emp.address<<endl;
				cout<<"\t\t\t\t\t\t\t\t\t\tENTER THE NEW ADDRESS:";
				cin.getline(emp.address,100);
				break;
				
			case 6:
				fflush(stdin);
				cout<<"\t\t\t\t\t\t\t\t\t\tOLD CONTACT: +91"<<emp.phn<<endl;
				cout<<"\t\t\t\t\t\t\t\t\t\tENTER THE NEW CONTACT:(+91)";
				cin.getline(phno,11);
				do
				
				{
					if(emp.phnvalidate(phno))
					{
						strcpy(emp.phn,phno);
						break;
					}
				}while(1);
				break;
				
			case 0:
				return emp;
				
			default:
				cout<<"\n\n\t\t\t\t\t\t\t\t\t\t============================="<<endl;
				red();
				cout<<"\t\t\t\t\t\t\t\t\t\tENTER THE CORRECT OPTION"<<endl;
				reset();
				cout<<"\t\t\t\t\t\t\t\t\t\t============================="<<endl;
		}
		
		system("pause");
	}
	return emp;
}


void modifyEmployee()                                                                                       //modify function
{
	
	employee emp;
	int n,fo=0;
	cout<<"\t\t\t\t\t\t\t\t\t\tENTER THE ID TO MODIFY:";
	cin>>n;
	fstream f("employee_details.dat",ios::in|ios::out|ios::binary);                                        //open the file in read and write mode
	if (!f)                                                                                                //if not found
	{
		cout << "\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
		red();
		cout << "\t\t\t\t\t\t\t\t\t\tTHERE IS SOME KIND OF SERVER ERROR............" << endl;
		reset();
		cout << "\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
	}
	else
	{
	while(f.read((char*)&emp,sizeof(emp)))                                                                  //if found read the file and check for the id match
	{
		if(emp.id==n)
		{
			emp=modify(emp);
			
			f.seekp((int)f.tellg()-sizeof(emp), ios::beg);
			f.write((char*)&emp,sizeof(emp));                                                               //modify and write the data
			fo=1;
			break;
		}
	}
	f.close();
	fo?cout<<"\n\t\t\t\t\t\t\t\t\t\t=====================================================\n\t\t\t\t\t\t\t\t\t\tMODIFICATION IS SUCCESSFUL!\n\t\t\t\t\t\t\t\t\t\t====================================================="<<endl:cout<<"\n\t\t\t\t\t\t\t\t\t\t=====================================================\n\t\t\t\t\t\t\t\t\t\tDATA NOT FOUND\n\t\t\t\t\t\t\t\t\t\t====================================================="<<endl;
}
}


void deleteEmployee()                                                                                     //delete emp function
{
	
	int pos, flag = 0, n;
		employee obj;                                                                                        //object creation
		ifstream f1;										                                                //ifstream object
		f1.open("employee_details.dat", ios::in | ios::binary);                                               //open the old file in read mode
		ofstream f2;										                                              //ofstream object
		f2.open("employee_details_temp.dat", ios::out | ios::binary);		                                              //open temp file in write mode

		if (!f1)                                                                                        //if there is no file
		{
			cout << "\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
			red();
			cout << "\n\t\t\t\t\t\t\t\t\t\tTHERE IS SOME SERVER ERROR IN THE BANK............" << endl;
			reset();
			cout << "\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
		}
		else
		{
			cout << "\t\t\t\t\t\t\t\t\t\tENTER THE EMPLOYEE NUMBER TO BE DELETED:";                          //get the acc number to be deleted
			cin >> n;
			cout << "\n\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			
			while (!f1.eof())
			{
				f1.read((char *)&obj, sizeof(obj));
				if (f1) // if(org)checks the buffer record in the file
				{
					if (obj.id == n) //comparing the roll no with roll no of record to be deleted
					{
						flag = 1;
					
					}
					else
					{
						f2.write((char *)&obj, sizeof(obj));                                                  // copy the record of "bankdatbase" file to "temp" file                                       
						                                    
					}
				}
			}
			f2.close();                                                                                    //close the files
			f1.close();
			remove("employee_details.dat");				                                                         // delete the old file
			rename("employee_details_temp.dat", "employee_details.dat");                                                          // rename new file to the older file

			if (flag == 1) //if the acc no is found and deleted
			{
				
				cout << "\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				green();
				cout << "\t\t\t\t\t\t\t\t\t\tRECORD IS DELETED SUCCESSFULLY" << endl<< endl;
				reset();
				cout << "\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				
			}

			else
			{
				cout << "\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				red();
				cout << "\t\t\t\t\t\t\t\t\t\tRECORD IS NOT FOUND TO BE DELETED" << endl<< endl;
				reset();
				cout << "\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			}
		}
}
class account : public Bankdata
{
	
public:
	
	void display()                                                                                       //function to display the details of the customer
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t================================================" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\tACCOUNT NUMBER: " << acc_no << endl;
		cout << "\t\t\t\t\t\t\t\t\t\tUSER NAME:" << name << endl;
		cout << "\t\t\t\t\t\t\t\t\t\tDOB:" << dob << endl;
		cout << "\t\t\t\t\t\t\t\t\t\tAGE:" << age << endl;
		cout << "\t\t\t\t\t\t\t\t\t\tOCCUPATION:" << occupation << endl;
		cout << "\t\t\t\t\t\t\t\t\t\tADDRESS:" << address << endl;
		cout << "\t\t\t\t\t\t\t\t\t\tCONTACT: +91" << phn_no << endl;
		cout << "\t\t\t\t\t\t\t\t\t\tBALANCE:" << total_balance << endl;
	}
};


void display_account_details()                                                                       //function to search and display the details of the customer
{
	
	int n=0;
	account a;
	yellow();
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tACCOUNT DETAILS" << endl;
	reset();
	cout << "\t\t\t\t\t\t\t\t\t\t================================================" << endl;
	ifstream f("bankdatabase.dat", ios::in | ios::binary);                                           //file is opened in read mode
	if(!f)                                                                                          //if the file is not created or error in opening the file
	{
	cout << "\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
	red();
	cout << "\n\t\t\t\t\t\t\t\t\t\tTHERE ARE NO RECORD IN THE BANK..................................." << endl;
	reset();
	cout << "\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
    }
   else
    {
	while (f.read((char *)&a, sizeof(a)))
	{
	n=1;
	a.display();
    }
    f.close();
    }
if(n==0)                                                                                          //if there is no records in the file
	{
		red();
		cout<<"\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"\t\t\t\t\t\t\t\t\t\tTHERE ARE NO RECORDS IN THE BANK"<<endl;
		cout<<"\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		reset();
	} 
}


void manager_menu()                                                                                            //menu function
{ 
	sign_in_off();
	int i,n,ch;
	while(1)
	{
	system("cls");
	cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tMANAGER MENU"<<endl;
	cout<<"\n\t\t\t\t\t\t\t\t\t\t============================================="<<endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t[1]Create Employee\n\t\t\t\t\t\t\t\t\t\t[2]Employee Details\n\t\t\t\t\t\t\t\t\t\t[3]Fixed Deposit Details\n\t\t\t\t\t\t\t\t\t\t[4]Loan Details\n\t\t\t\t\t\t\t\t\t\t[5]Accounts Details\n\t\t\t\t\t\t\t\t\t\t[6]Modify Employee Detail\n\t\t\t\t\t\t\t\t\t\t[7]Delete Employee\n\t\t\t\t\t\t\t\t\t\t[0]Exit\n";
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\tENTER THE OPTION YOU NEED TO DO:     ";
	cin>>ch;
	
	switch(ch)                                                                                                //choose for the correct case
	{
		case 1:
			sign_up_off();
			addRecord();
			break;
			
		case 2:
			readDisplay();
			break;
			
		case 3:
			display_all_fd_application();
			break;
			
		case 4:
			display_all_loan_application();
			break;
			
		case 5:
			display_account_details();
			break;
			
		case 6:
			modifyEmployee();
			break;
			
		case 7:
			deleteEmployee();
			break;
			
			
		case 0:
			cout<<"\n\t\t\t\t\t\t\t\t\t\t============================================="<<endl;
			green();
			cout<<"\t\t\t\t\t\t\t\t\t\tTHANK YOU !!";
			reset();
			cout<<"\n\t\t\t\t\t\t\t\t\t\t============================================="<<endl;
			return;
			
		default:
		    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t============================="<<endl;
			red();
			cout<<"\t\t\t\t\t\t\t\t\t\tENTER THE CORRECT OPTION"<<endl;
			reset();
			cout<<"\t\t\t\t\t\t\t\t\t\t============================="<<endl;
	}
	
	cout<<"-------------------------------------------------------"<<endl;
	system("pause");
	}
}
