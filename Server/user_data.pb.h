// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: user_data.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_user_5fdata_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_user_5fdata_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_user_5fdata_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_user_5fdata_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_user_5fdata_2eproto;
namespace proto {
class UserData;
struct UserDataDefaultTypeInternal;
extern UserDataDefaultTypeInternal _UserData_default_instance_;
}  // namespace proto
PROTOBUF_NAMESPACE_OPEN
template<> ::proto::UserData* Arena::CreateMaybeMessage<::proto::UserData>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace proto {

// ===================================================================

class UserData final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:proto.UserData) */ {
 public:
  inline UserData() : UserData(nullptr) {}
  ~UserData() override;
  explicit PROTOBUF_CONSTEXPR UserData(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  UserData(const UserData& from);
  UserData(UserData&& from) noexcept
    : UserData() {
    *this = ::std::move(from);
  }

  inline UserData& operator=(const UserData& from) {
    CopyFrom(from);
    return *this;
  }
  inline UserData& operator=(UserData&& from) noexcept {
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
  static const UserData& default_instance() {
    return *internal_default_instance();
  }
  static inline const UserData* internal_default_instance() {
    return reinterpret_cast<const UserData*>(
               &_UserData_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(UserData& a, UserData& b) {
    a.Swap(&b);
  }
  inline void Swap(UserData* other) {
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
  void UnsafeArenaSwap(UserData* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  UserData* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<UserData>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const UserData& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const UserData& from) {
    UserData::MergeImpl(*this, from);
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
  void InternalSwap(UserData* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "proto.UserData";
  }
  protected:
  explicit UserData(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kBlackListFieldNumber = 5,
    kFriendListFieldNumber = 6,
    kDialogsWithFieldNumber = 7,
    kLoginFieldNumber = 1,
    kNameFieldNumber = 2,
    kPasswordFieldNumber = 3,
    kIdFieldNumber = 4,
  };
  // repeated uint32 black_list = 5;
  int black_list_size() const;
  private:
  int _internal_black_list_size() const;
  public:
  void clear_black_list();
  private:
  uint32_t _internal_black_list(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >&
      _internal_black_list() const;
  void _internal_add_black_list(uint32_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >*
      _internal_mutable_black_list();
  public:
  uint32_t black_list(int index) const;
  void set_black_list(int index, uint32_t value);
  void add_black_list(uint32_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >&
      black_list() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >*
      mutable_black_list();

  // repeated uint32 friend_list = 6;
  int friend_list_size() const;
  private:
  int _internal_friend_list_size() const;
  public:
  void clear_friend_list();
  private:
  uint32_t _internal_friend_list(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >&
      _internal_friend_list() const;
  void _internal_add_friend_list(uint32_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >*
      _internal_mutable_friend_list();
  public:
  uint32_t friend_list(int index) const;
  void set_friend_list(int index, uint32_t value);
  void add_friend_list(uint32_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >&
      friend_list() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >*
      mutable_friend_list();

  // repeated uint32 dialogs_with = 7;
  int dialogs_with_size() const;
  private:
  int _internal_dialogs_with_size() const;
  public:
  void clear_dialogs_with();
  private:
  uint32_t _internal_dialogs_with(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >&
      _internal_dialogs_with() const;
  void _internal_add_dialogs_with(uint32_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >*
      _internal_mutable_dialogs_with();
  public:
  uint32_t dialogs_with(int index) const;
  void set_dialogs_with(int index, uint32_t value);
  void add_dialogs_with(uint32_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >&
      dialogs_with() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >*
      mutable_dialogs_with();

  // string login = 1;
  void clear_login();
  const std::string& login() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_login(ArgT0&& arg0, ArgT... args);
  std::string* mutable_login();
  PROTOBUF_NODISCARD std::string* release_login();
  void set_allocated_login(std::string* login);
  private:
  const std::string& _internal_login() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_login(const std::string& value);
  std::string* _internal_mutable_login();
  public:

  // string name = 2;
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // string password = 3;
  void clear_password();
  const std::string& password() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_password(ArgT0&& arg0, ArgT... args);
  std::string* mutable_password();
  PROTOBUF_NODISCARD std::string* release_password();
  void set_allocated_password(std::string* password);
  private:
  const std::string& _internal_password() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_password(const std::string& value);
  std::string* _internal_mutable_password();
  public:

  // uint32 id = 4;
  void clear_id();
  uint32_t id() const;
  void set_id(uint32_t value);
  private:
  uint32_t _internal_id() const;
  void _internal_set_id(uint32_t value);
  public:

  // @@protoc_insertion_point(class_scope:proto.UserData)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t > black_list_;
    mutable std::atomic<int> _black_list_cached_byte_size_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t > friend_list_;
    mutable std::atomic<int> _friend_list_cached_byte_size_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t > dialogs_with_;
    mutable std::atomic<int> _dialogs_with_cached_byte_size_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr login_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr password_;
    uint32_t id_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_user_5fdata_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// UserData

// string login = 1;
inline void UserData::clear_login() {
  _impl_.login_.ClearToEmpty();
}
inline const std::string& UserData::login() const {
  // @@protoc_insertion_point(field_get:proto.UserData.login)
  return _internal_login();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void UserData::set_login(ArgT0&& arg0, ArgT... args) {
 
 _impl_.login_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:proto.UserData.login)
}
inline std::string* UserData::mutable_login() {
  std::string* _s = _internal_mutable_login();
  // @@protoc_insertion_point(field_mutable:proto.UserData.login)
  return _s;
}
inline const std::string& UserData::_internal_login() const {
  return _impl_.login_.Get();
}
inline void UserData::_internal_set_login(const std::string& value) {
  
  _impl_.login_.Set(value, GetArenaForAllocation());
}
inline std::string* UserData::_internal_mutable_login() {
  
  return _impl_.login_.Mutable(GetArenaForAllocation());
}
inline std::string* UserData::release_login() {
  // @@protoc_insertion_point(field_release:proto.UserData.login)
  return _impl_.login_.Release();
}
inline void UserData::set_allocated_login(std::string* login) {
  if (login != nullptr) {
    
  } else {
    
  }
  _impl_.login_.SetAllocated(login, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.login_.IsDefault()) {
    _impl_.login_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:proto.UserData.login)
}

// string name = 2;
inline void UserData::clear_name() {
  _impl_.name_.ClearToEmpty();
}
inline const std::string& UserData::name() const {
  // @@protoc_insertion_point(field_get:proto.UserData.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void UserData::set_name(ArgT0&& arg0, ArgT... args) {
 
 _impl_.name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:proto.UserData.name)
}
inline std::string* UserData::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:proto.UserData.name)
  return _s;
}
inline const std::string& UserData::_internal_name() const {
  return _impl_.name_.Get();
}
inline void UserData::_internal_set_name(const std::string& value) {
  
  _impl_.name_.Set(value, GetArenaForAllocation());
}
inline std::string* UserData::_internal_mutable_name() {
  
  return _impl_.name_.Mutable(GetArenaForAllocation());
}
inline std::string* UserData::release_name() {
  // @@protoc_insertion_point(field_release:proto.UserData.name)
  return _impl_.name_.Release();
}
inline void UserData::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  _impl_.name_.SetAllocated(name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.name_.IsDefault()) {
    _impl_.name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:proto.UserData.name)
}

// string password = 3;
inline void UserData::clear_password() {
  _impl_.password_.ClearToEmpty();
}
inline const std::string& UserData::password() const {
  // @@protoc_insertion_point(field_get:proto.UserData.password)
  return _internal_password();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void UserData::set_password(ArgT0&& arg0, ArgT... args) {
 
 _impl_.password_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:proto.UserData.password)
}
inline std::string* UserData::mutable_password() {
  std::string* _s = _internal_mutable_password();
  // @@protoc_insertion_point(field_mutable:proto.UserData.password)
  return _s;
}
inline const std::string& UserData::_internal_password() const {
  return _impl_.password_.Get();
}
inline void UserData::_internal_set_password(const std::string& value) {
  
  _impl_.password_.Set(value, GetArenaForAllocation());
}
inline std::string* UserData::_internal_mutable_password() {
  
  return _impl_.password_.Mutable(GetArenaForAllocation());
}
inline std::string* UserData::release_password() {
  // @@protoc_insertion_point(field_release:proto.UserData.password)
  return _impl_.password_.Release();
}
inline void UserData::set_allocated_password(std::string* password) {
  if (password != nullptr) {
    
  } else {
    
  }
  _impl_.password_.SetAllocated(password, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.password_.IsDefault()) {
    _impl_.password_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:proto.UserData.password)
}

// uint32 id = 4;
inline void UserData::clear_id() {
  _impl_.id_ = 0u;
}
inline uint32_t UserData::_internal_id() const {
  return _impl_.id_;
}
inline uint32_t UserData::id() const {
  // @@protoc_insertion_point(field_get:proto.UserData.id)
  return _internal_id();
}
inline void UserData::_internal_set_id(uint32_t value) {
  
  _impl_.id_ = value;
}
inline void UserData::set_id(uint32_t value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:proto.UserData.id)
}

// repeated uint32 black_list = 5;
inline int UserData::_internal_black_list_size() const {
  return _impl_.black_list_.size();
}
inline int UserData::black_list_size() const {
  return _internal_black_list_size();
}
inline void UserData::clear_black_list() {
  _impl_.black_list_.Clear();
}
inline uint32_t UserData::_internal_black_list(int index) const {
  return _impl_.black_list_.Get(index);
}
inline uint32_t UserData::black_list(int index) const {
  // @@protoc_insertion_point(field_get:proto.UserData.black_list)
  return _internal_black_list(index);
}
inline void UserData::set_black_list(int index, uint32_t value) {
  _impl_.black_list_.Set(index, value);
  // @@protoc_insertion_point(field_set:proto.UserData.black_list)
}
inline void UserData::_internal_add_black_list(uint32_t value) {
  _impl_.black_list_.Add(value);
}
inline void UserData::add_black_list(uint32_t value) {
  _internal_add_black_list(value);
  // @@protoc_insertion_point(field_add:proto.UserData.black_list)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >&
UserData::_internal_black_list() const {
  return _impl_.black_list_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >&
UserData::black_list() const {
  // @@protoc_insertion_point(field_list:proto.UserData.black_list)
  return _internal_black_list();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >*
UserData::_internal_mutable_black_list() {
  return &_impl_.black_list_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >*
UserData::mutable_black_list() {
  // @@protoc_insertion_point(field_mutable_list:proto.UserData.black_list)
  return _internal_mutable_black_list();
}

// repeated uint32 friend_list = 6;
inline int UserData::_internal_friend_list_size() const {
  return _impl_.friend_list_.size();
}
inline int UserData::friend_list_size() const {
  return _internal_friend_list_size();
}
inline void UserData::clear_friend_list() {
  _impl_.friend_list_.Clear();
}
inline uint32_t UserData::_internal_friend_list(int index) const {
  return _impl_.friend_list_.Get(index);
}
inline uint32_t UserData::friend_list(int index) const {
  // @@protoc_insertion_point(field_get:proto.UserData.friend_list)
  return _internal_friend_list(index);
}
inline void UserData::set_friend_list(int index, uint32_t value) {
  _impl_.friend_list_.Set(index, value);
  // @@protoc_insertion_point(field_set:proto.UserData.friend_list)
}
inline void UserData::_internal_add_friend_list(uint32_t value) {
  _impl_.friend_list_.Add(value);
}
inline void UserData::add_friend_list(uint32_t value) {
  _internal_add_friend_list(value);
  // @@protoc_insertion_point(field_add:proto.UserData.friend_list)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >&
UserData::_internal_friend_list() const {
  return _impl_.friend_list_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >&
UserData::friend_list() const {
  // @@protoc_insertion_point(field_list:proto.UserData.friend_list)
  return _internal_friend_list();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >*
UserData::_internal_mutable_friend_list() {
  return &_impl_.friend_list_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >*
UserData::mutable_friend_list() {
  // @@protoc_insertion_point(field_mutable_list:proto.UserData.friend_list)
  return _internal_mutable_friend_list();
}

// repeated uint32 dialogs_with = 7;
inline int UserData::_internal_dialogs_with_size() const {
  return _impl_.dialogs_with_.size();
}
inline int UserData::dialogs_with_size() const {
  return _internal_dialogs_with_size();
}
inline void UserData::clear_dialogs_with() {
  _impl_.dialogs_with_.Clear();
}
inline uint32_t UserData::_internal_dialogs_with(int index) const {
  return _impl_.dialogs_with_.Get(index);
}
inline uint32_t UserData::dialogs_with(int index) const {
  // @@protoc_insertion_point(field_get:proto.UserData.dialogs_with)
  return _internal_dialogs_with(index);
}
inline void UserData::set_dialogs_with(int index, uint32_t value) {
  _impl_.dialogs_with_.Set(index, value);
  // @@protoc_insertion_point(field_set:proto.UserData.dialogs_with)
}
inline void UserData::_internal_add_dialogs_with(uint32_t value) {
  _impl_.dialogs_with_.Add(value);
}
inline void UserData::add_dialogs_with(uint32_t value) {
  _internal_add_dialogs_with(value);
  // @@protoc_insertion_point(field_add:proto.UserData.dialogs_with)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >&
UserData::_internal_dialogs_with() const {
  return _impl_.dialogs_with_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >&
UserData::dialogs_with() const {
  // @@protoc_insertion_point(field_list:proto.UserData.dialogs_with)
  return _internal_dialogs_with();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >*
UserData::_internal_mutable_dialogs_with() {
  return &_impl_.dialogs_with_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >*
UserData::mutable_dialogs_with() {
  // @@protoc_insertion_point(field_mutable_list:proto.UserData.dialogs_with)
  return _internal_mutable_dialogs_with();
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_user_5fdata_2eproto
