package me.homework.mirror;

import java.awt.*;
import java.awt.geom.GeneralPath;

public class Diamond implements Shape {

    private int x;
    private int y;
    private int width;
    private int height;

    public Diamond(int x, int y, int width, int height) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    @Override
    public void draw(Graphics g, Color color) {
        GeneralPath shape = new GeneralPath();
        Graphics2D g2 = (Graphics2D) g;

        shape.moveTo(getX(), getY() + getHeight() / 2);
        shape.lineTo(getX() + getWidth() / 2, getY());
        shape.lineTo(getX(), getY() - getHeight() / 2);
        shape.lineTo(getX() - getWidth() / 2, getY());
        shape.closePath();

        g2.setPaint(color);
        g2.fill(shape);
        g2.draw(shape);
        g2.setPaint(Color.BLACK);
    }
}
