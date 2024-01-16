using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cshSpawnBullet : MonoBehaviour
{
	public Transform Bullet; //객체끌어올거임
	public float fireTime = 1.0f; //1초에 한번씩 
	public float firePassTime = 0.0f;
	public Transform BulletFirePos; //객체끌어올거임

    public Transform LookatObj; //바라볼 객체

    // Update is called once per frame
    void Update()
	{
		if (firePassTime >= fireTime) //1초가 지나면
		{
			Instantiate(Bullet, BulletFirePos.position, BulletFirePos.rotation); //프리펩인 총알을 복제해라
			firePassTime = 0.0f; //발사하면 타이머 초기화
		}
		else
		{
			firePassTime += Time.deltaTime; //타이머
		}

        transform.LookAt(LookatObj); //바라볼 객체를 바라보기

    }

}
