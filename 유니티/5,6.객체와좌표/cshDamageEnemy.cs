using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cshDamageEnemy : MonoBehaviour
{
    public int HP = 3;

    void Start() 
    {
    
    }

    // Update is called once per frame
    void Update()
    {

    }

    void OnTriggerEnter(Collider coll) //�Ҹ��� Ʈ���� �̹Ƿ� Ʈ�����Լ��� ��
    {
        if (coll.gameObject.tag == "BULLET")
        {
            HP--;
            if(HP <= 0)
                Destroy(gameObject); //��(����)�� ���ش�
        }
    }


}

