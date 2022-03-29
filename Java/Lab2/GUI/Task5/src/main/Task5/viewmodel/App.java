package viewmodel;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import java.io.IOException;

public class App extends Application {

    private static Scene scene;

    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/view/Main.fxml"));
        scene = new Scene(loader.load());
        stage.setScene(scene);
        ((Controller)loader.getController()).init();
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }

}