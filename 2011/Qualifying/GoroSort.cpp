#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int T, N;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        cin>>N;
        int a;
        vector<int> v;
        vector<int> sorted;
        for(int i=0;i<N;i++)
        {
            cin>>a;
            v.push_back(a);
            sorted.push_back(a);

        }
        sort(sorted.begin(), sorted.end());
        int result = 0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i] != sorted[i])
            {
                result++;
            }
        }
        cout<<"Case #"<<(t+1)<<": "<<result<<endl;
    }
    return 0;
}
