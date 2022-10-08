package ex.lotto;
import java.util.Random;

public class Lotto {
	int[] lottoNumber = new int[6]; // 복권 1개에는 6개의 번호
	boolean isValid;
	
	Lotto(int n1, int n2, int n3, int n4, int n5, int n6) {
		//lottoNumber = new int[6];
		
		lottoNumber[0] = n1;
		lottoNumber[1] = n2;
		lottoNumber[2] = n3;
		lottoNumber[3] = n4;
		lottoNumber[4] = n5;
		lottoNumber[5] = n6;
		
		isValid = verify();
	}	
	
	Lotto(int[] arr) {
		lottoNumber = new int[6];
		
		for(int i = 0; i < 6; i++) {
			lottoNumber[i] = arr[i];
		}
		
		isValid = verify();
	}
	
	public Lotto() {
		generate();
		
		isValid = verify();
	}
	
	boolean verify() {
		//�닿� 鍮�援���怨������� ������ �ㅼ�� �몃�깆�� 媛�遺��� 鍮�援�, 諛�蹂듬Ц
		for(int i = 0; i < 6; i++) {
			for(int j = 1; i+j < 6; j++) {
				if((lottoNumber[i] == lottoNumber[i+j]) || (lottoNumber[j] < 0) || (lottoNumber[j] > 45))
					return false;
			}
		}
		return true;
	}
	
	void generate() {
		//���� ���� �쇰�� ���깊��怨�, �ㅼ�� ���깅��곕�� �닿� �ㅼ�닿� ��由� �댁��源�吏� 鍮�援�
		Random r = new Random();

		int new_rand = r.nextInt(45) + 1; // 1 ~ 45 ��濡��� ���� 異�泥�
		lottoNumber[0] = new_rand;
		
		for(int i = 1; i < 6; i++) {
			new_rand = r.nextInt(45) + 1; // 1 ~ 45 ��濡��� ���� 異�泥�
			for(int j = 0; j < i; j++) {
				if(lottoNumber[i] == lottoNumber[j] || (lottoNumber[i] < 0) || (lottoNumber[i] > 45)) {
					i--; // ��濡� 戮��� �レ��媛� 以�蹂듭�닿굅�� 1~45媛� ����硫� 1�� ��媛�湲�
				}	
			}
			lottoNumber[i] = new_rand;
		}
		
	}
	
	void show() {
		if(isValid == false) {
			System.out.println("�ㅻ�: ���⑦��吏� ���� 濡���踰��� ������.");
		}
		else {
			System.out.println("���⑦�� 濡���踰��� ������.");
			for(int i = 0; i < 6; i++) {
				System.out.print(lottoNumber[i] + " ");
			}
			System.out.println();
		}
	}
	
	int[] getNumbers() {
		if(isValid == false) {
			return null;
		}
		else {
			return lottoNumber; // 諛곗�댁�� �듭㎏濡� 諛���
		}
	}
	
}
