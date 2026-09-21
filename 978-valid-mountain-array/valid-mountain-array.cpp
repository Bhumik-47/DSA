class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        int i=1;
        bool in=0,d=0;
        while(i<n-1){
        if(arr[i]==arr[i-1]) return false;
        if(arr[i]>arr[i-1] && d==0 && i<n-1){
            in=1;
        
        
             if(arr[i]>arr[i+1] && in==1 && i<n-1){
                d=1;
                i++;
            }
            else i++;
        }
            
             else if(arr[i]>arr[i+1] && in==1 && i<n-1){
                d=1;
                i++;
            }
        
            else{
                return false;
            }
            
        }
        return in==1 && d==1;
    }
};