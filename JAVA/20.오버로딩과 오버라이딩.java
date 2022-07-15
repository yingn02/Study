class Cal { // 클래스 Cal
	public int sum(int v1, int v2) {
		return v1 + v2;
	}
	
	// sum이라는 이름은 같지만 다른 함수 overroding
	public int sum(int v1, int v2, int v3) {
		return v1 + v2 + v3;
	}
}

class Cal2 extends Cal { // 클래스 Cal를 상속받은 클래스 Cal2
	
	// 이미있는 똑같은 함수를 재정의 overriding
	public int sum(int v1, int v2) {
		System.out.println("sum 함수 호출됨");
		return v1 + v2;
	}
}

public class hello {
	public static void main(String[] args) {
		Cal2 c2 = new Cal2(); // 인스턴스 생성 (오브젝트 생성)
		
		System.out.println(c2.sum(2, 1)); //3
	}
}
