import java.net.*;
import java.io.*;
import java.util.HashMap;
import java.util.Map;

class ClientHandler extends Thread {
    Socket client;
    DataInputStream serverInputStream;
    DataOutputStream serverOutputStream;

    public ClientHandler(Socket client, DataInputStream serverInputStream, DataOutputStream serverOutputStream) throws IOException {
        //numar=serverInputStream.readUnsignedShort();

//        serverOutputStream.writeShort(nrDivizori);
//        serverOutputStream.write(divizori);
        this.client=client;
        this.serverInputStream=serverInputStream;
        this.serverOutputStream=serverOutputStream;
        int numar=0;
        numar=serverInputStream.readUnsignedShort();
        byte [] sir=new byte[numar];
        serverInputStream.read(sir);
        Map<Byte,Integer> frecvente=new HashMap<>();
        for(int i=0;i<numar;i++)
        {
            if(frecvente.containsKey((Byte) sir[i])==false)
            {
                frecvente.put(sir[i],1);
            }
            else if(frecvente.containsKey((Byte)sir[i]))
            {
                frecvente.put(sir[i],frecvente.get(sir[i])+1);
            }
        }
        int min=65535;
        byte foundChar=0;
        for(Byte key:frecvente.keySet())
        {
            if(min>frecvente.get(key))
            {
                foundChar=key;
                min=frecvente.get(key);
            }
        }
        serverOutputStream.writeByte(foundChar);
        serverOutputStream.writeShort(min);
        byte [ ] pozitii=new byte[min];
        int poz=0;
        for(byte i=0;i<numar;i++)
        {
            if(sir[i]==foundChar)
            {pozitii[poz++]=i;}
        }
        serverOutputStream.write(pozitii);


    }
}
public class Main {
    static ClientHandler [] threads=new ClientHandler[30];
    public static void main(String[] args) throws IOException{
        ServerSocket serverSocket=new ServerSocket(Integer.parseInt(args[0]));

        int i=-1;
        while(true)
        {
            Socket client=null;
            try
            {
                client=serverSocket.accept();
                System.out.println("Started a client.");
                DataInputStream serverInputStream=new DataInputStream(client.getInputStream());
                DataOutputStream serverOutputStream=new DataOutputStream(client.getOutputStream());
                i++;
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