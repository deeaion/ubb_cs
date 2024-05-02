using System;

namespace networking.dto
{[Serializable]
    public class AngajatDTO
    {
        public string Token { get; set; }
        public string Pass { get; set; }
        public AngajatDTO(string token, string pass)
        {
            Token = token;
            Pass = pass;
        }

        public override string ToString()
        {
            return base.ToString();
        }

        public override bool Equals(object obj)
        {
            return base.Equals(obj);
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }
    }
}