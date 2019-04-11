class Solution {
    public int lengthOfLongestSubstring(String s) {
        char [] str;
        if(s!=null&&s.length()!=0)
            str = s.toCharArray();
        else return 0;
        int first = 0,cur = 1;
        int maxlenth = 1;
        for(cur = 1;cur < s.length();cur++){
            for(int i = first;i < cur;i++){
                if(str[i] == str[cur])
                {
                    first = i+1;
                    break;
                }
            }
            maxlenth = ((cur - first + 1)>maxlenth)?(cur - first + 1):maxlenth;
        }
        return maxlenth;

    }
}
