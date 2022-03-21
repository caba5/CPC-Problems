#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <vector>

template <typename T>
class segment_tree{
    private:
        std::vector<T> t;

    public:
        segment_tree(std::size_t sz){
            t.reserve(4*sz);
        }

        /**
         * @param a Original array
         * @param i Index of the current vertex
         * @param tl Left boundary of segment
         * @param tr Right boundary of segment
         * 
         * It should be called with @param i = 1, 
         * @param tl = 0 and @param tr = n - 1
         */
        void build(std::vector<T> a, int i, int tl, int tr){
            if (tl == tr)
                t[i] = a[tl];
            else {
                int tm = (tl + tr) / 2;
                build(a, i*2, tl, tm);
                build(a, i*2+1, tm+1, tr);
                t[i] = t[i*2] + t[i*2+1];   // Adaptable
            }
        }

        /**
         * Can be a generic query modified to return something 
         * different than the sum
         * This is a range query
         * 
         * @param l Left boundary of the query
         * @param r Right boundary of the query
         */
        T sum(int i, int tl, int tr, int l, int r){
            if (l > r)
                return 0;
            if (l == tl && r == tr)
                return t[i];
            int tm = (tl + tr) / 2;
            return sum(i*2, tl, tm, l, std::min(r, tm))
                + sum(i*2+1, tm+1, tr, std::max(l, tm+1), r);   //Adaptable
        }

        /**
         * Can be adapted for different use cases of ST by 
         * changing the operation in the last line (sum as ST for sum).
         * 
         * @param pos Position of the element to update
         * @param new_val New value of the element
         */
        void update(int i, int tl, int tr, int pos, T new_val){
            if (tl == tr)
                t[i] = new_val;
            else{
                int tm = (tl + tr) / 2;
                if (pos <= tm)
                    update(i*2, tl, tm, pos, new_val);
                else
                    update(i*2+1, tm+1, tr, pos, new_val);
                t[i] = t[i*2] + t[i*2+1];   // Adaptable
            }
        }
};

#endif
