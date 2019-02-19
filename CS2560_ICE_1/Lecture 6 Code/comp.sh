FILES=./*.c
for f in $FILES
do 
	echo "Processing $f file..."
	gcc -o $f.out $f
done
