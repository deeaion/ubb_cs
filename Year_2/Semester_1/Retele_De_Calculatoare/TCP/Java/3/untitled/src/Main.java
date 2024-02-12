import java.net.*;
import java.io.*;
class ClientHandler extends Thread {
    public ClientHandler(Socket client, DataInputStream serverInputStream, DataOutputStream serverOutputStream) throws IOException {
        byte [] toInvert=new byte[200];
        int length;
        length=serverInputStream.readUnsignedShort();
        serverInputStream.read(toInvert);
        byte [] inverted=new byte[length];
        //System.out.println("Got "+numbers[0]+" numbers");
        int j=0;
        for(int i=length-1;i>=0;i--)
        {
            inverted[i]=toInvert[j];
            j++;
        }
        serverOutputStream.write(inverted);
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