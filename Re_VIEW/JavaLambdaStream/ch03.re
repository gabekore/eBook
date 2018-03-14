= メソッド参照

引数や戻り値が分かりきっている場合に、@<kw>{::} を使って書くこともできます。

特に説明はしません。コードを見てください。

 * 分かりきっているんだから書かなくていいじゃん！
 * 書く文字数が減ってシンプルでGood！！

ってな軽い感じで理解すればいいでしょう。

難しく考えすぎない！


//listnum[list-03-01][メソッド参照のサンプル][Java]{
public class Sample1 {
    private static void Main() {
        Consumer<String> cons = System.out::println;
        cons.accept("aiueo");

        Function<Integer, String> func = String::valueOf;
        cons.accept(func.apply(4));
    }
}
//}
