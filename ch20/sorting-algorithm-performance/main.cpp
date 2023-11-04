#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <chrono>
#include <array>
void swap(int& a, int&b) {
    int c = a;
    a = b;
    b = c;
}

void quickSort(int* a,int start ,int size) {

    

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


void insertionSort(int* items, int size) {                           
   // loop over the elements of the array                               
   for (size_t next{1}; next < size; ++next) {                
      int insert{items[next]}; // save value of next item to insert    
      size_t moveIndex{next}; // initialize location to place element  

      // search for the location in which to put the current element    
      while ((moveIndex > 0) && (items[moveIndex - 1] > insert)) {
         // shift element one slot to the right                         
         items[moveIndex] = items[moveIndex - 1];                   
         --moveIndex;                                                   
      }                                                 

      items[moveIndex] = insert; // place insert item back into array 
   }                                                      
}        

void selectionSort(int* items, int size) {                            
   // loop over size - 1 elements                                      
   for (size_t i{0}; i < size- 1; ++i) {                      
      size_t indexOfSmallest{i}; // will hold index of smallest element

      // loop to find index of smallest element                        
      for (size_t index{i + 1}; index < size; ++index) {       
         if (items[index] < items[indexOfSmallest]) {                  
            indexOfSmallest = index;                                   
         }                                                             
      }                                                                

      // swap the elements at positions i and indexOfSmallest          
      int hold{items[i]};                                                
      items[i] = items[indexOfSmallest];                               
      items[indexOfSmallest] = hold;                                   
   }                                                                   
}   

void merge(int* items, size_t left, size_t middle1, size_t middle2, size_t right) {

   size_t leftIndex{left}; // index into left subarray              
   size_t rightIndex{middle2}; // index into right subarray         
   size_t combinedIndex{left}; // index into temporary working array
   
   int* combined = new int[right + 1]; // working array                
           
                       

   // merge arrays until reaching end of either
   while (leftIndex <= middle1 && rightIndex <= right) {  
      // place smaller of two current elements into result
      // and move to next space in array                  
      if (items[leftIndex] <= items[rightIndex]) {        
         combined[combinedIndex++] = items[leftIndex++];  
      }                                                   
      else {                                              
         combined[combinedIndex++] = items[rightIndex++]; 
      }                                                   
   }                                                      

   if (leftIndex == middle2) { // if at end of left array         
      while (rightIndex <= right) { // copy in rest of right array
         combined[combinedIndex++] = items[rightIndex++];         
      }                                                           
   }                                                              
   else { // at end of right array                                  
      while (leftIndex <= middle1) { // copy in rest of left array
         combined[combinedIndex++] = items[leftIndex++];          
      }                                                           
   }                                                              

   // copy values back into original array
   for (size_t i = left; i <= right; ++i) {
      items[i] = combined[i];          
   }                                       

    delete[] combined;
} 

void mergeSort(int* items, size_t low, size_t high) {
   // test base case; size of array equals 1
   if ((high - low) >= 1) { // if not base case
      size_t middle1{(low + high) / 2}; // calculate middle of array
      size_t middle2{middle1 + 1}; // calculate next element over   
                                     

      // split array in half; sort each half (recursive calls)
      mergeSort(items, low, middle1); // first half of array  
      mergeSort(items, middle2, high); // second half of array

      // merge two sorted arrays after split calls return
      merge(items, low, middle1, middle2, high);
   } 
} 


int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " argument1 argument2 ..." << std::endl;
        return 1;
    }

    int numbersGenerated = std::stoi(argv[1]);

    //int numbersGenerated = 12;

    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_int_distribution<int> distrib(1, numbersGenerated); // Define the range [1, 4]


    std::fstream file;

    file.open("numbers.txt", std::ios::out);

    if (!file)
    {
        std::cerr << "Error openning file!" << std::endl;
        return 1;
    }
    
    int x{0};
    for (int i = 0; i < numbersGenerated; i++)
    {
        x = distrib(gen);
        file << x << "\n";
    }

    file.close();

    file.open("numbers.txt", std::ios::in);

    std::string a{""};
    int s{0}, i{0};
    int* tempArray = new int[numbersGenerated];

    for (size_t i = 0; i < numbersGenerated; i++)
    {
        tempArray[i] = 0;
    }
    
  
    while (!file.eof())
    {
        std::getline(file, a);
        if (a != "")
        {
            s = stoi(a);
            tempArray[i] = s;
            i++;
        }
    }

    int* tempArray2 = new int[numbersGenerated];

    for (size_t i = 0; i < numbersGenerated; i++)
    {
        tempArray2[i] = tempArray[i];
    }

    int* tempArray3 = new int[numbersGenerated];

    for (size_t i = 0; i < numbersGenerated; i++)
    {
        tempArray3[i] = tempArray[i];
    }

    int* tempArray4 = new int[numbersGenerated];

    for (size_t i = 0; i < numbersGenerated; i++)
    {
        tempArray4[i] = tempArray[i];
    }


    auto start = std::chrono::high_resolution_clock::now();
    // Perform your specific operation here

    insertionSort(tempArray, numbersGenerated);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "insertionSort: " << duration.count() << " microseconds" << std::endl;


    start = std::chrono::high_resolution_clock::now();
    // Perform your specific operation here

    selectionSort(tempArray2, numbersGenerated);

    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "selectionSort: " << duration.count() << " microseconds" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    // Perform your specific operation here

    mergeSort(tempArray3,0 ,numbersGenerated);

    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "mergeSort: " << duration.count() << " microseconds" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    // Perform your specific operation here

    quickSort(tempArray4,0 ,numbersGenerated);

    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "quickSort: " << duration.count() << " microseconds" << std::endl;
    
    delete[] tempArray;
    delete[] tempArray2;
    delete[] tempArray3;
    delete[] tempArray4;
    file.close();
}