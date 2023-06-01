package InterfaceCode;

import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

public class SmartObject {
    private int color;
    private int group;
    private String Configuration;
    private int brightness;
    private int mission;
    private String Id; // Smart object identified by their id
//    private String Ipaddress;


    // Initialize a smart object
    protected void CreateSO(String identifier) {
        this.Id=identifier;
        this.SetGroup(0);
        this.color= 0;
        this.Configuration ="11111111";
        this.brightness=255;
        this.mission = 1;


    }

    protected void SetGroup(int grp) {
        this.group = grp;
    }

    protected void SetColor(String id, int color) throws IOException{
        this.color = color;
        SendColorMessage(id);

    }


    protected void SetMission(String id, int mission) throws IOException{
        this.mission = mission;
        String message_type = "5"; // clear mission
        String mission_message;
        if (mission!=0) {
            if (mission == 1) {mission_message=  (mission) + this.color + "0000000000" ; }
            else {
                mission_message=  (mission) + "00000000000" ;}
        } else {
            mission_message = "000000000000";
        }

        System.out.println(mission_message);
        SendMessageSmartObject(id,message_type, mission_message);

    }
    protected void SetConfig(String id, String config) throws IOException {
        this.Configuration = config;
        SendColorMessage(id);
    }
    protected void SetBrightness(String id, int brightness) throws IOException {
        this.brightness =brightness;
        SendColorMessage(id);
    }

    protected void SendCalibrationMessage(String id, int calibration) throws IOException {
        String message_type = "6"; // clear mission
        //String message_example = "11000" ;// red, fully lit

        String calibration_message=  String.valueOf(calibration) ;


        SendMessageSmartObject(id,message_type,calibration_message);
    }


    private void SendColorMessage(String id) throws IOException {

        String message_type = "4"; // clear mission
        //String message_example = "11000" ;// red, fully lit
        String color_message;
        if (color !=0) {
            color_message=  String.valueOf(getColor()) + getBrightness() + getConfiguration()  ;
        } else {
            color_message = "000000000000";
        }

        SendMessageSmartObject(id,message_type,color_message);
    }

    // Send a
    protected void SendMessageSmartObject(String id, String message_type, String message ) throws IOException {

        String IpHost = id;
        id = "1";
        try (Socket socket = new Socket(IpHost, 3500)) {
            DataOutputStream dOut = new DataOutputStream(socket.getOutputStream());
            // Send the id
            dOut.write((id.getBytes(StandardCharsets.US_ASCII)), 0, id.getBytes(StandardCharsets.US_ASCII).length);
            dOut.flush();
            // Send type of request
            dOut.write((message_type.getBytes(StandardCharsets.US_ASCII)), 0, message_type.getBytes(StandardCharsets.US_ASCII).length);
            dOut.flush(); // Send off the data
            // Send the color config
            dOut.write((message.getBytes(StandardCharsets.US_ASCII)), 0, message.getBytes(StandardCharsets.US_ASCII).length);
            dOut.flush(); // Send off the data
        } catch (IOException e) {
            throw new IOException(e);
        }
    }

    protected void SendMessage(String message) throws IOException{
        String IpHost = this.Id;
        try (Socket socket = new Socket(IpHost, 3500)) {
            DataOutputStream dOut = new DataOutputStream(socket.getOutputStream());
            // Send the message
            dOut.write((message.getBytes(StandardCharsets.US_ASCII)), 0, message.getBytes(StandardCharsets.US_ASCII).length);
            dOut.flush();
        } catch (IOException e) {
            throw new IOException(e);
        }
    }


    public int getColor() {
        return color;
    }
    public int getGroup() {
        return group;
    }
    public String getId() {
        return Id;
    }
    public String getConfiguration(){
        return Configuration;
    }
    public int getBrightness(){
        return brightness;
    }
    public int getMission(){
        return mission;
    }
}
