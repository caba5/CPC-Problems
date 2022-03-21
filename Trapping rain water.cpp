#include <iostream>
#include <vector>

template<typename Iter>
int compute_trapped(Iter it, int& level){
    if (*it > level)
        level = *it;
    return level - *it;
}

void trapped(std::vector<int> const& v){
    auto begin = v.begin();
    auto end = v.end() - 1;

    int curr_level = 0;
    int trapped = 0;

    while (begin != end){
        if (*begin <= *end){
            trapped += compute_trapped(begin, curr_level);
            ++begin;
        }
        else{
            trapped += compute_trapped(end, curr_level);
            --end;
        }
    }

    std::cout << "The amount of total trapped water is: " << trapped << std::endl;
}

int main(){
    int n; std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

    trapped(arr);
    return 0;
}