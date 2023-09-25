//
// Generated file, do not edit! Created by opp_msgtool 6.0 from Packet.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "Packet_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

Register_Class(TcpIpPacket)

TcpIpPacket::TcpIpPacket(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

TcpIpPacket::TcpIpPacket(const TcpIpPacket& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

TcpIpPacket::~TcpIpPacket()
{
}

TcpIpPacket& TcpIpPacket::operator=(const TcpIpPacket& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void TcpIpPacket::copy(const TcpIpPacket& other)
{
    this->appHeader = other.appHeader;
    this->tcpHeader = other.tcpHeader;
    this->ipHeader = other.ipHeader;
    this->dllHeader = other.dllHeader;
    this->phyHeader = other.phyHeader;
    this->crc = other.crc;
    this->data = other.data;
    this->packetFormat = other.packetFormat;
}

void TcpIpPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->appHeader);
    doParsimPacking(b,this->tcpHeader);
    doParsimPacking(b,this->ipHeader);
    doParsimPacking(b,this->dllHeader);
    doParsimPacking(b,this->phyHeader);
    doParsimPacking(b,this->crc);
    doParsimPacking(b,this->data);
    doParsimPacking(b,this->packetFormat);
}

void TcpIpPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->appHeader);
    doParsimUnpacking(b,this->tcpHeader);
    doParsimUnpacking(b,this->ipHeader);
    doParsimUnpacking(b,this->dllHeader);
    doParsimUnpacking(b,this->phyHeader);
    doParsimUnpacking(b,this->crc);
    doParsimUnpacking(b,this->data);
    doParsimUnpacking(b,this->packetFormat);
}

int TcpIpPacket::getAppHeader() const
{
    return this->appHeader;
}

void TcpIpPacket::setAppHeader(int appHeader)
{
    this->appHeader = appHeader;
}

int TcpIpPacket::getTcpHeader() const
{
    return this->tcpHeader;
}

void TcpIpPacket::setTcpHeader(int tcpHeader)
{
    this->tcpHeader = tcpHeader;
}

int TcpIpPacket::getIpHeader() const
{
    return this->ipHeader;
}

void TcpIpPacket::setIpHeader(int ipHeader)
{
    this->ipHeader = ipHeader;
}

int TcpIpPacket::getDllHeader() const
{
    return this->dllHeader;
}

void TcpIpPacket::setDllHeader(int dllHeader)
{
    this->dllHeader = dllHeader;
}

int TcpIpPacket::getPhyHeader() const
{
    return this->phyHeader;
}

void TcpIpPacket::setPhyHeader(int phyHeader)
{
    this->phyHeader = phyHeader;
}

int TcpIpPacket::getCrc() const
{
    return this->crc;
}

void TcpIpPacket::setCrc(int crc)
{
    this->crc = crc;
}

int TcpIpPacket::getData() const
{
    return this->data;
}

void TcpIpPacket::setData(int data)
{
    this->data = data;
}

const char * TcpIpPacket::getPacketFormat() const
{
    return this->packetFormat.c_str();
}

void TcpIpPacket::setPacketFormat(const char * packetFormat)
{
    this->packetFormat = packetFormat;
}

class TcpIpPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_appHeader,
        FIELD_tcpHeader,
        FIELD_ipHeader,
        FIELD_dllHeader,
        FIELD_phyHeader,
        FIELD_crc,
        FIELD_data,
        FIELD_packetFormat,
    };
  public:
    TcpIpPacketDescriptor();
    virtual ~TcpIpPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(TcpIpPacketDescriptor)

TcpIpPacketDescriptor::TcpIpPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(TcpIpPacket)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

TcpIpPacketDescriptor::~TcpIpPacketDescriptor()
{
    delete[] propertyNames;
}

bool TcpIpPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TcpIpPacket *>(obj)!=nullptr;
}

const char **TcpIpPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *TcpIpPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int TcpIpPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 8+base->getFieldCount() : 8;
}

unsigned int TcpIpPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_appHeader
        FD_ISEDITABLE,    // FIELD_tcpHeader
        FD_ISEDITABLE,    // FIELD_ipHeader
        FD_ISEDITABLE,    // FIELD_dllHeader
        FD_ISEDITABLE,    // FIELD_phyHeader
        FD_ISEDITABLE,    // FIELD_crc
        FD_ISEDITABLE,    // FIELD_data
        FD_ISEDITABLE,    // FIELD_packetFormat
    };
    return (field >= 0 && field < 8) ? fieldTypeFlags[field] : 0;
}

const char *TcpIpPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "appHeader",
        "tcpHeader",
        "ipHeader",
        "dllHeader",
        "phyHeader",
        "crc",
        "data",
        "packetFormat",
    };
    return (field >= 0 && field < 8) ? fieldNames[field] : nullptr;
}

int TcpIpPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "appHeader") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "tcpHeader") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "ipHeader") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "dllHeader") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "phyHeader") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "crc") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "data") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "packetFormat") == 0) return baseIndex + 7;
    return base ? base->findField(fieldName) : -1;
}

const char *TcpIpPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_appHeader
        "int",    // FIELD_tcpHeader
        "int",    // FIELD_ipHeader
        "int",    // FIELD_dllHeader
        "int",    // FIELD_phyHeader
        "int",    // FIELD_crc
        "int",    // FIELD_data
        "string",    // FIELD_packetFormat
    };
    return (field >= 0 && field < 8) ? fieldTypeStrings[field] : nullptr;
}

const char **TcpIpPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *TcpIpPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int TcpIpPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    TcpIpPacket *pp = omnetpp::fromAnyPtr<TcpIpPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void TcpIpPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    TcpIpPacket *pp = omnetpp::fromAnyPtr<TcpIpPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'TcpIpPacket'", field);
    }
}

const char *TcpIpPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    TcpIpPacket *pp = omnetpp::fromAnyPtr<TcpIpPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TcpIpPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    TcpIpPacket *pp = omnetpp::fromAnyPtr<TcpIpPacket>(object); (void)pp;
    switch (field) {
        case FIELD_appHeader: return long2string(pp->getAppHeader());
        case FIELD_tcpHeader: return long2string(pp->getTcpHeader());
        case FIELD_ipHeader: return long2string(pp->getIpHeader());
        case FIELD_dllHeader: return long2string(pp->getDllHeader());
        case FIELD_phyHeader: return long2string(pp->getPhyHeader());
        case FIELD_crc: return long2string(pp->getCrc());
        case FIELD_data: return long2string(pp->getData());
        case FIELD_packetFormat: return oppstring2string(pp->getPacketFormat());
        default: return "";
    }
}

void TcpIpPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TcpIpPacket *pp = omnetpp::fromAnyPtr<TcpIpPacket>(object); (void)pp;
    switch (field) {
        case FIELD_appHeader: pp->setAppHeader(string2long(value)); break;
        case FIELD_tcpHeader: pp->setTcpHeader(string2long(value)); break;
        case FIELD_ipHeader: pp->setIpHeader(string2long(value)); break;
        case FIELD_dllHeader: pp->setDllHeader(string2long(value)); break;
        case FIELD_phyHeader: pp->setPhyHeader(string2long(value)); break;
        case FIELD_crc: pp->setCrc(string2long(value)); break;
        case FIELD_data: pp->setData(string2long(value)); break;
        case FIELD_packetFormat: pp->setPacketFormat((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TcpIpPacket'", field);
    }
}

omnetpp::cValue TcpIpPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    TcpIpPacket *pp = omnetpp::fromAnyPtr<TcpIpPacket>(object); (void)pp;
    switch (field) {
        case FIELD_appHeader: return pp->getAppHeader();
        case FIELD_tcpHeader: return pp->getTcpHeader();
        case FIELD_ipHeader: return pp->getIpHeader();
        case FIELD_dllHeader: return pp->getDllHeader();
        case FIELD_phyHeader: return pp->getPhyHeader();
        case FIELD_crc: return pp->getCrc();
        case FIELD_data: return pp->getData();
        case FIELD_packetFormat: return pp->getPacketFormat();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'TcpIpPacket' as cValue -- field index out of range?", field);
    }
}

void TcpIpPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TcpIpPacket *pp = omnetpp::fromAnyPtr<TcpIpPacket>(object); (void)pp;
    switch (field) {
        case FIELD_appHeader: pp->setAppHeader(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_tcpHeader: pp->setTcpHeader(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_ipHeader: pp->setIpHeader(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_dllHeader: pp->setDllHeader(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_phyHeader: pp->setPhyHeader(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_crc: pp->setCrc(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_data: pp->setData(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_packetFormat: pp->setPacketFormat(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TcpIpPacket'", field);
    }
}

const char *TcpIpPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr TcpIpPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    TcpIpPacket *pp = omnetpp::fromAnyPtr<TcpIpPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void TcpIpPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    TcpIpPacket *pp = omnetpp::fromAnyPtr<TcpIpPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TcpIpPacket'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

