namespace hs
{
    /// <summary>
    /// register a actorIMG to the list
    /// </summary>
    /// <param name="target">the ID of targeting actorIMG.</param>
    inline int registerActorIMG(actorIMG target)
    {
        actorIMGs.push_back(target);
        return (int)actorIMGs.size() - 1;
    }
}

#include "hs_usr_namespace_beta_mouse.h"
