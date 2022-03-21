#ifndef SEGMENT_TREE_LAZY_H
#define SEGMENT_TREE_LAZY_H

#include <vector>

// Done with assignments, no sum / min / other..

template <typename T>
class segment_tree_lazy{
    private:
        std::vector<T> t;
        std::vector<bool> marked;

        void push(int i){
            if (marked[i]){
                t[i*2] = t[i*2+1] = t[i];
                marked[i*2] = marked[i*2+1] = true;
                marked[i] = false;
            }
        }

    public:
        segment_tree_lazy(std::size_t sz){
            t.reserve(4*sz);
            marked.reserve(4*sz);
        }

        void build(std::vector<T> a, int i, int tl, int tr){
            if (tl == tr)
                t[i] = a[tl];
            else {
                int tm = (tl + tr) / 2;
                build(a, i*2, tl, tm);
                build(a, i*2+1, tm+1, tr);
            }
        }

        // Point query
        T get(int i, int tl, int tr, int pos){
            if (tl == tr)
                return t[i];
            push(i);
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                return get(i*2, tl, tm, pos);
            else
                return get(i*2+1, tm+1, tr, pos);
        }

        // Update on a segment
        void update(int i, int tl, int tr, int l, int r, T new_val){
            if (l > r)
                return;
            if (l == tl && r == tr){
                t[i] = new_val; // Adaptable
                marked[i] = true;
            }
            else{
                push(i);
                int tm = (tl + tr) / 2;
                update(i*2, tl, tm, l, std::min(r, tm), new_val);
                update(i*2+1, tm+1, tr, std::max(l, tm+1), r, new_val);
            }
        }
};

#endif