#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void convert(int arr[], int n)
{
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    sort(temp, temp + n);
  
    for (int i = 0; i < n; i++) {
        cout << lower_bound(temp, temp + n, arr[i]) - temp << endl;
        arr[i] = lower_bound(temp, temp + n, arr[i]) - temp + 1;
    }
}

template<typename T>
void remap(vector<T> arr){
    vector<T> tmp(arr);
    sort(tmp.begin(), tmp.end());
    size_t sz = distance(tmp.begin(), unique(tmp.begin(), tmp.end()));
    tmp.resize(sz);
    for (T &x : arr){
        cout << x << " \t--> ";
        x = distance(tmp.begin(), lower_bound(tmp.begin(), tmp.end(), x));
        cout << x << endl;
    }
}

int main(){
    /*
    int arr[] = {7, -90, 100, 1};
    convert(arr, 4);
    */
    vector<int> v = {7, -90, 100, 1, 100};
    remap(v);
    return 0;
}