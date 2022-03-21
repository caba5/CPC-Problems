#ifndef SEGMENT_TREE_PERSISTENT_H
#define SEGMENT_TREE_PERSISTENT_H

#include <vector>

struct Vertex{
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

Vertex* build(std::vector<int> a, int tl, int tr){
    if (tl == tr)
        return new Vertex(a[tl]);
    int tm = (tl + tr) / 2;
    return new Vertex(build(a, tl, tm), build(a, tm+1, tr));
}

// Range query
int get_sum(Vertex *v, int tl, int tr, int l, int r){
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return v->sum;
    int tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, std::min(r, tm))
        + get_sum(v->r, tm+1, r, std::max(l, tm+1), r);
}

// Point update
Vertex* update(Vertex *v, int tl, int tr, int pos, int new_val){
    if (tl == tr)
        return new Vertex(new_val);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos, new_val));
}

/*
    For using this tree you have to create an array of Vertex* roots and, 
    initially, insert the result of the first build. Then, for each time 
    the update function is called, its result has to be pushed back into 
    this array.
*/

#endif