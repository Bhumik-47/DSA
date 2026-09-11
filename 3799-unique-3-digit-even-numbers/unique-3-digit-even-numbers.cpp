class Solution {
public:
    vector<int>v;
    set<vector<int>>s;
    void fun(vector<int>&digits , int i){

    if(v.size()==3){
        vector<int> arr=v;
        sort(arr.begin(),arr.end());
        do{
          if(arr[2]%2==0&&arr[0]!=0){
            s.insert(arr);
            // for(auto x:arr) {
            //     cout << x << " ";
            // }
            // cout << endl;
          }
            
        }while(next_permutation(arr.begin(),arr.end()));
        return;
    }
        if(i>=digits.size()){
        return;
    }
    v.push_back(digits[i]);
    fun(digits,i+1);

    v.pop_back();
    fun(digits,i+1);
    }

    
    int totalNumbers(vector<int>& digits) {
       fun(digits,0);
       
       
       return s.size();
       
       
    }
};