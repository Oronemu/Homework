package viewmodel;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class App extends Application {
    
    public static void main(String[] args) {
        launch();
    }

    @Override
    public void start(Stage stage) throws Exception {
        Scene scene = FXMLLoader.load(getClass().getResource("/view/Main.fxml"));
        stage.setScene(scene);
        stage.show();
    }
}
