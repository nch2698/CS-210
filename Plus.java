package me.homework.mirror;

import java.awt.*;
import java.awt.geom.GeneralPath;

public class Plus implements Shape {

    private int x, y, width, height;

    public Plus(int x, int y, int width, int height) {
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
//        g.drawRect(getX() - getWidth() / 4, getY() - getHeight() / 2, getWidth() / 2, getHeight());
//        g.drawRect(getX() - getWidth() / 2, getY() - getHeight() / 4, getWidth(), getHeight() / 2);

        Graphics2D g2 = (Graphics2D) g;
        GeneralPath shape = new GeneralPath();

        shape.moveTo(getX() - getWidth() / 4, getY() - getHeight() / 2);
        shape.lineTo(getX() + getWidth() / 4, getY() - getHeight() / 2);
        shape.lineTo(getX() + getWidth() / 4, getY() - getHeight() / 4);
        shape.lineTo(getX() + getWidth() / 2, getY() - getHeight() / 4);
        shape.lineTo(getX() + getWidth() / 2, getY() + getHeight() / 4);
        shape.lineTo(getX() + getWidth() / 4, getY() + getHeight() / 4);
        shape.lineTo(getX() + getWidth() / 4, getY() + getHeight() / 2);
        shape.lineTo(getX() - getWidth() / 4, getY() + getHeight() / 2);
        shape.lineTo(getX() - getWidth() / 4, getY() + getHeight() / 4);
        shape.lineTo(getX() - getWidth() / 2, getY() + getHeight() / 4);
        shape.lineTo(getX() - getWidth() / 2, getY() - getHeight() / 4);
        shape.lineTo(getX() - getWidth() / 4, getY() - getHeight() / 4);

        shape.closePath();

        g2.setPaint(color);
        g2.fill(shape);
        g2.draw(shape);
        g2.setPaint(Color.BLACK);
    }
}
