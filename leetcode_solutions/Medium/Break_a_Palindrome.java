class Solution {
    public String breakPalindrome(String palindrome) {
        int len = palindrome.length();
        String res="";
        boolean change=false;
        int i = 0;
        for(;i < len / 2; i++){
            if(palindrome.charAt(i) != 'a'){
                res = palindrome.substring(0, i) + "a" + palindrome.substring(i+1);
                change = true;
                break;
            }
        }
        if(change == false && len > 1){
            res = palindrome.substring(0, len-1) + "b" ;
        }
        String f = "IMPOSS";
        if(res.equals(null)){
            return f;
        }
        else{
            return res;
        }
    }
}