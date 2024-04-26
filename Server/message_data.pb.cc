// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message_data.proto

#include "message_data.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace proto {
PROTOBUF_CONSTEXPR MessageData::MessageData(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.message_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.sender_name_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.date_of_sending_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.time_of_sending_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.sender_id_)*/0u
  , /*decltype(_impl_.receiver_id_)*/0u
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct MessageDataDefaultTypeInternal {
  PROTOBUF_CONSTEXPR MessageDataDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~MessageDataDefaultTypeInternal() {}
  union {
    MessageData _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 MessageDataDefaultTypeInternal _MessageData_default_instance_;
}  // namespace proto
static ::_pb::Metadata file_level_metadata_message_5fdata_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_message_5fdata_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_message_5fdata_2eproto = nullptr;

const uint32_t TableStruct_message_5fdata_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::proto::MessageData, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::proto::MessageData, _impl_.message_),
  PROTOBUF_FIELD_OFFSET(::proto::MessageData, _impl_.sender_id_),
  PROTOBUF_FIELD_OFFSET(::proto::MessageData, _impl_.sender_name_),
  PROTOBUF_FIELD_OFFSET(::proto::MessageData, _impl_.receiver_id_),
  PROTOBUF_FIELD_OFFSET(::proto::MessageData, _impl_.date_of_sending_),
  PROTOBUF_FIELD_OFFSET(::proto::MessageData, _impl_.time_of_sending_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::proto::MessageData)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::proto::_MessageData_default_instance_._instance,
};

const char descriptor_table_protodef_message_5fdata_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\022message_data.proto\022\005proto\"\215\001\n\013MessageD"
  "ata\022\017\n\007message\030\001 \001(\t\022\021\n\tsender_id\030\002 \001(\r\022"
  "\023\n\013sender_name\030\003 \001(\t\022\023\n\013receiver_id\030\004 \001("
  "\r\022\027\n\017date_of_sending\030\005 \001(\t\022\027\n\017time_of_se"
  "nding\030\006 \001(\tb\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_message_5fdata_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_message_5fdata_2eproto = {
    false, false, 179, descriptor_table_protodef_message_5fdata_2eproto,
    "message_data.proto",
    &descriptor_table_message_5fdata_2eproto_once, nullptr, 0, 1,
    schemas, file_default_instances, TableStruct_message_5fdata_2eproto::offsets,
    file_level_metadata_message_5fdata_2eproto, file_level_enum_descriptors_message_5fdata_2eproto,
    file_level_service_descriptors_message_5fdata_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_message_5fdata_2eproto_getter() {
  return &descriptor_table_message_5fdata_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_message_5fdata_2eproto(&descriptor_table_message_5fdata_2eproto);
namespace proto {

// ===================================================================

class MessageData::_Internal {
 public:
};

MessageData::MessageData(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:proto.MessageData)
}
MessageData::MessageData(const MessageData& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  MessageData* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.message_){}
    , decltype(_impl_.sender_name_){}
    , decltype(_impl_.date_of_sending_){}
    , decltype(_impl_.time_of_sending_){}
    , decltype(_impl_.sender_id_){}
    , decltype(_impl_.receiver_id_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.message_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.message_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_message().empty()) {
    _this->_impl_.message_.Set(from._internal_message(), 
      _this->GetArenaForAllocation());
  }
  _impl_.sender_name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.sender_name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_sender_name().empty()) {
    _this->_impl_.sender_name_.Set(from._internal_sender_name(), 
      _this->GetArenaForAllocation());
  }
  _impl_.date_of_sending_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.date_of_sending_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_date_of_sending().empty()) {
    _this->_impl_.date_of_sending_.Set(from._internal_date_of_sending(), 
      _this->GetArenaForAllocation());
  }
  _impl_.time_of_sending_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.time_of_sending_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_time_of_sending().empty()) {
    _this->_impl_.time_of_sending_.Set(from._internal_time_of_sending(), 
      _this->GetArenaForAllocation());
  }
  ::memcpy(&_impl_.sender_id_, &from._impl_.sender_id_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.receiver_id_) -
    reinterpret_cast<char*>(&_impl_.sender_id_)) + sizeof(_impl_.receiver_id_));
  // @@protoc_insertion_point(copy_constructor:proto.MessageData)
}

inline void MessageData::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.message_){}
    , decltype(_impl_.sender_name_){}
    , decltype(_impl_.date_of_sending_){}
    , decltype(_impl_.time_of_sending_){}
    , decltype(_impl_.sender_id_){0u}
    , decltype(_impl_.receiver_id_){0u}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.message_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.message_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.sender_name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.sender_name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.date_of_sending_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.date_of_sending_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.time_of_sending_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.time_of_sending_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

MessageData::~MessageData() {
  // @@protoc_insertion_point(destructor:proto.MessageData)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void MessageData::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.message_.Destroy();
  _impl_.sender_name_.Destroy();
  _impl_.date_of_sending_.Destroy();
  _impl_.time_of_sending_.Destroy();
}

void MessageData::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void MessageData::Clear() {
// @@protoc_insertion_point(message_clear_start:proto.MessageData)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.message_.ClearToEmpty();
  _impl_.sender_name_.ClearToEmpty();
  _impl_.date_of_sending_.ClearToEmpty();
  _impl_.time_of_sending_.ClearToEmpty();
  ::memset(&_impl_.sender_id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.receiver_id_) -
      reinterpret_cast<char*>(&_impl_.sender_id_)) + sizeof(_impl_.receiver_id_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* MessageData::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string message = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_message();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "proto.MessageData.message"));
        } else
          goto handle_unusual;
        continue;
      // uint32 sender_id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _impl_.sender_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string sender_name = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_sender_name();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "proto.MessageData.sender_name"));
        } else
          goto handle_unusual;
        continue;
      // uint32 receiver_id = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 32)) {
          _impl_.receiver_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string date_of_sending = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 42)) {
          auto str = _internal_mutable_date_of_sending();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "proto.MessageData.date_of_sending"));
        } else
          goto handle_unusual;
        continue;
      // string time_of_sending = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 50)) {
          auto str = _internal_mutable_time_of_sending();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "proto.MessageData.time_of_sending"));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* MessageData::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:proto.MessageData)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string message = 1;
  if (!this->_internal_message().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_message().data(), static_cast<int>(this->_internal_message().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "proto.MessageData.message");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_message(), target);
  }

  // uint32 sender_id = 2;
  if (this->_internal_sender_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(2, this->_internal_sender_id(), target);
  }

  // string sender_name = 3;
  if (!this->_internal_sender_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_sender_name().data(), static_cast<int>(this->_internal_sender_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "proto.MessageData.sender_name");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_sender_name(), target);
  }

  // uint32 receiver_id = 4;
  if (this->_internal_receiver_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(4, this->_internal_receiver_id(), target);
  }

  // string date_of_sending = 5;
  if (!this->_internal_date_of_sending().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_date_of_sending().data(), static_cast<int>(this->_internal_date_of_sending().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "proto.MessageData.date_of_sending");
    target = stream->WriteStringMaybeAliased(
        5, this->_internal_date_of_sending(), target);
  }

  // string time_of_sending = 6;
  if (!this->_internal_time_of_sending().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_time_of_sending().data(), static_cast<int>(this->_internal_time_of_sending().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "proto.MessageData.time_of_sending");
    target = stream->WriteStringMaybeAliased(
        6, this->_internal_time_of_sending(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:proto.MessageData)
  return target;
}

size_t MessageData::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:proto.MessageData)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string message = 1;
  if (!this->_internal_message().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_message());
  }

  // string sender_name = 3;
  if (!this->_internal_sender_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_sender_name());
  }

  // string date_of_sending = 5;
  if (!this->_internal_date_of_sending().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_date_of_sending());
  }

  // string time_of_sending = 6;
  if (!this->_internal_time_of_sending().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_time_of_sending());
  }

  // uint32 sender_id = 2;
  if (this->_internal_sender_id() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_sender_id());
  }

  // uint32 receiver_id = 4;
  if (this->_internal_receiver_id() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_receiver_id());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData MessageData::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    MessageData::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*MessageData::GetClassData() const { return &_class_data_; }


void MessageData::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<MessageData*>(&to_msg);
  auto& from = static_cast<const MessageData&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:proto.MessageData)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_message().empty()) {
    _this->_internal_set_message(from._internal_message());
  }
  if (!from._internal_sender_name().empty()) {
    _this->_internal_set_sender_name(from._internal_sender_name());
  }
  if (!from._internal_date_of_sending().empty()) {
    _this->_internal_set_date_of_sending(from._internal_date_of_sending());
  }
  if (!from._internal_time_of_sending().empty()) {
    _this->_internal_set_time_of_sending(from._internal_time_of_sending());
  }
  if (from._internal_sender_id() != 0) {
    _this->_internal_set_sender_id(from._internal_sender_id());
  }
  if (from._internal_receiver_id() != 0) {
    _this->_internal_set_receiver_id(from._internal_receiver_id());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void MessageData::CopyFrom(const MessageData& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:proto.MessageData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MessageData::IsInitialized() const {
  return true;
}

void MessageData::InternalSwap(MessageData* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.message_, lhs_arena,
      &other->_impl_.message_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.sender_name_, lhs_arena,
      &other->_impl_.sender_name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.date_of_sending_, lhs_arena,
      &other->_impl_.date_of_sending_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.time_of_sending_, lhs_arena,
      &other->_impl_.time_of_sending_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(MessageData, _impl_.receiver_id_)
      + sizeof(MessageData::_impl_.receiver_id_)
      - PROTOBUF_FIELD_OFFSET(MessageData, _impl_.sender_id_)>(
          reinterpret_cast<char*>(&_impl_.sender_id_),
          reinterpret_cast<char*>(&other->_impl_.sender_id_));
}

::PROTOBUF_NAMESPACE_ID::Metadata MessageData::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_message_5fdata_2eproto_getter, &descriptor_table_message_5fdata_2eproto_once,
      file_level_metadata_message_5fdata_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace proto
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::proto::MessageData*
Arena::CreateMaybeMessage< ::proto::MessageData >(Arena* arena) {
  return Arena::CreateMessageInternal< ::proto::MessageData >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>