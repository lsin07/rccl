/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.14.v202310241605.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_RCCLTEST_Rccl_Test_STUB_DEFAULT_HPP_
#define V1_RCCLTEST_Rccl_Test_STUB_DEFAULT_HPP_


#include <CommonAPI/Export.hpp>

#include <v1/rccltest/RcclTestStub.hpp>
#include <cassert>
#include <sstream>

# if defined(_MSC_VER)
#  if _MSC_VER >= 1300
/*
 * Diamond inheritance is used for the CommonAPI::Proxy base class.
 * The Microsoft compiler put warning (C4250) using a desired c++ feature: "Delegating to a sister class"
 * A powerful technique that arises from using virtual inheritance is to delegate a method from a class in another class
 * by using a common abstract base class. This is also called cross delegation.
 */
#    pragma warning( disable : 4250 )
#  endif
# endif

namespace v1 {
namespace rccltest {

/**
 * Provides a default implementation for RcclTestStubRemoteEvent and
 * RcclTestStub. Method callbacks have an empty implementation,
 * remote set calls on attributes will always change the value of the attribute
 * to the one received.
 *
 * Override this stub if you only want to provide a subset of the functionality
 * that would be defined for this service, and/or if you do not need any non-default
 * behaviour.
 */
class COMMONAPI_EXPORT_CLASS_EXPLICIT RcclTestStubDefault
    : public virtual RcclTestStub {
public:
    COMMONAPI_EXPORT RcclTestStubDefault()
        : remoteEventHandler_(this),
          interfaceVersion_(RcclTest::getInterfaceVersion()) {
    }

    COMMONAPI_EXPORT const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> _client) {
        (void)_client;
        return interfaceVersion_;
    }

    COMMONAPI_EXPORT RcclTestStubRemoteEvent* initStubAdapter(const std::shared_ptr< RcclTestStubAdapter> &_adapter) {
        CommonAPI::Stub<RcclTestStubAdapter, RcclTestStubRemoteEvent>::stubAdapter_ = _adapter;
        return &remoteEventHandler_;
    }

    COMMONAPI_EXPORT virtual void fireHelloEvent(const std::string &_message) {
        RcclTestStub::fireHelloEvent(_message);
    }


protected:
    class COMMONAPI_EXPORT_CLASS_EXPLICIT RemoteEventHandler: public virtual RcclTestStubRemoteEvent {
    public:
        COMMONAPI_EXPORT RemoteEventHandler(RcclTestStubDefault *_defaultStub)
            : 
              defaultStub_(_defaultStub) {
        }


    private:
        RcclTestStubDefault *defaultStub_;
    };
protected:
    RcclTestStubDefault::RemoteEventHandler remoteEventHandler_;

private:


    CommonAPI::Version interfaceVersion_;
};

} // namespace rccltest
} // namespace v1


// Compatibility
namespace v1_0 = v1;

#endif // V1_RCCLTEST_Rccl_Test_STUB_DEFAULT
