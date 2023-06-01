# Smart Object Interface

This application contains the Gui application written in javafx to allow easy communication 
with the smart object. It is hardly connected with the smart object driver.

## Run the project

This project was written using java 19 and javaFX, it is therefore required to dispose of a compatible 
version of java. The project use a maven systems to manage the different dependencies.

To launch the application you can directly execute the SmartObjectInterface.jar.

```
java -jar .\SmartObjectInterface.jar
```

## Usage

After launching the project, and being on the same Wi-Fi network as the smart objects,
it is possible to:
1. Add a smart-object
To add a smart object to the possible interaction you have to click on the button "Add",fill
the ip address of the smart object in the text box validate, and then actualize.
2. Select a smart-object
Select a smart object in the table, touch the button "Select". 
3. Select a group
Click on the button "Select Group" and choose the group you want to interact with.
4. Select all the smart object
To select all the smart object just click on the button "Select All".

After entering in one of the different communication mode, all these different actions are possible:
1. Change the color of the led,
2. Change the led configuration,
3. Change the brightness,
4. Change the group (only available for the "selected smart object" interface),
5. Launch a given mission,
6. Start the ground color sensor calibration (on black or white),
7. Start calibration of the accelerometer,
8. Send a message freely over the TCP connection.

## Source Code

The source code containing the javafx code is in the src/main/java directory, while all the FXML
files are in the src/main/resources/InterfaceCode directory.


