
class HS_actorsHandler
{
public:
    inline hs::actorIMG getActorByID(int ID)
    {
        return actorIMGs[ID];
    }
    inline int getCountTotal()
    {
        return (int)actorIMGs.size();
    }
    inline void removeByID(int ID)
    {
        actorIMGs.erase(actorIMGs.begin() + ID);
        return;
    }
    /// <summary>
    /// clear the actors,
    /// all ids will be unavailable
    /// </summary>
    void removeAll()
    {
        actorIMGs.clear();
        return;
    }
    void eraseAll()
    {
        for (int i = 0; i < actorIMGs.size(); ++i)
        {
            actorIMGs[i].remove(actorIMGs[i].lastPosition);
        }
        return;
    }
    void drawAll()
    {
        for (int i = 0; i < actorIMGs.size(); ++i)
        {
            actorIMGs[i].draw(actorIMGs[i].position);
        }
        return;
    }
    /// <summary>
    /// this only redraw the actors by id order
    /// </summary>
    void redrawAll()
    {
        for (int i = 0; i < actorIMGs.size(); ++i)
        {
            actorIMGs[i].remove(actorIMGs[i].lastPosition);
            actorIMGs[i].draw(actorIMGs[i].position);
        }
        return;
    }
    bool threadedUpWith(int thisID, int targID)
    {
        if (thisID == targID)
        {
            return false;
        }
        if (actorIMGs.size() < thisID || actorIMGs.size() < targID)
        {
            return false;
        }
        if (actorIMGs[thisID].attr.NoClip || actorIMGs[targID].attr.NoClip)
        {
            return false;
        }
        if (actorIMGs[thisID].position.X == actorIMGs[targID].position.X &&
            actorIMGs[thisID].position.Y == actorIMGs[targID].position.Y)
        {
            return true;
        }

        bool flag = false;

        register COORD thisbox[4] =
        {
            actorIMGs[thisID].data.hitbox[0],
            actorIMGs[thisID].data.hitbox[1],
            actorIMGs[thisID].data.hitbox[2],
            actorIMGs[thisID].data.hitbox[3]
        };
        register COORD targbox[4] =
        {
            actorIMGs[targID].data.hitbox[0],
            actorIMGs[targID].data.hitbox[1],
            actorIMGs[targID].data.hitbox[2],
            actorIMGs[targID].data.hitbox[3]
        };

        for (int i = 0; i < 4; ++i)
        {
            thisbox[i].X += actorIMGs[thisID].position.X;
            thisbox[i].Y += actorIMGs[thisID].position.Y;
            thisbox[i].X += actorIMGs[thisID].anchor.X;
            thisbox[i].Y += actorIMGs[thisID].anchor.Y;
            
            targbox[i].X += actorIMGs[targID].position.X;
            targbox[i].Y += actorIMGs[targID].position.Y;
            targbox[i].X += actorIMGs[targID].anchor.X;
            targbox[i].Y += actorIMGs[targID].anchor.Y;
        }

        for (int i = 0; i < 4; ++i)
        {
            flag |= (
                thisbox[0].X <= targbox[i].X &&
                thisbox[0].Y <= targbox[i].Y &&
                thisbox[3].X >= targbox[i].X &&
                thisbox[3].Y >= targbox[i].Y
                );
            flag |= (
                targbox[0].X <= thisbox[i].X &&
                targbox[0].Y <= thisbox[i].Y &&
                targbox[3].X >= thisbox[i].X &&
                targbox[3].Y >= thisbox[i].Y
                );

        }
        return flag;
    }
    bool threadedUp(int thisID)
    {
        bool flag = false;
        for (int i = 0; i < actorIMGs.size(); ++i)
        {
            if (thisID == i)
            {
                continue;
            }
            if (this->threadedUpWith(thisID, i))
            {
                flag = true;
                break;
            }
        }
        return flag;
    }
} actorHandler;
