import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));   
        int k = 1;
        while(cin.hasNext())
        {
            int v = 0;
            ArrayList<String> stringList = new ArrayList<String>();
            while(cin.hasNext())
            {
                //System.out.println("v "+v);
                String temp = cin.next();
                if(temp.compareTo("9")==0)
                    break;
                if(v != 0)
                    continue;
                stringList.add(temp);
                for(int i = 0;i < stringList.size()-1;i++)
                {
                    String str = stringList.get(i);
                    int x = temp.length();
                    int y = str.length();
                    if(x < y && temp.compareTo(str.substring(0, x))==0)
                    {
                        v = 1;
                        break;
                    }
                    else if(y < x && str.compareTo(temp.substring(0, y))==0)
                    {
                        v = 1;
                        break;
                    }
                }
                if(v != 0)
                {
                    System.out.println("Set "+k+" is not immediately decodable");
                    continue;
                }
            }
            if(v == 0)
                System.out.println("Set "+k+" is immediately decodable");
            v = 0;
            k++;
        }
    }
}
