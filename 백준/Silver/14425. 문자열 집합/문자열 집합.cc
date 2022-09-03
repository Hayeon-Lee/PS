#include <set>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    int m;
    cin >> n;
    cin >> m;
    set<string> arr1;
    string arr2;
    string u;
    int count = 0;

    for (int a = 0; a < n; a++)
    {
        cin >> u;
        arr1.insert(u);
    }
    for (int a = 0; a < m; a++)
    {
        cin >> arr2;
        if (arr1.find(arr2) != arr1.end())
        {
            count++;
        }
    }
    cout << count;
}