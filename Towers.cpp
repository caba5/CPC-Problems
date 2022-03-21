#include <iostream>
#include <vector>
#include <unordered_map>

void solve(std::vector<int> const& v){
    int highest = v[0];
    std::unordered_map<int, int> bars;
    for (auto it = v.begin(); it != v.end(); ++it){
        if (bars.find(*it) == bars.end())
            bars[*it] = 1;
        else
            bars[*it] += 1;

        if (bars[*it] > bars[highest])
            highest = *it;
    }
    
    std::cout << bars[highest] << " " << bars.size() << std::endl;
}

int main(){
    int n; std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

    solve(arr);
    return 0;
}