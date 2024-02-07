#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
using namespace std;

long int A[11000],B[11000];
int n,k,count=0;

void getInput(char fname[]) {
	ifstream fin(fname);
	for(int i=0; i<n; i++) {
		fin >> A[i];
	}
	fin.close();
}


void countSort() {
	int C[k];
	for(int i=0; i<=k ; i++) {
		count = count+1;
		C[i] = 0;
	}
	for(int j=1; j<=n ; j++) {
		count = count+1;
		C[A[j]] = C[A[j]]+1;
	}
	for(int i=1; i<=k ; i++) {
		count = count+1;
		C[i] = C[i-1]+C[i];
	}
	for(int j=n; j>=1 ; j--) {
		count = count+1;
		B[C[A[j]]] = A[j];
		C[A[j]] = C[A[j]]-1;
	}
}

void writeOutput() {
	cout << "n = " << n << "\nk = " << k << "\nCount = " << count << "\n\n";
}

void createInput() {
	int size[] = {10,50,100,500,1000,5000,10000};
	for(int i=0;i<7;i++) {
		char fname[25] = "input_csort_";
		char ext[2];
		srand((long int)clock());
		ext[0] = '1' + i;
		ext[1] = '\0';
		n = size[i];
		k = n/2;
		strcat(fname,ext);
		strcat(fname,".txt");
		ofstream fout(fname);
		for(int j=0;j<n;j++)
		{
		fout<<rand()% (n/2) <<"\t";
		}
		fout.close();
		count=0;
		getInput(fname);
		countSort();
		writeOutput();	
	}
}

int main(){ 
	createInput();
	return 0;	
}
