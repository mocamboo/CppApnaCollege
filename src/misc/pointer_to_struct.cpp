#include <bits/stdc++.h>
using namespace std;
struct Rectangle {
    int length;
    int breadth;
};

int main() {

    Rectangle* p;

    // /*************_____Stack________************/
    // Rectangle r={10,5};
    // p=&r;
    // /**************************************************************/

    /****************____Heap__________************/
    p = new Rectangle;
    p->breadth = 13;
    p->length = 12;
    /*********************************************************/
    cout << "Length is " << p->length << " and Breadth is " << p->breadth << endl;
}