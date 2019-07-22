int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int balance[gasSize];
    for(int i = 0;i<gasSize;++i){
        balance[i] = gas[i]-cost[i];
    }
    int result = 0, nowGas, i = 0;
    for(;i<gasSize;++i){
        nowGas = balance[i];
        if(nowGas<0)continue;
        int j = 1;
        for(;j<gasSize;++j){
            nowGas+=balance[(i+j)%gasSize];
            if(nowGas<0)break;;
        }
        if(j==gasSize&&nowGas>=0){
            return i;
        }
    }
    if(i == gasSize&&nowGas<0)
        result = -1;
    return result;
}


int main(void){
    int gas[5] = {1,2,3,4,5};
    int cost[5] = {3,4,5,1,2};
    int result;
    result = canCompleteCircuit(gas,5,cost,5);


}