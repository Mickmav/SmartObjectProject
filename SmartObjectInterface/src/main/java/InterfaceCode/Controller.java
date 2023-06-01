package InterfaceCode;


import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import java.io.IOException;



public class Controller {


    public TableView<SmartObject> SmartObjectTable;
    public TableColumn<SmartObject, String> IdColumn;
    public TableColumn<SmartObject, String> GroupColumn;

    static ObservableList<SmartObject> smart_object_list = FXCollections.observableArrayList();

    static ObservableList<SmartObject> smart_object_Group = FXCollections.observableArrayList();

    static ObservableList<SmartObject> actual_smart_object_list = smart_object_list;

    static SmartObject actual_smart_object= null;

    static Stage smart_object_window_stage;
    static Stage many_smart_object_window_stage;
    static Stage color_window_stage;
    static Stage mission_window_stage;
    static Stage group_color_window_stage;
    static Stage group_mission_window_stage;
    static Stage group_window_stage;
    static Stage add_to_group_window_stage;
    static Stage error_window;
    static Stage config_window_stage;
    static Stage add_smart_object_window;



    protected Stage OpenWindow(String name, int Width, int height, String title) throws IOException {
        Stage stage = new Stage();
        FXMLLoader fxmlLoader = new FXMLLoader(SmartObjectApplication.class.getResource(name));
        Scene scene = new Scene(fxmlLoader.load(), Width, height);
        stage.setTitle(title);
        stage.setScene(scene);
        stage.show();
        return stage;

    }
    // Refresh the List of smart Object
    protected void RefreshActualList(int grp){
        if (grp == -1){
            actual_smart_object_list = smart_object_list;
        }
        else {
            smart_object_Group.clear();
            for (SmartObject smart : smart_object_list){
                if (smart.getGroup() == grp)
                    smart_object_Group.add(smart);
            }
            actual_smart_object_list=smart_object_Group;
        }
    }
    protected void initializeTable(){
        SmartObjectTable.setItems(smart_object_list);
        IdColumn.setCellValueFactory(new PropertyValueFactory<>("Id"));
        GroupColumn.setCellValueFactory(new PropertyValueFactory<>("Group"));
        SmartObjectTable.getColumns().setAll(IdColumn, GroupColumn);
    }

    private static void CloseOpenedWindow() {
        if (many_smart_object_window_stage != null) {many_smart_object_window_stage.close();}
        if (smart_object_window_stage != null) {smart_object_window_stage.close();}
    }

    @FXML
    protected void Actualize() {initializeTable();}
    @FXML
    protected void Search() throws IOException {
        add_smart_object_window = OpenWindow("AddNewSmartObject.fxml", 500, 200, "Add");
    }

    // Initialization of a smart-object
    @FXML
    protected void CreateSmartObject(){
        SmartObject SO = new SmartObject();
        TextField id_msg =  (TextField) add_smart_object_window.getScene().getRoot().lookup("#IdMessage");
        String id = id_msg.getText();
        SO.CreateSO(id);
        smart_object_list.add(SO);
        add_smart_object_window.close();
    }


    @FXML
    protected void SendError(String err_msg) throws IOException {
        error_window= OpenWindow("ErrorWindow.fxml",400,50,"Error");
        Text txt_err = (Text) error_window.getScene().getRoot().lookup("#TextError");
        txt_err.setText("Error: " + err_msg);
    }


    /*
    * Interaction with just 1 selected smart object
    */

    @FXML
    protected void Select() throws IOException {
        actual_smart_object = SmartObjectTable.getSelectionModel().getSelectedItem();
        if (actual_smart_object == null) {
            System.out.println("Error no selected Smart-Object");
            SendError("no selected Smart-Object");
        }
        else {
            CloseOpenedWindow();
            smart_object_window_stage = OpenWindow("SmartObjectWindow.fxml",
                    600,400, "Smart-Objects");
            Text txt_id = (Text) smart_object_window_stage.getScene().getRoot().lookup("#TextId");
            txt_id.setText("Id: " + actual_smart_object.getId());
            Text txt_grp = (Text) smart_object_window_stage.getScene().getRoot().lookup("#TextGroup");
            txt_grp.setText("Group: "+ actual_smart_object.getGroup());
            Text txt_clr = (Text) smart_object_window_stage.getScene().getRoot().lookup("#TextColor");
            txt_clr.setText("Color: " +actual_smart_object.getColor());
            Text txt_mis = (Text) smart_object_window_stage.getScene().getRoot().lookup("#TextMission");
            txt_mis.setText("Mission: " +actual_smart_object.getMission());
            Text txt_config = (Text) smart_object_window_stage.getScene().getRoot().lookup("#TextConfig");
            txt_config.setText("Config: " +actual_smart_object.getConfiguration());
            Text txt_bright = (Text) smart_object_window_stage.getScene().getRoot().lookup("#TextBrightness");
            txt_bright.setText("Brightness: " +actual_smart_object.getBrightness());
        }
    }

    // Color Interaction
    @FXML
    protected void SetColorWindow() throws IOException {
        color_window_stage = OpenWindow("ColorWindow.fxml",400,200, "Smart-Objects Color");
    }
    @FXML
    protected void SetColor0() throws IOException {SetColor(0);}
    @FXML
    protected void SetColor1() throws IOException {SetColor(1);}
    @FXML
    protected void SetColor2() throws IOException {SetColor(2);}
    @FXML
    protected void SetColor3() throws IOException {SetColor(3);}
    @FXML
    protected void SetColor(int color) throws IOException {
        actual_smart_object.SetColor(actual_smart_object.getId(), color);
        color_window_stage.close();
        Text txt_clr = (Text) smart_object_window_stage.getScene().getRoot().lookup("#TextColor");
        txt_clr.setText("Color:" + actual_smart_object.getColor());
    }

    // Mission Interaction
    @FXML
    protected void SetMissionWindow() throws IOException {
        mission_window_stage = OpenWindow("MissionWindow.fxml",400,200, "Smart-Objects Color");
    }
    @FXML
    protected void SetMission1() throws IOException {SetMission(1);}
    @FXML
    protected void SetMission2() throws IOException {SetMission(2);}
    @FXML
    protected void SetMission3() throws IOException {SetMission(3);}
    @FXML
    protected void SetMissionExample() throws IOException {SetMission(8);}
    @FXML
    protected void SetMissionStop() throws IOException {SetMission(9);}
    @FXML
    protected void SetMission(int mission) throws IOException {
        actual_smart_object.SetMission(actual_smart_object.getId(), mission);
        mission_window_stage.close();
        Text txt_mis = (Text) smart_object_window_stage.getScene().getRoot().lookup("#TextMission");
        txt_mis.setText("Mission: " +  actual_smart_object.getMission());
    }

    // Interaction on the led config
    @FXML
    protected void SetConfigWindow() throws IOException {
        config_window_stage = OpenWindow("ConfigWindow.fxml",600,400, "Smart-Objects Color");
    }
    @FXML
    protected void SetConfig1() throws IOException {SetConfig(1);}
    @FXML
    protected void SetConfig2() throws IOException {SetConfig(2);}
    @FXML
    protected void SetConfig3() throws IOException {SetConfig(3);}
    @FXML
    protected void SetConfig4() throws IOException {SetConfig(4);}
    @FXML
    protected void SetConfig5() throws IOException {SetConfig(5);}
    @FXML
    protected void SetConfig6() throws IOException {SetConfig(6);}
    @FXML
    protected void SetConfig7() throws IOException {SetConfig(7);}
    @FXML
    protected void SetConfig8() throws IOException {SetConfig(8);}
    @FXML
    protected void SetConfig(int config) throws IOException {
        String configuration = changeConfig(config, actual_smart_object.getConfiguration());
        actual_smart_object.SetConfig(actual_smart_object.getId(), configuration);
        //config_window_stage.close();
        Text txt_config = (Text) smart_object_window_stage.getScene().getRoot().lookup("#TextConfig");
        txt_config.setText("Config: " +  actual_smart_object.getConfiguration());
    }

    String changeConfig(int config, String prevConfig){
        String configuration = prevConfig;
            if (config == 1){
            if (configuration.charAt(0) == '1' ){
                configuration=  "0"+ configuration.substring(config);
            }else {
                configuration=  "1"+ configuration.substring(config);
            }
        }
            else {
            if (configuration.charAt(config-1) == '1' ){
                configuration= configuration.substring(0,config-1) + "0"+ configuration.substring(config);
            }else {
                configuration= configuration.substring(0,config-1) + "1"+ configuration.substring(config);
            }
        }
        return configuration;
    }


    @FXML
    protected void SendMessage() throws IOException{
        TextField txt_msg = (TextField) smart_object_window_stage.getScene().getRoot().lookup("#Message");
        String message = txt_msg.getText();
        actual_smart_object.SendMessage(message);
    }
    @FXML
    protected void SetBrightness() throws IOException {
        TextField txt_bright_msg = (TextField) smart_object_window_stage.getScene().getRoot().lookup("#BrightnessMessage");
        int brightness = Integer.parseInt(txt_bright_msg.getText());
        actual_smart_object.SetBrightness(actual_smart_object.getId(), brightness);
        Text txt_bright = (Text) smart_object_window_stage.getScene().getRoot().lookup("#TextBrightness");
        txt_bright.setText("Brightness: " +actual_smart_object.getBrightness());
    }

    @FXML
    protected void SensorCalibrationWhite() throws IOException{
        actual_smart_object.SendCalibrationMessage(actual_smart_object.getId(), 1);

    }

    @FXML
    protected void SensorCalibrationWhiteBlack() throws IOException{
        actual_smart_object.SendCalibrationMessage(actual_smart_object.getId(), 2);

    }

    @FXML
    protected void SensorCalibrationAccel() throws IOException{
        actual_smart_object.SendCalibrationMessage(actual_smart_object.getId(), 3);

    }


    /*
    * Interaction on many smart object
    * */

    // Grouping methods
    @FXML
    protected void AddToGroup0() {AddToGroup(0);}
    @FXML
    protected void AddToGroup1() {AddToGroup(1);}
    @FXML
    protected void AddToGroup2() {AddToGroup(2);}
    @FXML
    protected void AddToGroup3() {AddToGroup(3);}
    @FXML
    protected void AddToGroup(int grp) {
        actual_smart_object.SetGroup(grp);
        Text txt_clr = (Text) smart_object_window_stage.getScene().getRoot().lookup("#TextGroup");
        txt_clr.setText("Group: " + actual_smart_object.getGroup());
        add_to_group_window_stage.close();
    }

    @FXML
    protected void SetGroupColorWindow() throws IOException {
        group_color_window_stage = OpenWindow("GroupColorWindow.fxml",
                300,150, "Smart-Objects Color");
    }
    @FXML
    protected void SelectGroupWindow() throws IOException {
        group_window_stage = OpenWindow("GroupWindow.fxml", 300,150, "Select Group");
    }

    @FXML
    protected void SelectGroup0() throws IOException {SelectGroup(0);}
    @FXML
    protected void SelectGroup1() throws IOException {SelectGroup(1);}
    @FXML
    protected void SelectGroup2() throws IOException {SelectGroup(2);}
    @FXML
    protected void SelectGroup3() throws IOException {SelectGroup(3);}
    @FXML
    protected void AddToGroupWindow() throws IOException {
        add_to_group_window_stage = OpenWindow("AddToGroupWindow.fxml", 400,200, "Add to Group");
    }

    @FXML
    protected void SelectGroup(int grp) throws IOException {
        RefreshActualList(grp);
        CloseOpenedWindow();
        if (actual_smart_object_list.size()!=0){
            many_smart_object_window_stage = OpenWindow("ManySmartObjectWindow.fxml",
                    400,500, "Many Smart-Object");
            Text txt_grp = (Text) many_smart_object_window_stage.getScene().getRoot().lookup("#TextGroup");
            txt_grp.setText("Group: "+ grp);
            Text txt_clr = (Text) many_smart_object_window_stage.getScene().getRoot().lookup("#TextColor");
            txt_clr.setText("Color: "+ actual_smart_object_list.get(0).getColor());
            Text txt_mis= (Text) many_smart_object_window_stage.getScene().getRoot().lookup("#TextMission");
            txt_mis.setText("Mission: "+ actual_smart_object_list.get(0).getMission());
        }
        else {System.out.println("Error group is empty");SendError("no selected Smart-Object");}
    }

    // Action on all smart object
    @FXML
    protected void SelectAll() throws IOException {
        RefreshActualList(-1);
        CloseOpenedWindow();
        if (actual_smart_object_list.size()!=0) {
            many_smart_object_window_stage = OpenWindow("ManySmartObjectWindow.fxml",
                    400, 500, "Many Smart-Objects");
            Text txt_grp = (Text) many_smart_object_window_stage.getScene().getRoot().lookup("#TextGroup");
            txt_grp.setText("All Smart-Objects");
            Text txt_clr = (Text) many_smart_object_window_stage.getScene().getRoot().lookup("#TextColor");
            txt_clr.setText("Color: "+ actual_smart_object_list.get(0).getColor());
        }
        else {System.out.println("Error no connected Smart-Object");SendError("no connected Smart-Object");}
    }

    @FXML
    protected void SetGroupColor0() throws IOException {SetGroupColor(0);}
    @FXML
    protected void SetGroupColor1() throws IOException {SetGroupColor(1);}
    @FXML
    protected void SetGroupColor2() throws IOException {SetGroupColor(2);}
    @FXML
    protected void SetGroupColor3() throws IOException {SetGroupColor(3);}
    @FXML
    protected void SetGroupColor(int clr) throws IOException {

        for (SmartObject smart : actual_smart_object_list){smart.SetColor(smart.getId(), clr); }

        group_color_window_stage.close();
        Text txt_clr = (Text) many_smart_object_window_stage.getScene().getRoot().lookup("#TextColor");
        txt_clr.setText("Color: "+ actual_smart_object_list.get(0).getColor());
    }

    // Mission interaction
    @FXML
    protected void SetGroupMissionWindow() throws IOException {
        group_mission_window_stage = OpenWindow("GroupMissionWindow.fxml",
                300,300, "Smart-Objects Mission");
    }
    @FXML
    protected void SetGroupMission1() throws IOException {SetGroupMission(1);}
    @FXML
    protected void SetGroupMission2() throws IOException {SetGroupMission(2);}
    @FXML
    protected void SetGroupMission3() throws IOException {SetGroupMission(3);}
    @FXML
    protected void SetGroupMissionExample() throws IOException {SetGroupMission(8);}
    @FXML
    protected void SetGroupMissionStop() throws IOException {SetGroupMission(9);}
    @FXML
    protected void SetGroupMission(int mission) throws IOException {
       for (SmartObject smart : actual_smart_object_list){smart.SetMission(smart.getId(),mission); }

        group_mission_window_stage.close();
        Text txt_mis = (Text) many_smart_object_window_stage.getScene().getRoot().lookup("#TextMission");
        txt_mis.setText("Mission: "+ actual_smart_object_list.get(0).getMission());
    }

    // Interaction with group
    @FXML
    protected void SetGroupConfigWindow() throws IOException {
        config_window_stage = OpenWindow("GroupConfigWindow.fxml",600,400, "Smart-Objects Config");
    }
    @FXML
    protected void SetGroupConfig1() throws IOException {SetGroupConfig(1);}
    @FXML
    protected void SetGroupConfig2() throws IOException {SetGroupConfig(2);}
    @FXML
    protected void SetGroupConfig3() throws IOException {SetGroupConfig(3);}
    @FXML
    protected void SetGroupConfig4() throws IOException {SetGroupConfig(4);}
    @FXML
    protected void SetGroupConfig5() throws IOException {SetGroupConfig(5);}
    @FXML
    protected void SetGroupConfig6() throws IOException {SetGroupConfig(6);}
    @FXML
    protected void SetGroupConfig7() throws IOException {SetGroupConfig(7);}
    @FXML
    protected void SetGroupConfig8() throws IOException {SetGroupConfig(8);}
    @FXML
    protected void SetGroupConfig(int config) throws IOException {
        int i=0;
        String configuration ="11111111";
        for (SmartObject smart : actual_smart_object_list){
            if (i==0){configuration = changeConfig(config, smart.getConfiguration());i++;}

                smart.SetConfig(smart.getId(), configuration);
            }
        Text txt_config = (Text) many_smart_object_window_stage.getScene().getRoot().lookup("#TextConfig");
        txt_config.setText("Config: " +  actual_smart_object_list.get(0).getConfiguration());
    }

    @FXML
    protected void SetGroupBrightness() throws IOException {
        TextField txt_bright_msg = (TextField) many_smart_object_window_stage.getScene().getRoot().lookup("#BrightnessMessage");
        int brightness = Integer.parseInt(txt_bright_msg.getText());

        for (SmartObject smart : actual_smart_object_list){smart.SetMission(smart.getId(),brightness); }

        Text txt_bright = (Text) many_smart_object_window_stage.getScene().getRoot().lookup("#TextBrightness");
        txt_bright.setText("Brightness: " + brightness);
    }

    @FXML
    protected void SendGroupMessage() throws IOException{
        TextField txt_msg = (TextField) many_smart_object_window_stage.getScene().getRoot().lookup("#Message");
        String message = txt_msg.getText();

        for (SmartObject smart : actual_smart_object_list){
            smart.SendMessage(message);
        }
    }

    @FXML
    protected void GroupSensorCalibrationWhite() throws IOException{
            for (SmartObject smart : actual_smart_object_list){
                smart.SendCalibrationMessage(smart.getId(), 1);
            }
    }

    @FXML
    protected void GroupSensorCalibrationWhiteBlack() throws IOException{
            for (SmartObject smart : actual_smart_object_list){
                smart.SendCalibrationMessage(smart.getId(),2);
            }
    }

    @FXML
    protected void GroupSensorCalibrationAccel() throws IOException{
        for (SmartObject smart : actual_smart_object_list){
            smart.SendCalibrationMessage(smart.getId(), 3);
        }
    }

}