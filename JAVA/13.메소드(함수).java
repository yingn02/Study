public class hello {
	//메소드 선언
	public static void print_hello() {
		System.out.println("hello");
	}
	
	public static void main(String[] args) {
		// c언어의 함수를 JAVA에서는 메소드라고 부른다
		// 코드를 효율적으로 바꾸는 것 : 리팩토링
		print_hello();
		print_hello();
		print_hello();
	}
}
