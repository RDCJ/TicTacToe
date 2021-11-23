#include <iostream>
#include <string.h>
#include <cstdlib>
#define _human 1
#define _computer -1
using namespace std;
const int SIZE = 3;
const int INF = 10000;
extern int status[SIZE][SIZE];
const string line = " ----- ";
const int NUM = 16;
extern int player;
int Check(int chess);
void Result(int chess, int player);
void SwitchPlayer();
int Minimax_Decision(int player);
int Max_Value(int chess, int player, int alpha, int beta);
int Min_Value(int chess, int player, int alpha, int beta);
void Initial();
void Draw();
char Pic(int x);
