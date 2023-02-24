#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct stu {
    string name;
    int kor, eng, math;
}; typedef struct stu STU;

int N;
STU* students;

bool compare(STU a, STU b) {
    if (a.kor == b.kor && a.eng == b.eng && a.math == b.math) return a.name < b.name;
    else if (a.kor == b.kor && a.eng == b.eng) return a.math > b.math;
    else if (a.kor == b.kor) return a.eng < b.eng;
    else return a.kor > b.kor;
}

void input() {
    scanf("%d", &N);
    students = new STU[N];
    for (int i = 0; i < N; i++) {
        string tmp;
        int a, b, c;
        cin >> tmp;
        scanf("%d %d %d", &a, &b, &c);

        students[i].name = tmp;
        students[i].kor = a;
        students[i].eng = b;
        students[i].math = c;
    }
}

void solution() {
    sort(students, students + N, compare);

    for (int i = 0; i < N; i++) cout << students[i].name << "\n";
}

int main() {
    input();
    solution();
}
