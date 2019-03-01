#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;

//declare variables
void Add();
void Edit();
void Display();
void Delete();
void Search();

struct Inventory
{
	string name;
	char tama;
	char a,b,x,y,z;
    char fname[25],lname[25],mname[25], address[25];
    int bday;
    int number;
    int age;
    int password;
    int choice;
};

int main()
{
	int m,d,c,user,username;
string first;
cout<<"Enter your First Name: ";
getline(cin, first);

string last;
cout<<"Enter your Last Name: ";
getline(cin, last);

string middle;
cout<<"Enter your Middle Name: ";
getline(cin, middle);

string age;
cout<<"Enter your Age: ";
getline(cin, age);

string birthday;
cout<<"Enter you Birthday"<<endl;
cout<<"MM: ";
cin>>m;
cout<<"DD: ";
cin>>d;
cout<<"YYYY: ";
cin>>c;

string password;
cout<<"Enter your Password: ";
int num[6];

int p;
cin >> num[6];

ostringstream pass;

pass << num[6];

string pass1 = pass.str();

string r =pass1.substr(0, 2);

string n=pass1.substr(2, 5);

stringstream pass2(r);
stringstream pass3(n);

int x=0;
int y=0;

pass3 >> x;
pass2 >> y;

p = x/y;


cout<<"Welcome you are now registered!"<<endl;

cout<<first<<last<<middle<<endl;

cout<<age<<endl;
cout<<m<<"-"<<d<<"-"<<c<<endl;
cout<<password<<endl;

string agun;
int i=0;
int j=last.size()-1;
while (j>i){
char temp;
temp=last[j];
last[j]=last[i];
last[i]=temp;
i++;
j--;}
cout <<"Username: "<< first.at(0)<<first.at(1)<<first.at(2)<<last.at(2)<<last.at(1)<<last.at(0)<<p<<endl;
cout<<"Password: "<<pass1<<endl;
cout<<endl;
cout<<"-------------­-------------------WELCOME--------------­------------------"<<endl;
cout <<"Username: "<< first.at(0)<<first.at(1)<<first.at(2)<<last.at(2)<<last.at(1)<<last.at(0)<<p<<endl;
cout<<"Password: "<<pass1<<endl;
    int choice;
    do
    {
         cout << "MENU" << endl;
        cout<<"1) Add a Record "<<endl;
        cout<<"2) Display Records "<<endl;
        cout<<"3) Edit Record "<<endl;
        cout<<"4) Delete Record"<<endl;
        cout<<"5) Search Record"<<endl;
        cout<<"6) Exit "<<endl<<endl;
        cout<<"Please choose option:";
        cin >> choice;
        
        switch (choice)// change into an if else statement then turn into a function
        {
        case 1:
            Add();
            break;	//Add record
        case 2:
            Display();
            break;	//Display record
        case 3:
            Edit(); 
            break; //Edit Record
        case 4:
            Delete();
            break;   //Delete record
        case 5:
        	Search(); 
        	break;   //Search record

        default:
            cout << "Invalid Selection" << endl;
        }
    }
    while
    (choice <= 4);
    system("PAUSE");
    return 0;
}
//Add function
void Add()
{
    system("CLS"); //clears screen
    fstream fout;
    const int size = 3;
    char ch;
    int i = 0;
    fout.open("Records.txt", ios::out);
    Inventory inv;
    do
    {
        cout << "Enter First name: " << endl;
        cin.ignore();
        cin >> inv.fname;
        cout<< "Enter Last name: " << endl;
        cin >> inv.lname;
        cout<< "Enter Middle name: " << endl;
        cin >> inv.mname;
        cout<< "Enter Age: " << endl;
        cin >> inv.age;
        cout<< "Enter birthday: " << endl;
        cin >> inv.bday;
        cout<< "Enter Password" << endl;
        cin.ignore();
        cin >> inv.password;
        

//write record to file
        fout.write(reinterpret_cast<char*>(&inv), sizeof(inv));
        cout << "Do you want to add another record? " << endl;
        cin >> ch;
    }
      while
    (ch == 'Y' && 1 < 4);

//close the file
    fout.close();
}
//"Display" function
void Display()
{
    fstream fout;
    fout.open("Records.txt", ios::in);
    Inventory inv;
    fout.read(reinterpret_cast <char*> (&inv), sizeof(inv));
    while (true)
  	{
    	if (!fout.good()) break;
    	cout<<"******* INFO *******"<<endl;
    	cout << "\nName\t: ";
        cout << inv.fname,inv.lname,inv.mname;
        cout << "\nAge: ";
        cout << inv.age;
        cout << "\nBirthday\t: ";
        cout << inv.bday;
        cout <<"Username: "<<inv.fname[0]<<inv.fname[1]<<inv.fname[2]<<inv.lname[2]<<inv.lname[1]<<inv.lname[0]<<endl;
        cout<<"Password: "<<inv.password<<endl;
        cout<<endl;
        cout<<"******* WELCOME *******"<<endl;
        cout <<"Username: "<<inv.fname[0]<<inv.fname[1]<<inv.fname[2]<<inv.lname[2]<<inv.lname[1]<<inv.lname[0]<<endl;
        cout<<"Password: "<<inv.password<<endl;
        cout<<"******* END OF RECORD *******"<<endl;
        fout.read(reinterpret_cast <char*> (&inv), sizeof(inv));
	}
	//close the file
    fout.close();

}
void Edit()
{
	char x,y,z;
	
    system("CLS"); //clears screen
    fstream fout;
    const int size = 3;
    char ch;
    int i = 0;
    fout.open("Records.txt", ios::out);
    Inventory inv;
    do
    {
    cout<<"Enter your name according on the format below:\n"<<endl;
	
	cout<<"Last Name:\n";
	cin>>inv.lname;
	
	cout<<"First Name:\n";
	getline (cin,inv.name);
  	cin>>inv.fname;
	
	cout<<"Password:\n";
	getline (cin,inv.name);
	cin>>inv.password;
	
	
	cout<<"\nYour Name & password is:\n";
	cout<<" [1] "<<inv.lname<<endl;
	cout<<" [2] "<<inv.fname<<endl;
	cout<<" [3] "<<inv.password<<endl;
	
	cout<<"\nEnter the name that you want to edit:"<<endl;
	
	std::cin>>inv.tama;
	
	switch (inv.lname[50])
     {
     	case 'A':
		cout<<"What do you want to update?"<<endl;	
		cin>>x;
		cout<<"\nYour updated into:"<<endl;
		cout <<"Username: "<<inv.fname[0]<<inv.fname[1]<<inv.fname[2]<<inv.lname[2]<<inv.lname[1]<<inv.lname[0]<<endl;
		cout<<"Password: "<<inv.password<<endl;
		fout.read(reinterpret_cast <char*> (&inv), sizeof(inv));
     	break;
     	
     	case 'B':
		cout<<"Drop the name you want to update"<<endl;
		cin>>y;	
		cout<<"\nYour name is updated into:"<<endl;
		cout <<"Username: "<<inv.fname[0]<<inv.fname[1]<<inv.fname[2]<<inv.lname[2]<<inv.lname[1]<<inv.lname[0]<<endl;
		cout<<"Password: "<<inv.password<<endl;
		fout.read(reinterpret_cast <char*> (&inv), sizeof(inv));
     	break;
     	
     	case 'C':
		cout<<"Drop the name you want to update"<<endl;
		cin>>z;	
		cout<<"\nYour name is updated into:"<<endl;
		cout <<"Username: "<<inv.fname[0]<<inv.fname[1]<<inv.fname[2]<<inv.lname[2]<<inv.lname[1]<<inv.lname[0]<<endl;
		cout<<"Password: "<<inv.password<<endl;
		fout.read(reinterpret_cast <char*> (&inv), sizeof(inv));
 	break;
 	
 	default:
            cout << "Invalid Selection" << endl;

	//write record to file
        fout.write(reinterpret_cast<char*>(&inv), sizeof(inv));
        cout << "Do you want to edit record? " << endl;
        cin >> inv.tama;
    }
    while
    (inv.tama == 'A' && 1 < 3);
   
//close the file
    fout.close();
}
 while
    (inv.tama == 'A' && 1 < 4);
    
}
void Delete()
{
	
}
void Search()
{
	
}
