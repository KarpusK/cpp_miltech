# generated from rosidl_generator_py/resource/_idl.py.em
# with input from antidrone_turret:msg/TurretStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TurretStatus(type):
    """Metaclass of message 'TurretStatus'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'TARGET_NONE': 0,
        'TARGET_LOW_CONFIDENCE': 1,
        'TARGET_LOCKED': 2,
        'ACTION_IDLE': 0,
        'ACTION_TRACK': 1,
        'TRIGGER_SKIP': 0,
        'TRIGGER_REQUESTED': 1,
        'TRIGGER_RELOADING': 2,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('antidrone_turret')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'antidrone_turret.msg.TurretStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__turret_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__turret_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__turret_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__turret_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__turret_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'TARGET_NONE': cls.__constants['TARGET_NONE'],
            'TARGET_LOW_CONFIDENCE': cls.__constants['TARGET_LOW_CONFIDENCE'],
            'TARGET_LOCKED': cls.__constants['TARGET_LOCKED'],
            'ACTION_IDLE': cls.__constants['ACTION_IDLE'],
            'ACTION_TRACK': cls.__constants['ACTION_TRACK'],
            'TRIGGER_SKIP': cls.__constants['TRIGGER_SKIP'],
            'TRIGGER_REQUESTED': cls.__constants['TRIGGER_REQUESTED'],
            'TRIGGER_RELOADING': cls.__constants['TRIGGER_RELOADING'],
        }

    @property
    def TARGET_NONE(self):
        """Message constant 'TARGET_NONE'."""
        return Metaclass_TurretStatus.__constants['TARGET_NONE']

    @property
    def TARGET_LOW_CONFIDENCE(self):
        """Message constant 'TARGET_LOW_CONFIDENCE'."""
        return Metaclass_TurretStatus.__constants['TARGET_LOW_CONFIDENCE']

    @property
    def TARGET_LOCKED(self):
        """Message constant 'TARGET_LOCKED'."""
        return Metaclass_TurretStatus.__constants['TARGET_LOCKED']

    @property
    def ACTION_IDLE(self):
        """Message constant 'ACTION_IDLE'."""
        return Metaclass_TurretStatus.__constants['ACTION_IDLE']

    @property
    def ACTION_TRACK(self):
        """Message constant 'ACTION_TRACK'."""
        return Metaclass_TurretStatus.__constants['ACTION_TRACK']

    @property
    def TRIGGER_SKIP(self):
        """Message constant 'TRIGGER_SKIP'."""
        return Metaclass_TurretStatus.__constants['TRIGGER_SKIP']

    @property
    def TRIGGER_REQUESTED(self):
        """Message constant 'TRIGGER_REQUESTED'."""
        return Metaclass_TurretStatus.__constants['TRIGGER_REQUESTED']

    @property
    def TRIGGER_RELOADING(self):
        """Message constant 'TRIGGER_RELOADING'."""
        return Metaclass_TurretStatus.__constants['TRIGGER_RELOADING']


class TurretStatus(metaclass=Metaclass_TurretStatus):
    """
    Message class 'TurretStatus'.

    Constants:
      TARGET_NONE
      TARGET_LOW_CONFIDENCE
      TARGET_LOCKED
      ACTION_IDLE
      ACTION_TRACK
      TRIGGER_SKIP
      TRIGGER_REQUESTED
      TRIGGER_RELOADING
    """

    __slots__ = [
        '_target_state',
        '_action',
        '_trigger_state',
        '_confidence',
        '_distance_m',
    ]

    _fields_and_field_types = {
        'target_state': 'uint8',
        'action': 'uint8',
        'trigger_state': 'uint8',
        'confidence': 'float',
        'distance_m': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.target_state = kwargs.get('target_state', int())
        self.action = kwargs.get('action', int())
        self.trigger_state = kwargs.get('trigger_state', int())
        self.confidence = kwargs.get('confidence', float())
        self.distance_m = kwargs.get('distance_m', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.target_state != other.target_state:
            return False
        if self.action != other.action:
            return False
        if self.trigger_state != other.trigger_state:
            return False
        if self.confidence != other.confidence:
            return False
        if self.distance_m != other.distance_m:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def target_state(self):
        """Message field 'target_state'."""
        return self._target_state

    @target_state.setter
    def target_state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'target_state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'target_state' field must be an unsigned integer in [0, 255]"
        self._target_state = value

    @builtins.property
    def action(self):
        """Message field 'action'."""
        return self._action

    @action.setter
    def action(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'action' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'action' field must be an unsigned integer in [0, 255]"
        self._action = value

    @builtins.property
    def trigger_state(self):
        """Message field 'trigger_state'."""
        return self._trigger_state

    @trigger_state.setter
    def trigger_state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'trigger_state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'trigger_state' field must be an unsigned integer in [0, 255]"
        self._trigger_state = value

    @builtins.property
    def confidence(self):
        """Message field 'confidence'."""
        return self._confidence

    @confidence.setter
    def confidence(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'confidence' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'confidence' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._confidence = value

    @builtins.property
    def distance_m(self):
        """Message field 'distance_m'."""
        return self._distance_m

    @distance_m.setter
    def distance_m(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'distance_m' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'distance_m' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._distance_m = value
