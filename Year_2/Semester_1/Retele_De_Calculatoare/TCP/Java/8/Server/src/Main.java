import java.net.*;
import java.io.*;
import java.util.HashSet;
import java.util.Set;

class ClientHandler extends Thread {
    public ClientHandler(Socket client, DataInputStream serverInputStream, DataOutputStream serverOutputStream) throws IOException {
        int n1,n2;
        n1=serverInputStream.readUnsignedShort();
        n2=serverInputStream.readUnsignedShort();
        byte [] sir1=new byte[n1];
        byte [] sir2=new byte[n2];
        serverInputStream.read(sir1);
        serverInputStream.read(sir2);
        int counter=0;
        Set<Byte> numereComune=new HashSet<>();
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                if(sir1[i]==sir2[j])
                {
                    numereComune.add(sir1[i]);
                }
            }
        }
        byte [] numere=new byte[numereComune.size()];
        for(byte i:numereComune)
        {
            numere[counter++]=i;
        }
        serverOutputStream.writeShort(numereComune.size());
        serverOutputStream.write(numere);
        serverOutputStream.flush();;

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