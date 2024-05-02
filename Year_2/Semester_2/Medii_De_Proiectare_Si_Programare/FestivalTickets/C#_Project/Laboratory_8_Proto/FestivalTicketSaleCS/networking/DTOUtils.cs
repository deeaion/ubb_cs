using model;
using networking.dto;

namespace networking
{
    public class DTOUtils
    {
        public static model.Angajat getFromDTO(AngajatDTO dto) {
            return new model.Angajat("","",dto.Token,dto.Token,dto.Pass);
        }
        public static AngajatDTO getDTO(model.Angajat angajat) {
            return new AngajatDTO( angajat.Username, angajat.Password);
        }
    }
}