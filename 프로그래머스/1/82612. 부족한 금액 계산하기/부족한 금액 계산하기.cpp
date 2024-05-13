using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    
    long long now_price = 0;
    for (int i=1; i<=count; i++) {
        now_price += (price * i);
    }
    
    if (now_price <= money) answer = 0;
    else answer = now_price - money;

    return answer;
}