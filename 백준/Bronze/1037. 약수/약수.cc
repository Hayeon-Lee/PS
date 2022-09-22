#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int total;
    
    cin >> total;
    int* arr = new int[total];

    for(int i=0; i < total; i++){
        cin >> arr[i];
    }

    sort(arr, arr + total);

    cout << arr[0] * arr[total-1];
}