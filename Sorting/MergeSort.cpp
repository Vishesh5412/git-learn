#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector <int> &arr){
  int n = arr.size();
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
     for(int j = i + 1; j < n; j++){
        minIndex = arr[j] < arr[minIndex] ? j : minIndex;
     }
        swap(arr[i], arr[minIndex]);
    }
}


void insertionSort(vector <int> &arr){
    for(int i = 1; i < arr.size(); i++){
        int j = i;
        while(j > 0 && arr[j] < arr[j-1]){
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}
int main() {
vector <int> arr = {44, 33, 11, 55, 77, 90, 40, 60, 99, 22,  88, 66};
selectionSort(arr);
for(int i = 0; i < arr.size(); i++){
    cout << arr[i] <<  " ";
}
cout << "\n";
insertionSort(arr);
for(int i = 0; i < arr.size(); i++){
    cout << arr[i] << " ";
}
    return 0;
}