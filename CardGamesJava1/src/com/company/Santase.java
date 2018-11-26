package com.company;
import java.util.*;

public class Santase extends Deck{
    public Santase()
    {
        size_ = 0;
        msize_ = 24;
        h_size_ = 6;
        min_p_ = 9;
        pwrs = new HashMap<Integer, Integer>();
        clrs = new HashMap<Character, Integer>();
        cards = new Vector<Card>(msize_, msize_);
        pwrs.put(9,9);
        pwrs.put(10, 13);
        pwrs.put(11, 10);
        pwrs.put(12, 11);
        pwrs.put(13, 12);
        pwrs.put(14, 14);
    }
}
