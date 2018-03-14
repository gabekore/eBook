= とりあえず、関数型プログラミングをやってみよう！

== 関数型プログラミングの基本形
Javaにおける関数型プログラミングの形はこんな形になります。

//listnum[list-06-01][Javaにおける関数型プログラミングの形][Java]{
    // 改行は任意
    // cole：コレクション
    // xxxx：関数
    // y   ：変数（コレクションの要素の一つ）
    // zzzz：処理
    cole.stream()
            .xxxx(y -> zzzz)
            .xxxx(y -> zzzz)
            .xxxx(y -> zzzz);

    // ↑このようにピリオドでメソッドをつなげていくのを
    //   メソッドチェーンと言います
//}

//note[個人的な偏見？]{
個人的には、Javaにおいて通常の配列を使うメリットは無いと思っています。

もちろん無意味にList等を使う必要は無いですし、意味があるなら通常の配列でもいいです。

しかし、関数型プログラミングを使うことが普通になれば通常の配列のメリットなんてゼロだと考えています。
//}

=={mondai-ch07-01} 関数型プログラミングの第一歩
=== 問題
//note{
@<kw>{List<String> liName = Arrays.asList("Tanaka", "Yamada", "Suzuki", "Hirata");}

@<kw>{liName}が持つ文字列全てを画面に表示せよ！

※ヒント：@<kw>{forEach}を使う
//}

=== 解答
参照：@<hd>{chA|ans-ch07-01}


=={mondai-ch07-02} @<kw>{.filter()}を使ってみよう

@<b>{『List<String>が持つ文字列で、5文字以上のみを表示しなさい』}

という問題が出た場合、あなたなら以下のようなプログラムを書きますか？

//listnum[list-06-02][@<kw>{.filter()}を使ってみよう][Java]{
public class Sample {
    public static void main(String[] args) {
        List<String> liName = Arrays.asList("ai","ueo","kaki","kukeko","sasisu","seso","tatituteto");

        for (String name : liName) {
            if (name.length() > 4) {
                System.out.println(name);
            }
        }
    }
}
//}

//cmd[処理結果]{
kukeko
sasisu
tatituteto
//}


.

.

.

.

.

.

.

.

.

.

.

.

Yesと答えたあなた、


@<b>{ダサいですっっっっっ！！！}

@<b>{超絶にダサいですっっっっっ！！！}

　


どうするかと言うと、@<kw>{.stream()}や@<kw>{.filter()}を使います。


ってことで、↓問題をどうぞ！

=== 問題
//note{
List<String> liName = Arrays.asList("ai","ueo","kaki","kukeko","sasisu","seso","tatituteto");

@<kw>{liName}が持つ文字列で、@<b>{5文字以上のみ}を画面に表示せよ！

※ヒント：@<kw>{.filter()}を使う
//}

=== 解答
参照：@<hd>{chA|ans-ch07-02}






=={mondai-ch07-03} @<kw>{.mapToInt()}を使ってみよう

@<b>{『List<Integer>が持つ数値で、10以上のみを合計しなさい』}

という問題が出た場合、あなたならどんなプログラムを書きますか？

まずは、直感で書いてみてください。

※多分コンパイル通らないと思いますが、それでいいのでまずは「こんな感じで書くんじゃないかなぁ？」という感じで書いてみてください。

.

.

.

.

.

.

.

.

.

.

.

.

直感で書いてみましたか？

.

.

.

//listnum[list-06-03][@<kw>{.filter()}を使ってみよう][Java]{
public class Sample {
    public static void main(String[] args) {
        List<Integer> ls = Arrays.asList(10,4,9,2,14,8,6);

        int total = ls.stream()
                      .filter(i->i > 9)
                      .sum();

        System.out.println("sum : " + Integer.toString(total));
    }
}
//}

//cmd[（希望する）処理結果]{
sum : 24
//}

↑

直感でこんな風な書き方をできていればOKです。

あとは、Javaの文法的な微調整をするだけです。


=== 問題
//note{
List<Integer> ls = Arrays.asList(10,4,9,2,14,8,6);

@<kw>{ls}が持つ数値で、@<kw>{10以上のみ}を合計しなさい！

※ヒント：@<kw>{.mapToInt()}を使う
//}

=== 解答
参照：@<hd>{chA|ans-ch07-03}


