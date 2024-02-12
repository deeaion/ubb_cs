import java.net.*;
import java.io.*;
class ClientHandler extends Thread {
    public ClientHandler(Socket client, DataInputStream serverInputStream, DataOutputStream serverOutputStream) throws IOException {
        int nrChar=0;
        nrChar=serverInputStream.readUnsignedShort();
        byte [] sir=new byte[nrChar];
        int i,l;
        serverInputStream.read(sir);
        i=serverInputStream.readUnsignedShort();
        l=serverInputStream.readUnsignedShort();
        byte [] sirnou=new byte[l];
        String newString=new String(sir,"ASCII");
        newString=newString.substring(i,l+i+1);
        sirnou=newString.getBytes();
        serverOutputStream.writeShort(sirnou.length);
        serverOutputStream.write(sirnou);

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