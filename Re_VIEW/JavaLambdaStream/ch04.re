= 関数インターフェースを自作しよう！

関数インターフェースを覚えましたが、これらはあくまでも汎用です。
使われる頻度が多そうなものを、Javaが用意してくれているだけに過ぎません。

しかし、、、

『引数が5個とか6個とかある場合はどないすんねん！！？？』

と思ったあなた！！

そうです、デキるんです！

関数インターフェースは自作デキるんです！

== まずは汎用関数インターフェースを見てみよう

rt.jar / java.util.function/Function.class を見てみましょう。@<br>{}
以下がそれです。

※コメントは掲載していません。@<br>{}
※defaultとかは無視してください。@<br>{}
※見るべきは@<b>{5〜8行目}です。



//listnum[list-04-01][Function.class][Java]{
package java.util.function;

import java.util.Objects;

@FunctionalInterface
public interface Function<T, R> {

    R apply(T t);

    default <V> Function<V, R> compose(Function<? super V, ? extends T> before) {
        Objects.requireNonNull(before);
        return (V v) -> apply(before.apply(v));
    }

    default <V> Function<T, V> andThen(Function<? super R, ? extends V> after) {
        Objects.requireNonNull(after);
        return (T t) -> after.apply(apply(t));
    }

    static <T> Function<T, T> identity() {
        return t -> t;
    }
}
//}


ここではFunctionしか取り上げませんが、他も同様です。@<br>{}
実際に各自で確認してみてください。

== 関数インターフェースのルール

これを覚えておけばオッケー！

 1. @<kw>{@FunctionalInterface}を付ける（付けなくてもいいけど、付けよう）
 2. @<kw>{<T, R>}とか@<kw>{<Integer>}とか、型を付ける
 3. @<kw>{R apply(T t);}みたいな実行メソッドを書く（命名は自由）

//listnum[list-04-02][関数インターフェースの形][Java]{
@FunctionalInterface
public interface Function<T, R> {
    R apply(T t);
}
//}

== さぁ！自作しよう！
これがサンプル。

//listnum[list-04-03][関数インターフェース自作のサンプル][Java]{
public class Sample1 {

    @FunctionalInterface
    public interface MyOriginFuncIf1<A, B, C> {
        C apply(A a, B b);
    }

    private static void Main() {
        final String str = "追加戦士だ！";
        MyOriginFuncIf1<Integer, String, Boolean> myoriginfunc1 = (a,b) -> {
            if (a > 10 && b.equals("hoge")) {
                System.out.println("true:" + a.toString() + ":" + b + ":" + str);
                return true;
            } else {
                System.out.println("false:" + a.toString() + ":" + b + ":" + str);
                return false;
            }
        };
        
        myoriginfunc1.apply(11, "hoge");
        myoriginfunc1.apply( 9, "hoge");
        myoriginfunc1.apply(11, "fuga");
    }
}
//}

=== 演習
さぁ！　作りやがれ！！！！

AとかBとかじゃなくて、IntegerとかStringとか決め打ちにすることも可能（メリットあるかどうかは知らん）

