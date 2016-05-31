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
