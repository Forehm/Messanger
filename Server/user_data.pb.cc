// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: user_data.proto

#include "user_data.pb.h"

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
PROTOBUF_CONSTEXPR UserData::UserData(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.black_list_)*/{}
  , /*decltype(_impl_._black_list_cached_byte_size_)*/{0}
  , /*decltype(_impl_.friend_list_)*/{}
  , /*decltype(_impl_._friend_list_cached_byte_size_)*/{0}
  , /*decltype(_impl_.dialogs_with_)*/{}
  , /*decltype(_impl_._dialogs_with_cached_byte_size_)*/{0}
  , /*decltype(_impl_.login_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.name_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.password_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.id_)*/0u
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct UserDataDefaultTypeInternal {
  PROTOBUF_CONSTEXPR UserDataDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~UserDataDefaultTypeInternal() {}
  union {
    UserData _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 UserDataDefaultTypeInternal _UserData_default_instance_;
}  // namespace proto
static ::_pb::Metadata file_level_metadata_user_5fdata_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_user_5fdata_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_user_5fdata_2eproto = nullptr;

const uint32_t TableStruct_user_5fdata_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::proto::UserData, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::proto::UserData, _impl_.login_),
  PROTOBUF_FIELD_OFFSET(::proto::UserData, _impl_.name_),
  PROTOBUF_FIELD_OFFSET(::proto::UserData, _impl_.password_),
  PROTOBUF_FIELD_OFFSET(::proto::UserData, _impl_.id_),
  PROTOBUF_FIELD_OFFSET(::proto::UserData, _impl_.black_list_),
  PROTOBUF_FIELD_OFFSET(::proto::UserData, _impl_.friend_list_),
  PROTOBUF_FIELD_OFFSET(::proto::UserData, _impl_.dialogs_with_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::proto::UserData)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::proto::_UserData_default_instance_._instance,
};

const char descriptor_table_protodef_user_5fdata_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\017user_data.proto\022\005proto\"\204\001\n\010UserData\022\r\n"
  "\005login\030\001 \001(\t\022\014\n\004name\030\002 \001(\t\022\020\n\010password\030\003"
  " \001(\t\022\n\n\002id\030\004 \001(\r\022\022\n\nblack_list\030\005 \003(\r\022\023\n\013"
  "friend_list\030\006 \003(\r\022\024\n\014dialogs_with\030\007 \003(\rb"
  "\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_user_5fdata_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_user_5fdata_2eproto = {
    false, false, 167, descriptor_table_protodef_user_5fdata_2eproto,
    "user_data.proto",
    &descriptor_table_user_5fdata_2eproto_once, nullptr, 0, 1,
    schemas, file_default_instances, TableStruct_user_5fdata_2eproto::offsets,
    file_level_metadata_user_5fdata_2eproto, file_level_enum_descriptors_user_5fdata_2eproto,
    file_level_service_descriptors_user_5fdata_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_user_5fdata_2eproto_getter() {
  return &descriptor_table_user_5fdata_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_user_5fdata_2eproto(&descriptor_table_user_5fdata_2eproto);
namespace proto {

// ===================================================================

class UserData::_Internal {
 public:
};

UserData::UserData(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:proto.UserData)
}
UserData::UserData(const UserData& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  UserData* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.black_list_){from._impl_.black_list_}
    , /*decltype(_impl_._black_list_cached_byte_size_)*/{0}
    , decltype(_impl_.friend_list_){from._impl_.friend_list_}
    , /*decltype(_impl_._friend_list_cached_byte_size_)*/{0}
    , decltype(_impl_.dialogs_with_){from._impl_.dialogs_with_}
    , /*decltype(_impl_._dialogs_with_cached_byte_size_)*/{0}
    , decltype(_impl_.login_){}
    , decltype(_impl_.name_){}
    , decltype(_impl_.password_){}
    , decltype(_impl_.id_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.login_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.login_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_login().empty()) {
    _this->_impl_.login_.Set(from._internal_login(), 
      _this->GetArenaForAllocation());
  }
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_name().empty()) {
    _this->_impl_.name_.Set(from._internal_name(), 
      _this->GetArenaForAllocation());
  }
  _impl_.password_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.password_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_password().empty()) {
    _this->_impl_.password_.Set(from._internal_password(), 
      _this->GetArenaForAllocation());
  }
  _this->_impl_.id_ = from._impl_.id_;
  // @@protoc_insertion_point(copy_constructor:proto.UserData)
}

inline void UserData::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.black_list_){arena}
    , /*decltype(_impl_._black_list_cached_byte_size_)*/{0}
    , decltype(_impl_.friend_list_){arena}
    , /*decltype(_impl_._friend_list_cached_byte_size_)*/{0}
    , decltype(_impl_.dialogs_with_){arena}
    , /*decltype(_impl_._dialogs_with_cached_byte_size_)*/{0}
    , decltype(_impl_.login_){}
    , decltype(_impl_.name_){}
    , decltype(_impl_.password_){}
    , decltype(_impl_.id_){0u}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.login_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.login_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.password_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.password_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

UserData::~UserData() {
  // @@protoc_insertion_point(destructor:proto.UserData)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void UserData::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.black_list_.~RepeatedField();
  _impl_.friend_list_.~RepeatedField();
  _impl_.dialogs_with_.~RepeatedField();
  _impl_.login_.Destroy();
  _impl_.name_.Destroy();
  _impl_.password_.Destroy();
}

void UserData::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void UserData::Clear() {
// @@protoc_insertion_point(message_clear_start:proto.UserData)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.black_list_.Clear();
  _impl_.friend_list_.Clear();
  _impl_.dialogs_with_.Clear();
  _impl_.login_.ClearToEmpty();
  _impl_.name_.ClearToEmpty();
  _impl_.password_.ClearToEmpty();
  _impl_.id_ = 0u;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* UserData::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string login = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_login();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "proto.UserData.login"));
        } else
          goto handle_unusual;
        continue;
      // string name = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_name();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "proto.UserData.name"));
        } else
          goto handle_unusual;
        continue;
      // string password = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_password();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "proto.UserData.password"));
        } else
          goto handle_unusual;
        continue;
      // uint32 id = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 32)) {
          _impl_.id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated uint32 black_list = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 42)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedUInt32Parser(_internal_mutable_black_list(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 40) {
          _internal_add_black_list(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated uint32 friend_list = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 50)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedUInt32Parser(_internal_mutable_friend_list(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 48) {
          _internal_add_friend_list(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated uint32 dialogs_with = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 58)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedUInt32Parser(_internal_mutable_dialogs_with(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 56) {
          _internal_add_dialogs_with(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
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

uint8_t* UserData::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:proto.UserData)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string login = 1;
  if (!this->_internal_login().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_login().data(), static_cast<int>(this->_internal_login().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "proto.UserData.login");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_login(), target);
  }

  // string name = 2;
  if (!this->_internal_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "proto.UserData.name");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_name(), target);
  }

  // string password = 3;
  if (!this->_internal_password().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_password().data(), static_cast<int>(this->_internal_password().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "proto.UserData.password");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_password(), target);
  }

  // uint32 id = 4;
  if (this->_internal_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(4, this->_internal_id(), target);
  }

  // repeated uint32 black_list = 5;
  {
    int byte_size = _impl_._black_list_cached_byte_size_.load(std::memory_order_relaxed);
    if (byte_size > 0) {
      target = stream->WriteUInt32Packed(
          5, _internal_black_list(), byte_size, target);
    }
  }

  // repeated uint32 friend_list = 6;
  {
    int byte_size = _impl_._friend_list_cached_byte_size_.load(std::memory_order_relaxed);
    if (byte_size > 0) {
      target = stream->WriteUInt32Packed(
          6, _internal_friend_list(), byte_size, target);
    }
  }

  // repeated uint32 dialogs_with = 7;
  {
    int byte_size = _impl_._dialogs_with_cached_byte_size_.load(std::memory_order_relaxed);
    if (byte_size > 0) {
      target = stream->WriteUInt32Packed(
          7, _internal_dialogs_with(), byte_size, target);
    }
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:proto.UserData)
  return target;
}

size_t UserData::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:proto.UserData)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated uint32 black_list = 5;
  {
    size_t data_size = ::_pbi::WireFormatLite::
      UInt32Size(this->_impl_.black_list_);
    if (data_size > 0) {
      total_size += 1 +
        ::_pbi::WireFormatLite::Int32Size(static_cast<int32_t>(data_size));
    }
    int cached_size = ::_pbi::ToCachedSize(data_size);
    _impl_._black_list_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  // repeated uint32 friend_list = 6;
  {
    size_t data_size = ::_pbi::WireFormatLite::
      UInt32Size(this->_impl_.friend_list_);
    if (data_size > 0) {
      total_size += 1 +
        ::_pbi::WireFormatLite::Int32Size(static_cast<int32_t>(data_size));
    }
    int cached_size = ::_pbi::ToCachedSize(data_size);
    _impl_._friend_list_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  // repeated uint32 dialogs_with = 7;
  {
    size_t data_size = ::_pbi::WireFormatLite::
      UInt32Size(this->_impl_.dialogs_with_);
    if (data_size > 0) {
      total_size += 1 +
        ::_pbi::WireFormatLite::Int32Size(static_cast<int32_t>(data_size));
    }
    int cached_size = ::_pbi::ToCachedSize(data_size);
    _impl_._dialogs_with_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  // string login = 1;
  if (!this->_internal_login().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_login());
  }

  // string name = 2;
  if (!this->_internal_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // string password = 3;
  if (!this->_internal_password().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_password());
  }

  // uint32 id = 4;
  if (this->_internal_id() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_id());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData UserData::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    UserData::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*UserData::GetClassData() const { return &_class_data_; }


void UserData::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<UserData*>(&to_msg);
  auto& from = static_cast<const UserData&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:proto.UserData)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.black_list_.MergeFrom(from._impl_.black_list_);
  _this->_impl_.friend_list_.MergeFrom(from._impl_.friend_list_);
  _this->_impl_.dialogs_with_.MergeFrom(from._impl_.dialogs_with_);
  if (!from._internal_login().empty()) {
    _this->_internal_set_login(from._internal_login());
  }
  if (!from._internal_name().empty()) {
    _this->_internal_set_name(from._internal_name());
  }
  if (!from._internal_password().empty()) {
    _this->_internal_set_password(from._internal_password());
  }
  if (from._internal_id() != 0) {
    _this->_internal_set_id(from._internal_id());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void UserData::CopyFrom(const UserData& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:proto.UserData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UserData::IsInitialized() const {
  return true;
}

void UserData::InternalSwap(UserData* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.black_list_.InternalSwap(&other->_impl_.black_list_);
  _impl_.friend_list_.InternalSwap(&other->_impl_.friend_list_);
  _impl_.dialogs_with_.InternalSwap(&other->_impl_.dialogs_with_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.login_, lhs_arena,
      &other->_impl_.login_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.name_, lhs_arena,
      &other->_impl_.name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.password_, lhs_arena,
      &other->_impl_.password_, rhs_arena
  );
  swap(_impl_.id_, other->_impl_.id_);
}

::PROTOBUF_NAMESPACE_ID::Metadata UserData::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_user_5fdata_2eproto_getter, &descriptor_table_user_5fdata_2eproto_once,
      file_level_metadata_user_5fdata_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace proto
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::proto::UserData*
Arena::CreateMaybeMessage< ::proto::UserData >(Arena* arena) {
  return Arena::CreateMessageInternal< ::proto::UserData >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
