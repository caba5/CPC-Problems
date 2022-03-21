#include <iostream>
#include "fenwick_tree.hpp"

int main(){
    int n, u; std::cin >> n >> u;
    fenwick_tree<int> F(n+1);

    int l, r, val;
    for (int i = 0; i < u; ++i){
        std::cin >> l >> r >> val;
        F.add(l, val);
        F.add(r+1, -1*val);
    }

    int q; std::cin >> q;
    for (int i = 0; i < q; ++i){
        std::cin >> l;
        std::cout << F.sum(l) << std::endl;
    }

    return 0;
}