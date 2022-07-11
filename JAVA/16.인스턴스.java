class Print { // 클래스를 선언함 
	public String s = ""; // 인스턴스에 속하므로 static 삭제함
	
	public void A() { // 인스턴스에 속하므로 static 삭제함
		System.out.println("--- A ---");
		System.out.println(s);
	}
	
	public void B() { // 인스턴스에 속하므로 static 삭제함
		System.out.println("--- B ---");
		System.out.println(s);
	}
}


public class hello {
	public static void main(String[] args) {
		// c++ 에서의 오브젝트 선언과 같은 역할, 인스턴스
		Print p1 = new Print();
		p1.s = "";
		
		
		p1.s = "Hello"; // s를 Hello로 설정
		p1.A(); // --- A --- Hello
		p1.B(); // --- B --- Hello
		
		p1.s = "World"; // s를 World로 설정
		p1.A(); // --- A --- World
		p1.B(); // --- B --- World
	} 
}
