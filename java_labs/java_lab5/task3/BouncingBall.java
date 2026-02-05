import javax.swing.*;
import java.awt.*;

public class BouncingBall extends JFrame {

    public BouncingBall() {
        setTitle("Bouncing Ball");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        add(new BallPanel());
        setVisible(true);
    }

    public static void main(String[] args) {
        new BouncingBall();
    }
}

class BallPanel extends JPanel {

    private int x = 50, y = 50;
    private int dx = 2, dy = 2;
    private final int BALL_SIZE = 30;

    public BallPanel() {
        setBackground(Color.BLUE);

        Timer timer = new Timer(10, e -> moveBall());
        timer.start();
    }

    private void moveBall() {
        x += dx;
        y += dy;

        // Bounce from left & right
        if (x <= 0 || x >= getWidth() - BALL_SIZE) {
            dx = -dx;
        }

        // Bounce from top & bottom
        if (y <= 0 || y >= getHeight() - BALL_SIZE) {
            dy = -dy;
        }

        repaint();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.WHITE);
        g.fillOval(x, y, BALL_SIZE, BALL_SIZE);
    }
}