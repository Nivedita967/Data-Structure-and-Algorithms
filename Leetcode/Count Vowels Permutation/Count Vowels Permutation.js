var countVowelPermutation = function(n) {
  if(n == 1) return 5;
  if(n == 2) return 10;
  
  let res = [3,2,2,1,2]; // start with 2nd result array, since it's already given in problem statement
  let mod = 1e9 + 7;
  for(let i=3;i<=n;i++){ 
    res = [
      (res[1]+res[2]+res[4]) % mod, //a
      (res[0]+res[2]) % mod, //e
      (res[1]+res[3]) % mod, //i
      (res[2]) % mod, //o
      (res[2]+res[3]) % mod //u
    ];
  }
  
  return (res[0] + res[1] + res[2] + res[3] + res[4]) % mod;
};
