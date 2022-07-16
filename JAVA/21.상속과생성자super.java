class Cal {
	int v1, v2;
	Cal(int v1, int v2) {
		System.out.println("Cal 생성자함수 호출");
		this.v1 = v1; this.v2 = v2; // this는 자기 자신
	}
}

class Cal2 extends Cal {
	Cal2(int v1, int v2) {
		super(v1, v2); // super는 자신의 부모 (Cal)
		System.out.println("Cal2 생성자함수 호출");
	} 
}

public class hello {
	public static void main(String[] args) {
		Cal c = new Cal(2, 1);
		Cal2 c2 = new Cal2(2, 1);
	}
}
