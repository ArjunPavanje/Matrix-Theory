//minCostClimbingStairs returns minimum cost to climb costSize steps (or to cross costSize'th step)
int minCostClimbingStairs(int* cost, int costSize){
    if(costSize==2){
        int a=cost[1];
        int b=cost[0];
        return (a>=b)?b:a;
    }
    else if(costSize>2){
        int cost1[costSize-1];
        for(int i=0;i<costSize-1;i++){
            cost1[i]=cost[i];
        }
        int a = minCostClimbingStairs(cost1,costSize-1)+cost[costSize-1];
        //minCostClimbingStairs(cost1,costSize-1)-->minimum cost to cross costSize-1'th step
        int cost2[costSize-2];
        for(int i=0;i<costSize-2;i++){
            cost2[i]=cost[i];
        }
        int b = minCostClimbingStairs(cost2,costSize-2)+cost[costSize-2];
        //minCostClimbingStairs(cost2,costSize-2)-->minimum cost to cross costSize-2'th step
        return (a>b)?b:a;   
    }
    return 0;
}   
