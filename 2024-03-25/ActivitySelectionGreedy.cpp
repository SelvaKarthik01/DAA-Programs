// Activity Selection using Greedy Algorithm and Recursive Algorithm 
#include<iostream>
#include<set>
using namespace std;
set<int> Greedy_Activity_Selector(int S[],int s[],int f[],int n)
{
 set<int>A;
 A.insert(S[0]);
 int k = 0;
 int count = 1;
 for(int m=1;m<n;m++)
 {
  if(s[m] >= f[k])
  {
   A.insert(S[m]);
   k = m;
  }
 }
 return A;
}
set<int> RecursiveActivitySelector(int S[],const int s[], const int f[], int k, int n) 
{
 int m = k + 1;
 
 while (m <= n && s[m] < f[k]) {
        m++;
    }
    if (m <= n) {
      
        set<int> A = RecursiveActivitySelector(S,s, f, m, n);
        A.insert(S[0]);
        A.insert(S[m]); 
        return A;
    } else {

        return set<int>(); 
    }
}
int main()
{
 int n;
 cout<<"Enter the Total No. of Activities : "<<endl;
 cin>>n;
 int S[n],s[n],f[n];
 for(int i=0;i<n;i++)
 {
  S[i] = i+1;
  cout<<"Enter the Start Time of Activity "<<i+1<<" : ";
  cin>>s[i];
  cout<<"Enter the Final Time of Activity "<<i+1<<" : ";
  cin>>f[i];
 }
 cout<<"[ ";
 for(int i=0;i<n;i++)
 {
  cout<<S[i]<<" ";
 }
 cout<<"]"<<endl;
cout<<"[ ";
 for(int i=0;i<n;i++)
 {
  cout<<s[i]<<" ";
 }
 cout<<"]"<<endl;
 cout<<"[ ";
 for(int i=0;i<n;i++)
 {
  cout<<f[i]<<" ";
 }
 cout<<"]"<<endl;
 for(int i=0;i<n-1;i++)
 {
  for(int j=0;j<n-i-1;j++)
  {
   if(f[j] > f[j+1])
   {
    swap(f[j],f[j+1]);
    swap(S[j],S[j+1]);
    swap(s[j],s[j+1]);
   }
  }
 }
 cout<<"After Sorting : "<<endl;
 cout<<"[ ";
 for(int i=0;i<n;i++)
 {
  cout<<S[i]<<" ";
 }
 cout<<"]"<<endl;
cout<<"[ ";
 for(int i=0;i<n;i++)
 {
  cout<<s[i]<<" ";
 }
 cout<<"]"<<endl;
 cout<<"[ ";
 for(int i=0;i<n;i++)
 {
  cout<<f[i]<<" ";
 }
 cout<<"]"<<endl;
 set<int>A = Greedy_Activity_Selector(S,s,f,n);
 cout<<"Greedy Algorithm : "<<endl;
 cout<<"The Activities must be Selected in this Order : [ ";
 set<int>::iterator itr;
 for(itr = A.begin(); itr != A.end();itr++)
 {
  cout<<*itr<<" ";
 }
 cout<<"]"<<endl;
 cout<<"Recursive Algorithm : "<<endl;
 set<int>B = RecursiveActivitySelector(S,s,f,0,n);
 cout<<"The Activities must be Selected in this Order : [ ";
 set<int>::iterator itr1;
 for(itr1 = B.begin(); itr1 != B.end();itr1++)
 {
  cout<<*itr1<<" ";
 }
 cout<<"]"<<endl;
 return 0;
}
