#include "Queue.h"
#include <random>

static int customerNumber{0};

int getRandomTime() {
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_int_distribution<int> distrib(1, 4); // Define the range [1, 4]

    int randomValue = distrib(gen); // Generate a random integer between 1 and 4
    return randomValue;
}

// 1> customer will arrive >> calculate the service time >> calculate the nextcustomer arrival time
// if service time passed from the customer arrival >> deque the customer
// if arrival time passed from the customer arrival >> enque a new customer and repeat the process

int main() {

    Queue<int> checkOutLine;
    
    int currentTime{0}, nextCustomerArrivalTime{getRandomTime()};
    int maxCurrentCustomers{0};
    int maxWaitTime{0};
    int lastCustomerNumber{0};
    

    for (int i = 0; i < 720; i++)
    {
        if (i > checkOutLine.queueHeadArrivalTime() + checkOutLine.queueHeadServiceTime() && !checkOutLine.isempty())
        {
            checkOutLine.dequeue();
            
            if (checkOutLine.queueHeadCustomerNumber() != 0)
            {
                lastCustomerNumber = checkOutLine.queueHeadCustomerNumber();
            }
            
            

        }

        if (i == currentTime + nextCustomerArrivalTime)
        {

            int randomServiceTime = getRandomTime();
            
            checkOutLine.enqueue(++customerNumber, randomServiceTime, i);
            currentTime = i;
            nextCustomerArrivalTime = getRandomTime();
            if (maxCurrentCustomers < checkOutLine.currentCustomersCount())
            {
                maxCurrentCustomers = checkOutLine.currentCustomersCount();
                maxWaitTime = checkOutLine.maxWaitTime();
            }
            
         
        }

        
           
    }

    checkOutLine.print();
    std::cout << "Last Customer Number = " << lastCustomerNumber << std::endl;
    std::cout << "Max Customers Queue = " << maxCurrentCustomers << std::endl;
    std::cout << "Max Wait Time = " << maxWaitTime << std::endl;

}




