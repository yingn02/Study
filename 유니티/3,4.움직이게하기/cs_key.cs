using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cs_key : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.Space))
        {
            Debug.Log("space!");
        }

        if (Input.GetMouseButtonDown(0)) {
            Debug.Log(Input.mousePosition); // Ŭ���� 2������ ��ǥ�� ���
            //����� 2������ ��ǥ�� ��������
            //��ġ ���ɼ��� �ִ� 2������ ��ǥ���� �� ������
            //�ϳ��� ���� �Ǵµ� �� ���� ���� ���ٴڰ� ������ �ű�� �̵���ų �� �ִ�
        }
    }
}
