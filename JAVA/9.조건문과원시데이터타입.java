public class hello {
	public static void main(String[] args) {
		// 더 이상 쪼개지지 않는 원시데이터 타입 (boolean, int, double, float, char ...)
		// 더 쪼갤 수 있다면 원시데이터 타입이 아니다 (String, Array, Date, File ...) 
		
		int key = 4321; // 원시데이터 타입
		
		if (key == 1234) { // 원시데이터 타입이 아니면 key.equals(1234)
			System.out.println("Login");
		}
		else if (key == 4321) {
			System.out.println("Login2");
		}
		else {
			System.out.println("Failed");
		}
		
	}
}
