//Programmer: Muhammad Umar Nadeem
// Roll number: 212052
//BSCS-3-C
//Instructor: Professor Sagheer Ahmed

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

//Global variables
int myarr[100];
int counter = 10;
int main_menu_check = 20;


//functions


void Main_menu_diplay()
{
    cout<<"Please enter your desired option."<<endl<<endl;
    cout<<"1. Insert."<<endl;
    cout<<"2. Delete."<<endl;
    cout<<"3. Update."<<endl;
    cout<<"4. Swap."<<endl;
    cout<<"5. Copy."<<endl;
    cout<<"6. Search."<<endl;
    cout<<"7. Sort."<<endl;
    cout<<"8. Find Size."<<endl;
    cout<<"9. Display."<<endl;
    cout<<"10. Exit."<<endl;

}

void array_display()
{

cout<<endl;
cout <<"The array's cell's serial numbers and their values are displayed for your convenience."<<endl<<endl;

for (int i  = 1; i<= counter; i ++)
{cout <<i<<": ["<<myarr[i - 1]<<"]   ";}
cout<<endl <<endl;

}

//------------------------Insertion -------------------------------//
void insert_at_start()
{
    int valstart;
    array_display();
    cout <<"Please enter the value you wish to store at the start of the array."<<endl;
    cin>>valstart;
    sleep(2);
    for (int i = counter; i > 0; i--){
    myarr[i] =myarr[i - 1];
    }
    myarr[0] = valstart;
    counter++;
}

void insert_at_spec_loc()
{


    int spec_loc;
    int value_at_loc;
    array_display();
    cout <<"Please enter the location where you wish to store the value"<<endl;
    cin>>spec_loc;
    sleep(2);
    if (spec_loc > counter || spec_loc <= 0)
    {
    cout <<"The location must be within the number of elements stored by the array."<<endl;
    sleep(2);
    }
    else
    {
        cout<<"Please enter the value you wish to store at "<<spec_loc<<endl;
        cin>>value_at_loc;
        sleep(2);
        for(int i = counter; i > spec_loc - 1; i--)
        {myarr[i] = myarr[i -1];}
        myarr[spec_loc - 1] = value_at_loc;
        counter++;
    }


}

void insert_at_end()
{
    int end_val;
    array_display();
    cout<<"Please enter the value you wish to store at the end"<<endl;
    cin>>end_val;
    sleep(2);
    myarr[counter] = end_val;
    counter++;
}

void Insert()
{
int insertion_loop_val = 0;
while (insertion_loop_val != 27){
int insertion_option;
cout <<"Please select your desired option"<<endl;
cout <<"1. Insert at start."<<endl;
cout <<"2. Insert at a specific location."<<endl;
cout <<"3. Insert at end."<<endl;
cout <<"4. Back to Main Menu"<<endl;

cin>>insertion_option;

if (insertion_option == 1)
    {insert_at_start();
    system("CLS");
    }

else if(insertion_option == 2)
    {insert_at_spec_loc();
    system("CLS");
    }

else if (insertion_option == 3)
    {insert_at_end();
    system("CLS");
    }

else if (insertion_option == 4)
    {insertion_loop_val = 27;
    system("CLS");
    }

else
    {cout <<"Invalid entry. Please enter a valid option."<<endl;
        sleep(5);
        system("CLS");
    }
}
}


//-------------------------------------------------------------------//

void Delete_at_start()
{
for (int i = 0; i<counter; i++)
{
    myarr[i] = myarr [i + 1];
}
counter--;
}

void Delete_at_spec_loc(){

int spec_loc;
array_display();
cout <<"Please enter the specific location which you would like to delete."<<endl;
cin>>spec_loc;
sleep(2);
if (spec_loc > counter || spec_loc <= 0)
    {
    cout <<"The location must be within the number of elements stored by the array."<<endl;
    sleep(5);
    }
for (int i = spec_loc - 1; i <counter; i++){
    myarr[i]=myarr[i+1];
}
counter--;
}


void Delete_at_end()
{
myarr[counter - 1] = 0;
counter--;
}


void Delete(){

int deletion_loop_val = 0;
int del_option;
while (deletion_loop_val != -1){
cout <<"Please select your desired option"<<endl;
cout <<"1. Delete at start."<<endl;
cout <<"2. Delete at a specific location."<<endl;
cout <<"3. Delete at end."<<endl;
cout <<"4. Back to Main Menu"<<endl;

cin>> del_option;
if (del_option == 1)
    {
        Delete_at_start();
        system("CLS");
    }
else if (del_option == 2)
    {
        Delete_at_spec_loc();
        system("CLS");
    }
else if (del_option == 3)
    {
        Delete_at_end();
        system("CLS");
    }
else if (del_option == 4)
    {
        deletion_loop_val = -1;
        system("CLS");
    }

else {
    cout <<"Please enter a valid choice"<<endl;
    sleep(5);
    system("CLS");
    }
}
}

//---------------------------------------UPDATE------------------------------------------------------//

void Update_by_index()
{
int spec_loc;
int new_val;
array_display();
cout <<"Please enter the location of the value you wish to update."<<endl;
cin>>spec_loc;
sleep(2);
if (spec_loc > counter || spec_loc <= 0)
    {
    cout <<"The location must be within the number of elements stored by the array."<<endl;
    sleep(5);
    }
else
{
    cout <<"Please enter the new value you wish to store at " <<spec_loc<<endl;
    cin>>new_val;
    sleep(1);
    myarr[spec_loc - 1] = new_val;
}
}

void Update_by_value()
{
    int check_size = 0;
    int old_val;
    int new_val;
    int choice;
    int* ____temp_array = new int [check_size + 1];
    array_display();
    cout <<"Please enter the value you wish to update in the array."<<endl;
    cin>>old_val;
    sleep(1);
    for (int i = 0; i<counter; i++)
        {
            if (myarr[i] == old_val)
            {
            ____temp_array[check_size] = i;
            check_size++;
            }
        }

    if (check_size <= 0){cout<<"The value "<<old_val<<" is not present anywhere in the array. Please enter a valid value."<<endl;
    sleep(5);
    }

    else if (check_size == 1)
    {
    cout << old_val<<" is placed at cell # "<<____temp_array[check_size - 1] + 1<<" in the array. Please enter the new value you'd like to update it to"<<endl;
    cin>> new_val;
    sleep(1);
    myarr[____temp_array[check_size -1]] = new_val;
    }
    else if (check_size > 1)
    {
      cout<<"The value "<<old_val<<" is present at cell numbers ";
      for (int i = 0; i < check_size; i++){
        cout<<____temp_array[i] + 1<<", ";
      }
      cout<<endl <<"Which of these cells would you like to update?"<<endl;
      cin>>choice;
      sleep(1);
      cout<<"Please enter the new value you'd like to update it to."<<endl;
      cin>>new_val;
      sleep(1);
      myarr[choice - 1] =new_val;
    }

    delete[] ____temp_array;
}

void Update(){

int updation_loop_val = 0;
int choice;
while (updation_loop_val != -1){
cout <<"Please select your desired option"<<endl;
cout <<"1. Update by index"<<endl;
cout <<"2. Update by value"<<endl;
cout <<"3. Back to main menu"<<endl;

cin>>choice;
if (choice == 1)
    {
    Update_by_index();
    system("CLS");
    }
else if (choice == 2)
    {
    Update_by_value();
    system("CLS");
    }
else if (choice ==3)
    {
    updation_loop_val = -1;
    system("CLS");
    }
else
    {
     cout <<"Please enter a valid choice"<<endl;
     sleep(5);
     system("CLS");
    }

}

}





//-------------------------------------------------COPY--------------------------------------------------//
//4.

void Copy_by_index()
{
    int copied_cell;
    int to_cell;
    int check1 = 0;
    while (check1 != -1)
    {
    array_display();
    cout<<"Please enter the cell number whose value you wish to copy"<<endl;
    cin>>copied_cell;
    sleep(1);
    if(copied_cell <= 0 || copied_cell > counter)
    {
        cout<<"Location of copied cell must be within the number of elements of the array"<<endl;
        sleep(2);
        break;
    }
    else
    {
    cout<<myarr[copied_cell - 1]<<" is stored at cell # "<<copied_cell<<". Please enter the cell you wish to copy "<<myarr[copied_cell -1]<<" to"<<endl;
    cin>>to_cell;
    if(to_cell <= 0 || to_cell >counter)
        {
         cout<<"Location of destination cell must be within the number of elements stored by the era"<<endl;
         sleep(2);
         break;
        }
    else
    {
        myarr[to_cell - 1] = myarr[copied_cell - 1];
        check1 = - 1;
    }
    }
    }
}

void Copy_by_value()
{
int from_value;
int to_value;
int check1 = 0;
int check2 = 0;
int choice = 0;

int find_size = 0;
int* ___temp_arr = new int [find_size + 1];

while (check1 != -1){
array_display();
cout <<"Please enter the value you wish to copy"<<endl;
cin>>from_value;
sleep(2);
for (int i = 0 ; i<counter; i++)
    {
     if(myarr[i] == from_value)
        {
            check2 = 100;
        }
    }
if (check2 != 100)
    {
        cout <<"Copied value is not stored in the array. You must copy an existing value"<<endl;
        sleep(2);
        break;
    }
else
    {
    check2 = 0;
    cout <<"Please enter the value you wish to copy " << from_value<<" over."<<endl;
    cin>>to_value;
    sleep(2);
    for (int j = 0; j < counter; j++)
        {
         if (myarr[j] == to_value)
             {

                 ___temp_arr[find_size] = j;
                 find_size++;
             }
        }
    if (find_size == 0)
            {
                cout<<"Destination value is not stored in the array. You must paste your copied value over an existing value"<<endl;
                break;
                sleep(2);
            }
    else if (find_size == 1)
    {
    myarr[___temp_arr[find_size -1]] = from_value;
    check1 = -1;
    }
    else if (find_size > 1)
    {
      cout<<"The value "<<to_value<<" is present at cell numbers ";
      for (int i = 0; i < find_size; i++){
        cout<<___temp_arr[i] + 1<<", ";
      }
      cout<<endl <<"Which of these cells would you like to update?"<<endl;
      cin>>choice;
      sleep(2);
      myarr[choice - 1] = from_value;
      check1 = -1;
    }



    }
    delete [] ___temp_arr;
    }
    }

 void Copy()
 {
     int choice = 0;
     int copy_loop_val = 0;

     while (copy_loop_val != -1){
     cout <<"Please enter your desired option"<<endl;
     cout <<"1. Copy by index"<<endl;
     cout <<"2. Copy by value"<<endl;
     cout <<"3. Back to main menu"<<endl;
     cin>>choice;
     if (choice == 1)
         {
          Copy_by_index();
          system("CLS");
         }

     else if (choice == 2)
        {
            Copy_by_value();
            system("CLS");
        }

     else if (choice == 3)
        {
        copy_loop_val = -1;
        }
     else
     {
         cout <<"Please enter a valid choice."<<endl;
        system("CLS");
     }


     }

 }



void Swap_by_index()
{
    int check1 = 0;
    int a = 0;
    int b = 0;
    int temp_var;
    while (check1 == 0){
    array_display();
    cout <<"Please enter the two cells you wish to swap"<<endl;
    cout <<"1. Cell # 1: ";
    cin>>a;
    sleep(2);
    if (a <= 0 || a > counter)
        {cout<<endl<<"You must enter a cell between 1 and "<<counter;sleep(2); break;}
    cout <<"2. Cell # 2: ";
    cin>>b;
    sleep(2);
    if (b <= 0 || b > counter)
        {cout<<endl<<"You must enter a cell between 1 and "<<counter;sleep(2); break;}

    else
        {
         temp_var = myarr[a-1];
         myarr[a-1] = myarr[b-1];
         myarr[b-1] = temp_var;
         check1 = -1;
        }
    }
}

void Swap_by_value()
{
int val1 = 0;
int val2 = 0;
int check1 = 0;
int check2 = 0;
int count1 = 0;
int count2 = 0;
int select1;
int select2;
int* ta1 = new int [count1 + 1];
int* ta2 = new int [count2 + 1];
int temp_store;

while(check1 != -1)
    {

    array_display();
    cout <<"Please enter the first value of the swap."<<endl;
    cin>>val1;
    cout <<"Please enter the second value of the swap."<<endl;
    cin>>val2;
    sleep(2);
    for(int i = 0; i<counter; i++)
        {
         if (myarr[i] == val1)
             {
              ta1[count1] = i;
              count1++;
             }

        }

    for(int j = 0; j<counter; j++)
    {
     if (myarr[j] == val2)
         {
          ta2[count2] = j;
          count2++;
         }
    }

    if ((count1 <= 0) || count2 <= 0)
        {cout <<"One or both of your entered values doesn't exist in the array. Please try again with existing values."<<endl;sleep(2); break;}

    else if ((count1 == 1) && (count2 == 1))
        {
        temp_store = myarr[ta1[count1 - 1]];
        myarr[ta1[count2 - 1]] = myarr[ta2[count2 - 1]];
        myarr[ta2[count2 - 1]] = temp_store;
        check1 = -1;
         }

    else if ((count1 > 1) && (count2 == 1))
    {
    cout << val1<<" is present at cell numbers ";
    for (int m = 0; m < count1; m++)
        {cout << ta1[m] + 1<< ", ";}

    cout <<endl<< "At which cell do you want to swap "<<val1<<" with "<<val2<<"?"<<endl;
    cin>>select1;
    sleep(2);
    temp_store = myarr[select1 - 1];
    myarr[select1 - 1] = myarr[ta2[count2 - 1]];
    myarr[ta2[count2 - 1]] = temp_store;
    check1 = -1;
    }

    else if ((count1 == 1) && (count2 > 1))
    {
        cout <<val2<<" is present at cell numbers ";
        for (int n = 0; n < count2; n++)
        {cout << ta2[n] + 1<< ", ";}

        cout<<endl<<"At which cell do you want to swap "<<val2<< " with "<<val1<<"?"<<endl;
        cin>>select2;
        sleep(2);
    temp_store = myarr[select2 - 1];
    myarr[select2 - 1] = myarr[ta1[count1 - 1]];
    myarr[ta1[count1 - 1]] = temp_store;
    check1 = -1;
    }
    else if ((count1 >1) && (count2 > 1))
        {
        cout << val1<<" is present at cell numbers ";
        for (int p = 0; p < count1; p++)
        {cout << ta1[p] + 1<< ", ";}

        cout <<val2<<" is present at cell numbers ";
        for (int q = 0; q < count2; q++)
        {cout << ta2[q] + 1 << ", ";}

        cout <<"Please enter the two cells you wish to swap of "<<val1 <<" and "<<val2<<endl;
        cout<<"Cell #1"<<endl;
        cin>>select1;
        cout<<"Cell #2"<<endl;
        cin>>select2;
        sleep(2);
    temp_store = myarr[select2 - 1];
    myarr[select2 - 1] = myarr[select1 - 1];
    myarr[select1 - 1] = temp_store;
    check1 = -1;
        }



}
delete [] ta1;
delete [] ta2;
}

void Swap()
{
int choice;
int check1;

while (check1 != -1)
{
cout <<"Please select your desired option"<<endl;
cout <<"1. Swap by index"<<endl;
cout <<"2. Swap by value"<<endl;
cout <<"3. Back to main menu"<<endl;
cin>>choice;

if (choice == 1)
    {
    Swap_by_index();
    system("CLS");
    }
else if (choice == 2)
    {
    Swap_by_value();
    system("CLS");
    }
else if (choice ==3)
    {
    check1 = -1;
    system("CLS");
    }
else
    {
     cout <<"Please enter a valid choice"<<endl;
     sleep(5);
     system("CLS");
    }
}

}


void Search_by_index(){

int user_entry;
array_display();
cout <<"Please enter the serial location of the cell you wish to search"<<endl;
cin>>user_entry;
cout <<"The value at cell # "<<user_entry<<" is "<<myarr[user_entry - 1]<<endl;
}

void Search_by_value(){

int m = 200;
 while (m != -1){
int temp_array[counter];
int user_entry;
int j = 0;
int total_values_detected = 0;
array_display();
cout <<"Please enter the value you wish to locate in the array."<<endl;
cin>>user_entry;
for (int i =0; i< counter; i++){

    if (myarr[i] == user_entry)
    {
        temp_array[j] = i;
        j++;
    }
    }

cout <<"The value "<<user_entry<<" lies at cell locations ";
for (int k =0; k <= j; k++)
    {
        cout<<temp_array[k]<<", ";
    }
cout<<endl;
}
}

void Search()
{
int m = 200;
while (m != -1){
int entry;
cout <<"Please select your desired option"<<endl;
cout <<"1. Search by index"<<endl;
cout <<"2. Search by value."<<endl;
cout <<"3. Back to main menu"<<endl;
cin>>entry;

if (entry == 1)
{
    Search_by_index();
}
else if (entry == 2)
{
    Search_by_value();
}
else if (entry  == 3)
    {
        m =-1;
    }

else
    {
        cout <<"Invalid selection. Please select a valid option."<<endl;
    }
}

}




//------------------------------DISPLAY-----------------------//
void Display()
{   cout<<"The array is displayed below."<<endl;
    for (int i  = 0; i < counter; i ++)
    {cout <<i+ 1<<": ["<<myarr [i]<<"] , ";}
    cout <<endl<<endl;
}


void Sort_ascending()
{
int temp = 0;
int maxi = counter - 1;
for (int i = 0; i <=maxi; i++)
{
for (int j = 0; j <=maxi; j++){

    if (myarr[j] >= myarr[maxi])
        {
        temp = myarr[j];
        myarr[j]=myarr[maxi];
        myarr[maxi] =temp;
        }
}
maxi--;
i = 0;
}


}

void sort_descending()
{
int temp = 0;
int maxi = counter - 1;
for (int i = 0; i <=maxi; i++)
{
for (int j = 0; j <=maxi; j++){

    if (myarr[j] <= myarr[maxi])
        {
        temp = myarr[j];
        myarr[j]=myarr[maxi];
        myarr[maxi] =temp;
        }
}
maxi--;
i = 0;
}


}

void sorting()
{
    int checker = 20;
    while ( checker != -1){
    int option;
cout <<"Please select your desired option."<<endl;
cout<<"1. Sort by ascending order."<<endl;
cout<<"2. Sort by descending order."<<endl;
cout<<"3. Back to main menu."<<endl;
cin>>option;
if(option == 1)
    {
        Sort_ascending();

        system("CLS");
    }
else if (option == 2)
    {
        sort_descending();
        system("CLS");
    }
else if (option == 3)
{
checker = -1;
}
else if (option == 4){cout<<"Invalid selection. Please select a valid option."<<endl;}
sleep(2);
system("CLS");
}
}
int main(){


    cout<<"Please initialize the array with 10 elements"<<endl;

     for (int i = 0; i<10; i++)
    {
        cin>>myarr[i];

    }

while(main_menu_check == 20)
{
int Main_menu_option;
Main_menu_diplay();
cin>>Main_menu_option;

if (Main_menu_option == 1) {Insert();}
else if(Main_menu_option == 2){Delete();}
else if(Main_menu_option == 3){Update();}
else if (Main_menu_option == 4){Swap();}
else if (Main_menu_option == 5){Copy();}
else if (Main_menu_option == 6){Search();}
else if (Main_menu_option == 7){sorting();}
else if (Main_menu_option == 8) {cout <<"The array has "<<counter<<" elements stored in it."<<endl;sleep(5);}
else if (Main_menu_option == 9){Display(); sleep(7);}
else if (Main_menu_option == 10){main_menu_check= -1; cout<<"Thank you for using our program. Fee Amanillah! :)"<<endl;
sleep(5); }
system("CLS");

}

return 0;
}
