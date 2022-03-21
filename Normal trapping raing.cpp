#include <iostream>
#include <vector>

int solve(std::vector<int> const& v){
    std::vector<int> LL(v.size());
    std::vector<int> RL(v.size());

    LL[0] = v[0];
    for (int i = 1; i < v.size(); ++i){
        if (v[i] > LL[i-1])
            LL[i] = v[i];
        else
            LL[i] = LL[i-1];
    }
    RL[v.size()-1] = v[v.size()-1];
    for (int i = v.size()-2; i >= 0; --i){
        if (v[i] > RL[i+1])
            RL[i] = v[i];
        else
            RL[i] = RL[i+1];
    }

    int amount = 0;
    for (int i = 0; i < v.size(); ++i)
        amount += std::min(LL[i], RL[i]) - v[i];

    return amount;
}

int main(){
    int n; std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
    
    std::cout << "Result = " << solve(v) << std::endl;
    
    return 0;
}