import java.net.*;
import java.io.*;
class ClientHandler extends Thread {
    public ClientHandler(Socket client, DataInputStream serverInputStream, DataOutputStream serverOutputStream) throws IOException {
        int sizeSir1=serverInputStream.readUnsignedShort();
        int sizeSir2=serverInputStream.readUnsignedShort();
        byte [] byteSir1=new byte[sizeSir1];
        byte [] byteSir2=new byte[sizeSir2];
        serverInputStream.read(byteSir1);
        serverInputStream.read(byteSir2);
        byte [] interclasate=new byte[sizeSir1+sizeSir2];
        int iS1=0;
        int iS2=0;
        int indicesir=0;
        while(iS1<sizeSir1&&iS2<sizeSir2)
        {
            interclasate[indicesir++]=byteSir1[iS1++];
            interclasate[indicesir++]=byteSir2[iS2++];
        }
        while(iS1<sizeSir1)
        {
            interclasate[indicesir++]=byteSir1[iS1++];
        }
        while(iS2<sizeSir2)
        {
            interclasate[indicesir++]=byteSir2[iS2++];
        }
        serverOutputStream.write(interclasate);
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