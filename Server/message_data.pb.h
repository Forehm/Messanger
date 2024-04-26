// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message_data.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_message_5fdata_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_message_5fdata_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_message_5fdata_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_message_5fdata_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_message_5fdata_2eproto;
namespace proto {
class MessageData;
struct MessageDataDefaultTypeInternal;
extern MessageDataDefaultTypeInternal _MessageData_default_instance_;
}  // namespace proto
PROTOBUF_NAMESPACE_OPEN
template<> ::proto::MessageData* Arena::CreateMaybeMessage<::proto::MessageData>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace proto {

// ===================================================================

class MessageData final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:proto.MessageData) */ {
 public:
  inline MessageData() : MessageData(nullptr) {}
  ~MessageData() override;
  explicit PROTOBUF_CONSTEXPR MessageData(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  MessageData(const MessageData& from);
  MessageData(MessageData&& from) noexcept
    : MessageData() {
    *this = ::std::move(from);
  }

  inline MessageData& operator=(const MessageData& from) {
    CopyFrom(from);
    return *this;
  }
  inline MessageData& operator=(MessageData&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const MessageData& default_instance() {
    return *internal_default_instance();
  }
  static inline const MessageData* internal_default_instance() {
    return reinterpret_cast<const MessageData*>(
               &_MessageData_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(MessageData& a, MessageData& b) {
    a.Swap(&b);
  }
  inline void Swap(MessageData* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(MessageData* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  MessageData* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<MessageData>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const MessageData& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const MessageData& from) {
    MessageData::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(MessageData* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "proto.MessageData";
  }
  protected:
  explicit MessageData(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMessageFieldNumber = 1,
    kSenderNameFieldNumber = 3,
    kDateOfSendingFieldNumber = 5,
    kTimeOfSendingFieldNumber = 6,
    kSenderIdFieldNumber = 2,
    kReceiverIdFieldNumber = 4,
  };
  // string message = 1;
  void clear_message();
  const std::string& message() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_message(ArgT0&& arg0, ArgT... args);
  std::string* mutable_message();
  PROTOBUF_NODISCARD std::string* release_message();
  void set_allocated_message(std::string* message);
  private:
  const std::string& _internal_message() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_message(const std::string& value);
  std::string* _internal_mutable_message();
  public:

  // string sender_name = 3;
  void clear_sender_name();
  const std::string& sender_name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_sender_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_sender_name();
  PROTOBUF_NODISCARD std::string* release_sender_name();
  void set_allocated_sender_name(std::string* sender_name);
  private:
  const std::string& _internal_sender_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_sender_name(const std::string& value);
  std::string* _internal_mutable_sender_name();
  public:

  // string date_of_sending = 5;
  void clear_date_of_sending();
  const std::string& date_of_sending() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_date_of_sending(ArgT0&& arg0, ArgT... args);
  std::string* mutable_date_of_sending();
  PROTOBUF_NODISCARD std::string* release_date_of_sending();
  void set_allocated_date_of_sending(std::string* date_of_sending);
  private:
  const std::string& _internal_date_of_sending() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_date_of_sending(const std::string& value);
  std::string* _internal_mutable_date_of_sending();
  public:

  // string time_of_sending = 6;
  void clear_time_of_sending();
  const std::string& time_of_sending() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_time_of_sending(ArgT0&& arg0, ArgT... args);
  std::string* mutable_time_of_sending();
  PROTOBUF_NODISCARD std::string* release_time_of_sending();
  void set_allocated_time_of_sending(std::string* time_of_sending);
  private:
  const std::string& _internal_time_of_sending() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_time_of_sending(const std::string& value);
  std::string* _internal_mutable_time_of_sending();
  public:

  // uint32 sender_id = 2;
  void clear_sender_id();
  uint32_t sender_id() const;
  void set_sender_id(uint32_t value);
  private:
  uint32_t _internal_sender_id() const;
  void _internal_set_sender_id(uint32_t value);
  public:

  // uint32 receiver_id = 4;
  void clear_receiver_id();
  uint32_t receiver_id() const;
  void set_receiver_id(uint32_t value);
  private:
  uint32_t _internal_receiver_id() const;
  void _internal_set_receiver_id(uint32_t value);
  public:

  // @@protoc_insertion_point(class_scope:proto.MessageData)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr message_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr sender_name_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr date_of_sending_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr time_of_sending_;
    uint32_t sender_id_;
    uint32_t receiver_id_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_message_5fdata_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// MessageData

// string message = 1;
inline void MessageData::clear_message() {
  _impl_.message_.ClearToEmpty();
}
inline const std::string& MessageData::message() const {
  // @@protoc_insertion_point(field_get:proto.MessageData.message)
  return _internal_message();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void MessageData::set_message(ArgT0&& arg0, ArgT... args) {
 
 _impl_.message_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:proto.MessageData.message)
}
inline std::string* MessageData::mutable_message() {
  std::string* _s = _internal_mutable_message();
  // @@protoc_insertion_point(field_mutable:proto.MessageData.message)
  return _s;
}
inline const std::string& MessageData::_internal_message() const {
  return _impl_.message_.Get();
}
inline void MessageData::_internal_set_message(const std::string& value) {
  
  _impl_.message_.Set(value, GetArenaForAllocation());
}
inline std::string* MessageData::_internal_mutable_message() {
  
  return _impl_.message_.Mutable(GetArenaForAllocation());
}
inline std::string* MessageData::release_message() {
  // @@protoc_insertion_point(field_release:proto.MessageData.message)
  return _impl_.message_.Release();
}
inline void MessageData::set_allocated_message(std::string* message) {
  if (message != nullptr) {
    
  } else {
    
  }
  _impl_.message_.SetAllocated(message, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.message_.IsDefault()) {
    _impl_.message_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:proto.MessageData.message)
}

// uint32 sender_id = 2;
inline void MessageData::clear_sender_id() {
  _impl_.sender_id_ = 0u;
}
inline uint32_t MessageData::_internal_sender_id() const {
  return _impl_.sender_id_;
}
inline uint32_t MessageData::sender_id() const {
  // @@protoc_insertion_point(field_get:proto.MessageData.sender_id)
  return _internal_sender_id();
}
inline void MessageData::_internal_set_sender_id(uint32_t value) {
  
  _impl_.sender_id_ = value;
}
inline void MessageData::set_sender_id(uint32_t value) {
  _internal_set_sender_id(value);
  // @@protoc_insertion_point(field_set:proto.MessageData.sender_id)
}

// string sender_name = 3;
inline void MessageData::clear_sender_name() {
  _impl_.sender_name_.ClearToEmpty();
}
inline const std::string& MessageData::sender_name() const {
  // @@protoc_insertion_point(field_get:proto.MessageData.sender_name)
  return _internal_sender_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void MessageData::set_sender_name(ArgT0&& arg0, ArgT... args) {
 
 _impl_.sender_name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:proto.MessageData.sender_name)
}
inline std::string* MessageData::mutable_sender_name() {
  std::string* _s = _internal_mutable_sender_name();
  // @@protoc_insertion_point(field_mutable:proto.MessageData.sender_name)
  return _s;
}
inline const std::string& MessageData::_internal_sender_name() const {
  return _impl_.sender_name_.Get();
}
inline void MessageData::_internal_set_sender_name(const std::string& value) {
  
  _impl_.sender_name_.Set(value, GetArenaForAllocation());
}
inline std::string* MessageData::_internal_mutable_sender_name() {
  
  return _impl_.sender_name_.Mutable(GetArenaForAllocation());
}
inline std::string* MessageData::release_sender_name() {
  // @@protoc_insertion_point(field_release:proto.MessageData.sender_name)
  return _impl_.sender_name_.Release();
}
inline void MessageData::set_allocated_sender_name(std::string* sender_name) {
  if (sender_name != nullptr) {
    
  } else {
    
  }
  _impl_.sender_name_.SetAllocated(sender_name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.sender_name_.IsDefault()) {
    _impl_.sender_name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:proto.MessageData.sender_name)
}

// uint32 receiver_id = 4;
inline void MessageData::clear_receiver_id() {
  _impl_.receiver_id_ = 0u;
}
inline uint32_t MessageData::_internal_receiver_id() const {
  return _impl_.receiver_id_;
}
inline uint32_t MessageData::receiver_id() const {
  // @@protoc_insertion_point(field_get:proto.MessageData.receiver_id)
  return _internal_receiver_id();
}
inline void MessageData::_internal_set_receiver_id(uint32_t value) {
  
  _impl_.receiver_id_ = value;
}
inline void MessageData::set_receiver_id(uint32_t value) {
  _internal_set_receiver_id(value);
  // @@protoc_insertion_point(field_set:proto.MessageData.receiver_id)
}

// string date_of_sending = 5;
inline void MessageData::clear_date_of_sending() {
  _impl_.date_of_sending_.ClearToEmpty();
}
inline const std::string& MessageData::date_of_sending() const {
  // @@protoc_insertion_point(field_get:proto.MessageData.date_of_sending)
  return _internal_date_of_sending();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void MessageData::set_date_of_sending(ArgT0&& arg0, ArgT... args) {
 
 _impl_.date_of_sending_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:proto.MessageData.date_of_sending)
}
inline std::string* MessageData::mutable_date_of_sending() {
  std::string* _s = _internal_mutable_date_of_sending();
  // @@protoc_insertion_point(field_mutable:proto.MessageData.date_of_sending)
  return _s;
}
inline const std::string& MessageData::_internal_date_of_sending() const {
  return _impl_.date_of_sending_.Get();
}
inline void MessageData::_internal_set_date_of_sending(const std::string& value) {
  
  _impl_.date_of_sending_.Set(value, GetArenaForAllocation());
}
inline std::string* MessageData::_internal_mutable_date_of_sending() {
  
  return _impl_.date_of_sending_.Mutable(GetArenaForAllocation());
}
inline std::string* MessageData::release_date_of_sending() {
  // @@protoc_insertion_point(field_release:proto.MessageData.date_of_sending)
  return _impl_.date_of_sending_.Release();
}
inline void MessageData::set_allocated_date_of_sending(std::string* date_of_sending) {
  if (date_of_sending != nullptr) {
    
  } else {
    
  }
  _impl_.date_of_sending_.SetAllocated(date_of_sending, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.date_of_sending_.IsDefault()) {
    _impl_.date_of_sending_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:proto.MessageData.date_of_sending)
}

// string time_of_sending = 6;
inline void MessageData::clear_time_of_sending() {
  _impl_.time_of_sending_.ClearToEmpty();
}
inline const std::string& MessageData::time_of_sending() const {
  // @@protoc_insertion_point(field_get:proto.MessageData.time_of_sending)
  return _internal_time_of_sending();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void MessageData::set_time_of_sending(ArgT0&& arg0, ArgT... args) {
 
 _impl_.time_of_sending_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:proto.MessageData.time_of_sending)
}
inline std::string* MessageData::mutable_time_of_sending() {
  std::string* _s = _internal_mutable_time_of_sending();
  // @@protoc_insertion_point(field_mutable:proto.MessageData.time_of_sending)
  return _s;
}
inline const std::string& MessageData::_internal_time_of_sending() const {
  return _impl_.time_of_sending_.Get();
}
inline void MessageData::_internal_set_time_of_sending(const std::string& value) {
  
  _impl_.time_of_sending_.Set(value, GetArenaForAllocation());
}
inline std::string* MessageData::_internal_mutable_time_of_sending() {
  
  return _impl_.time_of_sending_.Mutable(GetArenaForAllocation());
}
inline std::string* MessageData::release_time_of_sending() {
  // @@protoc_insertion_point(field_release:proto.MessageData.time_of_sending)
  return _impl_.time_of_sending_.Release();
}
inline void MessageData::set_allocated_time_of_sending(std::string* time_of_sending) {
  if (time_of_sending != nullptr) {
    
  } else {
    
  }
  _impl_.time_of_sending_.SetAllocated(time_of_sending, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.time_of_sending_.IsDefault()) {
    _impl_.time_of_sending_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:proto.MessageData.time_of_sending)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_message_5fdata_2eproto