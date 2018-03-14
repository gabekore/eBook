= もうちょい真面目に関数型プログラミング（Stream API）を解説しよう

== Stream APIの要素
Stream APIを使う時、この三つの要素を意識します。

 1. ストリーム生成（１個）
 2. 中間操作（0個以上）
 3. 終端操作（1個）

#@# == Stream APIの要素
#@# Stream APIを使う時、この三つの要素を意識します。

#@#  1. ストリーム生成（1個）
#@#  2. 中間操作（0個以上）
#@#  3. 終端操作（1個）


=== 1. ストリーム生成
==== パターン1：stream()メソッド
<collection>@<kw>{.stream()}

==== パターン2：Streamインタフェース
//listnum[list-07-01][Streamインタフェースを使うパターン][Java]{
String[] str = { "taro", "jiro", "saburo" };
Stream<String> st1 = Arrays.stream(str);
//}

//table[tbl-ch08-01][Streamインタフェース]{
Streamオブジェクト	意味
-------------------------------------------------------------
Stream<T>	要素がオブジェクトの時に使用
IntStream	要素がint型の時に使用
LongStream	要素がlong型の時に使用
DoubleStream	要素がdouble型の時に使用
//}

#@# //table[tbl-ch08-01][Streamインタフェース]{
#@# Streamオブジェクト	意味
#@# -------------------------------------------------------------
#@# Stream<T>	要素がオブジェクトの時に使用
#@# IntStream	要素がint型の時に使用
#@# LongStream	要素がlong型の時に使用
#@# DoubleStream	要素がdouble型の時に使用
#@# //}

プリミティブ型に対応しているのは@<table>{tbl-ch08-01}の下3つのみです。
char型やboolean型の場合はIntStreamを代用します。

//note{
個人的にはプリミティブ型は殆ど使わないため、@<table>{tbl-ch08-01}の下3つを使うことは無いです。
//}


=== 2. 中間操作
//table[tbl-ch08-02][中間操作]{
中間操作	意味
-------------------------------------------------------------
@<kw>{.filter()}	抽出条件、ifみたいな感覚で使えばいい
@<kw>{.map()}	要素を別の値や型に変換、.map(c -> Integer.parseInt(c))みたいな感じ
@<kw>{.mapToInt()}	要素を別のint型に変換
@<kw>{.flatMap()}	
@<kw>{.distinct()}	重複要素を削除
@<kw>{.sorted()}	ソート
@<kw>{.limit()}	要素数の制限
@<kw>{.skip()}	指定した要素をスキップ
@<kw>{.peek()}	要素の確認（デバッグ用途）
//}

#@# //table[tbl-ch08-02][中間操作]{
#@# 中間操作	意味
#@# -------------------------------------------------------------
#@# @<kw>{.filter()}	抽出条件、ifみたいな感覚で使えばいい
#@# @<kw>{.map()}	要素を別の値や型に変換、.map(c -> Integer.parseInt(c))みたいな感じ
#@# @<kw>{.mapToInt()}	要素を別のint型に変換
#@# @<kw>{.flatMap()}	
#@# @<kw>{.distinct()}	重複要素を削除
#@# @<kw>{.sorted()}	ソート
#@# @<kw>{.limit()}	要素数の制限
#@# @<kw>{.skip()}	指定した要素をスキップ
#@# @<kw>{.peek()}	要素の確認（デバッグ用途）
#@# //}


=== 3. 終端操作
//table[tbl-ch08-03][終端操作]{
終端操作	意味
-------------------------------------------------------------
@<kw>{.forEach()}	for文みたいな処理
@<kw>{.reduce()}	減らす、部分集約
@<kw>{.collect()}	汎用の集約処理
@<kw>{.allMatch()}	すべての要素が条件に合致するか否か
@<kw>{.anyMatch()}	条件に合致する要素が1つ以上あるか否か
@<kw>{.noneMatch()}	条件に合致する要素が無い
@<kw>{.findFirst()}	最初に合致した要素を返す
@<kw>{.findAny()}	最初に合致した要素を返す（順番の保証無し）
@<kw>{.min()}	最小値
@<kw>{.max()}	最大値
@<kw>{.count()}	要素の個数
@<kw>{.toArray()}	配列にする
@<kw>{.sum()}	合計する、※@<kw>{.mapToInt()}を先に使っておく
//}




