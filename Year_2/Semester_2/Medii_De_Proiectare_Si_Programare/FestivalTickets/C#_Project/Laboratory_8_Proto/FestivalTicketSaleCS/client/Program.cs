using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using networking;
using services.Exceptions;

namespace client
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            IFestivalServices server = new FestivalServerProxy("127.0.0.1",55556);
            FestivalClientCtrl ctrl = new FestivalClientCtrl(server);
            LogInForm win = new LogInForm();
            win.setService(ctrl);

            Application.Run(win);
        }
    }
}