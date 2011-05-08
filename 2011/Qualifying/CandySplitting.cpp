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
        cout<<"Case #"<<(t+1)<<": ";
        cin>>N;
        int C;
        vector<int> v;
        for(int i=0;i<N;i++)
        {
            cin>>C;
            v.push_back(C);
        }
        sort(v.begin(), v.end());

        long long sum = 0;
        for(int i=0;i<v.size();i++)
        {
            sum ^= v[i];
        }
        if(sum!=0)
        {
           cout<<"NO"<<endl; 
        }
        else
        {
                long long left = v[0];
                long long right = v[1];
                long long l, r;
                l = left;
                r = right;

                for(int i=2;i<v.size();i++)
                {
                    right ^= v[i];
                    r += v[i];
                }
                int i = 1;
                while(left!=right)
                {
                    left ^= v[i];
                    right ^= v[i];
                    l += v[i];
                    r -= v[i];
                    i++;
                }
                if(l>r)
                    swap(l, r);
                cout<<r<<endl;
        }
    }
    return 0;
}
