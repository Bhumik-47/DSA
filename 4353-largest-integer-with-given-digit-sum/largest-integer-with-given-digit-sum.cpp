class Solution {
public:
    bool check(int num, int s){
        int dig=0,sum=0,co=num;
        while(num>0){
            int r=num%10;
            sum+=r;
            dig++;
            num/=10;
        }
        if(dig<=co && sum==s)return true;
        return false;
    }
    int largestInteger(int n, int s) {
        int maxi=-1;
        int numb=0;
        if(n==0 || s==0)return 0;
        else if(n==1)numb=9;
        else if(n==2)numb=99;
        else if(n==3)numb=999;
        else if(n==4)numb=9999;
        else if(n==5)numb=99999;
        for(int i=0;i<=numb;i++){
            if(check(i,s))
            maxi=max(maxi,i);
        }
        return maxi;
    }
};