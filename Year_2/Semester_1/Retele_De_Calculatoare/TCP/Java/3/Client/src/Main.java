import java.io.*;
import java.net.Socket;
import java.net.UnknownHostException;

public class Main {
    private static  String SERVER_ADDRESS;
    private static Integer SERVER_PORT;
    private static final int UNSIGNED_SHORT_MAX_VALUE=65535;
    private static final int UNSIGNED_SHORT_MIN_VALUE=0;
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
    private static String readResult(Socket socket,DataInputStream soIn,int howManyNumbers) throws IOException {
        String mirrored="";
        try
        {
            byte [] read=new byte[howManyNumbers];
            soIn.read(read);
            mirrored=new String(read,"UTF-8");

        }
        catch (NumberFormatException e)
        {
            System.err.println("Not input/Char");
        }
        return mirrored;

    }
    private static void writeStringsToSocket(String sir, DataOutputStream socketOut, DataInputStream socketIn) throws IOException {
        socketOut.write(sir.getBytes("ASCII"));
        socketOut.flush();
    }
    private static void writeIntegertoSocket(int nrSir1, DataOutputStream socketOut) throws IOException {
        socketOut.writeShort(nrSir1);
        socketOut.flush();
    }
    private static String readFromUserString(String s, BufferedReader reader) throws IOException{
        System.out.println(s);
        String sir="";

        sir=reader.readLine();
        if(sir.length()==0)
        {
            throw new IllegalArgumentException("String cannot be empty!");
        }
        return sir;
    }


    public static void main(String[] args) {
        /*
            Un client trimite unui server un sir de numere. Serverul va returna clientului suma numerelor primite.
         */
        Socket socket=null;
        BufferedReader reader=null;
        SERVER_ADDRESS=args[0];
        SERVER_PORT=Integer.parseInt(args[1]);

        try
        {
            reader=new BufferedReader(new InputStreamReader(System.in));
            socket=new Socket(SERVER_ADDRESS,SERVER_PORT);
            DataOutputStream socketOut=new DataOutputStream(socket.getOutputStream());
            DataInputStream socketIn=new DataInputStream(socket.getInputStream());
            String sir=readFromUserString("Dati sirul de numere: ",reader);
            int howManyNummbers=sir.length();
            writeIntegertoSocket(howManyNummbers,socketOut);
            writeStringsToSocket(sir,socketOut,socketIn);
            String oglindit=readResult(socket,socketIn,howManyNummbers);
            System.out.println("Got the mirrored string : "+oglindit);

        } catch (UnknownHostException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}