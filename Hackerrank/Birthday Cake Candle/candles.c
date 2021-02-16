int birthdayCakeCandles(int candles_count, int* candles) 
{
    int max = candles[0];
    int count = 0;
    for(int i=0; i<candles_count; i++) //Find Tallest Candle
        if(max<candles[i])
            max = candles[i];
    for(int i=0; i<candles_count; i++) //Counting Candle
        if(max==candles[i])
            count++;
    return count;
}
