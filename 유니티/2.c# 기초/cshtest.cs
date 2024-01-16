using System.Collections; //#include 대신 이렇게쓴다
using System.Collections.Generic;
using UnityEngine;

public class cshtest : MonoBehaviour //MonoBehaviour이라는 부모로 부터 상속받는다 //클래스이름 = 파일명 꼭 지켜라 //파일을 오브젝트에 끌어놓으면 적용가능
{
    public int num=20;
    //private int num = 20; //private 가 디폴트임
    //상속받은애가 접근가능하도록 protect를 적을 수도 있겠지만 상속할 일이 별로 없다

    // Start is called before the first frame update
    void Start() //시작할 때 (부모가 가지고 있던 걸 재정의하는 것이므로 채우지 않아도 실행이 되긴함)
    {
        //Debug.Log("Start");
        Debug.Log(num);
    }

    // Update is called once per frame
    void Update() //장면이 바뀔 때 마다 호출됨, 고사양컴퓨터일수록 자주 호출됨
    {
       // Debug.Log("Update");
    }
}
