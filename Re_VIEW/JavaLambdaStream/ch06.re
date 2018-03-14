= 関数型プログラミングについて

前章まででラムダ式を覚えられましたでしょうか？

実際の所、ラムダ式@<b>{だけ}を覚えたところで、実用面でのメリットは少ないでしょう。

StreamAPI・Enum等組み合わせて使うことによってラムダ式のメリットが大きくなります。

//note{
Javaにおける関数型プログラミングの定義ですが、

@<b>{関数型プログラミング = StreamAPI + ラムダ式}

だと思います。
タブン・・・（ごめんなさい、筆者はよく分かりません・・・・）
//}


ここからはStreamAPIを学びます。@<br>{}
ラムダ式がナチュラルに出てきますし、特に解説しませんので注意してね♪

NetBeansやEclipse等の統合開発環境を使っている場合、@<kw>{(} を打つとインテリセンスで引数等のToolTipが見えると思います。@<br>{}
そのToolTipで関数インターフェースが出てくれば、引数として関数インターフェース（ラムダ式）を要求されているということです。

== 臭いプログラム（Code smell）

もしあなたが以下のようなコードを書いていれば、「臭いプログラマ」とか「臭いプログラム」@<fn>{codesmell}と言われても仕方ありません。
//footnote[codesmell][code smell： https://ja.wikipedia.org/wiki/コードの臭い]


//listnum[list-05-01][任意の文字列の存在をチェックするプログラム][Java]{
public class Sample {
    public static void main(String[] args) {

        // 文字列の集まりの中に"hit"という文字列があるか否かを知り合い

        boolean found = false;
        String strs[] = {"aaa", "bbb", "hit", "ccc", "ddd"};

        for (String str : strs) {
            if (str.equals("hit")) {
                found = true;
                break;
            }
        }

        if (found) {
            System.out.println("hitはありました");
        } else {
            System.out.println("hitは無いです");
        }
    }
}
//}


//cmd[処理結果]{
hitはありました
//}


=={mondai-ch06-01} 臭くないコードに書き直す
=== 問題
//note{
臭くないコードに書き直せ！！！
//}

=== 解答
参照：@<hd>{chA|ans-ch06-01}



