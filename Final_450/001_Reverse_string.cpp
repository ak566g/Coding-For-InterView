
string reverseWord(string str){
    int i = 0;
    int j = str.size()-1;
    
    while(i<j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    
    return str;
}