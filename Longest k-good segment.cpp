#include <iostream>
#include <vector>
#include <unordered_set>

void solve(std::vector<int> const& v, int k){
    std::unordered_set<int> segment_nums;
    int left{0}, right{0}, counter{0}, max_right{0}, max_left{0};
    while (right < v.size()){
        if (counter <= k){
            if (segment_nums.find(v[right]) == segment_nums.end())
                segment_nums.insert(v[right]), 
                counter++;
            if ((counter <= k) && (right - left > max_right - max_left))
                max_right = right, 
                max_left = left;
            right++;
        }
        else{
            segment_nums.erase(v[left]);
            counter--;
            left++;
        }
    }
    
    std::cout << max_left + 1 << " " << max_right + 1 << std::endl;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n, k; std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

    solve(arr, k);
    return 0;
}