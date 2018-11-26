package com.company;
import java.util.*;

public class War extends Deck {
    public War()
    {
        size_ = 0;
        msize_= 52;
        h_size_ = 26;
        min_p_ = 2;
        pwrs = new HashMap<Integer, Integer>();
        clrs = new HashMap<Character, Integer>();
        cards = new Vector<Card>(msize_, msize_);
        for(Integer i = 2; i <= 14; i++)
        {
            pwrs.put(i, i);
        }
    }
}
