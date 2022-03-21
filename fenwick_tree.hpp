#ifndef FENWICK_TREE_H
#define FENWICK_TREE_H

#include <vector>

template<typename T>
class fenwick_tree{
    private:
        std::size_t n;  // n+1 has to be passed to constructor
        std::vector<T> arr;
    
    public:
        fenwick_tree(std::size_t size) : n(size) {
            arr = std::vector<T>(n, 0);
        }

        fenwick_tree(std::vector<T> v) : fenwick_tree(v.size()) {
            for (std::size_t i = 0; i < v.size(); ++i)
                add(i, v[i]);
        }

        void add(std::size_t index, T val){
            index++;    // Matches the indexing [1..n]
            while (index <= n){
                arr[index] += val;
                index += index & -index;
            }
        }

        T sum(std::size_t index){
            T s = 0;
            index++;    // Matches the indexing [1..n]
            while(index > 0){
                s += arr[index];
                index -= index & -index;
            }
            return s;
        }

        void init(){
            arr.clear();
            arr = std::vector<T>(n, 0);
        }
};

#endif