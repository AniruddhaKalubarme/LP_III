#include <bits/stdc++.h>
using namespace std;

class job{
    public:
    string id;
    int deadline;
    int profit;
};

bool compare(job a, job b)
{
    return (a.profit>b.profit);
}

int main()
{
    int n;
    cout<<"Enter the number of jobs: ";
    cin>>n;
    vector<job> jobs;

    int slots = 0;
    for(int i = 0; i<n; i++)
    {
        job j;
        cout<<"Enter Job ID, Deadline and Profit for Job "<<i+1<<": ";
        cin>>j.id>>j.deadline>>j.profit;
        slots = max(slots, j.deadline);
        jobs.push_back(j);
    }

    sort(jobs.begin(), jobs.end(), compare);

    vector<job> result(slots+1);

    for(auto i : jobs)
    {
        int index = i.deadline;
        while(index>0 && result[index].id != "")
        {
            index--;
        }

        if(index>0)
        {
            result[index] = i;
        }
    }

    for(int i = 1; i<=slots; i++)
    {
        cout<<result[i].id <<" -> "<<result[i].profit<<endl;
    }

    return 0;
}
