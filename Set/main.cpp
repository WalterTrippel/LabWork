#include <iostream>
#include <cstdlib>

#include "Set.h"
#include "RedBlackTree.h"
//#include "BinaryTree.h"

using namespace std;

int main() {

    RedBlackTree *RBTree1 = new RedBlackTree;
    RedBlackTree *RBTree2 = new RedBlackTree;

    RedBlackTree *RBTree3 = new RedBlackTree;
    RedBlackTree *RBTree4 = new RedBlackTree;
    RedBlackTree *RBTree5 = new RedBlackTree;
    RedBlackTree *RBTree6 = new RedBlackTree;


    Set setOnBRT1Original(RBTree1);
    Set setOnBRT2Original(RBTree2);

    Set setOnBRT1Sum(RBTree3);
    Set setOnBRT2SubstrLeft(RBTree4);
    Set setOnBRT3SubstrRight(RBTree5);
    Set setOnBRT4Cross(RBTree6);

    for(int i=1; i<11; ++i)
        setOnBRT1Original.addElement(i);
    setOnBRT1Original.show();


    for(int i=6; i<16; ++i)
        setOnBRT2Original.addElement(i);
    setOnBRT2Original.show();

    std::cout<<"\nSum:\n";
    setOnBRT1Sum = setOnBRT1Original;
    setOnBRT1Sum + setOnBRT2Original;
    setOnBRT1Sum.show();

    std::cout<<"\nSubstrLeft:\n";
    setOnBRT2SubstrLeft = setOnBRT1Original;
    setOnBRT2SubstrLeft - setOnBRT2Original;
    setOnBRT2SubstrLeft.show();

    std::cout<<"\nSubstrRight:\n";
    setOnBRT3SubstrRight = setOnBRT2Original;
    setOnBRT3SubstrRight - setOnBRT1Original;
    setOnBRT3SubstrRight.show();

    return 0;
}
