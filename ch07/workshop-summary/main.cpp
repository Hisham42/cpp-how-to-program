#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

void processData(int personNumber, int productNumber, int itemsQuantity);
void output();
int totalRow(int row);
int totalColumn(int column);
int arrayTotal();

const int PEOPLE = 3;
const int PRODUCTS = 4;
int SLIP[PEOPLE][PRODUCTS];

int main(){

//receiveData();
    int personNumber{0}, productNumber{0}, itemsQuantity{0};

    while (true)
    {
        //Validating input
        cout << "Please insert your slip or -1 to quit: \n"
            << "Person Number: ";
            cin >> personNumber;
        if (personNumber == -1)
        {
            break;
        }

        cout << "Product Number: ";
            cin >> productNumber;
        cout << "Item Quantity: ";
            cin >> itemsQuantity;

        
        if (personNumber > 3 || productNumber > 4 || itemsQuantity < 0 || productNumber < 0 || personNumber < 0)
        {
            cout << "\ninvalid input, try again\n" << endl;
            continue;
        }
        //End of validation

        //process();
        else
        {
            processData(personNumber, productNumber, itemsQuantity);
        }
         
    }

    output();


}

void processData(int personNumber, int productNumber, int itemsQuantity) {
    SLIP[personNumber - 1][productNumber - 1] += itemsQuantity;
}

void output() {
    cout << "\n" << setw(13) << left << "People"
    << setw(3) << " "
    << setw(13) << "Product 1"
    << setw(3) << " "
    << setw(13) << "Product 2" 
    << setw(3) << " "
    << setw(13) << "Product 3" 
    << setw(3) << " "
    << setw(13) << "Product 4" 
    << setw(3) << " "
    << setw(13) << "Total" << endl;

    for (size_t i = 0; i < PEOPLE; i++)
    {
        cout << setw(13) << left << i + 1;

        for (size_t j = 0; j < PRODUCTS; j++)
        {
            cout << setw(3) << " " 
            << setw(13) << left << SLIP[i][j];
        }

        cout << setw(3) << " " 
        << setw(13) << left << totalRow(i);
        cout << endl;

    }

    
    cout << setw(13) << left << "Total";

    for (size_t j = 0; j < PRODUCTS; j++)
    {
        cout << setw(3) << " " 
        << setw(13) << left << totalColumn(j);
    }
    
    cout << setw(3) << " " 
    << setw(13) << left << arrayTotal();
    cout << endl;
        
    
     
}

int totalRow(int row){
    int total{0};

    for (size_t j = 0; j < PRODUCTS; j++)
        {
            total += SLIP[row][j];
        }

    return total;
          
}

int totalColumn(int column){
    int total{0};

    for (size_t j = 0; j < PEOPLE; j++)
        {
            total += SLIP[j][column];
        }

    return total;
          
}

int arrayTotal(){
    int total{0};
    for (size_t i = 0; i < PEOPLE; i++)
    {
        for (size_t j = 0; j < PRODUCTS; j++)
        {
            total += SLIP[i][j];
        }
        
    }

    return total;
    
}
