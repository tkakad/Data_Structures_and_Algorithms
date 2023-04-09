#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void display(vector<int> numbers){
    for(int i = 0; i < numbers.size(); i++)
        cout << numbers[i] << " ";

    cout << endl;
}

vector<int> insertion_sort(vector<int> numbers){
    int temp;
    bool inserted;

    for(int i = 1; i < numbers.size(); i++){
        temp = numbers[i];
        inserted = false;

        for(int j = i - 1; j >= 0; j--){
            if(temp < numbers[j]) 
                swap(numbers[j], numbers[j+1]); 
            else{
                numbers[j+1] = temp;
                inserted = true;

                cout << "After Step " << i << ": ";
                display(numbers);
                cout << endl;

                break;
            }
        }

        if(!inserted){
            numbers[0] = temp;

            cout << "After Step " << i << ": ";
            display(numbers);
            cout << endl;
        }
    }

    return numbers;
}

int main(){
    vector<int> numbers = { 3, 5, 4, 8, 10, 2, 6, 1, 4 };

    cout << "Before Insertion-Sort: ";
    display(numbers);
    cout << endl;

    numbers = insertion_sort(numbers);

    cout << "After Insertion-Sort: ";
    display(numbers);
    cout << endl;

    return 0;
}