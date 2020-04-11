long repeatedString(string s, long n) {

long int size = s.size();
long int quotient = n/size;
long int remainder = n%size;
long int countFull = 0;
long int countRemain = 0;

for(int i = 0; i<size; i++) {
    if(s[i] == 'a') {
        countFull++;       
    }
}

if(remainder!=0) {
    for(int i = 0; i<remainder; i++) {
        if(s[i] == 'a') {
            countRemain++;
        }
    }
}

long int total = quotient*countFull + countRemain;

return total;
}
