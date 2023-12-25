package Logic;

import Enum.Operation;
import Model.ComplexNumber;

import java.security.InvalidParameterException;
import java.util.ArrayList;
import java.util.regex.Pattern;

public class ExpresssionParser {
    private final String[] args;
    public ExpresssionParser(String[] args)
    {
        this.args=args;
    }
    /*INDIVIDUAL VALIDATORS */
    private boolean isComplexNumberValid(String toParse)
    {
        //i cover all cases here. If I just have a complex number of type i cover it first. After
        // If i do not have that i cover with a REGEX all possible cases if it is not
        //IF it is not a correct form of a complex number i throw an exception
        if(Pattern.matches("^i$",toParse))
        {
            return true;
        }
       if(Pattern.matches("^(-{0,1}([0-9]+(.[0-9]+)*))*[+-]{0,1}([0-9]+(.[0-9]+)*\\*i+)*$", toParse))
       {
           return true;
       }
            return Pattern.matches("^(-{0,1}([0-9]+(.[0-9]+)*))*[+-]{0,1}(i+)*$", toParse);

    }
    private boolean isOperatorValid(String toCheck,Operation operationExp)
    {
        Operation operation;
        operation=OperatorType(toCheck);
        if(operationExp==null)
            return true;
        return operationExp == operation;
    }
    /*GET TYPE OF OPERATOR IN CASE IT IS THE FIRST ONE*/
    private Operation OperatorType(String toCheck)
    {
        switch (toCheck)
        {
            case "+": return Operation.ADDITION;
            case "-":return Operation.SUBSTRACTION;
            case "*":return Operation.MULTIPLICATION;
            case "/":return Operation.DIVISION;
            default:
                return null;
        }
    }
    /*PARSER FOR COMPLEX NUMBERS*/
    private ComplexNumber ComplexNumberParser(String toParse)
    {
        if(Pattern.matches("^i$",toParse))
        {
            return new ComplexNumber(0,1);
        }
            //i have a valid number. now i have to split it and add it to my array
            //if it is of for a+b*i or simply a
            String[] splited;
            if(Pattern.matches("^-([0-9]+(.[0-9]+)*)*(\\+([0-9]+(.[0-9]+)*)*\\*?i)*$",toParse))
            {
                //first number is negative
                splited=toParse.split("-",100);
                splited[0]=splited[1];
                toParse=splited[0];
                splited=toParse.split("\\+",100);
                splited[0]="-"+splited[0];
                if(splited[1].equals("i"))
                    splited[1]="1";

            }
        else if(Pattern.matches("^-([0-9]+(.[0-9]+)*)*(-([0-9]+(.[0-9]+)*)*\\*?i)*$",toParse))
        {
            //first number is negative
            splited=toParse.split("-",100);
            toParse=splited[1];
            splited=toParse.split("-",100);
            splited[0]="-"+splited[0];
            if(splited[1].equals("-i"))
                splited[1]="-1";

        }
          else  if(Pattern.matches( "^([0-9]+(.[0-9]+)*)*(\\+([0-9]+(.[0-9]+)*)*\\*?i)*$",toParse))
            {
                splited=toParse.split("\\+",100);
                if(splited[1].equals("i"))
                    splited[1]="1";
            }
            else if(Pattern.matches("^([0-9]+(.[0-9]+)*)*(-([0-9]+(.[0-9]+)*)*\\*?i)*$",toParse))
            {
                splited=toParse.split("-",100);
                if(splited[1].equals("i"))
                {splited[1]="-1";}
                else {splited[1]="-"+splited[1];}
            }

            else
            {
                //THE CASE WHERE YOU ONLY HAVE A REAL PART OR ONLY THE IMAG PART
                //real
                if(Pattern.matches("^([0-9]+(.[0-9]+)*)*(.[0-9]+)*?$",toParse))
                {
                    return new ComplexNumber(Double.parseDouble(toParse),0);
                }
                //imag
                else
                {
                    return new ComplexNumber(0,Double.parseDouble(toParse.replace("*i","")));
                }
            }

            //acum fac numarul
            double re=Double.parseDouble(splited[0]);
            if(splited.length>1)
            {double im=Double.parseDouble(splited[1].replace("*i",""));
            return new ComplexNumber(re,im);}
            else

            { return new ComplexNumber(re,0);}

    }

//VERIFY EXPRESSION
    //Throws exceotion if invalid
    private void verifyExpression() {
        if(args.length%2==0||args.length<3)
        {
            throw new InvalidParameterException("Invalid Expression");
        }

        Operation operationExp=null;
        for(int i=0;i<args.length;i++)
        {
            if(i%2==0)
            {
                if(!isComplexNumberValid(args[i]))
                {
                    throw new InvalidParameterException("Invalid Expression");
                }

            }
            else
            {
                if(isOperatorValid(args[i],operationExp))
                {
                    if(operationExp==null)
                    {
                        operationExp=OperatorType(args[i]);
                    }
                }
                else
                {
                    throw new InvalidParameterException("Invalid Expression");
                }
            }
        }

    }
    public ComplexNumber evaluateExpression()
    {
        verifyExpression();

        ArrayList<ComplexNumber> numbers= new ArrayList<>();
        Operation op=OperatorType(args[1]);
        for(int i=0;i<args.length;i+=2)
        {
            numbers.add(ComplexNumberParser(args[i]));
        }
        ExpressionFactory factory=ExpressionFactory.getInstance();
        return factory.createExpression(op, numbers).execute();
    }


}

