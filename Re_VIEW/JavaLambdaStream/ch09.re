= Stream APIとラムダ式を組み合わせてみよう

ラムダ式を単独で使うことはあまりありません。

あったとしても、特別メリットがあるわけではありません。

せいぜい、1回しか使わない関数をラムダ式に置き換える程度です。

　

Stream APIやEnumと紐付けてこそ便利さが発揮されます！

== @<hd>{chA|ans-ch07-03}を少しだけ改造してみる

変更したのは@<kw>{.filter()}の部分のみ。

別にどってこと無いですけど、Stream APIとラムダ式はこういう風に組み合わせて書く事ができます。

//note{
@<kw>{.filter(i->i > 9)}の@<kw>{i->i > 9}の時点でラムダ式ですけど、お伝えしたいのはラムダ式の入った変数を使うことで再利用が容易になるということです。
//}

//listnum[list-A-07][@<kw>{.mapToInt()}を使ってみよう][Java]{
package streamlambda;

import java.util.Arrays;
import java.util.List;
import java.util.function.Predicate;

public class StreamLambda {

    public static void main(String[] args) {
        StreamLambda sl = new StreamLambda();
        sl.exec();
    }
    
    /** コンストラクタ */
    public StreamLambda() {
        // nop
    }
    
    private void exec() {
        List<Integer> ls = Arrays.asList(10,4,9,2,14,8,6);

        Predicate<Integer> pred = (i)->i > 9;
        
        // ↓こういう書き方でもOK
        // Predicate<Integer> pred = (i)->{return i > 9;};
        
        int total = ls.stream()
                      .filter(i -> pred.test(i))    // Stream<Integer>
                      .mapToInt(i->i)               // IntStream
                      .sum();

        System.out.println("sum : " + Integer.toString(total));
    }
}
//}