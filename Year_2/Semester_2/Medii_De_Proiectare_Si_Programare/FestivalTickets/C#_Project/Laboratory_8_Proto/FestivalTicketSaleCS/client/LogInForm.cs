using System;
using System.Windows.Forms;

namespace client
{
    public partial class LogInForm : Form
    {
        private FestivalClientCtrl _service;
        public LogInForm(FestivalClientCtrl service)
        {
            InitializeComponent();
            this._service = service;
            
        }
        public void setService(FestivalClientCtrl service)
        {
            this._service = service;
        }
        public LogInForm()
        {
            InitializeComponent();
        }

        public void killApp(EmployeeForm form)
        {
            BeginInvoke((MethodInvoker)delegate
            {
                    Application.Exit();
            });
            
        }

        private void logIn_Click(object sender, EventArgs e)
        {
            string username=emailTxt.Text;
            string password=passwordTxt.Text;
            try
            {
                if (_service.logIn(username, password))
                {
               
                    EmployeeForm mainForm = new EmployeeForm(_service);
                    mainForm.Text="Employee Form"+username;
                    mainForm.Show();
                    this.Hide();
                }
                else
                {
                    MessageBox.Show("Invalid username or password");
                    return;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message);
            }
            
        }
        

        private void LogInForm_Load(object sender, EventArgs e)
        {
            
        }
    }
}