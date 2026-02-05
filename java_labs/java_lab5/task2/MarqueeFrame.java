import javax.swing.*;
import java.awt.*;

public class MarqueeFrame extends JFrame {

    private JLabel marqueeLabel;
    private int x;

    public MarqueeFrame() {
        setTitle("Text Marquee");
        setSize(400, 150);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        // Blue background
        getContentPane().setBackground(Color.BLUE);
        setLayout(null); // IMPORTANT for movement

        marqueeLabel = new JLabel("Welcom to Marquee Application,using java."); //max = 50 chars
        marqueeLabel.setFont(new Font("Arial", Font.BOLD, 16));
        marqueeLabel.setForeground(Color.WHITE);

        add(marqueeLabel);

        // Start position (outside the frame on the right)
        x = getWidth();
        marqueeLabel.setBounds(x, 50, 350, 30);

        // Timer for animation
        Timer timer = new Timer(30, e -> moveText());
        timer.start();

        setVisible(true);
    }

    private void moveText() {
        x -= 2; // speed (smaller = slower)
        marqueeLabel.setLocation(x, 50);

        // Reset when text leaves screen
        if (x + marqueeLabel.getWidth() < 0) {
            x = getWidth();
        }
    }

    public static void main(String[] args) {
        new MarqueeFrame();
    }
}