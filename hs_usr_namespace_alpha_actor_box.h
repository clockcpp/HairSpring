namespace hs
{
    
    class Box
    {
    public:
        COORD x0y0 = { -1,-1 };
        COORD x0y1 = { -1,-1 };
        COORD x1y0 = { -1,-1 };
        COORD x1y1 = { -1,-1 };
        void to_box(COORD a, COORD b)
        {
            if (a.X == b.X || a.Y == b.Y)
            {
                return;
            }
            this->x0y0 = { min(a.X,b.X),min(a.Y,b.Y) };
            this->x0y1 = { min(a.X,b.X),max(a.Y,b.Y) };
            this->x1y0 = { max(a.X,b.X),min(a.Y,b.Y) };
            this->x1y1 = { max(a.X,b.X),max(a.Y,b.Y) };
        }
        bool insideBox(COORD targ)
        {
            if (this->x0y0.X <= targ.X && this->x1y1.X >= targ.X &&
                this->x0y0.Y <= targ.Y && this->x1y1.Y >= targ.Y)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool is_valid()
        {
            if (this->x0y0.X == -1 || this->x0y0.Y == -1)
            {
                return 0;
            }
            if (this->x0y1.X == -1 || this->x0y1.Y == -1)
            {
                return 0;
            }
            if (this->x1y0.X == -1 || this->x1y0.Y == -1)
            {
                return 0;
            }
            if (this->x1y1.X == -1 || this->x1y1.Y == -1)
            {
                return 0;
            }
            return 1;
        }
    };
}
