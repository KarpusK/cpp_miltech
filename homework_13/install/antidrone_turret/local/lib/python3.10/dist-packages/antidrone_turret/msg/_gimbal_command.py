# generated from rosidl_generator_py/resource/_idl.py.em
# with input from antidrone_turret:msg/GimbalCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GimbalCommand(type):
    """Metaclass of message 'GimbalCommand'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'DOWN': -1,
        'CENTER': 0,
        'UP': 1,
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
                'antidrone_turret.msg.GimbalCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__gimbal_command
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__gimbal_command
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__gimbal_command
            cls._TYPE_SUPPORT = module.type_support_msg__msg__gimbal_command
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__gimbal_command

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'DOWN': cls.__constants['DOWN'],
            'CENTER': cls.__constants['CENTER'],
            'UP': cls.__constants['UP'],
        }

    @property
    def DOWN(self):
        """Message constant 'DOWN'."""
        return Metaclass_GimbalCommand.__constants['DOWN']

    @property
    def CENTER(self):
        """Message constant 'CENTER'."""
        return Metaclass_GimbalCommand.__constants['CENTER']

    @property
    def UP(self):
        """Message constant 'UP'."""
        return Metaclass_GimbalCommand.__constants['UP']


class GimbalCommand(metaclass=Metaclass_GimbalCommand):
    """
    Message class 'GimbalCommand'.

    Constants:
      DOWN
      CENTER
      UP
    """

    __slots__ = [
        '_direction',
        '_target_y',
        '_error_y',
    ]

    _fields_and_field_types = {
        'direction': 'int8',
        'target_y': 'float',
        'error_y': 'float',
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
        self.target_y = kwargs.get('target_y', float())
        self.error_y = kwargs.get('error_y', float())

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
        if self.target_y != other.target_y:
            return False
        if self.error_y != other.error_y:
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
    def target_y(self):
        """Message field 'target_y'."""
        return self._target_y

    @target_y.setter
    def target_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'target_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'target_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._target_y = value

    @builtins.property
    def error_y(self):
        """Message field 'error_y'."""
        return self._error_y

    @error_y.setter
    def error_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'error_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'error_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._error_y = value
