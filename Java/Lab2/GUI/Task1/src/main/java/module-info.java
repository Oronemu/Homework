module main {
    requires javafx.controls;
    requires javafx.fxml;
    requires javafx.graphics;

    opens viewmodel to javafx.fxml, javafx.graphics;
}
