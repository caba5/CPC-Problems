#include <iostream>
#include <vector>
#include <stack>

void solve(std::vector<int> const& v){
    std::stack<int> S;
    std::vector<int> next(v.size());
    for (int i = v.size() - 1; i >= 0; --i){
        while (!S.empty() && v[i] > S.top())
            S.pop();

        if (S.empty())
            next[i] = -1;
        else
            next[i] = S.top();
            
        S.push(v[i]);
    }

    for (int x : next)
        std::cout << x << " ";
    std::cout << std::endl;
}

int main(){
    int n; std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];
    solve(arr);
    return 0;
}