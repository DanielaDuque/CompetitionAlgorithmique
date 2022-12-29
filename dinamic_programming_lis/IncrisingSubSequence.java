import java.util.Scanner;

class Main {

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
        while (N != 0){
            int[] sequence = new int[N];
            int[] numbers = new int[N];
            int[] pred = new int[N];
            for(int i = 0; i < N; i++){
                pred[i] = -1;
            }
            int longestSubsequence = 0;

            for (int i = 0; i < N; i++) {
                sequence[i] = sc.nextInt();
                numbers[i] = 1;
                int pos = binary_search(numbers, 0, longestSubsequence - 1, sequence[i]);
                numbers[pos] = sequence[i];
                longestSubsequence = Math.max(longestSubsequence, pos + 1);
            }


            System.out.print(longestSubsequence + " ");
            for(int i = 0; i < longestSubsequence; i++){
                System.out.print(numbers[i] + " ");
             }
             System.out.print("\n");
             N = sc.nextInt();
        }
    }
}