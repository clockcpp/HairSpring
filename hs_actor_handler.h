namespace hs
{
    int registerActorIMG(actorIMG);
}


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
            if (actorIMGs[i].isLogicActor)
            {
                continue;
            }
            actorIMGs[i].remove(actorIMGs[i].lastPosition);
        }
        return;
    }
    void drawAll()
    {
        for (int i = 0; i < actorIMGs.size(); ++i)
        {
            if (actorIMGs[i].isLogicActor)
            {
                continue;
            }
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
            if (actorIMGs[i].isLogicActor)
            {
                continue;
            }
            actorIMGs[i].remove(actorIMGs[i].lastPosition);
            actorIMGs[i].draw(actorIMGs[i].position);
        }
        return;
    }
    bool threadedUpWith(int thisID, int targID)
    {
        // skip self
        if (thisID == targID)
        {
            return false;
        }
        // out of range
        if (actorIMGs.size() < thisID || actorIMGs.size() < targID)
        {
            return false;
        }
        // noclip
        if (actorIMGs[thisID].attr.NoClip || actorIMGs[targID].attr.NoClip)
        {
            return false;
        }
        // skip same position (unless logic actors)
        if (actorIMGs[thisID].position.X == actorIMGs[targID].position.X &&
            actorIMGs[thisID].position.Y == actorIMGs[targID].position.Y &&
            !actorIMGs[thisID].isLogicActor &&
            !actorIMGs[targID].isLogicActor
            )
        {
            return true;
        }

        // start testing
        bool flag = false;

        // create the box
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

        // add the position and anchor
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

        // check those box
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
            if (flag)
            {
                break;
            }
        }
        return flag;
    }
    bool threadedUp(int thisID, int* optionalIgnoreIDs = NULL)
    {
        // skip ignored actor.
        if (optionalIgnoreIDs != NULL)
        {
            // check every element of the ignored ids.
            for (int i = 0; i < sizeof(*optionalIgnoreIDs) / sizeof(int); ++i)
            {
                if (thisID == optionalIgnoreIDs[i])
                {
                    return false;
                }
            }
        }

        // start checking
        bool flag = false;
        for (int i = 0; i < actorIMGs.size(); ++i)
        {
            if (thisID == i)
            {
                continue;
            }
            if (threadedUpWith(thisID, i))
            {
                flag = true;
                break;
            }
        }
        return flag;
    }
    bool adjacentWith(int thisID, int targID)
    {
        bool ans = false;
        hs::actorIMG tmp;
        tmp = actorIMGs[thisID];
        
        // expand hitbox
        tmp.data.hitbox[0].X -= 1;
        tmp.data.hitbox[0].Y -= 1;
        tmp.data.hitbox[1].X += 1;
        tmp.data.hitbox[1].Y -= 1;
        tmp.data.hitbox[2].X -= 1;
        tmp.data.hitbox[2].Y += 1;
        tmp.data.hitbox[3].X += 1;
        tmp.data.hitbox[3].Y += 1;

        // start testing
        // register tmp actor
        tmp.isLogicActor = true;
        int id = hs::registerActorIMG(tmp);

        // test
        ans = threadedUpWith(id, targID);

        // free tmp actor
        actorHandler.removeByID(id);

        return ans;
    }
    bool adjacent(int thisID, int* optionalIgnoreIDs = NULL)
    {
        // skip ignored actor.
        if (optionalIgnoreIDs != NULL)
        {
            // check every element of the ignored ids.
            for (int i = 0; i < sizeof(*optionalIgnoreIDs) / sizeof(int); ++i)
            {
                if (thisID == optionalIgnoreIDs[i])
                {
                    return false;
                }
            }
        }

        // start checking
        bool flag = false;
        for (int i = 0; i < actorIMGs.size(); ++i)
        {
            if (thisID == i)
            {
                continue;
            }
            if (adjacentWith(thisID, i))
            {
                flag = true;
                break;
            }
        }
        return flag;
    }
    /// <summary>
    /// get the state of adjacent
    /// </summary>
    /// <param name="thisID"></param>
    /// <param name="targID"></param>
    /// <returns>ans+=: 0: nil; 1: UP; 10: DOWN, 100: L, 1000: R</returns>
    int getAdjacentState(int thisID, int targID)
    {
        if (!actorHandler.adjacentWith(thisID, targID))
        {
            return 0;
        }

        int ans = 0;
        const short binMap[4] = { 1,2,4,8 };

        // X: self
        // #: target

        // X
        // #

        if (
            actorIMGs[thisID].position.Y + 
            actorIMGs[thisID].anchor.Y + 
            actorIMGs[thisID].data.hitbox[3].Y+1
            ==
            actorIMGs[targID].position.Y + 
            actorIMGs[targID].anchor.Y + 
            actorIMGs[targID].data.hitbox[0].Y
        )
        {
            ans |= binMap[0];
        }

        // #
        // X
        if (
            actorIMGs[thisID].position.Y +
            actorIMGs[thisID].anchor.Y +
            actorIMGs[thisID].data.hitbox[0].Y-1
            ==
            actorIMGs[targID].position.Y +
            actorIMGs[targID].anchor.Y +
            actorIMGs[targID].data.hitbox[3].Y
        )
        {
            ans |= binMap[1];
        }

        // X#
        if (
            actorIMGs[thisID].position.X +
            actorIMGs[thisID].anchor.X +
            actorIMGs[thisID].data.hitbox[3].X+1
            ==
            actorIMGs[targID].position.X +
            actorIMGs[targID].anchor.X +
            actorIMGs[targID].data.hitbox[0].X
        )
        {
            ans |= binMap[2];
        }

        // #X
        if (actorIMGs[thisID].position.X +
            actorIMGs[thisID].anchor.X +
            actorIMGs[thisID].data.hitbox[0].X - 1
            ==
            actorIMGs[targID].position.X +
            actorIMGs[targID].anchor.X +
            actorIMGs[targID].data.hitbox[3].X
            )
        {
            ans |= binMap[3];
        }

        // prevent corners
        return ans;
    }
    /// <summary>
    /// get the state of adjacent
    /// </summary>
    /// <param name="thisID"></param>
    /// <param name="targID"></param>
    /// <returns>ans+=: 0: nil; 1: UP; 10: DOWN, 100: L, 1000: R</returns>
    int getAdjacentStateNoRepeat(int thisID, int targID)
    {
        if (!actorHandler.adjacentWith(thisID, targID))
        {
            return 0;
        }

        int ans = 0;
        const short binMap[4] = { 1,2,4,8 };

        // X: self
        // #: target

        // X
        // #

        if (
            actorIMGs[thisID].position.Y +
            actorIMGs[thisID].anchor.Y +
            actorIMGs[thisID].data.hitbox[3].Y + 1
            ==
            actorIMGs[targID].position.Y +
            actorIMGs[targID].anchor.Y +
            actorIMGs[targID].data.hitbox[0].Y
            )
        {
            ans = binMap[0];
            return ans;
        }

        // #
        // X
        if (
            actorIMGs[thisID].position.Y +
            actorIMGs[thisID].anchor.Y +
            actorIMGs[thisID].data.hitbox[0].Y - 1
            ==
            actorIMGs[targID].position.Y +
            actorIMGs[targID].anchor.Y +
            actorIMGs[targID].data.hitbox[3].Y
            )
        {
            ans = binMap[1];
            return ans;
        }

        // X#
        if (
            actorIMGs[thisID].position.X +
            actorIMGs[thisID].anchor.X +
            actorIMGs[thisID].data.hitbox[3].X + 1
            ==
            actorIMGs[targID].position.X +
            actorIMGs[targID].anchor.X +
            actorIMGs[targID].data.hitbox[0].X
            )
        {
            ans = binMap[2];
            return ans;
        }

        // #X
        if (actorIMGs[thisID].position.X +
            actorIMGs[thisID].anchor.X +
            actorIMGs[thisID].data.hitbox[0].X - 1
            ==
            actorIMGs[targID].position.X +
            actorIMGs[targID].anchor.X +
            actorIMGs[targID].data.hitbox[3].X
            )
        {
            ans = binMap[3];
            return ans;
        }

        // didn't get anything
        return 0;
    }
} actorHandler;
