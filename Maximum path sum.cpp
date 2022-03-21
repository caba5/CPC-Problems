/* Non-full problem */

#include <climits>

/*
struct Node{
    int data,
    Node *left, *right;
}
*/

int maxLeaf(struct Node *n, int &max){
    if (n == NULL) return INT_MIN;
    int pathleft = maxLeaf(n->left, max);
    int pathright = maxLeaf(n->right, max);

    if ((pathleft == INT_MIN) && (pathright == INT_MIN))
        return n->data;

    int pathcurr = n->data;
    pathcurr += pathleft > pathright ? pathleft : pathright;

    if ((pathleft != INT_MIN) && (pathright != INT_MIN)){
        int maxcurr = n->data + pathleft + pathright;
        if (maxcurr > max) max = maxcurr;
    }

    return pathcurr;
}

int solution(Node *root){
    int max = INT_MIN;
    maxLeaf(root, max);
    return max;
}