#include <string>

class Invoice
{
private:
    /* part number (str) - part description (str) - quantity (int) - price (int) - VAT (double) - discount (double) */ 
    //constructors

    std::string partNumber;
    std::string partDescription;
    int quantity;
    int price;
    double vat;
    double discount;

public:
    //constructor
    Invoice(std::string inPartNumber, std::string inPartDescription, int inQuantity, int inPrice) 
    : partNumber{inPartNumber}, partDescription{inPartDescription},
     quantity{inQuantity}, price{inPrice}, vat{.002 * price}, discount{0} {
        //control

        if (inQuantity < 0)
        {
            quantity = 0;
        }
        if (inPrice < 0)
        {
            price = 0;
        }
        

     }

    /*set&get for each data member*/

    //setters

    void setPartNumber(std::string itemNumber) {
        partNumber = itemNumber;

    }

    void setPartDescription(std::string itemDescription) {
        partDescription = itemDescription;

    }

    void setQuantity(int itemQuantity) {
        quantity = itemQuantity;

    }

    void setPrice(int itemPrice) {
        price = itemPrice;

    }

    void setVat(int itemVat) {
        vat = itemVat;

    }

    void setDiscount(int itemDiscount) {
        discount = itemDiscount;

    }


    //getters

    std::string getPartNumber() const {
        return partNumber;

    }

    std::string getPartDescription() const {
        return partDescription;

    }

    int getQuantity() {
        return quantity;

    }

    int getPrice() {
        return price;

    }

    double getVat() {
        return vat;

    }

    double getDiscount() {
        return discount;

    }

    //getInvoiceAmount

    double getInvoiceAmount() {
        double invoiceAmount = quantity * price + vat - discount;
        return invoiceAmount;
    }

    
};
