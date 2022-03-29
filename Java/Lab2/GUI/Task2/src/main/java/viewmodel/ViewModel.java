package viewmodel;

import javafx.fxml.FXML;
import javafx.scene.control.CheckBox;
import javafx.scene.control.PasswordField;
import javafx.scene.control.ProgressBar;
import javafx.scene.control.ProgressIndicator;
import javafx.scene.input.MouseEvent;

public class ViewModel {
    
    @FXML
    CheckBox checkBox1, checkBox2, checkBox3;

    @FXML
    ProgressIndicator progressIndicator;

    @FXML
    PasswordField passwordField;

    @FXML
    ProgressBar progressBar;

    public void onClick(MouseEvent event) {
        if(event.getSource() == checkBox1) {
            if(checkBox1.isSelected()) {
                progressIndicator.setVisible(true);
            }
            else {
                progressIndicator.setVisible(false);
            }
        } else if(event.getSource() == checkBox2) {
            if(checkBox2.isSelected()) {
                passwordField.setVisible(true);
            }
            else {
                passwordField.setVisible(false);
            }
        }
        else if (event.getSource() == checkBox3) {
            if(checkBox3.isSelected()) {
                progressBar.setVisible(true);
            }
            else {
                progressBar.setVisible(false);
            }
        }
    }
}
