#include<iostream>
#include<cstring>
using namespace std;
int arr[15][15],num[15],sum[15],ans=1001;
int x,y;
int pd(){
 for(int i=1;i<y;i++){
  if(sum[i]!=sum[i+1]||!sum[i]){
   return 0;
  }
 }
 return 1;
}
void dfs(int n){
 for(int i=0;i<=num[n];i++){
  for(int j=1;j<=y;j++){
   sum[j]+=arr[n][j]*i;
  }
  if(n<x){
   dfs(n+1);
  }else{
   if(pd()&&ans>sum[1]*y){
    ans=sum[1]*y;
   }
  }
  for(int j=1;j<=y;j++){
   sum[j]-=arr[n][j]*i;
  }
 }
}
int main()
{
 memset(sum,0,sizeof(sum));
 cin>>x>>y;
 for(int i=1;i<=x;i++){
  for(int j=1;j<=y;j++){
   cin>>arr[i][j];
  }
 }
 for(int i=1;i<=x;i++){
  cin>>num[i];
 }
 dfs(1);
 if(ans<=1000){
  cout<<ans;
 }else{
  cout<<"alternative!";
 }
 return 0;
 }

