#include <bits/stdc++.h>

using namespace std;

long long pairWiseProduct(const vector<int>& numbers);
long long pairWiseProductFast(const vector<int>&numbers);

int main()
{
    /*
    while(true)
    {
        int n = rand() % 1000 + 2;
        cout << n << endl;

        vector<int> a;
        for(int i = 0; i < n; ++i)
        {
            a.push_back(rand() % 100000);
        }
        for(int i = 0; i < n; ++i)
        {
            cout << a[i] << ' ';
        }
        cout << endl;

        long long res1 = pairWiseProduct(a);
        long long res2 = pairWiseProductFast(a);

        if(res1 != res2){
            cout << "wrong answer " << res1 << ' ' << res2 << endl;
            break;
        }
        else{
            cout << "ok" << endl;
        }
    }
*/


    int n;
    cin >> n;
    vector<int> numbers(n);

    for(int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    cout << pairWiseProductFast(numbers) << endl;

    return 0;
}


long long pairWiseProduct(const vector<int>& numbers)
{
    long long result = 0;

    int n = numbers.size();

    for(int i = 0; i< n; i++){
        for(int j = i+1; j < n; j++)
        {
            if((long long)numbers[i]*numbers[j] > result){
                result = ((long long)(numbers[i])*numbers[j]);
            }
        }
    }
    return result;
}

long long pairWiseProductFast(const vector<int>&numbers)
{
    int n = numbers.size();

    int max_index1 = -1;
    for(int i = 0; i < n; i++)
    {
        if((max_index1 == -1) || (numbers[i]> numbers[max_index1])){
            max_index1 = i;
        }
    }

    int max_index2 = -1;
    for(int i = 0; i < n; i++)
    {
        if((i != max_index1) && ((max_index2 == -1) || (numbers[i] > numbers[max_index2]))){
            max_index2 = i;
        }
    }

    //cout << max_index1 << ' ' << max_index2 << endl;

    return ((long long)(numbers[max_index1])) * numbers[max_index2];
}

