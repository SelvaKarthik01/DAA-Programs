//Implementation of Sum of Subset using Backtracking Method
#include<iostream>
using namespace std;
void BackTrack(int A[],int n,int target,int Subset[],int SubsetSize,int start,int sum)
{
 if (sum == target)
 {
  cout<<"[ ";
  for(int i=0;i<SubsetSize;++i)
  {
   cout<<Subset[i]<<" ";
  }
  cout<<"]"<<endl; 
 }
 for(int i=start;i<n;i++)
 {
  if(A[i] + sum <= target)
  {
   Subset[SubsetSize++] = A[i];
   BackTrack(A,n,target,Subset,SubsetSize,i+1,sum + A[i]) ;
   SubsetSize -= 1;
  }
 }
}
void findSubsets(int A[],int n,int target)
{
 int Subset[n];
 int SubsetSize = 0;
 BackTrack(A,n,target,Subset,SubsetSize,0,0);
}
int main()
{
 int n;
 cout<<"Enter the No. of Elements in Array : ";
 cin>>n;
 int A[n];
 cout<<"Enter the Elements of the Array : "<<endl;
 for(int i=0;i<n;i++)
 {
  cout<<"Element No."<<i+1<<" : ";
  cin>>A[i];
 }
 int target;
 cout<<"Enter the Target Sum : ";
 cin>>target;
 cout<<"All Possible Subsets : "<<endl;
 cout<<endl;
 findSubsets(A,n,target);
 return 0;
}