package me.homework.mirror;

import javax.swing.*;
import java.awt.*;

public class MirrorApplet extends JApplet {

    private static final int WIDTH = 800;
    private static final int HEIGHT = 600;

    private static final int PLUS_SIZE = 20;
    private static final int DIAMOND_WIDTH = 16;
    private static final int DIAMOND_HEIGHT = 18;
    private static final int MARGIN = 10;

    private static final Color CORNER_COLOR = Color.GREEN;
    private static final Color SIDE_COLOR = Color.YELLOW;

    @Override
    public void init() {
        setSize(new Dimension(WIDTH, HEIGHT));
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);

        g.setColor(Color.BLUE);
        g.fillRect(WIDTH / 4, HEIGHT / 4, WIDTH / 2, HEIGHT / 2);
        g.setColor(Color.BLACK);
        new Diamond(WIDTH / 2, HEIGHT / 2, WIDTH / 2, HEIGHT / 2).draw(g, Color.CYAN);

        drawCorners(g);

        drawDiamondsSide(g, WIDTH / 2, HEIGHT / 4, 3 * WIDTH / 4, HEIGHT / 2);
        drawDiamondsSide(g, WIDTH / 2, HEIGHT / 4, WIDTH / 4, HEIGHT / 2);
        drawDiamondsSide(g, WIDTH / 2, 3 * HEIGHT / 4, WIDTH / 4, HEIGHT / 2);
        drawDiamondsSide(g, WIDTH / 2, 3 * HEIGHT / 4, 3 * WIDTH / 4, HEIGHT / 2);
    }

    private void drawCorners(Graphics g) {
        new Plus(WIDTH / 4, HEIGHT / 4, PLUS_SIZE, PLUS_SIZE).draw(g, CORNER_COLOR);
        new Plus(3 * WIDTH / 4, HEIGHT / 4, PLUS_SIZE, PLUS_SIZE).draw(g, CORNER_COLOR);
        new Plus(3 * WIDTH / 4, 3 * HEIGHT / 4, PLUS_SIZE, PLUS_SIZE).draw(g, CORNER_COLOR);
        new Plus(WIDTH / 4, 3 * HEIGHT / 4, PLUS_SIZE, PLUS_SIZE).draw(g, CORNER_COLOR);
    }

    private void drawDiamondsSide(Graphics g, int x1, int y1, int x2, int y2) {
        int width = x2 - x1;
        int height = y2 - y1;

        double distance = Math.sqrt(width * width + height * height);

        int numberOfShapes = (int) (distance / (Math.sqrt(DIAMOND_WIDTH * DIAMOND_WIDTH + DIAMOND_HEIGHT * DIAMOND_HEIGHT) + MARGIN));

        double stepX = width / numberOfShapes;
        double stepY = height / numberOfShapes;

        if (x1 < x2 && y1 < y2)
            for (int x = x1, y = y1; x <= x2 && y <= y2; x += stepX, y += stepY) {
                new Diamond(x, y, DIAMOND_WIDTH, DIAMOND_HEIGHT).draw(g, SIDE_COLOR);
            }
        else if (x1 < x2 && y1 > y2)
            for (int x = x1, y = y1; x <= x2 && y >= y2; x += stepX, y += stepY) {
                new Diamond(x, y, DIAMOND_WIDTH, DIAMOND_HEIGHT).draw(g, SIDE_COLOR);
            }
        else if (x1 > x2 && y1 < y2)
            for (int x = x1, y = y1; x >= x2 && y <= y2; x += stepX, y += stepY) {
                new Diamond(x, y, DIAMOND_WIDTH, DIAMOND_HEIGHT).draw(g, SIDE_COLOR);
            }
        else
            for (int x = x1, y = y1; x >= x2 && y >= y2; x += stepX, y += stepY) {
                new Diamond(x, y, DIAMOND_WIDTH, DIAMOND_HEIGHT).draw(g, SIDE_COLOR);
            }

    }
}
