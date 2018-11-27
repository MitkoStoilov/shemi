package com.company;
import java.util.*;

public class Calculator {
    public Deque<Double> stack;

    public Calculator()
    {
        stack = new ArrayDeque<Double>();
    }

    public Deque<Double> push(String pushed)
    {
        try{
            stack.push(Double.parseDouble(pushed));
        }
        catch(NumberFormatException error){
            try {
                if (pushed.equals("+")) {
                    Double temp1 = stack.pop();
                    Double temp2 = stack.pop();
                    stack.push(temp2 + temp1);}

                else if (pushed.equals("-")) {
                    Double temp1 = stack.pop();
                    Double temp2 = stack.pop();
                    stack.push(temp2 - temp1);}

                else if (pushed.equals("*")||pushed.equals("×")) {
                    Double temp1 = stack.pop();
                    Double temp2 = stack.pop();
                    stack.push(temp2 * temp1);}

                else if (pushed.equals("÷")||pushed.equals("/")){
                    Double temp1 = stack.pop();
                    Double temp2 = stack.pop();
                    stack.push(temp2 / temp1);}
                else
                    System.out.printf("ERROR: Unsupported operation%n");
            }
            catch(EmptyStackException empty)
            {
                System.out.printf("ERROR: Too many operations%n");
            }
        }

        return stack;
    }

    public void cout()
    {
        System.out.printf("%f%n", stack.peek());
    }
}
