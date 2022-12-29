package com.company;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

class Amite{
    ArrayList<Integer> father = new ArrayList<>();
    ArrayList<Integer> size = new ArrayList<>();
    HashMap<String, Integer> map = new HashMap();
    int cont = 0;
    Amite(){}

    public int join(String first, String second){
        int fatherFirst = father(map.get(first));
        int fatehrSecond = father(map.get(second));

        if(fatehrSecond==fatherFirst) return size.get(fatehrSecond);
        else{
            if(fatherFirst< fatehrSecond) {
                father.set(fatehrSecond, fatherFirst);
                size.set(fatherFirst, size.get(fatehrSecond) + size.get(fatherFirst));
                return size.get(fatherFirst);
            }else{
                father.set(fatherFirst, fatehrSecond);
                size.set(fatehrSecond, size.get(fatehrSecond) + size.get(fatherFirst));
                return size.get(fatehrSecond);
            }
        }

    }

    public void create(String val){
        if(map.containsKey(val)) return;
        int index = cont++;
        map.put(val, index);
        father.add(index);
        size.add(1);
    }

    public int father(int pos){
        if(father.get(pos) == pos) return pos;
        else {
            int fatherPos = father(father.get(pos));
            father.set(pos, fatherPos);
            return fatherPos;
        }
    }

}

public class Main {


    public static void main(String[] args) {
        // write your code here
        Scanner sc = new Scanner(System.in);
        int numberCase = sc.nextInt();
        for (int i = 0; i < numberCase; i++) {
            int N = sc.nextInt();
            Amite am = new Amite();
            for (int j = 0; j < N; j++) {
                String first = sc.next();
                String second = sc.next();
                am.create(first);
                am.create(second);
                System.out.println(am.join(first, second));
            }

        }
    }
}
