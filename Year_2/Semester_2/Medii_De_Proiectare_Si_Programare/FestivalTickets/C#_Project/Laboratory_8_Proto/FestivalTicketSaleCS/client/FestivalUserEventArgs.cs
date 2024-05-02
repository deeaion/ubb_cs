using System;

namespace client
{
    public enum FestivalUserEvent
    {
        LoggedIn, LoggedOut, BiletAdded,SpectacoleReceived
    }
    public class FestivalUserEventArgs : EventArgs
    {
        private readonly FestivalUserEvent userEvent;
        private readonly Object data;
        
        public FestivalUserEventArgs (FestivalUserEvent userEvent, object data)
        {
            this.userEvent = userEvent;
            this.data = data;
        }
        public FestivalUserEvent UserEventType
        {
            get { return userEvent; }
        }

        public object Data
        {
            get { return data; }
        }

    }
}