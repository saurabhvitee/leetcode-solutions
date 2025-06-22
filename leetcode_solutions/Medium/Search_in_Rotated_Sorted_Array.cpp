class Solution {
public:
    int search1(vector<int> &arr, int l, int h, int key) {

    if (l > h)  
        return -1; 

    int mid = (l+h)/2; 
    if (arr[mid] == key) 
        return mid; 

    // If arr[l...mid] is sorted 
    if (arr[l] <= arr[mid]) { 

        if (key >= arr[l] && key <= arr[mid]) 
            return search1(arr, l, mid-1, key); 

        return search1(arr, mid+1, h, key); 
    } 

    if (key >= arr[mid] && key <= arr[h]) 
        return search1(arr, mid+1, h, key); 

    return search1(arr, l, mid-1, key); 
}
    int search(vector<int>& arr, int target) {
        int l=0;
        int h = arr.size()-1;
        return search1(arr,l,h,target);
    }
};