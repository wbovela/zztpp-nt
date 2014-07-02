// published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#ifndef _WORLD_HPP
#define _WORLD_HPP

#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <malloc>

//#include "gameinfo.hpp"
//#include "board.hpp"

class World {

	public:
   	static World* Instance();
      int readWorld(char *p_sWorld);

   protected:
   	World ();
      ~World ();

   private:
   	static World* _instance;
      unsigned long m_lWorldSize;
      char *m_cWorld;

   	getGameInfo(void);
      getBoardByNumber(int p_iBoard);
};

#endif