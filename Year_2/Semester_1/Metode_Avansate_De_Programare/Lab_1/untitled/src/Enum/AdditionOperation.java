package Enum;
import Logic.ComplexExpression;
import Model.ComplexNumber;

import java.util.ArrayList;


public class AdditionOperation extends ComplexExpression {
    public AdditionOperation(ArrayList<ComplexNumber> numbers) {
        super(numbers);
    }
    // protected ArrayList<ComplexNumber> numbers;
//    public AdditionOperation(ArrayList<ComplexNumber> numbers)
//    {
//        super(numbers);
//    }


    public ComplexNumber executeOneOperation(ComplexNumber nr1, ComplexNumber nr2) {
        return nr1.addition(nr2);
    }
}
