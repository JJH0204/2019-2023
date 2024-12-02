using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player_MOV : MonoBehaviour
{
    //플레이어 이동 구현
    public Character player;
    public float Speed;
    public Vector3 vDirResult;
    public GameObject SeeTarget;

    private void OnDrawGizmos()
    {
        Gizmos.DrawWireSphere(this.transform.position, this.gameObject.GetComponent<Character>().fSeeRadius);
    }
    private void FixedUpdate()
    {
        int nLayer = 1 << LayerMask.NameToLayer("Monster");
        Character thisChar = this.gameObject.GetComponent<Character>();

        Collider2D[] Seecollider = Physics2D.OverlapCircleAll(this.transform.position, thisChar.fSeeRadius, nLayer);

        if (Seecollider != null)
        {
            SeeTarget = Seecollider.gameObject;
            Debug.Log("SeeTarget : " + SeeTarget.name);
        }
        else
        {
            if (SeeTarget)
            {
                if (SeeTarget.tag == "Monster")
                {
                    SeeTarget = null;
                    Debug.Log("SeeFixedUpdate: null");
                }
                else
                    Debug.Log("SeeTarget:" + SeeTarget);
            }
            Debug.Log("SeeTarget is null");
        }

        if(SeeTarget)
        {
            Vector3 vTargetPos = SeeTarget.gameObject.transform.position;
            Vector3 vPlayerPos = this.transform.position;

            Vector3 vDist = vTargetPos - vPlayerPos;
            Vector3 vDir = vDist.normalized;
            vDirResult = vDir;
        }
    }
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        player = this.gameObject.GetComponent<Character>();
        Speed = player.fSpeed;

        if (Input.GetKey(KeyCode.W))
            gameObject.transform.position += Vector3.up * Time.deltaTime*Speed;

        if (Input.GetKey(KeyCode.A))
            gameObject.transform.position += Vector3.left * Time.deltaTime*Speed;

        if (Input.GetKey(KeyCode.D))
            gameObject.transform.position += Vector3.right * Time.deltaTime*Speed;

        if (Input.GetKey(KeyCode.S))
            gameObject.transform.position += Vector3.down * Time.deltaTime*Speed;
    }
}
