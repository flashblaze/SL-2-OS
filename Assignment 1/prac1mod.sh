fileName="addressBook"
j=1;
i=0;

while [ $j != 0 ]; do
	echo -e "Choose your options:\n1: Create database\n2: View records\n3: Insert new record\n4: Modify record\n5: Delete record\n0: Exit"
	read opt;

	case $opt in
		0 )
			echo "Exiting!"
			exit 0
			;;

		1 )
			if [ -e $fileName ]; then
				rm $fileName
			fi
			echo "How many records do you want to enter? "
			read ans
			while [ $i -lt $ans ]
			do
				echo "Enter name: "
				read name
				echo "Enter roll: "
				read roll
				echo "Enter tele: "
				read tele
				echo -e "$name\t$roll\t$tele" | cat >> $fileName
				i=`expr $i + 1`
			done
			;;

		2 )
			echo -e "How do you want to view records?\n1: All records\n2: Particular record"
			read ans2
			if [ $ans2 -eq 1 ]
			then
				cat $fileName
			else
				echo "Enter name to search: "
				read name2
				grep $name2 $fileName
			fi
			;;

		3 )
			echo "Enter name: "
			read name
			echo "Enter roll: "
			read roll
			echo "Enter tele: "
			read tele
			echo -e "$name\t$roll\t$tele" | cat >> $fileName
			;;

		4 )
			echo "Enter name of the record to modify: "
			read name3
			temp="temp"
			grep -n $name3 $fileName
			RETURNSTATUS=`echo $?`
			if [ $RETURNSTATUS -eq 1 ]
			then
				echo "No record found!"
			else
			grep -v $name3 $fileName | cat >> $temp
			rm $fileName
			cat $temp | cat >> $fileName
			rm $temp
			echo "Enter name: "
			read name
			echo "Enter roll: "
			read roll
			echo "Enter tele: "
			read tele
			echo -e "$name\t$roll\t$tele" | cat >> $fileName
			fi
			;;
		5 )
			echo "Enter name of the record to delete: "
			read name3
			temp="temp"
			grep -n $name3 $fileName
			RETURNSTATUS=`echo $?`
			if [ $RETURNSTATUS -eq 1 ]
			then
				echo "No record found!"
			else
			grep -v $name3 $fileName | cat >> $temp
			rm $fileName
			cat $temp | cat >> $fileName
			rm $temp
			fi
			;;

		* )
			echo "Incorrect option! Choose again"				

	esac
done