void array_sort(int *vec, int n){
    int i, j, temp; 
  
    for (i = 0; i < n; i++) {  // Iterate through the elements in the array.
  
        for (j = i + 1; j < n; j++) { // Compare the current element with the elements that come after it.
  
            if (*(vec+ i) > *(vec + j)) {  // If the current element is greater than the next element, swap.
  
                temp = *(vec + i); 
                *(vec + i) = *(vec + j); 
                *(vec + j) = temp; 
            } 
        } 
    } 
}