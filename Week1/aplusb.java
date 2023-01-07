import java.util.Scanner;

class SumOfDigits {
    static int sumOfDigits(int first, int second) {
        return first + second;
    }

    public static void main(String[] args) {
    	Scanner s = new Scanner(System.in);
	int a = s.nextInt();
	int b = s.nextInt();
	System.out.println(sumOfDigits(a,b));
    }
}
