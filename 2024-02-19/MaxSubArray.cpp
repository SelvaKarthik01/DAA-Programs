#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
using namespace std;
int Max_Subarray_BF(int A[],int n,int &count)
{
 long int max_sum = -(INT_MAX);
 int i,sum=0,l,h;
 for(i=1;i<=n;i++)
 {
  sum = 0;
  for(int j=i;j<=n;j++)
  {
   count += 1;
   sum += A[j];
   if(sum > max_sum)
   {
    max_sum = sum;
    l=i;h=j;
   }
  }
 }
 return(l,h,max_sum);
}
int Find_Max_Cross_Subarray(int A[],int low,int mid,int high,int &count)
{
 int left_sum = -(INT_MAX);
 int sum = 0,max_left,max_right,right_sum;
 for(int i=mid;i<low;i--)
 {
  count += 1;
  sum += A[i];
  if(sum > left_sum)
  {
   left_sum = sum;
   max_left = i;
  }
 }
 right_sum = -(INT_MAX);
 sum = 0;
 for(int j=mid +1;j<high;j++)
 {
  count += 1;
  sum = sum + A[j];
  if(sum > right_sum)
  {
   right_sum = sum;
   max_right = j;
  }
 }
 return(max_left,max_right,left_sum+right_sum);
}
int Find_Max_Subarray(int A[],int low,int high,int &count)
{
 if(low == high)
 {
  return (low,high,A[low]);
 }
 else
 {
  int l_low,r_low,c_low,l_high,r_high,c_high,l_sum,r_sum,c_sum;
  int mid = (low + high)/2;
  (l_low,l_high,l_sum)= Find_Max_Subarray(A,low,mid,count);
  (r_low,r_high,r_sum)=Find_Max_Subarray(A,mid+1,high,count);
  (c_low,c_high,c_sum)=Find_Max_Cross_Subarray(A,low,mid,high,count);
  if(l_sum >= r_sum and l_sum >= c_sum)
  {
   return (l_low,l_high,l_sum);
  }
  else if(r_sum>=l_sum and r_sum>= c_sum)
  {
   return(r_low,r_high,r_sum);
  }
  else
  {
   return(c_low,c_high,c_sum);
  }
 }
}
int main()
{
 ofstream fout("input_maxSubArray.txt");
 srand((long int)clock());
 for(int i=0;i<10000;i++)
 {
  int num = rand()%30;
  if(rand()%2 == 0)
  {
   fout<<-1 *num<<"\t";
  }
  else
  {
   fout<<num<<"\t";
  }
 }
 fout.close();
 cout<<"Enter the Value for N : "<<endl;
 int n;
 cin>>n;
 int A[n];
 ifstream fin;
 fin.open("input_maxSubArray.txt");
 for(int i=0;i<n;i++)
 {
  fin>>A[i];
 }
 int count = 0,a,b,c,e,f,g;
 cout<<"Brute Force Method : "<<endl;
 (a,b,c) = Max_Subarray_BF(A,n,count);
 cout<<"Low : "<<a<<"\n"<<"High : "<<b<<"\n"<<"Max Sum : "<<c<<"\n"<<endl;
 cout<<"Total No. of Comparisons : "<<count<<endl;
 cout<<endl;
 cout<<"Divide and Conquer Method : "<<endl;
 count = 0;
 (e,f,g) = Find_Max_Subarray(A,0,n-1,count);
 cout<<"Low : "<<e<<"\n"<<"High : "<<f<<"\n"<<"Max Sum : "<<g<<"\n"<<endl;
 cout<<"Total No. of Comparisons : "<<count<<endl;

 fin.close();
 return 0;
} 
