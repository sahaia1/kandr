num1=`python hex_to_decimal.py $1`
num2=`python hex_to_decimal.py $2`
num3=`echo "python -c 'print $num1 - $num2'" | bash`
echo `python decimal_to_hex.py $num3`

