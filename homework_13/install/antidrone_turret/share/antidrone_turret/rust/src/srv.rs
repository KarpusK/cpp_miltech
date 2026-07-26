#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to antidrone_turret__srv__TriggerActuator_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::TriggerActuator_Request::default())
  }
}

impl rosidl_runtime_rs::Message for TriggerActuator_Request {
  type RmwMsg = super::srv::rmw::TriggerActuator_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        confidence: msg.confidence,
        distance_m: msg.distance_m,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      confidence: msg.confidence,
      distance_m: msg.distance_m,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      confidence: msg.confidence,
      distance_m: msg.distance_m,
    }
  }
}


// Corresponds to antidrone_turret__srv__TriggerActuator_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::TriggerActuator_Response::default())
  }
}

impl rosidl_runtime_rs::Message for TriggerActuator_Response {
  type RmwMsg = super::srv::rmw::TriggerActuator_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        trigger_count: msg.trigger_count,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
      trigger_count: msg.trigger_count,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      trigger_count: msg.trigger_count,
    }
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


