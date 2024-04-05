//(서버와 연결 후) 서버의 메시지를 한 번만 받아서 출력하고 종료(가장 심플하게 구현)
//앞의 코드를 다음과 같이 수정, 이후 Ctrl+Shift+O 눌러서 import 파일 정리

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.Socket;

public class TestClient31 {
	public static void main(String[] args) {
		
		try {
			Socket socket = new Socket("localhost", 9999); // 클라이언트 소켓 생성. 서버에 바로 접속
			
			InputStream is = socket.getInputStream();
			InputStreamReader ir = new InputStreamReader(is);
			BufferedReader in = new BufferedReader(ir); 
			
			String inputMessage = in.readLine(); // 서버로부터 한 행의 텍스트 받음
			System.out.println("받은 메시지: " + inputMessage); // 서버가 보낸 메시지 화면에 출력


			socket.close(); 
			
		} catch (IOException e) {
			System.out.println("오류가 발생했습니다.");
		}
	}
}


