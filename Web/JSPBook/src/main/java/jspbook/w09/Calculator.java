package jspbook.w09;

public class Calculator {
    private int num1;
    private int num2;
    private String op;
    private int rslt;

    public int getNum1() { return num1; }
    public void setNum1(int num1) { this.num1 = num1; }

    public int getNum2() { return num2; }
    public void setNum2(int num2) { this.num2 = num2; }

    public String getOp() { return op; }
    public void setOp(String op) { this.op = op; }

    public int getRslt() { return rslt; }
    public void setRslt(int rslt) { this.rslt = rslt; }
    
    private int add(int a, int b) { return a + b; }
    private int sub(int a, int b) { return a - b; }
    private int mult(int a, int b) { return a * b; }
    private int div(int a, int b) { return a / b; }

    public int calc() {
        if (op.equals("+")) {
            rslt = add(num1, num2);
        } else if (op.equals("-")) {
            rslt = sub(num1, num2);
        } else if (op.equals("*")) {
            rslt = mult(num1, num2);
        } else if (op.equals("/")) {
            rslt = div(num1, num2);
        }
        return rslt;
    }
}