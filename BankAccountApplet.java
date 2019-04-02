package me.homework.bankaccount;

import javax.swing.*;
import java.awt.*;

public class BankAccountApplet extends JApplet {

    private static final int WIDTH = 500;
    private static final int HEIGHT = 350;
    private static final int FIELD_LEN = 30;

    private BankAccount dadAcc;
    private BankAccount momAcc;
    private BankAccount sonAcc;

    private JTextField dadNameField = new JTextField(FIELD_LEN);
    private JTextField dadBalance = new JTextField(FIELD_LEN);

    private JTextField momNameField = new JTextField(FIELD_LEN);
    private JTextField momBalance = new JTextField(FIELD_LEN);

    private JTextField sonNameField = new JTextField(FIELD_LEN);
    private JTextField sonBalance = new JTextField(FIELD_LEN);

    private JButton submit = new JButton("Submit");

    @Override
    public void init() {
        super.init();

        this.setSize(new Dimension(WIDTH, HEIGHT));
        this.setLayout(new GridBagLayout());

        GridBagConstraints gbc = new GridBagConstraints();

        gbc.gridy = 0;
        JPanel initPanel = new JPanel();
        initPanel.setBorder(BorderFactory.createTitledBorder("Initiate"));
        initPanel.setLayout(new GridBagLayout());
        this.getContentPane().add(initPanel, gbc);

        gbc.gridy = 0;
        JPanel dadForm = new JPanel(new GridBagLayout());
        dadForm.setBorder(BorderFactory.createTitledBorder("Dad"));
        initPanel.add(dadForm, gbc);

        gbc.gridy++;
        JPanel momForm = new JPanel(new GridBagLayout());
        momForm.setBorder(BorderFactory.createTitledBorder("Mom"));
        initPanel.add(momForm, gbc);

        gbc.gridy++;
        JPanel sonForm = new JPanel(new GridBagLayout());
        sonForm.setBorder(BorderFactory.createTitledBorder("Son"));
        initPanel.add(sonForm, gbc);

        GridBagConstraints left = new GridBagConstraints();
        left.anchor = GridBagConstraints.EAST;
        GridBagConstraints right = new GridBagConstraints();
        right.weightx = 2;
        right.fill = GridBagConstraints.HORIZONTAL;
        right.gridwidth = GridBagConstraints.REMAINDER;

        drawForm(dadForm, left, right, dadNameField, dadBalance, "Dad");
        drawForm(momForm, left, right, momNameField, momBalance, "Mom");
        drawForm(sonForm, left, right, sonNameField, sonBalance, "Son");

        gbc.gridy++;
        initPanel.add(submit, gbc);

        gbc.gridy = 0;
        JPanel transferPanel = new JPanel();
        transferPanel.setVisible(false);
        transferPanel.setBorder(BorderFactory.createTitledBorder("Transfer Money"));
        this.getContentPane().add(transferPanel, gbc);

        JPanel fromPanel = new JPanel();
        JPanel toPanel = new JPanel();
        ButtonGroup from = new ButtonGroup();
        ButtonGroup to = new ButtonGroup();

        drawTransfer(fromPanel, from, "From");
        drawTransfer(toPanel, to, "To");

        gbc.gridx = 0;
        gbc.gridy = 0;
        transferPanel.add(fromPanel, gbc);

        gbc.gridx = 1;
        gbc.gridy = 0;
        transferPanel.add(toPanel, gbc);

        JPanel amountPanel = new JPanel();
        amountPanel.setLayout(new GridBagLayout());
        JTextField amountField = new JTextField(20);
        JButton transfer = new JButton("Transfer");
        gbc.gridx = 0;
        gbc.gridy = 0;
        amountPanel.add(amountField, gbc);
        gbc.gridy = 1;
        amountPanel.add(transfer, gbc);
        gbc.gridx = 2;
        gbc.gridy = 0;
        transferPanel.add(amountPanel, gbc);

        submit.addActionListener(event -> {
            dadAcc = new BankAccount(dadNameField.getText());
            dadAcc.credit(Double.parseDouble(dadBalance.getText()));

            momAcc = new BankAccount(momNameField.getText());
            momAcc.credit(Double.parseDouble(momBalance.getText()));

            sonAcc = new BankAccount(sonNameField.getText());
            sonAcc.credit(Double.parseDouble(sonBalance.getText()));
            initPanel.setVisible(false);
            transferPanel.setVisible(true);
        });
        transfer.addActionListener(event -> {
            double amount = Double.parseDouble(amountField.getText());
            BankAccount fromAcc = getAccount(from.getSelection().getMnemonic());
            BankAccount toAcc = getAccount(to.getSelection().getMnemonic());

            if (fromAcc == null || toAcc == null) {
                JOptionPane.showMessageDialog(this, "Invalid From or To");
                return;
            }

            if (fromAcc.transfer(toAcc, amount)) {
                JOptionPane.showMessageDialog(this, "Transfer successfully $" + amount + " from " + fromAcc.getOwnerName() + " to " + toAcc.getOwnerName());
            } else {
                JOptionPane.showMessageDialog(this, "Failed to transfer $" + amount + " from " + fromAcc.getOwnerName() + " to " + toAcc.getOwnerName());
            }
        });
    }

    private BankAccount getAccount(int code) {
        switch (code) {
            case 0:
                return dadAcc;
            case 1:
                return momAcc;
            case 2:
                return sonAcc;
            default:
                return null;
        }
    }

    private void drawTransfer(JPanel panel, ButtonGroup bg, String name) {
        panel.setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();

        panel.setBorder(BorderFactory.createTitledBorder(name));

        JRadioButton rb1 = new JRadioButton("Dad");
        JRadioButton rb2 = new JRadioButton("Mom");
        JRadioButton rb3 = new JRadioButton("Son");

        rb1.setMnemonic(0);
        rb2.setMnemonic(1);
        rb3.setMnemonic(2);

        bg.add(rb1);
        bg.add(rb2);
        bg.add(rb3);

        panel.add(rb1, gbc);
        gbc.gridy++;
        panel.add(rb2, gbc);
        gbc.gridy++;
        panel.add(rb3, gbc);
    }

    private void drawForm(JPanel form, GridBagConstraints left, GridBagConstraints right, JTextField nameField, JTextField balance, String name) {
        form.add(new JLabel(name + " Name: "), left);
        form.add(nameField, right);
        form.add(new JLabel(name + " Bank balance: "), left);
        form.add(balance, right);
    }

    @Override
    public void start() {
        super.start();


    }
}
