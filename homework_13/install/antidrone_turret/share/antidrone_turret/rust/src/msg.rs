#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to antidrone_turret__msg__Target

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Target::default())
  }
}

impl rosidl_runtime_rs::Message for Target {
  type RmwMsg = super::msg::rmw::Target;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        visible: msg.visible,
        x: msg.x,
        y: msg.y,
        distance_m: msg.distance_m,
        confidence: msg.confidence,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      visible: msg.visible,
      x: msg.x,
      y: msg.y,
      distance_m: msg.distance_m,
      confidence: msg.confidence,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      visible: msg.visible,
      x: msg.x,
      y: msg.y,
      distance_m: msg.distance_m,
      confidence: msg.confidence,
    }
  }
}


// Corresponds to antidrone_turret__msg__ActuatorStatus

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ActuatorStatus::default())
  }
}

impl rosidl_runtime_rs::Message for ActuatorStatus {
  type RmwMsg = super::msg::rmw::ActuatorStatus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        state: msg.state,
        trigger_count: msg.trigger_count,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      state: msg.state,
      trigger_count: msg.trigger_count,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      state: msg.state,
      trigger_count: msg.trigger_count,
    }
  }
}


// Corresponds to antidrone_turret__msg__ServoCommand

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ServoCommand::default())
  }
}

impl rosidl_runtime_rs::Message for ServoCommand {
  type RmwMsg = super::msg::rmw::ServoCommand;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        direction: msg.direction,
        target_x: msg.target_x,
        error_x: msg.error_x,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      direction: msg.direction,
      target_x: msg.target_x,
      error_x: msg.error_x,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      direction: msg.direction,
      target_x: msg.target_x,
      error_x: msg.error_x,
    }
  }
}


// Corresponds to antidrone_turret__msg__GimbalCommand

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::GimbalCommand::default())
  }
}

impl rosidl_runtime_rs::Message for GimbalCommand {
  type RmwMsg = super::msg::rmw::GimbalCommand;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        direction: msg.direction,
        target_y: msg.target_y,
        error_y: msg.error_y,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      direction: msg.direction,
      target_y: msg.target_y,
      error_y: msg.error_y,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      direction: msg.direction,
      target_y: msg.target_y,
      error_y: msg.error_y,
    }
  }
}


// Corresponds to antidrone_turret__msg__TurretStatus

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::TurretStatus::default())
  }
}

impl rosidl_runtime_rs::Message for TurretStatus {
  type RmwMsg = super::msg::rmw::TurretStatus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        target_state: msg.target_state,
        action: msg.action,
        trigger_state: msg.trigger_state,
        confidence: msg.confidence,
        distance_m: msg.distance_m,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      target_state: msg.target_state,
      action: msg.action,
      trigger_state: msg.trigger_state,
      confidence: msg.confidence,
      distance_m: msg.distance_m,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      target_state: msg.target_state,
      action: msg.action,
      trigger_state: msg.trigger_state,
      confidence: msg.confidence,
      distance_m: msg.distance_m,
    }
  }
}


