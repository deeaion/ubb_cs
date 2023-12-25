package Logic;
import Enum.Operation;
import Model.ComplexNumber;
import Enum.*;

import java.util.ArrayList;

public class ExpressionFactory {
    private static ExpressionFactory instance;
    public static ExpressionFactory getInstance()
    {
        if (instance==null)
        {
            instance=new ExpressionFactory();
        }
        return instance;
    }
    public ComplexExpression createExpression(Operation operation, ArrayList<ComplexNumber> args)
    {
       switch (operation)
       {
           case ADDITION :
               return new AdditionOperation(args);
           case SUBSTRACTION:
               return new SubstractionOperation(args);
           case DIVISION:
               return new DivisionOperation(args);
           case MULTIPLICATION:
               return new MultiplicationOperation(args);
           default:
               throw new IllegalArgumentException("Invalid operator!");
       }

    }

}
