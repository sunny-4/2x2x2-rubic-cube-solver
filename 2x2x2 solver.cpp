#include <cstdio>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <tuple>
#include <iostream>
#include <queue>
#include <math.h>
#include <assert.h>
#include <utility>
using namespace std;

struct board {
    int e[7];
};
struct board2 {
    int o[2];
};
struct colb {
    char c[6][4];
};
struct tesl {
    string t[21];
};
int fact(int i)
{
    int p = 1;
    for (int j = 2; j <= i; ++j) {
        p *= j;
    }
    return p;
}

tesl brg(const colb & b){
    tesl arr;
    char col[6]={b.c[0][0],b.c[1][0],b.c[2][0],b.c[3][0],b.c[4][0],b.c[5][0]};
    int res[21][3]={
        {0,3,4},{4,0,3},{3,4,0},
        {0,4,1},{1,0,4},{4,1,0},
        {0,5,3},{3,0,5},{5,3,0},
        {0,1,5},{5,0,1},{1,5,0},
        {2,4,3},{3,2,4},{4,3,2},
        {2,1,4},{4,2,1},{1,4,2},
        {2,5,1},{1,2,5},{5,1,2}};
    for(int i=0;i<21;i++){
        string str;
        for(int j=0;j<3;j++){
            str.push_back(col[res[i][j]]);
        }
        arr.t[i]=str;
        str.clear();
    }    
    return arr;
}
board trans(const colb& b,const tesl& arr){
    board ans;
    string str;
    str.push_back(b.c[0][0]);
    str.push_back(b.c[3][1]);
    str.push_back(b.c[4][2]);
    for (int i=0;i<21;i++){
        if (str==arr.t[i]){
            ans.e[i/3]=(0)*3+(i%3);
        }
    }
    str.clear();
    str.push_back(b.c[0][1]);
    str.push_back(b.c[4][3]);
    str.push_back(b.c[1][0]);
    for (int i=0;i<21;i++){
        if (str==arr.t[i]){
            ans.e[i/3]=(1)*3+(i%3);
        }
    }
    str.clear();
    str.push_back(b.c[0][2]);
    str.push_back(b.c[5][0]);
    str.push_back(b.c[3][3]);
    for (int i=0;i<21;i++){
        if (str==arr.t[i]){
            ans.e[i/3]=(2)*3+(i%3);
        }
    }
    str.clear();
    str.push_back(b.c[0][3]);
    str.push_back(b.c[1][2]);
    str.push_back(b.c[5][1]);
    for (int i=0;i<21;i++){
        if (str==arr.t[i]){
            ans.e[i/3]=(3)*3+(i%3);
        }
    }
    str.clear();
    str.push_back(b.c[2][0]);
    str.push_back(b.c[4][0]);
    str.push_back(b.c[3][0]);
    for (int i=0;i<21;i++){
        if (str==arr.t[i]){
            ans.e[i/3]=(4)*3+(i%3);
        }
    }
    str.clear();
    str.push_back(b.c[2][1]);
    str.push_back(b.c[1][1]);
    str.push_back(b.c[4][1]);
    for (int i=0;i<21;i++){
        if (str==arr.t[i]){
            ans.e[i/3]=(5)*3+(i%3);
        }
    }
    str.clear();
    str.push_back(b.c[2][3]);
    str.push_back(b.c[5][3]);
    str.push_back(b.c[1][3]);
    for (int i=0;i<21;i++){
        if (str==arr.t[i]){
            ans.e[i/3]=(6)*3+(i%3);
        }
    }
    return ans;
}
char clr(const char c){
    if(c=='r'){
        return 'o';
    }
    if(c=='o'){
        return 'r';
    }
    if(c=='w'){
        return 'y';
    }
    if(c=='y'){
        return 'w';
    }
    if(c=='b'){
        return 'g';
    }
    if(c=='g'){
        return 'b';
    }
    return ' ';
}
colb trans1(const colb & b)
{
    colb temp;

    for(int i=0;i<4;i++){
        temp.c[2][i]=b.c[2][2];
    }
    for(int i=0;i<4;i++){
        temp.c[3][i]=b.c[3][2];
    }
    for(int i=0;i<4;i++){
        temp.c[5][i]=b.c[5][2];
    }
    for(int i=0;i<4;i++){
        temp.c[0][i]=clr(b.c[2][2]);
    }
    for(int i=0;i<4;i++){
        temp.c[1][i]=clr(b.c[3][2]);
    }
    for(int i=0;i<4;i++){
        temp.c[4][i]=clr(b.c[5][2]);
    }
    return temp;

}
void print_board(const board& b)
{
    for (int r = 0; r < 7; ++r) {
        printf("%3d", b.e[r]);
    }
    printf("\n");
}

void print_board(const colb& b)
{
    for (int r = 0; r < 6; ++r) {
        for (int c = 0; c < 4; ++c) {
            printf("%c ", b.c[r][c]);
        }
        printf("\n");
    }
}

void read_board(colb& b)
{
    for (int r = 0; r < 6; ++r) {
        for(int cl = 0; cl < 4; ++cl){
            scanf("%s", &b.c[r][cl]);
            if (b.c[r][cl]=='r'){
                b.c[r][cl]='o';
            }else if (b.c[r][cl]=='o'){
                b.c[r][cl]='r';
            }
        }
    }
}

board front(const board& b)
{
    board o = b;
    int arr[21]={3,4,5,9,10,11,0,1,2,6,7,8,12,13,14,15,16,17,18,19,20};
    for (int i=0;i<7;i++){
        o.e[i]=arr[o.e[i]];
    }
    return o;
}

board right(const board& b)
{
    board o = b;
    int arr[21]={0,1,2,17,15,16,6,7,8,4,5,3,12,13,14,19,20,18,11,9,10};
    for (int i=0;i<7;i++){
        o.e[i]=arr[o.e[i]];
    }
    return o;
}

board up(const board& b)
{
    board o = b;
    int arr[21]={14,12,13,1,2,0,6,7,8,9,10,11,16,17,15,5,3,4,18,19,20};
    for (int i=0;i<7;i++){
        o.e[i]=arr[o.e[i]];
    }
    return o;
}

enum move { R=1,U=2,F=3,R2=4,U2=5,F2=6,R1=7,U1=8,F1=9};

int ord(const board& board){
    int val=0;
    int k=6;
    for (int r = 0; r < 7; ++r) {
        int v=board.e[r];
        val+=v*pow(21,k);
        k-=1;
    }
    return val;
}
board2 decode(const board& res){
    board temp;
    board2 temp1;
    int k=0,val=0;
    for (int i=0;i<7;i++){
        temp.e[i]=(res.e[i]/3)+1;
        val+=(res.e[i]%3)*pow(3,k);
        k++;
    }
    int seen[8] = { 0 };
        int a = 0;
        int t = 6;

        for (int r = 0; r < 7; ++r) {
                int v = temp.e[r];
                int o = 0;
                for (int i = 1; i < v; ++i) {
                    if (!seen[i]) { ++o; }
                }
                a += o * fact(t);
                --t;
                seen[v] = 1;
    }
    temp1.o[0]=a;
    temp1.o[1]=val;
    return temp1;
}
board decode(int ord){
    board node;
    int temp=ord;
    
    for (int r = 6; r >=0; r--) {
        node.e[r]=temp%21;
        temp=temp/21;
    }
    return node;
}
#define maxi1 (5050) 
#define maxi2 (2190) 
std::vector<int> solve(const board& src, const board& dest)
{ 
    queue <int> q;
    int visited[maxi1][maxi2];
    int parent[maxi1][maxi2];
    int initial=ord(src);
    int final=ord(dest);
    q.push(ord(src));
    board2 tem1=decode(src);
    visited[tem1.o[0]][tem1.o[1]] = U;
    int temp=0;
    while (!q.empty()) {
        int child = q.front();
        q.pop();
        board u=decode(child);
        if (child==final) {
            std::vector<int> moves;
            while (child!=initial) {
                board2 tem2=decode(decode(child));
                moves.push_back(visited[tem2.o[0]][tem2.o[1]]);
                child=parent[tem2.o[0]][tem2.o[1]];
            }
            std::reverse(moves.begin(), moves.end());
            return moves;
        }

        board a1 = front(u);
        board a2 = front(a1);
        board a3 = front(a2);
        board b1 = right(u);
        board b2 = right(b1);
        board b3 = right(b2);
        board c1 = up(u);
        board c2 = up(c1);
        board c3 = up(c2);

        board2 a1ord = decode(a1);
        board2 a2ord = decode(a2);
        board2 a3ord = decode(a3);
        board2 b1ord = decode(b1);
        board2 b2ord = decode(b2);
        board2 b3ord = decode(b3);
        board2 c1ord = decode(c1);
        board2 c2ord = decode(c2);
        board2 c3ord = decode(c3);

        if (!visited[a1ord.o[0]][a1ord.o[1]]) {
            visited[a1ord.o[0]][a1ord.o[1]] = F;
            parent[a1ord.o[0]][a1ord.o[1]] = child;
            q.push(ord(a1));
        }
        if (!visited[a2ord.o[0]][a2ord.o[1]]) {
            visited[a2ord.o[0]][a2ord.o[1]] = F1;
            parent[a2ord.o[0]][a2ord.o[1]] = child;
            q.push(ord(a2));
        }
        if (!visited[a3ord.o[0]][a3ord.o[1]]) {
            visited[a3ord.o[0]][a3ord.o[1]] = F2;
            parent[a3ord.o[0]][a3ord.o[1]] = child;
            q.push(ord(a3));
        }
        if (!visited[b1ord.o[0]][b1ord.o[1]]) {
            visited[b1ord.o[0]][b1ord.o[1]] = R;
            parent[b1ord.o[0]][b1ord.o[1]] = child;
            q.push(ord(b1));
        }
        if (!visited[b2ord.o[0]][b2ord.o[1]]) {
            visited[b2ord.o[0]][b2ord.o[1]] = R2;
            parent[b2ord.o[0]][b2ord.o[1]] = child;
            q.push(ord(b2));
        }
        if (!visited[b3ord.o[0]][b3ord.o[1]]) {
            visited[b3ord.o[0]][b3ord.o[1]] = R1;
            parent[b3ord.o[0]][b3ord.o[1]] = child;
            q.push(ord(b3));
        }
        if (!visited[c1ord.o[0]][c1ord.o[1]]) {
            visited[c1ord.o[0]][c1ord.o[1]] = U;
            parent[c1ord.o[0]][c1ord.o[1]] = child;
            q.push(ord(c1));
        }
        if (!visited[c2ord.o[0]][c2ord.o[1]]) {
            visited[c2ord.o[0]][c2ord.o[1]] = U2;
            parent[c2ord.o[0]][c2ord.o[1]] = child;
            q.push(ord(c2));
        }
        if (!visited[c3ord.o[0]][c3ord.o[1]]) {
            visited[c3ord.o[0]][c3ord.o[1]] = U1;
            parent[c3ord.o[0]][c3ord.o[1]] = child;
            q.push(ord(c3));
        }
        temp+=1;
    }
    printf("Not possible");
    return std::vector<int>( );
}

void print_moves(const std::vector<int>& moves)
{
    for (auto m: moves) {
        switch (m) {
        case U: printf("U "); break;
        case F: printf("F "); break;
        case R: printf("R "); break;
        case U1: printf("U' "); break;
        case F1: printf("F' "); break;
        case R1: printf("R' "); break;
        case U2: printf("U2 "); break;
        case F2: printf("F2 "); break;
        case R2: printf("R2 "); break;
        }
    }
    printf("\n");
}

int main()
{
    colb src1;
    read_board(src1);
    colb dest1=trans1(src1);
    board src=trans(src1,brg(dest1));
    board dest=trans(dest1,brg(dest1));
    printf("\n");
    printf("Given Input :\n");
    printf("\n");
    print_board(src1);
    printf("\n");
    printf("Destination :\n");
    printf("\n");
    print_board(dest1);
    printf("\n");
    auto moves = solve(src, dest);
    print_moves(moves);
    return 0;
}