echo "-e Enter your option!"
read opt

case $opt in

1)
	echo "Enter file 1 name"
	read file1
	echo "Enter file 2 name"
	read file2
	cp $file1 $file2
	;;
	
2)
	echo "This is "
	;;
	
esac

