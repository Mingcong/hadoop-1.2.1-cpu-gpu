import java.io.*;

public class call_caffe {
         public static void main(String[] args)
         {
		String batchSize = args[0];
		String mode = args[1];
		String input = args[2];
		String output = args[3];
		try {  
//			String command = "/home/ideal/git/apps_for_streaming/CPU/shell/run.sh /home/ideal/car_10m.avi out.txt 8";
			String command = "/home/ideal/hadoop-1.2.1-cpu-gpu/apps/caffe_classification/run.sh " + batchSize + " " + mode + " " + input + " " + output;
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
