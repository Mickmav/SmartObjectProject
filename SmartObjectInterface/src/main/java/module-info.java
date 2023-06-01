module InterfaceCode.demo {
    requires javafx.controls;
    requires javafx.fxml;


    opens InterfaceCode to javafx.fxml;
    exports InterfaceCode;
}