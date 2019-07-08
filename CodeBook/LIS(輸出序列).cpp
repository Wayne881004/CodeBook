//Longest Increasing Subsequence (LIS)

#include <iostream>
#include <algorithm> 
using namespace std;

int Count; //幾個數字
int seq[5];
int length[5];
int pv[5]; // prev[x] 記錄 s[x] 是接在哪個數字後面

void trace(int i)
{
    if (pv[i] != -1) {
    	trace(pv[i]);
    }
    cout << seq[i] << ' ';
}

void LIS()
{
    for (int i=0; i< Count; i++) length[i] = 1;

    for (int i=0; i< Count; i++) pv[i] = -1;    // -1 代表 s[i] 是開頭數字，沒有接在其他數字後面。
 
    for (int i=0; i< Count; i++)
        for (int j=i+1; j< Count; j++)
            if (seq[i] < seq[j])
                if (length[i] + 1 > length[j])
                {
                    length[j] = length[i] + 1;
                    pv[j] = i;
                }
 
    int n = 0, pos = 0;
    for (int i=0; i< Count; i++){
        if (length[i] > n)
        {
            n = length[i];
            pos = i;
        }
    }
    trace(pos); // 印出一個LIS
}
 


int main(int argc, char const *argv[])
{

	cin >> Count;
	for(int i = 0 ; i <  Count ; i++){
		cin >> seq[i];
	}
	LIS();
	return 0;
}
