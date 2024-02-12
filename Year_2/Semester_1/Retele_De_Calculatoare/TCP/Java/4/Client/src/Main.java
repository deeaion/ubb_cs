// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.net.*;
import java.io.*;
import java.sql.Struct;
import java.util.Base64;

public class Main {
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
            DataInputStream soIn=new DataInputStream(socket.getInputStream());
            DataOutputStream socketOut=new DataOutputStream(socket.getOutputStream());
            int number= readUnsignedShort("Number: ",reader);
            writeIntegertoSocket(number,socket,socketOut);
            int [] divizori=readResult(socket,soIn);
            System.out.println("Divizori");


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

    private static int [] readResult(Socket socket,DataInputStream soIn) throws IOException {
        char charact = 0;
        int freq=-1;

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

    private static void writeIntegertoSocket(int number, Socket s,DataOutputStream socketOut) throws IOException {
        socketOut.writeShort(number);
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
    private static int readUnsignedShort(String message, BufferedReader reader) throws IOException {
        int unsignedShortNumber = 0;
        System.out.print(message);
        try {
            unsignedShortNumber = Integer.parseInt(reader.readLine());
            if (unsignedShortNumber < UNSIGNED_SHORT_MIN_VALUE || unsignedShortNumber > UNSIGNED_SHORT_MAX_VALUE) {
                throw new IllegalArgumentException("The given number must be unsigned short [0..65535]!");
            }
        } catch (NumberFormatException e) {
            System.err.println("The given input is not an integer!");
        }
        return unsignedShortNumber;
    }

}