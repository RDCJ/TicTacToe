#include "tic.h"
using namespace std;
int Check(int chess){ //判断棋局是否结束，若平局返回0，若一方获胜返回1，未结束返回2
    int row = chess/SIZE;
    int col = chess%SIZE;
    if(status[row][0] == status[row][1] && status[row][0] == status[row][2]){
        return status[row][col];
    }
    if(status[0][col] == status[1][col] && status[0][col]== status[2][col]){
        return status[row][col];
    }
    if(row == col && status[(row+2)%SIZE][(col+2)%SIZE] == status[row][col] && status[row][col] == status[(row+1)%SIZE][(col+1)%SIZE]){
        return status[row][col];
    }
    if(row+col == SIZE-1 && status[(row+2)%SIZE][(col+1)%SIZE] == status[row][col] && status[row][col] == status[(row+1)%SIZE][(col+2)%SIZE]){
        return status[row][col];
    }
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(status[i][j] == 0){
                return 2;
            }
        }
    }
    return 0;
}

void SwitchPlayer(){//交换下棋者
    player = -player;
}

void Result(int chess, int player){//将棋子下到棋盘上
    status[chess/SIZE][chess%SIZE] = player;
}

int Minimax_Decision(int player)
{ //min-max搜索，player为计算机
    int max = -INF;
    int flag = -1; //最大效用对于的棋盘位置
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            if(status[i][j] == 0)
            {
                status[i][j] = player;//在当前棋局状态下进行扩展（预测）
                int temp = Min_Value(i*SIZE+j, -player, max, INF);
                if(max < temp)
                {
                    max = temp;
                    flag = i*SIZE+j;
                }
                status[i][j] = 0;//计算完成之后，恢复棋局状态
            }
    return flag;
}


int Max_Value(int chess, int player, int alpha, int beta)
{
    int re = Check(chess);//判断棋局

    //如果棋局完结，给出当前棋局状态的价值
    if(re == _computer) return 1;
    if(re == _human) return -1;
    if(re == 0) return 0; //平局

    //to-do 如果棋局尚未完结，扩展当前棋局，递归计算价值
    int max = -INF;
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            if(status[i][j] == 0)
            {
                status[i][j] = player;//在当前棋局状态下进行扩展（预测）
                int temp = Min_Value(i*SIZE+j, -player, alpha, beta);
                status[i][j] = 0;//计算完成之后，恢复棋局状态
                if (max < temp) max = temp;
                if (max > beta) return max;
                if (temp > alpha) alpha = temp;
            }
    return max;
}


int Min_Value(int chess, int player, int alpha, int beta)
{
    int re = Check(chess); //判断棋局

    //如果棋局完结，给出当前棋局状态的价值
    if(re == _computer) return 1; //计算机赢，价值为1
    if(re == _human) return -1; //人类棋手赢，价值为-1
    if(re == 0) return 0; //平局

    //to-do 如果棋局尚未完结，扩展当前棋局，递归计算价值
    int min = INF;
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            if(status[i][j] == 0)
            {
                status[i][j] = player;//在当前棋局状态下进行扩展（预测）
                int temp = Max_Value(i*SIZE+j, -player, alpha, beta);
                status[i][j] = 0;//计算完成之后，恢复棋局状态
                if (min > temp) min = temp;
                if (min < alpha) return min;
                if (temp < beta) beta = temp;
            }

    return min;
}
