#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n; std::cin >> n;
    std::vector<int> inputs(n);
    for (int i = 0; i < n; ++i)
        std::cin >> inputs[i];
    
    int curr = 0;   // No need to use an array, just propagate current item
    int moves = 0;
    for (int i = 0; i < n; ++i){
        if (curr - inputs[i] != 0){
            curr += inputs[i] - curr;
            moves++;
        }        
    }

    std::cout << moves << std::endl;

    return 0;
}