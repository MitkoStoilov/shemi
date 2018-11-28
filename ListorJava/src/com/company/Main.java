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
        child.pushListor(10, childchild);
        listor.pushListor(10, child);
        listor.cout();
        System.out.printf("%n");
        System.out.printf("%d%n", listor.at(40));
    }
}
