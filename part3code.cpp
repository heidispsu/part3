#include <cstdlib>
#include <pthread.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>


using namespace std;
void openFile();
void* quickSort(void* threadid);
void* selectionSort(void *threadid);
void* bubbleSort(void* threadid);
void* mergeSort(void *threadid);
void* insertionSort(void *threadid);
void* shellSort(void *threadid);
void mergeNumbers(int *myArray, int minCount, int maxCount, int midCount);
void mergeSort(int *myArray, int minCount, int maxCount);
void insertionSort(int *myArray, int size);
void print_array(int *myArray, int size);
void bubbleSort(int *myArray, int size);
void shellSort(int *myArray, int size);
void trial1();
void trial2();
int array1[500000];
int array2[500000];
int array3[250000];
int array4[250000];
int array5[250000];
int array6[250000];


void trial1(){
    // Mike is going to be working on this
    // make sure you uncomment the below code to work and also make sure
    /* int t1, t2;
     void *status;
     t1 = pthread_create(&thread1, NULL, quickSort, (void *)i);
     t2 = pthread_create(&thread2, NULL, selectionSort, (void *)i);
     pthread_join(thread1, &status);
     pthread_join(thread2, &status);
     */
}

void trial2(){
    // contains threads to 4 sorts
    int i, t1, t2, t3, t4;
    void *status;
    pthread_t thread1, thread2, thread3, thread4;
    t1 = pthread_create(&thread1, NULL, mergeSort, (void *)i);
    t2 = pthread_create(&thread2, NULL, insertionSort, (void *)i);
    //t3 = pthread_create(&thread3, NULL, bubbleSort, (void *)i);
    //t4 = pthread_create(&thread4, NULL, shellSort, (void *)i);
    pthread_join(thread1, &status);
    pthread_join(thread2, &status);
    pthread_join(thread3, &status);
    pthread_join(thread4, &status);




}


int main(int argc, char *argv[]) {

    openFile();
    int i;
    //trial1();
    trial2();

    for(int i = 0; i < 500000; i++)
    {
        cout << "Array1 position "<< i << ": " << array1[i] << endl;
    }
    for(int i = 0; i < 500000; i++)
    {
        cout << "Array2 position " << i << ": " << array2[i] << endl;
    }
    return 0;
}
void* quickSort(void* threadid){
    long tid = (long) threadid;
    cout << "I am performing the Quick Sort" <<  endl;
    // TODO: Call the original quick sort below this
    //       use array1
    pthread_exit(NULL);


}

void* selectionSort(void *threadid){
    long tid = (long) threadid;
    cout << "I am performing the Selection Sort" <<  endl;
    // TODO: Call the original selection sort below this and also call the exit method
    //       Use Array2
    pthread_exit(NULL);

}
void* insertionSort(void* threadid){
    long tid = (long) threadid;
    cout << "I am performing the Insertion Sort" <<  endl;
    insertionSort(array3, 250000);
    pthread_exit(NULL);
}
void* shellSort(void *threadid){
    long tid = (long) threadid;
    cout << "I am performing the Shell Sort" <<  endl;
    shellSort(array4, 250000);
    pthread_exit(NULL);

}

void* bubbleSort(void* threadid){
    long tid = (long)threadid;
    cout << "I am performing the Bubble Sort" << endl;
    bubbleSort(array5, 250000);
    pthread_exit(NULL);

}
void* mergeSort(void *threadid){
    long tid = (long)threadid;
    cout << "I am performing the Bubble Sort" << endl;
    mergeSort(array6, 0, 249999);
    pthread_exit(NULL);
}

void openFile(){

    ifstream myFile;
    myFile.open("/home/jeswin/Desktop/numbers.txt");
    if(myFile.is_open())
    {
        string character;
        int temp;
        cout << "file has opened" << endl;
        for(int i = 0; i < 1000000; i++)
        {

            getline(myFile, character);
            temp = atoi(character.c_str());


            cout << "I value is "<< i << endl;

            // seperated arrays
            cout << temp << endl;
            if(i < 500000)
                array1[i] = temp;
            if( i < 250000)
                array3[i] = temp;
            if(i >= 250000 && i < 500000)
                array4[i-250000] = temp;
            if(i >= 500000 && i< 750000)
                array5[i -500000] =temp;
            if(i >= 750000 && i < 1000000)
                array6[i-750000] = temp;
            if(i >= 500000)
                array2[i-500000] = temp;




        }



        // while(getline(myFile, character))
        //    cout << character <<  endl;
        cout << "first element" << endl;
        cout << array1[0] << endl;


        cout << "file is about to close";
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
        cout << "Insertion Sort waiting..." << num1 << endl;
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
            cout << "Bubble Sort waiting" << num1 << endl;
        }
    }
}

void shellSort(int *myArray, int size)
{
    int gap, num1, num2, temp;

    for (gap =  size/2; gap > 0; gap /= 2)
    {
        for (num1 = gap; num1 < size; num1++)
        {
            for (num2 = num1 -gap; num2 > 0 && myArray[num2] > myArray[num2 + gap]; num2 -= gap )
            {
                temp = myArray[num2];
                myArray[num2] = myArray[num2 + gap];
                myArray[num2 + gap] = temp;
            }
            cout << "Shell Sort waiting " << num1 << endl;
        }
    }
}
