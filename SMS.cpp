#include <iostream>
#include<fstream>
#include<windows.h>
using namespace std;

class student
{
	public : 
        char name[80];
        char id[80];
        int roll;
        float sub1,sub2,sub3,sub4,sum,average;
};

void welcome();
void menu();
void input();
void separate_data(int);
void full_report();
void result(int);
void deleterecord(int);
void modify(int);

int main()
{
    system("cls");
	system("color b");
    welcome();
    int choice;

    do{
        system("cls");
        system("color a");
        cout<<"\n\n";
        cout<<"\t\t\t\t==================== SMS: Student Management System ===================="<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t\t1. MAIN MENU\n";
        cout<<"\t\t\t\t\t\t2. EXIT\n";
        cout<<"Enter Option :";
        cin>>choice;
        system("cls");
        switch(choice)
             {
                  case 1:
                     {
                          menu();
                          break;
                     }
                  case 2:
                     {         
	                      cout << "\t\t\t\t\t\t\t     We Were Glad To Have You On-Board With Us."<<endl;
	                      return 0;
                     }
                  default : 
                  {
                          cout<<"Invalid Input! Please Try Again";
                          main();
                  }
             }
        }while(choice!='2');
    return 0;
}
void input()
{
    system("cls");
    student s;
    ofstream outfile;
    outfile.open("Report.txt",ios::app|ios::binary);
    if(outfile.fail())
    {
        cout<<"ERROR => FILE NOT FOUND ! press enter any key to continue";
        cin.ignore();
        cin.get();
    }
    cout<<"\n\n";
    cout<<"\t\t\t\t======= Please Enter Student Data ========\n\n";
    cout<<"Name :";
    cin.ignore();
    cin.getline(s.name,80);
    cout<<"Registration Number : ";
    cin.ignore();
    cin.get(s.id,80);
    cout<<"Roll Number :";
    cin>>s.roll;
    cout<<"Subject 1 Marks :";
    cin>>s.sub1;
    cout<<"Subject 2 Marks :";
    cin>>s.sub2;
    cout<<"Subject 3 Marks :";
    cin>>s.sub3;
    cout<<"Subject 4 Marks :";
    cin>>s.sub4;
    s.sum=s.sub1+s.sub2+s.sub3+s.sub4;
    s.average=(s.sum/4);
    outfile.write(reinterpret_cast<char *> (&s), sizeof(student));
    outfile.close();
    cout<<endl;
    cout<<"\t\t\t\t\t\tFile Saved Successfully!"<<endl;
    cout<<endl;
    cout<<"press any key to continue...";
    cin.ignore();
    cin.get();
}

void welcome()

{

    cout << "\n\n";
    Sleep(200);
    cout << "\t\t\t\t * * *  **** *      ****  ***   ***   ****   " << endl;
    Sleep(200);
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *        "<< endl;
    Sleep(200);
    cout << "\t\t\t\t * * * ***** *     *     *   * * * * *****    " << endl;
    Sleep(200);
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *         " << endl;
    Sleep(200);
    cout << "\t\t\t\t  ***   **** *****  ****  ***  * * *  ****     " << endl;
    Sleep(200);
    cout<<endl;
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(400);
    cout<<"\t\t\t\tSMS: Student Management System"<<endl;
    Sleep(400);
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(400);
    cout<<"press any key to continue...";
    cin.ignore();
    cin.get();
}

void menu()

{
    system("color c");
    int choice;
    cout<<"\t\t\t\t================= MENU ================\n\n"<<endl;
     Sleep(100);
    cout<<"\t\t\t\t1 => Create Student Profile\n\n"<<endl;
     Sleep(100);
    cout<<"\t\t\t\t2 => Complete SMS Report\n\n"<<endl;
     Sleep(100);
    cout<<"\t\t\t\t3 => Student Personal Report\n\n"<<endl;
     Sleep(100);
    cout<<"\t\t\t\t4 => Modify Student Record\n\n"<<endl;
     Sleep(100);
    cout<<"\t\t\t\t5 => Result\n\n"<<endl;
     Sleep(100);
    cout<<"\t\t\t\t6 => Delete Student Report\n\n"<<endl;
     Sleep(100);
    cout<<"\t\t\t\t=============================="<<endl;
     Sleep(100);
    cout<<"\t\t\t\tWhat To Do ? :";
     Sleep(100);
    cin>>choice;
    cout<<endl;
    switch(choice)
    {
    case 1:
        {
            input();
            break;
        }
    case 2:
        {
            full_report();
            break;
        }
    case 3:
          {
              int n;
              cout<<"Student Roll Number :";
              cin>>n;
              separate_data(n);
              break;
          }
    case 4:
        {
            int n;
            cout<<"Student Roll Number :";
            cin>>n;
            modify(n);
            break;
        }

    case 5:
        {
            int n;
            cout<<"Student Roll Number :";
            cin>>n;
            cout<<endl;
            result(n);
            break;
        }
    case 6:
        {
            int n;
            cout<<"Student Roll Number :";
            cin>>n;
            cout<<endl;
            deleterecord(n);
            break;
        }
    default : 
    {
    	cout<<"\n Invalid Input ! Please Try Again";
    	Sleep(400);
    	system("cls");
		menu();
	}
    }
}

void full_report()

{
    system("cls");
    student s;
    ifstream infile;
    bool check=false;
    infile.open("Report.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"ERROR => FILE NOT FOUND !     press any key to continue...";
        cin.ignore();
        cin.get();
    }
     cout<<"\n\n";
     cout<<"\t\t\t\tALL STUDENTS REPORT "<<endl;
     cout<<"=================================================================================="<<endl;
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    {
        cout<<"\t\t\t\tName : "<<s.name<<endl<<endl;
        cout<<"\t\t\t\tID : "<<s.id<<endl<<endl;
        cout<<"\t\t\t\tRoll Number : "<<s.roll<<endl<<endl;
        cout<<"\t\t\t\tSubject 1 Marks : "<<s.sub1<<endl<<endl;
        cout<<"\t\t\t\tSubject 2 Marks : "<<s.sub2<<endl<<endl;
        cout<<"\t\t\t\tSubject 3 Marks : "<<s.sub3<<endl<<endl;
        cout<<"\t\t\t\tSubject 4 Marks : "<<s.sub4<<endl<<endl;
        cout<<"\t\t\t\tTotal : "<<s.sum<<endl<<endl;
        cout<<"\t\t\t\tAverage : "<<s.average<<endl<<endl;
        cout<<"=================================================================================="<<endl;
        check=true;
    }
    infile.close();
    if(check==false)
    cout<<"\t\t\t\tNO RECORD FOUND..."<<endl<<endl;
    cout<<"press any key to continue....";
    cin.ignore();
    cin.get();
}

void separate_data(int n)

{
    system("cls");
    student s;
    ifstream infile;
    infile.open("Report.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"File Not Found!!!";

        cin.ignore();
        cin.get();
    }
    bool equality=false;
    cout<<"\t\t\t\t========== Personal Report ==========\n\n";
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    {
        if(s.roll==n)
        {
        cout<<"\t\t\t\tName :"<<s.name<<endl;
        cout<<"\t\t\t\tID : "<<s.id<<endl;
        cout<<"\t\t\t\tRoll Number :"<<s.roll<<endl;
        cout<<"\t\t\t\tSubject 1 Marks : "<<s.sub1<<endl;
        cout<<"\t\t\t\tSubject 2 Marks : "<<s.sub2<<endl;
        cout<<"\t\t\t\tSubject 3 Marks : "<<s.sub3<<endl;
        cout<<"\t\t\t\tSubject 4 Marks : "<<s.sub4<<endl;
        cout<<"\t\t\t\tTotal : "<<s.sum<<endl;
        cout<<"\t\t\t\tAverage : "<<s.average<<endl;
        cout<<"\t\t\t\t================================================"<<endl;
        equality=true;
        }
    }
        infile.close();
        if(equality==false)
            cout<<"\t\t\t\tRECORD NOT FOUND..."<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
}

void result(int n)

{
    system("cls");
    student s;
    ifstream infile;
    infile.open("Report.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"File Not Found !!!"<<endl;
        cin.ignore();
        cin.get();
    }
    bool eq=false;
    cout<<"\t\t\t\t=========== Personal Report ==========\n\n";
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    {
        if(s.roll==n)
        {
        cout<<"\t\t\t\tName : "<<s.name<<endl<<endl;
        cout<<"\t\t\t\tSubject 1 Marks : "<<s.sub1<<endl<<endl;
        cout<<"\t\t\t\tSubject 2 Marks : " <<s.sub2<<endl<<endl;
        cout<<"\t\t\t\tSubject 3 Marks : "<<s.sub3<<endl<<endl;
        cout<<"\t\t\t\tSubject 4 Marks : "<<s.sub4<<endl<<endl;
        cout<<"\t\t\t\tTotal : "<<s.sum<<endl<<endl;
        cout<<"\t\t\t\tAverage : "<<s.average<<endl<<endl;
        cout<<"\t\t\t\t=================================================="<<endl;
        eq=true;
        }
    }
        infile.close();
        if(eq==false)
            cout<<"\t\t\t\tRECORD NOT FOUND..."<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
}

void modify(int n)

{
    system("cls");
    student s;
    fstream infile;
    infile.open("Report.txt",ios::binary|ios::in|ios::out);
    if(infile.fail())
    {
        cout<<"File Not Found!!!"<<endl;
        cin.ignore();
        cin.get();
    }
     bool checker=false;
     cout<<"\t\t\t\t==========Modify Record==========\n\n";
     while(!infile.eof() && checker==false)
     {
     infile.read(reinterpret_cast<char*>(&s),sizeof(student));
     {
         if(s.roll==n)
         {
        cout<<"\t\t\t\tName : "<<s.name<<endl<<endl;
        cout<<"\t\t\t\tID : "<<s.id<<endl<<endl;
        cout<<"\t\t\t\tRoll Number : "<<s.roll<<endl<<endl;
        cout<<"\t\t\t\tSubject 1 Marks : "<<s.sub1<<endl<<endl;
        cout<<"\t\t\t\tSubject 2 Marks : "<<s.sub2<<endl<<endl;
        cout<<"\t\t\t\tSubject 3 Marks : "<<s.sub3<<endl<<endl;
        cout<<"\t\t\t\tSubject 4 Marks : "<<s.sub4<<endl<<endl;
        cout<<"============================================="<<endl;
        cout<<"\t\tEnter New Data"<<endl;
        cout<<"============================================="<<endl;
        cout<<"Name : ";
    cin.ignore();
    cin.getline(s.name,80);
    cout<<"Id : ";
    cin.ignore();
    cin.get(s.id,80);
    cout<<"Roll Number : ";
    cin>>s.roll;
    cout<<"Subject 1 Marks : ";
    cin>>s.sub1;
    cout<<"Subject 2 Marks : ";
    cin>>s.sub2;
    cout<<"Subject 3 Marks : ";
    cin>>s.sub3;
    cout<<"Subject 4 Marks : ";
    cin>>s.sub4;
    s.sum=s.sub1+s.sub2+s.sub3+s.sub4;
    s.average=(s.sum/4);
    int pos=(-1)*static_cast<int>(sizeof(student));
    infile.seekp(pos,ios::cur);
    infile.write(reinterpret_cast<char *> (&s), sizeof(student));
    cout<<endl;
    cout<<"\t\t\t\tFile Successfully Updated "<<endl;
    checker=true;
         }
     }
     }
     infile.close();
         if(checker==false)
            cout<<"\t\t\t\tRecord Not Found"<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
  }

  void deleterecord(int n)

  {
     system("cls");
     student s;
     ifstream infile;
     infile.open("Report.txt",ios::binary);
     if(!infile)
     {
         cout<<"File Not Found!!!"<<endl;
         cin.ignore();
         cin.get();
     }
     ofstream outfile;
     outfile.open("Record2.txt",ios::binary);
     infile.seekg(0,ios::beg);
     cout<<"\t\t\t\t=========== Delete Record ==========\n\n";
     while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
     {
         if(s.roll!=n)
         {
             outfile.write(reinterpret_cast<char*>(&s),sizeof(student));
         }
     }
     infile.close();
     outfile.close();
     remove("Report.txt");
     rename("Record2.txt","Report.txt");
     cout<<endl;
     cout<<"\t\t\t\tRecord Deleted Successfully!!!"<<endl;
     cout<<"press any key to continue...";
     cin.ignore();
     cin.get();
  }


