//(클라이언트와 연결이 되면) "연결 완료" 메시지를 한 번만 자동으로 보내고 종료(가장 심플하게 구현)
//앞의 코드를 다음과 같이 수정, 이후 Ctrl+Shift+O 눌러서 import 파일 정리

import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class TestServer4 {
	public static void main(String[] args) {
		try {

			ServerSocket listener = new ServerSocket(9999); // 서버 소켓 생성
			Socket socket = listener.accept(); // 클라이언트로부터 연결 요청 대기
			
			PrintWriter out = new PrintWriter(socket.getOutputStream());
			out.print("서버 연결 완료"+"\n"); // 연결이 되면 클라이언트로 "서버 연결 완료" 메시지를 보냄
			out.flush();
			
			out.close();
			socket.close(); 
			listener.close(); 
			
		} catch (IOException e) {
			System.out.println("오류가 발생했습니다.");
		}
	}
}



