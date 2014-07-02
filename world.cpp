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

#pragma warn -use

#include "world.hpp"


World* World::_instance = 0;

World::World() {};
World::~World() {};

World* World::Instance() {
	if (_instance == 0) {
   	_instance = new World;
   }
   return _instance;
}

int World::readWorld(char *p_sWorld) {
      	struct stat results;

         // get the number of bytes in the file
      	stat(p_sWorld, &results);
         m_lWorldSize = results.st_size;

         // open the file
         ifstream o_File (p_sWorld, ios::in | ios::binary);
         if (!o_File.eof() && !o_File.fail()) {
         	o_File.seekg(0, o_File.end);
            streampos iFileSize = o_File.tellg();

            m_cWorld = (char *)malloc((iFileSize)*sizeof(char));
            
            if (m_cWorld==NULL) {
            	cout << "error allocating memory." << endl;
            }

            o_File.seekg(0, o_File.beg);
            o_File.read(m_cWorld, iFileSize);
         }

         cout << "constructor read " << sizeof(m_cWorld) << " elements." << endl;

};

