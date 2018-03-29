= Stream APIとラムダ式を組み合わせてみよう

ラムダ式を単独で使うことはあまりありません。

あったとしても、特別メリットがあるわけではありません。

せいぜい、1回しか使わない関数をラムダ式に置き換える程度です。


Stream APIやEnumと紐付けてこそ便利さが発揮されます！

== @<hd>{chA|ans-ch07-03}を少しだけ改造してみる

変更したのは@<kw>{.filter()}の部分のみ。

別にどってこと無いですけど、Stream APIとラムダ式はこういう風に組み合わせて書く事ができます。

//note{
@<kw>{.filter(i->i > 9)}の@<kw>{i->i > 9}の時点でラムダ式ですけど、ここでお伝えしたいのはラムダ式の入った変数を使うことで再利用が容易になるということです。
//}

//listnum[list-ch09-01][@<kw>{.mapToInt()}を使ってみよう][Java]{
package streamlambda;

import java.util.Arrays;
import java.util.List;
import java.util.function.Predicate;

public class StreamLambda {

    /** コンストラクタ　*/
    public StreamLambda() {
        // nop
    }

    void exec() {
        // ↓こういう書き方でもOK
        // Predicate<Integer> pred = (i)->{return i > 9;};

        List<Integer> ls = Arrays.asList(10,4,9,2,14,8,6);
        Predicate<Integer> pred = (i)->i > 9;

        sumTrue(ls, pred);
        sumFalse(ls, pred);

    }

    /**
     * 9超のみの合計
     * @param ls
     * @param pred
     */
    private void sumTrue(List<Integer> ls, Predicate<Integer> pred)
    {
        int total = ls.stream()
                      .filter(i -> pred.test(i))    // Stream<Integer>
                      .mapToInt(i->i)               // IntStream
                      .sum();

        System.out.println("sum1 : " + Integer.toString(total));
    }

    /**
     * 9以下のみの合計
     * @param ls
     * @param pred
     */
    private void sumFalse(List<Integer> ls, Predicate<Integer> pred)
    {
        int total = ls.stream()
                      .filter(i -> !pred.test(i))   // Stream<Integer>
                      .mapToInt(i->i)               // IntStream
                      .sum();

        System.out.println("sum2 : " + Integer.toString(total));
    }
}
//}


//cmd[処理結果]{
sum1 : 24
sum2 : 29
//}


== メソッド参照もStream APIの中で使ってみる
//listnum[list-ch09-02][メソッド参照もStream APIの中で使ってみる][Java]{
package streamlambda;

import java.util.Arrays;
import java.util.List;

public class StreamMethodRef {
    void exec() {
        List<String> ls = Arrays.asList("a", "b", "c", "d", "e");

        ls.stream()
          .map(String::toUpperCase)
          .forEach(System.out::println);
    }
}
//}

//cmd[処理結果]{
A
B
C
D
E
//}
