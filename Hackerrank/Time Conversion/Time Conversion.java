static String timeConversion(String s) {
        boolean isAM = s.endsWith("AM"); //check if time is AM or PM
        short hour = Short.valueOf(s.substring(0, 2)); //get the hour value

        s = s.substring(0, s.length() - 2);

        if(isAM) {
            if(hour == 12)
                s = "00" + s.substring(2);   //if 12 oclock, 24 hr format is 00 so just add minutes         
        } else {
            if(hour < 12)
                s = (hour + 12) + s.substring(2); 
        }

        return s;
    }
