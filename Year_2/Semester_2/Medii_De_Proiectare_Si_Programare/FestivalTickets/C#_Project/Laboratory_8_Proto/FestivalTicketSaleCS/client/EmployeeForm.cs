using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.Linq;
using System.Runtime.Remoting.Channels;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using model;

namespace client
{
    public partial class EmployeeForm : Form
    {
        private readonly FestivalClientCtrl service;
        private readonly IList<model.SpectacolDTO> _spectacolDtosMain;
        private readonly IList<model.SpectacolDTO> _spectacolDtosSecond;
        private readonly IList<String> _artists;
    public EmployeeForm(FestivalClientCtrl service)
    {
       
        InitializeComponent();
      
        this.service=service;
        _artists = service.getArtists();
        _spectacolDtosMain = service.getSpectacole(DateTime.Now,"None",false);
        _spectacolDtosSecond= service.getSpectacole(DateTime.Now,"None",true);
        service.updateEvent += updateTables;
        this.Closing+=(sender,args)=>service.logOut();
        initItems();
        
      
    }
    private void updateTables(object sender, EventArgs e)
    {
        if (this.InvokeRequired)
        {
           BeginInvoke(new MethodInvoker(() => updateTables(sender, e)));
        }
        else
        {
            setTableMain(sender, e);
            setTableSecond(sender, e);
        }
    }

    private void initItems()
    {
        setArtistCombo();
        setTableMain(null,null);
        setTableSecond(null,null);
       
    }

    private void setArtistCombo()
    {
        
        comboArtist.Items.Clear();
        comboArtist.Items.AddRange(_artists.ToArray());
        comboArtist.SelectedValue = comboArtist.Items[_artists.Count - 1];
        comboArtist.Text = "None";
    }

    private void setTableSecond(object sender, EventArgs e)
    {
        IList<model.SpectacolDTO> spectacole = service.getSpectacole(dateTimeSecond.Value, "None",true);
        dataGridSecond.Rows.Clear();
        foreach (var spectacol in spectacole)
        {
            int rowIndex = dataGridSecond.Rows.Add();  // Add a new row and get its index
            DataGridViewRow row = dataGridSecond.Rows[rowIndex];  // Get the new row
            row.Cells["ArtistColS"].Value = spectacol.Artist;
            row.Cells["DateCol"].Value = spectacol.Data;
            row.Cells["PlaceCol"].Value = spectacol.Locatie;
            row.Cells["AvailableCol"].Value = spectacol.NumarLocuriDisponibile;
            row.Tag = spectacol;
            if (spectacol.NumarLocuriDisponibile == "0")
            {
                row.DefaultCellStyle.BackColor = Color.Red;
            }
        }
    }
    private void setTableMain(object sender, EventArgs e)
    {
        string artist = comboArtist.Text;
        IList<model.SpectacolDTO> spectacole =service.getSpectacole(dateTimePickerMain.Value, artist, checkBoxDate.Checked);
        dataGridMain.Rows.Clear();
        foreach (var spectacol in spectacole)
        {
            int rowIndex = dataGridMain.Rows.Add();  // Add a new row and get its index
            DataGridViewRow row = dataGridMain.Rows[rowIndex];  // Get the new row
            row.Cells["ArtistColMain"].Value = spectacol.Artist;
            row.Cells["DataColMain"].Value = spectacol.Data;
            row.Cells["PlaceColMain"].Value = spectacol.Locatie;
            row.Cells["AvailableSeatsMain"].Value = spectacol.NumarLocuriDisponibile;
            row.Cells["SoldSeatsMain"].Value = spectacol.NumarLocuriVandute;
            row.Tag = spectacol;
            if (spectacol.NumarLocuriDisponibile == "0")
            {
                row.DefaultCellStyle.BackColor = Color.Red;
            }
        }
    }
    






    private void label11_Click(object sender, EventArgs e)
    {
        
    }

  

    

    private void EmployeeForm_Load(object sender, EventArgs e)
    {
        setTableMain(null,null);
    }

    private void checkBox1_CheckedChanged(object sender, EventArgs e)
    {
        setTableMain(null,null);
    }

    private void setInformationAboutShowMain(object sender, DataGridViewCellEventArgs e)
    {
        DataGridViewRow row=dataGridMain.Rows[dataGridMain.SelectedCells[0].RowIndex];
        if(row!=null)
        {
            artistLblMain.Visible=true;
            dateLblMain.Visible=true;
            placeLblMain.Visible=true;
            label6.Visible=true;
            label9.Visible=true;
            label4.Visible=true;
            string artist = row.Cells["ArtistColMain"].Value.ToString();
            string locatie = row.Cells["PlaceColMain"].Value.ToString();
            string data = row.Cells["DataColMain"].Value.ToString();
            artistLblMain.Text=artist;
            dateLblMain.Text=data;
            placeLblMain.Text=locatie;
        }
    }

    private void btnAddMain_Click(object sender, EventArgs e)
    {
        string nume = nameTxtMain.Text.ToString();
        int nr = Convert.ToInt32(nPeopleMain.Value.ToString());
        DataGridViewRow row = dataGridMain.Rows[dataGridMain.SelectedCells[0].RowIndex];
        model.SpectacolDTO spectacol = (model.SpectacolDTO)row.Tag;
        try
        {
            service.sellTicket(nume, Int64.Parse(spectacol.Id_spectacol), nr);
        }
        catch (Exception exception)
        {
           MessageBox.Show(exception.Message);
        }
    }

    private void sellTicketSecond_Click(object sender, EventArgs e)
    {
        string nume = nameTxt.Text.ToString();
        int nr = Convert.ToInt32(peopleNr.Value.ToString());
        DataGridViewRow row = dataGridSecond.Rows[dataGridSecond.SelectedCells[0].RowIndex];
        model.SpectacolDTO spectacol = (model.SpectacolDTO)row.Tag;

        try
        {
            service.sellTicket(nume, Int64.Parse(spectacol.Id_spectacol), nr);
        }
        catch (Exception exception)
        {
            MessageBox.Show(exception.Message);
        }
    }

    private void dateTimePickerMain_ValueChanged(object sender, EventArgs e)
    {
        tabView.SelectedTab = tabPage2;
        dateTimeSecond.Value=dateTimePickerMain.Value;
        initItems();
    }

    private void dateTimeSecond_ValueChanged(object sender, EventArgs e)
    {
        setTableSecond(sender,e);
    }

    private void logOutMain_Click(object sender, EventArgs e)
    {
        try
        {
            service.logOut();

        }
        catch (Exception exception)
        {
            MessageBox.Show(exception.Message);
        }
        service.updateEvent-= updateTables;
        Application.Exit();
    }

   
    }
}