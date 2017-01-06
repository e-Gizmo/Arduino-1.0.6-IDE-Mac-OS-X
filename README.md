# Arduino-1.0.6-IDE-Mac-OS-X
## Previous IDE Release
###### gizDuino boards file Included (No need to patch) Just download it!
- Join Github and follow for more updates...
- Github account: www.github.com/e-Gizmo/
- Visit our Website at www.e-gizmo.com - [e-Gizmo Mechatronix Central](www.e-gizmo.com)
- Facebook Page: www.facebook.com/eGizmoMechatronix/
- YouTube Channel: www.youtube.com/channel/UCPTmP3ql3_D302-zh5sZqAw

Important notes:

- ## IDE Installation for Mac users

1. Install first the PL2303 Driver package for gizDuino boards!
 -----
 - Prolific Driver, downloads here: <https://github.com/e-Gizmo/Arduino-1.0.6-IDE-Mac-OS-X/blob/master/md_PL2303_MacOSX-10_6up_v1_5_0.zip?raw=true>
 - If the current one fails, download and try to install the package found here: <http://sourceforge.net/projects/osx-pl2303/>
 
 
2. Download
 -------
 ![how to download](http://i.makeagif.com/media/6-21-2016/_xYx6X.gif)
 
3. **Copy the whole 'gizduino-' folder found inside the Windows version of the Arduino package (arduino-1.0.1).**

 - This folder can be found in 'arduino-1.0.1/hardware'.
 
 

4. **Look for Arduino.app in your system (usually on the desktop or in your Applications folder). Right-click on it and select 'Show Package Contents'. This enables you to explore the IDE directories.**

 - Paste the 'gizduino-' folder you copied in 'Contents/Resources/Java/hardware/'. To check if you are in the right directory, the folders 'arduino' and 'tools' should be present.



5.  **Close the Arduino application if it is currently open. After pasting the folder, re-open the application, plug in your Gizduino board via USB, then proceed to Tools > Boards to check. Gizduino board versions should be present and selectable.**



6. **To finalize the IDE set-up, choose 'dev/tty/usbserial' as your Serial Port. You are now ready to program your Gizduino.**



- **NOTE:** When a Network Preferences pop-up window shows up, do not panic. This a normal occurence when using the PL2303 driver. You can close the window or you can confirm (Add), any choice would do and will not affect the Arduino application.
