int num1(long long int z)
{
    if(z<=9) //if less than 9, return the number itself
    {
        return z;
    }
    long long int sum=0;
    long long int m=0;

    while(z!=0) //recursive sum
    {
        
        m=z%10; //modulus to get digit in units place
        sum=sum+m;
        z=z/10; //divide by 10


    }
    return num1(sum); //recursively call num1, untill single digit number derived


}

// Complete the superDigit function below.
int superDigit(string n, int k) {
long long int sum=0;
long long int m;
   for(int i=0; i<n.size(); i++){ //iterate through characters of string
        sum += n[i] - '0';
    }

    return num1(sum*k);

}