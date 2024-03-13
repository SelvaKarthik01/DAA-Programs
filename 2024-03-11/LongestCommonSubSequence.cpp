// Completed Divide and Conquer and Bottom-Up Approach in Dynamic Programming Need to Complete Top-Bottom and Printing the Sequence 

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<cstring>
using namespace std;

void getInput(string &X,string &Y,int m,int n)
{
 string line;
 char S[] = {'A','B','C'};
 ofstream fout("lcs_input.txt");
 for(int i=0;i<m;i++)
 {
  fout<<S[rand() % 3];
 }
 fout<<endl;
 for(int i=0;i<n;i++)
 {
  fout<<S[rand() % 3];
 }
 fout.close();
 ifstream fin("lcs_input.txt");
 getline(fin,X);
 cout<<X<<endl;;
 getline(fin,Y);
 cout<<Y<<endl;
}

void PRINT_LCS(string X, int i, int j) {
    if (i == 0 || j == 0)
        return;
    
    char b[i + 1][j + 1]; 
    
    if (b[i][j] == '↖') {
        PRINT_LCS(X, i - 1, j - 1);
        cout << X[i - 1];
    } else if (b[i][j] == '↑') {
        PRINT_LCS(X, i - 1, j);
    } else {
        PRINT_LCS(X, i, j - 1);
    }
}

int LCS_LENGTH_TD(string X, string Y, int** c, int i, int j, int& count) {
    if (i == 0 || j == 0)
        return 0;
    
    if (c[i][j] != -1)
        return c[i][j];
    
    count++; // Increment comparison count
    
    if (X[i - 1] == Y[j - 1]) {
        c[i][j] = LCS_LENGTH_TD(X, Y, c, i - 1, j - 1, count) + 1;
    } else {
        c[i][j] = max(LCS_LENGTH_TD(X, Y, c, i - 1, j, count), LCS_LENGTH_TD(X, Y, c, i, j - 1, count));
    }
    
    return c[i][j];
}

int LCS_LENGTH_BU(string X,string Y,int m,int n,int &count)
{
 int L[m+1][n+1];
 for(int i=0;i<=m;i++)
 {
  L[i][0] = 0;
 }
 for(int j=0;j<=n;j++)
 {
  L[0][j] = 0;
 }
 for(int i=1;i<=m;i++)
 {
  for(int j=1;j<=n;j++)
  {
   count += 1;
   if(X[i-1] == Y[j-1])
   {
    L[i][j] = 1+ L[i-1][j-1];
   }
   else 
   {
    L[i][j] = max(L[i-1][j],L[i][j-1]);
   }
  }
 }
 return L[m][n];
} 
int LCS_LENGTH_DC(string X,string Y,int m,int n,int &count)
{
 count += 1;
 if(m==0 || n==0)
 {
  return 0;
 }
 else
 {
  if(X[m-1] == Y[n-1])
  {
   return 1 + LCS_LENGTH_DC(X,Y,m-1,n-1,count);
  }
  else
  {
   int t1 = LCS_LENGTH_DC(X,Y,m-1,n,count);
   int t2 = LCS_LENGTH_DC(X,Y,m,n-1,count);
   if(t1 >= t2)
   {
    return t1; 
   }
   else
   {
    return t2;
   }
  }
 }
}
int main()
{
 int m,n;
 cout<<"Enter the Length of First String(M) : ";
 cin>>m;
 cout<<"Enter the Length for Second String(N) : ";
 cin>>n;
 string X,Y;
 getInput(X,Y,m,n);
 int length,count =0;
 length = LCS_LENGTH_DC(X,Y,m,n,count);
 cout<<"Length of the Longest Common Subsequence using DC is : "<<length<<endl;
 cout<<"Total No. of Comparisons using DC : "<<count<<endl;
 count = 0;
 length = LCS_LENGTH_BU(X,Y,m,n,count);
 cout<<"Length of the Longest Subsequence using Bottom Up : "<<length<<endl;
 cout<<"Total No. of Comparisons using Bottom-Up Approach : "<<count<<endl;
 count = 0;
  int** memo = new int*[m + 1];
    for (int i = 0; i <= m; ++i) {
        memo[i] = new int[n + 1];
        for (int j = 0; j <= n; ++j) {
            memo[i][j] = -1;
        }
    }
    
    // Counter to track the number of comparisons
    int comparisonCount = 0;
    
    // Compute LCS length using top-down dynamic programming
    int lcsLength = LCS_LENGTH_TD(X, Y, memo, m, n, comparisonCount);
    
    cout << "Length of Longest Common Subsequence: " << lcsLength << endl;
    cout << "Total Number of Comparisons using Top-Down Approach : " << comparisonCount << endl;
    
    // Deallocate memoization table
    for (int i = 0; i <= m; ++i) {
        delete[] memo[i];
    }
    delete[] memo;
 PRINT_LCS(X,m-1,n-1);
 return 0;
}
