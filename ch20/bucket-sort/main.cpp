#include "bucket.h"

int main() {
    Bucket arr(10);
    arr.insertValueAt(97, 0);
    arr.insertValueAt(3, 1);
    arr.insertValueAt(45, 2);
    arr.insertValueAt(35, 3);
    arr.insertValueAt(28, 4);
    arr.insertValueAt(40, 5);
    arr.insertValueAt(117, 6);
    arr.insertValueAt(65, 7);
    arr.insertValueAt(71, 8);
    arr.insertValueAt(108, 9);
    arr.printArray();

    arr.bucketSort(3);


    arr.printArray();
    


   
}