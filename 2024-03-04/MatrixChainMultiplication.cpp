//Implementation of Matrix Chain Multiplication using Dynamic Programming and Divide and Conquer Method 
#include<iostream>
#include<fstream>
#include<limits.h>
#include<stdlib.h>
using namespace std;
void getInput(int p[], int n)
{
 ofstream fout;
 fout.open("input.txt");
 srand((long int)clock());
 for(int i=0;i<n;i++)
 {
  fout<<rand() % 30<<"\t";
 }
 fout.close();
 ifstream fin;
 fin.open("input.txt");
 for(int i=0;i<n;i++)
 {
  fin>>p[i];
 }
}
int Matrix_Chain_Order(int p[],int n,int &count)
{
 int m[n][n],s[n][n];
 int q,k;
 for(int i=1;i<=n;i++)
 {
  m[i][i] = 0;
 }
 for(int l=2;l<=n-1;l++)
 {
  for(int i=1;i<=n-1;i++)
  {
   int j = i+l;
   m[i][j] = INT_MAX;
   for(k=i;k<=j-1;k++)
   {
    count = count + 1; 
    q = m[i][k] + m[k][j]+p[i-1]*p[k]*p[j];   
    if(q<m[i][j])
    {
     m[i][j] = q;
     s[i][j] = k;
    }
   }
  }
 }
 return q,k;
}
void Print_Opt_Order(int s[],int i,int j)
{
 if(i==j)
 {
  cout<<s<<i<<endl;
 }
 else
 {
  cout<<"(";
  Print_Opt_Order(s,i,s[i,j]);
  Print_Opt_Order(s,s[i,j]+1,j);
  cout<<" )"<<endl;
 }
}
int Rec_Mat_Chain(int p[],int i,int j,int &count)
{
 if(i==j)
 {
  return 0;
 }
 long int t= INT_MAX;
 long int  q;
 for(int k=i;k<=j-1;k++)
 {
  count +=1;
  q = Rec_Mat_Chain(p,i,k,count) + Rec_Mat_Chain(p,k+1,j,count) + p[i-1]*p[k]*p[j];
  if(q<t)
  {
   t=q;
  }
 }
 return t;
}
int main()
{
 int n;
 cout<<"Enter the Number of Dimensions :";
 cin>>n;
 int p[n];
 int count = 0;
 getInput(p,n);
 for(int i=0;i<n;i++)
 {
  cout<<p[i]<<endl;
 }
 int i,j;
 cout<<"Enter the Value of i and j : "<<endl;
 cin>>i>>j;
 cout<<"Multiplications : "<<Rec_Mat_Chain(p,i,j,count)<<endl;
 cout<<"Divide and Conquer Operations  : "<<count<<endl;
 int a,b;
 count = 0;
 a,b = Matrix_Chain_Order(p,n,count);
 cout<<a<<endl;
 cout<<"Dynamic Programming Operations : "<<count<<endl;
 return 0;
}
 
