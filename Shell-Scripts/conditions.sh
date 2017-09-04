echo "Enter marks of subject 1: "
read s1
echo "Enter marks of subject 2: "
read s2
echo "Enter marks of subject 3: "
read s3
echo "Enter marks of subject 4: "
read s4
echo "Enter marks of subject 5: "
read s5
sum1=`expr $s1 + $s2 + $s3 + $s4 + $s5`
res1=`expr $sum1 / 5`
if test $res1 -ge 65
  then
  echo "Congrats you have got distinction!"
  
elif test $res1 -gt 60 -a $res1 -lt 65
  then
  echo "Congrats you have got 1st Class!"
  
elif test $res1 -gt 55 -a $res1 -lt 60
  then
  echo "Congrats you have got 2nd Class!"
  
elif test $res1 -gt 50 -a $res1 -lt 65
  then
  echo "Congrats you have got 3rd Class!"
  
else
  echo "Unfortunately you are failed!"
fi
