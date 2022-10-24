// Yet Another Number Game
import java.util.Scanner;


public class Main {

    public static void main(String[] args) {
	// write your code here
        Scanner sc = new Scanner(System.in);

        int numberCase = sc.nextInt();
        for (int i = 0; i < numberCase; i++) {
            int N = sc.nextInt();
            if(N%2==1) System.out.println("BOB");
            else System.out.println("ALICE");
        }
    }
}
