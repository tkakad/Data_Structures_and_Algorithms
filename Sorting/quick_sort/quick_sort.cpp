#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &numbers, int a, int b){
    int temp = numbers[a];
    numbers[a] = numbers[b];
    numbers[b] = temp;
}

int partition(vector<int> &numbers, int low, int high){
    int pivot = numbers[low], i = low, j = high;

    do{
        do{
            i++;
        }while(numbers[i] <= pivot);

        do{
            j--;
        }while(numbers[j] > pivot);

        if(i < j)
            swap(numbers, i, j);
    }while(i < j);

    swap(numbers, low, j);
    
    return j;
}

void quick_sort(vector<int> &numbers, int low, int high){
    int i;

    if(low < high){
        i = partition(numbers, low, high);
        quick_sort(numbers, low, i);
        quick_sort(numbers, i+1, high);
    }
}

void display(vector<int> numbers){
    for(int i = 0; i < numbers.size() - 1; i++)
        cout << numbers[i] << " ";
    
    cout << endl;
}

int main(){
    vector<int> numbers = { 11, 13, 7, 12, 16, 9, 24, 5, 10, 3 };

    numbers.push_back(INT32_MAX);

    cout << "Before Quick Sort: ";
    display(numbers);

    quick_sort(numbers, 0, numbers.size() - 1);

    cout << "\nAfter Quick Sort: ";
    display(numbers);

    return 0;
}