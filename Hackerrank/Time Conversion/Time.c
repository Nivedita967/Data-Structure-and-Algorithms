char* timeConversion(char* s) 
{
    /*
     This code is messy and could be better than this but it pass all the test case
     */
    if(s[0]=='1'&& s[1]=='2' && s[8]=='A') //Checks for 12:XX AM
    {
        s[0]='0';
        s[1]='0';
        goto end;
    }
    if(s[8]=='P') //Checks for PM
    {
        if(s[0]=='1'&& s[1]=='2')// 12:XX PM
        goto end;
        if(s[0]=='1') //10:XX PM or 11:XX PM
        {
            s[0]='2';
            s[1] += 2;
            goto end;
        }
        if(s[1]<='7') //No carry till 7:XX PM
        {
            s[0]='1';
            s[1] += 2;
        }
        else
        {
            s[0]='2'; //A carry after 8:XX PM
            if(s[1]=='8')
                s[1]='0';
            else if(s[1]=='9')
                s[1]='1';
            else
                s[1] += 2;
            goto end;
        }
    }
    end:
    s[8]='\0';
    return s;
}
