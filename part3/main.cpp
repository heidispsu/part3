//
//  main.cpp
//  part3
//
//  Created by Heidi and Jeswin on 6/14/15.
//  Copyright (c) 2015 Heidi . All rights reserved.
//

#include <cstdlib>
#include <pthread.h>
#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;
int array1[499999];
int array2[499999];
void openFile();
void writeFile();
void mergeNumbers(int *myArray, int minCount, int maxCount, int midCount);
void mergeSort(int *myArray, int minCount, int maxCount);
void insertionSort(int *myArray, int size);
void print_array(int *myArray, int size);
void bubbleSort(int *myArray, int size);


int main(int argc, const char * argv[])
{
    
    //test array
    //int array3[5] = {10, 5, 2, 9, 7};
    
    openFile();
    
    cout << "ok" << endl;
    
    mergeSort(array1,0, 499999);
    
    for(int i = 0; i < 500000; i++)
    {
        cout << array1[i] << endl;
    }
    
    return 0;
}

void writeFile()
{
    ofstream writer;
    writer.open("/Users/Heidi/Desktop/Operating Systems Summer 2015/part3/part3/results.txt", ios::out);
    
    if(!writer){
        cout << "Error: File not open." << endl;
    }
    else{
        writer << "example" << endl;
    }
    
    writer.close();
    

}

void openFile()
{
    ifstream myFile;
    myFile.open("/Users/Heidi/Desktop/Operating Systems Summer 2015/part3/part3/numbers.txt");
    cout << myFile.is_open() << endl;
    
    if(myFile.is_open())
    {
        string character;
        int temp;
        cout << "file has opened" << endl;
        
        for(int i = 0; i < 1000000; i++)
        {
            getline(myFile, character);
            temp = atoi(character.c_str());
            
            //separate into two arrays
            if(i <500000)
            {
                array1[i] = temp;
            }
            if(i >=500000)
            {
                array2[i-500000] = temp;
            }
            
        }
        
        cout << array1[499999] <<endl;
        cout << array2[499999] <<endl;
        
        myFile.close();
    }

}

void mergeSort(int *myArray, int minCount, int maxCount)
{
    int midCount;
    if (minCount < maxCount)
    {
        midCount=(minCount+maxCount)/2;
        mergeSort(myArray,minCount,midCount);
        mergeSort(myArray,midCount + 1,maxCount);
        
        mergeNumbers(myArray, minCount, maxCount, midCount);
    }
    return;
}

void mergeNumbers(int *myArray, int minCount, int maxCount, int midCount)
{
    int newArray[500000];
    int arrayNum = minCount;
    int num1 = minCount;
    int num2 = midCount + 1;
   

    while (num1 <= midCount && num2 <= maxCount)
    {
        if (myArray[num1] < myArray[num2])
        {
            newArray[arrayNum] = myArray[num1];
            num1++;
            arrayNum++;
        }
        else
        {
            newArray[arrayNum] = myArray[num2];
            num2++;
            arrayNum++;
        }
    }

    while (num1 <= midCount)
    {
        newArray[arrayNum] = myArray[num1];
        num1++;
        arrayNum++;
    }

    while (num2 <= maxCount)
    {
        newArray[arrayNum] = myArray[num2];
        num2++;
        arrayNum++;
    }

    for (num1 = minCount; num1 < arrayNum; num1++)
    {
        myArray[num1] = newArray[num1];
    }
}

void insertionSort(int *myArray, int size)
{
    int num1, num2;
    int temp;
    
    for(num1 = 1; num1 < size; num1++)
    {
        num2 = num1;
        while(num2 > 0 && myArray[num2-1] > myArray[num2])
        {
            temp = myArray[num2];
            myArray[num2] = myArray[num2-1];
            myArray[num2-1] = temp;
            num2--;
        }
        cout << "waiting..." << num1 << endl;
    }
}

void print_array(int *myArray, int size)
{
    
    cout<< "sorting: ";
    int j;
    for (j=0; j<size;j++)
        for (j=0; j<size;j++)
            cout <<" "<< myArray[j];
    cout << endl;
}

void bubbleSort(int *myArray,int size)
{
    int temp;
    for(int num1 = 0; num1 <= size-1; num1++)
    {
        for(int num2 = 0; num2 < size-1; num2++)
        {
            if(myArray[num2] > myArray[num2+1])
            {
                temp = myArray[num2];
                myArray[num2] = myArray[num2+1];
                myArray[num2+1] = temp;
            }
            cout << "waiting" << num1 << endl;
        }
    }
}

