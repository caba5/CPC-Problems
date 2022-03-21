#include <iostream>
#include <vector>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n; std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

    int jumps = 0, curr_jump_end = 0, farthest = 0;
    for (int i = 0; i < n - 1; ++i){
        farthest = std::max(farthest, i + arr[i]);
        if (i == curr_jump_end){
            jumps++;
            curr_jump_end = farthest;
        }
    }
    std::cout << jumps << std::endl;

    return 0;
}