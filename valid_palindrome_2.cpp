/*
Two-Pointer Method with Skip Check 
Use two pointers, left and right, starting at the beginning and end of the string.
If characters at left and right match, move inward.
If a mismatch occurs, check two cases:
Skip the left character and check if the remaining string is a palindrome.
Skip the right character and check if the remaining string is a palindrome.
If either case returns true, the string is a valid palindrome after removing one character.
If both fail, return false.
*/
class Solution {
public:

    bool isPalindrome(string s)
    {
        int start = 0;
        int end = s.length()-1;
        while(start<end)
        {
            if(s[start] != s[end])
            return false;
            start++;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) 
    {
        /*
        Find the first mismatch between the characters in s 
        lets say we have string 
        abfdrfba
        01234567

        in the above string the first mismatch occurs at index start=3 and end = 4
        -> option-1: delete element at index start=3 and find if the remaining string is palindrome
        -> option-2 : delete element at index end=4 and find if the remaining string is palindrome
        */
        int n = s.length();
        int start = 0;
        int end = n-1;
        string s1,s2;
        while(start<end)
        {
            if(s[start] != s[end])
            {
                // we can either remove s[start] from the string or s[end] from the string
                s1 = s.substr(0,start) + s.substr(start+1,n); //not taking character at start index
                s2 = s.substr(0,end) + s.substr(end+1,n); // not taking character at end index
                return isPalindrome(s1) or isPalindrome(s2);
            }
            start++;
            end--;
        }
        return true;
    }
};
