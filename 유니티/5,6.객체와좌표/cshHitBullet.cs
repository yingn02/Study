using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cshHitBullet : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    void OnCollisionEnter(Collision coll) //collider�� ������ �� ȣ��Ǵ� �Լ�
    {
        if (coll.gameObject.tag == "BULLET") //���� ���� �Ѵ�  collider�� �ְ�+  BULLET�̶�� �±׸� �ް��ִ¾ְ� ����
        {
            Destroy(coll.gameObject); //��(�Ҹ�)�� ���ֶ� (coll ���� ��(��)�� �����)
        }
    }

    //�Ʊ��� �����ϵ� ���� �����ϸ� �ȵ� �� �߰��ϸ� ���� �ִ� �Լ��� �ð� �̰� ���� (������ �Ȱ���)
    void OnTriggerEnter(Collider coll) //trigger�� ������ �� ȣ��Ǵ� �Լ�
    {
        if (coll.gameObject.tag == "BULLET")
        {
            Destroy(coll.gameObject);
        }
    }


    // Update is called once per frame
    void Update()
    {
        
    }
}
