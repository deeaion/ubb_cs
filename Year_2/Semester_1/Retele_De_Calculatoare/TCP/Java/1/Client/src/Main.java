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
    private static int readResult(Socket socket,DataInputStream soIn) throws IOException {
        int sum=0;
        try
        {
            sum= soIn.readUnsignedShort();
            if(sum>UNSIGNED_SHORT_MAX_VALUE||sum<UNSIGNED_SHORT_MIN_VALUE)
                throw new IllegalArgumentException("Not unsignet int");

        }
        catch (NumberFormatException e)
        {
            System.err.println("Not input/Char");
        }
        return sum;

    }
    private static void writeStringsToSocket(byte[] numbers, DataOutputStream socketOut, DataInputStream socketIn) throws IOException {
        socketOut.write(numbers);
        socketOut.flush();
    }
    private static void writeIntegertoSocket(int nrSir1, DataOutputStream socketOut) throws IOException {
        socketOut.writeShort(nrSir1);
        socketOut.flush();
    }
    private static byte [] readFromUserString(String s, BufferedReader reader) throws IOException{
        System.out.println(s);
        String sir="";

        sir=reader.readLine();
        if(sir.length()==0)
        {
            throw new IllegalArgumentException("String cannot be empty!");
        }
        String [] numberString=sir.split(" ");
        int howMany=numberString.length;
        byte [] numbers=new byte[howMany+1];
        numbers[0]=(byte)howMany;
        for(int i=1;i<howMany+1;i++)
        {
            numbers[i]=Byte.parseByte(numberString[i-1]);
        }
        return numbers;
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
            byte [] numbers=readFromUserString("Dati sirul de numere: ",reader);
            int howManyNummbers=numbers[0];
            writeStringsToSocket(numbers,socketOut,socketIn);
            int sum=readResult(socket,socketIn);
            System.out.println("Got the sum of the numbers : "+sum);

        } catch (UnknownHostException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}