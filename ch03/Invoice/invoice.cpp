#include <iostream>
#include "invoice.h"

using namespace std;

void displayItem(Invoice item);

int main(){

    // instantiate Item 01
    Invoice item01{"1982", "big mac", 3, 25};

    Invoice item02{"997", "Coca-Cola", 22, 29};

    //print the invoice

    displayItem(item01);

    cout << "\n next item \n";

    displayItem(item02);


}

void displayItem(Invoice item) {

    cout << "Item Number: " << item.getPartNumber() << "\n";

    cout << "Item Description: " << item.getPartDescription() << "\n";

    cout << "Item Price: " << item.getPrice() << "\n";

    cout << "Item Quantity: " << item.getQuantity() << "\n";

    cout << "VAT: " << item.getVat() << "\n";

    cout << "Discount: " << item.getDiscount() << "\n";

    cout << "Total: " << item.getInvoiceAmount() << "\n";
}