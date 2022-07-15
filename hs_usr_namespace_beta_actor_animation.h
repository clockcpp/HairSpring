/**
 *
 * !--			FILENAME: "hs_usr_namespace_beta_actor_animation.h"		--
 * !--			ORGANIZATION: 2022(c) ExL Studios						--
 * !--			PROGRAMMER:	Executif									--
 *
 * Summary: The part that controls the animation of actors
 *
 * Type: Open-source
 * License: LGPL 2.1
 *
**/

namespace hs
{
	/// <summary>
	/// the class that controls animate of actor
	/// </summary>
	class actorAni
	{
	public:
		/// <summary>
		/// get the handler
		/// </summary>
		/// <returns>returns current ID for changing</returns>
		inline int getID()
		{
			return this->data[now];
		}
		/// <summary>
		/// load animate frams from an animate list file
		/// </summary>
		/// <param name="path">the file path</param>
		void open(string path)
		{
			fstream fin;
			fin.open(path);
			char tmp[HS_MAXN];

			// failed to open actor
			if (fin.fail())
			{
				mav("Failed to open animated actor file at <actorAni>.open(\"" + path + "\").");
			}

			// open all the actors
			actorIMG tmpActor;
			while (!fin.eof())
			{
				// read a line
				memset(tmp, 0, sizeof(tmp));
				fin.getline(tmp, sizeof(tmp));
				
				// jump comments
				if (tmp[0] == '#')
				{
					continue;
				}
				// jump lines that contains nothing
				if (tmp[0] == '\0')
				{
					continue;
				}

				// register actor
				tmpActor = hs::createActorFromFile(tmp);
				this->data.push_back(hs::registerActorIMGByID(tmpActor));
			}
		}
		/// <summary>
		/// change current frame to selected frame 
		/// </summary>
		/// <param name="internalNum">the frame number</param>
		void changeTo(int internalNum)
		{
			if (internalNum > this->data.size() - 1)
			{
				mav("Unable to load a not exist actor at <actorAni>.changeTo");
			}

			// sync data
			actorHandler.syncDataWithID(this->now, internalNum);
			
			// erase old one
			actorIMGs[this->data[this->now]].remove(actorIMGs[this->data[this->now]].position);

			// set invisible
			for (int i = 0; i < this->data.size(); ++i)
			{
				actorIMGs[this->data[i]].isLogicActor = true;
			}
			actorIMGs[this->data[internalNum]].isLogicActor = false;

			// draw new one
			actorIMGs[this->data[internalNum]].draw(actorIMGs[this->data[internalNum]].position);

			// set new one
			this->now = internalNum;
		}
		/// <summary>
		/// change current frame to next(become the first if already reached the end)
		/// </summary>
		void showNext(int after = 0, int before = 0x3f3f3f)
		{
			if (before == 0x3f3f3f)
			{
				before = int(this->data.size() - 1);
			}

			int tmp = this->now;
			if (tmp == before)
			{
				tmp = after;
			}
			else
			{
				++tmp;
			}

			this->changeTo(tmp);
		}
		/// <summary>
		/// change current frame to previous(become the last if this is the first)
		/// </summary>
		void showPrev(int after = 0, int before = 0x3f3f3f)
		{
			if (before == 0x3f3f3f)
			{
				before = int(this->data.size() - 1);
			}

			int tmp = this->now;
			if (tmp == after)
			{
				tmp = before;
			}
			else
			{
				--tmp;
			}
			this->changeTo(tmp);
		}
		/// <summary>
		/// delete self and all images about self
		/// </summary>
		void remove()
		{
			// remove one by one
			for (int i = 0; i < this->data.size(); ++i)
			{
				actorHandler.removeByID(data[i]);
			}
			data.clear();
		}
	private:
		vector<int> data;
		int now = 0;
	};
}
