using System.Collections; //#include ��� �̷��Ծ���
using System.Collections.Generic;
using UnityEngine;

public class cshtest : MonoBehaviour //MonoBehaviour�̶�� �θ�� ���� ��ӹ޴´� //Ŭ�����̸� = ���ϸ� �� ���Ѷ� //������ ������Ʈ�� ��������� ���밡��
{
    public int num=20;
    //private int num = 20; //private �� ����Ʈ��
    //��ӹ����ְ� ���ٰ����ϵ��� protect�� ���� ���� �ְ����� ����� ���� ���� ����

    // Start is called before the first frame update
    void Start() //������ �� (�θ� ������ �ִ� �� �������ϴ� ���̹Ƿ� ä���� �ʾƵ� ������ �Ǳ���)
    {
        //Debug.Log("Start");
        Debug.Log(num);
    }

    // Update is called once per frame
    void Update() //����� �ٲ� �� ���� ȣ���, ������ǻ���ϼ��� ���� ȣ���
    {
       // Debug.Log("Update");
    }
}
