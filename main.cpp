#include <iostream>
#include <iostream>

#include "point.h"
#include "btree.h"


#include "quicksort.h"



int main()
{
    /*
    BTree<Point> btree;

    btree.insert(Point(1,1));
    btree.insert(Point(2,2));
    btree.insert(Point(3,3));
*/
    BTree<int> btree;
    btree.insert(1);
    btree.insert(2);
    btree.insert(3);
    btree.insert(4);
    btree.insert(5);
    std::cout << std::endl;
    btree.print();

    std::cout << "Balance:" << btree.getBalance() << std::endl;

    /*
    std::vector<int> test{4,2,1,1,1,5,3};

    Quicksort::sort(test);
    for (int i=0; i< test.size(); ++i) {
     std::cout << test[i] << " ";
    }
    std::cout << std::endl;
    */

    return 0;
}
