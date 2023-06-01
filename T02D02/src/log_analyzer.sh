if [ -e "$1" ];  # если файл найден, то:
then

#    file_name=$(awk '{print $1}' "$1" | wc -l)
#    unique_files=$(awk '{print $1}' "$1" | uniq | wc -l)
#    change_hash=$(awk '{print $8}' "$1" | uniq | wc -l)
#    echo "$file_name $unique_files $change_hash"

    echo ` awk '{print $1}' "$1" | wc -l`' '` awk '{print $1}' "$1" | uniq | wc -l`' '` awk '{print $8}' "$1" | uniq | wc -l`

else
    echo "File does not exists."
fi
