package model.util;
import java.io.FileInputStream;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Properties;

import javax.sql.rowset.CachedRowSet;
import javax.sql.rowset.RowSetProvider;

public class DBUtil {

    private static String JDBC_DRIVER;
    private static String connString;
    private static String user;
    private static String password;

    private static Connection connection = null;

    private static void getConfig(String file) throws IOException {
        Properties properties = new Properties();
        try {
            properties.load(new FileInputStream(file));
        } catch (IOException e) {
            throw e;
        }
        JDBC_DRIVER = properties.getProperty("jdbc_driver");
        connString = properties.getProperty("connection");
        user = properties.getProperty("user");
        password = properties.getProperty("password");
    }

    private static void dbConnect() throws SQLException, ClassNotFoundException, IOException {
        try {
            getConfig("db.config");
        } catch (IOException e) {
            throw e;
        }
        try {
            Class.forName(JDBC_DRIVER);
        } catch (ClassNotFoundException e) {
            throw e;
        }
        try {
            connection = DriverManager.getConnection(connString, user, password);
        } catch (SQLException e) {
            throw e;
        }
    }

    private static void dbDisconnect() throws SQLException {
        try {
            if (connection != null) {
                connection.close();
            }
        } catch (SQLException e) {
            throw e;
        }
    }

    public static ResultSet dbExecuteQuery(String query) throws Exception {
        Statement statement = null;
        ResultSet resultSet = null;
        CachedRowSet crs;
        try {
            dbConnect();
            statement = connection.createStatement();
            resultSet = statement.executeQuery(query);
            crs = RowSetProvider.newFactory().createCachedRowSet();
            crs.populate(resultSet);
        } catch (ClassNotFoundException | SQLException e) {
            throw e;
        } 
        finally {
            if (resultSet != null) {
                resultSet.close();
            }
            if (statement != null) {
                statement.close();
            }
            dbDisconnect();
        }
        return crs;
    }

    public static void dbExecuteUpdate(String update) throws Exception {
        Statement statement = null;
        try {
            dbConnect();
            statement = connection.createStatement();
            statement.executeUpdate(update);
        } catch (SQLException | ClassNotFoundException e) {
            throw e;
        } finally {
            if (statement != null) {
                statement.close();
            }
            dbDisconnect();
        }
    }
}
