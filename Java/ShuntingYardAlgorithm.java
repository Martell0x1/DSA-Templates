import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

public class ShuntingYardAlgorithm {

    public String PostFix(String Exp){
        // P EDMAS
        DynamicStack Operators = new DynamicStack();
        String postfix = "";
        Map<Character,Integer> precedence = new HashMap<>();
        precedence.put('^',5);
        precedence.put('/',4);
        precedence.put('*',3);
        precedence.put('+',2);
        precedence.put('-',1);

        boolean Pre = false;
        int cnt = 0;
        for(int x = 0 ; x < Exp.length() ; x++){
            if(Exp.charAt(x) >= '0' && Exp.charAt(x) <= '9'){
                postfix+=Exp.charAt(x);
            }
            else{
                if(Exp.charAt(x) == '(') {
                    Operators.push('(');
                }
                if(Exp.charAt(x) == ')'){
                    Pre = false;
                    while(cnt-- != 0){
                        postfix+=Operators.top();
                        Operators.pop();
                    }
                }
                if(!Operators.isEmpty() && ( precedence.get(Exp.charAt(x)) < precedence.get(Operators.top())) ){
                    postfix+=Operators.top();
                    Operators.pop();
                    Operators.push(Exp.charAt(x));
                    if(Pre) cnt++;
                }
                else {
                    Operators.push(Exp.charAt(x));
                    if(Pre) cnt++;
                }


            }
        }
        return postfix+Operators.top();
    }
}
