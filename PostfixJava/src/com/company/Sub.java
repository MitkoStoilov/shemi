package com.company;

public class Sub implements Operand{
    public String operation_;

    public java.lang.Number operate(java.lang.Number op1, java.lang.Number op2)
    {
        return op2.doubleValue() - op1.doubleValue();
    }

    public String getO()
    {
        return operation_;
    }
}
