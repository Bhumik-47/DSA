class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int st=0,en=n-1;
        int mid;
        while(st<=en){
            mid=st+(en-st)/2;
            if(mid>0 && mid<n-1 && arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])return mid;
            else if(mid<n-1 && arr[mid]<arr[mid+1])st=mid;
            else en=mid;
        }
        return mid;
    }
};