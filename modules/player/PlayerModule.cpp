#include "PlayerEndPoint.hpp"
#include "KmsMediaPlayerEndPointType_constants.h"
#include <module.hpp>

namespace kurento
{

static std::shared_ptr<MediaObjectImpl>
objectFactory (MediaSet &mediaSet, std::shared_ptr< MediaPipeline > parent,
               const std::map< std::string, KmsMediaParam > &params)
{
  return std::shared_ptr<MediaObjectImpl> (new PlayerEndPoint (mediaSet, parent,
         params) );
}

static std::string
getName()
{
  return g_KmsMediaPlayerEndPointType_constants.TYPE_NAME;
}

KURENTO_CREATE_MODULE (KURENTO_MODULE_ELEMENT, getName, objectFactory);

} // kurento