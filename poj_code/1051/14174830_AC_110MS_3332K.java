import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));   
        int t = cin.nextInt();
        String [] let = {".-","-...","-.-.","-..",".","..-.","--.",
                        "....","..",".---","-.-",".-..","--","-.",
                        "---",".--.","--.-",".-.","...","-","..-",
                        "...-",".--","-..-","-.--","--..",
                        "..--",".-.-","---.","----"};
                        //_,.?
        for(int k = 1;k <= t;k++)
        {
            String str = new String();
            str = cin.next();
            String f = new String();
            int[] num = new int[1000];
            for(int i = 0;i < str.length();i++)
            {
                if(str.charAt(i) >= 'A' && str.charAt(i) <= 'Z')
                {
                    f += let[str.charAt(i)-'A'];
                    num[i] = let[str.charAt(i)-'A'].length();
                }
                else
                {
                    int j=0;
                    switch(str.charAt(i))
                    {
                        case '_':j=26;break;
                        case ',':j=27;break;
                        case '.':j=28;break;
                        case '?':j=29;break;
                    }
                    f += let[j];
                    num[i] = let[j].length();
                }
            }/*
            for(int i = 0;i < 1000;i++)
                if(num[i] != 0)
                    System.out.print(num[i]+" ");*/
            //System.out.println();
            String ans = new String();
            String temp = new String();
            int p = 0;
            for(int i = 1000-1;i >= 0;i--)
                if(num[i] != 0)
                {
                    temp = f.substring(p+0, p+num[i]);
                    //System.out.print("temp"+temp+" "+num[i]+" ");
                    p += num[i];
                    for(int j = 0;j < 40;j++)
                        if(temp.compareTo(let[j]) == 0)
                        {
                            if(j < 26)
                                ans += temp.valueOf((char)('A'+j));
                            else
                            {
                                switch(j)
                                {
                                    case 26:ans += temp.valueOf('_');break;
                                    case 27:ans += temp.valueOf(',');break;
                                    case 28:ans += temp.valueOf('.');break;
                                    case 29:ans += temp.valueOf('?');break;
                                }
                            }
                            break;
                        }
                }
            System.out.println(k+": "+ans);
        }
    }
}
