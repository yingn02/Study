using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cs_player : MonoBehaviour
{
    public GameObject prefab; //������


    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.A)) //A ������
        {
            float rnd = Random.Range(0.0f, 0.5f); //0 ~ 0.5 ������ ������ �߻���Ű�� rnd�� ���� 
            this.transform.position = new Vector3(0.0f, 1.0f, rnd); //this(player)�� �������� ����� ���� ���� 
        }


        if (Input.GetKeyDown(KeyCode.B))
        {
            float rnd = Random.Range(0.0f, 360.0f);
            this.transform.rotation = Quaternion.Euler(rnd, 0.0f, 0.0f); //x���� �������� ȸ��

        }

        if (Input.GetKey(KeyCode.UpArrow))
        {
            this.transform.Translate(new Vector3(0.0f, 0.0f, 0.1f * 3.0f * Time.deltaTime)); //�̵� (�����̵��� �ƴ�), ����(����)�� �ӵ�(��Į��)
        }

        if (Input.GetKey(KeyCode.DownArrow))
        {
            this.transform.Translate(new Vector3(0.0f, 0.0f, -0.1f * 3.0f * Time.deltaTime)); //�̵� (�����̵��� �ƴ�), ����(����)�� �ӵ�(��Į��)
        }

        if (Input.GetKey(KeyCode.R))
        {
            this.transform.Rotate(1.0f * 90.0f * Time.deltaTime, 0.0f, 0.0f); //1�� �� x������ 90����
        }

        if (Input.GetKey(KeyCode.L))
        {
            this.transform.Rotate(1.0f * -90.0f * Time.deltaTime, 0.0f, 0.0f); //1�� �� x������ -90����
        }

        if (Input.GetMouseButtonDown(0)) //������, ���콺 ���ʹ�ư
        {
            GameObject go = GameObject.Instantiate(prefab) as GameObject; //Instantiate: �������� �����ϴ� �Լ�
            go.transform.position = new Vector3(Random.Range(-2.0f, 2.0f), 1.0f, 1.0f);
        }

    }
}
