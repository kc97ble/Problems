#!/bin/bash
c=0;
for f in ??; do
  let "c=c+1"
  mv $f $c.in
done
c=0;
for f in ??.a; do
  let "c=c+1";
  mv $f $c.out
done
