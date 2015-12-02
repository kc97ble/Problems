#!/bin/bash

nt=0
function nextTest {
  nt=$(($nt+1))
  fn=`printf "%02d" $nt`
  echo "Test $fn: $1"
  echo -n "                <test points = \"$2\" comment = \"" >> "testset.xml"
  $1 > $fn 2>> "testset.xml" || exit
  echo -n $3 >> "testset.xml"
  echo "\" />" >> "testset.xml"
}
function groupHeader {
  echo "Группа: $1"
  echo "            <test-group" >> "testset.xml"
  echo "                comment = \"$1\"" >> "testset.xml"
  echo "                score = \"$3\"" >> "testset.xml"
  echo "                feedback = \"group-score\"" >> "testset.xml"
  echo "                group-bonus = \"$2\"" >> "testset.xml"
  echo "            >" >> "testset.xml"
}
function groupFooter {
  echo -e "            </test-group>" >> "testset.xml"
  echo "Последний тест группы: $nt"
}

echo "=== Prepare ==="

name="garden"
echo "== Wipe"
rm -f {0..9}{0..9}{,.a}
echo "== Compile checker"
if ! [ -e check.exe ] || [ ../check.cpp -nt check.exe ] ; then
  g++ -O2 -Wall -I../tools -o check.exe ../check.cpp
fi
echo "== Compile generators"
for f in "gt_log" "gt_n2" "gt_rand" "gt_rand2" "gt_window" "gen_sk_1" "gen_sk_2" "gen_rand" "gen_anti_n2" ; do
  if ! [ -e $f.exe ] || [ $f.cpp -nt $f.exe ] ; then
    g++ -O2 -Wall -o $f.exe $f.cpp
  fi
done
echo "== Compile solution"
sol="../${name}_yp"
if ! [ -e $sol.exe ] || [ $sol.pas -nt $sol.exe ] ; then
  fpc -o"${sol}.exe" "${sol}.pas"
fi

echo "=== Tests ==="
rm -f {problem,testset}.xml
groupHeader "Оранжерея квадратная, длина стороны не превышает 10, количество растений не превышает 6" "10" "group"
nextTest "cat test1_0.manual" "0" "Один квадрат"
nextTest "cat test1_1.manual" "0" "Один квадрат"
nextTest "cat test4_0.manual" "0" "Четыре квадрата"
nextTest "cat test6_0.manual" "0" "Шесть квадратов"
groupFooter
groupHeader "Длины стороны не превышает 20, количество растений не превышает 20" "20" "group"
nextTest "./gt_n2.exe 3 239" "0"
nextTest "./gen_sk_1.exe 11 3 800" "0"
nextTest "./gen_sk_1.exe 15 4 800" "0"
nextTest "./gen_sk_1.exe 13 3 800" "0"
nextTest "./gen_sk_1.exe 18 4 800" "0"
nextTest "./gen_rand.exe 17 20 890 301703" "0"
nextTest "./gen_rand.exe 20 19 890 301703" "0"
nextTest "./gen_rand.exe 20 20 890 301703" "0"
nextTest "./gt_window.exe 4 1 239" "0"
groupFooter
groupHeader "Длины стороны не превышает 1000, количество растений не превышает 1000" "30" "group"
nextTest "./gt_log.exe 3 1 3017" "0"
nextTest "./gt_n2.exe 30 239" "0"
nextTest "./gen_rand.exe 500 780 890 301703" "0"
nextTest "./gen_rand.exe 239 17 890 301703" "0"
nextTest "./gen_rand.exe 1000 999 890 301703" "0"
nextTest "./gen_rand.exe 1000 1000 890 301703" "0"
nextTest "./gen_rand.exe 1 999 890 301703" "0"
nextTest "./gen_rand.exe 1000 999 890 301703" "0"
nextTest "./gt_window.exe 239 2 239" "0"
groupFooter
groupHeader "Длины стороны не превышает 200000, количество растений не превышает 200000" "0" "sum"
nextTest "./gt_log.exe 10 3 301703" "2"
nextTest "./gt_n2.exe 400 239" "2"
nextTest "./gen_anti_n2.exe 2500" "2"
nextTest "./gt_rand.exe 450 5 239" "2"
nextTest "./gt_rand2.exe 450 100 239" "2"
nextTest "./gt_window.exe 40450 1 239" "2"
nextTest "./gen_sk_2.exe 239 3 100" "2"
nextTest "./gen_sk_2.exe 239 4 500" "2"
nextTest "./gen_rand.exe 200000 197999 750 301703" "2"
nextTest "./gen_rand.exe 200000 200000 750 301703" "2"
groupFooter
groupHeader "Длины стороны не превышает 10^12, количество растений не превышает 200000" "0" "sum"
nextTest "./gt_log.exe 13 35938722" "2"
nextTest "./gt_n2.exe 49999 3017" "2"
nextTest "./gen_anti_n2.exe 2500" "2"
nextTest "./gt_rand.exe 1000 13 736" "2"
nextTest "./gt_rand2.exe 1000 100 673" "2"
nextTest "./gt_window.exe 49999 666666 301703" "2"
nextTest "./gen_sk_2.exe 239 5 550" "2"
nextTest "./gen_rand.exe 1000000000000 979900000000 950 301703" "2"
nextTest "./gen_rand.exe 979900000000 1000000000000 950 301707" "2"
nextTest "./gen_rand.exe 1000000000000 1000000000000 950 301701" "2"
groupFooter


echo "=== Answers ==="
for f in {0..9}{0..9} ; do
  if [ -e $f ] ; then
    echo "Test $f"
    cp "${f}" "${name}.in"
    time ./$sol.exe
    cp "${name}.out" "${f}.a"
    ./check.exe "${name}.in" "${name}.out" "${name}.out"
  fi
done

echo "=== Problem config ==="
cat "header.xml" | iconv -f=utf8 -t=cp1251 >> problem.xml
cat "testset.xml" | iconv -f=utf8 -t=cp1251 >> problem.xml
cat "footer.xml" | iconv -f=utf8 -t=cp1251 >> problem.xml
