class Print { // 클래스를 선언함 
	public String s = ""; // 인스턴스에 속하므로 static 삭제함
	
	Print(String s) { //생성자 함수
		System.out.println("생성자가 호출됨");
		this.s = s; // s = s 가 아니라 this를 쓴다
	}

	
	public void A() { // 인스턴스에 속하므로 static 삭제함
		System.out.println("--- A ---");
		System.out.println(this.s); //여기도 this
	}
}


public class hello {
	public static void main(String[] args) {
		Print p1 = new Print("****"); // 인스턴스, 생성자가 호출됨
		
		p1.s = "Hello"; // s를 Hello로 설정
		p1.A(); // --- A --- Hello
	} 
}
