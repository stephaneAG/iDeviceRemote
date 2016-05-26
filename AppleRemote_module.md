<!--- StephaneAG - 2016 -->
Apple Remote
=====================

* KEYWORDS: Apple,Remote,IR,Infrared,Received,Remote Control,TSOP34838,TSOP322,TSOP324,TSOP344,TSOP348,VS1838B

Use the [AppleRemote](/modules/AppleRemote.js) ([About Modules](/Modules)) module for it.

Wiring
------

See the existing docs for the IR receivers that can be used & their pinouts

Software
-------

The module 'll return a string  of the command or the code if it's not recognized

```javascript
require("AppleRemote").connect(C3, function(codeOrCmd) {
  if (codeOrCmd=='volumeDown') ...
  else if (codeOrCmd=='volumeup') ...
  else if (codeOrCmd=='previousTrack') ...
  else if (codeOrCmd=='nextTrack') ...
  else if (codeOrCmd=='playPause') ...
  else if (codeOrCmd=='menu') ...
  else console.log("Unknown command: "+codeOrCmd);
});
```

Docs
-----

* [Infrared Remote Control](http://www.espruino.com/Infrared+Remote+Control)
* [IRReceiver](http://www.espruino.com/IRReceiver)
