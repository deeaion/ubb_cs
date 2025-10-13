import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Random;

public class Problema1 {
    /*
        For generation of an array of n elements with values between 0 and upperBound
     */
    public static int[] generationOfArray(int n,int upperBound)
    {
        // we use random to do it
        int[] array=new int[n];
        Random random= new Random();
        for(int i=0;i<n;i++)
        {
            array[i]=random.nextInt(upperBound);
        }
        return array;
    }
    /*
        For sequential method to check that the method using Threads is correct
 */
    public static int[] sumOfArrays(int[] array1,int[] array2)
    {
        int n=array1.length;
        int[] result=new int[n];
        for(int i=0;i<n;i++)
        {
            result[i]=(int)Math.sqrt(array1[i]*array1[i]*array1[i]*array1[i]*array1[i]+
                    array2[i]*array2[i]*array2[i]*array2[i]*array2[i]);
        }
        return result;
    }

    public static void main(String[] args) {
        int n=200023;
        int upperBound=10003000;
        //generating the arrays
        int[] array1=generationOfArray(n,upperBound);
        int[] array2=generationOfArray(n,upperBound);
        // print out the arrays
//        System.out.println("Array 1: ");
//        System.out.println(Arrays.toString(array1));
//        System.out.println("Array 2: ");
//        System.out.println(Arrays.toString(array2));
        //creating the threads
        int number_of_threads=15;
        Thread [] threads=new MyThread[number_of_threads];
        //for parallelism
        int [] result=new int[n];
        int start=0;
        int end=n/number_of_threads;
        int rest=n % number_of_threads; // we will add the rest to the last thread
        //start time
        long startTime=System.nanoTime();
        for(int i=0;i<number_of_threads;i++)
        {
            if(rest>0){
                end++;
                rest--;
            }
            //initializam threadul cu start si end
            threads[i]=new MyThread(i,start,end,array1,array2,result);
            start=end;
            end=start+n/number_of_threads;
            threads[i].start();
        }
        for(int i=0;i<number_of_threads;i++)
        {
            try {
                threads[i].join();
            } catch (InterruptedException e) {
               throw new RuntimeException(e);
            }
        }
        long endTime=System.nanoTime();
//        System.out.println("Result "+ "in parallel method:");
        System.out.println("Result in paralel:");
        System.out.println(" in "+(endTime-startTime)+" ms");
        startTime=System.nanoTime();
        int[] result2=sumOfArrays(array1,array2);
        System.out.println("Result in sequential:");
        endTime=System.nanoTime();
//        System.out.println("Result by sequential method: ");
        System.out.println( " in "+(endTime-startTime)+" ms");
        //Type 3
        Thread [] threads2=new MyThread2[number_of_threads];
        startTime=System.nanoTime();
        for(int i=0;i<number_of_threads;i++)
        {
            threads2[i]=new MyThread2(i,number_of_threads,n,array1,array2,result);
            threads2[i].start();

        }
        for(int i=0;i<number_of_threads;i++)
        {
            try {
                threads2[i].join();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
        //checking if the results are the same
        endTime=System.nanoTime();
        System.out.println("Result in paralel with jump from p to p:");
        System.out.println(" in "+(endTime-startTime)+" ms");
        boolean ok=Arrays.equals(result,result2);
        if(ok)
        {
            System.out.println("The results are the same");
        }
        else
        {
            System.out.println("The results are not the same");
        }

    }
}
