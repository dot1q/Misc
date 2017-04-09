namespace assignment3
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.sql_textbox = new System.Windows.Forms.TextBox();
            this.access_textbox = new System.Windows.Forms.TextBox();
            this.open_sql_file_bttn = new System.Windows.Forms.Button();
            this.open_access_file_bttn = new System.Windows.Forms.Button();
            this.run_query_bttn = new System.Windows.Forms.Button();
            this.exit_bttn = new System.Windows.Forms.Button();
            this.result_listbox = new System.Windows.Forms.RichTextBox();
            this.SuspendLayout();
            // 
            // sql_textbox
            // 
            this.sql_textbox.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.sql_textbox.Location = new System.Drawing.Point(154, 14);
            this.sql_textbox.Name = "sql_textbox";
            this.sql_textbox.Size = new System.Drawing.Size(344, 20);
            this.sql_textbox.TabIndex = 0;
            // 
            // access_textbox
            // 
            this.access_textbox.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.access_textbox.Location = new System.Drawing.Point(154, 43);
            this.access_textbox.Name = "access_textbox";
            this.access_textbox.Size = new System.Drawing.Size(344, 20);
            this.access_textbox.TabIndex = 1;
            // 
            // open_sql_file_bttn
            // 
            this.open_sql_file_bttn.Location = new System.Drawing.Point(12, 12);
            this.open_sql_file_bttn.Name = "open_sql_file_bttn";
            this.open_sql_file_bttn.Size = new System.Drawing.Size(136, 23);
            this.open_sql_file_bttn.TabIndex = 2;
            this.open_sql_file_bttn.Text = "SQL script file...";
            this.open_sql_file_bttn.UseVisualStyleBackColor = true;
            this.open_sql_file_bttn.Click += new System.EventHandler(this.open_sql_file_bttn_Click);
            // 
            // open_access_file_bttn
            // 
            this.open_access_file_bttn.Location = new System.Drawing.Point(12, 41);
            this.open_access_file_bttn.Name = "open_access_file_bttn";
            this.open_access_file_bttn.Size = new System.Drawing.Size(136, 23);
            this.open_access_file_bttn.TabIndex = 3;
            this.open_access_file_bttn.Text = "Access database file...";
            this.open_access_file_bttn.UseVisualStyleBackColor = true;
            this.open_access_file_bttn.Click += new System.EventHandler(this.open_access_file_bttn_Click);
            // 
            // run_query_bttn
            // 
            this.run_query_bttn.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.run_query_bttn.Location = new System.Drawing.Point(342, 664);
            this.run_query_bttn.Name = "run_query_bttn";
            this.run_query_bttn.Size = new System.Drawing.Size(75, 23);
            this.run_query_bttn.TabIndex = 4;
            this.run_query_bttn.Text = "Run";
            this.run_query_bttn.UseVisualStyleBackColor = true;
            this.run_query_bttn.Click += new System.EventHandler(this.run_query_bttn_Click);
            // 
            // exit_bttn
            // 
            this.exit_bttn.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.exit_bttn.Location = new System.Drawing.Point(423, 664);
            this.exit_bttn.Name = "exit_bttn";
            this.exit_bttn.Size = new System.Drawing.Size(75, 23);
            this.exit_bttn.TabIndex = 5;
            this.exit_bttn.Text = "Close";
            this.exit_bttn.UseVisualStyleBackColor = true;
            this.exit_bttn.Click += new System.EventHandler(this.exit_bttn_Click);
            // 
            // result_listbox
            // 
            this.result_listbox.Location = new System.Drawing.Point(12, 70);
            this.result_listbox.Name = "result_listbox";
            this.result_listbox.Size = new System.Drawing.Size(486, 588);
            this.result_listbox.TabIndex = 7;
            this.result_listbox.Text = "";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(510, 699);
            this.Controls.Add(this.result_listbox);
            this.Controls.Add(this.exit_bttn);
            this.Controls.Add(this.run_query_bttn);
            this.Controls.Add(this.open_access_file_bttn);
            this.Controls.Add(this.open_sql_file_bttn);
            this.Controls.Add(this.access_textbox);
            this.Controls.Add(this.sql_textbox);
            this.Name = "Form1";
            this.Text = "SQL Interpreter for Access";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox sql_textbox;
        private System.Windows.Forms.TextBox access_textbox;
        private System.Windows.Forms.Button open_sql_file_bttn;
        private System.Windows.Forms.Button open_access_file_bttn;
        private System.Windows.Forms.Button run_query_bttn;
        private System.Windows.Forms.Button exit_bttn;
        private System.Windows.Forms.RichTextBox result_listbox;
    }
}

