class Solution {
    public String breakPalindrome(String s) {
		//Check if the length equals 1
        if(s.length()==1) return ""; 
		//Convert string s into an array of chars, because String are immutable in Java
        char[] arr = s.toCharArray();
        int n = arr.length;
        for(int i=0; i<n; i++) {
			//arr[0]==arr[n-1]; arr[1]==arr[n-1-1] -> arr[i]==arr[n-1-i]
            int j = n-1-i; 
			//Make sure we don't change the middle character, because the string is still padlindrome
            if(i!=j) { 
                if(arr[i]!='a') {
					 //Change the first char which is not 'a' into 'a'
                    arr[i]='a';
					//The method change the array into String type
                    return String.valueOf(arr); 
                }                
            }
        }
		//If all chars in array are 'a' -> change the last char into 'b'
        arr[n-1]='b';
        return String.valueOf(arr);
    }
}