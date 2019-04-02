package me.homework.bankaccount;

public class BankAccount {

    private static final double MIN_BALANCE = 5;
    private String ownerName;
    private double balance;


    public BankAccount(String owner) {
        this.balance = 0;
        this.ownerName = owner;
    }

    public String getOwnerName() {
        return ownerName;
    }

    public void setOwnerName(String ownerName) {
        this.ownerName = ownerName;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    boolean debit(double amount) {
        if (amount < 0) return false;

        if (this.balance - amount <= MIN_BALANCE) return false;

        this.balance -= amount;

        return true;
    }

    boolean credit(double amount) {
        if (amount < 0) return false;

        this.balance += amount;

        return true;
    }

    boolean transfer(BankAccount receiver, double amount) {
        // Debit must stand before credit
        return this.debit(amount) && receiver.credit(amount);
    }
}
