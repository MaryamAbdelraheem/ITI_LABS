package Package;
import java.util.function.Function;

public class QudraticTemp implements Function<Float[], Float[]> {
//Function interface 
    @Override
    public Float[] apply(Float[] t) {
        float a = t[0];
        float b = t[1];
        float c = t[2];

        float delta = b * b - 4 * a * c;
        if(delta >= 0){
            //real roots 
            float root1 = (float)(-b + Math.sqrt(delta)) / (2 * a);
            float root2 = (float)(-b - Math.sqrt(delta)) / (2 * a);
            return new Float[]{root1, root2};
        }
        else{
            //complex roots
            return new Float[]{Float.NaN, Float.NaN};
        }
    }
}