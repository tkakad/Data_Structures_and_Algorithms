#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void display(vector<int> numbers){
    cout << "Numbers: ";
    
    for(int i = 0; i < numbers.size(); i++)
        cout << numbers[i] << " ";

    cout << endl;
}

vector<int> bubble_sort(vector<int> numbers){
    int num_swaps;

    for(int i = 0; i < numbers.size() - 1; i++){
        num_swaps = 0;

        for(int j = 0; j < numbers.size() - 1 - i; j++){
            if(numbers[j] > numbers[j + 1]){
                swap(numbers[j], numbers[j + 1]);
                num_swaps++;
            }
        }
        
        cout << "After Step " << i + 1 << ": ";
        display(numbers);
        cout << endl;

        if(!num_swaps)
            return numbers;
    }

    return numbers;
}

int main(){
    vector<int> numbers = { 4, 5, 1, 7, 9, 2, 6, 8, 3 };

    cout << "Before Bubble-Sort: ";
    display(numbers);
    cout << endl;

    numbers = bubble_sort(numbers);

    cout << "After Bubble-Sort: ";
    display(numbers);
}