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
        DataOutputStream socketOut=null;
        DataInputStream socketIn=null;
        try{
            reader=new BufferedReader(new InputStreamReader(System.in));
            socket=new Socket(SERVER_ADDRESS,SERVER_PORT);
            socketIn=new DataInputStream(socket.getInputStream());
            socketOut=new DataOutputStream(socket.getOutputStream());
            String sir=readStringFromConsole("Dati sir: ",reader);
            int i=readUnsignedShortConsole("Dati i: ",reader);
            int l=readUnsignedShortConsole("Dati l: ",reader);
            writeIntegertoSocket(sir.length(),socket,socketOut);
          writeStringToSocket(sir,socket,socketOut);
            writeIntegertoSocket(i,socket,socketOut);
            writeIntegertoSocket(l,socket,socketOut);
            readResult(socket,socketIn);



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

    private static void readResult(Socket socket,DataInputStream socketIn) throws IOException {
        int numar=0;
        numar=socketIn.readUnsignedShort();
        byte [] sir=new byte[numar];
        socketIn.read(sir);
        String newString=new String(sir,"ASCII");
        System.out.println(newString);


    }
    /**WRITE TO SERVER*/
    private static void writeStringToSocket(String sir1, Socket socket,DataOutputStream socketOut) throws IOException {
        socketOut.write(sir1.getBytes("ASCII"));
        socketOut.flush();
    }
    private static void writeCharToSocket(char c,DataOutputStream socketOut) throws IOException {
        socketOut.writeChar(c);
        socketOut.flush();
    }
    private static void writeIntegertoSocket(int number, Socket s,DataOutputStream socketOut) throws IOException {
        socketOut.writeShort(number);
        socketOut.flush();
    }
    /**READ FROM CONSOLE*/
    private static char readCharConsole(String message, BufferedReader reader) throws IOException {
        char charactertoBeread=0;
        System.out.print(message);
        try {
            String lineRead=reader.readLine();
            if (lineRead.length()>1) {
                throw new IllegalArgumentException("The given number must be a CHAR!");
            }
            charactertoBeread = lineRead.toCharArray()[0];

        } catch (NumberFormatException e) {
            System.err.println("The given input is not an integer!");
        }
        return charactertoBeread;
    }
    private static String readStringFromConsole(String s, BufferedReader reader) throws IOException{
        System.out.println(s);
        String sir;
        sir=reader.readLine();
        if(sir.isEmpty())
        {
            throw new IllegalArgumentException("String cannot be empty!");
        }

        return sir;
    }
    private static int readUnsignedShortConsole(String message, BufferedReader reader) throws IOException {
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