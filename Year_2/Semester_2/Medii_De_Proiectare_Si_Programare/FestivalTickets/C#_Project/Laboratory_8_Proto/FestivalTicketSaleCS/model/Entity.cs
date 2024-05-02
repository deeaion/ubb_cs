using System;

namespace model
{[Serializable]
    public class Entity<TId>
    {
        public Entity() {}

        public Entity(TId id)
        {
            this.Id = id;
        }

        public TId Id
        {
            get;
            set;
        }
    }
}

