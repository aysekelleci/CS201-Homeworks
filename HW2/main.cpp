/** Ayşe Kelleci
 * CS201 HW2 Algorithm Analysis
 * 05.12.2021
 */ 

#include <iostream>
using namespace std;
#include <stdlib.h>
#include<time.h>
#include <math.h>
#include <ctime>

//for algorithm1 check all values respectively
bool isSubsetLinear(int arr1[], int arr2[], int m, int n)
{
    bool isSubset = false;
    for( int i = 0; i< n; i++)
    {
        isSubset = false;
        for(int j= 0; j< m; j++ )
        {
            if( arr2[i] == arr1[j])
            {
                isSubset = true;
                break;
            }
        }

        if(!isSubset)
        {
            return false;
        }
    }
    return true;
}

/////////algorithm 2 sort first array and traverse arr2 by using binary search
void SelectionSort( int arr[], int size)
{
    int min; 
    int index;
    int swap;
    for(int i = 0; i < size-1; i++ )
    {
        min = arr[i];
        index = i;
        for( int j = i+1; j < size; j++ )
        {
            if( arr[j] < min)
            {
                min = arr[j];
                index = j;
            }
        }
        swap = arr[i];
        arr[i]= min;
        arr[index] = swap;
    }
}

int binarySearch(int arr[], int low, int high, const int number)
{
    if( low <=  high)
    {
        int mid = (low+ high)/2;
        if((mid == 0 || number > arr[mid - 1]) && (arr[mid] == number) )
        {
            return mid; 
        }
        else if( arr[mid] > number)
        {
            return binarySearch( arr, low, mid-1, number);
        }

        else if( arr[mid] < number)
        {
            return binarySearch( arr, mid+1, high, number);
        }
    }
    return -1;
}

//checks whether it is subset or not
bool isSubsetWithBinarySearch( int arr1[], int arr2[], int m, int n)
{
    SelectionSort( arr1, m);
    bool isSubset = true;
    for( int i = 0; i < n; i++)
    {
        if(binarySearch(arr1, 0,  m-1, arr2[i]) == -1) 
        { 
            return false;
        }
    }
    return true;
}

//////////////////////////////////////////////////////////
//algorithm 3 check values by using frequency table
int* frequencyTable( int arr[], int size)
{
    int max = arr[0];
    for( int i = 1; i< size; i++)
    {
        if( arr[i]> max)
        {
            max = arr[i];
        }
    }

    int* frequencyArr = new int[max+1]();  
    for(int i = 0; i< size; i++)
    {
        frequencyArr[arr[i]] = 1;
    }

    return frequencyArr;
}

bool isSubsetByFT( int arr1[], int arr2[], int m, int n)
{
    bool isSubset = true;
    int* frequencyArr = frequencyTable( arr1, m );
    for( int i = 0; i< n; i++)
    {
        if( arr2[i] <= m && frequencyArr[arr2[i]]  == 0)
            isSubset = false;
            //return false;
    }
    //delete frequencyArr;
    return isSubset;

}

void printArray( const int arr[], const int size)
{
    for(int i = 0; i< size; i++)
    {
        cout << arr[i]<< ", ";
    }
    cout<< endl;
}

int main()
{
    const int size = 1000000; //the size of array1

    const int secondSize = 1000; //the size of second array

    int* arr1 = new int[size];

    int arr2 [ secondSize];

    int arr2Init[secondSize*3]; //these array is used to create array which have unique numbers in arr2

    
    srand(time(0));

    for( int i = 0; i< size; i++)
    {
        arr1[i] = i+1;
        //arr1[i] = 0 + (rand() % static_cast<int>(size*2 - 0 + 1)); //the values of arr1 change from 1 to size*2 [1, size*2]
    }

    //SelectionSort(arr1, size); // first array  is sorted

    for( int i = 0; i< secondSize*3; i++)
    {
        if( i == 0)
            arr2Init[i] = 1;
        if( i % 500 !=0)
        {
            arr2Init[i]= i+1; //initialize all values of arr2Init 
        }
        else 
            arr2Init[i] = 1+ i; 
    }

    //printArray( arr2Init, secondSize*3);

    for( int i = 0; i < secondSize*3; i++)
    {
        //change the place of all values 
        int random = (rand() % static_cast<int>(secondSize*3 + 1));
        if( random <= size )
        {
            int temp = arr2Init[random]; 
            arr2Init[random] = arr2Init[i];
            arr2Init[i] = temp;
        }
    } 

    for( int i = 0; i< secondSize; i++)
    {
        //select first seconsize elements of ramdomly placed arr2Inıt array 
        arr2[i] =  arr2Init[i]; 
    }

    //Algorithm 1
    double duration1;
	clock_t startTime1 = clock();
	// Code block
    for( int i = 0; i< 1000; i++) 
    {
        isSubsetLinear( arr1, arr2, size, secondSize);
    }

	//Compute the number of seconds that passed since the starting time
	duration1 = 1000 * double( clock() - startTime1 ) / CLOCKS_PER_SEC;
    cout << endl;
	cout << "Algorithm1 tooks " << duration1 << " milliseconds." << endl;
    cout << "---------------------------------------------------------"<< endl << endl;

    //Algorithm 2
    double duration2;
	clock_t startTime2 = clock();
	// Code block
    for( int i= 0; i<1000; i++)
    {
        isSubsetWithBinarySearch( arr1, arr2, size, secondSize);
    }
	//Compute the number of seconds that passed since the starting time
	duration2 = 1000 * double( clock() - startTime2 ) / CLOCKS_PER_SEC;
	cout << "Algorithm2 tooks " << duration2 << " milliseconds." << endl;
    cout << "---------------------------------------------------------" << endl << endl; 

    //Algorithm 3
    double duration3;
	clock_t startTime3 = clock();
	// Code block
    for (int i = 0; i < 1000; i++)
    {
        
        isSubsetByFT( arr1, arr2, size, secondSize);
    }
 
	//Compute the number of seconds that passed since the starting time
	duration3 = 1000 * double( clock() - startTime3 ) / CLOCKS_PER_SEC;
	cout << "Algorithm3 tooks " << duration3 << " milliseconds." << endl;
    cout << "---------------------------------------------------------" << endl;
    delete arr1; 

    return 0;
}
