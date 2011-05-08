#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

void p(vector<char> v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        map<pair<char, char>, char> combine;
        int C, D, N;

        cin>>C;
        for(int i=0;i<C;i++)
        {
            string s;
            cin>>s;
            char a, b, c;
            a = s[0];
            b = s[1];
            c = s[2];
            if(b<a)
                swap(a, b);
            combine[make_pair(a, b)] = c;
             
        }
        map<char, vector<char> > oppose;
        for(char i='A';i<='Z';i++)
        {
            oppose[i] = vector<char>();
            oppose[i].clear();
        }
        
        cin>>D;
        for(int i=0;i<D;i++)
        {
            string s;
            cin>>s;
            char a, b;
            a = s[0];
            b = s[1];
            oppose[a].push_back(b);
            oppose[b].push_back(a);
        }

        vector<char> result;
        cin>>N;
        string s;
        cin>>s;
        for(int i=0;i<N;i++)
        {
            char b = s[i];
            char t = s[i];
            
            if(!result.empty())
            {
                char a;
                a = result.back();
                char at = a;
                if(b<a)
                    swap(a, b);
                if(combine.find(make_pair(a, b))!=combine.end())
                {
                    result.pop_back();
                    result.push_back(combine[make_pair(a, b)]);
                }
                else 
                {
                    bool flag = false;
                    for(int l=result.size()-1;l>=0;l--)
                    {
                        if(find(oppose[t].begin(), oppose[t].end(), result[l])!=oppose[t].end())
                        {
                            result.clear();
                            flag = true;
                            break;
                        }

                    }
                    if(!flag)
                    {
                        result.push_back(t);
                    }
                }
            }
            else
            {
                result.push_back(t);
            }
        }
        cout<<"Case #"<<(t+1)<<": [";
        signed int k =0;
        for(;k<(int)result.size()-1;k++)
        {
            cout<<result[k]<<", ";
        }
        for(;k<result.size();k++)
        {
            cout<<result[k];
        }
        cout<<"]"<<endl;
    }

    return 0;
}
