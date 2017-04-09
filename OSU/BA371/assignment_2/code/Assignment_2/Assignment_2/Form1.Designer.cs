namespace Assignment_2
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
            this.log_select_bttn = new System.Windows.Forms.Button();
            this.process_bttn = new System.Windows.Forms.Button();
            this.log_path_textbox = new System.Windows.Forms.TextBox();
            this.quit_bttn = new System.Windows.Forms.Button();
            this.log_output_textbox = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // log_select_bttn
            // 
            this.log_select_bttn.Location = new System.Drawing.Point(12, 12);
            this.log_select_bttn.Name = "log_select_bttn";
            this.log_select_bttn.Size = new System.Drawing.Size(75, 23);
            this.log_select_bttn.TabIndex = 0;
            this.log_select_bttn.Text = "Select log file";
            this.log_select_bttn.UseVisualStyleBackColor = true;
            this.log_select_bttn.Click += new System.EventHandler(this.log_select_bttn_Click);
            // 
            // process_bttn
            // 
            this.process_bttn.Location = new System.Drawing.Point(375, 38);
            this.process_bttn.Name = "process_bttn";
            this.process_bttn.Size = new System.Drawing.Size(75, 23);
            this.process_bttn.TabIndex = 2;
            this.process_bttn.Text = "Go!";
            this.process_bttn.UseVisualStyleBackColor = true;
            this.process_bttn.Click += new System.EventHandler(this.process_bttn_Click);
            // 
            // log_path_textbox
            // 
            this.log_path_textbox.Location = new System.Drawing.Point(93, 12);
            this.log_path_textbox.Name = "log_path_textbox";
            this.log_path_textbox.Size = new System.Drawing.Size(357, 20);
            this.log_path_textbox.TabIndex = 3;
            // 
            // quit_bttn
            // 
            this.quit_bttn.Location = new System.Drawing.Point(375, 521);
            this.quit_bttn.Name = "quit_bttn";
            this.quit_bttn.Size = new System.Drawing.Size(75, 23);
            this.quit_bttn.TabIndex = 4;
            this.quit_bttn.Text = "Exit";
            this.quit_bttn.UseVisualStyleBackColor = true;
            this.quit_bttn.Click += new System.EventHandler(this.exit_bttn_Click);
            // 
            // log_output_textbox
            // 
            this.log_output_textbox.FormattingEnabled = true;
            this.log_output_textbox.Location = new System.Drawing.Point(12, 41);
            this.log_output_textbox.Name = "log_output_textbox";
            this.log_output_textbox.Size = new System.Drawing.Size(357, 498);
            this.log_output_textbox.TabIndex = 5;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(462, 556);
            this.Controls.Add(this.log_output_textbox);
            this.Controls.Add(this.quit_bttn);
            this.Controls.Add(this.log_path_textbox);
            this.Controls.Add(this.process_bttn);
            this.Controls.Add(this.log_select_bttn);
            this.Name = "Form1";
            this.Text = "Who\'s Hitting Us?";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button log_select_bttn;
        private System.Windows.Forms.Button process_bttn;
        private System.Windows.Forms.TextBox log_path_textbox;
        private System.Windows.Forms.Button quit_bttn;
        private System.Windows.Forms.ListBox log_output_textbox;
    }
}

