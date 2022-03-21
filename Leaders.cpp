#include <iostream>
#include <vector>

void leaders(std::vector<int> const& v){
    std::vector<int> leaders;
    int max = INT32_MIN;
    for (int i = v.size() - 1; i >= 0; --i){
        if (v[i] > max){
            leaders.push_back(v[i]);
            max = v[i];
        }
    }
    
    for (std::vector<int>::reverse_iterator it = leaders.rbegin(); it != leaders.rend(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    int n; std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];
    leaders(arr);
    return 0;
}