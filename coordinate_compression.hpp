#ifndef COORDINATE_COMPRESSION_H
#define COORDINATE_COMPRESSION_H

#include <vector>
#include <algorithm>

template <typename T>
void remap(std::vector<T> &v){
    std::vector<T> tmp(v.size());
    std::copy(v.begin(), v.end(), tmp.begin());
    std::sort(tmp.begin(), tmp.end());
    size_t sz = std::distance(tmp.begin(), std::unique(tmp.begin(), tmp.end()));
    tmp.resize(sz);
    for (T &x : v)
        x = std::distance(tmp.begin(), std::lower_bound(tmp.begin(), tmp.end(), x));
}

#endif