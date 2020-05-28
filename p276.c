//dp

int numWays(int n, int k){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return k;
    }
    else if(n==2){
        return k*k;
    }
    else{
        
         int v1 = k*(k-1), v2 = k;
            for(int i = 2; i<n; ++i){
                int tmp = v1;
                v1 = (k-1) * (v1+v2);
                v2 = tmp;
            }
        return v1+v2;
    }
}