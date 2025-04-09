#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    
    stringstream ss(s);
    
    vector<int> words;
    string word;
    
    while(getline(ss, word, ' ')) {
        words.push_back(stoi(word));
    }
    
    sort(words.begin(), words.end());
    string answer;
    answer += to_string(words[0]);
    answer += " ";
    answer += to_string(words[words.size()-1]);
    
    return answer;
}