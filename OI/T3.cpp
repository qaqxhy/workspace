#include<bits/stdc++.h>
using namespace std;
int n;
int a[101];
int k;
int recipe[101][101];
int result=0;

bool check_recipts(int metal){
    bool tag = true;
    if(a[metal]>0){
        a[metal]--;
    }
    else{
        if(recipe[metal][0]==0){
            tag = false;
        }
        for(int ii=1;ii<=recipe[metal][0];ii++){
            if(check_recipts(recipe[metal][ii])==false){
                tag = false;
                break;
            }
        }
    }
    return tag;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        // cout<<a[i];
    }
    cin>>k;
    // cout<<k;
    for(int i=1;i<=k;i++)
    {
        int tmp;
        cin>>tmp;
        cin>>recipe[tmp][0];
        for(int j=1;j<=recipe[tmp][0];j++)
        {
            cin>>recipe[tmp][j];
        }
    }

/*     cout<<n<<endl;
     for(int i=1;i<=n;i++)
     {
         // cin>>a[i];
         cout<<a[i]<<" ";
     }
     cout << endl;
     for(int i=1;i<=n;i++)
     {
         cout<<recipe[i][0]<<" ";
         for(int j=1;j<=n;j++)
         {
             cout<<recipe[i][j]<<" ";
         }
        cout<<endl;
     }*/

    while(check_recipts(n)){
        result++;
    }
    cout<<result<<endl;


}