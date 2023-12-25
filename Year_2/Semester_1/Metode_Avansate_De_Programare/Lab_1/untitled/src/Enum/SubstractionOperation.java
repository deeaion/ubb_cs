package Enum;

import Logic.ComplexExpression;
import Model.ComplexNumber;

import java.util.ArrayList;

public class SubstractionOperation extends ComplexExpression {
    ArrayList<ComplexNumber> numbers;
    public SubstractionOperation(ArrayList<ComplexNumber> numbers)
    {
        super(numbers);
    }


    @Override
    protected ComplexNumber executeOneOperation(ComplexNumber nr1, ComplexNumber nr2) {
       return nr1.substraction(nr2);
    }
}
