//
//  main.cpp
//  enumToChar
//
//  Created by Harry O'Brien on 10/05/2019.
//  Copyright © 2019 SociaDevLtd. All rights reserved.
//

#include <iostream>

enum EventType
{
  Closed,                 ///< The window requested to be closed (no data)
  Resized,                ///< The window was resized (data in event.size)
  LostFocus,              ///< The window lost the focus (no data)
  GainedFocus,            ///< The window gained the focus (no data)
  TextEntered,            ///< A character was entered (data in event.text)
  KeyPressed,             ///< A key was pressed (data in event.key)
  KeyReleased,            ///< A key was released (data in event.key)
  MouseWheelMoved,        ///< The mouse wheel was scrolled (data in event.mouseWheel) (deprecated)
  MouseWheelScrolled,     ///< The mouse wheel was scrolled (data in event.mouseWheelScroll)
  MouseButtonPressed,     ///< A mouse button was pressed (data in event.mouseButton)
  MouseButtonReleased,    ///< A mouse button was released (data in event.mouseButton)
  MouseMoved,             ///< The mouse cursor moved (data in event.mouseMove)
  MouseEntered,           ///< The mouse cursor entered the area of the window (no data)
  MouseLeft,              ///< The mouse cursor left the area of the window (no data)
  JoystickButtonPressed,  ///< A joystick button was pressed (data in event.joystickButton)
  JoystickButtonReleased, ///< A joystick button was released (data in event.joystickButton)
  JoystickMoved,          ///< The joystick moved along an axis (data in event.joystickMove)
  JoystickConnected,      ///< A joystick was connected (data in event.joystickConnect)
  JoystickDisconnected,   ///< A joystick was disconnected (data in event.joystickConnect)
  TouchBegan,             ///< A touch event began (data in event.touch)
  TouchMoved,             ///< A touch moved (data in event.touch)
  TouchEnded,             ///< A touch event ended (data in event.touch)
  SensorChanged,          ///< A sensor value changed (data in event.sensor)
  
  Count                   ///< Keep last -- the total number of event types
};

struct
{
  const char* operator()(EventType e)
  {
    const char* EventName[] = {
      "Closed",
      "Resized",                ///< The window was resized (data in event.size)
      "LostFocus",              ///< The window lost the focus (no data)
      "GainedFocus",            ///< The window gained the focus (no data)
      "TextEntered",            ///< A character was entered (data in event.text)
      "KeyPressed",             ///< A key was pressed (data in event.key)
      "KeyReleased",            ///< A key was released (data in event.key)
      "MouseWheelMoved",        ///< The mouse wheel was scrolled (data in event.mouseWheel) (deprecated)
      "MouseWheelScrolled",     ///< The mouse wheel was scrolled (data in event.mouseWheelScroll)
      "MouseButtonPressed",     ///< A mouse button was pressed (data in event.mouseButton)
      "MouseButtonReleased",    ///< A mouse button was released (data in event.mouseButton)
      "MouseMoved",             ///< The mouse cursor moved (data in event.mouseMove)
      "MouseEntered",           ///< The mouse cursor entered the area of the window (no data)
      "MouseLeft",              ///< The mouse cursor left the area of the window (no data)
      "JoystickButtonPressed",  ///< A joystick button was pressed (data in event.joystickButton)
      "JoystickButtonReleased", ///< A joystick button was released (data in event.joystickButton)
      "JoystickMoved",          ///< The joystick moved along an axis (data in event.joystickMove)
      "JoystickConnected",      ///< A joystick was connected (data in event.joystickConnect)
      "JoystickDisconnected",   ///< A joystick was disconnected (data in event.joystickConnect)
      "TouchBegan",             ///< A touch event began (data in event.touch)
      "TouchMoved",             ///< A touch moved (data in event.touch)
      "TouchEnded",             ///< A touch event ended (data in event.touch)
      "SensorChanged",          ///< A sensor value changed (data in event.sensor)
      
      "Count"                   ///< Keep last -- the total number of event types
    };
    
    return EventName[e];
  }
} eventNameInverse;

int main(int argc, const char * argv[]) {

  std::cout << eventNameInverse(EventType::Closed) << std::endl;
  
  return 0;
}
