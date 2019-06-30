//DP
//LCS 最長子字串

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define strMAX

using namespace std;

char str1[strMAX];
char str2[strMAX];

scanf("%s", str1);
scanf("%s", str2);

int len1 = strlen(str1);
int len2 = strlen(str2);

int dp[len1+1][len2+2];
//dp包含空字串

memset(dp, 0, sizeof(dp));

for(int i = 1 ; i <= len1 ; i++)
{
    for(int j = 1 ; j < len2 ; j++)
    {
        if(str1[i-1] == str2[j-1])
            dp[i][j] = dp[i-1][j-1] + 1;
        else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
}

int ans = dp[str1][str2];
