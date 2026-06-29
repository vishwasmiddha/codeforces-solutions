import java.util.Scanner;
 
 
public class myClass {
    
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in); 
        String a = sc.next();
        String b  =sc.next();
        int sum = 0;
        
       
        
        
        for(int i = 0; i< a.length(); i++){
        
            
            if(a.charAt(i)==b.charAt(i)) {
                System.out.print(0);
            } else {
                System.out.print(1);
            }
             
        } 
        
        
       
     
        
    }
}