import java.io.*;

public class call_cpu_object_search {
         public static void main(String[] args)
         {
		String input = args[0];
		String output = args[1];
		String numThreads = args[2];
		try {  
//			String command = "/home/ideal/git/apps_for_streaming/CPU/shell/run.sh /home/ideal/car_10m.avi out.txt 8";
			String command = "/home/ideal/hadoop-1.2.1-cpu-gpu/apps/CPU/object_search/run.sh " + input + " " + output + " " + numThreads;
  			Process proc = Runtime.getRuntime().exec(command);  
			readProcessOutput(proc);
  			int exitVal = proc.waitFor();  
			if(exitVal == 100){
				System.out.println("Streaming processing .........Completed");
			}else{
				System.out.println("Error: Call app");
				System.out.println(exitVal);
			}
		} catch (Exception e) {  
   	 		e.printStackTrace();  
		}  
		System.out.println("finished");
         }



    /**
     * print the output of process
     *
     * @param process
     */
    private static void readProcessOutput(final Process process) {
        // System.out print normal output and System.err print error
        read(process.getInputStream(), System.out);
        read(process.getErrorStream(), System.err);
    }

    // read the stream of input
    private static void read(InputStream inputStream, PrintStream out) {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));

            String line;
            while ((line = reader.readLine()) != null) {
                out.println(line);
            }

        } catch (IOException e) {
            e.printStackTrace();
        } finally {

            try {
                inputStream.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

}
