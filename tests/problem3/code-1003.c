#include<bits/stdc++.h>
using namespace std;
char m[4][4];
struct node{
    char M[4][4];
    int dis;
    char last;
    node(char m[4][4],int d=0,char c='B'){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                M[i][j]=m[i][j];
            }
        }
        dis=d;
        last=c;
    }
};
string con(char m[4][4]){
    string s="";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            s+=m[i][j];
        }
    }
    return s;
}
bool judge(char m[4][4]){
    for(int i=0;i<4;i++){
        if(m[i][0]==m[i][1]&&m[i][0]==m[i][2]&&m[i][0]==m[i][3])return true;
        if(m[0][i]==m[1][i]&&m[0][i]==m[2][i]&&m[0][i]==m[3][i])return true;
    }
    if(m[0][0]==m[1][1]&&m[0][0]==m[2][2]&&m[0][0]==m[3][3])return true;
    if(m[0][3]==m[1][2]&&m[0][3]==m[2][1]&&m[0][3]==m[3][0])return true;
    return false;
}
map<string,int> vis;
int main(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>m[i][j];
        }
    }
    queue<node> q;
    q.push(node(m,0,'O'));
    vis[con(m)]=1;
    while(!q.empty()){
        node t = q.front();q.pop();
        if(judge(t.M)){cout<<t.dis;return 0;}
        int x[2],y[2];
        int num=-1;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(t.M[i][j]=='O'){
                    x[++num]=i;
                    y[num]=j;
                }
            }
        }
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        for(int i=0;i<2;i++){
            for(int j=0;j<4;j++){
                int nx = x[i]+dx[j];
                int ny = y[i]+dy[j];
                char temp[4][4];
                for(int i=0;i<4;i++){
                    for(int j=0;j<4;j++){
                        temp[i][j]=t.M[i][j];
                    }
                }
                if(nx>=0&&nx<4&&ny>=0&&ny<4&&t.M[nx][ny]!='O'&&t.M[nx][ny]!=t.last){

                    temp[x[i]][y[i]]=temp[nx][ny];
                    temp[nx][ny]='O';
                    string s = con(temp);
                    if(!vis[s]){
                        vis[s]=1;
                        q.push(node(temp,t.dis+1,temp[x[i]][y[i]]));
                        if(judge(temp)){
                            cout<<t.dis+1;
                            return 0;
                        }
                    }
                }
            }
        }
    }

}

