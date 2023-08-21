import java.util.*;
interface Abc
{
	void compare(String x,String y);
}

class FI
{
	public static void main(String... args)
	{
		Abc obj=(x,y) ->{
			if(x.compareTo(y)==0)
				System.out.println("Both are equal");
			else
				System.out.println("Both are not equal");
		};
		Scanner in=new Scanner(System.in);
		System.out.println("Enter string 1:");
		String str1=in.next();
		System.out.println("Enter string 2:");
		String str2=in.next();
		obj.compare(str1,str2);
	}
}
				
  
