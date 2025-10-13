public class MyThread2 extends Thread{
    private int id;
    private int p;
    private int[] array1;
    private int[] array2;
    private int[] result;
    private int n;
    public MyThread2(int id,int p,int n,int [] array1,int []array2,int []result)
    {
        this.id=id;
        this.p=p;
        this.array1=array1;
        this.array2=array2;
        this.result=result;
    }
    @Override
    public void run(){
        for(int i=id;i<n;i+=p)
        {
            result[i]=(int)Math.sqrt(array1[i]*array1[i]*array1[i]*array1[i]*array1[i]+
                    array2[i]*array2[i]*array2[i]*array2[i]*array2[i]);
        }
    }
}
