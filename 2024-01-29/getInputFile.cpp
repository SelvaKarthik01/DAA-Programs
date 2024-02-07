#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void randomInput()
{
	ofstream fout("input.txt");
	srand ((long int)clock());
	for (int i=0; i<10010; i++)
	    fout << rand()%30000<<"\t";
	fout.close();	
}
void ascendingInput()
{
	ofstream fout("input-asc.txt");
	for (int i=0; i<10010; i++)
	    fout <<i<<"\t";
	fout.close();	
}
void descendingInput()
{
	ofstream fout("input-desc.txt");
	for (int i=10009; i>=0; i--)
	    fout <<i<<"\t";
	fout.close();	
}
void equalInput()
{
	ofstream fout("input-equal.txt");
	for (int i=0; i<=10010; i++)
	    fout <<1<<"\t";
	fout.close();	
}
int main(){
	randomInput();
	ascendingInput();
	descendingInput();
	equalInput();
	return 0;
}
