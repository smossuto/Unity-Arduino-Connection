using UnityEngine;
using System.Collections;
using System.IO.Ports;

// testing out the joystick + arduino
// public class TestConnection : MonoBehaviour
// {
//     SerialPort data_stream = new SerialPort("COM4", 9600);
//     public string receivedstring;
//     public GameObject test_data;
//     public Rigidbody rb;
//     //rb = getcomponent<Rigidbody>();
//     public float sensitivity = 0.01f;

//     public string[] datas;

//     void Start()
//     {
//         rb = GetComponent<Rigidbody>();   //added this line
//         Debug.Log("hello world");
//         data_stream.Open();
//         Debug.Log("hello world again");
//     }

//     void Update()
//     {
//         receivedstring = data_stream.ReadLine();
//         //Debug.Log(receivedstring);

//         string[] datas = receivedstring.Split(',');
//         //Debug.Log(datas[0]); Debug.Log(datas[1]); Debug.Log(datas[2]);
//         rb.AddForce(0, 0, float.Parse(datas[0]) * sensitivity * Time.deltaTime, ForceMode.VelocityChange);
//         rb.AddForce(float.Parse(datas[1]) * sensitivity * Time.deltaTime, 0, 0, ForceMode.VelocityChange);
    
//         transform.Rotate(0, float.Parse(datas[2]), 0);
//     }
// }



// testing out the force sensor + arduino
public class TestConnection : MonoBehaviour
{
    SerialPort data_stream = new SerialPort("COM5", 9600);
    public string receivedstring;
    public GameObject test_data;
    public Rigidbody rb;
    //rb = getcomponent<Rigidbody>();
    public float sensitivity = 0.01f;

    public string[] datas;

    void Start()
    {
        rb = GetComponent<Rigidbody>();   //added this line
        Debug.Log("hello world");
        data_stream.Open();
        Debug.Log("hello world again");
    }

    void Update()
    {
        receivedstring = data_stream.ReadLine();
        //Debug.Log(receivedstring);

        string[] datas = receivedstring.Split(',');
        //Debug.Log(datas[0]); Debug.Log(datas[1]); Debug.Log(datas[2]);
        
        //temp = float.Parse(datas[0]) * sensitivity * Time.deltaTime
        //rb.AddForce(0, 0, temp >= 10 ? temp : 0, ForceMode.VelocityChange);
        rb.AddForce(0, 0, float.Parse(datas[0]) * sensitivity * Time.deltaTime, ForceMode.VelocityChange);
        //rb.AddForce(float.Parse(datas[1]) * sensitivity * Time.deltaTime, 0, 0, ForceMode.VelocityChange);
    
        //transform.Rotate(0, float.Parse(datas[2]), 0);
    }
}