#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "antidrone_turret__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__antidrone_turret__srv__TriggerActuator_Request() -> *const std::ffi::c_void;
}

#[link(name = "antidrone_turret__rosidl_generator_c")]
extern "C" {
    fn antidrone_turret__srv__TriggerActuator_Request__init(msg: *mut TriggerActuator_Request) -> bool;
    fn antidrone_turret__srv__TriggerActuator_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TriggerActuator_Request>, size: usize) -> bool;
    fn antidrone_turret__srv__TriggerActuator_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TriggerActuator_Request>);
    fn antidrone_turret__srv__TriggerActuator_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TriggerActuator_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<TriggerActuator_Request>) -> bool;
}

// Corresponds to antidrone_turret__srv__TriggerActuator_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TriggerActuator_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub distance_m: f32,

}



impl Default for TriggerActuator_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !antidrone_turret__srv__TriggerActuator_Request__init(&mut msg as *mut _) {
        panic!("Call to antidrone_turret__srv__TriggerActuator_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TriggerActuator_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { antidrone_turret__srv__TriggerActuator_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { antidrone_turret__srv__TriggerActuator_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { antidrone_turret__srv__TriggerActuator_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TriggerActuator_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TriggerActuator_Request where Self: Sized {
  const TYPE_NAME: &'static str = "antidrone_turret/srv/TriggerActuator_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__antidrone_turret__srv__TriggerActuator_Request() }
  }
}


#[link(name = "antidrone_turret__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__antidrone_turret__srv__TriggerActuator_Response() -> *const std::ffi::c_void;
}

#[link(name = "antidrone_turret__rosidl_generator_c")]
extern "C" {
    fn antidrone_turret__srv__TriggerActuator_Response__init(msg: *mut TriggerActuator_Response) -> bool;
    fn antidrone_turret__srv__TriggerActuator_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TriggerActuator_Response>, size: usize) -> bool;
    fn antidrone_turret__srv__TriggerActuator_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TriggerActuator_Response>);
    fn antidrone_turret__srv__TriggerActuator_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TriggerActuator_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<TriggerActuator_Response>) -> bool;
}

// Corresponds to antidrone_turret__srv__TriggerActuator_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TriggerActuator_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub trigger_count: u32,

}



impl Default for TriggerActuator_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !antidrone_turret__srv__TriggerActuator_Response__init(&mut msg as *mut _) {
        panic!("Call to antidrone_turret__srv__TriggerActuator_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TriggerActuator_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { antidrone_turret__srv__TriggerActuator_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { antidrone_turret__srv__TriggerActuator_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { antidrone_turret__srv__TriggerActuator_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TriggerActuator_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TriggerActuator_Response where Self: Sized {
  const TYPE_NAME: &'static str = "antidrone_turret/srv/TriggerActuator_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__antidrone_turret__srv__TriggerActuator_Response() }
  }
}






#[link(name = "antidrone_turret__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__antidrone_turret__srv__TriggerActuator() -> *const std::ffi::c_void;
}

// Corresponds to antidrone_turret__srv__TriggerActuator
#[allow(missing_docs, non_camel_case_types)]
pub struct TriggerActuator;

impl rosidl_runtime_rs::Service for TriggerActuator {
    type Request = TriggerActuator_Request;
    type Response = TriggerActuator_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__antidrone_turret__srv__TriggerActuator() }
    }
}


