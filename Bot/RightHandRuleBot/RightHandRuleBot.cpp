#include "RightHandRuleBot.h"

<<<<<<< HEAD
=======
//I bordi della mappa sono considerati muri.
>>>>>>> a3a6cafc78b95adccb8cb04ee08b6a77c354c149

int RightHandRuleBot::move(Maze& m){
    srand(time(NULL));
    int dire = rand()%8;    
    
    while(!m.isExit()){
        for(int noWall = 0; noWall < 9 && !m.isExit(); noWall++){
            if(!m.isPath(Direzione((dire+1)%8)) && m.isPath(Direzione(dire))){
                m.simpleMove(Direzione(dire));
                noWall = 0;
            }
            if(noWall == 0) dire=(dire+2)%8; 
            //dall'iterazione precedente so che alla mia destra c'è un muro, quindi inizio
            //a cercare partendo dalla prima casella a destra possibilmente libera, cioè "avanti destra"
            else dire=(dire+7)%8;
            //poi ruoto la testa destra a sisistra. dopo aver controllato tutte le 8 caselle 
            //o non ho muri intorno a me, o sono circondato da muri
        }
        
        int pityTimer = 0;
        do{
            dire = rand()%8;    //cerco una via casuale...
            if(pityTimer++ > 999) return 0; //risparmio il bot e resitituisco l'informazione riguardo al suo fallimeno 
        }while(!m.isPath(Direzione(dire)));
        
        while(m.isPath(Direzione(dire)) && !m.isExit()) //...la seguo fino al primo muro
            m.simpleMove(Direzione(dire));
    }
    return 1;
}

