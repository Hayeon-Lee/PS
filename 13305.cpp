#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

long long dist[100000];
long long cost[100000];
long long price;
long long now;

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N-1; i++) scanf("%lld", &dist[i]);
	for (int i = 0; i < N; i++) scanf("%lld", &cost[i]);

	price = (cost[0] * dist[0]);
	now = cost[0];

	for (int i = 1; i < N; i++) {
		if (now < cost[i]) price += now * dist[i];
		else {
			price += (cost[i] * dist[i]);
			now = cost[i];
		}
	}

	printf("%lld", price);
}
