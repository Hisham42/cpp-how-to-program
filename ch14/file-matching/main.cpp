#include "Client.h"
#include <fstream>
#include <cstdlib> 


int main() {
    

// create a blankfile master.dat to store data

    fstream masterFile("Masterfile.dat",ios::out | ios::in | ios::binary);

    if (!masterFile)
    {
        cerr << "File could not be opened." << endl;
        exit (EXIT_FAILURE);
    }
    
    Client blankClient; // constructor zeros out each data member

    // output 100 blank records to file
    for (int i{0}; i < 100; ++i) {
        masterFile.write(                                                    
            reinterpret_cast<const char*>(&blankClient), sizeof(Client));
    }


// read data from inputfile


    // open the input fule
    ifstream inputFile("input.txt",ios::in); 

    if (!inputFile)
    {
        cerr << "File could not be opened." << endl;
        exit (EXIT_FAILURE);
    }


    string line, accountName, telefonNum, country, accountNumStr, balanceStr;
    int accountNum;
    double balance;
    Client master;


    // read data from input file and store it in master file
    while (!inputFile.eof())
    {
        getline(inputFile, line);

        istringstream iss(line);

        if (getline(iss, accountNumStr, ',') &&
            getline(iss, accountName, ',') &&
            getline(iss, telefonNum, ',') &&
            getline(iss, country, ',') &&
            getline(iss, balanceStr, ','))
        {
            if (!accountNumStr.empty() && accountNumStr[0] == ' ') {
                accountNumStr.erase(0, 1);
            }
            master.setAccountNumber(stoi(accountNumStr));

            if (!accountName.empty() && accountName[0] == ' ') {
                accountName.erase(0, 1);
            }
            master.setName(accountName);

            if (!telefonNum.empty() && telefonNum[0] == ' ') {
                telefonNum.erase(0, 1);
            }
            master.setPhone(telefonNum);

            if (!country.empty() && country[0] == ' ') {
                country.erase(0, 1);
            }
            master.setCountry(country);

            if (!balanceStr.empty() && balanceStr[0] == ' ') {
                balanceStr.erase(0, 1);
            }
            master.setBalance(stod(balanceStr));
        }
        else
        {
            cerr << "Error parsing line: " << line << endl;
        }


        

    masterFile.seekp(                                         
        (master.getAccountNumber() - 1980) * sizeof(Client));


    // write user-specified information in file                  
    masterFile.write(                                               
        reinterpret_cast<const char*>(&master), sizeof(Client));
    }
    

    // testing masterfile
    

    


    fstream masterNew("MasterfileNew.dat", ios:: out | ios:: in | ios::binary);

    if (!masterNew)
    {
        cerr << "File could not be opened." << endl;
        exit (EXIT_FAILURE);
    }

    for (int i{0}; i < 100; ++i) {
        masterNew.write(                                                    
            reinterpret_cast<const char*>(&blankClient), sizeof(Client));
    }
    
    // copying data to masterfile new
    masterFile.seekg(0, std::ios::beg);
    while (!masterFile.eof())
    {
        masterFile.read(                                                    
            reinterpret_cast<char*>(&master), sizeof(Client));

        masterNew.write(                                                    
            reinterpret_cast<const char*>(&master), sizeof(Client));
    }

    // testing
    


    // read data from transaction
    fstream transaction("transactions.txt", ios::out | ios::in);

    while (!transaction.eof())
    {

        getline(transaction, line);

        istringstream iss(line);

        if (getline(iss, accountNumStr, ',') &&
            getline(iss, balanceStr, ','))
            {
                if (!accountNumStr.empty() && accountNumStr[0] == ' ') 
                {
                    accountNumStr.erase(0, 1);
                }
                if (!balanceStr.empty() && balanceStr[0] == ' ') 
                {
                    balanceStr.erase(0, 1);
                }
            }

        int accNu = stoi(accountNumStr);
        double accBal = stod(balanceStr);

        masterNew.seekg(0, std::ios::beg);
        while (masterNew.read(                                                    
                reinterpret_cast<char*>(&master), sizeof(Client))) {
            
            if (master.getAccountNumber() == accNu)
            {
                master.setBalance(master.getBalance() + accBal);

                // seek backword
                masterNew.seekg(-static_cast<std::streamoff>(sizeof(Client)), std::ios::cur);
                
                // write updated class
                masterNew.write(                                                    
                reinterpret_cast<const char*>(&master), sizeof(Client));

                cout << "Operation Done" << endl;
                cout << masterNew.fail() << endl;
                break;
                
               
            }            
        }
    }

    masterNew.seekg(0, std::ios::beg);
    while (masterNew.read(                                                    
            reinterpret_cast<char*>(&master), sizeof(Client))) {
        
        if (master.getAccountNumber() != 0)
        {
           cout << master << endl;
            
            
        }            
    }

}


































/*

    // 1 >>>>>> create a blank Masterfile

    

   

    

    
 
    outputFile.close();



    ifstream inputfile_master("Masterfile.dat", ios::in | ios::binary);
    if (!inputfile_master)
        {
            cerr << "File could not be opened." << endl;
            exit (EXIT_FAILURE);
        }

    while (inputfile_master.read(
        reinterpret_cast<const char*>(&master), sizeof(Client)));
    {
        cout << master << endl;
    }
    


    ifstream transactionFile("transactions.txt", ios::in | ios::binary);
    if (!transactionFile)
        {
            cerr << "File could not be opened." << endl;
            exit (EXIT_FAILURE);
        }


    // create new masterfile and put blank data in it
    ofstream newOutputFile("masterfilenew.dat", ios::out | ios::binary);
    if (!newOutputFile)
        {
            cerr << "File could not be opened." << endl;
            exit (EXIT_FAILURE);
        }

    for (int i{0}; i < 100; ++i) {
            newOutputFile.write(                                                    
                reinterpret_cast<const char*>(&blankClient), sizeof(Client));
        }

    // read data from masterfile and store it in new master to start processing

    while (inputfile_master.read(reinterpret_cast<char*>(&master), sizeof(Client))) {
            // display record
            if (master.getAccountNumber() != 0) {
                
                newOutputFile.write(reinterpret_cast<char*>(&master), sizeof(Client));
            }

        }

    ifstream newOutputFile2("masterfilenew.dat", ios::out | ios::binary);



    while (newOutputFile2.read(reinterpret_cast<char*>(&master), sizeof(Client))) {
            // display record
            if (master.getAccountNumber() != 0) {
                
                cout << master << endl;
            }

        } 



 

   
}

*/


