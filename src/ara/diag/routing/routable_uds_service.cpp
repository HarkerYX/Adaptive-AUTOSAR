#include "../diag_error_domain.h"
#include "./routable_uds_service.h"

namespace ara
{
    namespace diag
    {
        namespace routing
        {
            RoutableUdsService::RoutableUdsService(
                const ara::core::InstanceSpecifier &specifier,
                uint8_t sid) noexcept : mSpecifier{specifier},
                                        mSid{sid},
                                        mOffered{false}
            {
            }

            ara::core::Result<void> RoutableUdsService::Offer()
            {
                if (mOffered)
                {
                    ara::core::ErrorDomain *_errorDomain{DiagErrorDomain::GetDiagDomain()};
                    auto _diagErrorDomain{static_cast<DiagErrorDomain *>(_errorDomain)};
                    ara::core::ErrorCode _errorCode{_diagErrorDomain->MakeErrorCode(DiagErrc::kAlreadyOffered)};
                    auto _result{ara::core::Result<void>::FromError(_errorCode)};

                    return _result;
                }
                else
                {
                    mOffered = true;
                    ara::core::Result<void> _result;

                    return _result;
                }
            }

            bool RoutableUdsService::IsOffered() const noexcept
            {
                return mOffered;
            }

            void RoutableUdsService::StopOffer() noexcept
            {
                mOffered = false;
            }
        }
    }
}