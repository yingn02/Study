public class hello {
	public static void main(String[] args) {
		// 데이터타입변환 (Casting)
		
		int a = (int)1.1;
		System.out.println(a); // 1
		
		double b = (double)1;
		System.out.println(b);
		
		String c = Integer.toString(123); // 123
		System.out.println(c); // "123"
	}
}
