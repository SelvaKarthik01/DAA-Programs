//Implemting Counting Sort using DSA Algorithms and Taking Analysis of it 
#include<iostream>
#include<fstream>
using namespace std;
void CountSort(int A[],int B[],int n,int k,int &count)
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
 for(int i=0;i<=k;i++)
 {
  count += 1;
  C[i]= C[i-1]+C[i];
 }
 for(int j=n;j>=1;j--)
 {
  count += 1;
  B[C[A[j]]]=A[j];
  C[A[j]]=C[A[j]]-1;
 }
}
int main()
{
 int n= 10;
 int count = 0;
 int A[11000],B[11000];
 ifstream fin;
 fin.open("input_csort_1.txt");
 for(int i=0;i<n;i++)
 {
  fin>>A[i];
 }
 fin.close();
 int k = n/2;
 CountSort(A,B,n,k,count);
 cout<<"Total No. of Comparisons(N="<<n<<") : "<<count<<endl;
 int n1= 50;
 count = 0;
 int A1[11000],B1[11000];
 ifstream fin1;
 fin1.open("input_csort_2.txt");
 for(int i=0;i<n1;i++)
 {
  fin1>>A1[i];
 }
 fin1.close();
 k = n1/2;
 CountSort(A1,B1,n1,k,count);
 cout<<"Total No. of Comparisons(N="<<n1<<") : "<<count<<endl;
 int n2= 100;
 count = 0;
 int A2[11000],B2[11000];
 ifstream fin2;
 fin2.open("input_csort_3.txt");
 for(int i=0;i<n2;i++)
 {
  fin2>>A2[i];
 }
 fin2.close();
 k = n2/2;
 CountSort(A2,B2,n2,k,count);
 cout<<"Total No. of Comparisons(N="<<n2<<") : "<<count<<endl;
 int n3= 500;
 count = 0;
 int A3[11000],B3[11000];
 ifstream fin3;
 fin3.open("input_csort_4.txt");
 for(int i=0;i<n3;i++)
 {
  fin3>>A3[i];
 }
 fin3.close();
 k = n3/2;
 CountSort(A3,B3,n3,k,count);
 cout<<"Total No. of Comparisons(N="<<n3<<") : "<<count<<endl;
 int n4= 1000;
 count = 0;
 int A4[11000],B4[11000];
 ifstream fin4;
 fin4.open("input_csort_5.txt");
 for(int i=0;i<n4;i++)
 {
  fin4>>A4[i];
 }
 fin4.close();
 k = n4/2;
 CountSort(A4,B4,n4,k,count);
 cout<<"Total No. of Comparisons(N="<<n4<<") : "<<count<<endl;
 int n5= 5000;
 count = 0;
 int A5[11000],B5[11000];
 ifstream fin5;
 fin5.open("input_csort_6.txt");
 for(int i=0;i<n5;i++)
 {
  fin5>>A5[i];
 }
 fin5.close();
 k = n5/2;
 CountSort(A5,B5,n5,k,count);
 cout<<"Total No. of Comparisons(N="<<n5<<"):"<<count<<endl;
 int n6= 10000;
 count = 0;
 int A6[11000],B6[11000];
 ifstream fin6;
 fin6.open("input_csort_7.txt");
 for(int i=0;i<n6;i++)
 {
  fin6>>A6[i];
 }
 fin6.close();
 k = n6/2;
 CountSort(A6,B6,n6,k,count);
 cout<<"Total No. of Comparisons(N="<<n6<<") : "<<count<<endl;
 return 0;
}
 
  

