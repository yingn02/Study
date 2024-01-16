using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cshPysic : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
		if (Input.GetKey(KeyCode.UpArrow)) //Getkey는 키 입력이 1번만 적용되는 게 아니라 누적되는거라 Time.deltaTime를 써줘야한다
		{
			//오브젝트로부터 rigid body 를 얻어오고, 앞방향으로 300만큼 계속 이동하라
			//힘을 '추가'하는거라 가속도가 붙음 (AddForce)
			GetComponent<Rigidbody>().AddForce(Vector3.forward * 300 * Time.deltaTime);  
		}
		if (Input.GetKey(KeyCode.DownArrow))
		{
			GetComponent<Rigidbody>().AddForce(Vector3.back * 300 * Time.deltaTime);
		}
		if (Input.GetKey(KeyCode.LeftArrow))
		{
			GetComponent<Rigidbody>().AddForce(Vector3.left * 300 * Time.deltaTime);
		}
		if (Input.GetKey(KeyCode.RightArrow))
		{
			GetComponent<Rigidbody>().AddForce(Vector3.right * 300 * Time.deltaTime);
		}
		if (Input.GetKey(KeyCode.U))
		{
			GetComponent<Rigidbody>().AddForce(Vector3.up * 300 * Time.deltaTime);
		}
		if (Input.GetKey(KeyCode.D))
		{
			GetComponent<Rigidbody>().AddForce(Vector3.down * 300 * Time.deltaTime);
		}

	}
}
