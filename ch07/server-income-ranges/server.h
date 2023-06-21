const int BASIC = 7;
const int RATE = 3;

class Server
{
private:
    /* data */
    int tip;
    int workedHour;

public:
    Server(int tips, int workedHours) : 
        tip{tips}, workedHour{workedHours} {
            if (tips < 0 || workedHours < 0)
            {
                tips = 0;
                workedHours = 0;
            }
            
        }
        


    int totalPaid(){

        int total = workedHour * RATE + tip + BASIC;

        return total;

    }


};


