#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;

	map< string, int> book_string;
	map<int, string> book_int;
	scanf("%d %d", &N, &M);

	string name;
	for (int i = 1; i <= N; i++) {
		cin >> name;
		book_string.insert({ name, i });
		book_int.insert({ i, name });
	}

	for (int i = 1; i <= M; i++) {
		cin >> name;
		
		if (atoi(name.c_str()) != 0) //숫자면
		{
			cout << book_int.find(atoi(name.c_str()))->second << '\n';

		}

		else { //문자면
			printf("%d\n", (book_string.find(name))->second);
		}
	}
}