#include <iostream>
#include <ctime>
#include "MaxHeap.h"

using namespace std;

int main() {
    MaxHeap<int> maxHeap = MaxHeap<int>(100);

    srand(time(NULL));
    for(int i = 0;i < 50;i++)
        maxHeap.insert(rand()%100);
    maxHeap.testPrint();
    return 0;
}
