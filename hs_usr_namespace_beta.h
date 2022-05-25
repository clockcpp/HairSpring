namespace hs
{
    /// <summary>
    /// register a actorIMG to the list
    /// </summary>
    /// <param name="target">the ID of targeting actorIMG.</param>
    int registerActorIMG(actorIMG target, string name)
    {
        actorIMGs.push_back(target);
        if (actorIDs.count(name) != 0)
        {
            mav("Attempt to create actor which has the same name with another one.");
        }
        actorIDs.insert({ name, (int)actorIMGs.size() - 1 });
        return (int)actorIMGs.size() - 1;
    }
    /// <summary>
    /// register a actorIMG to the list
    /// </summary>
    /// <param name="target">the ID of targeting actorIMG.</param>
    int registerActorIMGByID(actorIMG target)
    {
        actorIMGs.push_back(target);
        return (int)actorIMGs.size() - 1;
    }
    /// <summary>
    /// look for a actor with following name
    /// </summary>
    /// <param name="name">the name</param>
    /// <returns>the id, if not found then return -1</returns>
    int getActor(string name)
    {
        map<string, int>::iterator iter;
        iter = actorIDs.find(name);
        if (iter != actorIDs.end())
        {
            return iter->second;
        }
        else
        {
            return -1;
        }
        mav("at getActor(string name):\n  iterator out of range");
    }
}

#include "hs_usr_namespace_beta_mouse.h"
