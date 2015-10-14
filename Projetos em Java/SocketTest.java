/**
 * @version 1.10 1997-06-27
 * @author Cay Horstmann
 */

import java.io.*;
import java.net.*;

public class SocketTest
{  public static void main(String[] args)
   {  try
      {  Socket s = new Socket("www.globo.com", 80);

         BufferedReader in = new BufferedReader
            (new InputStreamReader(s.getInputStream())); //para ler da rede
         boolean more = true;
         while (more)
         {  String line = in.readLine();
            if (line == null) more = false;
            else
               System.out.println(line);
         }

      }
      catch (IOException e)
      {  System.out.println("Error" + e);
      }
   }
}

