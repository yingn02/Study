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
            Debug.Log(Input.mousePosition); // 클릭한 2차원의 좌표를 출력
            //얻어진 2차원의 좌표를 바탕으로
            //일치 가능성이 있는 2차원의 좌표들을 쭉 이으면
            //하나의 선이 되는데 그 선이 맵의 땅바닥과 만나고 거기로 이동시킬 수 있다
        }
    }
}
