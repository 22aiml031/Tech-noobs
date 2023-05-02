#include<iostream>
#include<iomanip>
#include<string>
#include<conio.h>
#include<stdlib.h>
using namespace std;

int main();
void show_data(int searchkey);     //function used to show data to end-user.
void get_data(int i);           //function used to obtain data from end-user.
void search_student(int searchkey);
void add_student();      //This function is used to add record of new student.
void edit_student(int idnumber);   //function is used to edit existing record.
void fullscreen();
int ts;

struct student    //Structure student is made to store student attributes.
{
  int rollno;
  string name;
  string fname;
  string cell;
  string dob;
  string address;
};

student rec[50];  //This is basic array of defined structure to sore data.
int main()
{
  system("CLS");
  system("color B1");
  int choice;   //int variable used to determine which operation user want to do.
  int idnumber;   //int variable used to record ID number whih user want to edit.
  int searchkey;  //int variable to store student roll_no by which user can search.

  cout<<"Enter The Total Number of Student(s)- Max 50: ";
  cin>>ts;

 while(ts--)
 {
  cout<<"\n\t\tWhat do you want to do?"<<endl;
  cout<<"\t\t----------------------"<<endl;
  cout<<"\t\t1-Add student"<<endl;
  cout<<"\t\t2-Edit student"<<endl;
  cout<<"\t\t3-Search student"<<endl;
  cout<<"\t\t4-Quit Program"<<endl;
  cout<<"\t\t----------------------"<<endl;
  cout<<"Enter your choice: ";

  cin>>choice;
  switch(choice)
 {
   case 1:         //If user presses 1 then student adding module would be displayed.
    add_student();
    break;
   case 2:         //If there are no records in array then it will ask the user to input records first.
    if(rec[0].rollno==0)
   {
     cout<<"Please Add sudents first."<<endl;
     system("pause");
    main();
   }
    else         //If records are present in array then it will show table.
   {
     cout<<endl;
     cout<<"--------------------------------------------------------------------------------"<<endl;
     cout<<"---------------------------Student record Table---------------------------------"<<endl;
     cout<<"--------------------------------------------------------------------------------"<<endl;
     cout<<setw(15)<<left<<"ID   "<<setw(15)<<left<<"Roll   "<<setw(15)<<left<<"Name      "<<setw(15)<<left<<"Father"<<"Cell no."<<"DOB "<<"Address\n\n";
     cout<<"--------------------------------------------------------------------------------"<<endl;

     for(int i=0;i<=ts;i++)
    {
      show_data(i);     //funtion is called with index value to show data.
     }

     cout<<"--------------------------------------------------------------------------------"<<endl;
     cout<<"Which ID number your want to edit: ";

     cin>>idnumber;            //Asking the user at which ID he wants to make a change.

    if(idnumber>ts || idnumber<0)  //Validating the ID number.
    {
          cout<<"\nInvalid ID Number."<<endl;
       }
       else
    {
          edit_student(idnumber);    //Passing ID number to Edit Function.
       }
   }
   break;

  case 3:
    if(rec[0].rollno==0)     //If no record exist then ask the user o enter records first.
   {
     cout<<"Please Add sudents first."<<endl;
     system("pause");
     main();         //Return to main so user can input new record.
    }
    else
   {
     cout<<"Enter roll_no of student you want to search: ";
     cin>>searchkey;     //roll_no as the search key can be entered by user.
     search_student(searchkey);}
     break;
   case 4:
    return 0;        //Terminating the records.
    break;
   default:         //Default value for ivalid Input.
    cout<<"Invalid number."<<endl;
    system("pause");
  main();
  }
 }
  return 0;
}


void get_data(int i)        //Function for receiving data from user and populatiing the variables with values.
{
  cout<<"Enter student roll number in  format(1XXX): "<<endl;
  cin>>rec[i].rollno;
  cout<<"Enter student name: "<<endl;
  cin>>rec[i].name;
  cout<<"Enter student's Father name: "<<endl;
  cin>>rec[i].fname;
  cout<<"Enter student's cell phone number: "<<endl;
  cin>>rec[i].cell;
  cout<<"Enter student's Date of Birth(dd/mm/yyyy): "<<endl;
  cin>>rec[i].dob;
  cout<<"Enter student's Address: "<< endl;
  cin>>rec[i].address;
}

void show_data(int searchkey)      //Function for showing data on the screen.
{
  int i=searchkey;
  cout<<"\n"<<i<<"    "<<endl;
  cout<<rec[i].rollno<<"\t";
  cout<<setw(10)<<rec[i].name<<"\t";
  cout<<rec[i].fname<<"\t";
  cout<<rec[i].cell<<"\t";
  cout<<rec[i].dob<<"\t";
  cout<<rec[i].address<<"\t";
}

void search_student(int searchkey)
{
  for(int i=0;i<=ts;i++)       //Loop thrugh complete array.
 {
   if(rec[i].rollno==searchkey)    //If roll number matches to search term.
  {
    cout<<"ID\t "<<"Roll\t"
   <<"Name\t"<<"Father\t"<<"Cell no.\t"
    <<"DOB\t"<<"Address\n\n"<<endl;
    show_data(i);       //A function is used inside another function.
   }
  }
}

void add_student()         //This function is used to add record of new student.
{
  for(int i=0;i<=ts;i++)
 {
    get_data(i);
    cout<<"\n"<<endl;        //Loop was processed 5 times to get input for 5 students.
  }

  cout<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"---------------------------Student record Table---------------------------------"<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<setw(15)<<left<<"\nID"<<endl << setw(15)<<left<<"\nRoll" <<endl
    <<setw(15)<<left<<"\nName" <<endl <<setw(15)<<left<<"\nFather" <<endl <<setw(15)<<left<<"\nCell no."<<
    endl<<setw(15)<<left<<"\nDOB"<<endl <<setw(15)<<left<<"\nAddress\n\n"<<endl;



  for(int i=0;i<=ts;i++)
 {
    show_data(i);        //Loop was processed for 5 times to show obtained records.
  }
  cout << endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"---------------------------------FINISH-----------------------------------------"<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  system("pause");

  main();          //Return to main function to again show menu.
}

void edit_student(int idnumber)     //function is used to edit existing record.
{
  for(int i=0;i<=ts;i++)       //Loop is started.
 {
   if(idnumber==i)       //Through loop every value is compared with search term.
  {
    cout<<"\nExisted information about this record.\n\n";
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<setw(15)<<left<<"ID: " <<endl <<setw(15)<<left <<"Roll:"<<
    endl <<setw(15)<<left<<"Name: " <<endl <<setw(15)<<left<<"Father:\t"<<endl <<setw(15)<<left<<"Cell no:"<<endl
    <<setw(15)<<left<<"DOB:          "<<endl <<setw(15)<<left<<"Address:\n\n"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    show_data(i);       //Load information for existing record.
    cout<<"\n\nEnter new data for above shown record.\n\n";
    get_data(i);         //Inputing data for that specific record.
    cout<<"\n\nRecord updated successfully."<<endl;
    system("pause");
    main();           //Return to main function.
   }
  }
}
