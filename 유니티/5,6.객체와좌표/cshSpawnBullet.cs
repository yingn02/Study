using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cshSpawnBullet : MonoBehaviour
{
	public Transform Bullet; //��ü����ð���
	public float fireTime = 1.0f; //1�ʿ� �ѹ��� 
	public float firePassTime = 0.0f;
	public Transform BulletFirePos; //��ü����ð���

    public Transform LookatObj; //�ٶ� ��ü

    // Update is called once per frame
    void Update()
	{
		if (firePassTime >= fireTime) //1�ʰ� ������
		{
			Instantiate(Bullet, BulletFirePos.position, BulletFirePos.rotation); //�������� �Ѿ��� �����ض�
			firePassTime = 0.0f; //�߻��ϸ� Ÿ�̸� �ʱ�ȭ
		}
		else
		{
			firePassTime += Time.deltaTime; //Ÿ�̸�
		}

        transform.LookAt(LookatObj); //�ٶ� ��ü�� �ٶ󺸱�

    }

}
