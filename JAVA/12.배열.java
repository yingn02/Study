public class hello {
	public static void main(String[] args) {
		//크기가 3인 문자열 배열 생성
		String[] user = new String[3];
		String[] user2 = {"kiwi", "banana", "pineapple"};
		
		user[0] = "kiwi";
		user[1] = "banana";
		user[2] = "pineapple";
		
		System.out.println(user[0]); // kiwi
		System.out.println(user[1]); // banana
		System.out.println(user[2]); // pineapple
		System.out.println(user2[0]); // kiwi
		System.out.println(user2[1]); // banana
		System.out.println(user2[2]); // pineapple
		
		//크기가 5인 정수 배열 생성
		int[] score = {50, 70, 100};
		
		System.out.println(score[0]); // 50
		System.out.println(score[1]); // 70
		System.out.println(score[2]); // 100
	}
}
