//Implementing Radix Sort using DSA Algorithm
#include<fstream>
#include <bits/stdc++.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
void Countsort(long int A[],long int B[],int n, int k,int &count)
{
 int C[k];
 for(int i=0;i<=k;i++)
 {
  count += 1;
  C[i] = 0;
 }
 for(int j=1;j<=n;j++)
 {
  count += 1;
  C[A[j]] = C[A[j]] + 1;
 }
 for(int i =1;i<=k;i++)
 {
  count += 1;
  C[i] = C[i-1] + C[i];
 }
 for(int j=n;j>=1;j--)
 {
  count += 1;
  B[C[A[j]]] = A[j];
  C[A[j]] = C[A[j]] - 1;
 }
}
void RadixSort(long int A[],int m,int n,int &count)
{
 long int B[11000];
 for(int d=1;d<=m;d++)
 {
  Countsort(A,B,n,10,count);
  for(int i=0;i<n;i++)\
  {
   A[i] = B[i];
  }
 }
}
int main()
{
 ofstream fout("input_rsort.txt");
 srand ((long int)clock());
 for(int i=0;i<10000;i++)
 {
  fout<<1000 + rand()%9000<<"\t";
 }
 fout.close();
 int n;
 cout<<"Enter the Value for N : "<<endl;
 cin>> n;
 long int A[11000];
 ifstream fin("input_rsort.txt");
 for(int i=0;i<n;i++)
 {
  fin>>A[i];
 }
 int count = 0;
 int max_el = *max_element(A,A+n);
 int m = to_string(max_el).length();
 RadixSort(A,m,n,count);
 cout<<"Total No. of Comparisons : "<<count<<endl;
 fin.close();
 return 0;
}
 