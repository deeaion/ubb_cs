namespace client
{
    partial class EmployeeForm
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
            this.nPeopleMain = new System.Windows.Forms.NumericUpDown();
            this.tabView = new System.Windows.Forms.TabControl();
            this.tabFirst = new System.Windows.Forms.TabPage();
            this.dataGridMain = new System.Windows.Forms.DataGridView();
            this.ArtistColMain = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.DataColMain = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.PlaceColMain = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.AvailableSeatsMain = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.SoldSeatsMain = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.checkBoxDate = new System.Windows.Forms.CheckBox();
            this.comboArtist = new System.Windows.Forms.ComboBox();
            this.dateTimePickerMain = new System.Windows.Forms.DateTimePicker();
            this.logOutMain = new System.Windows.Forms.Button();
            this.btnAddMain = new System.Windows.Forms.Button();
            this.nameTxtMain = new System.Windows.Forms.TextBox();
            this.label12 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.placeLblMain = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.dateLblMain = new System.Windows.Forms.Label();
            this.artistLblMain = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.sellTicketSecond = new System.Windows.Forms.Button();
            this.peopleNr = new System.Windows.Forms.NumericUpDown();
            this.nameTxt = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.dataGridSecond = new System.Windows.Forms.DataGridView();
            this.ArtistColS = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.DateCol = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.PlaceCol = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.AvailableCol = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dateTimeSecond = new System.Windows.Forms.DateTimePicker();
            ((System.ComponentModel.ISupportInitialize)(this.nPeopleMain)).BeginInit();
            this.tabView.SuspendLayout();
            this.tabFirst.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridMain)).BeginInit();
            this.tabPage2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.peopleNr)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridSecond)).BeginInit();
            this.SuspendLayout();
            // 
            // nPeopleMain
            // 
            this.nPeopleMain.Location = new System.Drawing.Point(186, 790);
            this.nPeopleMain.Name = "nPeopleMain";
            this.nPeopleMain.Size = new System.Drawing.Size(204, 28);
            this.nPeopleMain.TabIndex = 0;
            // 
            // tabView
            // 
            this.tabView.AccessibleDescription = "Festivals";
            this.tabView.AccessibleName = "Festivals";
            this.tabView.Controls.Add(this.tabFirst);
            this.tabView.Controls.Add(this.tabPage2);
            this.tabView.Font = new System.Drawing.Font("Microsoft YaHei UI", 8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tabView.Location = new System.Drawing.Point(-6, -1);
            this.tabView.Name = "tabView";
            this.tabView.SelectedIndex = 0;
            this.tabView.Size = new System.Drawing.Size(1217, 895);
            this.tabView.TabIndex = 1;
            this.tabView.Tag = "Festivals";
            // 
            // tabFirst
            // 
            this.tabFirst.Controls.Add(this.dataGridMain);
            this.tabFirst.Controls.Add(this.checkBoxDate);
            this.tabFirst.Controls.Add(this.comboArtist);
            this.tabFirst.Controls.Add(this.dateTimePickerMain);
            this.tabFirst.Controls.Add(this.logOutMain);
            this.tabFirst.Controls.Add(this.btnAddMain);
            this.tabFirst.Controls.Add(this.nameTxtMain);
            this.tabFirst.Controls.Add(this.label12);
            this.tabFirst.Controls.Add(this.label11);
            this.tabFirst.Controls.Add(this.placeLblMain);
            this.tabFirst.Controls.Add(this.label9);
            this.tabFirst.Controls.Add(this.dateLblMain);
            this.tabFirst.Controls.Add(this.artistLblMain);
            this.tabFirst.Controls.Add(this.label6);
            this.tabFirst.Controls.Add(this.label5);
            this.tabFirst.Controls.Add(this.label4);
            this.tabFirst.Controls.Add(this.label3);
            this.tabFirst.Controls.Add(this.label2);
            this.tabFirst.Controls.Add(this.label1);
            this.tabFirst.Controls.Add(this.nPeopleMain);
            this.tabFirst.Location = new System.Drawing.Point(4, 30);
            this.tabFirst.Name = "tabFirst";
            this.tabFirst.Padding = new System.Windows.Forms.Padding(3);
            this.tabFirst.Size = new System.Drawing.Size(1209, 861);
            this.tabFirst.TabIndex = 0;
            this.tabFirst.Text = "Festivals";
            this.tabFirst.UseVisualStyleBackColor = true;
            // 
            // dataGridMain
            // 
            this.dataGridMain.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridMain.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] { this.ArtistColMain, this.DataColMain, this.PlaceColMain, this.AvailableSeatsMain, this.SoldSeatsMain });
            this.dataGridMain.Location = new System.Drawing.Point(65, 205);
            this.dataGridMain.Name = "dataGridMain";
            this.dataGridMain.RowTemplate.Height = 28;
            this.dataGridMain.Size = new System.Drawing.Size(1084, 476);
            this.dataGridMain.TabIndex = 20;
            this.dataGridMain.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.setInformationAboutShowMain);
            // 
            // ArtistColMain
            // 
            this.ArtistColMain.HeaderText = "Artist";
            this.ArtistColMain.Name = "ArtistColMain";
            // 
            // DataColMain
            // 
            this.DataColMain.HeaderText = "Data";
            this.DataColMain.Name = "DataColMain";
            // 
            // PlaceColMain
            // 
            this.PlaceColMain.HeaderText = "Place";
            this.PlaceColMain.Name = "PlaceColMain";
            // 
            // AvailableSeatsMain
            // 
            this.AvailableSeatsMain.HeaderText = "Available";
            this.AvailableSeatsMain.Name = "AvailableSeatsMain";
            // 
            // SoldSeatsMain
            // 
            this.SoldSeatsMain.HeaderText = "Sold";
            this.SoldSeatsMain.Name = "SoldSeatsMain";
            // 
            // checkBoxDate
            // 
            this.checkBoxDate.Location = new System.Drawing.Point(448, 80);
            this.checkBoxDate.Name = "checkBoxDate";
            this.checkBoxDate.Size = new System.Drawing.Size(149, 24);
            this.checkBoxDate.TabIndex = 19;
            this.checkBoxDate.Text = "Filter By Date?";
            this.checkBoxDate.UseVisualStyleBackColor = true;
            this.checkBoxDate.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // comboArtist
            // 
            this.comboArtist.FormattingEnabled = true;
            this.comboArtist.Location = new System.Drawing.Point(114, 125);
            this.comboArtist.Name = "comboArtist";
            this.comboArtist.Size = new System.Drawing.Size(255, 29);
            this.comboArtist.TabIndex = 18;
            this.comboArtist.SelectedIndexChanged += new System.EventHandler(this.setTableMain);
            // 
            // dateTimePickerMain
            // 
            this.dateTimePickerMain.Location = new System.Drawing.Point(114, 81);
            this.dateTimePickerMain.Name = "dateTimePickerMain";
            this.dateTimePickerMain.Size = new System.Drawing.Size(312, 28);
            this.dateTimePickerMain.TabIndex = 17;
            this.dateTimePickerMain.Value = new System.DateTime(2024, 3, 31, 22, 54, 55, 0);
            this.dateTimePickerMain.ValueChanged += new System.EventHandler(this.dateTimePickerMain_ValueChanged);
            // 
            // logOutMain
            // 
            this.logOutMain.Location = new System.Drawing.Point(1030, 790);
            this.logOutMain.Name = "logOutMain";
            this.logOutMain.Size = new System.Drawing.Size(149, 55);
            this.logOutMain.TabIndex = 16;
            this.logOutMain.Text = "LOG OUT";
            this.logOutMain.UseVisualStyleBackColor = true;
            this.logOutMain.Click += new System.EventHandler(this.logOutMain_Click);
            // 
            // btnAddMain
            // 
            this.btnAddMain.Location = new System.Drawing.Point(419, 775);
            this.btnAddMain.Name = "btnAddMain";
            this.btnAddMain.Size = new System.Drawing.Size(133, 34);
            this.btnAddMain.TabIndex = 15;
            this.btnAddMain.Text = "Add Ticket";
            this.btnAddMain.UseVisualStyleBackColor = true;
            this.btnAddMain.Click += new System.EventHandler(this.btnAddMain_Click);
            // 
            // nameTxtMain
            // 
            this.nameTxtMain.Location = new System.Drawing.Point(186, 756);
            this.nameTxtMain.Name = "nameTxtMain";
            this.nameTxtMain.Size = new System.Drawing.Size(204, 28);
            this.nameTxtMain.TabIndex = 14;
            // 
            // label12
            // 
            this.label12.Location = new System.Drawing.Point(29, 795);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(132, 23);
            this.label12.TabIndex = 13;
            this.label12.Text = "Nr. Of Tickets:";
            // 
            // label11
            // 
            this.label11.Location = new System.Drawing.Point(29, 761);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(184, 23);
            this.label11.TabIndex = 12;
            this.label11.Text = "Name of Customer:";
            this.label11.Click += new System.EventHandler(this.label11_Click);
            // 
            // placeLblMain
            // 
            this.placeLblMain.Location = new System.Drawing.Point(924, 99);
            this.placeLblMain.Name = "placeLblMain";
            this.placeLblMain.Size = new System.Drawing.Size(100, 23);
            this.placeLblMain.TabIndex = 11;
            this.placeLblMain.Text = "label10";
            this.placeLblMain.Visible = false;
            // 
            // label9
            // 
            this.label9.Location = new System.Drawing.Point(752, 58);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(100, 23);
            this.label9.TabIndex = 10;
            this.label9.Text = "Date";
            this.label9.Visible = false;
            // 
            // dateLblMain
            // 
            this.dateLblMain.Location = new System.Drawing.Point(924, 60);
            this.dateLblMain.Name = "dateLblMain";
            this.dateLblMain.Size = new System.Drawing.Size(100, 23);
            this.dateLblMain.TabIndex = 9;
            this.dateLblMain.Text = "label8";
            this.dateLblMain.Visible = false;
            // 
            // artistLblMain
            // 
            this.artistLblMain.Location = new System.Drawing.Point(924, 24);
            this.artistLblMain.Name = "artistLblMain";
            this.artistLblMain.Size = new System.Drawing.Size(165, 36);
            this.artistLblMain.TabIndex = 8;
            this.artistLblMain.Text = "label7";
            this.artistLblMain.Visible = false;
            // 
            // label6
            // 
            this.label6.Location = new System.Drawing.Point(752, 24);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(100, 23);
            this.label6.TabIndex = 7;
            this.label6.Text = "Artist";
            this.label6.Visible = false;
            // 
            // label5
            // 
            this.label5.Location = new System.Drawing.Point(29, 734);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(171, 27);
            this.label5.TabIndex = 6;
            this.label5.Text = "SELL TICKET?";
            // 
            // label4
            // 
            this.label4.Location = new System.Drawing.Point(752, 99);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(100, 23);
            this.label4.TabIndex = 5;
            this.label4.Text = "Place";
            this.label4.Visible = false;
            // 
            // label3
            // 
            this.label3.Location = new System.Drawing.Point(26, 131);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(100, 23);
            this.label3.TabIndex = 4;
            this.label3.Text = "ARTIST";
            // 
            // label2
            // 
            this.label2.Location = new System.Drawing.Point(26, 81);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(100, 23);
            this.label2.TabIndex = 3;
            this.label2.Text = "DATE";
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(26, 24);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(229, 57);
            this.label1.TabIndex = 2;
            this.label1.Text = "SHOWS";
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.sellTicketSecond);
            this.tabPage2.Controls.Add(this.peopleNr);
            this.tabPage2.Controls.Add(this.nameTxt);
            this.tabPage2.Controls.Add(this.label10);
            this.tabPage2.Controls.Add(this.label8);
            this.tabPage2.Controls.Add(this.label7);
            this.tabPage2.Controls.Add(this.dataGridSecond);
            this.tabPage2.Controls.Add(this.dateTimeSecond);
            this.tabPage2.Location = new System.Drawing.Point(4, 30);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(1209, 861);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "FestivalsDate";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // sellTicketSecond
            // 
            this.sellTicketSecond.Location = new System.Drawing.Point(1005, 453);
            this.sellTicketSecond.Name = "sellTicketSecond";
            this.sellTicketSecond.Size = new System.Drawing.Size(149, 47);
            this.sellTicketSecond.TabIndex = 7;
            this.sellTicketSecond.Text = "Sell Ticket";
            this.sellTicketSecond.UseVisualStyleBackColor = true;
            this.sellTicketSecond.Click += new System.EventHandler(this.sellTicketSecond_Click);
            // 
            // peopleNr
            // 
            this.peopleNr.Location = new System.Drawing.Point(963, 382);
            this.peopleNr.Name = "peopleNr";
            this.peopleNr.Size = new System.Drawing.Size(176, 28);
            this.peopleNr.TabIndex = 6;
            // 
            // nameTxt
            // 
            this.nameTxt.Location = new System.Drawing.Point(963, 339);
            this.nameTxt.Name = "nameTxt";
            this.nameTxt.Size = new System.Drawing.Size(176, 28);
            this.nameTxt.TabIndex = 5;
            // 
            // label10
            // 
            this.label10.Location = new System.Drawing.Point(786, 384);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(126, 28);
            this.label10.TabIndex = 4;
            this.label10.Text = "Nr. Of people";
            // 
            // label8
            // 
            this.label8.Location = new System.Drawing.Point(786, 342);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(154, 33);
            this.label8.TabIndex = 3;
            this.label8.Text = "NameOfClient";
            // 
            // label7
            // 
            this.label7.Location = new System.Drawing.Point(772, 297);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(168, 45);
            this.label7.TabIndex = 2;
            this.label7.Text = "Sell Ticket";
            // 
            // dataGridSecond
            // 
            this.dataGridSecond.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridSecond.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] { this.ArtistColS, this.DateCol, this.PlaceCol, this.AvailableCol });
            this.dataGridSecond.Location = new System.Drawing.Point(49, 104);
            this.dataGridSecond.Name = "dataGridSecond";
            this.dataGridSecond.RowTemplate.Height = 28;
            this.dataGridSecond.Size = new System.Drawing.Size(671, 740);
            this.dataGridSecond.TabIndex = 1;
            // 
            // ArtistColS
            // 
            this.ArtistColS.HeaderText = "Artist";
            this.ArtistColS.Name = "ArtistColS";
            // 
            // DateCol
            // 
            this.DateCol.HeaderText = "Date";
            this.DateCol.Name = "DateCol";
            // 
            // PlaceCol
            // 
            this.PlaceCol.HeaderText = "PlaceCol";
            this.PlaceCol.Name = "PlaceCol";
            // 
            // AvailableCol
            // 
            this.AvailableCol.HeaderText = "Nr. of available Col";
            this.AvailableCol.Name = "AvailableCol";
            // 
            // dateTimeSecond
            // 
            this.dateTimeSecond.Location = new System.Drawing.Point(23, 24);
            this.dateTimeSecond.Name = "dateTimeSecond";
            this.dateTimeSecond.Size = new System.Drawing.Size(289, 28);
            this.dateTimeSecond.TabIndex = 0;
            this.dateTimeSecond.ValueChanged += new System.EventHandler(this.dateTimeSecond_ValueChanged);
            // 
            // EmployeeForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1204, 885);
            this.Controls.Add(this.tabView);
            this.Name = "EmployeeForm";
            this.Text = "EmployeeForm";
            this.Load += new System.EventHandler(this.EmployeeForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.nPeopleMain)).EndInit();
            this.tabView.ResumeLayout(false);
            this.tabFirst.ResumeLayout(false);
            this.tabFirst.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridMain)).EndInit();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.peopleNr)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridSecond)).EndInit();
            this.ResumeLayout(false);
        }

    private System.Windows.Forms.Button sellTicketSecond;

    private System.Windows.Forms.DataGridViewTextBoxColumn ArtistColMain;
    private System.Windows.Forms.DataGridViewTextBoxColumn DataColMain;
    private System.Windows.Forms.DataGridViewTextBoxColumn PlaceColMain;
    private System.Windows.Forms.DataGridViewTextBoxColumn AvailableSeatsMain;
    private System.Windows.Forms.DataGridViewTextBoxColumn SoldSeatsMain;

    private System.Windows.Forms.DataGridView dataGridMain;

    private System.Windows.Forms.CheckBox checkBoxDate;

    private System.Windows.Forms.TextBox nameTxt;
    private System.Windows.Forms.NumericUpDown peopleNr;

    private System.Windows.Forms.Label label7;
    private System.Windows.Forms.Label label8;
    private System.Windows.Forms.Label label10;

    private System.Windows.Forms.DataGridViewTextBoxColumn ArtistColS;
    private System.Windows.Forms.DataGridViewTextBoxColumn DateCol;
    private System.Windows.Forms.DataGridViewTextBoxColumn PlaceCol;
    private System.Windows.Forms.DataGridViewTextBoxColumn AvailableCol;

    private System.Windows.Forms.DataGridView dataGridSecond;

    private System.Windows.Forms.DateTimePicker dateTimeSecond;

    private System.Windows.Forms.TextBox nameTxtMain;
    private System.Windows.Forms.Button btnAddMain;
    private System.Windows.Forms.Button logOutMain;
    private System.Windows.Forms.DateTimePicker dateTimePickerMain;
    private System.Windows.Forms.ComboBox comboArtist;

    private System.Windows.Forms.Label placeLblMain;
    private System.Windows.Forms.Label label11;
    private System.Windows.Forms.Label label12;

    private System.Windows.Forms.Label label1;
    private System.Windows.Forms.Label label2;
    private System.Windows.Forms.Label label3;
    private System.Windows.Forms.Label label4;
    private System.Windows.Forms.Label label5;
    private System.Windows.Forms.Label label6;
    private System.Windows.Forms.Label artistLblMain;
    private System.Windows.Forms.Label dateLblMain;
    private System.Windows.Forms.Label label9;

    private System.Windows.Forms.DataGridViewTextBoxColumn ArtistCol;
   


    protected System.Windows.Forms.TabControl tabView;
    private System.Windows.Forms.TabPage tabFirst;
    private System.Windows.Forms.TabPage tabPage2;

    private System.Windows.Forms.NumericUpDown nPeopleMain;

    #endregion
    }

}