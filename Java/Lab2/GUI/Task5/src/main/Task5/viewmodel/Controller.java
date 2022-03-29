package viewmodel;

import javafx.fxml.FXML;
import javafx.scene.control.RadioButton;
import javafx.scene.control.ToggleGroup;
import javafx.scene.text.Text;

public class Controller {

    @FXML
    private RadioButton a1, a2, a3;

    @FXML
    private RadioButton b1, b2, b3;

    @FXML
    private RadioButton c1, c2, c3;

    @FXML
    private Text result;

    private ToggleGroup one;
    private ToggleGroup two;
    private ToggleGroup three;

    public void init() {
        one = new ToggleGroup();
        a1.setToggleGroup(one);
        a2.setToggleGroup(one);
        a3.setToggleGroup(one);
        two = new ToggleGroup();
        b1.setToggleGroup(two);
        b2.setToggleGroup(two);
        b3.setToggleGroup(two);
        three = new ToggleGroup();
        c1.setToggleGroup(three);
        c2.setToggleGroup(three);
        c3.setToggleGroup(three);
    }

    public void onClick() {
        RadioButton A1 = (RadioButton)one.getSelectedToggle();
        RadioButton B1 = (RadioButton)two.getSelectedToggle();
        RadioButton C1 = (RadioButton)three.getSelectedToggle();
        result.setText(A1.getText() + ',' + B1.getText() + ',' + C1.getText());
    }

}
