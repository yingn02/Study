package ex.hw;
import ex.lotto.LottoCard;

public class LottoSim {

	public static void main(String[] args) {
		// �� ���� �ζ� ī�� ���� �ζ� ���� 5���� �ڵ� ���� ����� �̿��� ���� �� ���
		System.out.println("1번째 로또 카드");
		
		LottoCard lc = new LottoCard(5);
		lc.print_nums();
		
		System.out.println();
		
		// �Ǵٸ� �ζ� ī���� �ζ� ���� 3���� ���� (2���� �ڵ�)
		System.out.println("2번째 로또 카드");
		
		LottoCard lc2 = new LottoCard(5);
		lc2.manu(1, 3, 6, 9, 12, 15, 18); //ī���� 1��° ������ 3�� ����� ��ȣ ���� (����)
		lc2.manu(2, 4, 8, 12, 16, 20, 24); //ī���� 2��° ������ 4�� ����� ��ȣ ���� (����)
		lc2.manu(3, 5, 10, 15, 20, 25, 30); //ī���� 3��° ������ 5�� ����� ��ȣ ���� (����)
		lc2.print_nums();
		//������ 4 ~ 5��° ������ �ڵ����� �̹� �����Ǿ������� �ǵ帱 ���� ����
	}

}
