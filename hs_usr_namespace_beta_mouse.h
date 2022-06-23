/**
 * 
 * !--			FILENAME: "hs_usr_namespace_beta_mouth.h"			--
 * !--			ORGANIZATION: 2022(c) ExL Studios					--
 * !--			PROGRAMMER:	Executif								--
 * 
 * Summary: The secondary mouse controller
 * 
 * Type: Open-source
 * License: LGPL 2.1
 * 
**/

namespace hs
{
    /// <summary>
    /// if mouse is down at a actor's hitbox...
    /// </summary>
    bool mouseDownAtActor(int key, int targID)
    {
        if (actorIMGs.size() < targID)
        {
            return false;
        }
        return mouseDownIn(key,
            {
                short
                (
                    actorIMGs[targID].position.X +
                    actorIMGs[targID].anchor.X +
                    actorIMGs[targID].data.hitbox[0].X
                ),
                short
                (
                    actorIMGs[targID].position.Y +
                    actorIMGs[targID].anchor.Y +
                    actorIMGs[targID].data.hitbox[0].Y
                )
            },
            {
                short
                (
                    actorIMGs[targID].position.X +
                    actorIMGs[targID].anchor.X +
                    actorIMGs[targID].data.hitbox[3].X
                ),
                short
                (
                    actorIMGs[targID].position.Y +
                    actorIMGs[targID].anchor.Y +
                    actorIMGs[targID].data.hitbox[3].Y
                )
            }
        );
    }
    /// <summary>
    /// the same to mousedownatactor, but only active once until it releases.
    /// </summary>
    bool mousePressAtActor(int key, int targID)
    {
        if (actorIMGs.size() < targID)
        {
            return false;
        }
        return mousePressIn(key,
            {
                short
                (
                    actorIMGs[targID].position.X +
                    actorIMGs[targID].anchor.X +
                    actorIMGs[targID].data.hitbox[0].X
                ),
                short
                (
                    actorIMGs[targID].position.Y +
                    actorIMGs[targID].anchor.Y +
                    actorIMGs[targID].data.hitbox[0].Y
                )
            },
            {
                short
                (
                    actorIMGs[targID].position.X +
                    actorIMGs[targID].anchor.X +
                    actorIMGs[targID].data.hitbox[3].X
                ),
                short
                (
                    actorIMGs[targID].position.Y +
                    actorIMGs[targID].anchor.Y +
                    actorIMGs[targID].data.hitbox[3].Y
                )
            }
            );
    }
}
