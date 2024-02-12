import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    private static  String SERVER_ADDRESS;
    private static Integer SERVER_PORT;
    private static final int UNSIGNED_SHORT_MAX_VALUE=65535;
    private static final int UNSIGNED_SHORT_MIN_VALUE=0;
    private static DatagramSocket socket=null;

    public static void main(String[] args) {


    }
    /**WRITE TO SERVER*/
    private static void writeStringToSocket(byte[] toSend, InetAddress adress,int serverPort) throws IOException {

        byte[] lenght=converUnsignedShortToByte(toSend.length);
        DatagramPacket packet1=new DatagramPacket(lenght,lenght.length,adress,serverPort);
        socket.send(packet1);
        DatagramPacket packet2=new DatagramPacket(toSend,toSend.length,adress,serverPort);
        socket.send(packet2);
    }
    private static void writeCharToSocket(char c,InetAddress adress,int serverPort) throws IOException {
        byte[] toSend=new byte[1];
        toSend[0]=(byte)c;
        DatagramPacket packet=new DatagramPacket(toSend,1,adress,serverPort);
        socket.send(packet);
    }
    private static void writeIntegertoSocket(byte[] toSend, InetAddress adress,int serverPort) throws IOException {
        DatagramPacket packet=new DatagramPacket(toSend,toSend.length,adress,serverPort);
        socket.send(packet);
    }
    private static void writeByteArrayToSocket(byte [] toSend,DataOutputStream socketOut,InetAddress adress,int serverPort) throws IOException {
        DatagramPacket packet=new DatagramPacket(toSend,toSend.length,adress,serverPort);
        socket.send(packet);
    }
    /**READ FROM CONSOLE*/
    private static byte[] readCharConsole(String message, BufferedReader reader) throws IOException {
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
        byte [] nrInVect=new byte[1];
        nrInVect[0]=(byte) charactertoBeread;
        return nrInVect;
    }
    private static byte[] readStringFromConsole(String s, BufferedReader reader) throws IOException{
        System.out.println(s);
        String sir;
        sir=reader.readLine();
        if(sir.isEmpty())
        {
            throw new IllegalArgumentException("String cannot be empty!");
        }
        byte [] nou_sir=null;
        try
        {
            nou_sir=convertStringToByte(sir);
        }
        catch (UnsupportedEncodingException e)
        {
            System.out.println(e);

        }

        return nou_sir;
    }
    private static byte[] convertStringToByte(String s) throws UnsupportedEncodingException {
        byte[] nou_sir=s.getBytes("ASCII");
        nou_sir[s.length()-1]=0;
        return nou_sir;
    }
    private static byte[] readUnsignedShortConsole(String message, BufferedReader reader) throws IOException {
        int value = 0;
        byte numar[]=new byte[2];
        System.out.print(message);
        try {
            value = Integer.parseInt(reader.readLine());
            if (value < UNSIGNED_SHORT_MIN_VALUE || value > UNSIGNED_SHORT_MAX_VALUE) {
                throw new IllegalArgumentException("The given number must be unsigned short [0..65535]!");
            }
        } catch (NumberFormatException e) {
            System.err.println("The given input is not an integer!");
        }
        return converUnsignedShortToByte(value);
    }
    private static byte[] readUnsignedLongConsole(String message, BufferedReader reader) throws IOException {
        int value = 0;
        byte numar[]=new byte[4];
        System.out.print(message);
        try {
            value = Integer.parseInt(reader.readLine());

        } catch (NumberFormatException e) {
            System.err.println("The given input is not an integer!");
        }
        return convertUnsignedLongToByte(value);

    }
    private static byte[] convertUnsignedLongToByte(int value)
    {
        byte numar[]=new byte[4];
        numar[0] = (byte) ((value >> 24) & 0xFF);
        numar[1] = (byte) ((value >> 16) & 0xFF);
        numar[2] = (byte) ((value >> 8) & 0xFF);
        numar[3] = (byte) (value & 0xFF);
        return numar;
    }
    private static byte[] converUnsignedShortToByte(int value)
    {
        byte numar[]=new byte[2];
        numar[0] = (byte) ((value >> 8) & 0xFF);
        numar[1] = (byte) (value & 0xFF);
        return numar;
    }

}