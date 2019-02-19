FILES=./*.out
for f in $FILES
do
	echo "Running File $f..."
	$f
	echo ""
	echo ""
done
