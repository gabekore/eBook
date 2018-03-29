#!/bin/bash

# このシェルの起動ディレクトリに移動
echo "◆カレントディレクトリ"
cd `dirname $0`
pwd
# ↓pause代わり、Waitは変数になる
echo "Press the Enter Key..."
read Wait


echo "◆Rubyのバージョン"
ruby -v
# ↓pause代わり、Waitは変数になる
echo "Press the Enter Key..."
read Wait

echo "binフォルダ作成"
mkdir bin
# ↓pause代わり、Waitは変数になる
echo "Press the Enter Key..."
read Wait


# PDFの作成
echo "◆PDFの作成を開始します"
# ↓pause代わり、Waitは変数になる
echo "Press the Enter Key..."
read Wait
review-pdfmaker config.yml
mv *.pdf ./bin/.


# EPUBの作成
echo "◆EPUBの作成を開始します"
# ↓pause代わり、Waitは変数になる
echo "Press the Enter Key..."
read Wait
review-epubmaker config.yml
mv *.epub ./bin/.



# HTMLの作成
echo "◆HTMLの作成を開始します"
# ↓pause代わり、Waitは変数になる
echo "Press the Enter Key..."
read Wait
mkdir ./bin/html
review-compile --target html ch01.re > ./bin/html/ch01.html 
review-compile --target html ch02.re > ./bin/html/ch02.html
review-compile --target html ch03.re > ./bin/html/ch03.html
review-compile --target html ch04.re > ./bin/html/ch04.html
review-compile --target html ch05.re > ./bin/html/ch05.html
review-compile --target html ch06.re > ./bin/html/ch06.html
review-compile --target html ch07.re > ./bin/html/ch07.html
review-compile --target html ch08.re > ./bin/html/ch08.html
review-compile --target html ch09.re > ./bin/html/ch09.html
review-compile --target html chA.re  > ./bin/html/chA.html


