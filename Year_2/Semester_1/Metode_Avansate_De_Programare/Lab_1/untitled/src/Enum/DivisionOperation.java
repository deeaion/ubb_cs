package Enum;

import Logic.ComplexExpression;
import Model.ComplexNumber;

import java.util.ArrayList;

public class DivisionOperation extends ComplexExpression {
    ArrayList<ComplexNumber> numbers;
    public DivisionOperation(ArrayList<ComplexNumber> numbers)
    {
        super(numbers);
    }


    @Override
    protected ComplexNumber executeOneOperation(ComplexNumber nr1, ComplexNumber nr2) {
        return nr1.division(nr2);
    }

}
