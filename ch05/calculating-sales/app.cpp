#include <iostream>

using namespace std;

int main() {

    int product{0};
    double price{0};
    int quantity;
    double totalPrice{0};


    while (product != -1)
    {
        price = 0, quantity = 0, product = 0;

        cout << "Product number: ";
        cin >> product;

        if (product != -1)
        {
        
            cout << "quantity sold: ";
            cin >> quantity;


            switch (product)
            {
            case 1:
                price = 2.98 * quantity;
                break;
            
            case 2:
                price = 4.50 * quantity;
                break;

            case 3:
                price = 9.98 * quantity;
                break;

            case 4:
                price = 4.49 * quantity;
                break;

            case 5:
                price = 6.87 * quantity;
                break;
            
            default:
                break;
            }


            totalPrice += price;
        }
    }
    
    cout << "\nTotal retail value of all products sold: " << totalPrice << endl;
        
}