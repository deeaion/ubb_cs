package Model;

public class ComplexNumber {
    private double re,im;
    public ComplexNumber(double re, double im){
        this.re=re;
        this.im=im;
    }
    public ComplexNumber()
    {
        this.re=0;
        this.im=0;
    }
    public ComplexNumber addition(ComplexNumber other)
    {
        return new ComplexNumber(other.re+re,other.im+im);
    }
    public ComplexNumber substraction(ComplexNumber other)
    {
        return new ComplexNumber(re-other.re,im-other.im);
    }
    public ComplexNumber multiplication(ComplexNumber other)
    {
       // System.out.println(other.im);
        return new ComplexNumber(re*other.re-im*other.im,im*other.re+re* other.im);
    }
    public ComplexNumber conjugate()
    {
        return new ComplexNumber(re,0-im);
    }
    public ComplexNumber division(ComplexNumber other)
    {
        //ComplexNumber result=new ComplexNumber(0,0);
        ComplexNumber ConjugateofDenuminator=other.conjugate();
       // System.out.println(ConjugateofDenuminator.toString());
        double denuminator=other.multiplication(ConjugateofDenuminator).re;
       // System.out.println(denuminator);
        ComplexNumber result=this.multiplication(ConjugateofDenuminator);
      //  System.out.println(result.toString());
        result.setIm(result.getIm()/denuminator);
        result.setRe(result.getRe()/denuminator);
        return result;
    }
    public double getRe() {
        return re;
    }

    public double getIm() {
        return im;
    }

    public void setRe(double re) {
        this.re = re;
    }

    public void setIm(double im) {
        this.im = im;
    }
    @Override
    public String toString() {
        if(im>0)
          return re+"+"+im+"*i";
        else
            return re+""+im+"*i";
    }
}
