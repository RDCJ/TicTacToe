#include <iostream>
#include "tic.h"
using namespace std;

int player = 1;
int status[SIZE][SIZE];
void Initial(){  //初始化状态
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            status[i][j] = 0;
        }
    }
}
char Pic(int x){
    if(x == 0){
        return ' ';
    }else if(x == 1){
        return 'o';
    }else{
        return 'x';
    }
}
void Draw(){   //画出当前状态
    cout << line << endl;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            cout << "|" << Pic(status[i][j]);
        }
        cout << "|" << endl;
        cout << line << endl;
    }
}
int main(){
    Initial();//初始化
    Draw();//画出棋盘
    while(1){
        int chess;
        if(player == 1){ //人类棋手为1
            cout << "Please input:" << endl;
            cin >> chess; //输入下棋位置1-9
            chess--;
            if(status[chess/SIZE][chess%SIZE] == 0){
                Result(chess, player);
            }else{
                cout << "The location is occupied" << endl;
                Draw();
                continue;
            }
        }else{//计算机为-1
            chess = Minimax_Decision(player);//min-max决策,chess表示下棋位置
            Result(chess, player);//在棋盘上落棋子
        }
        Draw();
        int re = Check(chess);
        if(re == 2){
            SwitchPlayer();
            continue;
        }
        if(re == 1){ //human
            cout << "you win!" << endl;
            break;
        }
        if(re == -1) //computer
        {
            cout << "computer win!" << endl;
            break;
        }
        if(re == 0){
            cout << "No space." << endl;
            break;
        }
    }
}
