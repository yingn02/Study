class Print { // 클래스를 선언함 
	public static String s = "";
	
	public static void A() {
		System.out.println("--- A ---");
		System.out.println(s);
	}
	
	public static void B() {
		System.out.println("--- B ---");
		System.out.println(s);
	}
}


public class hello {
	public static void main(String[] args) {
		Print.s = "Hello"; // s를 Hello로 설정
		Print.A(); // --- A --- Hello
		Print.B(); // --- B --- Hello
		
		Print.s = "World"; // s를 World로 설정
		Print.A(); // --- A --- World
		Print.B(); // --- B --- World
	} 
}
