package ex.lotto;
public class LottoCard {
	int[][] mLotto; //Lotto 媛�泥댁�� 諛곗��
	boolean[][] minValid;
	int mEffNum; //媛��� �ㅼ���� 濡���蹂듦��� 媛���(1 ~ 5)
	
	public LottoCard(int n) { 
		mEffNum = n; // n <= 5
		mLotto = new int[mEffNum][6]; 
		minValid = new boolean[mEffNum][6]; 
		
		for(int i = 0; i < n; i++) { //n�� ���� (����)
			Lotto lotto = new Lotto();
			mLotto[i] = lotto.getNumbers();
			for(int j=0;j<6;j++) {
				minValid[i][j] = lotto.verify();
			}
		}
		
	}
	
	//濡��� 移대�� �� �뱀�� 濡��� 蹂듦��� 踰��몃�� ����/���� �ㅼ��
	public void auto(int n) { //n踰�吏� 蹂듦��� �����쇰�
		Lotto lotto = new Lotto();
		mLotto[n] = lotto.getNumbers();
	}
	
	public void manu(int n, int n1, int n2, int n3, int n4, int n5, int n6) { //n踰�吏� 蹂듦��� �����쇰�
		Lotto lotto = new Lotto(n1, n2, n3, n4, n5, n6);
		mLotto[n] = lotto.getNumbers();
	}
	
	
	// 濡��� 移대�� �� ���⑦�� 媛��� �ㅼ���� 蹂듦��� 濡��� 踰��� 諛��� �뱀�� 異���
	int[] get_nums() { //諛���
		int[] nums = new int[30];
		int index = 0;
		
		for(int i = 0; i < mEffNum; i++) {
			if(minValid[i][0] == true && minValid[i][1] == true && minValid[i][2] == true && minValid[i][3] == true && minValid[i][4] == true && minValid[i][5] == true) {
				for(int j = 0; j < 6; j++) { //���⑦��硫� 諛곗�댁�� 踰��� 6媛� �ｊ린
					nums[index] = mLotto[i][j]; 
				}
			}
		}
		return nums; // ���⑦�� 踰��몃�ㅼ�� 紐⑥�� 諛곗�댁�� �듭㎏濡� 諛���
	}
	
	public void print_nums() { //異���		
		for(int i = 0; i < mEffNum; i++) {
			if(minValid[i][0] == true && minValid[i][1] == true && minValid[i][2] == true && minValid[i][3] == true && minValid[i][4] == true && minValid[i][5] == true) {
				for(int j = 0; j < 6; j++) { //���⑦��硫� 6媛��� 踰��� 異���
					System.out.print(mLotto[i][j] + " ");
				}
				System.out.println();
			}
		}
	}
	
	
	
	
	
	
	
	
}
