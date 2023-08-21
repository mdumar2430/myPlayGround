import java.util.Scanner;
class Simple
{
  static long factorial(int n)
  { 
     long fact=1L;
    for(int i=1;i<=n;i++)
    {
	fact=fact*i;
    }
    return fact;
  }
  public static void main(String... args)
  {
    Scanner input=new Scanner(System.in);
    System.out.println("\nEnter no. of terms:");
    int n=input.nextInt();
    long res=factorial(n);
    System.out.println("Factorial of "+n+" is "+res); 
  }
}
