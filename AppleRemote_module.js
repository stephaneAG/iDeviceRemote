/* Espruino Apple Remote module v0.1a by StephaneAG - thx to the original code by Gordon Williams */
/* 
Apple Remote

```
require("AppleRemote").connect(C3, function(codeOrCmd) { // to be used when the module is being tested
  if (codeOrCmd=='volumeDown') ...
  else if (codeOrCmd=='volumeup') ...
  else if (codeOrCmd=='previousTrack') ...
  else if (codeOrCmd=='nextTrack') ...
  else if (codeOrCmd=='playPause') ...
  else if (codeOrCmd=='menu') ...
  else console.log("Unknown command: "+codeOrCmd);
});
```  

*/


var AppleRemote = {
  codes: {
    2011246765: 'volumeDown',
    2011254957: 'volumeUp',
    2011271341: 'previousTrack',
    2011259053: 'nextTrack',
    2011275437: 'playPause',
    2011283629: 'menu'
  },
  lastTime: 0,
  timeout: undefined,
  code: 0,
  handleCode: function(){
    AppleRemote.timeout = undefined;
    // handle the Apple Remote code
    if ( AppleRemote.codes[AppleRemote.code] !== undefined ) print( AppleRemote.codes[AppleRemote.code] );
    else print( AppleRemote.code );
    AppleRemote.code = 0;
  },
  onPulseOn: function(e){
    AppleRemote.code = ( AppleRemote.code*2 ) | ( (e.time - AppleRemote.lastTime)>0.001 );
    if ( AppleRemote.timeout!== undefined ) clearTimeout( AppleRemote.timeout );
    AppleRemote.timeout = setTimeout( AppleRemote.handleCode, 20 ); 
    AppleRemote.lastTime = e.time;
  },
  onPulseOff: function(e){
    AppleRemote.lastTime = e.time;
  }
};

exports.connect = function(pin, callback) {
  setWatch(AppleRemote.onPulseOn, pin, {repeat: true, edge: "falling"});
  setWatch(AppleRemote.onPulseOff, pin, {repeat: true, edge: "rising"});
};
