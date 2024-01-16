using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cs_player : MonoBehaviour
{
    public GameObject prefab; //프리펩


    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.A)) //A 누르면
        {
            float rnd = Random.Range(0.0f, 0.5f); //0 ~ 0.5 사이의 난수를 발생시키고 rnd에 대입 
            this.transform.position = new Vector3(0.0f, 1.0f, rnd); //this(player)의 포지션을 지우고 새로 선언 
        }


        if (Input.GetKeyDown(KeyCode.B))
        {
            float rnd = Random.Range(0.0f, 360.0f);
            this.transform.rotation = Quaternion.Euler(rnd, 0.0f, 0.0f); //x축을 기준으로 회전

        }

        if (Input.GetKey(KeyCode.UpArrow))
        {
            this.transform.Translate(new Vector3(0.0f, 0.0f, 0.1f * 3.0f * Time.deltaTime)); //이동 (순간이동이 아닌), 방향(벡터)과 속도(스칼라)
        }

        if (Input.GetKey(KeyCode.DownArrow))
        {
            this.transform.Translate(new Vector3(0.0f, 0.0f, -0.1f * 3.0f * Time.deltaTime)); //이동 (순간이동이 아닌), 방향(벡터)과 속도(스칼라)
        }

        if (Input.GetKey(KeyCode.R))
        {
            this.transform.Rotate(1.0f * 90.0f * Time.deltaTime, 0.0f, 0.0f); //1초 후 x축으로 90도씩
        }

        if (Input.GetKey(KeyCode.L))
        {
            this.transform.Rotate(1.0f * -90.0f * Time.deltaTime, 0.0f, 0.0f); //1초 후 x축으로 -90도씩
        }

        if (Input.GetMouseButtonDown(0)) //프리펩, 마우스 왼쪽버튼
        {
            GameObject go = GameObject.Instantiate(prefab) as GameObject; //Instantiate: 프리펩을 복제하는 함수
            go.transform.position = new Vector3(Random.Range(-2.0f, 2.0f), 1.0f, 1.0f);
        }

    }
}
