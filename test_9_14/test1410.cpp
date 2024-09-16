#include <iostream>
#include <algorithm>
using namespace std;
bool isPointInsideRect(int x, int y, int xleft, int ytop, int xright, int ybottom) {
    if (xleft > xright) swap(xleft, xright);
    if (ytop < ybottom) swap(ytop, ybottom);
    return (x >= xleft && x <= xright && y >= ybottom && y <= ytop);
}
int cross(int x1, int y1, int x2, int y2) {
    return x1 * y2 - x2 * y1;
}
bool isSegmentIntersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int d1 = cross(x3 - x1, y3 - y1, x2 - x1, y2 - y1);
    int d2 = cross(x4 - x1, y4 - y1, x2 - x1, y2 - y1);
    int d3 = cross(x1 - x3, y1 - y3, x4 - x3, y4 - y3);
    int d4 = cross(x2 - x3, y2 - y3, x4 - x3, y4 - y3);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) {
    }
    if (d1 == 0 && min(x1, x2) <= x3 && x3 <= max(x1, x2) && min(y1, y2) <= y3 && y3 <= max(y1, y2)) return true;
    if (d2 == 0 && min(x1, x2) <= x4 && x4 <= max(x1, x2) && min(y1, y2) <= y4 && y4 <= max(y1, y2)) return true;
    if (d3 == 0 && min(x3, x4) <= x1 && x1 <= max(x3, x4) && min(y3, y4) <= y1 && y1 <= max(y3, y4)) return true;
    if (d4 == 0 && min(x3, x4) <= x2 && x2 <= max(x3, x4) && min(y3, y4) <= y2 && y2 <= max(y3, y4)) return true;

    return false;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int xstart, ystart, xend, yend;
        int xleft, ytop, xright, ybottom;

        cin >> xstart >> ystart >> xend >> yend >> xleft >> ytop >> xright >> ybottom;
        if (isPointInsideRect(xstart, ystart, xleft, ytop, xright, ybottom) ||
            isPointInsideRect(xend, yend, xleft, ytop, xright, ybottom)) {
            cout << "T" << endl;
            continue;
        }
        bool intersects = isSegmentIntersect(xstart, ystart, xend, yend, xleft, ytop, xleft, ybottom) ||
            isSegmentIntersect(xstart, ystart, xend, yend, xright, ytop, xright, ybottom) ||
            isSegmentIntersect(xstart, ystart, xend, yend, xleft, ytop, xright, ytop) ||
            isSegmentIntersect(xstart, ystart, xend, yend, xleft, ybottom, xright, ybottom);

        if (intersects) {
            cout << "T" << endl;
        }
        else {
            cout << "F" << endl;
        }
    }

    return 0;
}
