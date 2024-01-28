#include <iostream>
#include <fstream>
#include <limits.h>
#include <cstring>

using namespace std;
class HeapSort{
	private:
		long int a[11000];
	public:
		void readInput(int n, int type){
			char s[16];
			switch (type){
				case 0: strcpy(s, "input.txt"); break;
				case 1: strcpy(s, "input-asc.txt"); break;
				case 2: strcpy(s, "input-desc.txt"); break;
				case 3: strcpy(s, "input-equal.txt"); break;
			}
			ifstream fin(s);
			for (int i=0; i<n; i++)
			   fin >> a[i];
			fin.close();
		}
		void writeOutput(int n){
			ofstream fout("output.txt");
			for (int i=0; i<n; i++)
			   fout << a[n-1-i] << "\t";
			fout.close();   
		}
		
		void maxHeapify(int heapsize, int i, int &count)
		{	
		    count++;  
			int left, right, max;
			left = 2*i + 1;
			right = 2*i + 2;
			if(left<=heapsize && a[left]>a[i])
			{
				max = left;
			}
			else
			{
				max = i;
			}
			if(right<=heapsize && a[right]>a[max])
			{
				max = right;
			}
			if(max!=i)
			{
				swap(a[i],a[max]);
				maxHeapify(heapsize, max, count);
			}		
		}

		void buildMaxHeap(int heapsize, int &count)
		{
			for(int i=(heapsize+1)/2;i>=0;i--)
			{
				maxHeapify(heapsize, i, count);
			}
		}

		int heapSort(int n)
		{
			int count = 0;
			int heapsize = n-1;
			buildMaxHeap(heapsize, count);
			for(int i=n-1;i>=1;i--)
			{
				swap(a[0],a[i]);
				heapsize--;
				maxHeapify(heapsize, 0, count);
			}
			return count;
		}
};
int main(){
	HeapSort s;
	int ch;
	int len[7] = {10, 50, 100, 500, 1000, 5000, 10000};
	do {
		cout << "1. Heap Sort , 2.Exit " << endl;
		cout << "Enter your option: ";
		cin >> ch;
		if (ch != 1 && ch==2) 
		    break;
		cout << "For Random Input: " << endl;
		for (int i=0; i<7; i++){
			int count = 0;
			int n = len[i];
			s.readInput(n, 0);
			switch (ch){
				case 1: count = s.heapSort(n-1);
				        break;
			}	
			s.writeOutput(n);
			cout << "Input size: " << n << "\t" << "No. of Comparisons: " << count << endl;
		}
		cout << endl << "For ascending order input: " << endl;
		for (int i=0; i<7; i++){
			int count = 0;
			int n = len[i];
			s.readInput(n, 1);
			switch (ch){
				case 1: count = s.heapSort(n-1);
				        break;
			}	
		//	s.writeOutput(n);
			cout << "Input size: " << n << "\t" << "No. of Comparisons: " << count << endl;
		}
		cout << endl << "For descending order input: " << endl;
		for (int i=0; i<7; i++){
			int count = 0;
			int n = len[i];
			s.readInput(n, 2);
			switch (ch){
				case 1: count = s.heapSort(n-1);
				        break;
			}	
		//	s.writeOutput(n);
			cout << "Input size: " << n << "\t" << "No. of Comparisons: " << count << endl;
		}
		cout << endl << "For all elements are same input: " << endl;
		for (int i=0; i<7; i++){
			int count = 0;
			int n = len[i];
			s.readInput(n, 3);
			switch (ch){
				case 1: count = s.heapSort(n-1);
				        break;
			}	
		//	s.writeOutput(n);
			cout << "Input size: " << n << "\t" << "No. of Comparisons: " << count << endl;
		}
	}
	while (ch < 5);
	return 0;
}
