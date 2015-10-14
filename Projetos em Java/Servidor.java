package teste;
import java.io.*;
import java.net.*;
public class Servidor
{ public static void main(String[] arg)
  { ServerSocket s;
    try
    { s = new ServerSocket(6789);
      System.out.println("Servidor iniciado na porta 6789");
      while(true)
      { Socket cliente = s.accept();
        System.out.println("Conexão estabelecida "+"("+cliente+")");
        DataInputStream in = new DataInputStream(cliente.getInputStream());
        DataOutputStream out = new DataOutputStream(cliente.getOutputStream());
        double numero, soma = 0.0;
        numero = in.readDouble();
        while(numero != -1.0)
        { soma += numero;
          System.out.println("Valor recebido: "+numero+ " \t - parcial = "+soma);
          numero = in.readDouble();
        }
          out.writeDouble(soma);
          cliente.close();
          System.out.println("Conexão encerrada.");
     }
    }
     catch(Exception e)
      { System.out.println("Erro: "+e.getMessage()); }
   }
}
