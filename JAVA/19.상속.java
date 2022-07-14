class Cal { // 클래스 Cal
	public int sum(int v1, int v2) {
		return v1 + v2;
	}
}

class Cal2 extends Cal { // 클래스 Cal를 상속받은 클래스 Cal2
	
}

public class hello {
	public static void main(String[] args) {
		Cal2 c2 = new Cal2(); // 인스턴스 생성 (오브젝트 생성)
		
		System.out.println(c2.sum(2, 1)); //3
	}
}
