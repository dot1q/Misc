using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace assignment3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        /*
         * open_sql_file_bttn_Click handler for button click
         * Auto generated method
         */
        private void open_sql_file_bttn_Click(object sender, EventArgs e)
        {
            OpenFileDialog sql_file_dialogBox = new OpenFileDialog();
            sql_file_dialogBox.Title = "Open SQL File";
            sql_file_dialogBox.Filter = "SQL and TXT Files|*.txt;*.sql";
            if (sql_file_dialogBox.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    sql_textbox.Text = sql_file_dialogBox.FileName;
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: Could not select SQL file from disk. Error: " + ex.Message);
                }
            }
        }

        /*
         * open_access_file_bttn_Click handler for button click
         * Auto generated method
         */
        private void open_access_file_bttn_Click(object sender, EventArgs e)
        {
            OpenFileDialog access_file_dialogBox = new OpenFileDialog();
            access_file_dialogBox.Title = "Open SQL File";
            access_file_dialogBox.Filter = "Access files|*.accdb";
            if (access_file_dialogBox.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    access_textbox.Text = access_file_dialogBox.FileName;
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: Could not select Access file from disk. Error: " + ex.Message);
                }
            }
        }

        /*
         * exit_bttn_Click handler for button click
         * Auto generated method
         */
        private void exit_bttn_Click(object sender, EventArgs e)
        {
            Dispose();          // exit the program gracefully 
        }

        /*
         * run_query_bttn_Click handler for button click
         * Auto generated method
         */
        private void run_query_bttn_Click(object sender, EventArgs e)
        {
            result_listbox.Clear();
            if (string.IsNullOrWhiteSpace(sql_textbox.Text))            // check for empty sql textbox
            {
                MessageBox.Show("Your sql file is empty!");
                return;
            }

            if (string.IsNullOrWhiteSpace(access_textbox.Text))         // check for empty database textbox
            {
                MessageBox.Show("Your database is empty!");
                return;
            }

            System.IO.FileStream InFile;
            System.IO.StreamReader Reader;

            InFile = new System.IO.FileStream(sql_textbox.Text, System.IO.FileMode.Open, System.IO.FileAccess.Read);
            Reader = new System.IO.StreamReader(InFile);
            string Buffer = Reader.ReadToEnd();
            string[] sql_commands = Buffer.Split(new char[] { ';' });

            // Attempt to open the database
            string ConnectString = "provider=Microsoft.ACE.OLEDB.12.0;" + "Data Source="+access_textbox.Text;
            System.Data.OleDb.OleDbConnection Connection = new System.Data.OleDb.OleDbConnection(ConnectString);

            System.Data.OleDb.OleDbCommand SQLCommand = null;
            System.Data.OleDb.OleDbDataReader SQLDataReader = null;             // copy pasta from lab
            string Result_string;

            try /* opening the db connection */
            {
                result_listbox.AppendText(ConnectString + "\r\n");
                Connection.Open();
                result_listbox.AppendText("Connection open...\r\n");
            }
            catch (System.Exception f)
            {
                result_listbox.AppendText("Problems opening..." + f.Message + "\r\n");
                return;         //This is a fatal error, return
            }


            for (int i = 0; i < sql_commands.Length; i++)                   // Go through each string buffer line and add to the db
            {
                if (!string.IsNullOrWhiteSpace(sql_commands[i]))
                {
                    SQLCommand = new System.Data.OleDb.OleDbCommand(sql_commands[i], Connection);
                    //execute the statement
                    result_listbox.AppendText("Attempting to add: " + sql_commands[i] + "\r\n");

                    try
                    {
                        SQLDataReader = SQLCommand.ExecuteReader();
                        result_listbox.AppendText("Execution successful\r\n\r\n");
                    }
                    catch (System.Exception f)
                    {
                        result_listbox.AppendText("Problems executing..." + f.Message + "\r\n");
                    }

                    /* at this point we know that execution succeeded so we can start reading the
                       results. Since we do not know how many records we get returned, we'll stick
                       the read in a while() loop that keeps executing until we no longer get
                       results from the reader. */

                    try
                    {
                        while (SQLDataReader.Read())
                        {
                            Result_string = SQLDataReader.GetString(0);
                            result_listbox.AppendText(Result_string + "\r\n");
                        }
                        SQLDataReader.Close();
                    }
                    catch (System.Exception f)
                    {
                        result_listbox.AppendText("Problems reading data..." + f.Message + "\r\n");
                        break;
                    }
                }
            }


            try /* closing the connection */
            {
                Connection.Close();
                result_listbox.AppendText("Connection closed... \r\n");
            }
            catch (System.Exception f)
            {
                result_listbox.AppendText("Problems closing..." + f.Message+"\r\n");
            }
        }

    }
}
