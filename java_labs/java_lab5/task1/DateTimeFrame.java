import javax.swing.*;
import java.awt.*;
import java.text.SimpleDateFormat;
import java.util.Date;

public class DateTimeFrame extends JFrame {

    private JLabel dateTimeLabel;

    public DateTimeFrame() {
        setTitle("Date & Time");
        setSize(300, 150);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        dateTimeLabel = new JLabel();
        dateTimeLabel.setHorizontalAlignment(SwingConstants.CENTER);
        dateTimeLabel.setFont(new Font("Arial", Font.BOLD, 16));
        getContentPane().setBackground(Color.YELLOW);

        add(dateTimeLabel);

        Timer timer = new Timer(1000, e -> updateDateTime());
        timer.start();

        updateDateTime();
        setVisible(true);
    }

    private void updateDateTime() {
        SimpleDateFormat formatter =
                new SimpleDateFormat("dd-MM-yyyy  HH:mm:ss");
        dateTimeLabel.setText(formatter.format(new Date()));
    }

    public static void main(String[] args) {
        new DateTimeFrame();
    }
}