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

    void OnTriggerEnter(Collider coll) //불릿이 트리거 이므로 트리거함수를 씀
    {
        if (coll.gameObject.tag == "BULLET")
        {
            HP--;
            if(HP <= 0)
                Destroy(gameObject); //나(적군)를 없앤다
        }
    }


}

