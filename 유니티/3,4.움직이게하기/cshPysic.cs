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
		if (Input.GetKey(KeyCode.UpArrow)) //Getkey�� Ű �Է��� 1���� ����Ǵ� �� �ƴ϶� �����Ǵ°Ŷ� Time.deltaTime�� ������Ѵ�
		{
			//������Ʈ�κ��� rigid body �� ������, �չ������� 300��ŭ ��� �̵��϶�
			//���� '�߰�'�ϴ°Ŷ� ���ӵ��� ���� (AddForce)
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
