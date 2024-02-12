import java.net.*;
import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Set;

class ClientHandler extends Thread {
    public ClientHandler(Socket client, DataInputStream serverInputStream, DataOutputStream serverOutputStream) throws IOException {
        int n1,n2;
        n1=serverInputStream.readUnsignedShort();
        n2=serverInputStream.readUnsignedShort();
        byte [] numere1=new byte [n1];
        byte [] numere2=new byte [n2];
        serverInputStream.read(numere1);
        serverInputStream.read(numere2);
        Set<Byte> numere=new HashSet<>();
        for(byte i:numere1)
        {
            numere.add(i);
        }
        for(byte j:numere2)
        {
            numere.remove(j);
        }
        byte [] found=new byte[numere.size()];
        int i=0;
        for(byte n:numere)
        {
            found[i++]=n;
        }
        serverOutputStream.writeShort(numere.size());
        serverOutputStream.write(found);
        serverOutputStream.flush();

    }
}
public class Main {
    public static void main(String[] args) throws IOException{
        ServerSocket serverSocket=new ServerSocket(Integer.parseInt(args[0]));
        Thread [] threads=new Thread[30];
        int i=0;
        while(true)
        {
            Socket client=null;
            try
            {
                client=serverSocket.accept();
                System.out.println("Started a client.");
                DataInputStream serverInputStream=new DataInputStream(client.getInputStream());
                DataOutputStream serverOutputStream=new DataOutputStream(client.getOutputStream());
                threads[i]=new ClientHandler(client,serverInputStream,serverOutputStream);
                threads[i].start();
            }
            catch (IOException e)
            {
                System.err.println(e);
            }
            if(i>=30)
            {
                for(i=0;i<30;i++)
                {
                    try {
                        threads[i].join();
                    } catch (InterruptedException e) {
                        throw new RuntimeException(e);
                    }
                }
                i=0;
            }
        }

    }


}