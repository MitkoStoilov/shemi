package com.company;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Deck deck = new Deck();
        Santase dick = new Santase();
        for(int i = 2; i <= 10; i++)
        {
            deck.push(new Card('S', i));
        }
        deck.cout();
        dick.copyCards(deck);
        dick.cout();
        dick.seed();
    }
}