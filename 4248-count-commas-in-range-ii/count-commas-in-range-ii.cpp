class Solution {
public:
    long long countCommas(long long n) {
        long long st=1000;
        long long en=st*1000-1;
        long long cm = 1;
        long long a=0;
        while(st<=n){
           a+=(min(n,en)-st+1)*cm;
           if(en>n)break;
           st=st*1000;
           en=st*1000-1;
           cm++;
        }
        return a;
    }
};