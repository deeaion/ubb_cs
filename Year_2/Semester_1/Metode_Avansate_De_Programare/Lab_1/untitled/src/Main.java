// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.

import Logic.ExpresssionParser;
import Model.ComplexNumber;

import java.security.InvalidParameterException;

public class Main {
    public static void main(String[] args) {

        try
        {
            ComplexNumber res=new ExpresssionParser(args).evaluateExpression();
            System.out.println(res.toString());
        }
        catch (InvalidParameterException mes)
        {
            System.out.println(mes);
        }
}}