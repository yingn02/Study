//클라이언트 구현, 연결 후 클라이언트에서 먼저 메시지 보냄, 이후 순차적으로 한 번씩 메시지를 주고 받음(에코 서버/클라이언트)
//서버와 클라이언트 중 어디서든 "끝"을 입력하면 서버와 클라이언트 모두 동시에 종료

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.util.Scanner;

//소스 코드를 입력하고 Ctrl+Shift+O를 눌러서 필요한 파일을 포함 
public class TestClient {
	public static void main(String[] args) {
		
		try {
			Socket socket = new Socket("localhost", 9999); // 클라이언트 소켓 생성. 서버에 바로 접속
			System.out.println("클라이언트입니다. 서버에 접속하였습니다.");
			
			BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream())); 
			BufferedWriter out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())); 
			
			Scanner scanner = new Scanner(System.in);
			
			String inputMessage;
			String outputMessage;
			
			while (true) {
				
				System.out.print("보낼 메시지 입력 >> ");
				outputMessage = scanner.nextLine(); // 키보드에서 한 행의 문자열 읽음
				out.write(outputMessage+"\n"); // 서버로 보냄
				out.flush();
				if (outputMessage.equals("끝")) { // "끝"이 입력되면 연결 종료
					System.out.println("연결을 종료합니다.");
					break;
				}	
		
				inputMessage = in.readLine(); // 서버로부터 한 행의 텍스트 받음
				System.out.println("받은 메시지: " + inputMessage); // 서버가 보낸 메시지 화면에 출력
				if (inputMessage.equals("끝")) { // 서버가 "끝"을 보내면 연결 종료
					System.out.println("연결을 종료합니다.");
					break;
				}	
			}
			
			scanner.close();
			socket.close(); 
			
		} catch (IOException e) {
			System.out.println("오류가 발생했습니다.");
		}
	}

}

