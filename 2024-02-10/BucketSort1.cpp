#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct SLLNODE {
    float data;
    SLLNODE* link;
};

void INSERT_ORDER(SLLNODE*& first, float x, int& count) {
    SLLNODE* n = new SLLNODE();
    n->data = x;

    SLLNODE* temp = first;

    if (first == NULL || first->data >= x) {
        n->link = first;
        first = n;
        return;
    }

    while (temp->link != NULL && temp->link->data < x) {
        count++;
        temp = temp->link;
    }

    n->link = temp->link;
    temp->link = n;
}

int BUCKETSORT(float A[], int n) {
    SLLNODE* B[n];
    int count = 0;
    for (int i = 0; i < n; ++i) {
        B[i] = NULL;
    }
    for (int i = 0; i < n; ++i) {
        count++;
        int index = static_cast<int>(n * A[i]);
        INSERT_ORDER(B[index], A[i], count);
    }


    for (int i = 0; i < n; ++i) {
        SLLNODE* current = B[i];
        while (current != NULL) {
            count += current->data;
            current = current->link;
        }
    }

    return count;
}
int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    ofstream fout("input_bsort.txt");
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < n; i++) {
        fout << (float)rand() / RAND_MAX << "\t";
    }
    fout.close();
    ifstream fin("input_bsort.txt");
    float A[n];
    for (int i = 0; i < n; ++i) {
        fin >> A[i];
    }
    fin.close();
    cout << "Original Array: ";
    for (int i = 0; i < n; ++i) {
        cout << A[i] << "\t";
    }
    cout << endl;
    int comparisons = BUCKETSORT(A, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; ++i) {
        cout << A[i] << "\t";
    }
    cout << endl;
    cout << "Number of Comparisons: " << comparisons << endl;
    return 0;
}

