#include "Person.h"
#include "fstream"


int main() {

    fstream nameageo("nameage.dat", ios::out | ios::binary);

    if (!nameageo)
    {
        cerr << "File cannot be opened" << endl;
    }

    Person blank;
    

    for (size_t i = 0; i < 100; i++)
    {
        blank.setId(i + 1);
        nameageo.write(reinterpret_cast<const char*>(&blank), sizeof(Person));
        
    }
    

    
    ifstream input("input.txt", ios::in);

    // seek to the right position
    nameageo.seekp(-10 * sizeof(Person), ios::end);

    string line, last, first, age, id;
    int ageI, idI;
    int i = 90;

    Person master;

    while (input >> line)
    {

        istringstream iss(line);

        if (getline(iss, last, ',') &&
            getline(iss, first, ',') &&
            getline(iss, age, ',') &&
            getline(iss, id, ','))
            {
                ageI = stoi(age);
                idI = stoi(id);
            
        master.setFirstName(first);
        master.setLastName(last);
        master.setAge(ageI);
        master.setId(idI);

        nameageo.write(reinterpret_cast<const char*>(&master), sizeof(Person));

        cout << i << endl;
        i++;
        }

    }

    nameageo.close();

    nameageo.open("nameage.dat", ios::in | ios::out | ios::binary);

    Person master2;
    
    int k = 91;
    

    while (nameageo.read(reinterpret_cast<char*>(&master2), sizeof(Person)))
    {

        if (master2.getFirstName() =="")
        {
            cout << "No info for user id: " << master2.getId() << endl;
        }
        else
        {
            nameageo.seekp(-1 * sizeof(Person), ios::cur);
            blank.setId(k);
            nameageo.write(reinterpret_cast<char*>(&blank), sizeof(Person));
            nameageo.seekp(-1 * sizeof(Person), ios::cur);
            nameageo.read(reinterpret_cast<char*>(&master2), sizeof(Person));
            cout << master2.getId() << endl;
            cout << master2.getFirstName() << endl;
            cout << master2.getLastName() << endl;
            cout << master2.getAge() << endl;
            cout << "===================" << endl;
            k++;
        }
        
        
    }


    

    nameageo.close();
    input.close();
    

    



    
    
    
 

}