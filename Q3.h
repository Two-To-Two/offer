#include <iostream>

using namespace std;

/// 不一定一定是右上角的数字开始，左下角也可以。
/// 关键在于该数字可以既是一个最小，又是一个最大，故可以排除一行及一列。

bool check2D(int *m, int value, int width, int height) {
    if (m == nullptr) return false; /// NOTE check validity!!!

    int x_max = width-1; int y_min = 0;
    for (int y = 0; y < height; y++) {
        if (value == m[y*width + width-1]) return true;
        if (value > m[y*width + width-1]) y_min = y;
        else break;
    }
    for (int x = width-1; x >= 0; x--) {
        if (value == m[x]) return true;
        if (value < m[x]) x_max = x;
        else break;
    }

    if (y_min == height || x_max == width) return false;

    for (int y = y_min; y < height; y++) {
        for (int x = 0; x < x_max; x++) {
            if (m[x+y*width] == value) return true;
        }
    }

    return false;
}