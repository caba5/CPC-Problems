#include <iostream>
#include <vector>
#include <deque>

void solve(std::vector<int> const& v, int k){
    std::deque<int> pos(k);
    std::vector<int> maxs;
    maxs.reserve(v.size() - k + 1);

    for (int i = 0; i < v.size(); ++i){
        while (!pos.empty() && pos.front() <= i - k)
            pos.pop_front();
        
        while (!pos.empty() && v[pos.back()] <= v[i])
            pos.pop_back();
        
        pos.push_back(i);

        if (i >= k - 1)
            maxs.push_back(v[pos.front()]);
    }

    for (int x : maxs)
        std::cout << x << " ";
    std::cout << std::endl;
}

int main(){
    int n; std::cin >> n;
    int k; std::cin >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

    solve(arr, k);
    return 0;
}