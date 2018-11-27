package com.company;

public class Main {

    public static void main(String[] args) {
        Listor listor = new Listor();
        Listor child = new Listor();
        Listor childchild = new Listor();
        for(int i = 0; i < 20; i++)
        {
            listor.push(i);
            child.push(i+100);
            childchild.push(i+200);
        }
        listor.pushListor(10, child);
        child.pushListor(10, childchild);
        listor.cout();
        System.out.printf("%n%d%n", listor.at(29));
    }
}
