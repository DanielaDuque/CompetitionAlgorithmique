import java.util.Scanner;

public class Main {

    static int binary_search(int [] lis, int start, int end, int val)
    {
        while (start <= end)
        {
            int middle = start + (end - start) / 2;
            if (lis[middle] == val) return middle;
            if (lis[middle] < val) start = middle + 1;
            else end = middle - 1;
        }
        return start;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] sequence = new int[N];
        int[] numbers = new int[N];
        int longestSubsequence = 0;

        for (int i = 0; i < N; i++) {
            sequence[i] = sc.nextInt();
            numbers[i] = 1;
            int pos = binary_search(numbers, 0, longestSubsequence - 1, sequence[i]);
            numbers[pos] = sequence[i];
            longestSubsequence = Math.max(longestSubsequence, pos + 1);
        }
        System.out.println(longestSubsequence);
    }
}