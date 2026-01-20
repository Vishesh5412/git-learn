#include <bits/stdc++.h>
using namespace std;
int setPivot(vector <int> &arr, int st, int en){
   int pIndex = st;
   while(st < en){
    while(st < en && arr[en] > arr[pIndex]){
        en--;
    }
    swap(arr[pIndex], arr[en]);
    pIndex = en;
    while(st < en && arr[st] <= arr[pIndex]){
        st++;
    }
    swap(arr[pIndex], arr[st]);
    pIndex = st;
   } 
   return pIndex;
}
void quickSort(vector <int> &arr, int st, int en){
    if (st < en){
    int pIndex = setPivot(arr, st, en);
     quickSort(arr, st, pIndex-1);
     quickSort(arr, pIndex+1, en);
    }
}

int main() {
vector <int> arr = {7, 3, 1, 5, 8, 2, 4, 6, 9};
quickSort(arr, 0, arr.size()-1);
for(int i = 0; i < arr.size(); i++){
    cout << arr[i] << " ";
}
    return 0;
}