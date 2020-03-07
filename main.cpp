
#include "head.h"
int main() {
    Field_P l1, l2(4, 3);
    l1 = 6;
    l1 = l2;
    std::cout << l2 << '\n';
    l1[8] = 9;
    std::cout << l1 << '\n';
    l2[8] = 7;
    Field_P l3;//(l2 + l1) ;//= l2 + l1;
    l3 = l2 + l1;
    std::cout << l3 << '\n';
    return 0;
}
