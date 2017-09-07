fileName=stud.dat
i=0
j=1
while [ $j != 0 ]
do
	echo -e "Choose your option\n1: Create database\n2: View records\n3: Insert new record\n4: Modify record\n5: Delete record\n0: Exit"
	read opt
	case $opt in

		0 )
			echo "Exiting!"
			exit 0
			;;

		1) 
			echo -e "How many records do you want to insert?\n"
			read num
			while [ $i -lt $num ]
			do
				echo "Insert Roll: "
				read Roll
				echo "Insert Name: "
				read Name
				echo "Insert Address: "
				read Address
				echo "Insert Phone no: "
				read Phone
				echo -e "$Roll\t$Name\t$Address\t$Phone\n" | cat >> $fileName
				i=`expr $i + 1`
			done
			;;

		2 )
			echo -e "1: View all record\n2: View specific record"
			read choice
			if test  $choice -eq 1
				then
					cat $fileName
			else
				echo "Enter Name: "
				read Name
				grep $Name $fileName
			fi
			#how to use grep on a specific column?
			;;

		3 ) 
			echo "Insert Roll: "
			read Roll
			echo "Insert Name: "
			read Name
			echo "Insert Address: "
			read Address
			echo "Insert Phone no: "
			read Phone
			echo -e "$Roll\t$Name\t$Address\t$Phone\n" | cat >> $fileName
			;;

		4 )
			echo "Enter name of record you want to modify: "
			read mname
			temp="temp"
			grep -v $mname $fileName | cat >> $temp
			rm $fileName
			cat $temp | cat >> $fileName
			rm $temp
			echo "Insert Roll: "
			read Roll
			echo "Insert Name: "
			read Name
			echo "Insert Address: "
			read Address
			echo "Insert Phone no: "
			read Phone
			echo -e "$Roll\t$Name\t$Address\t$Phone\n" | cat >> $fileName
			;; 

		5 )
			echo "Enter name of record you want to delete:: "
			read mname
			temp="temp"
			grep -v $mname $fileName | cat >> $temp
			rm $fileName
			cat $temp | cat >> $fileName
			rm $temp
			;; 

		*)
            echo "Invalid option. Choose again!"
            ;;

	esac
done
