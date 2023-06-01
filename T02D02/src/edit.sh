#!/bin/bash

if [ -e "$1" ];
then

    if [ $# -eq 3 ];
    then
  
        if [ $2 != $3 ];
        then
        
            if [ $2 != "" ];
            then
                
                sed -i '' "s/$2/$3/g" "$1"

                FILENAME=$(stat -f "%N" "$1")

                FILESIZE=$(stat -f "%z" "$1")

                TIME=$(stat -f "%Sm" -t "%Y-%m-%d %H:%M" "$1")

                Hash=$(cat "$1" | shasum -a 256 | head -c 40)

                RESULT="$FILENAME - $FILESIZE - $TIME - $Hash - sha256"
                echo "$RESULT" >> files.log
      
            else
                echo "Nothing to change."
            fi
        
        else
            echo "Can not change the same strings."
        fi
  
    else
        echo "Wrong number of arguments."
    fi

else
    echo "File does not exists."
fi
