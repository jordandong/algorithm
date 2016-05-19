/*
Implement an iterator to flatten a 2d vector.
For example,
Given 2d vector =
[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 2, 3, 4, 5, 6].
*/

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) : vec(vec2d) {
        x = vec.begin();
        if (x != vec.end()) {
            y = x->begin();
            adjustNextIter();
        }
    }

    int next() {
        const auto ret = *y;
        ++y;
        adjustNextIter();
        return ret;
    }

    bool hasNext() {
        return x != vec.end() && y != x->end();
    }
    
    void adjustNextIter() {
        while (x != vec.end() && y == x->end()) { 
            ++x;
            if (x != vec.end()) {
                y = x->begin();
            }
        }
    }

private:
    vector<vector<int>>& vec;
    vector<vector<int>>::iterator x;
    vector<int>::iterator y;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
