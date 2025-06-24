#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int A;
    cin >> A;

    int B;
    cin >> B;

    int C;
    cin >> C;

    string aplusb = to_string(A) + to_string(B);
    int ab = stoi(aplusb);

    printf("%d\n", A + B - C);
    printf("%d", (ab - C));
}