using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cshFire : MonoBehaviour
{
    private float bulletSpeed = 1000.0f;
    private Transform thisTransform;
    // Use this for initialization
    void Start() //������ ���� ����
    {
        thisTransform = GetComponent<Transform>(); //Tramsform�� ���Ͷ�
        FireBullet(); //�߻�Ƕ�
    }

    void FireBullet()
    {
        GetComponent<Rigidbody>().AddForce(thisTransform.forward * bulletSpeed); //�չ������� ���� ���ض� (deltaTime�� ���ϸ� �ȵȴ�)
    }


    // Update is called once per frame
    void Update()
    {
        
    }
}
