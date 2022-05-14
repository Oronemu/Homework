package model.player;
import java.sql.ResultSet;
import java.sql.SQLException;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import model.util.DBUtil;

public class PlayerDAO {

    private static ObservableList<Player> getPlayersList(ResultSet rSet) {
        ObservableList<Player> pList = FXCollections.observableArrayList();
        try {
            while(rSet.next()) {
            Player player = new Player(rSet.getString("NICKNAME"), rSet.getInt("SCORE"), rSet.getInt("ID"));
            pList.add(player);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return pList;
    }

    public static ObservableList<Player> getAll() throws Exception {
        String query = "SELECT * FROM PLAYERS";
        try {
            ResultSet rSet = DBUtil.dbExecuteQuery(query);
            ObservableList<Player> pList = getPlayersList(rSet);
            return pList;
        } catch (Exception e) {
            throw e;
        }
    }

    public static void deletePlayerWithId(String id) {
        String query = "DELETE FROM PLAYERS\nWHERE ID = " + id + ";";
        try {
            DBUtil.dbExecuteUpdate(query);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void insertPlayer(String id, String nickname, String score) {
        String query = "INSERT INTO PLAYERS \nVALUES (" + 
        id + ", \'" + nickname + "\', " + score + ");";
        try {
            DBUtil.dbExecuteUpdate(query);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
