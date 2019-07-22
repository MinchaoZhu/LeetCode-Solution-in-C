int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int min = 0, nowGas = 0, minIndex = 0;
    for(int i = 0; i<gasSize;++i){
        nowGas += gas[i]-cost[i];
        if(nowGas<min){
            minIndex = i+1;
            min = nowGas;
        }
    }
    return nowGas>=0?minIndex:-1;
}


int main(void){
    int gas[5] = {1,2,3,4,5};
    int cost[5] = {3,4,5,1,2};
    int result;
    result = canCompleteCircuit(gas,5,cost,5);


}