#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    int N;
    vector<string> arr;
    vector<char> answer;

    scanf("%d", &N);
    getchar();
    
    for(int i=0; i<N; i++) {
        string input_string;
        getline(cin, input_string);
        arr.push_back(input_string);
    }

    for (int i=0; i<arr.size(); i++){
        string s1, s2;
        s1 = arr[i].substr(0, arr[i].find(" "));
        s2 = arr[i].substr(arr[i].find(" ")+1, arr[i].length());

        int index = 0;
        if (s1.find("x")!= string::npos) index = s1.find("x");
        else index = s1.find("X");

        char a = s2[index];
        if (a >= 'a' && a <= 'z') a = (a-'a'+'A');
        answer.push_back(a);
    }

    for (int i=0; i<answer.size(); i++){
        printf("%c", answer[i]);
    }
}
