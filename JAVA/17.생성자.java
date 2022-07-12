class Print { // 클래스를 선언함 
	public String s = ""; // 인스턴스에 속하므로 static 삭제함
	
	Print() { //생성자 함수
		System.out.println("생성자가 호출됨");
	}

	
	public void A() { // 인스턴스에 속하므로 static 삭제함
		System.out.println("--- A ---");
		System.out.println(s);
	}
}


public class hello {
	public static void main(String[] args) {
		Print p1 = new Print(); // 인스턴스, 생성자가 호출됨
		
		p1.s = "Hello"; // s를 Hello로 설정
		p1.A(); // --- A --- Hello
	} 
}
