package Logic;

import Model.ComplexNumber;

import java.util.ArrayList;

public abstract class ComplexExpression {
    //attributes
//    Operation operation;
    protected ArrayList<ComplexNumber> numbers;
    //constructor
    public ComplexExpression(ArrayList<ComplexNumber> numbers)
    {

//        this.operation=operation;
        this.numbers=numbers;

    }
    //methods
    public  ComplexNumber execute()
    {
        ComplexNumber result=numbers.get(0);
        for(int i=1;i<numbers.size();i++)
        {
            result=executeOneOperation(result,numbers.get(i));
        }
        return result;
    }
    protected abstract ComplexNumber executeOneOperation(ComplexNumber nr1, ComplexNumber nr2);

}
