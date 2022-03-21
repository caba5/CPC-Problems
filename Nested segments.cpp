#include <iostream>
#include <vector>
#include <algorithm>
#include "fenwick_tree.hpp"

struct segment{
    int start, finish, id;

    segment(int s, int f, int i) 
        : start(s)
        , finish(f)
        , id(i) {}
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n; std::cin >> n;
    std::vector<int> all_positions;
    all_positions.reserve(n*2);
    std::vector<segment> segs;
    segs.reserve(n);
    for (int i = 0; i < n; ++i){
        int start, finish;
        std::cin >> start >> finish;
        all_positions.push_back(start);
        all_positions.push_back(finish);
        segs.emplace_back(start, finish, i);
    }

    std::cout << "Sorting positions..." << std::endl;
    std::sort(all_positions.begin(), all_positions.end());
    for (auto x : all_positions)
        std::cout << x << " ";
    std::cout << std::endl;

    // Remap -> coordinate compression
    std::cout << "Remapping segments..." << std::endl;
    for (segment &s : segs){
        std::cout << s.start << ", " << s.finish << " --> ";
        s.start = std::lower_bound(all_positions.begin(), all_positions.end(), s.start) - all_positions.begin();
        s.finish = std::lower_bound(all_positions.begin(), all_positions.end(), s.finish) - all_positions.begin();
        std::cout << s.start << ", " << s.finish << std::endl;
    }

    std::cout << "Sorting segments by starting position..." << std::endl;
    std::sort(segs.begin(), segs.end(), [](segment &s1, segment &s2){
        return s1.start < s2.start;
    });
    for (auto x : segs)
        std::cout << x.start << ", " << x.finish << std::endl;

    fenwick_tree<int> s(n*2);
    for (int i = 0; i < n; ++i)
        s.add(segs[i].finish, 1);

    std::vector<int> res(n);
    for (int i = 0; i < n; ++i){
        res[segs[i].id] = s.sum(segs[i].finish) - 1;
        s.add(segs[i].finish, -1);
    }

    for (int amount : res)
        std::cout << amount << std::endl;

    return 0;
}