using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

/*
 *  Hitter class located within Program.cs
 */

namespace Assignment_2
{
    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();
        }

        private void exit_bttn_Click(object sender, EventArgs e)
        {
            Dispose();
        }

        private void log_select_bttn_Click(object sender, EventArgs e)
        {
            OpenFileDialog logFileDialog = new OpenFileDialog();
            logFileDialog.Title = "Open Log File";
            logFileDialog.Filter = "TXT files|*.txt";
           //  logFileDialog.InitialDirectory = @"Z:\";
            if (logFileDialog.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    log_path_textbox.Text = logFileDialog.FileName;
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: Could not select file from disk. Error: " + ex.Message);
                }
            }
        }

        private void process_bttn_Click(object sender, EventArgs e)
        {
            log_output_textbox.Items.Clear();
            try
            {

                int counter = 0;            // this counter will record how many unique IP's are recording within the program
                string[] logFile_arr = System.IO.File.ReadAllLines(log_path_textbox.Text);
                hitter[] hitters = new hitter[logFile_arr.Length];          // Create an array of hitters that is the for the length of the log file. This is inefficent since it wastes a lot of space

                for (int i=0; i<logFile_arr.Length; i++)                    // go through each line and split up the string based on spaces
                {
                    string[] entries = logFile_arr[i].Split(' ');
                    if(entries.Length < 1) {
                        MessageBox.Show("Error: Your file is invalid!");
                        return;
                    }
                    // string ip = entries[1];                 

                    for (int x=0; x<hitters.Length; x++)
                    {
                        if(hitters[x] == null && entries[1] != "" && entries[1] != " ")         // create an object if the element is null and prased string is not null or only a space
                        {
                            hitters[x] = new hitter();
                            hitters[x].ip = entries[1];
                            hitters[x].hit_count = 1;
                            counter++;  // add one to counter to figure out how many elements we really need
                            break;
                        } else
                        {
                            if(hitters[x].ip == entries[1])         // The current element is not null, so check if the object has the same IP
                            {
                                hitters[x].hit_count++;
                                break;          // once incremented, add to it. 
                            }
                        }

                    }


                }       // end the main for loop


                // Now we have an array that is really long and inefficent. So lets copy the array and make it more 'efficent'

                hitter[] new_hitters = new hitter[counter];
                int new_counter = 0;
                for(int i=0; i<hitters.Length; i++)         // once again, go through all the hitters
                {
                    if (hitters[i] != null)                 // check if the hitter element is not null (this is pretty much an error check, but our code is so inefficent I don't want to chance it)
                    {
                        new_hitters[new_counter] = hitters[i];
                        new_counter++;
                    }
                }


                // We now have a valid array of IP's and counts that is ready to be sorted. The call Array.Sort is considered a black box in this case

                Array.Sort(new_hitters, delegate (hitter x, hitter y) { return y.hit_count.CompareTo(x.hit_count); });          // perform a sort now that our array has no uninitalized elements

                hitter excluded_ip = new hitter();          // the excluded IP is the IP address that we do not want to count
                int arr_length = 0;

                if(new_hitters.Length < 100)
                {
                    arr_length = new_hitters.Length;
                } else
                {                                           // this is to account for log files that have less than 100 lines
                    arr_length = 100;
                }


                for (int x = 0; x < arr_length; x++)               // get the top 100
                {
                    if (new_hitters[x] == null)             // nulls don't count. We don't like them
                    {
                        break;
                    }
                    else
                    {
                        if (new_hitters[x].ip == "140.211.167.204")         // we need to exclude this IP address
                        {
                            excluded_ip = new_hitters[x];
                            if(new_hitters.Length > 100)
                            {
                                arr_length++;
                            }
                          //  x--;            // we need to go back, because things broke
                        } else
                        {
                            log_output_textbox.Items.Add(new_hitters[x].ip + ": " + new_hitters[x].hit_count + "\r\n");
                        }
                       
                    }
                }


                log_output_textbox.Items.Add("==================================\r\n");                 // This is the statistics output after the 100 lines
                log_output_textbox.Items.Add(excluded_ip.ip+" count: "+excluded_ip.hit_count+"\r\n");
                if(new_hitters[0].ip == excluded_ip.ip)             // if the excluded IP is the same one as the highest hit counter, we cannot display it
                {
                    if(arr_length > 1)                              // also to prevent a fatal error, we need to make sure the array is greater than 1
                    {
                        log_output_textbox.Items.Add("Max count: " + new_hitters[1].ip + " - " + new_hitters[1].hit_count + "\r\n");
                    }
                } else
                {                                                   // the excluded IP is not the highest element, so we can just print out element 0
                    log_output_textbox.Items.Add("Max count: " + new_hitters[0].ip + " - " + new_hitters[0].hit_count + "\r\n");
                }

                log_output_textbox.Items.Add("Min count: " + new_hitters[arr_length - 1].ip + " - " + new_hitters[arr_length-1].hit_count+ "\r\n");

                int mean_size = 0;
                long mean_sum = 0;
                for(int i=0; i< arr_length; i++)                    // We want to loop through each of the 100 records and get the sum
                {
                    if(new_hitters[i].ip != excluded_ip.ip)
                    {
                        mean_sum += new_hitters[i].hit_count;
                        mean_size++;
                    }
                }

                log_output_textbox.Items.Add("Mean count: "+Math.Round((double)mean_sum/mean_size, 2)+" \r\n");

                // yes, this is all occuring within the try catch. I could put it afterwards and the only difference would be that on an error, it would present no messagebox. Currently the error may or may not be correct
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: Could not read file from disk. Error: " + ex.Message);
            }
        }

        private void log_output_textbox_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
