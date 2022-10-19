class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v ; 
        int i = 0 , j = 0 ; 
        while (i<nums1.size() && j<nums2.size()){
            if (nums1[i]<=nums2[j]){
                v.push_back(nums1[i]) ; 
                ++i ; 
            }else{
                v.push_back(nums2[j]);
                ++j ; 
            }
        }
        while(i<nums1.size()){
            v.push_back(nums1[i]) ; 
            ++i ; 
        }
        while(j<nums2.size()){
            v.push_back(nums2[j]) ; 
            ++j ; 
        }
        int mid = v.size()/2 ;
        double x = v[mid] ; 
        if (v.size()%2 == 0){
            return (x+v[mid-1])/2.0 ;             
        }else 
            return x ;
    }
};