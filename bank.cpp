#include<iostream>                                   // header for cin & cout
#include<fstream>                                   //  header for file manipulation
#include<dir.h>                                    //  header for making directory iin pc
#include<ctime>                                    //  header for generating random account no
#include<cstdlib>                                  // header used for rename & remove fn
#include<stdio.h>                                  // header used for clear the screen fn ex systen("cls");
using namespace std;
int count1=1;
typedef long long int int_type;
class Bank                                          // starting of class
{public:
    int counter=0;                                   //  all variable declare
    int_type account_no,mobile_no,adhar_no;
    char address[90],pan_no[15],holder_name[25];
    double price=0.0;

    Bank()                                             //constructor
    {
        mkdir("C:/lexie");                            // making dir
    }
    void get_data(void);
    void view_all(void);
    void show_data(void);
    void add_data(void);
    int_type account(void);
    int len(int_type);
    void search_data(int_type);
    void update_data(int_type);
    void delete_data(int_type);
    void deposit(int_type);
    void withdraw(int_type);
};
void Bank::withdraw(int_type t)                          // fn is used to withdraw amount
{
    double fprice;
    int_type account_no1,mobile_no1,adhar_no1;
    char *holder_name1[25];
    ifstream file;
       file.open("C:/lexie/bank.dat",ios::in|ios::binary);
       if(!file)
        cout<<"file not found";
       else{
            ofstream fout("C:/lexie/temp.dat",ios::binary|ios::app);
       file.read((char*)this,sizeof(*this));
       while(!file.eof())
       {
        if(t==account_no)
        {
            account_no1=account_no;
           char* holder_name1=holder_name;
           char* address_=address;
            mobile_no1=mobile_no;
            adhar_no1=adhar_no;
           char* pan_no1=pan_no;
            cout<<"Enter amount to withdraw :";
            cin>>fprice;
            price-=fprice;
            fout.write((char*)this,sizeof(*this));
            count1++;
            break;
        }
        fout.write((char*)this,sizeof(*this));
        file.read((char*)this,sizeof(*this));
    }
    fout.close();
    }
    file.close();
    remove("C:/lexie/bank.dat");                                      // it is used to remove old file
    rename("C:/lexie/temp.dat","C:/lexie/bank.dat");                     // it is uused to rename the files
    if(count1>1)
        cout<<"\ncash withdraw successful\n";
}
void Bank::deposit(int_type t)                                        // fn used for deposit amount
{
    double fprice;
    int_type account_no1,mobile_no1,adhar_no1;
    char *holder_name1[25];
    ifstream file;
       file.open("C:/lexie/bank.dat",ios::in|ios::binary);
       if(!file)
        cout<<"file not found";
       else{
            ofstream fout("C:/lexie/temp.dat",ios::binary|ios::app);
       file.read((char*)this,sizeof(*this));
       while(!file.eof())
       {
        if(t==account_no)
        {
            account_no1=account_no;
           char* holder_name1=holder_name;
           char* address_=address;
            mobile_no1=mobile_no;
            adhar_no1=adhar_no;
           char* pan_no1=pan_no;
            cout<<"Enter amount for deposit :";
            cin>>fprice;
            price+=fprice;
            fout.write((char*)this,sizeof(*this));
            count1++;
            break;
        }
        fout.write((char*)this,sizeof(*this));
        file.read((char*)this,sizeof(*this));
    }
    fout.close();
    }
    file.close();
    remove("C:/lexie/bank.dat");
    rename("C:/lexie/temp.dat","C:/lexie/bank.dat");
    if(count1>1)
        cout<<"\ncash deposit successful\n";
}
void Bank::delete_data(int_type t)                                   // fn is used to del the account
{
    ifstream obj("C:/lexie/bank.dat",ios::in|ios::binary);
        if(!obj)
            cout<<"file doesn't exit";
        else
        {
            ofstream fout("C:/lexie/temp.dat",ios::out|ios::binary);
            obj.read((char*)this,sizeof(*this));
            while(!obj.eof())
            {
                if(t==account_no)
                      counter++;
                else
                    fout.write((char*)this,sizeof(*this));
                obj.read((char*)this,sizeof(*this));
            }
            if(counter>0)
                cout<<"deleted data successful";
            else
                cout<<"this data is not in file";
            fout.close();
        }
        obj.close();
        remove("C:/lexie/bank.dat");
        rename("C:/lexie/temp.dat","C:/lexie/bank.dat");
}
void Bank::update_data(int_type t)                                                     // fn is used to update account
{
       fstream file;
       file.open("C:/lexie/bank.dat",ios::in|ios::binary|ios::out|ios::ate);
       if(!file)
        cout<<"file not found";
       else{
       file.seekg(0);
       file.read((char*)this,sizeof(*this));
       while(!file.eof())
       {
           if(t==account_no)
           {
               get_data();
               file.seekp(file.tellp()-sizeof(*this));
               file.write((char*)this,sizeof(*this));
           }
           file.read((char*)this,sizeof(*this));
       }}
       file.close();
}
void Bank::search_data(int_type t)                            // fn is used to search account data
{
    ifstream fin("C:/lexie/bank.dat");
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof())
    {
        if(t==account_no)
            show_data();
        fin.read((char*)this,sizeof(*this));
    }
    fin.close();
}
void Bank::view_all()                                         // fn is used to view all data
{
    ifstream fin("C:/lexie/bank.dat");
    if(!fin)
        cout<<"file doesn't exit";
    else{
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof())
    {
        show_data();
        fin.read((char*)this,sizeof(*this));
    }}
    fin.close();
}
int Bank::len(long long int temp)                                    // fn is used to calculate length of account no.
{
    int count1=0;
    while(temp!=0)
    {
        temp=temp/10;
        count1++;
    }
    return count1;
}
int_type Bank::account()                                          // fn is used to generate random account no.
{
    srand(time(0));
    long long int num,temp=0;
    int i,num1;
    while(1)
      {
          num=rand()%1000;
          temp=temp*1000+num;
          num1=len(temp);
            if(num1>11)
                break;
          i--;
      }
      for(i=1;i<=num1-11;i++)
        temp=temp/10;
    return (temp);
}
void Bank::get_data()                                       // fn is used to get the data from user
{
    account_no=account();
    cin.ignore();
    cout<<"Name: ";
    cin.getline(holder_name,24);
    cout<<"Address: ";
    cin.getline(address,89);
    cout<<"Mobile: ";
    cin>>mobile_no;
    cout<<"Adhar Number: ";
    cin>>adhar_no;
    cout<<"Pan Number: ";
    cin.ignore();
    cin.getline(pan_no,14);
    price;
}
void Bank::show_data()                                              // fn is used to show data
{
    cout<<count1<<"=> Account Number: "<<account_no;
    cout<<"\n    Name: "<<holder_name;
    cout<<"\n    Address: "<<address;
    cout<<"\n    Mobile: "<<mobile_no;
    cout<<"\n    Adhar No: "<<adhar_no;
    cout<<"\n    Price: "<<price;
    cout<<"\n    Pan Number: "<<pan_no<<endl<<endl;count1++;

}
void Bank::add_data()                                                                 // fn is used to add data
{
    ofstream fout("C:/lexie/bank.dat",ios::app|ios::ate|ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
}
int menu_u()                                                                         // fn menu
{
    cout<<"================                         ===================\n";
    cout<<"                    1=>  DEPOSIT\n";
    cout<<"                    2=>  WITHDRAW\n";
    cout<<"================                         ===================\n";
    char choice;
    cout<<"Enter choice: ";
    cin>>choice;
    //system("cls");
    return(choice);
}
int menu2()
{
    cout<<"================      1=> ADMIN     ==========================\n";
    cout<<"================      2=> USERS     ==========================\n";
    int choice;
    cout<<"Enter choice: ";
    cin>>choice;
    system("cls");
    return choice;
}
int menu()
{
    int choice;
    cout<<"================                         ===================\n";
    cout<<"                  BANK  MANAGEMENT\n\n";
    cout<<"************************************************************\n";
    cout<<"                      1=> List                             *\n";
    cout<<"                      2=> ADD                              *\n";
    cout<<"                      3=> UPDATE                           *\n";
    cout<<"                      4=> SEARCH                           *\n";
    cout<<"                      5=> DELETE                           *\n";
    cout<<"                      6=> EXIT                             *\n";
    cout<<"************************************************************\n";
    cout<<"Enter choice:";
    cin>>choice;
    system("cls");
    return(choice);
}
main()                                                                      // starting of main fn
{
    int_type account;
    Bank obj;
    switch(menu2())
    {
case 1:
    char choice;do{
    long long int account_no;
    switch(menu())
    {
    case 1:
        obj.view_all();
        break;
    case 2:
        obj.get_data();
        obj.add_data();
        break;
    case 3:
        obj.view_all();
        cout<<"\n\nEnter Account which you want to update: ";
        cin>>account_no;
        obj.update_data(account_no);
        break;
    case 4:
        obj.view_all();
        cout<<"\n\nEnter Account which you want to search: ";
        cin>>account_no;
        obj.search_data(account_no);
        break;
    case 5:
        obj.view_all();
        cout<<"\n\nEnter Account which you delete: ";
        cin>>account_no;
        obj.delete_data(account_no);
        break;
    default:
        cout<<"wrong choice";
        break;
        }
        cout<<"\nif you want to do something more press y else n: ";
        cin>>choice;
        system("cls");
    }while(choice=='y'||choice=='Y');break;
    case 2:
        switch(menu_u())
        {
        case 49:
            cout<<"Enter account no: ";
            cin>>account;
            obj.deposit(account);
            break;
        case 50:
            cout<<"Enter account no: ";
            cin>>account;
            obj.withdraw(account);
            break;
        }
    }
}
