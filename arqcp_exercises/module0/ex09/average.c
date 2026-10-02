int average1(int n1, int n2){
    return (n1 + n2)/2;
}

int average2(int v2[], int n) {

    int total = 0;
    for (int i = 0; i < n; i++){
       total += v2[i]; 
    }
    
    return total / n;
}