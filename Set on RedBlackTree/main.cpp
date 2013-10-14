#include <iostream>
#include "RedBlackTree.h"
#include <cstdlib>

//using namespace std;
int main()
{

    RedBlackTree tree1, tree2, tree3;

    for(int i=0; i<10; ++i)
        tree1.insertNode(i);
    std::cout<< "tree1\n";
    tree1.show();

    for(int i=5; i<15; ++i)
        tree2.insertNode(i);
    std::cout<< "tree2\n";
    tree2.show();
    std::cout<<"\n\n";

    tree3 = tree1 + tree2;
    tree1.show();
    std::cout<<" + \n";
    tree2.show();
    std::cout<<" = \n";
    tree3.show();
    std::cout<<"\n\n";

    tree3 = tree1 - tree2;
    tree1.show();
    std::cout<<" - \n";
    tree2.show();
    std::cout<<" = \n";
    tree3.show();
    std::cout<<"\n\n";

    tree3 = tree2 - tree1;
    tree2.show();
    std::cout<<" - \n";
    tree1.show();
    std::cout<<" = \n";
    tree3.show();
    std::cout<<"\n\n";

    tree3 = tree1 ^ tree2;
    tree1.show();
    std::cout<<" ^ \n";
    tree2.show();
    std::cout<<" = \n";
    tree3.show();

    return 0;
}
