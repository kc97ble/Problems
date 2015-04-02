#!/bin/bash
mkdir __statement
for i in *; do 
	cp "$i/statement/$i.pdf" "__statement/$i.pdf"
done

