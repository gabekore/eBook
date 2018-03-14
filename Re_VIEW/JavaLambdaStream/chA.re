= 問題の解答

== @<chapref>{ch01}
==={ans-ch01-01} @<hd>{ch01|mondai-ch01-01}の解答例

ラムダ式は、ラムダ式外にある変数を参照することができます。

但しその変数は@<kw>{final}もしくは事実上の@<kw>{final}である必要があります。


//listnum[list-A-01][Runnableになんとかして引数を渡す方法例1][Java]{
public class LambdaSample1 {
    public static void main(String[] args) {
        final String str = "ランナブルだよぉ〜ん";
        Runnable rn = () -> System.out.println(str);
        rn.run();
    }
}
//}

//cmd[処理結果]{
ランナブルだよぉ〜ん
//}



//listnum[list-A-02][Runnableになんとかして引数を渡す方法例2][Java]{
public class RunnableSample {
    public static void main(String[] args) {
        Func01();
        Func02();
        Func03();
    }

    public static void Func01() {
        RunnableRun("ほげほげだよぉ〜ん");
    }
    public static void Func02() {
        RunnableRun("ふがふがだよぉ〜ん");
    }
    public static void Func03() {
        RunnableRun("へげへげだよぉ〜ん");
    }

    public static void RunnableRun(final String str) {
        Runnable rn = ()->System.out.println(str);
        rn.run();
    }
}
//}



//cmd[処理結果]{
ほげほげだよぉ〜ん
ふがふがだよぉ〜ん
へげへげだよぉ〜ん
//}



== @<chapref>{ch05}
==={ans-ch05-01} @<hd>{ch05|mondai-ch05-01}の解答例

//listnum[list-A-0][@<kw>{Runnable}を使ってみよう][Java]{
package ensyuu;

public final class RunnableTest {
    
    public static void doRnblAll() {
        System.out.println("==> doRnblAll");
        doRnbl01();
        doRnbl02();
        doRnbl03();
        doRnbl04();
    }
    
    // １．Runnableで文字を表示せよ
    private static void doRnbl01() {
        System.out.println("==> doRnbl01");
        Runnable rnbl = () -> System.out.println("  -->doRnbl01");
        runrunrun(rnbl);
    }
    
    // ２．Runnableがnullでも問題無いように処理せよ
    private static void doRnbl02() {
        System.out.println("==> doRnbl02");
        Runnable rnbl = null;
        runrunrun(rnbl);
    }
    
    // ３．Runnableでラムダ式外の変数を使って足し算せよ
    private static void doRnbl03() {
        System.out.println("==> doRnbl03");
        
        int plus1 = 23;
        int plus2 = 45;
        
        Runnable rnbl = () -> {
            int ans = plus1 + plus2;
            System.out.println("  ans : " + Integer.toString(ans));
        };
        runrunrun(rnbl);
    }
    
    // ４．関数の引数を使って、Runnableで足し算せよ
    private static void doRnbl04() {
        System.out.println("==> doRnbl04");
        doRnbl04_01(135, 246);
        doRnbl04_01(111, 222);
        doRnbl04_01(333, 444);
    }
    private static void doRnbl04_01(int plus1, int plus2) {
        System.out.println("==> doRnbl04_01");
        
        Runnable rnbl = () -> {
            int ans = plus1 + plus2;
            System.out.println("  ans : " + Integer.toString(ans));
        };
        runrunrun(rnbl);
    }
    
    // ５．Runnableを実行するための関数を作れ
    private static void runrunrun(Runnable rnbl) {
        System.out.println("==> runrunrun");
        if (rnbl != null) {
            rnbl.run();
        }
    }
}
//}


//cmd[処理結果]{
==> doRnblAll
==> doRnbl01
==> runrunrun
  -->doRnbl01
==> doRnbl02
==> runrunrun
==> doRnbl03
==> runrunrun
  ans : 68
==> doRnbl04
==> doRnbl04_01
==> runrunrun
  ans : 381
==> doRnbl04_01
==> runrunrun
  ans : 333
==> doRnbl04_01
==> runrunrun
  ans : 777
//}


==={ans-ch05-02} @<hd>{ch05|mondai-ch05-02}の解答例

//listnum[list-A-0][@<kw>{Consumer}を使ってみよう][Java]{
package ensyuu;

import java.util.function.Consumer;

public final class ConsumerTest {
    
    public static void doCnsmAll() {
        System.out.println("==> doCnsmAll");
        doCnsm01();
        doCnsm02();
        doCnsm03();
    }
    
    // １．Consumer<String>の引数を表示せよ
    private static void doCnsm01() {
        System.out.println("==> doCnsm01");
        Consumer<String> cnsm = System.out::println;
        accaccacc(cnsm, "  ->doCnsm01");
    }
    
    // ２．Consumer<Integer>の引数とラムダ式外の変数を計算に使用し、計算結果を表示せよ
    private static void doCnsm02() {
        System.out.println("==> doCnsm02");
        
        int out_i = 9;
        
        Consumer<Integer> cnsm = (i) -> {
            i += 2;
            i *= out_i;
            System.out.println("  ans : " + Integer.toString(i));
        };
        
        accaccacc(cnsm, 6);
    }
    
    // ３．Consumerの引数と関数の引数を使って、Consumerで足し算せよ
    private static void doCnsm03() {
        System.out.println("==> doCnsm03");
        doCnsm03_01(135, 246);
        doCnsm03_01(111, 222);
        doCnsm03_01(333, 444);
    }
    private static void doCnsm03_01(int plus1, int plus2) {
        System.out.println("==> doCnsm03_01");
        
        Consumer<Integer> cnsm = (i) -> {
            int ans = i + plus1 + plus2;
            System.out.println("  ans : " + Integer.toString(ans));
        };
        accaccacc(cnsm, 1000);
    }
    
    // ４．Consumerを実行するための関数を作れ
    private static <T> void accaccacc(Consumer<T> cnsm, T param) {
        System.out.println("==> accaccacc");
        if (cnsm != null) {
            cnsm.accept(param);
        }
    }
}
//}


//cmd[処理結果]{
==> doCnsmAll
==> doCnsm01
==> accaccacc
  ->doCnsm01
==> doCnsm02
==> accaccacc
  ans : 72
==> doCnsm03
==> doCnsm03_01
==> accaccacc
  ans : 1381
==> doCnsm03_01
==> accaccacc
  ans : 1333
==> doCnsm03_01
==> accaccacc
  ans : 1777
//}


==={ans-ch05-03} @<hd>{ch05|mondai-ch05-03}の解答例

//listnum[list-A-0][@<kw>{Function<T,R>}を使ってみよう][Java]{
package ensyuu;

import java.util.function.Consumer;
import java.util.function.Function;

public final class FunctionTest {

    public static void doFnctAll() {
        System.out.println("==> doFnctAll");
        doFnct01();
    }
    
    // １．FunctionにRunnableかConsumerを組み合わせて何か作れ
    private static void doFnct01() {
        
        System.out.println("==> doFnct01");
            
        Runnable rnbl = () -> System.out.println("----> 1");
        
        Function<Integer, String> fnct = (i) -> {
            
            Consumer<Integer> cnsm = (ii) -> {
                int ans = i + ii + 10;
                
                String s = Integer.toString(ans);
                
                rnbl.run();
                System.out.println("ans : " + s);
            };
            cnsm.accept(2);
            
            
            Runnable rnbl2 = () -> System.out.println("----> 2");
            rnbl2.run();
            
            String s = "Your input is " + Integer.toString(i) + ".";
            
            return s;
        };
        System.out.println(fnct.apply(4));
    }
}
//}


//cmd[処理結果]{
==> doFnctAll
==> doFnct01
----> 1
ans : 16
----> 2
Your input is 4.
//}


==={ans-ch05-04} @<hd>{ch05|mondai-ch05-04}の解答例

//listnum[list-A-0][@<kw>{Predicate}を使ってみよう][Java]{
package ensyuu;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.function.BiFunction;
import java.util.function.Predicate;

public final class PredicateTest {
    
    public static void doPredAll() {
        System.out.println("==> doPredAll");
        doPred01();
    }
    
    private static int num1;
    private static int num2;
    
    private static BiFunction<Integer, Integer, Integer> funcPlus = (a,b)->{
        return (a + b);
    };
    private static BiFunction<Integer, Integer, Integer> funcMinus = (a,b)->{
        return (a - b);
    };
    
    private static Runnable rnblPlus = ()->{
        int ans = funcPlus.apply(num1, num2);
        System.out.println("plus+ans : " + ans);
    };
    private static Runnable rnblMinus = ()->{
        int ans = funcMinus.apply(num1, num2);
        System.out.println("minus-ans : " + ans);
    };

    private static Predicate<Integer> pred = (a) -> {
        return (a == 1);
    };
    
    // １．PredicateにRunnableかConsumerかFunctionかを組み合わせて何か作れ
    private static void doPred01() {
        
        System.out.println("==> doPred01");
        BufferedReader d = new BufferedReader(new InputStreamReader(System.in));
        int a = 0;
        try {
            System.out.println("input : 1 or 2\n? ");
            a = Integer.parseInt(d.readLine());
            
            System.out.println("１つ目の数字\n? ");
            num1 = Integer.parseInt(d.readLine());
            
            System.out.println("２つ目の数字\n? ");
            num2 = Integer.parseInt(d.readLine());
        } catch (IOException ex) {
            System.out.println("Exception!");
        }
        
        if (pred.test(a)) {
            rnblPlus.run();
        } else {
            rnblMinus.run();
        }
        
        System.out.println("End");
    }
}
//}


//cmd[処理結果]{
==> doPredAll
==> doPred01
input : 1 or 2
? 
5
１つ目の数字
? 
6
２つ目の数字
? 
7
minus-ans : -1
End
//}


==={ans-ch05-05} @<hd>{ch05|mondai-ch05-05}の解答例

//listnum[list-A-0][@<kw>{Supplier<R>}を使ってみよう][Java]{
package ensyuu;

import java.util.function.BiFunction;
import java.util.function.Consumer;
import java.util.function.Predicate;
import java.util.function.Supplier;

public final class SupplierTest {
    public static void doSuppAll() {
        System.out.println("==> doSuppAll");
        doSupp01();
    }
    
    // １．SupplierにRunnableかConsumerかFunctionかPredicateかを組み合わせて何か作れ
    private static void doSupp01() {
        
        System.out.println("==> doSupp01");
        
        Consumer<Object> cnsm = (o)->{
            if (o instanceof Integer) {
                System.out.println("Integerだよ〜ん！" + o);

            } else if (o instanceof String) {
                System.out.println("Stringだよ〜ん！" + o);
            
            } else if (o instanceof Boolean) {
                System.out.println("Booleanだよ〜ん！" + o);
            
            } else if (o instanceof Object) {
                System.out.println("Objectだよ〜ん！" + o);
            
            } else {
                System.out.println("不明だよ〜ん！" + o);
            
            } 
        }; 
        
        Supplier<Object> splr = ( )->{return 10;};
        
        Predicate<Object> pdct = (o)->{
            
            if (!(o instanceof Integer)) {
                return false;
            }
            
            Integer temp = (Integer)o;
            
            return (temp > 100);
        };
        
        BiFunction<Object,Object,Object> fnct = (Object o1,Object o2)->{
            if (!(o1 instanceof Integer) || !(o2 instanceof Integer)) {
                return -999;
            }
            Integer ret = (Integer)o1 + (Integer)o2 * (Integer)splr.get();
            
            if (pdct.test(ret)) {
                return ret;
            }
            
            return -888;
        };
        
        cnsm.accept(fnct.apply(10, 20));
        cnsm.accept(fnct.apply("10", 20));
        cnsm.accept(fnct.apply(0, 0));
    }
}
//}


//cmd[処理結果]{
    ==> doSuppAll
==> doSupp01
Integerだよ〜ん！210
Integerだよ〜ん！-999
Integerだよ〜ん！-888
//}










== @<chapref>{ch06}
==={ans-ch06-01} @<hd>{ch06|mondai-ch06-01}の解答例

//listnum[list-A-03][臭くないコードに書き直す][Java]{
public class Sample {
    public static void main(String[] args) {
        List<String> hoge = Arrays.asList("aaa", "bbb", "hit", "ccc", "ddd");
        System.out.println(hoge.contains("hit") ? "hitはありました" : "hitは無いです");

        // 三項演算子は臭い・臭くないとは無関係
        // containsメソッドとか行数に注目してね
    }
}
//}

//cmd[処理結果]{
hitはありました
//}

== @<chapref>{ch07}
==={ans-ch07-01} @<hd>{ch07|mondai-ch07-01}の解答例

//listnum[list-A-04][関数型プログラミングの第一歩1][Java]{
public class Sample {
    public static void main(String[] args) {
        List<String> ls = Arrays.asList("aaa", "bbb", "ccc", "ddd", "eee");

        ls.forEach(s -> System.out.println(s));
    }
}
//}

//listnum[list-A-05][関数型プログラミングの第一歩2][Java]{
public class Sample {
    public static void main(String[] args) {
        List<String> ls = Arrays.asList("aaa", "bbb", "ccc", "ddd", "eee");

        // メソッド参照
        ls.forEach(System.out::println);
    }
}
//}

//listnum[list-A-06][関数型プログラミングの第一歩3][Java]{
// 意味は無いけど、こういう書き方も可能
public class Sample {
    public static void main(String[] args) {
        List<String> ls = Arrays.asList("aaa", "bbb", "ccc", "ddd", "eee");

        ls.stream()
          .forEach(s -> System.out.println(s));
    }
}
//}

//cmd[処理結果]{
aaa
bbb
ccc
ddd
eee
//}



==={ans-ch07-02} @<hd>{ch07|mondai-ch07-02}の解答例

//listnum[list-A-07][@<kw>{.filter()}を使ってみよう][Java]{
public class Sample {
    public static void main(String[] args) {
        List<String> liName = Arrays.asList("ai","ueo","kaki","kukeko","sasisu","seso","tatituteto");

        liName.stream()
              .filter(s -> s.length() > 4)
              .forEach(System.out::println);
    }
}
//}


//cmd[処理結果]{
kukeko
sasisu
tatituteto
//}




==={ans-ch07-03} @<hd>{ch07|mondai-ch07-03}の解答例

//listnum[list-A-07][@<kw>{.mapToInt()}を使ってみよう][Java]{
public class Sample {
    public static void main(String[] args) {
        List<Integer> ls = Arrays.asList(10,4,9,2,14,8,6);

        int total = ls.stream()
                      .filter(i->i > 9)    // Stream<Integer>
                      .mapToInt(i->i)      // IntStream
                      .sum();

        System.out.println("sum : " + Integer.toString(total));
    }
}
//}


//cmd[処理結果]{
sum : 24
//}










