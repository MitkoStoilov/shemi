package com.company;
import java.util.*;

public class Main {

    public static Vector<String> parse(String str, String Delimeter)
    {
        Vector<String> parsed = new Vector<String>(10, 10);
        parsed = new Vector<String>(Arrays.asList(str.split(Delimeter, 52)));
        return parsed;
    }

    public static void main(String[] args) {
        DoubleCalc calc = new DoubleCalc();
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        Vector<String> parsed = new Vector<String>(100, 100);
        parsed = parse(s, " ");
        for(int i = 0; i < parsed.size(); i++)
        {
            calc.push(parsed.elementAt(i));
        }
        calc.cout();
    }
}
