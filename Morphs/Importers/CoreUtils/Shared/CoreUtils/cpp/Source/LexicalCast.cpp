#include "CoreUtilsPch.h"
#include <CoreUtils/LexicalCast.h>

namespace Spectre
{
namespace Utils
{
    //--------------------------------------------------------------------------------

    LexicalCastFailed::LexicalCastFailed(std::string const& reason) : SpectreException(reason, false) { }

    //--------------------------------------------------------------------------------

} // namespace Utils

//--------------------------------------------------------------------------------

} // namespace Spectre
