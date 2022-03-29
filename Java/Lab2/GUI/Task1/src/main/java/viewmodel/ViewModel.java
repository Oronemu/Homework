package viewmodel;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import model.Model;

public class ViewModel {
    
    @FXML
    TextField textLeft;

    @FXML
    TextField textRight;

    @FXML
    Button button;

    private boolean first = false;

    public void onClick() {
        String[] res;
        res = Model.change(textLeft.getText(), textRight.getText());
        textLeft.setText(res[0]);
        textRight.setText(res[1]);
        if(first) {
            button.setText("->");
        }
        else {
            button.setText("<-");
        }
        first = !first;
    }
}
