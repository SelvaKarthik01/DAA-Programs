#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
struct node
{
 int data;
 node* link;
}
struct sll
{
 int count;
 node * head;
}

void BucketSort(long int A[],long int &count)
{
 int n = A.length;
 for(int i=0;i<=n-1;i++))
 {
  long int B[i];
 }
 for(int i=1;i<=n;i++)
 {
  count += 1;
 }
 InsertOrder(B[[n*A[i]]],A[i]);
 for(int i=0;i<=n-1;i++)
 {
  B[i] = B[i]+B[i+1];
  count += 1;
 }
}
void InsertOrder(int first,int x,int &count)
{
 sll S;
 S->count = 0;
 S->head = NULL;
 node *n = new node;
 n->data = x;
 
int main()
{
 ofstream fout("input_bsort.txt");
 srand((long int )clock());
 for(int i=0;i<10;i++)
 {
  fout<<(float)rand()/RAND_MAX<<"\t";
 }
 fout.close();
 long int A[11000];
 ifstream fin("input_bsort.txt")
 for(int i=0;i<n;i++)
 {
  fin>>A[i];
 }
 
  
}
