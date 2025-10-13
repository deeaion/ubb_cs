public class MyThread extends Thread{
    private int id;
    private int start;
    private int end;
    private int[] array1;
    private int[] array2;
    private int[] result;
    public MyThread(int id,int start,int end,int [] array1,int []array2,int []result)
    {
        this.id=id;
        this.start=start;
        this.end=end;
        this.array1=array1;
        this.array2=array2;
        this.result=result;
    }
    @Override
    public void run(){
        for(int i=start;i<end;i++)
        {
            result[i]=(int)Math.sqrt(array1[i]*array1[i]*array1[i]*array1[i]*array1[i]+
                    array2[i]*array2[i]*array2[i]*array2[i]*array2[i]);
        }
    }
}
