/**
 * 
 * !--			FILENAME: "hs_usr_namespace_alpha_cfg.h"			--
 * !--			ORGANIZATION: 2022(c) ExL Studios					--
 * !--			PROGRAMMER:	Executif								--
 * 
 * Summary: The part that reads config files
 * 
 * Type: Open-source
 * License: LGPL 2.1
 * 
**/

namespace hs
{
    /// <summary>
    /// read a bool value from a config file
    /// config file:
    /// name = true
    /// name = false
    /// #this is note
    /// </summary>
    /// <param name="filePath">path of the config file</param>
    /// <param name="name">name of the tag</param>
    /// <returns>value if success</returns>
    bool readConfigBool(string filePath, string name)
    {
        return _HairSpring::readConfigBool(filePath, name);
    }
    /// <summary>
    /// read a int value from a config file
    /// config file:
    /// name = value
    /// #this is note
    /// </summary>
    /// <param name="filePath">path of the config file</param>
    /// <param name="name">name of the tag</param>
    /// <returns>value if success</returns>
    int readConfigInt(string filePath, string name)
    {
        return _HairSpring::readConfigInt(filePath, name);
    }
    /// <summary>
    /// read a string value from a config file
    /// config file:
    /// name = "value"
    /// #this is note
    /// </summary>
    /// <param name="filePath">path of the config file</param>
    /// <param name="name">name of the tag</param>
    /// <returns>value if success</returns>
    string readConfigStr(string filePath, string name)
    {
        return _HairSpring::readConfigStr(filePath, name);
    }
}