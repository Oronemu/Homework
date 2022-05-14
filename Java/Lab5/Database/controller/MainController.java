package controller;

import javafx.collections.ObservableList;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.ContextMenu;
import javafx.scene.control.MenuItem;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TablePosition;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.MouseButton;
import javafx.scene.input.MouseEvent;
import model.player.Player;
import model.player.PlayerDAO;

public class MainController {
    
    @FXML
    TableView<Player> table;

    @FXML
    private TableColumn<Player, String> columnNickname;

    @FXML 
    private TableColumn<Player, Integer> columnScore;

    @FXML
    private TableColumn<Player, Integer> columnId;

    @FXML
    private TextField textId, textNickname, textScore;

    @FXML
    private void initialize() {
        columnNickname.setCellValueFactory(new PropertyValueFactory<Player, String>("Nickname"));
        columnScore.setCellValueFactory(new PropertyValueFactory<Player, Integer>("Score"));
        columnId.setCellValueFactory(new PropertyValueFactory<Player, Integer>("Id"));
        
        ContextMenu cm = new ContextMenu();
        MenuItem mi1 = new MenuItem("Добавить");
        cm.getItems().add(mi1);
        MenuItem mi2 = new MenuItem("Изменить");
        cm.getItems().add(mi2);
        MenuItem mi3 = new MenuItem("Удалить");
        cm.getItems().add(mi3);

        table.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {

        @Override
        public void handle(MouseEvent t) {
            if(t.getButton() == MouseButton.SECONDARY) {
                cm.show(table, t.getScreenX(), t.getScreenY());
            }
        }
        });

        mi1.setOnAction(event -> {
            insert();
        });

        mi3.setOnAction(event -> {
            delete();
        });

        update();
    }

    @FXML
    public void update() {
        try {
            ObservableList<Player> players = PlayerDAO.getAll();
            addPlayers(players);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void addPlayers(ObservableList<Player> players) {
        table.setItems(players);
    }

    @FXML
    public void delete() {
        String id = String.valueOf(table.getSelectionModel().getSelectedItem().getId());
        PlayerDAO.deletePlayerWithId(id);
        update();
    }

    @FXML
    public void insert() {
        PlayerDAO.insertPlayer(textId.getText(), textNickname.getText(), textScore.getText());
        textId.clear();
        textNickname.clear();
        textScore.clear();
        update();
    }
}
