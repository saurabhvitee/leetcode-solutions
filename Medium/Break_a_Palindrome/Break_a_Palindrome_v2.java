class Solution {
    public String breakPalindrome(String palindrome) {
        //palindrome = "aca";
        //æ¯åæï¼æ¾å°ç¬¬ä¸ä¸ªä¸æ¯açå­ç¬¦æ¿æ¢ä¹
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
        System.out.println(res);
        if(change == false && len > 1){
            res = palindrome.substring(0, len-1) + "b" ;
        }
        return res;
    }
}