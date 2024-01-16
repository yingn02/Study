using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cshHitBullet : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    void OnCollisionEnter(Collision coll) //collider가 들어왔을 때 호출되는 함수
    {
        if (coll.gameObject.tag == "BULLET") //나랑 쟤가 둘다  collider가 있고+  BULLET이라는 태그를 달고있는애가 오면
        {
            Destroy(coll.gameObject); //걔(불릿)를 없애라 (coll 빼면 내(벽)가 사라짐)
        }
    }

    //아군은 관통하되 벽은 관통하면 안될 때 추가하면 위에 있는 함수를 씹고 이걸 실행 (구현은 똑같음)
    void OnTriggerEnter(Collider coll) //trigger가 들어왔을 때 호출되는 함수
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
