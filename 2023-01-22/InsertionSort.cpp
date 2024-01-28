//Insertion Sorting using DSA Algorithm 
#include<iostream>
#include<fstream>
using namespace std;
void Insertion_Sort(int array[],int n)
{
 cout<<"The Entered Array : ["<<array[0];
 for(int i=1;i<n;i++)
 {
  cout<<", "<<array[i];
 }
 cout<<" ]"<<endl;
 int count = 0;
 for(int j=1;j<n;j++)
 {
  int key = array[j];
  int i=j-1;
  while(i>=0 and array[i]>key)
  {
   array[i+1] = array[i];
   i=i-1;
   count += 1;
  }
   array[i+1] = key;
   count += 1;
 } 
 cout<<"The Sorted Array : ["<<array[0];
 for(int i=1;i<n;i++)
 {
  cout<<", "<<array[i];
 }
 cout<<" ]"<<endl;
 cout<<"Total No. of Comparisons : "<<count<<endl;
 ofstream fout;
 fout.open("OutputFile.txt");
 fout<<n<<"\t";
 for(int i=0;i<n;i++)
 {
  fout<<"\t"<<array[i];
 }
 fout<<"\t\t"<<count;
 fout.close();
 cout<<"Output written in File Successfully !!"<<endl;
}
int main()
{
 int choice =0;
 while (choice != 5)
 {
  cout<<"1. Random Input "<<endl;
  cout<<"2. Ascending Order Input  "<<endl;
  cout<<"3. Descending Order Order Input  "<<endl;
  cout<<"4. Equal Input  "<<endl;
  cout<<"5. To Exit"<<endl;
  cout<<"Enter Your Choice : "<<endl;
  cin>>choice;
  int n;
  cout<<"Enter the Total No. fo Elements : "<<endl;
  cin>>n;
  int a[n];
  if(choice == 1)
  {
   ifstream fin;
   fin.open("input.txt");
   for(int i=0;i<n;i++)
   {
    fin>>a[i];
   }
   fin.close();
   Insertion_Sort(a,n);
  }
  else if (choice == 2)
  {
   ifstream fin;
   fin.open("input-asc.txt");
   for(int i=0;i<n;i++)
   {
    fin>>a[i];
   }
   fin.close();
   Insertion_Sort(a,n);
  }
  else if(choice == 3)
  {
   ifstream fin;
   fin.open("input-desc.txt");
   for(int i=0;i<n;i++)
   {
    fin>>a[i];
   }
   fin.close();
   Insertion_Sort(a,n);
  }
  else if(choice == 4)
  {
   ifstream fin;
   fin.open("input-equal.txt");
   for(int i=0;i<n;i++)
   {
    fin>>a[i];
   }
   fin.close();
   Insertion_Sort(a,n);
  }
  else if(choice == 5)
  {
   break;
  }
  else 
  {
   cout<<"Invalid Input Please ry Again"<<endl;
  }
 }
 return 0;
}
