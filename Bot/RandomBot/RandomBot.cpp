#include "RandomBot.h"

int RandomBot::move(Maze& m){
    srand(time(NULL));
    while(!m.isExit()){
        int tempD = rand()%8;
        if(m.isPath(Direzione(tempD))) m.simpleMove(Direzione(tempD));
    }
    return 1;
}