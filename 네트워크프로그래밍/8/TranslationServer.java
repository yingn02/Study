package test1019;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class TranslationServer {

	public static void main(String[] args) throws Exception { //메인
		System.out.println("영어 번역 서버가 실행중입니다.");
		int clientId = 0; //클라이언트는 1명이 아니다, 클라이언트의 번호임
		ServerSocket ss = new ServerSocket(9101);
		try { //예외처리
			while (true) {
				clientId++;
				Translator t = new Translator(ss.accept(), clientId); //서버를구동, 클라이언트의 요청이 올때까지 대기, 요청오면 테스트
				t.start();
			}
		} finally {
			ss.close();
		}
	}

	private static class Translator extends Thread { //스레드, 내부클래스임, inner클래스는 밖 클래스의 멤버에 모두 접근가능! setter함수같은거안써도됨
		private Socket socket;
		private int myId;

		public Translator(Socket socket, int clientId) {//Socket socket는  accept함수가 보낸객체를 받음 , 객체의 정체는 스레드객체?
			this.socket = socket;
			this.myId = clientId;
		}

		public void run() { //동시에 실행하고픈 프로그램을 작성
			try {
				BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream())); // 소켓 입력 스트림
				BufferedWriter out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())); // 소켓 출력 스트림

				out.write("안녕하세요? 클라이언트 번호는 " + myId + "입니다." + "\n"); 
				out.write("단어를 입력하세요" + "\n"); 
				out.flush();
				
				while (true) {
					String input = in.readLine();
					if (input == null) {
						break;
					}
					if (input.equals("java") == true) {
						out.write("java->자바" + "\n");
					    out.flush();
					}
					else {
						out.write("조금 쉬운 단어를 보내주세요." + "\n");
						out.flush();
					}
				}
			} catch (IOException e) {
				System.out.println("클라이언트 번호: " + myId + "처리 실패" + e);
			} finally {
				try {
					socket.close();
				} catch (IOException e) {
					System.out.println("소켓 종료 오류" + e);
				}
				System.out.println("클라이언트 번호: " + myId + "처리 처리 종료");
			}
		}

	}
}