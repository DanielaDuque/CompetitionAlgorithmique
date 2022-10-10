//package com.company;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {

    public static boolean possible(long t, ArrayList<Integer> machines, int objects){
        long obj = 0;
        for (int val: machines) {
            obj +=  t/val;
//            System.out.println(obj + " " + t + " " + objects);
            if(obj >= objects) return true;
        }
        return false;
    }

    public static long search(ArrayList<Integer> machines, int objects) {
        long max = (long) Math.pow(10,18);//max(machines,objects);
        long min = 0;
        long res = 0;
        while(min <= max) {
//            System.out.println(max + " : " + min);
            long moyen = min + (max-min)/2;
            boolean pos = possible(moyen, machines,objects);
            if(pos) {
                res = moyen;
                max = moyen -1;
            }
            else{
                min = moyen +1;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        // write your code here
        Scanner sc = new Scanner(System.in);
        int machines = sc.nextInt();
        int objects = sc.nextInt();
        ArrayList<Integer> arr = new ArrayList<>();
        for (int i = 0; i < machines; i++) {
            arr.add(sc.nextInt());
        }
        System.out.println(search(arr,objects));

    }
}
