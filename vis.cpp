#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int> max_h;
    priority_queue<int, vector<int>, greater<int>> min_h;
public:
    MedianFinder() {
        
    }
    
    void addNum(int val) {
        min_h.push(val);
        // if ()
        // if (min_h.size() > max_h.size()){
        //     max_h.push(min_h.top());
        //     min_h.pop();
        // }
    }
    
    double findMedian() {
        double a = max_h.empty() ? -1 : max_h.top();
        double b = min_h.empty() ? -1 : min_h.top();
        
        return (max_h.size() == min_h.size()) ? (a + b) / 2 : max_h.top();
    }
};


void findMax(vector <int> &arr1, vector <int> &arr2, int k){
    int n = arr1.size();
    vector <int> sumArr;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sumArr.push_back(arr1[i] + arr2[j]);
        }
    }
   priority_queue<int, vector<int>, greater<int>> pq;
   int i = 0;
   for(i = 0; i < k; i++) {
     pq.push(sumArr[i]) ;
   }
   while(i < sumArr.size()){
     pq.push(sumArr[i]);
     pq.pop();
     i++;
   }
   vector <int> ans;
   while(!pq.empty()){
    ans.push_back(pq.top());
    pq.pop();
   }
   for(int val : ans) {
     cout << val << " ";
   }
}
int minCost(int n, vector<int>& arr) {
        vector dp(n + 1, vector <int> (n + 1, 0));
        for(int i = n; i > -1; i--){
            for(int j = i + 1; j < n + 1; j++){
               int min_val = 0;
               for(int k = 0; k < arr.size(); k++){
                   min_val = min(min_val, dp[i][arr[k]] + dp[arr[k]][j]);
               }
               dp[i][j] = min_val;
            }
        }
        return dp[0][n];
    }
int main() {
    vector <int> arr1 = {3, 4, 5};
    vector <int> arr2 = {2, 6, 3};
    findMax(arr1, arr2, 2);
    return 0;
}