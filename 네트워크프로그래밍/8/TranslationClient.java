package test1019;
import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;

import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class TranslationClient extends JFrame implements ActionListener { //인터페이스? 클라에서는 다른사용자따위신경안씀, 스레드없다!

	private BufferedReader in;
	private BufferedWriter out;
	private JTextField field;
	private JTextArea area;

	public TranslationClient() throws Exception, IOException {

		setTitle("클라이언트");
		setSize(500, 300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);

		field = new JTextField(50);
		field.addActionListener(this);

		area = new JTextArea(10, 50);

		area.setEditable(false);
		add(field, BorderLayout.NORTH);
		add(area, BorderLayout.CENTER);
		//여기부터는 소켓 프로그래밍
		Socket socket = new Socket("localhost", 9101);
		in = new BufferedReader(new InputStreamReader(socket.getInputStream())); // 소켓 입력 스트림
		out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())); // 소켓 출력 스트림

		area.append(in.readLine() + "\n"); //네트워크로 들어오는 데이터 1줄 읽어들여라 그리고 append해라(로그출력)
		area.append(in.readLine() + "\n");
	}

	@Override
	public void actionPerformed(ActionEvent arg0) { //

		String response = null;
		try {
			out.write(field.getText() + "\n"); //입력받은거 전송해라
		    out.flush();
			response = in.readLine();//읽어들여라
		} catch (IOException e) {
			e.printStackTrace();
		}
		area.append(response + "\n");
	}

	public static void main(String[] args) throws Exception {
		TranslationClient client = new TranslationClient();
	}

}