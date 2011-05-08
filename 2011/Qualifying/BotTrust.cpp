#include <vector>
#include <utility>
#include <iostream>
#include <stdlib.h>
#include <map>

using namespace std;

int main()
{

    int T, N;

    cin>>T;
    for(int t=0;t<T;t++)
    {

        cin>>N;
        string c;
        int s;
        map<string, int> m;
        m["O"] = 1;
        m["B"] = 1;

        map<string, int> stepTime;
        stepTime["O"] = 0;
        stepTime["B"] = 0;

        int total = 0;
        string p;
        cin>>c>>s;
        p=c;
        int st = abs(m[c]-s)+1;
        total += st;
        stepTime[c] += st;
        m[c] = s;
        for(int i=0;i<N-1;i++)
        {
            cin>>c>>s;
            st = abs(m[c]-s)+1;
            m[c] = s;
            if(c==p)
            {
               stepTime[c] += st;
               total += st;
            }
            else
            {
                if(stepTime[p]>=st)
                {
                    total++;
                    stepTime[c]++;

                }
                else
                {
                    total += (st-stepTime[p]);
                    stepTime[c]+=(st-stepTime[p]);
                }
                stepTime[p] = 0;
                p = c;

            }
        }
        cout<<"Case #"<<(t+1)<<": "<<total<<endl;
    }

    return 0;

}
