#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int Partition(int array[],int p,int r,int &count)
{
 int x = array[r];
 int i=p-1;
 for(int j=p;j<r-1;j++)
 {
  count += 1;
  if(array[j] <= x)
  {
   i+=1;
   int temp = array[i];
   array[i] = array[j];
   array[j] = temp;
  }
 }
 int temp = array[r];
 array[r] = array[i+1];
 array[i+1] = temp;
 return i+1;
}
void QuickSort(int array[],int p,int r,int &count)
{
 if(p<r)
 {
  int q = Partition(array,p,r,count);
  QuickSort(array,p,q-1,count);
  QuickSort(array,q+1,r,count);
 }
}
int Random(int p,int r)
{
 return (rand() % (r-p+1) + 1);
}
int Randomized_Partition(int array[],int p,int r,int &count)
{
 int i= Random(p,r);
 int temp = array[r];
 array[r] = array[i];
 array[i] = temp;
 return Partition(array,p,r,count);
}
void Randomized_QuickSort(int array[],int p,int r,int &count)
{  
 if(p<r)
 {
  int q = Randomized_Partition(array,p,r,count);
  Randomized_QuickSort(array,p,q-1,count);
  Randomized_QuickSort(array,q+1,r,count);
 }
}
int main()
{
 int choice = 0;  
 while(choice != 3)
 {
  cout<<"1. QuickSort"<<endl;
  cout<<"2. Randomized QuickSort"<<endl;
  cout<<"3. To Exit"<<endl;
  cout<<"Enter Your Choice : "<<endl;
  cin>>choice;
  if(choice == 1)
  {
   int count=0,n;
   cout<<"Enter the Value for N : "<<endl;
   cin>>n;
   int a[n];
   ifstream fin;
   fin.open("input.txt");
   for(int i=0;i<n;i++)
   {
    fin>>a[i];
   }
   fin.close();
   QuickSort(a,0,n-1,count);
   cout<<"Random Input : "<<count<<endl;
   count = 0;
   ifstream fin1;
   fin1.open("input-asc.txt");
   for(int i=0;i<n;i++)
   {
    fin1>>a[i];
   }
   fin1.close();
   QuickSort(a,0,n-1,count);
   cout<<"Ascending Input : "<<count<<endl;
   count = 0;
   ifstream fin2;
   fin2.open("input-desc.txt");
   for(int i=0;i<n;i++)
   {
    fin2>>a[i];
   }
   fin2.close();
   QuickSort(a,0,n-1,count);
   cout<<"Descending Input : "<<count<<endl;
   count = 0;
   ifstream fin3;
   fin3.open("input-equal.txt");
   for(int i=0;i<n;i++)
   {
    fin3>>a[i];
   }
   fin3.close();
   QuickSort(a,0,n-1,count);
   cout<<"Equal Input : "<<count<<endl;
  }
  else if(choice == 2)
  {
   int count=0,n;
   cout<<"Enter the Value for N : "<<endl;
   cin>>n;
   int a[n];
   ifstream fin4;
   fin4.open("input.txt");
   for(int i=0;i<n;i++)
   {
    fin4>>a[i];
   }
   fin4.close();
   Randomized_QuickSort(a,0,n-1,count);
   cout<<"Random Input : "<<count<<endl;
   count = 0;
   ifstream fin5;
   fin5.open("input-asc.txt");
   for(int i=0;i<n;i++)
   {
    fin5>>a[i];
   }
   fin5.close();
   Randomized_QuickSort(a,0,n-1,count);
   cout<<"Ascending Input : "<<count<<endl;
   count = 0;
   ifstream fin6;
   fin6.open("input-desc.txt");
   for(int i=0;i<n;i++)
   {
    fin6>>a[i];
   }
   fin6.close();
   Randomized_QuickSort(a,0,n-1,count);
   cout<<"Descending Input : "<<count<<endl;
   count = 0;
   ifstream fin7;
   fin7.open("input-equal.txt");
   for(int i=0;i<n;i++)
   {
    fin7>>a[i];
   }
   fin7.close();
   Randomized_QuickSort(a,0,n-1,count);
   cout<<"Equal Input : "<<count<<endl;
  }
  else if(choice == 3)
  {
   cout<<"Thank You !!"<<endl;
   break;
  }
  else
  {
   cout<<"Invalid Input !!"<<endl;
  }
 }
 return 0;
}
   

