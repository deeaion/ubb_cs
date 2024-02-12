import java.net.*;
import java.io.*;
class ClientHandler extends Thread {
    public ClientHandler(Socket client, DataInputStream serverInputStream, DataOutputStream serverOutputStream) throws IOException {
        int nrChars;
        nrChars=serverInputStream.readUnsignedShort();
        char character;
        //citesc sir
        byte [] sir=new byte[nrChars+1];
        serverInputStream.read(sir);
        //citesc char
        character=(char)serverInputStream.readUnsignedByte();
        int counter=0;
        byte [] pozitii=new byte[nrChars];
        //caut pozitiile elementului
        for(byte i=0;i<nrChars;i++)
        {
            if(sir[i]==character)
            {
                pozitii[counter++]=i;
            }
        }
        byte [] truncatedArray=new byte[counter];
        System.arraycopy(pozitii,0,truncatedArray,0,counter);
        //trimit cate elemente am
        serverOutputStream.writeInt(counter);
        serverOutputStream.flush();;
        serverOutputStream.write(truncatedArray);
        serverOutputStream.flush();;

    }
}
public class Main {
    public static void main(String[] args) throws IOException{
        ServerSocket serverSocket=new ServerSocket(Integer.parseInt(args[0]));
        Thread [] threads=new Thread[30];
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