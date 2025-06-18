#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    unordered_map<string, int> genre_total;
    unordered_map<string, vector<pair<int, int>>> genre_songs;
    
    for (int i=0; i<genres.size(); i++) {
        genre_total[genres[i]] += plays[i];
        genre_songs[genres[i]].push_back({plays[i], i});
    }
    
    vector<pair<int, string>> genre_order;
    for (auto it: genre_total) {
        genre_order.push_back({it.second, it.first});
    }
    sort(genre_order.rbegin(), genre_order.rend());
    
    vector<int> answer;
    
    for (auto g: genre_order) {
        string genre = g.second;
        auto &songs = genre_songs[genre];
        
        sort(songs.begin(), songs.end(), [](pair<int, int>a, pair<int, int>b){
            if (a.first != b.first) return a.first > b.first;
            else return a.second < b.second;
        });
        for (int i=0; i<songs.size() && i < 2; i++) {
            answer.push_back(songs[i].second);
        }
    }
    
    return answer;
}