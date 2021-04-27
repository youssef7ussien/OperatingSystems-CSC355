#!/bin/bash


# (i) Create a directory in your home directory having 2 subdirectories

mainDirectory="Operating Systems (CSC 355)"
subDirectories=("Sheet 1" "Sheet 2" "Sheet 3" "Test")

readonly mainDirecory
readonly subDirectories

for i in ${!subDirectories[@]}; do
    mkdir -p "$mainDirectory/${subDirectories[$i]}"
done

echo "(1) Create directories completed."

# (ii) In the first sub directory create 3 different files with different
# content in each of them.

cat << EOF > "$mainDirectory/${subDirectories[0]}/File 1.txt"
Hello 1!
This is "File 1" in subdirectory "${subDirectories[0]}" in directory "$mainDirectory"
EOF

cat << EOF > "$mainDirectory/${subDirectories[0]}/File 2.txt"
Hello 2!
This is "File 2" in subdirectory "${subDirectories[0]}" in directory "$mainDirectory"
EOF

cat << EOF > "$mainDirectory/${subDirectories[0]}/File 3.txt"
Hello 3!
This is "File 3" in subdirectory "${subDirectories[0]}" in directory "$mainDirectory"
EOF

echo "" ; echo "(2) Create files completed."

# (iii) Copy the first file from the first subdirectory to the second subdirectory.

echo ""
cp "$mainDirectory/${subDirectories[0]}/File 1.txt" "$mainDirectory/${subDirectories[1]}"
echo "(3) Copy completed."

# (iv) Create one more file in the second subdirectory which has the output of
# the number of users and number of files.

cd "$mainDirectory/${subDirectories[1]}/"

cat << EOF > "File 2.txt"
The number of files in (`pwd`)
= `ls | wc -l` (without this file)

The number of users = `who | wc -l`
EOF

cd .. ; cd ..

echo "" ; echo "(4) Create file completed."


# (v) List all the files which starts with either a or A.

filesName=("After" "script" "execute" "Agenda" "available" "Art")

readonly filesName

for i in ${!filesName[@]}; do
    touch "$mainDirectory/${subDirectories[3]}/${filesName[$i]}.txt"
done

echo "" ; echo "(5) List files which starts with 'a' or 'A': "

cd "$mainDirectory/${subDirectories[3]}/"

ls -d [aA]*

cd .. ; cd ..


# (vi) Count the number of files in the current directory.

echo "" ; echo "(6) The number of files in (`pwd`): `ls | wc -l`"

# (vii) Display the output if the compilation of a program succeeds.

echo "" ; echo "(7) The program completed successfully."
