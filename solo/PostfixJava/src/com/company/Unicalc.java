package com.company;
import java.util.*;

public class Unicalc<T> implements Calculator {
    public Deque<Double> stack;
    HashMap<String, Operand> ops_ = new HashMap<String, Operand>();

    public Object push(String pushed)
    {
        try{
            stack.push(Double.parseDouble(pushed));
        }
        catch(NumberFormatException error){
            try {
                stack.push(ops_.get(pushed).operate(stack.pop(), stack.pop()).doubleValue());
            }
            catch(NoSuchElementException empty)
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
