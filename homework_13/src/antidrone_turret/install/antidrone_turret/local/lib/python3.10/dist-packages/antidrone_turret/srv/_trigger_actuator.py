# generated from rosidl_generator_py/resource/_idl.py.em
# with input from antidrone_turret:srv/TriggerActuator.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TriggerActuator_Request(type):
    """Metaclass of message 'TriggerActuator_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
                'antidrone_turret.srv.TriggerActuator_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__trigger_actuator__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__trigger_actuator__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__trigger_actuator__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__trigger_actuator__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__trigger_actuator__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TriggerActuator_Request(metaclass=Metaclass_TriggerActuator_Request):
    """Message class 'TriggerActuator_Request'."""

    __slots__ = [
        '_confidence',
        '_distance_m',
    ]

    _fields_and_field_types = {
        'confidence': 'float',
        'distance_m': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
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


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_TriggerActuator_Response(type):
    """Metaclass of message 'TriggerActuator_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
                'antidrone_turret.srv.TriggerActuator_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__trigger_actuator__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__trigger_actuator__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__trigger_actuator__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__trigger_actuator__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__trigger_actuator__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TriggerActuator_Response(metaclass=Metaclass_TriggerActuator_Response):
    """Message class 'TriggerActuator_Response'."""

    __slots__ = [
        '_accepted',
        '_trigger_count',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'trigger_count': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())
        self.trigger_count = kwargs.get('trigger_count', int())

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
        if self.accepted != other.accepted:
            return False
        if self.trigger_count != other.trigger_count:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

    @builtins.property
    def trigger_count(self):
        """Message field 'trigger_count'."""
        return self._trigger_count

    @trigger_count.setter
    def trigger_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'trigger_count' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'trigger_count' field must be an unsigned integer in [0, 4294967295]"
        self._trigger_count = value


class Metaclass_TriggerActuator(type):
    """Metaclass of service 'TriggerActuator'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('antidrone_turret')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'antidrone_turret.srv.TriggerActuator')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__trigger_actuator

            from antidrone_turret.srv import _trigger_actuator
            if _trigger_actuator.Metaclass_TriggerActuator_Request._TYPE_SUPPORT is None:
                _trigger_actuator.Metaclass_TriggerActuator_Request.__import_type_support__()
            if _trigger_actuator.Metaclass_TriggerActuator_Response._TYPE_SUPPORT is None:
                _trigger_actuator.Metaclass_TriggerActuator_Response.__import_type_support__()


class TriggerActuator(metaclass=Metaclass_TriggerActuator):
    from antidrone_turret.srv._trigger_actuator import TriggerActuator_Request as Request
    from antidrone_turret.srv._trigger_actuator import TriggerActuator_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
