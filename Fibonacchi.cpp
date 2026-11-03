#include<iostream>
using namespace std;

int main()
{
    int n, t1 = 0, t2 = 1, nextTerm = 0;
    int stepCount = 0;

    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci Series: ";
    
    for (int i = 1; i <= n; ++i)
    {
        if(i == 1)
        {
            cout << t1 << ", ";
            continue;
        }
        if(i == 2)
        {
            cout << t2 << ", ";
            continue;
        }

        stepCount++;
        nextTerm = t1 + t2;

        stepCount++;
        t1 = t2;

        stepCount++;
        t2 = nextTerm;
        
        cout << nextTerm << ", ";
    }

    cout<< "\nTotal steps taken: " << stepCount << endl;
    return 0;
}


/*
Formula - 3(n - 2)
Time complexity - O(n)
*/