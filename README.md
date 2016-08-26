# iDeviceRemote
ideas, wip &amp; stuff related to building/writing remotes for the Apple devices


----

##### Apple Remote
```
 ############### 
# ============  #
#               #
#       +       #
#               #
#  <<  >||  >>  #
#               #
#       -       #
#               #
#               #
#      menu     #
#               #
#               #
#               #
#               #
#               #
#               #
#               #
#               #
 ###############
```
[AppleRemote_module.js](AppleRemote_module.js)

| Command [using ken shirriff' lib] | [using Espruino & custom decoder ] | Description |
| :---                              | :---        | :---        |
| 0x77E150AD | 2011254957 | Volume Up
| 0x77E130AD | 2011246765 | Volume Down
| 0x77E1A0AD | 2011275437 | Play / Pause
| 0x77E160AD | 2011259053 | Next
| 0x77E190AD | 2011271341 | Previous
| 0x77E1C0AD | 2011283629 | Menu
  
----
  


##### Apple Dock
```
      ____________ 
 ____|============|____  
#                      #
#      ==========      #
#                      #
#______________________#

```
[AppleDock_module.js](AppleDock_module.js)

| Command | Description |
| :---   | :---        |
0x00 0x00 | Button Released |
0x00 0x01 | Play |
0x00 0x02 | Vol+ |
0x00 0x04 | Vol- |
0x00 0x08 | Skip> |
0x00 0x10 | Skip< |
0x00 0x20 | Next Album |
0x00 0x40 | Previous Album |
0x00 0x80 | Stop |
0x00 0x00 0x01 | Play |
0x00 0x00 0x02 | Pause |
0x00 0x00 0x04 | Mute (toggle) |
0x00 0x00 0x20 | Next Playlist |
0x00 0x00 0x40 | Previous Playlist |
0x00 0x00 0x80 | Toggles Shuffle |
0x00 0x00 0x00 0x01 | Toggles Repeat |
0x00 0x00 0x00 0x04 | Ipod Off |
0x00 0x00 0x00 0x08 | Ipod On |
0x00 0x00 0x00 0x40 | Menu Button |
0x00 0x00 0x00 0x80 | OK/Select |
0x00 0x00 0x00 0x00 0x01 | Scroll Up
0x00 0x00 0x00 0x00 0x02 | Scroll Down


##### iDevice keyboard shortcut



System
| Command | Description |
| :---   | :---        |
F1 | Dim screen |
F2 | Brighten screen |
F7 | Back one song |
F8 | Play/Pause |
F9 | Skin song |
F10 | Mute |
F11 | Decrease volume |
F120 | Increase volume |
CMD + Space | Display languages list - tap space to choose one |
CMD + SPACE ( hold ) | Spotlight search
EJECT | Toggle onscreen keyboard
CMD + ENTER | Send text message ?

Text selection & navigation
| Command | Description |
| :---   | :---        |
CMD + C | Copy |
CMD + X | Cut |
CMD + V | Paste |
CMD + Z | Undo |
CMD + SHIFT + Z | Redo |
CMD + Delete | Delete text to beginning of line |
CTRL + K | Delete text to end of line |
ALT + Delete | Delte the word before the cursor |
CMD + topArrow | Jump to top of document |
CMD + downArrow | Jump to bottom of document |
CMD + leftArrow | Jump to beginning of line |
CMD + rightArrow | Jump to end of line |
ALT + topArrow | Jump to previous starts of line |
ALT + downArrow | Jump to next end of line |
ALT + leftArrow | Jump to previous word |
ALT + rightArrow | Jump to next word |
SHIFT + topArrow | Select text above |
SHIFT + downArrow | Select text below |
SHIFT + leftArrow | Select text on left |
SHIFT + rightArrow | Select text on right |
SHIFT + CMD + topArrow | Select all text to beginning of document |
SHIFT + CMD + downArrow | Select all text to end of document |
SHIFT + CMD + leftArrow | Select all text to beginning of line |
SHIFT + CMD + downArrow | Select all text to end of line |
SHIFT + ALT + topArrow | Select text above, line by line |
SHIFT + ALT + downArrow | Select text below, line by line |
SHIFT + ALT + leftArrow | Select text on left, word by word |
SHIFT + ALT + rightArrow | Select text on right, word by word |

Navigation
R: Settings > General > Accessibility > turn on VoiceOver ( actual voice over can be turned off with CTRL + ALT + S )
| Command | Description |
| :---   | :---        |
CTRL + ALT + H | Home button |
CTRL + ALT + H + H | Show multitask bar |
CTRL + ALT + I | Item chooser |
ESCAPE | Back button |
rightArrow | Next item |
leftArrow | Previous item |
topArrow + downArrow | Tap selected item |
ALT + downArrow | Scroll down |
ALT + upArrow | Scroll up |
ALT + leftArrow | Scroll left |
ALT + rightArrow | Scroll right |
CTRL + ALT + S | Toggle VoiceOver speech |
CMD + SHIFT + TAB | Switch to previous app |
CMD + TAB | Switch back to original app |
leftArrow/rightArrow then ALT + either | Navigate through dock |

Safari
| Command | Description |
| :---   | :---        |
CMD + L | Open location |
CMD +  T | Open new tab |
CMD + W | Close current tab |
CMD + R | refresh current tab |
CMD + . | Stop loading current tab |

Mail
| Command | Description |
| :---   | :---        |
CMD + N | Create a new message |
CMD + SHIFT + D | Send message |
BACKSPACE | Delete currently selected message |
upArrow/downArrow | Select suggested mail in To/CC/BCC fields |

Pages
| Command | Description |
| :---   | :---        |
CMD + SHIFT + K | Comment |
CMD + ALT + K | Show next comment |
CMD + ALT + SHIFT + K | Show previous comment |

VoiceOver
| Command | Description |
| :---   | :---        |
CTRL + ALT + A | Read all fro current position |
CTRL + ALT + B | Read from the top |
CTRL + ALT + M | Move tothe status bar |
CTRL + ALT + leftArrow | Select previous item |
CTRL + ALT + rightArrow | Select next item |
CTRL + ALT + SPACE | Tap an item |
CTRL + ALT + "-" | Double tap with two fingers |
CTRL + ALT + upArrow | Choose the previous rotor item |
CTRL + ALT + downArrow | Choose the next rotor item|
CTRL + ALT + CMD + leftArrow | Choose the previous speech rotor item |
CTRL + ALT + CMD + rightArrow | Choose the next speech rotor item |
CTRL + ALT + CMD + upArrow | Adjust speech rotor item up |
CTRL + ALT + CMD + downArrow | Adjust speech rotor item down |
CTRL + ALT + SHIFT + S | Toggle screen curtain |
CTRL + ALT + K | Turn on VoiceOver help ( ESCAPE to toggle off ) |
