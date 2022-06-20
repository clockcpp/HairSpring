/**
 *
 * !--			FILENAME: "hs_actor_handler.h"			--
 * !--			ORGANIZATION: 2022(c) ExL Studios   	--
 * !--			PROGRAMMER:	Executif			    	--
 *
 * Summary: Functions for controlling actors
 *
 * Type: Open-source
 * License: LGPL 2.1
 *
**/

namespace hs
{
    int registerActorIMGByID(actorIMG target);
    int getActor(string);
}

/// <summary>
/// a class that used to control actors
/// use "actorHandler.<FunctionName>" in your code.
/// </summary>
class HS_actorsHandler
{
public:
    /// <summary>
    /// get the actor by its ID
    /// </summary>
    /// <param name="ID"></param>
    /// <returns>the actor</returns>
    inline hs::actorIMG getActorByID(int ID)
    {
        return actorIMGs[ID];
    }
    /// <summary>
    /// get the count of actors, !! including logic actors!!
    /// </summary>
    /// <returns></returns>
    inline int getCountTotal()
    {
        return (int)actorIMGs.size();
    }
    /// <summary>
    /// remove a actor by its ID
    /// </summary>
    /// <param name="ID"></param>
    inline void removeByID(int ID)
    {
        actorIMGs.erase(actorIMGs.begin() + ID);
        return;
    }
    /// <summary>
    /// remove a actor by its name
    /// </summary>
    /// <param name="name"></param>
    void removeByName(string name)
    {
        int ID = hs::getActor(name);
        actorIMGs.erase(actorIMGs.begin() + ID);
        map<string, int>::iterator iter = actorIDs.begin();
        for (; iter != actorIDs.end(); ++iter)
        {
            if (iter->second == ID)
            {
                actorIDs.erase(iter);
                break;
            }
        }

        for (iter = actorIDs.begin();iter != actorIDs.end();++iter)
        {
            if (iter->second > ID)
            {
                --iter->second;
            }
        }
        return;
    }
    /// <summary>
    /// clear the actors,
    /// all ids will be unavailable
    /// </summary>
    void removeAll()
    {
        actorIMGs.clear();
        actorIDs.clear();
        return;
    }
    /// <summary>
    /// erase all actors from the screen
    /// </summary>
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
    /// <summary>
    /// draw all the actors (not logic actors) to the screen
    /// </summary>
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
    /// <summary>
    /// judge whether the actor hits another and threaded-up with it
    /// </summary>
    /// <param name="thisID"></param>
    /// <param name="targID"></param>
    /// <returns></returns>
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
    /// <summary>
    /// judge whether the actor hits any other actor and threaded-up with it
    /// </summary>
    /// <param name="thisID"></param>
    /// <param name="optionalIgnoreIDs"></param>
    /// <returns></returns>
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
    /// <summary>
    /// judge whether the actor hits another but didn't threaded-up with it
    /// </summary>
    /// <param name="thisID"></param>
    /// <param name="targID"></param>
    /// <returns></returns>
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
        int id = hs::registerActorIMGByID(tmp);

        // test
        ans = threadedUpWith(id, targID);

        // free tmp actor
        actorHandler.removeByID(id);

        return ans;
    }
    /// <summary>
    /// judge whether the actor hits any other actor but didn't threaded-up with it
    /// </summary>
    /// <param name="thisID"></param>
    /// <param name="optionalIgnoreIDs"></param>
    /// <returns></returns>
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
    /// <summary>
    /// judge whether the targeting actor is out-of-bundle.
    /// If so, return the state(use definition of HS_OOB_<STATE>), else return 0.
    /// Def list:
    /// HS_OOB_LEFT;
    /// HS_OOB_RIGHT;
    /// HS_OOB_UP;
    /// HS_OOB_DOWN.
    /// </summary>
    /// <param name="thisID">the actor that should be detected</param>
    /// <returns>the state(HS_OOB_)</returns>
    int getOutOfBundleState(int thisID)
    {
        // make the hitbox a 'box'
        hs::Box index;
        index.to_box
        (
            {
                actorIMGs[thisID].data.hitbox[0].X,
                actorIMGs[thisID].data.hitbox[0].Y
            },
            {
                actorIMGs[thisID].data.hitbox[3].X,
                actorIMGs[thisID].data.hitbox[3].Y
            }
        );

        // the box is valid?
        if (!index.is_valid())
        {
            return HS_OOB_INVALID;
        }

        // judge whether it is out of bundle
        /**
         *                              x=n, y<0
         *              +=======================================+
         *              |------------------------------------_OX|
         *              |               HS_OOB_UP               |
         *              |                                       |
         * x<0, y=n     | HS_OOB_LEFT             HS_OOB_RIGHT  |       x>MAX, y=n
         *              |                                       |
         *              |                                       |
         *              |               HS_OOB_DOWN             |
         *              +---------------------------------------+
         *                              x=n, y>MAXN
        **/
        short x[4];
        short y[4];

        for (int i = 0; i < 4; ++i)
        {
            x[i] = actorIMGs[thisID].position.X + actorIMGs[thisID].data.hitbox[i].X + actorIMGs[thisID].anchor.X;
            y[i] = actorIMGs[thisID].position.Y + actorIMGs[thisID].data.hitbox[i].Y + actorIMGs[thisID].anchor.Y;
        }

        for (int i = 0; i < 4; ++i)
        {
            if (y[i] < 0)
            {
                return HS_OOB_UP;
            }
            if (y[i] > cfg.consoleSizeY)
            {
                return HS_OOB_DOWN;
            }
            if (x[i] < 0)
            {
                return HS_OOB_LEFT;
            }
            if (x[i] > cfg.consoleSizeX)
            {
                return HS_OOB_RIGHT;
            }
        }

        // nothing
        return HS_OOB_NOTHING;
    }

    void syncDataWithID(int self, int targ)
    {
        actorIMGs[targ].anchor = actorIMGs[self].anchor;
        actorIMGs[targ].attr.NoClip = actorIMGs[self].attr.NoClip;
        actorIMGs[targ].attr.NoGravity = actorIMGs[self].attr.NoGravity;
        actorIMGs[targ].teleport(actorIMGs[self].position);
    }
    void syncDataWithName(string self, string targ)
    {
        syncDataWithID(hs::getActor(self), hs::getActor(targ));
    }
} actorHandler;

// trigger part
namespace hs
{
    /// <summary>
    /// a class used to detecting actors
    /// </summary>
    class trigger
    {
    public:
        bool triggered = false;
        /// <summary>
        /// set two coord.s to current trigger
        /// </summary>
        /// <param name="xy">x[0]y[0]</param>
        /// <param name="x[1]y[1]"></param>
        /// <param name="targ">the detecting target</param>
        /// <returns>if success then return false</returns>
        bool set(COORD xy, COORD x1y1)
        {
            this->index.to_box(xy, x1y1);
            return !this->index.is_valid();
        }
        bool check(int targID)
        {
            // prevent wrong data
            if (!this->index.is_valid())
            {
                // return this is not on trigger
                return 0;
            }

            // init actor tmp for detecting
            hs::actorIMG tmp;

            // result will save here...
            bool ans = false;

            // set the hitbox

            tmp.data.hitbox[0].X = this->index.x0y0.X;
            tmp.data.hitbox[0].Y = this->index.x0y0.Y;
            tmp.data.hitbox[1].X = this->index.x1y0.X;
            tmp.data.hitbox[1].Y = this->index.x1y0.Y;
            tmp.data.hitbox[2].X = this->index.x0y1.X;
            tmp.data.hitbox[2].Y = this->index.x0y1.Y;
            tmp.data.hitbox[3].X = this->index.x1y1.X;
            tmp.data.hitbox[3].Y = this->index.x1y1.Y;

            // start testing
            // register tmp actor
            tmp.isLogicActor = true;
            int id = hs::registerActorIMGByID(tmp);

            // test
            ans = actorHandler.threadedUpWith(id, targID);

            // free tmp actor
            actorHandler.removeByID(id);

            // return the result
            this->triggered = ans == true ? true : this->triggered;
            return ans;
        }
    private:
        hs::Box index;
    };
};