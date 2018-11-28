package com.company;
import java.util.*;

public class Listor extends Vector{
    public Vector<Integer> data_;
    public HashMap<Integer, Listor> child_ = new HashMap<Integer, Listor>();

    public Listor()
    {
        data_ = new Vector<Integer>(50, 50);
    }

    public Listor(Vector<Integer> data)
    {
        data_ = new Vector<Integer>(data.size(), data.size());
        data_ = data;
    }

    public void push(Integer element)
    {
        data_.add(element);
    }

    public void pushListor(Integer position, Listor listor)
    {
        child_.put(position, listor);
    }

    public Integer at(Integer index)
    {
        int current = 0;
        int sizes = 0;
        for(Map.Entry<Integer, Listor> entry : child_.entrySet())
        {

            if(index > entry.getKey() + entry.getValue().size()) {

                sizes = sizes + entry.getValue().data_.size() + entry.getKey();
            }
            if(entry.getKey() <= index && entry.getKey() + entry.getValue().size() > index)
            {
                sizes = sizes + entry.getValue().data_.size();
                current = current + entry.getKey();
                if(entry.getKey()+entry.getValue().data_.size() > index-current)
                {
                    return entry.getValue().at(index-current);
                }
            }
        }
        return data_.elementAt(index - sizes - current);
    }

    public int size()
    {
        Integer size = data_.size();
        for(Map.Entry<Integer, Listor> entry : child_.entrySet())
        {
            size = size + entry.getValue().data_.size();
        }
        return size;
    }

    public void cout()
    {
        for(int i = 0; i < data_.size(); i++) {
            if (child_.containsKey(i))
                child_.get(i).cout();
            System.out.printf("%d ", data_.elementAt(i));
        }
    }
}
