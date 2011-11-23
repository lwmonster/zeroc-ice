// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

#ifndef ICE_OBJECT_H
#define ICE_OBJECT_H

#include <IceUtil/Mutex.h>
#include <Ice/GCShared.h>
#include <Ice/ObjectF.h>
#include <Ice/ProxyF.h>
#include <Ice/IncomingAsyncF.h>
#include <Ice/Current.h>
#include <Ice/StreamF.h>

namespace IceInternal
{

class Incoming;
class BasicStream;

enum DispatchStatus
{
    DispatchOK,
    DispatchUserException,
    DispatchObjectNotExist,
    DispatchFacetNotExist,
    DispatchOperationNotExist,
    DispatchUnknownLocalException,
    DispatchUnknownUserException,
    DispatchUnknownException,
    DispatchAsync // "Pseudo dispatch status", used internally only to indicate async dispatch.
};

}

namespace Ice
{

//
// No virtual inheritance from IceUtil::GCShared is required. This
// used to be virtual inheritance from IceUtil::Shared, because we
// could derive multiple times from IceUtil::Shared, such as deriving
// a servant class from both Ice::Object and IceUtil::Thread. However,
// we never derive from IceUtil::GCShared more than once.
//
class ICE_API Object : public IceInternal::GCShared
{
public:

    virtual bool operator==(const Object&) const;
    virtual bool operator!=(const Object&) const;
    virtual bool operator<(const Object&) const;

    virtual Int ice_hash() const;

    virtual bool ice_isA(const std::string&, const Current& = Current()) const;
    IceInternal::DispatchStatus ___ice_isA(IceInternal::Incoming&, const Current&);

    virtual void ice_ping(const Current&  = Current()) const;
    IceInternal::DispatchStatus ___ice_ping(IceInternal::Incoming&, const Current&);

    virtual std::vector< std::string> ice_ids(const Current& = Current()) const;
    IceInternal::DispatchStatus ___ice_ids(IceInternal::Incoming&, const Current&);

    virtual const std::string& ice_id(const Current& = Current()) const;
    IceInternal::DispatchStatus ___ice_id(IceInternal::Incoming&, const Current&);

    virtual Int ice_operationAttributes(const std::string&) const;

    static const std::string& ice_staticId();

    virtual ObjectPtr ice_clone() const;

    virtual void ice_preMarshal();
    virtual void ice_postUnmarshal();

    static std::string __all[];
    virtual IceInternal::DispatchStatus __dispatch(IceInternal::Incoming&, const Current&);

    virtual void __write(IceInternal::BasicStream*) const;
    virtual void __read(IceInternal::BasicStream*, bool);

    virtual void __write(const OutputStreamPtr&) const;
    virtual void __read(const InputStreamPtr&, bool);

    virtual void __gcReachable(IceInternal::GCCountMap&) const {}
    virtual void __gcClear() {}

protected:

    Object() {} // This class is abstract.
    virtual ~Object() {}

    static void __checkMode(OperationMode, OperationMode);
};

class ICE_API Blobject : virtual public Object
{
public:

    // Returns true if ok, false if user exception.
    virtual bool ice_invoke(const std::vector<Byte>&, std::vector<Byte>&, const Current&) = 0;
    virtual IceInternal::DispatchStatus __dispatch(IceInternal::Incoming&, const Current&);
};

class ICE_API BlobjectArray : virtual public Object
{
public:

    // Returns true if ok, false if user exception.
    virtual bool ice_invoke(const std::pair<const Byte*, const Byte*>&, std::vector<Byte>&, const Current&) = 0;
    virtual IceInternal::DispatchStatus __dispatch(IceInternal::Incoming&, const Current&);
};

class ICE_API BlobjectAsync : virtual public Object
{
public:

    // Returns true if ok, false if user exception.
    virtual void ice_invoke_async(const AMD_Object_ice_invokePtr&, const std::vector<Byte>&, const Current&) = 0;
    virtual IceInternal::DispatchStatus __dispatch(IceInternal::Incoming&, const Current&);
};

class ICE_API BlobjectArrayAsync : virtual public Object
{
public:

    // Returns true if ok, false if user exception.
    virtual void ice_invoke_async(const AMD_Array_Object_ice_invokePtr&, const std::pair<const Byte*, const Byte*>&,
                                  const Current&) = 0;
    virtual IceInternal::DispatchStatus __dispatch(IceInternal::Incoming&, const Current&);
};

ICE_API void ice_writeObject(const OutputStreamPtr&, const ObjectPtr&);
ICE_API void ice_readObject(const InputStreamPtr&, ObjectPtr&);

}

#endif
