#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int last_going = arr[0];
    int last_len = 1;
    int curr_len = 1;
    int max_len = 1;
    for (int i = 1; i < n; ++i){
        if (arr[i] > arr[i-1]){
            curr_len++;
            if (arr[i] > last_going){
                last_going = arr[i];
                last_len++;
            }
            else if (last_going != INT32_MAX){
                max_len = max(max_len, last_len);
                last_len = 0;
                last_going = INT32_MAX;
            }
        } else{
            max_len = max(max_len, last_len);
            last_len = curr_len + 1;
            last_going = arr[i-1];
            curr_len = 1;
        }        
    }

    max_len = max(max(max_len, curr_len), last_len);

    cout << max_len << endl;

    return 0;
}