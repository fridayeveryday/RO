#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;




int main()
{
    //cout << (1 << 2);
    //cout << (((1 << 6) & 10) >> 6);
    //cout << ();
    int n, k;
    cin >> n >> k;
    vector<vector<int> > data(n, vector<int>(k + 1, 0));
    for (size_t i = 0; i < n; i++)
    {
        int field_count = 0;
        cin >> field_count;
        data[i][0] = field_count;
        for (size_t j = 1; j < field_count+1; j++)
        {
            cin >> data[i][j];
            int a = data[i][j];
            a++;
        }
    }
   /* cout << "\n";
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < k; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << "\n";
    }*/
    int ministries = (1 << k) - 1;
    vector<int> numbersOfMinisters(k);
    //vector<bool> coveredMinistries(k, 0);
    int coveredMinistries = 0;
    int countOfBits = 1;
    int totalNumberOfMinisters = k;
    int localNumberOfMinisters = 0;

  // ministers
    for (int mask = 1; mask < (1 << n); mask++) {

        if (mask == (1 << (countOfBits - 1))) {
            countOfBits++;
        }
        localNumberOfMinisters = 0;
        coveredMinistries = 0;
        numbersOfMinisters.resize(0, 0);
        for (size_t j = 0; j < countOfBits; j++)
        {
            int valueOfBit = ((1 << j) & mask) >> j;
            if (valueOfBit) {
                localNumberOfMinisters++;
                // todo
                for (size_t ind = 1; ind < (data[j][0]+1); ind++)
                {
                    coveredMinistries = coveredMinistries | (1 << (data[j][ind]-1));
                }
                numbersOfMinisters.push_back(j);
            }
        }
        if ((ministries == coveredMinistries) && (localNumberOfMinisters < totalNumberOfMinisters)) {
            totalNumberOfMinisters = localNumberOfMinisters;
        }


        /*for (int subMask = mask; subMask; subMask = (subMask - 1) & mask) {
                
        }*/
    }
    cout << totalNumberOfMinisters << "\n";

    for (size_t i = 0; i < totalNumberOfMinisters; i++)
    {
        cout << numbersOfMinisters[i] + 1 << " ";
    }
}   
