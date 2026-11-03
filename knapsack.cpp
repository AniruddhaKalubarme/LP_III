#include<bits/stdc++.h>
using namespace std;

class object{
    public:
    float weight;
    float profit;
    string id;
    float priority;
};

bool compare(object o1, object o2)
{
    return (o1.priority > o2.priority);
}

int main()
{
    int n;
    float knapsackSize;
    cout<<"Enter number of objects and Bag size: ";
    cin>>n>>knapsackSize;

    vector<object> arr;
    for(int i = 0; i<n; i++)
    {
        object o;
        cout<<"Enter the id, profit and weight for object "<<i+1<<" : ";
        cin>>o.id>>o.profit>>o.weight;
        o.priority = o.profit / o.weight;
        arr.push_back(o);
    }

    sort(arr.begin(), arr.end(), compare);
    float profit = 0;

    for(auto i : arr)
    {
        if(i.weight <= knapsackSize)
        {
            knapsackSize -= i.weight;
            profit+=i.profit;
        }
        else
        {
            profit+=knapsackSize/i.weight * i.profit;
            knapsackSize = 0; 
            break;
        }
    }

    cout<<"Profit is: "<<profit<<endl;

    return 0;
}