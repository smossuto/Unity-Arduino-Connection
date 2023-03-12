# Project to test arduino to unity connection
## 1. Clone the repo.

</br>

## 2. Load the desired arduino code onto your arduino
- Arduino code is in the ARDUINO CODE folder. (_testunityconnection.ino_ is the joystick code)
    - Might have to install the HX711 library in arduino IDE for the force sensor code. Click on library manager to search for libraries (3rd icon on left bar).
- Test that you're getting data by opening the serial monitor (Ctrl+Shift+M shortcut). Then close it.

&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <font size="2"> <u>_Note:</u> Close the serial monitor before starting the game b/c only 1 thing can read from the arduino at once or something :skull:_ </font>

</br>

## 3. Open the project in Unity:
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <font size="2"> <u>_Note:</u> Check the COM port for your arduino. Make sure the COM in TestConnection.cs matches your arduino's COM. (this line: *SerialPort data_stream = new SerialPort("COM4", 9600);*). If not, just change it in TestConnection.cs._ </font>
- Go to Unity Hub and click "Open" and then find your cloned repo.
- Then launch the project by clicking on it in your list of projects in Unity Hub.
    - Once in Unity, click the play button (the triangle) and then switch from "Game" to "Scene" in the main window thing.
    - While looking at the "Scene" window, you should see the cube move when you move the joystick/press down on the force sensor.
        - Moving the joystick slides the cube around, pressing down on it (like a button) makes the cube spin.
        - Force sensor code only reads from one force sensor right now, so press it from the opposite direction to move backwards ("negative" force)
        - If the cube starts sliding off the screen, press "Shift+f" to make the camera lock on the cube.
    - __DONE__
    
    &nbsp;
    - At the bottom you can click on "Console" to see console logs. The first message should say "hello world - {device}".
    - In the top left "Hierarchy" panel, you can click on "Serial Data Cube" once the game is running and you can see "Receivedstring" in the "Inspector" panel on the right.
        - Receivedstring is under "Test Connection (Script)" in the Inspector panel.
        - Receivedstring is the arduino data.