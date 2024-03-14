import java.util.Scanner;

public class viikonpaiva {
    
    /* We have stored here some 100% certain weekdays at the turn of 21th century.
    notice the pattern - normal year has 365 and leap year 366 days.
    resolting to (365)%7 = 1 and (366)%7 = 2 changes in the weekdays index.*/
    static String[] weekdays = {"maanantai", "tiistai", "keskiviikko", "torstai", "perjantai", "lauantai", "sunnuntai"};
    static int[] daysPerMonthsNormalYear = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    static int[] daysPerMonthsLeapYear = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};;
    static int firstJanuary2000 = 5; // index 5 from weekdays list
    static int lastDecember1999 = -3; // notice that the index is reserved, more info negIndexToPos

    // scanner is needed to receive the input of date
    static Scanner scan = new Scanner(System.in);

    //---------------------------------------------------------------------------------------------------------
    


    //---------------------------------------
    // START THE MAIN METHOD!!!
    //---------------------------------------
    public static void main(String [] Args) {
        String date = scan.nextLine(); // test date, later replace with scan
        String [] splitDate = date.split("\\.");
        int years = Integer.parseInt(splitDate[2]);
        int months = Integer.parseInt(splitDate[1]);
        int days = Integer.parseInt(splitDate[0]); 

        if (years >= 2000) {
            // calculate forward from 1.1.2000
            System.out.println(calculateForward(years, months, days));
        } 
        else {
            // calculate backwards from 31.12.1999
            System.out.println(calculateBackward(years, months, days));
        }
        
    }

    //---------------------------------------------------------------------------------------------------------


    //---------------------------------------
    // START calculateForward
    //---------------------------------------

    // currentYear to determine if it is a leap year
    // daysPerMonth to store correct amount of days for each month (note the daysPerMonthsNormalYear and daysPerMonthsLeapYear arrays)
    // this function starts calculating starting from 1.1.2000
    // decide which daysPerMonth array we use depending on leap year:
    // to avoid misunderstandings, we first store startingDayOfYear to indexOfDays
    // Now we know first weekday of our target year, and just add months and days as days to the index.
    // for example 31+28+14 would be 14th of march and therrefore would add 73 days to the index.
    // we use month -1 because the last month is only partially used (like if we need 10th february, we take 31 from january)
    private static String calculateForward(int year, int month, int day) {
        int startingDayOfYear = firstJanuary2000;
        int currentYear; 
        int [] daysPerMonths; 

        for (currentYear = 2000; currentYear < year; currentYear ++) {
            if (currentYear % 400 == 0 || currentYear % 4 == 0 && currentYear % 100 != 0) {
                startingDayOfYear += 2;
            } else {
                startingDayOfYear += 1;
            }
        }
        
        if (currentYear % 400 == 0 || currentYear % 4 == 0 && currentYear % 100 != 0) {
            daysPerMonths = daysPerMonthsLeapYear;
        } else {
            daysPerMonths = daysPerMonthsNormalYear;
        }
        
        int indexOfDays = startingDayOfYear; 

        for (int i = 0; i < month-1; i++) {
            indexOfDays += daysPerMonths[i];
        }
        indexOfDays += day-1; // as noticed, remove one days because we are alrdy 1th day of the month;

        return weekdays[indexOfDays%7];
    }

    // --------------------------------------------------------------------------------------------------------



    //---------------------------------------
    // START calculateBackward
    //---------------------------------------

    // here we basically do the reverse of calculateForward, so we go backwards every step
    // notice that 31.12.1997 = keskiviikko, 31.12.1996 = tiistai but 31.12.1995 = sunnuntai
    // so we need to during leap year tkae away -2 index
    // please note that negIndexToPos contains the %7 operation.
    private static String calculateBackward(int year, int month, int day) {
        int endingDayOfYear = lastDecember1999;
        int currentYear; 
        int [] daysPerMonths; 

        for (currentYear = 1999; currentYear > year; currentYear -= 1) {
            if ((currentYear) % 400 == 0 || (currentYear) % 4 == 0 && (currentYear) % 100 != 0) {
                endingDayOfYear -= 2;
            }
            else {
                endingDayOfYear -= 1;
            }
        }

        // return weekdays[negIndexToPos(endingDayOfYear)]; tested that the last day of year works fine!!!

        // test which daysOfMonth array we use to calculate days of months:
        if ((currentYear) % 400 == 0 || (currentYear) % 4 == 0 && (currentYear) % 100 != 0) {
                daysPerMonths = daysPerMonthsLeapYear;
        } else {
                daysPerMonths = daysPerMonthsNormalYear;
        }

        int indexOfDays = endingDayOfYear;

        // add to the index all full before target month
        for (int i = 11; i > month-1; i --) {
            indexOfDays -= daysPerMonths[i];
        }

        // add the days of the target month (for example 15th october = 31-15 = 16 -> indexOfDays -= 16)
        indexOfDays -= (daysPerMonths[month-1] - day);

        return weekdays[negIndexToPos(indexOfDays)];


    }

    // ------------------------------------------------------------------------------------------------------



    //---------------------------------------
    // START negIndexToPos
    //---------------------------------------

    private static int negIndexToPos(int number) {
        int positiveIndex = 0;
        number = number % 7;

        if (number == -1) {
            positiveIndex = 6;
        } 
        else if (number == -2) {
            positiveIndex = 5;
        } 
        else if (number == -3) {
            positiveIndex = 4;
        } 
        else if (number == -4) {
            positiveIndex = 3;
        } 
        else if (number == -5) {
            positiveIndex = 2;
        } 
        else if (number == -6) {
            positiveIndex = 1;
        } 
        else if (number == 0) {
            positiveIndex = 0;
        }

        return positiveIndex;
    }
}

// ------------------------------------------------------------------------------------------------------