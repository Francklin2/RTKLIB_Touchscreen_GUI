#!/bin/bash
#############################################
cd $PWD/src/
sed -i 's/ crc32/ rtk_crc32/' rtkcmn.c
sed -i 's/ crc32/ rtk_crc32/' rtklib.h
sed -i 's/ crc32/ rtk_crc32/' rcv/rcvlex.c
sed -i 's/(crc32(/(rtk_crc32(/' rcv/novatel.c
#car il y avait des problèmes avec certaines fonctions
#############################################
database=$(find -name "*.c")
rm -f *.o
echo $database
#IFS est le internal field separator pour indiquer quel caractère à considérer comme saut de ligne
old_IFS=${IFS} IFS=$'\n'
for db in ${database}
do
   echo "essai compile " $db
   filename=${db%.*}
   echo "gcc -Wall -c ${db} -o $filename.o"
   #gcc -Wall -c ${db} #-o $filename".o"
   gcc -c ${db} -Wall -O3 -ansi -pedantic -I. -DTRACE -DENAGLO -DENAGAL -DENAQZS -DNFREQ=3
done
echo "fini compil"
IFS=${old_IFS}
#############################################
# library creation
database=$(find -name "*.o")
old_IFS=${IFS} IFS=$'\n'
#for db in ${database}
#do
#  ar ruscP librtk.a ${db}
#done
ar ruscP librtk.a ${database}

IFS=${old_IFS}
mv librtk.a ../librtk.a
cp rtklib.h ../rtklib.h
rm *.o
echo "fini ar"
#############################################
