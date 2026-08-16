#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "antidrone_turret__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__antidrone_turret__msg__Target() -> *const std::ffi::c_void;
}

#[link(name = "antidrone_turret__rosidl_generator_c")]
extern "C" {
    fn antidrone_turret__msg__Target__init(msg: *mut Target) -> bool;
    fn antidrone_turret__msg__Target__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Target>, size: usize) -> bool;
    fn antidrone_turret__msg__Target__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Target>);
    fn antidrone_turret__msg__Target__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Target>, out_seq: *mut rosidl_runtime_rs::Sequence<Target>) -> bool;
}

// Corresponds to antidrone_turret__msg__Target
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Target {

    // This member is not documented.
    #[allow(missing_docs)]
    pub visible: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub distance_m: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f32,

}



impl Default for Target {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !antidrone_turret__msg__Target__init(&mut msg as *mut _) {
        panic!("Call to antidrone_turret__msg__Target__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Target {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { antidrone_turret__msg__Target__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { antidrone_turret__msg__Target__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { antidrone_turret__msg__Target__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Target {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Target where Self: Sized {
  const TYPE_NAME: &'static str = "antidrone_turret/msg/Target";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__antidrone_turret__msg__Target() }
  }
}


#[link(name = "antidrone_turret__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__antidrone_turret__msg__ActuatorStatus() -> *const std::ffi::c_void;
}

#[link(name = "antidrone_turret__rosidl_generator_c")]
extern "C" {
    fn antidrone_turret__msg__ActuatorStatus__init(msg: *mut ActuatorStatus) -> bool;
    fn antidrone_turret__msg__ActuatorStatus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ActuatorStatus>, size: usize) -> bool;
    fn antidrone_turret__msg__ActuatorStatus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ActuatorStatus>);
    fn antidrone_turret__msg__ActuatorStatus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ActuatorStatus>, out_seq: *mut rosidl_runtime_rs::Sequence<ActuatorStatus>) -> bool;
}

// Corresponds to antidrone_turret__msg__ActuatorStatus
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ActuatorStatus {

    // This member is not documented.
    #[allow(missing_docs)]
    pub state: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub trigger_count: u32,

}

impl ActuatorStatus {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const READY: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RELOADING: u8 = 1;

}


impl Default for ActuatorStatus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !antidrone_turret__msg__ActuatorStatus__init(&mut msg as *mut _) {
        panic!("Call to antidrone_turret__msg__ActuatorStatus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ActuatorStatus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { antidrone_turret__msg__ActuatorStatus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { antidrone_turret__msg__ActuatorStatus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { antidrone_turret__msg__ActuatorStatus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ActuatorStatus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ActuatorStatus where Self: Sized {
  const TYPE_NAME: &'static str = "antidrone_turret/msg/ActuatorStatus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__antidrone_turret__msg__ActuatorStatus() }
  }
}


#[link(name = "antidrone_turret__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__antidrone_turret__msg__ServoCommand() -> *const std::ffi::c_void;
}

#[link(name = "antidrone_turret__rosidl_generator_c")]
extern "C" {
    fn antidrone_turret__msg__ServoCommand__init(msg: *mut ServoCommand) -> bool;
    fn antidrone_turret__msg__ServoCommand__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ServoCommand>, size: usize) -> bool;
    fn antidrone_turret__msg__ServoCommand__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ServoCommand>);
    fn antidrone_turret__msg__ServoCommand__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ServoCommand>, out_seq: *mut rosidl_runtime_rs::Sequence<ServoCommand>) -> bool;
}

// Corresponds to antidrone_turret__msg__ServoCommand
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ServoCommand {

    // This member is not documented.
    #[allow(missing_docs)]
    pub direction: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub target_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error_x: f32,

}

impl ServoCommand {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const LEFT: i8 = -1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CENTER: i8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RIGHT: i8 = 1;

}


impl Default for ServoCommand {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !antidrone_turret__msg__ServoCommand__init(&mut msg as *mut _) {
        panic!("Call to antidrone_turret__msg__ServoCommand__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ServoCommand {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { antidrone_turret__msg__ServoCommand__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { antidrone_turret__msg__ServoCommand__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { antidrone_turret__msg__ServoCommand__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ServoCommand {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ServoCommand where Self: Sized {
  const TYPE_NAME: &'static str = "antidrone_turret/msg/ServoCommand";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__antidrone_turret__msg__ServoCommand() }
  }
}


#[link(name = "antidrone_turret__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__antidrone_turret__msg__GimbalCommand() -> *const std::ffi::c_void;
}

#[link(name = "antidrone_turret__rosidl_generator_c")]
extern "C" {
    fn antidrone_turret__msg__GimbalCommand__init(msg: *mut GimbalCommand) -> bool;
    fn antidrone_turret__msg__GimbalCommand__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GimbalCommand>, size: usize) -> bool;
    fn antidrone_turret__msg__GimbalCommand__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GimbalCommand>);
    fn antidrone_turret__msg__GimbalCommand__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GimbalCommand>, out_seq: *mut rosidl_runtime_rs::Sequence<GimbalCommand>) -> bool;
}

// Corresponds to antidrone_turret__msg__GimbalCommand
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GimbalCommand {

    // This member is not documented.
    #[allow(missing_docs)]
    pub direction: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub target_y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error_y: f32,

}

impl GimbalCommand {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const DOWN: i8 = -1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CENTER: i8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const UP: i8 = 1;

}


impl Default for GimbalCommand {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !antidrone_turret__msg__GimbalCommand__init(&mut msg as *mut _) {
        panic!("Call to antidrone_turret__msg__GimbalCommand__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GimbalCommand {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { antidrone_turret__msg__GimbalCommand__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { antidrone_turret__msg__GimbalCommand__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { antidrone_turret__msg__GimbalCommand__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GimbalCommand {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GimbalCommand where Self: Sized {
  const TYPE_NAME: &'static str = "antidrone_turret/msg/GimbalCommand";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__antidrone_turret__msg__GimbalCommand() }
  }
}


#[link(name = "antidrone_turret__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__antidrone_turret__msg__TurretStatus() -> *const std::ffi::c_void;
}

#[link(name = "antidrone_turret__rosidl_generator_c")]
extern "C" {
    fn antidrone_turret__msg__TurretStatus__init(msg: *mut TurretStatus) -> bool;
    fn antidrone_turret__msg__TurretStatus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TurretStatus>, size: usize) -> bool;
    fn antidrone_turret__msg__TurretStatus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TurretStatus>);
    fn antidrone_turret__msg__TurretStatus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TurretStatus>, out_seq: *mut rosidl_runtime_rs::Sequence<TurretStatus>) -> bool;
}

// Corresponds to antidrone_turret__msg__TurretStatus
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TurretStatus {

    // This member is not documented.
    #[allow(missing_docs)]
    pub target_state: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub action: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub trigger_state: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub distance_m: f32,

}

impl TurretStatus {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TARGET_NONE: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TARGET_LOW_CONFIDENCE: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TARGET_LOCKED: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ACTION_IDLE: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ACTION_TRACK: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRIGGER_SKIP: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRIGGER_REQUESTED: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TRIGGER_RELOADING: u8 = 2;

}


impl Default for TurretStatus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !antidrone_turret__msg__TurretStatus__init(&mut msg as *mut _) {
        panic!("Call to antidrone_turret__msg__TurretStatus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TurretStatus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { antidrone_turret__msg__TurretStatus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { antidrone_turret__msg__TurretStatus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { antidrone_turret__msg__TurretStatus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TurretStatus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TurretStatus where Self: Sized {
  const TYPE_NAME: &'static str = "antidrone_turret/msg/TurretStatus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__antidrone_turret__msg__TurretStatus() }
  }
}


