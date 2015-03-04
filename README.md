## Updater.dll
Disables the update window from Skype 6.21 for Windows Desktop.

![Skype Update](http://www.navossoc.com/wp-content/uploads/2015/03/Skype_Update.png)

## Installation

Skype is a 32 bits only application, but it can be installed on different locations:

#### 32 bits
Just replace the file Updater.dll in %ProgramFiles%\Skype\Updater

#### 64 bits
Just replace the file Updater.dll in %ProgramFiles(x86)%\Skype\Updater

## Troubleshooting
#### Your solution (DLL) doesn't seem to work.
Try to check if the Skype Updater service is set to Automatic (default).

The same thing can be done through the **Command Prompt (Admin)**
>REG ADD HKLM\SYSTEM\CurrentControlSet\Services\SkypeUpdate /v Start /t REG_DWORD /d 2 /f
