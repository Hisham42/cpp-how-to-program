#include <iostream>

void swap(int& a, int&b) {
    int c = a;
    a = b;
    b = c;
}

void quickSort(int (&a)[],int start ,int size) {

    

    if (size - 1 - start > 0)
    {   
        int target = start;
        int leftLimit = start;
        int rightLimit = size - 1;
        bool controller1{true};

        while (true)
        {
            controller1 = false;

            for (int i = rightLimit; i > target; i--)
            {
                if (a[i] < a[target])
                {
                    swap(a[i], a[target]);
                    leftLimit = target + 1;
                    target = i;
                    
                    controller1 = true;
                    
                    break;
                }
               
            }


            for (int j = leftLimit; j < target; j++)
            {
                if (a[j] > a[target] )
                {
                    swap(a[j] , a[target]);

                    rightLimit = target - 1;

                    target = j;

                    controller1 = true;
                    
                    break;
                }
            
                
            }

            if (controller1 == false)
            {
                break;
            }
            
            
            
        }
       
        quickSort(a, start, target);
        quickSort(a, target + 1, size);
        
        
    }
        

    
    
    
}

int main() {

    int a[10] = {37, 2, 6, 4, 89, 8, 10, 12, 68, 45};


    quickSort(a, 0, 10);

    for (size_t i = 0; i < 10; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    

}