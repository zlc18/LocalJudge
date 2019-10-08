#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

const int N = 55;
const int maxn = N*N;
const int maxm = 2*N*N*N;
int r, c;
int n=0, m=0; // #ndoes, #edges

int G[N][N];
int p[maxn]; // 并查集
int o[maxm]; // 权值第i小的边
int w[maxm]; // weights
int u[maxm]; // node u
int v[maxm]; // node v

int cmp(const int i, const int j) { return w[i] < w[j]; }
int find(int x) { return p[x]==x? x : p[x]=find(p[x]); }
int merge(int x, int y) { return p[find(x)]=find(y); }

void kruskal(int& ans, int& cnt) { // O(mlogn)
for(int i=1; i<=m; ++i) o[i] = i;
sort(o+1, o+m+1, cmp); // 边按权值排序
for(int i=1; i<=m; ++i) {
int e = o[i], x = find(u[e]), y = find(v[e]);
if(x != y) {
ans += w[e]; p[x] = y;
cnt++;
}
}
}

inline void addEdge(int x, int y, int w_) {
m++;
u[m] = x, v[m] = y, w[m] = w_;
}


int main() {
char t;
scanf("%d %d", &r, &c);

memset(G, 0, sizeof(G));
for(int i=1; i<maxn; i++) p[i] = i;

for(int i=0; i<r; ++i) {
scanf("\n");
for(int j=0; j<c; ++j) {
scanf("%c", &t);
if(t=='#') {
int & a = G[i][j], & b = G[i+1][j],
& c = G[i][j+1], & d = G[i+1][j+1];
if(!a) a = ++n;
if(!b) b = ++n;
if(!c) c = ++n;
if(!d) d = ++n;
merge(a, b);
merge(a, c);
merge(d, b);
merge(d, a);
}

}
}

// 统计连通分量
int a = 0;
for(int i=1; i<=n; ++i) if(find(i)==i) a++;
printf("%d\n", a);

// 暴力加边
for(int i=0; i<=r; ++i) {
for(int j=0; j<=c; ++j) if(G[i][j]) {
for(int k=j+1; k<=c; ++k) if(G[i][k]) {
int a = G[i][j], b = G[i][k];
if(find(a)!=find(b)) {
addEdge(a, b, k-j);
addEdge(b, a, k-j);
}
}
}
}
for(int j=0; j<=c; ++j) {
for(int i=0; i<=r; ++i) if(G[i][j]) {
for(int k=i+1; k<=r; ++k) if(G[k][j]) {
int a = G[i][j], b = G[k][j];
if(find(a)!=find(b)) {
addEdge(a, b, k-i);
addEdge(b, a, k-i);
}
}
}
}
int cnt=0, sum=0;
kruskal(sum, cnt);
printf("%d %d\n", cnt, sum);
return 0;
}