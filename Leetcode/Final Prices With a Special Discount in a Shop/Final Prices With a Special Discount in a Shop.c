
//C program to find Final Prices With a Special Discount in a Shop
int* finalPrices(int* prices, int pricesSize, int* returnSize){
*returnSize = pricesSize;
    //creating and initializing fi
    int *fi = (int *)malloc(sizeof(int) * pricesSize);
    

    for (int i = 0; i < (pricesSize - 1); i++){
        fi[i] = prices[i];
         //checking if j is less that length-1
        for (int j = i + 1; j < pricesSize; j++){
            if(prices[i] >= prices[j]){
                //Calculating the discount
                fi[i] = prices[i] - prices[j];
                break;
            }
        }
    }
    fi[pricesSize - 1] = prices[pricesSize - 1];
      //return answer
    return fi;
}

