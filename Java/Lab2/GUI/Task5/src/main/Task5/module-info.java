module viewmodel {
    requires javafx.controls;
    requires javafx.fxml;

    opens viewmodel to javafx.fxml;
    exports viewmodel;
}
