
import java.util.regex.*;
class Solution {
    public int myAtoi(String str) {
        String cpy=str.trim();
        String pattern="(-|\+)?d+";
        Pattern r=Pattern.compile(pattern);
        Matcher m=r.matcher(cpy);
        boolean flag=m.lookingAt();
        if(!flag)
            return 0;
        String temp=m.group();
        if(temp.length()<1)
            return 0;
        StringBuilder temp2=new StringBuilder(temp);
        if(temp.charAt(0)=='+'){
            temp2.delete(0,0);
        }
        if(Double.valueOf(temp2.toString())>Double.valueOf(Integer.MAX_VALUE))
            return Integer.MAX_VALUE;
        if(Double.valueOf(temp2.toString())<Double.valueOf(Integer.MIN_VALUE))
            return Integer.MIN_VALUE;
        int res=Integer.valueOf(temp2.toString()).intValue();
        return res;
    }
}