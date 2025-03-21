#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int k = N / pow(10, i);
        if (k == 0)
        {
            break;
        }
        ans = i + 1;
    }
    


    return 0;
}