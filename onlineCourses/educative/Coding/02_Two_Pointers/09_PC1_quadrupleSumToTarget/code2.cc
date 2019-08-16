// O(n^2 lg n)Solution
// http://www.codeproject.com/Articles/38381/STL-Sort-Comparison-Function
// http://www.cplusplus.com/reference/algorithm/sort/
class Solution {
public:
    struct twoSum
    {
        int i1, i2, data;
        twoSum(int i1, int i2, int data)
        {
            this->i1=i1;
            this->i2=i2;
            this->data=data;
        }
    };
    struct compareTwoSum
    {
        bool operator() (twoSum a, twoSum b)
        {
            if(a.data==b.data)
            {
                if(a.i1==b.i1)return a.i2<b.i2;
                else return a.i1<b.i1;
            }
            else return a.data<b.data;
        }
    } cts;
    // TLE for Large Cases if I give vector<int> v
    int beg(vector<twoSum> &v, int l, int r, int val)
    {
        int m;
        while(l<=r)
        {
            m=(l+r)>>1;
            if(val<=v[m].data)r=m-1;
            else l=m+1;
        }
        return r+1;
    }
    // TLE for Large Cases if I give vector<int> v
    int end(vector<twoSum> &v, int l, int r, int val)
    {
        int m;
        while(l<=r)
        {
            m=(l+r)>>1;
            if(val>=v[m].data)l=m+1;
            else r=m-1;
        }
        return l-1;
    }
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        int n=num.size();
        if(n<4)return result;
        vector<twoSum> v;
        int i, j, lb, ub;
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                v.push_back(twoSum(i,j,num[i]+num[j]));
            }
        }
        sort(v.begin(),v.end(),cts);
        n=v.size();
        for(i=0;i<n;i++)
        {
            lb=beg(v,i+1,n-1,target-v[i].data);
            ub=end(v,i+1,n-1,target-v[i].data);
            for(j=lb;j<=ub;j++)
            {
                if(v[j].i1==v[i].i1)continue;
                if(v[j].i2==v[i].i1)continue;
                if(v[j].i1==v[i].i2)continue;
                if(v[j].i2==v[i].i2)continue;
                vector<int> quad;
                quad.push_back(num[v[i].i1]);
                quad.push_back(num[v[i].i2]);
                quad.push_back(num[v[j].i1]);
                quad.push_back(num[v[j].i2]);
                sort(quad.begin(),quad.end());
                if(find(result.begin(),result.end(),quad)==result.end())result.push_back(quad);
            }
        }
        return result;
    }
};
