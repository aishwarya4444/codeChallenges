/*
https://www.hackerrank.com/challenges/string-reduction/problem
https://www.hackerrank.com/challenges/string-reduction/editorial
https://www.geeksforgeeks.org/smallest-length-string-with-repeated-replacement-of-two-distinct-adjacent/
https://www.programmersought.com/article/76015030790/
*/
Problem Name : Min String
Topic : DP
Difficulty : Hard
EXPLANATION
A naive way to do this would be to find all possible replacements, and recurse until we find the minimum string. This would take exponential time.

Lemma: Order of letters does not effect the length or value of minimum string.

Proof By Induction Base case: Take string ‘ab’ and ‘ba’, they both reduce to ‘c’

Inductive Hypothesis: All strings of length <= k reduce to the same string assuming the number of occurrences of each letter in each string is the same.

Inductive Step: Take two strings of length k + 1 having same number of occurrences of each letter. Find a pair of letters that are adjacent in both strings. Here, two cases arise:

We manage to find such a pair of letters. We can then replace these letters with the third letter, thus getting two strings of length k having same occurrences of each letter, which by inductive hypothesis reduces to the same string. i.e. We have ‘abcacb’ and ‘accbba’ and reduce ‘ac’ in both strings, we thus get ‘abcbb’ and ‘bcbba’. We cannot find such a pair. This arises when all letters in the string are the same. In this case, the two strings themselves are the same i.e. ‘ccccccc’ and ‘ccccccc’. Thus by induction we have proven this lemma.

Mathematical Approach We can do better than this using three main principles:

If the string cannot be reduced further, then all letters in the string are the same. The length of minimum string is either <= 2 or equal to the length of original string, or 2 < minimum string length < original string length is never true. If each letter of the string is present an odd amount of times, after one reduction step, they shall all be present an even amount of times. The converse is also true, that is, if each letter of the string is present an even amount of times, they shall be present an odd amount of times after one reduction step. These can be proven as follows:

If any two different letters are present, we can select these and reduce string length further. Proof by contradiction: Assume we have a reduced string of length less than original string. For example 'bbbbbbb'. Then this string must have originated from a string like 'acbbbbbb', 'bbacbbbb' or any other such combination of the same. In this case, we could have selected 'bc' instead of 'ac' and reduced further. From the recursive step above, we increase one letter by one and decrease the other two by one. So if we had a combination as (odd, odd, odd), then it would become (odd + 1, odd – 1, odd – 1) or (even, even, even). The reverse is shown in a similar fashion. Now we can combine the above principles. If the string consists of the same letter repeating, it's minimum reduced string is itself, and length is the length of the string. Now, the other possible options are reduced string being of one character length or two. Now if all characters are present an even number of times, or an odd number of times, the only answer that is possible is 2, because (0, 2, 0) is (even, even, even) while (0, 1, 0) is (even, odd, even) so only 2 preserves this evenness. In any other condition, the answer becomes 1.

Time Complexity : O(N).
#include<bits/stdc++.h>
using namespace std;

int stringReduction(string str)
{
    int n = str.length();

    int count[3] = {0};
    for (int i=0; i<n; ++i)
        count[str[i]-'a']++;

    if (count[0] == n || count[1] == n ||
        count[2] == n)
        return n;

    if ((count[0] % 2) == (count[1] % 2) &&
        (count[1] % 2) == (count[2] % 2))
        return 2;

    return 1;
}



int main()
{
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        cout << stringReduction(str)<<"\n";
    }
    return 0;
}
Approach 2
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
 #define fio ios_base::sync_with_stdio(false)

#define ll long long int

#define s(x) scanf("%lld",&x)
#define s2(x,y) s(x)+s(y)
#define s3(x,y,z) s(x)+s(y)+s(z)

#define p(x) printf("%lld\n",x)
#define p2(x,y) p(x)+p(y)
#define p3(x,y,z) p(x)+p(y)+p(z)
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)

#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define pb push_back

ll inf = 1e18;
ll mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

int canBeConverted[102][102][3];

bool findIfPossible(ll lf, ll rt, char &ch, string &str){
  if(lf>rt or lf>=str.size())return false;
  if(lf==rt)return str[lf]==ch;
  if(canBeConverted[lf][rt][ch-'a']!=-1)return canBeConverted[lf][rt][ch-'a'];

  char ch1,ch2;
    if(ch=='a'){
        ch1='b';
        ch2='c';
    }else if(ch=='b'){
        ch1='a';
        ch2='c';
    }else{
        ch1='a';
        ch2='b';
    }
  bool ans=false;
  for(ll k=lf;k<rt;k++){
    ans=findIfPossible(lf,k,ch1,str) and findIfPossible(k+1,rt,ch2,str);
    if(!ans)ans=findIfPossible(lf,k,ch2,str) and findIfPossible(k+1,rt,ch1,str);
    if(ans)return canBeConverted[lf][rt][ch-'a']=ans;
  }
  return canBeConverted[lf][rt][ch-'a']=false;
}

int main()
{
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ll t=1;
  s(t);
  while(t--){
    string str;
    cin>>str;
    ll n=str.size();

    if(n==1){
      cout<<"1\n";
      continue;
    }

    ll dp[3][102]={0};
    memset(canBeConverted,-1,sizeof(canBeConverted));

    F(i,0,n-1){
      RF(j,i,0){
        for(char ch='a'; ch<='c'; ch++){
          bool isPossible = findIfPossible(j,i,ch,str);
          if(isPossible){
            if(j==0)dp[ch-'a'][i]=1;
            else if(dp[ch-'a'][j-1]!=0){
              if(dp[ch-'a'][i]>0)dp[ch-'a'][i]=min(dp[ch-'a'][i],dp[ch-'a'][j-1]+1);
              else dp[ch-'a'][i]=dp[ch-'a'][j-1]+1;
            }
          }
        }
      }
    }

    for(ll i=0;i<3;i++){
      if(dp[i][n-1]==0)dp[i][n-1]=INT_MAX;
    }
    cout<<min(dp[0][n-1],min(dp[1][n-1],dp[2][n-1]))<<endl;
  }
}