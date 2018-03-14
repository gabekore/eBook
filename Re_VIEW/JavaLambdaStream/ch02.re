= ラムダ式ってどんなのがあるの？

ここまでラムダ式を作るのにRunnableの関数型インターフェースを使いましたが、それ以外の関数型インターフェースを見て見ましょう。

//note{
T：引数@<br>{}
U：引数@<br>{}
R：戻り値
//}

//table[tbl-02-01][関数型インターフェースの種類（よく使うもの）]{
名前	引数	戻り値	覚え方
-------------------------------------------------------------
Runnable	引数（無し）	戻り値（無し）	Runnableは動作可能、動作するだけなので引数も戻り値も無し！
Consumer<T>	引数１個	戻り値（無し）	Consumerは消費者、消費するだけなので引数のみ、戻り値は無し！
Function<T,R>	引数１個	戻り値１個	Functionは関数、ごく普通な関数の形なので引数と戻り値がある
Predicate<T>	引数１個	戻り値１個@<br>{}（boolean固定）	Predicateは述語、述べている内容（引数）が正or否か、boolean固定なので<T,R>とは表記しない
Supplier<R>	引数（無し）	戻り値１個	Supplierは供給者、供給のみなので引数はもらいませんよ、戻り値を与えるのみ@<br>{}本当はSupplier<T>と表記しますが、分かりにくいので<R>としています
//}

//table[tbl-02-02][関数型インターフェースの種類（Bi系）]{
名前	引数	戻り値
-------------------------------------------------------------
BiConsumer<T,U>	引数２個	戻り値（無し）
BiFunction<T,U,R>	引数２個	戻り値１個
BiPredicate<T,U>	引数２個	戻り値１個@<br>{}（boolean固定）
//}

上記以外もありますが、まずはこれらを使ってみましょう。
上記以外のものは↓このパッケージを見てください。

 * rt.jar / java.util.function


== 実行するためのメソッド
//table[tbl-02-03][実行メソッド]{
名前	実行メソッド	覚え方
-------------------------------------------------------------
Runnable	run	Runnableなので、走るだけ
Consumer<T>	.accept(t)	消費者なので、Tを受け入れる（Tをもらう）
Function<T,R>	.apply(t)	Tを適用する
Predicate<T>	.test(t)	True or Falseを試すのでtest
Supplier<R>	.get()	提供者からRをgetする
BiConsumer<T,U>	.accept(t,u)
BiFunction<T,U,R>	.apply(t,u)
BiPredicate<T,U>	.test(t,u)
//}


== 演習
//note{
上記で書かれた全ての関数型インターフェースを使って、なんでもいいのでプログラムを書いてみよう！！！

組み合わせてもOK！
//}

 * @<kw>{Consumer}
 * @<kw>{Function}
 * @<kw>{Predicate}
 * @<kw>{Supplier}
 * @<kw>{BiConsumer}
 * @<kw>{BiFunction}
 * @<kw>{BiPredicate}

== サンプル
=== 参考：import
 * import java.util.function.BiConsumer;
 * import java.util.function.BiFunction;
 * import java.util.function.BiPredicate;
 * import java.util.function.Consumer;
 * import java.util.function.Function;
 * import java.util.function.Predicate;
 * import java.util.function.Supplier;

=== Consumerのサンプル
//listnum[list-02-01][サンプル][Java]{
public class Sample1 {
    public static void main(String[] args) {
        // Consumer
        // 引数１個、戻り値（無し）
        // 覚え方：Consumerは消費者、消費するだけなので引数１個で戻り値は無し！
        Consumer<Integer> cons = (t) -> {
            t *= 2;
            System.out.println(t);
        };
        cons.accept(4);
    }
}
//}

//cmd[処理結果]{
8
//}

=== Functionのサンプル
//listnum[list-02-02][サンプル][Java]{
public class Sample1 {
    public static void main(String[] args) {
        // Function
        // 引数１個、戻り値１個
        // 覚え方：Functionは関数、ごく普通な関数の形なので引数と戻り値がある
        Function<Integer, String> func = (t) -> {
            switch(t) {
                case 1:
                    return "イチです";
                case 2:
                    return "ニイです";
                case 3:
                    return "サンです";
                default:
                    return "その他です";
            }
        };
        System.out.println(func.apply(3));
    }
}
//}

//cmd[処理結果]{
サンです
//}

=== Predicateのサンプル
//listnum[list-02-03][サンプル][Java]{
public class Sample1 {
    public static void main(String[] args) {
        // Predicate
        // 引数１個、戻り値１個（boolean固定）
        // 覚え方：Predicateは述語
        Predicate<Integer> pred = (t) -> {
            if (t > 3) {
                return true;
            }
            return false;
        };
        System.out.println(pred.test(4) + ":" + pred.test(3));
    }
}
//}

//cmd[処理結果]{
true:false
//}

=== Supplierのサンプル
//listnum[list-02-04][サンプル][Java]{
public class Sample1 {
    public static void main(String[] args) {
        // Supplier
        // 引数（無し）、戻り値１個
        // 覚え方：Supplierは供給者、供給のみなので引数はもらいませんよ、戻り値を与えるのみ
        Supplier<String> supp = () -> {
            return "サプライヤーだよぉ〜ん";
        };
        System.out.println(supp.get());
    }
}
//}

//cmd[処理結果]{
サプライヤーだよぉ〜ん
//}

=== BiConsumerのサンプル
//listnum[list-02-05][サンプル][Java]{
public class Sample1 {
    public static void main(String[] args) {
        BiConsumer<Integer, String> bcon = (i,s) -> {
            String is;
            if (i > 5) {
                System.out.println("おーまーえーはー" + s);
            } else {
                System.out.println("Are you " + s);
            }
        };

        bcon.accept(6, "アーホーかー？");
        bcon.accept(5, "fool?");
    }
}
//}

//cmd[処理結果]{

//}

=== BiFunctionのサンプル
//listnum[list-02-06][サンプル][Java]{
public class Sample1 {
    public static void main(String[] args) {
        BiFunction<Integer, Integer, String> bfunc = (t,u) -> {
            if (t == null) {
                return "第一引数がnullやんけーー！";
            } else if (u == null) {
                return "第二引数がnullやんけーー！";
            }

            return "オッケーなんじゃー！";
        };

        System.out.println(apBiFunc(bfunc, null, null));
        System.out.println(apBiFunc(bfunc, null, 1));
        System.out.println(apBiFunc(bfunc, 2, null));
        System.out.println(apBiFunc(bfunc, 3, 4));
    }

    private static <T,U,R> R apBiFunc(BiFunction<T, U, R> bf, T t, U u) {
        return bf.apply(t, u);
    }
}
//}

//cmd[処理結果]{
第一引数がnullやんけーー！
第一引数がnullやんけーー！
第二引数がnullやんけーー！
オッケーなんじゃー！
//}

=== BiPredicateのサンプル
//listnum[list-02-07][サンプル][Java]{
public class Sample1 {
    public static void main(String[] args) {
        BiPredicate<Integer, Integer> bpre = (t,u) -> {
            return (t > u);
        };

        System.out.println(bpre.test(1, 2));
        System.out.println(bpre.test(2, 1));
        System.out.println(bpre.test(3, 3));
    }
}
//}

//cmd[処理結果]{
false
true
false
//}

