# generated from rosidl_generator_py/resource/_idl.py.em
# with input from antidrone_turret:msg/ServoCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ServoCommand(type):
    """Metaclass of message 'ServoCommand'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'LEFT': -1,
        'CENTER': 0,
        'RIGHT': 1,
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
                'antidrone_turret.msg.ServoCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__servo_command
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__servo_command
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__servo_command
            cls._TYPE_SUPPORT = module.type_support_msg__msg__servo_command
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__servo_command

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'LEFT': cls.__constants['LEFT'],
            'CENTER': cls.__constants['CENTER'],
            'RIGHT': cls.__constants['RIGHT'],
        }

    @property
    def LEFT(self):
        """Message constant 'LEFT'."""
        return Metaclass_ServoCommand.__constants['LEFT']

    @property
    def CENTER(self):
        """Message constant 'CENTER'."""
        return Metaclass_ServoCommand.__constants['CENTER']

    @property
    def RIGHT(self):
        """Message constant 'RIGHT'."""
        return Metaclass_ServoCommand.__constants['RIGHT']


class ServoCommand(metaclass=Metaclass_ServoCommand):
    """
    Message class 'ServoCommand'.

    Constants:
      LEFT
      CENTER
      RIGHT
    """

    __slots__ = [
        '_direction',
        '_target_x',
        '_error_x',
    ]

    _fields_and_field_types = {
        'direction': 'int8',
        'target_x': 'float',
        'error_x': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.direction = kwargs.get('direction', int())
        self.target_x = kwargs.get('target_x', float())
        self.error_x = kwargs.get('error_x', float())

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
        if self.direction != other.direction:
            return False
        if self.target_x != other.target_x:
            return False
        if self.error_x != other.error_x:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def direction(self):
        """Message field 'direction'."""
        return self._direction

    @direction.setter
    def direction(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'direction' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'direction' field must be an integer in [-128, 127]"
        self._direction = value

    @builtins.property
    def target_x(self):
        """Message field 'target_x'."""
        return self._target_x

    @target_x.setter
    def target_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'target_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'target_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._target_x = value

    @builtins.property
    def error_x(self):
        """Message field 'error_x'."""
        return self._error_x

    @error_x.setter
    def error_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'error_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'error_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._error_x = value
