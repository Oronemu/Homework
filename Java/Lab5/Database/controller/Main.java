package controller;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;

public class Main extends Application {

    public static void main(String[] args) {
        launch();
    }

    @Override
    public void start(Stage stage) throws Exception {
        BorderPane pane = FXMLLoader.load(getClass().getResource("../view/Main.fxml"));
        stage.setScene(new Scene(pane));
        stage.show();
    }
}