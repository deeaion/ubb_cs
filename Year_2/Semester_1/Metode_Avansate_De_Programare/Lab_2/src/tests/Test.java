package tests;

import decorator.DelayTaskRunner;
import decorator.PrinterTaskRunner;
import decorator.StrategyTaskRunner;
import decorator.TaskRunner;
import factory.Strategy;
import model.MessageTask;
import model.Sorting.SortingStrategy;
import model.Sorting.SortingTask;

import java.security.InvalidParameterException;
import java.time.LocalDateTime;
import java.util.ArrayList;

public class Test {
    private void testSorting(int toS[],SortingStrategy strategy)
    {
        System.out.print("\n"+strategy.toString()+": ");
        SortingTask sot=new SortingTask(toS, strategy,"AAAAA","#42424");
        sot.execute();
        for(int i:toS)
        {
            System.out.print(i);
            System.out.print(" ");
        }
    }
    private ArrayList<MessageTask> getListofMessage()
    {
        ArrayList<MessageTask> listOfMesssages = new ArrayList<>();
        for(Integer i=1;i<6;i++)
        {
            MessageTask mt = new MessageTask(i.toString(),"Feedback lab1", "Ai obtinut 9.6"+i.toString(),"Gigi", "Ana",LocalDateTime.of(2018,9,27,9,29));
            listOfMesssages.add(mt);
        }
        return listOfMesssages;
    }
    private void testCreate4(String strat)
    {
        ArrayList<MessageTask> listofMessages=this.getListofMessage();
        StrategyTaskRunner strategyMan=new StrategyTaskRunner(Strategy.valueOf(strat));
        listofMessages.forEach(strategyMan::addTask);
        strategyMan.executeAll();
    }
    private  void test13(String strat)
    {
        ArrayList<MessageTask> listofMessages=this.getListofMessage();
        StrategyTaskRunner strategyMan=new StrategyTaskRunner(Strategy.valueOf(strat));
        TaskRunner runner=new PrinterTaskRunner(strategyMan);
        listofMessages.forEach(runner::addTask);
        runner.executeAll();
    }

    private void test14(String strat)
    {
        System.out.println("----------------------------------\nStrategy->Printer->Delay");

        ArrayList<MessageTask> listofMessages=this.getListofMessage();
        StrategyTaskRunner strategyMan=new StrategyTaskRunner(Strategy.valueOf(strat));
        listofMessages.forEach(e-> strategyMan.addTask(e));
        TaskRunner runner=new PrinterTaskRunner(strategyMan);
        //same here
        runner=new DelayTaskRunner(runner);
        runner.executeAll();
        System.out.println("-------------------------------------------------------");

    }
    private void test14b(String strat)
    {
        System.out.println("----------------------------------\nStrategy->Delay->Printer");
        ArrayList<MessageTask> listofMessages=this.getListofMessage();
        StrategyTaskRunner strategyMan=new StrategyTaskRunner(Strategy.valueOf(strat));
        listofMessages.forEach(e-> strategyMan.addTask(e));
        TaskRunner runner;
        runner=new DelayTaskRunner(strategyMan);
        runner=new PrinterTaskRunner(strategyMan);
        runner.executeAll();
        System.out.println("-------------------------------------------------------");
        //same here


    }

        private void testAllSort(int toS[])
        {
            System.out.println("Initial vector:");
            for(int i:toS){
                System.out.print(i);
                System.out.print(" ");
            }
            int vectorSize=toS.length;
            int toS2[]=new int[vectorSize];
            for(int i=0;i<vectorSize;i++)
            {
                toS2[i]=toS[i];
            }
            int toS3[]=new int[vectorSize];
            for(int i=0;i<vectorSize;i++)
            {
                toS3[i]=toS[i];
            }

            testSorting(toS,SortingStrategy.MergeSort);
            testSorting(toS2,SortingStrategy.BubbleSort);
            testSorting(toS3,SortingStrategy.QuickSort);
        }
        public void executeAll(String [] args)
        {
            int  toS[]=new int[]{1,0,2,1,10,-1,23,313,1,2,10,23};
            testAllSort(toS);
            System.out.println("\nTEST 4 (FIFO)");

            testCreate4("FIFO");
            System.out.println("\nTEST 4 (LIFO)");
            testCreate4("LIFO");
            System.out.println("\nTEST 13 (FIFO)");
            test13("FIFO");
            System.out.println("\nTEST 13 (LIFO)");
            test13("LIFO");
            if(args.length==0)
            {
                System.out.println("U HAVE NOT PROVIDED ANY PARAMETER!");
                return;
            }
            String strat=args[0];
            try
            {
                System.out.println("----------------------------");
                System.out.println("TRYING TEST 14 with strategy "+strat);
                test14(strat);
                test14b(strat);
            }
            catch (IllegalArgumentException exc)
            {
                System.out.println(exc);
            }


        }
}
