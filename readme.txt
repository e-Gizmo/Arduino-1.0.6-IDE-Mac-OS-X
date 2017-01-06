IDE Installation for Mac users

1. Install the PL2303 driver package. If the current one fails, download and try to install the package found here. -> http://sourceforge.net/projects/osx-pl2303/

2. Launch the Arduino application by double-clicking the zip file. This will install the IDE on your system.

You may skip this step if you already have the Arduino IDE installed in your system beforehand.

3. Copy the whole 'gizduino-' folder found inside the Windows version of the Arduino package (arduino-1.0.1).

This folder can be found in 'arduino-1.0.1/hardware'.

4. Look for Arduino.app in your system (usually on the desktop or in your Applications folder). Right-click on it and select 'Show Package Contents'. This enables you to explore the IDE directories.

Paste the 'gizduino-' folder you copied in 'Contents/Resources/Java/hardware/'. To check if you are in the right directory, the folders 'arduino' and 'tools' should be present.

5. Close the Arduino application if it is currently open. After pasting the folder, re-open the application, plug in your Gizduino board via USB, then proceed to Tools > Boards to check. Gizduino board versions should be present and selectable.

6. To finalize the IDE set-up, choose 'dev/tty/usbserial' as your Serial Port. You are now ready to program your Gizduino.


NOTE: When a Network Preferences pop-up window shows up, do not panic. This a normal occurence when using the PL2303 driver. You can close the window or you can confirm (Add), any choice would do and will not affect the Arduino application.