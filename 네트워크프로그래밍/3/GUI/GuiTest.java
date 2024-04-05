import javax.swing.JFrame;

public class GuiTest {

	public static void main(String[] args) {
		JFrame f = new JFrame("Frame Test"); //이 라인을 클릭하고 컨트롤 + 쉬프트 + o 누르면 자동 임포트
		f.setTitle("MyFrame");
		f.setSize(300, 200);
		f.setLocation(400, 200);
		f.setVisible(true);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //이거 없으면 프로그램을 종료할 수 없음 (17p)
	}

}
