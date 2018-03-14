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


# PDFの作成
echo "◆PDFの作成を開始します"
# ↓pause代わり、Waitは変数になる
echo "Press the Enter Key..."
read Wait
review-pdfmaker config.yml




# EPUBの作成
echo "◆EPUBの作成を開始します"
# ↓pause代わり、Waitは変数になる
echo "Press the Enter Key..."
read Wait
review-epubmaker config.yml



# HTMLの作成
echo "◆HTMLの作成を開始します"
# ↓pause代わり、Waitは変数になる
echo "Press the Enter Key..."
read Wait
mkdir html
review-compile --target html ch01.re > ./html/ch01.html 
review-compile --target html ch02.re > ./html/ch02.html
review-compile --target html ch03.re > ./html/ch03.html
review-compile --target html ch04.re > ./html/ch04.html
review-compile --target html ch05.re > ./html/ch05.html
review-compile --target html ch06.re > ./html/ch06.html
review-compile --target html ch07.re > ./html/ch07.html
review-compile --target html ch08.re > ./html/ch08.html


