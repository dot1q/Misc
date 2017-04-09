using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;                        // Import the whole library because I am lazy



namespace assignment1
{


    class Program
    {

        const float MAX_INTEREST_RATE = 10;       // ---> Don't be mad that it's global, it's not like I'm storing user data here!
        const float MAX_STARTING_CAPITAL = 1000;
        const int MAX_COMPOUND_PERIODS = 25;
        const int MAX_INTEREST_INTERVALS = 25;

        public struct User_args  
        {  
            public float min_interest_rate;
            public float max_interest_rate;
            public float starting_capital;
            public int num_of_periods;
            public int num_of_interest_intervals;
        }  

        /*
         * Main Method
         */
        static void Main(string[] args)
        {
            string html_js_arr;
            User_args user_input = new User_args();
            // Begin by gathering the user input
            Get_user_input(ref user_input);

            html_js_arr = Compute_interest_rates(ref user_input);

            // Write the file output
            Write_file(ref html_js_arr);

            System.Console.ReadLine();

        }

        /********************************************************************* 
         ** Function: Computes all the interest rates
         ** Description: Takes in the user struct and returns the interest rate string to write to file
         ** Parameters: Referenced User_args struct
         ** Pre-Conditions: All struct values should be non null
         ** Post-Conditions: string that is Javascript ready
         *********************************************************************/
        private static string Compute_interest_rates(ref User_args user_input)
        {
            string js_arr_str = "[['Period',";          // setting up the string
            double[] interest_rates = new double[user_input.num_of_interest_intervals + 1];                           // This will create a fixed interest rate constant from user input
            double interest_rate = Math.Round( ((user_input.max_interest_rate - user_input.min_interest_rate) / user_input.num_of_interest_intervals), 2);

            for (int x = 0; x < interest_rates.Length; x++)
            {
                
                interest_rates[x] = interest_rate * x + user_input.min_interest_rate;
                js_arr_str += "'" + interest_rates[x] + "%'";

                if (x + 1 != interest_rates.Length)
                    js_arr_str += ",";
            }
            js_arr_str += "],";             // If this is the last loop, don't print a comma. Javascript is cool and allows this, but I'm picky. 


            // Loop through periods gathered from user input. We want to do this first, because the Google API requires our Y axis to be rows
            for (int y = 0; y < user_input.num_of_periods; y++)
            {
                js_arr_str += "['" + (y + 1) + "',";

                // Go through the previously stored interest rates
                for (int x = 0; x < interest_rates.Length; x++)
                {
                    // compute the compund interest
                    double amount = Math.Round( (user_input.starting_capital * System.Math.Pow(1 + (interest_rates[x] / 100), y + 1)) ,2);
                    js_arr_str += amount;       // append to string. No need to put in quotes, it is a number, and javascript does not require elements to be cast a strings
                    //System.Console.Write("$" + amount + ", ");
                    if (x+1 != interest_rates.Length)
                        js_arr_str += ",";
                }
                js_arr_str += "]";              // This will close the javascript array
                if(y+1 != user_input.num_of_periods)        // If this is the last loop, don't print a comma. Javascript is cool and allows this, but I'm picky. 
                    js_arr_str += ",";
            }
            return js_arr_str+"]";          //return string with closing bracket
        }


        /********************************************************************* 
         ** Function: Write the file
         ** Description: Will created/access directory, and create/overwrite foo.html and overwrite contents with passed referenced string
         ** Parameters: Referenced string js_arr_str
         ** Pre-Conditions: js_arr_str should not be null! At the minimum, it should have a [] for Javascript to be happy
         ** Post-Conditions: returns nothing
         *********************************************************************/
        private static void Write_file(ref String js_arr_str)
        {
            System.IO.StreamWriter output_file_obj = null;                  // declare output file object, but leave it null since we are going to 'try' to set it later
                                                                            // yeah, we're sticking it in a folder. Gonna spice it up a bit
            while (!Directory.Exists("outputs"))
            {
                try{
                    Directory.CreateDirectory("outputs");                   // try to make the directory if it doesn't not exist
                } catch
                {
                    System.Console.WriteLine("FATAL ERROR! Directory not writeable!");
                    System.Console.ReadLine();
                    System.Environment.Exit(1);                             // This is fatal error, gracefully return control to OS
                }
            }       // directory exists now


            try
            {
                // Attempt to open file for writing, but overwrite, not append
                output_file_obj = new System.IO.StreamWriter("outputs\\foo.html", false);
            } catch
            {
                // File could not be opened, probably a fatal error
                System.Console.WriteLine("FATAL ERROR! File not found, and could not create a file either. This is very bad.");
                System.Console.ReadLine();
                System.Environment.Exit(1);
            }

            string html1 = "<html>" +           // the joys of attempting to format multiline strings
 "<head>" +
  "<script type=\"text/javascript\" src=\"https://www.google.com/jsapi\"></script>" +
    "<script type =\"text/javascript\">" +
  "google.load(\"visualization\", \"1\", {packages:[\"linechart\"]});" +
  "google.setOnLoadCallback(drawChart);" +
            "function drawChart() {" +
                "var data = google.visualization.arrayToDataTable(";

            string html2 = ");" +
                "var chart = new google.visualization.LineChart(document.getElementById('chart_div'));" +
                "chart.draw(data, { width: 1000, height: 500, legend: 'bottom', title: 'Compound Interest Profiles'});" +
            "}" +
"</script>" +
 "</head>" +
  "<body>" +
"<div id=\"chart_div\"></div>" +
   "</body>" +
  "</html>";                        // glad that's over...
            output_file_obj.WriteLine(html1 + js_arr_str + html2);              // concatenate this dude, and write it to the file
            // yeah, it's not large enough and the user input limits are small, so I am not going to put this into a string buffer for writing to the file! SORRY.
            output_file_obj.Close();
            System.Console.WriteLine("\r\nYour html file is outputted to the following directory...\r\n" + Directory.GetCurrentDirectory() + "\\outputs\\foo.html");
            System.Diagnostics.Process.Start("outputs\\foo.html");
        }


        /********************************************************************* 
         ** Function: Obtain user input
         ** Description: will obtain user input and check if it is valid
         ** Parameters: message Referenced User_args struct
         ** Pre-Conditions: Referenced struct should be defined!
         ** Post-Conditions: returns nothing
         *********************************************************************/
        private static void Get_user_input(ref User_args user_input)
        {
            bool error;             // purposly left uninitalized because the do while will set it
            int dummy_int = 0;      // dummy vars are because c# can't pass null ints or doubles
            float dummy_float = 0;  // --^

            // Get starting capital
            do
            {
                error = check_for_validity("Enter the starting capital [1-" + MAX_STARTING_CAPITAL + "]: ", 'f', ref user_input.starting_capital, ref dummy_int, MAX_STARTING_CAPITAL, 0);
            } while (error);                                                        // do while there are errors


            do                  // This do while is for when the user inputs a high interest rate lower than the low
            {
                // Get low interest rate
                do
                {
                    error = check_for_validity("Enter the low interest rate [0-"+ MAX_INTEREST_RATE + "]: ", 'f', ref user_input.min_interest_rate, ref dummy_int, MAX_INTEREST_RATE, 0);
                } while (error);

                // Get high interest rate
                do
                {
                    error = check_for_validity("Enter the high interest rate [0-" + MAX_INTEREST_RATE + "]: ", 'f', ref user_input.max_interest_rate, ref dummy_int, MAX_INTEREST_RATE, 0);
                } while (error);
                if (user_input.max_interest_rate < user_input.min_interest_rate)
                    System.Console.WriteLine("Your max interest rate is less than your min! Try again...");
            } while (user_input.max_interest_rate < user_input.min_interest_rate);


            // Get interest intervals
            do
            {
                error = check_for_validity("Enter the number of interest intervals [0-" + MAX_INTEREST_INTERVALS + "]: ", 'i', ref dummy_float, ref user_input.num_of_interest_intervals, 0, MAX_INTEREST_INTERVALS);
            } while (error);

            // Get periods
            do
            {
                error = check_for_validity("Enter the number of periods [0-" + MAX_COMPOUND_PERIODS + "]: ", 'i', ref dummy_float, ref user_input.num_of_periods, 0, MAX_COMPOUND_PERIODS);
            } while (error);
        }


        /********************************************************************* 
         ** Function: check for validity
         ** Description: check if user input is valid
         ** Parameters: message (string), type (char) i -> int, f->float, ref_float the reference of the float to store, ref_int the reference of the int to store, upper float bound, lower float bound
         ** Pre-Conditions: All values must be non null
         ** Post-Conditions: returns bool
         *********************************************************************/
        static bool check_for_validity(string message, char type, ref float ref_float, ref int ref_int, float float_upperBound, int int_upperBound)
        {
            System.Console.Write(message);
            string user_input_str = System.Console.ReadLine();

            if(type.Equals('i'))
            {
                if (check_for_int(user_input_str))          // call parse check to see if string can be convereted!
                {
                    int int_temp = int.Parse(user_input_str);           // create a temp var for checking until pushed to struct
                    if (int_temp > 0 && int_temp <= int_upperBound)
                    {
                        ref_int = int_temp;
                        return false;
                    }
                    else
                    {
                        System.Console.WriteLine("Your number does not intersect the required range. Try again.");
                        return true;
                    }
                }
                else
                {
                    System.Console.WriteLine("Error, you didn't enter a number");
                    return true;               // return false, we found an error
                }
            } else if (type.Equals('f'))
            {
                if (check_for_float(user_input_str))          // call parse check to see if string can be convereted!
                {
                    float float_temp = float.Parse(user_input_str);           // create a temp var for checking until pushed to struct
                    if (float_temp > 0 && float_temp <= float_upperBound)
                    {
                        ref_float = float_temp;
                        return false;
                    }
                    else
                    {
                        System.Console.WriteLine("Your number does not intersect the required range. Try again.");
                        return true;
                    }
                }
                else
                {
                    System.Console.WriteLine("Error, you didn't enter a number");
                    return true;               // return false, we found an error
                }
            }
            System.Console.WriteLine("Unknown error!");
            return true;
        }

        /********************************************************************* 
         ** Function: check_for_int
         ** Description: checks if the passed parameter can be parsed as a int
         ** Parameters: user_input (string)
         ** Pre-Conditions: user_input has a value
         ** Post-Conditions: returns a bool
         *********************************************************************/
        static bool check_for_int(string user_input)
        {
            // attempt to parse float from string
            try
            {
                int.Parse(user_input);
            } catch
            {
                // string cannot be converted, return false
                return false;
            }
            // string can convert to int, return true
            return true;
        }

        /********************************************************************* 
         ** Function: check_for_float
         ** Description: checks if the passed parameter can be parsed as a float
         ** Parameters: user_input (string)
         ** Pre-Conditions: user_input has a value
         ** Post-Conditions: returns a bool
         *********************************************************************/
        static bool check_for_float(string user_input)
        {
            // attempt to parse float from string
            try
            {
                float.Parse(user_input);
            } catch
            {
                // string cannot be converted, return false
                return false;
            }
            // string can convert to float, return true
            return true;
        }
    }
}
