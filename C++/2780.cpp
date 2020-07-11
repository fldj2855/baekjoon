#include<iostream>
#define endl '\n';

using namespace std;

int dp[1005][10]={1,1,1,1,1,1,1,1,1,1};
bool D[10][10]={
	{0,0,0,0,0,0,0,1,0,0},	// 0 -> 7
	{0,0,1,0,1,0,0,0,0,0},	// 1 -> 2, 4
	{0,1,0,1,0,1,0,0,0,0},	// 2 -> 1, 3, 5
	{0,0,1,0,0,0,1,0,0,0},	// 3 -> 2,6
	{0,1,0,0,0,1,0,1,0,0},	// 4 -> 1, 5, 7
	{0,0,1,0,1,0,1,0,1,0},	// 5 -> 2, 4, 6, 8
	{0,0,0,1,0,1,0,0,0,1},	// 6 -> 3, 5, 9
	{1,0,0,0,1,0,0,0,1,0},	// 7 -> 0, 4, 8
	{0,0,0,0,0,1,0,1,0,1},	// 8 -> 5, 7, 9
	{0,0,0,0,0,0,1,0,1,0},	// 9 -> 6, 8
};
int sum[1005] = {10};

int main(void)
{
	int s = 0;
	for(int i = 1; i < 1005; ++i)
	{
		s = 0;
		for(int j = 0; j < 10; ++j)
		{
			for(int z = 0; z < 10; ++z)
			{
				if(D[j][z])
					dp[i][j] += dp[i-1][z];
			}
			
			s += dp[i][j] %= 1234567;
		}
		sum[i] = s % 1234567;
	}

	int t;
	cin >> t;
	while(t--)
	{
		int tmp;
		cin >> tmp;
		cout << sum[tmp-1] << endl;
	}

	return 0;
}