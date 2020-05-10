#include "CoreUtilsPch.h"
#include <CoreUtils/LexicalCast.h>

namespace Babylon
{
namespace Utils
{
    //--------------------------------------------------------------------------------

    LexicalCastFailed::LexicalCastFailed(std::string const& reason) : BabylonException(reason, false) { }

    //--------------------------------------------------------------------------------

} // namespace Utils

//--------------------------------------------------------------------------------

} // namespace Babylon
