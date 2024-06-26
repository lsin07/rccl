/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.14.v202310241606.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#ifndef V1_RCCLTEST_RCCL_TEST_SOMEIP_STUB_ADAPTER_HPP_
#define V1_RCCLTEST_RCCL_TEST_SOMEIP_STUB_ADAPTER_HPP_

#include <v1/rccltest/RcclTestStub.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>
#include <CommonAPI/SomeIP/StubAdapterHelper.hpp>
#include <CommonAPI/SomeIP/StubAdapter.hpp>
#include <CommonAPI/SomeIP/Factory.hpp>
#include <CommonAPI/SomeIP/Types.hpp>
#include <CommonAPI/SomeIP/Constants.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace rccltest {

template <typename _Stub = ::v1::rccltest::RcclTestStub, typename... _Stubs>
class RcclTestSomeIPStubAdapterInternal
    : public virtual RcclTestStubAdapter,
      public CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...>,
      public std::enable_shared_from_this< RcclTestSomeIPStubAdapterInternal<_Stub, _Stubs...>>
{
public:
    typedef CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...> RcclTestSomeIPStubAdapterHelper;

    ~RcclTestSomeIPStubAdapterInternal() {
        deactivateManagedInstances();
        RcclTestSomeIPStubAdapterHelper::deinit();
    }

    void fireHelloEvent(const std::string &_message);

    void deactivateManagedInstances() {}
    
    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v1::rccltest::RcclTestStub,
        CommonAPI::Version
    > getRcclTestInterfaceVersionStubDispatcher;

    RcclTestSomeIPStubAdapterInternal(
        const CommonAPI::SomeIP::Address &_address,
        const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
        const std::shared_ptr<CommonAPI::StubBase> &_stub):
        CommonAPI::SomeIP::StubAdapter(_address, _connection),
        RcclTestSomeIPStubAdapterHelper(
            _address,
            _connection,
            std::dynamic_pointer_cast< RcclTestStub>(_stub)),
        getRcclTestInterfaceVersionStubDispatcher(&RcclTestStub::lockInterfaceVersionAttribute, &RcclTestStub::getInterfaceVersion, false, true)
    {
        // Provided events/fields
        {
            std::set<CommonAPI::SomeIP::eventgroup_id_t> itsEventGroups;
            itsEventGroups.insert(CommonAPI::SomeIP::eventgroup_id_t(0x80f2));
            CommonAPI::SomeIP::StubAdapter::registerEvent(CommonAPI::SomeIP::event_id_t(0x80f2), itsEventGroups, CommonAPI::SomeIP::event_type_e::ET_EVENT, CommonAPI::SomeIP::reliability_type_e::RT_UNRELIABLE);
        }
    }

    // Register/Unregister event handlers for selective broadcasts
    void registerSelectiveEventHandlers();
    void unregisterSelectiveEventHandlers();

};

template <typename _Stub, typename... _Stubs>
void RcclTestSomeIPStubAdapterInternal<_Stub, _Stubs...>::fireHelloEvent(const std::string &_message) {
    CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment> deployed_message(_message, static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr));
    CommonAPI::SomeIP::StubEventHelper<CommonAPI::SomeIP::SerializableArguments<  CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment > 
    >>
        ::sendEvent(
            *this,
            CommonAPI::SomeIP::event_id_t(0x80f2),
            false,
             deployed_message 
    );
}


template <typename _Stub, typename... _Stubs>
void RcclTestSomeIPStubAdapterInternal<_Stub, _Stubs...>::registerSelectiveEventHandlers() {

}

template <typename _Stub, typename... _Stubs>
void RcclTestSomeIPStubAdapterInternal<_Stub, _Stubs...>::unregisterSelectiveEventHandlers() {

}

template <typename _Stub = ::v1::rccltest::RcclTestStub, typename... _Stubs>
class RcclTestSomeIPStubAdapter
    : public RcclTestSomeIPStubAdapterInternal<_Stub, _Stubs...> {
public:
    RcclTestSomeIPStubAdapter(const CommonAPI::SomeIP::Address &_address,
                                            const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
                                            const std::shared_ptr<CommonAPI::StubBase> &_stub)
        : CommonAPI::SomeIP::StubAdapter(_address, _connection),
          RcclTestSomeIPStubAdapterInternal<_Stub, _Stubs...>(_address, _connection, _stub) {
    }
};

} // namespace rccltest
} // namespace v1

#endif // V1_RCCLTEST_Rccl_Test_SOMEIP_STUB_ADAPTER_HPP_
