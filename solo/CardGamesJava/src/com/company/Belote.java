package com.company;
import java.util.*;
public class Belote extends Deck {
    public Belote() {
        msize_ = 32;
        h_size_ = 8;
        pwrs = new HashMap<Character, Integer>();
        clrs = new HashMap<Character, Integer>();
        cards = new Vector<Card>(msize_, msize_);
        pwrs.put((char)7, 7);
        pwrs.put((char)8, 8);
        pwrs.put((char)9, 9);
        pwrs.put((char)10, 13);
        pwrs.put('J', 10);
        pwrs.put('Q', 11);
        pwrs.put('K', 12);
        pwrs.put('A', 14);

        clrs.put('S', 4);
        clrs.put('H', 3);
        clrs.put('D', 2);
        clrs.put('C', 1);
    }
}
