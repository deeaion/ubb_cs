// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.net.*;
import java.io.*;
import java.sql.Struct;
import java.util.Base64;

public class Main {
    public static class CharAndInt{
        char character;
        int freq;

        public CharAndInt(char charact, int freq) {
            this.character=charact;
            this.freq=freq;
        }
    };
    private static  String SERVER_ADDRESS;
    private static Integer SERVER_PORT;
    private static final int UNSIGNED_SHORT_MAX_VALUE=65535;
    private static final int UNSIGNED_SHORT_MIN_VALUE=0;
    public static void main(String args[])
    {
        SERVER_ADDRESS=args[0];
        SERVER_PORT= Integer.parseInt(args[1]);
        Socket socket=null;
        BufferedReader reader=null;
        try{
            reader=new BufferedReader(new InputStreamReader(System.in));
            socket=new Socket(SERVER_ADDRESS,SERVER_PORT);
            String sir1= readString("Sir 1: ",reader);
            String sir2=readString("Sir 2: ",reader);
            int nrSir1=sir1.length()+1;
            int nrSir2=sir2.length()+1;
            writeIntegertoSocket(nrSir1,nrSir2,socket);
            writeStringsToSocket(sir1,sir2,socket);
            CharAndInt numbers=readCharAndIntCount(socket);
            System.out.println("Character "+numbers.character+"appears "+numbers.freq+" times");


        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        finally {
            closeStreams(socket,reader);
        }
    }

    private static void closeStreams(Socket socket, BufferedReader reader) {
        if(socket!=null)
        {
            try{
                socket.close();;
            }
            catch (IOException e)
            {
                System.err.println("COULD NOT CLOSE");
            }
        }
        if(reader!=null)
        {
            try {
                reader.close();
            }
            catch (IOException e)
            {
                System.err.println("Could not close reader");
            }
        }
    }

    private static CharAndInt readCharAndIntCount(Socket socket) throws IOException {
        char charact = 0;
        int freq=-1;
        DataInputStream soIn=new DataInputStream(socket.getInputStream());
        try
        {
            charact= (char) soIn.readUnsignedByte();
//            if(charact>256)
//                throw new IllegalArgumentException("NOPE");
            freq=soIn.readUnsignedShort();

        }
        catch (NumberFormatException e)
        {
            System.err.println("Not input/Char");
        }
        return new CharAndInt(charact,freq);

    }

    private static void writeStringsToSocket(String sir1, String sir2, Socket socket) throws IOException {
        DataOutputStream socketOut=new DataOutputStream(socket.getOutputStream());
        socketOut.write(sir1.getBytes("ASCII"));
        socketOut.write(sir2.getBytes("ASCII"));
        socketOut.flush();
    }

    private static void writeIntegertoSocket(int nrSir1, int nrSir2, Socket s) throws IOException {
        DataOutputStream socketOut=new DataOutputStream(s.getOutputStream());
        socketOut.writeShort(nrSir1);
        socketOut.writeShort(nrSir2);
        socketOut.flush();
    }

    private static String readString(String s, BufferedReader reader) throws IOException{
        System.out.println(s);
        String sir="";
           sir=reader.readLine();
           if(sir.length()==0)
           {
               throw new IllegalArgumentException("String cannot be empty!");
           }

        return sir;
    }
}