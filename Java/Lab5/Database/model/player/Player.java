package model.player;

import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;

public class Player {
    
    private SimpleStringProperty nickname;
    private SimpleIntegerProperty score;
    private SimpleIntegerProperty id;

    public Player(String nickname, int score, int id) {
        this.nickname = new SimpleStringProperty(nickname);
        this.score = new SimpleIntegerProperty(score);
        this.id = new SimpleIntegerProperty(id);
    }

    public void setNickname(String nickname) {
        this.nickname.set(nickname);
    }

    public void setScore(int score) {
        this.score.set(score);
    }

    public String getNickname() {
        return nickname.get();
    }

    public int getScore() {
        return score.get();
    }

    public int getId() {
        return id.get();
    }

    public void setId(int id) {
        this.id.set(id);
    }
}
