
public class Scratch {

	public static void main(String[] args) {
		A a = new B(); // 업캐스팅
		a.f();
		//a.g(); //오류 발생

		B b = (B) a; //다운캐스팅
		b.f();
		b.g();
	}

}

class A {
	void f() {
		System.out.println("f 함수 호출");
	}
}

class B extends A {
	void g() {
		System.out.println("g 함수 호출");
	}
}
