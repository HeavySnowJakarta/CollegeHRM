#!/usr/bin/env sh
# This file generates `qml.qrc` for POSIX compatible systems. The shell
# grammar is also POSIX compatible.
# Notice: Only call this script from the root path of this project.

# The initial works.
rootPath=`pwd`
relPath=/src
qrcFile=/qml.qrc
fullTargetPath=$rootPath$relPath$qrcFile

# Create the file and write the file header to it.
echo 'Starting to generate `qml.qrc`...'
echo '<!-- This file is automatically generated by `generate_qrc.sh`. -->' > $fullTargetPath
echo '<!DOCTYPE RCC><RCC version="1.0">' >> $fullTargetPath
echo '    <qresource prefix="/">' >> $fullTargetPath

# A function to get all files of a directory into the file.
# $1: The root path of the loop.
# TODO: Deal with the `src` problem.
add(){
    find "$1" -type f | while read -r file; do
        if [ `basename "$file"` != 'README.txt' ]; then
            relativePath="${file#$rootPath$relPath/}"
            echo "        <file>$relativePath</file>" >> $fullTargetPath
        fi
    done
}

# Add the files and inform the user.
inform(){
    echo "Reading directory $1"
    add $1
}

# Read the files to the target.
inform "$rootPath$relPath/assets"
inform "$rootPath$relPath/ui"

# Final works.
echo '    </qresource>' >> $fullTargetPath
echo '</RCC>' >> $fullTargetPath
echo 'Finished to generate file `qml.qrc`.'