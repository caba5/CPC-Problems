#include <iostream>
#include <vector>
#include <algorithm>

struct meeting{
    int start, end;
    
    meeting(int s, int e)
        : start(s), end(e) {}
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n; std::cin >> n;
    std::vector<meeting> arr;
    arr.reserve(n);
    for (int i = 0; i < n; ++i){
        int start, end;
        std::cin >> start >> end;
        arr.emplace_back(start, end);
    }

    std::sort(arr.begin(), arr.end(), [](const meeting m1, const meeting m2){
        return m1.end < m2.end;
    });

    int curr_end = -1;
    int count = 0;
    for (meeting m : arr){
        if (m.start > curr_end){
            curr_end = m.end;
            count++;
        }
    }

    std::cout << count << std::endl;


    return 0;
}