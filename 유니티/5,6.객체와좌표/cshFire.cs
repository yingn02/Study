using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cshFire : MonoBehaviour
{
    private float bulletSpeed = 1000.0f;
    private Transform thisTransform;
    // Use this for initialization
    void Start() //생성이 되자 마자
    {
        thisTransform = GetComponent<Transform>(); //Tramsform을 얻어와라
        FireBullet(); //발사되라
    }

    void FireBullet()
    {
        GetComponent<Rigidbody>().AddForce(thisTransform.forward * bulletSpeed); //앞방향으로 힘을 가해라 (deltaTime을 곱하면 안된다)
    }


    // Update is called once per frame
    void Update()
    {
        
    }
}
