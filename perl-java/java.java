import java.io.*;

public class java{
	public static void main(String[] arg)throws IOException{
		BufferedReader inData=new BufferedReader(new InputStreamReader(System.in));
		String aux;
		int n = 0;
		int num_ei = 0;

		System.out.print("Digite o numero de frases: ");
		aux=inData.readLine();
		n=Integer.parseInt(aux);
		
		FileWriter writer = new FileWriter("text.txt");
		PrintWriter out = new PrintWriter(writer);

		for(int i=1;i<=n;i++){
    		System.out.print(i+" - ");
    		aux=inData.readLine();
    		out.println(aux);
    	}

		writer.close();

		FileReader reader=new FileReader("text.txt");
		BufferedReader in=new BufferedReader(reader);

		while((aux=in.readLine())!= null){
   			if(aux.contains("ei")){
        		num_ei++;
    		}
		}
		
		reader.close();

		System.out.println("\n\nnumero de frases que tem 'ei' = "+num_ei);
	}
}