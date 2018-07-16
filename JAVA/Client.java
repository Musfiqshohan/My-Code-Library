import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

public class examClient {


    public static void main(String args[]) throws IOException {


        Socket s1 = new Socket("127.0.0.1", 1234);
        Scanner sc= new Scanner(System.in);

        DataInputStream is;
        DataOutputStream os;

        is = new DataInputStream(s1.getInputStream());
        os = new DataOutputStream(s1.getOutputStream());



            String line = is.readLine();


            System.out.println(line);

            String out;
            out=sc.next();

            os.writeBytes(out);
            os.writeBytes("from me");


        is.close();
        os.close();
        s1.close();
    }

}

