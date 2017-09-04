i=0
j=1
while [ $j != 0 ]
do
    echo -e "Choose your option:\n1: Enter initial entry\n2: Find a record\n3: No. of records\n4: Enter additional records"
    echo "Press 0 to exit"
    read opt
    case $opt in 
        0)
            echo "Exiting!"
            exit 0
            ;;

        1)
            echo "How many students do you want to enter?"
            read ch
            while [ $i -lt $ch ]
            do
                echo "Enter Roll No of student `expr $i + 1`"
                read rno
                echo "Enter Name of student `expr $i + 1`"
                read name
                echo -e "$rno\t$name" >> std.dat
                i=`expr $i + 1`
            done
            ;;

        2)
            echo "Enter Roll No you want to find"
            read rno

            grep $rno std.dat
            ;;

        3)
            echo "The no of records are: "
            wc -l std.dat | cut -c1
            ;;

        4) 
            echo "How many additional records do you want to enter?"
            read ch1
            j=0
            while [ $j -lt $ch1 ]
            do
                echo "Enter Roll No of student `expr $j + $i + 1`"
                read rno
                echo "Enter Name of student `expr $j + $i + 1`"
                read name
                echo -e "$rno\t$name" >> std.dat
                j=`expr $j + 1`
            done
            ;;

        *)
            echo "Invalid optio. Choose again!"
            ;;

        esac
    
done